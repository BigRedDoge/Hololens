// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yolo_interface:msg/Yolo.idl
// generated code does not contain a copyright notice

#ifndef YOLO_INTERFACE__MSG__DETAIL__YOLO__BUILDER_HPP_
#define YOLO_INTERFACE__MSG__DETAIL__YOLO__BUILDER_HPP_

#include "yolo_interface/msg/detail/yolo__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace yolo_interface
{

namespace msg
{

namespace builder
{

class Init_Yolo_detections
{
public:
  Init_Yolo_detections()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::yolo_interface::msg::Yolo detections(::yolo_interface::msg::Yolo::_detections_type arg)
  {
    msg_.detections = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yolo_interface::msg::Yolo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yolo_interface::msg::Yolo>()
{
  return yolo_interface::msg::builder::Init_Yolo_detections();
}

}  // namespace yolo_interface

#endif  // YOLO_INTERFACE__MSG__DETAIL__YOLO__BUILDER_HPP_
