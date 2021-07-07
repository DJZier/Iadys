// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from iadys:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef IADYS__MSG__DETAIL__POSITION__BUILDER_HPP_
#define IADYS__MSG__DETAIL__POSITION__BUILDER_HPP_

#include "iadys/msg/detail/position__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace iadys
{

namespace msg
{

namespace builder
{

class Init_Position_teta
{
public:
  explicit Init_Position_teta(::iadys::msg::Position & msg)
  : msg_(msg)
  {}
  ::iadys::msg::Position teta(::iadys::msg::Position::_teta_type arg)
  {
    msg_.teta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::iadys::msg::Position msg_;
};

class Init_Position_z
{
public:
  explicit Init_Position_z(::iadys::msg::Position & msg)
  : msg_(msg)
  {}
  Init_Position_teta z(::iadys::msg::Position::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_Position_teta(msg_);
  }

private:
  ::iadys::msg::Position msg_;
};

class Init_Position_y
{
public:
  explicit Init_Position_y(::iadys::msg::Position & msg)
  : msg_(msg)
  {}
  Init_Position_z y(::iadys::msg::Position::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Position_z(msg_);
  }

private:
  ::iadys::msg::Position msg_;
};

class Init_Position_x
{
public:
  Init_Position_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Position_y x(::iadys::msg::Position::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Position_y(msg_);
  }

private:
  ::iadys::msg::Position msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::iadys::msg::Position>()
{
  return iadys::msg::builder::Init_Position_x();
}

}  // namespace iadys

#endif  // IADYS__MSG__DETAIL__POSITION__BUILDER_HPP_
