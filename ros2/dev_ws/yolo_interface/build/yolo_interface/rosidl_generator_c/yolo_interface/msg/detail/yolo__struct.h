// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yolo_interface:msg/Yolo.idl
// generated code does not contain a copyright notice

#ifndef YOLO_INTERFACE__MSG__DETAIL__YOLO__STRUCT_H_
#define YOLO_INTERFACE__MSG__DETAIL__YOLO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/Yolo in the package yolo_interface.
typedef struct yolo_interface__msg__Yolo
{
  uint8_t detections;
} yolo_interface__msg__Yolo;

// Struct for a sequence of yolo_interface__msg__Yolo.
typedef struct yolo_interface__msg__Yolo__Sequence
{
  yolo_interface__msg__Yolo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yolo_interface__msg__Yolo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YOLO_INTERFACE__MSG__DETAIL__YOLO__STRUCT_H_
