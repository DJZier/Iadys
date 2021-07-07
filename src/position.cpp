#include <chrono>
#include <memory>
#include <opencv2/highgui.hpp>
#include "aruco.h"

#include "rclcpp/rclcpp.hpp"
#include "iadys/msg/position.hpp"

using namespace std::chrono_literals;
using namespace std;
cv::VideoCapture cap(2);
cv::Range row1(0,0);
cv::Range row2(1,0);
cv::Range row3(2,0);
cv::Range col(0,0);
class PositionPublisher : public rclcpp::Node
{
public:
  PositionPublisher()
  : Node("position_publisher")
  {
    position_publisher_ = this->create_publisher<iadys::msg::Position>("topic" ,10);



    camera.readFromXMLFile("/home/florian/aruco_ws/EstimateMarkerPose/aruco_calibration_board_a4.yml");///
    Detector.setDictionary("ARUCO_MIP_36h12");


    auto publish_msg = [this]() -> void {
        auto message = iadys::msg::Position();

        cap.read(im);
        //im=cv::imread(argv[1]);
        auto markers=Detector.detect(im,camera, 0.048);//0.05 is the marker size
        for(auto m:markers){
            aruco::CvDrawingUtils::draw3dAxis(im,m,camera);
            cout<<"rvec = " << m.Rvec<<"   tvec= "<<m.Tvec<<endl;

            /*message.x = m.Tvec(row1,col);
            message.y =m.Tvec(row2,col);
            message.z = m.Tvec(row3,col);
            message.teta = m.Rvec(row3,col);*/
            

            message.x = m.Tvec.at<float>(0,0);

        }
        cv::imshow("image",im);
        cv::waitKey(1);



        

        RCLCPP_INFO(this->get_logger(), "Publishing position X : '%f'", message.x);
        

        std::cout << "Publishing Position\nX:" << message.x <<
          "  Y:" << message.y <<"    Z: " << message.z << "    teta : " << message.teta << std::endl;

        this->position_publisher_->publish(message);
      };
    timer_ = this->create_wall_timer(1s, publish_msg);
  }

private:
  rclcpp::Publisher<iadys::msg::Position>::SharedPtr position_publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  cv::Mat im;///
  aruco::CameraParameters camera;///
  aruco::MarkerDetector Detector;///
};


int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PositionPublisher>());
  rclcpp::shutdown();

  return 0;
}
