// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from yolo_interface:msg/Yolo.idl
// generated code does not contain a copyright notice
#include "yolo_interface/msg/detail/yolo__rosidl_typesupport_fastrtps_cpp.hpp"
#include "yolo_interface/msg/detail/yolo__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace yolo_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yolo_interface
cdr_serialize(
  const yolo_interface::msg::Yolo & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: detections
  cdr << ros_message.detections;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yolo_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  yolo_interface::msg::Yolo & ros_message)
{
  // Member: detections
  cdr >> ros_message.detections;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yolo_interface
get_serialized_size(
  const yolo_interface::msg::Yolo & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: detections
  {
    size_t item_size = sizeof(ros_message.detections);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yolo_interface
max_serialized_size_Yolo(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: detections
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _Yolo__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const yolo_interface::msg::Yolo *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Yolo__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<yolo_interface::msg::Yolo *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Yolo__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const yolo_interface::msg::Yolo *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Yolo__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_Yolo(full_bounded, 0);
}

static message_type_support_callbacks_t _Yolo__callbacks = {
  "yolo_interface::msg",
  "Yolo",
  _Yolo__cdr_serialize,
  _Yolo__cdr_deserialize,
  _Yolo__get_serialized_size,
  _Yolo__max_serialized_size
};

static rosidl_message_type_support_t _Yolo__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Yolo__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace yolo_interface

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_yolo_interface
const rosidl_message_type_support_t *
get_message_type_support_handle<yolo_interface::msg::Yolo>()
{
  return &yolo_interface::msg::typesupport_fastrtps_cpp::_Yolo__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, yolo_interface, msg, Yolo)() {
  return &yolo_interface::msg::typesupport_fastrtps_cpp::_Yolo__handle;
}

#ifdef __cplusplus
}
#endif
