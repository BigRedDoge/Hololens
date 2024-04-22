// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from yolo_interface:msg/Yolo.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "yolo_interface/msg/detail/yolo__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace yolo_interface
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Yolo_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) yolo_interface::msg::Yolo(_init);
}

void Yolo_fini_function(void * message_memory)
{
  auto typed_message = static_cast<yolo_interface::msg::Yolo *>(message_memory);
  typed_message->~Yolo();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Yolo_message_member_array[1] = {
  {
    "detections",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolo_interface::msg::Yolo, detections),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Yolo_message_members = {
  "yolo_interface::msg",  // message namespace
  "Yolo",  // message name
  1,  // number of fields
  sizeof(yolo_interface::msg::Yolo),
  Yolo_message_member_array,  // message members
  Yolo_init_function,  // function to initialize message memory (memory has to be allocated)
  Yolo_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Yolo_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Yolo_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace yolo_interface


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<yolo_interface::msg::Yolo>()
{
  return &::yolo_interface::msg::rosidl_typesupport_introspection_cpp::Yolo_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, yolo_interface, msg, Yolo)() {
  return &::yolo_interface::msg::rosidl_typesupport_introspection_cpp::Yolo_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
