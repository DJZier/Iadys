// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from iadys:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef IADYS__MSG__DETAIL__POSITION__STRUCT_H_
#define IADYS__MSG__DETAIL__POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/Position in the package iadys.
typedef struct iadys__msg__Position
{
  float x;
  float y;
  float z;
  float teta;
} iadys__msg__Position;

// Struct for a sequence of iadys__msg__Position.
typedef struct iadys__msg__Position__Sequence
{
  iadys__msg__Position * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} iadys__msg__Position__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // IADYS__MSG__DETAIL__POSITION__STRUCT_H_
