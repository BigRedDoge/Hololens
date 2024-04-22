// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from yolo_interface:msg/Yolo.idl
// generated code does not contain a copyright notice

#ifndef YOLO_INTERFACE__MSG__DETAIL__YOLO__TRAITS_HPP_
#define YOLO_INTERFACE__MSG__DETAIL__YOLO__TRAITS_HPP_

#include "yolo_interface/msg/detail/yolo__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<yolo_interface::msg::Yolo>()
{
  return "yolo_interface::msg::Yolo";
}

template<>
inline const char * name<yolo_interface::msg::Yolo>()
{
  return "yolo_interface/msg/Yolo";
}

template<>
struct has_fixed_size<yolo_interface::msg::Yolo>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<yolo_interface::msg::Yolo>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<yolo_interface::msg::Yolo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // YOLO_INTERFACE__MSG__DETAIL__YOLO__TRAITS_HPP_
