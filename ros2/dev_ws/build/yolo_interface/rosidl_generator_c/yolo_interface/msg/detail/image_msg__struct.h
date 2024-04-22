// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yolo_interface:msg/ImageMsg.idl
// generated code does not contain a copyright notice

#ifndef YOLO_INTERFACE__MSG__DETAIL__IMAGE_MSG__STRUCT_H_
#define YOLO_INTERFACE__MSG__DETAIL__IMAGE_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'encoding'
#include "rosidl_runtime_c/string.h"
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/ImageMsg in the package yolo_interface.
typedef struct yolo_interface__msg__ImageMsg
{
  uint32_t height;
  uint32_t width;
  rosidl_runtime_c__String encoding;
  uint8_t is_bigendian;
  uint32_t step;
  rosidl_runtime_c__uint8__Sequence data;
} yolo_interface__msg__ImageMsg;

// Struct for a sequence of yolo_interface__msg__ImageMsg.
typedef struct yolo_interface__msg__ImageMsg__Sequence
{
  yolo_interface__msg__ImageMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yolo_interface__msg__ImageMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YOLO_INTERFACE__MSG__DETAIL__IMAGE_MSG__STRUCT_H_
