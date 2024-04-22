// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yolo_interface:msg/ImageMsg.idl
// generated code does not contain a copyright notice

#ifndef YOLO_INTERFACE__MSG__DETAIL__IMAGE_MSG__BUILDER_HPP_
#define YOLO_INTERFACE__MSG__DETAIL__IMAGE_MSG__BUILDER_HPP_

#include "yolo_interface/msg/detail/image_msg__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace yolo_interface
{

namespace msg
{

namespace builder
{

class Init_ImageMsg_data
{
public:
  explicit Init_ImageMsg_data(::yolo_interface::msg::ImageMsg & msg)
  : msg_(msg)
  {}
  ::yolo_interface::msg::ImageMsg data(::yolo_interface::msg::ImageMsg::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yolo_interface::msg::ImageMsg msg_;
};

class Init_ImageMsg_step
{
public:
  explicit Init_ImageMsg_step(::yolo_interface::msg::ImageMsg & msg)
  : msg_(msg)
  {}
  Init_ImageMsg_data step(::yolo_interface::msg::ImageMsg::_step_type arg)
  {
    msg_.step = std::move(arg);
    return Init_ImageMsg_data(msg_);
  }

private:
  ::yolo_interface::msg::ImageMsg msg_;
};

class Init_ImageMsg_is_bigendian
{
public:
  explicit Init_ImageMsg_is_bigendian(::yolo_interface::msg::ImageMsg & msg)
  : msg_(msg)
  {}
  Init_ImageMsg_step is_bigendian(::yolo_interface::msg::ImageMsg::_is_bigendian_type arg)
  {
    msg_.is_bigendian = std::move(arg);
    return Init_ImageMsg_step(msg_);
  }

private:
  ::yolo_interface::msg::ImageMsg msg_;
};

class Init_ImageMsg_encoding
{
public:
  explicit Init_ImageMsg_encoding(::yolo_interface::msg::ImageMsg & msg)
  : msg_(msg)
  {}
  Init_ImageMsg_is_bigendian encoding(::yolo_interface::msg::ImageMsg::_encoding_type arg)
  {
    msg_.encoding = std::move(arg);
    return Init_ImageMsg_is_bigendian(msg_);
  }

private:
  ::yolo_interface::msg::ImageMsg msg_;
};

class Init_ImageMsg_width
{
public:
  explicit Init_ImageMsg_width(::yolo_interface::msg::ImageMsg & msg)
  : msg_(msg)
  {}
  Init_ImageMsg_encoding width(::yolo_interface::msg::ImageMsg::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_ImageMsg_encoding(msg_);
  }

private:
  ::yolo_interface::msg::ImageMsg msg_;
};

class Init_ImageMsg_height
{
public:
  Init_ImageMsg_height()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImageMsg_width height(::yolo_interface::msg::ImageMsg::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_ImageMsg_width(msg_);
  }

private:
  ::yolo_interface::msg::ImageMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yolo_interface::msg::ImageMsg>()
{
  return yolo_interface::msg::builder::Init_ImageMsg_height();
}

}  // namespace yolo_interface

#endif  // YOLO_INTERFACE__MSG__DETAIL__IMAGE_MSG__BUILDER_HPP_
