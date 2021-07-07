// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from iadys:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef IADYS__MSG__DETAIL__POSITION__TRAITS_HPP_
#define IADYS__MSG__DETAIL__POSITION__TRAITS_HPP_

#include "iadys/msg/detail/position__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<iadys::msg::Position>()
{
  return "iadys::msg::Position";
}

template<>
inline const char * name<iadys::msg::Position>()
{
  return "iadys/msg/Position";
}

template<>
struct has_fixed_size<iadys::msg::Position>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<iadys::msg::Position>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<iadys::msg::Position>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // IADYS__MSG__DETAIL__POSITION__TRAITS_HPP_
