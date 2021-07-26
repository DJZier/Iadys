#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <unistd.h>



std::vector<float> compute_bezier(int t, std::vector<float> P0 ,std::vector<float> P1, std::vector<float> P2,std::vector<float> P3){
    std::vector<float> r(2);
    float a = pow((1-t), 3) * P0[0];
    float b = 3*t*pow((1-t),2) * P1[0];
    float c = 3*t*t*(1-t) * P2[0];
    float d = t*t*t * P3[0];
    r[0] = a+b+c+d;

    float e = pow((1-t), 3) * P0[1];
    float f = 3*t*pow((1-t),2) * P1[1];
    float g = 3*t*t*(1-t) * P2[1];
    float h = t*t*t * P3[1];
    r[1] = e+f+g+h;

    return r;
}

float compute_alpha_beta (std::vector<float> P0,std::vector<float> P1){
    // Vérifier conversion degré radian
    return 90 - atan((P1[1]-P0[1])/(P1[0]-P0[0]));
}



int main(){
    bool boucle_ros = true;
    float teta,alpha,beta,vr,vl,vt, R, C;
    std::vector<float> P0(2),P1(2),P2(2),P3(2),Mt(2),M0(2), M1(2), M2(2);
    std::vector<float> omega; // Centre du cercle passant par M0,M1,M2
    std::vector<float> A(2), B(2); // points milieux des cordes M0M1 et M1M2
    float d= 0.1; // distance entre les moteurs

    

    while (boucle_ros) {

        // Définition de P0
        P0[0]= robot_pose.position.x; // --> essayer de déclarer les Pi du meme type que .position
        P0[1]= robot_pose.position.y;

        // Définition de P1
        if (robot_pose.orientation <0 && robot_pose > 180){
            P1[0] = P0[0] + cos(teta);
            if (robot_pose.orientation <0){
                P1[1] = P0[1] - sin(teta);
            } else {
                P1[1] = P0[1] + sin(teta);
            }
        }else {
            P1[0] = P0[0] - cos(teta);
            if (robot_pose.orientation < 90){
                P1[1] = P0[1] - sin(teta);
            } else {
                P1[1] = P0[1] + sin(teta);
            }
        }

        // Définition de P3
        P3[0] = 8.76;
        P3[1] = -3;

        // Définition de P2
        if (robot_pose.position.x > 3 || robot_pose.position.y > 3 || robot_pose.position.x < -3 || robot_pose.position.y < -3){
            P2[0] = P3[0] - 1;
        }else {
            P2[0] = sqrt((pow(robot_pose.position.x,2)+pow(robot_pose.position.y,2)))/3;
        }
        
        P2[1] = P3[1];

        // Calcul de M0
        M0 = P0;

        // Calcul de M1
        M1 = compute_bezier(0.1, P0, P1, P2, P3);

        // Calcul de M2
        M2 = compute_bezier(0.2, P0, P1, P2, P3);

        // Calculs d'alpha et beta
        alpha = compute_alpha_beta(M0,M1);
        beta = compute_alpha_beta(M1,M2);

        // Calculs de A et B
        A[0] = (M0[0]+M1[0])/2;
        A[1] = (M0[1]+M1[1])/2;

        B[0] = (M2[0]+M1[0])/2;
        B[1] = (M2[1]+M1[1])/2;

        // Calcul de Omega
        omega[0] = A[0] + ((A[1]-B[1])-(A[0]-B[0])*tan(beta))/(tan(beta)-tan(alpha));
        omega[1] = A[1] + (omega[0]-A[0]) * tan(alpha);

        // Calcul du rayon de courbure R
        R = sqrt((pow(omega[0]-M0[0],2) + pow(omega[1]-M0[1],2)));

        // Calcul de la corde M0M2 --> C
        C = sqrt((pow(M2[0]-M0[0],2) + pow(M2[1]-M0[1],2)));

        // Calcul de teta 
        teta = 2* asin(C/(2*R));

        // Calcul des vitesses moteurs
        vr = ((R+d)/R)*vt;
        vl = ((R-d)/R)*vt;




        // Ajout d'un delay simulant le temps de réponse du robot IRL
        sleep(500);
    }

    return 0;
}