// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from yolo_interface:msg/ImageMsg.idl
// generated code does not contain a copyright notice
#include "yolo_interface/msg/detail/image_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `encoding`
#include "rosidl_runtime_c/string_functions.h"
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
yolo_interface__msg__ImageMsg__init(yolo_interface__msg__ImageMsg * msg)
{
  if (!msg) {
    return false;
  }
  // height
  // width
  // encoding
  if (!rosidl_runtime_c__String__init(&msg->encoding)) {
    yolo_interface__msg__ImageMsg__fini(msg);
    return false;
  }
  // is_bigendian
  // step
  // data
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->data, 0)) {
    yolo_interface__msg__ImageMsg__fini(msg);
    return false;
  }
  return true;
}

void
yolo_interface__msg__ImageMsg__fini(yolo_interface__msg__ImageMsg * msg)
{
  if (!msg) {
    return;
  }
  // height
  // width
  // encoding
  rosidl_runtime_c__String__fini(&msg->encoding);
  // is_bigendian
  // step
  // data
  rosidl_runtime_c__uint8__Sequence__fini(&msg->data);
}

bool
yolo_interface__msg__ImageMsg__are_equal(const yolo_interface__msg__ImageMsg * lhs, const yolo_interface__msg__ImageMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // height
  if (lhs->height != rhs->height) {
    return false;
  }
  // width
  if (lhs->width != rhs->width) {
    return false;
  }
  // encoding
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->encoding), &(rhs->encoding)))
  {
    return false;
  }
  // is_bigendian
  if (lhs->is_bigendian != rhs->is_bigendian) {
    return false;
  }
  // step
  if (lhs->step != rhs->step) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
yolo_interface__msg__ImageMsg__copy(
  const yolo_interface__msg__ImageMsg * input,
  yolo_interface__msg__ImageMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // height
  output->height = input->height;
  // width
  output->width = input->width;
  // encoding
  if (!rosidl_runtime_c__String__copy(
      &(input->encoding), &(output->encoding)))
  {
    return false;
  }
  // is_bigendian
  output->is_bigendian = input->is_bigendian;
  // step
  output->step = input->step;
  // data
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

yolo_interface__msg__ImageMsg *
yolo_interface__msg__ImageMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolo_interface__msg__ImageMsg * msg = (yolo_interface__msg__ImageMsg *)allocator.allocate(sizeof(yolo_interface__msg__ImageMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(yolo_interface__msg__ImageMsg));
  bool success = yolo_interface__msg__ImageMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
yolo_interface__msg__ImageMsg__destroy(yolo_interface__msg__ImageMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    yolo_interface__msg__ImageMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
yolo_interface__msg__ImageMsg__Sequence__init(yolo_interface__msg__ImageMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolo_interface__msg__ImageMsg * data = NULL;

  if (size) {
    data = (yolo_interface__msg__ImageMsg *)allocator.zero_allocate(size, sizeof(yolo_interface__msg__ImageMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = yolo_interface__msg__ImageMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        yolo_interface__msg__ImageMsg__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
yolo_interface__msg__ImageMsg__Sequence__fini(yolo_interface__msg__ImageMsg__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      yolo_interface__msg__ImageMsg__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

yolo_interface__msg__ImageMsg__Sequence *
yolo_interface__msg__ImageMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolo_interface__msg__ImageMsg__Sequence * array = (yolo_interface__msg__ImageMsg__Sequence *)allocator.allocate(sizeof(yolo_interface__msg__ImageMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = yolo_interface__msg__ImageMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
yolo_interface__msg__ImageMsg__Sequence__destroy(yolo_interface__msg__ImageMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    yolo_interface__msg__ImageMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
yolo_interface__msg__ImageMsg__Sequence__are_equal(const yolo_interface__msg__ImageMsg__Sequence * lhs, const yolo_interface__msg__ImageMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!yolo_interface__msg__ImageMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
yolo_interface__msg__ImageMsg__Sequence__copy(
  const yolo_interface__msg__ImageMsg__Sequence * input,
  yolo_interface__msg__ImageMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(yolo_interface__msg__ImageMsg);
    yolo_interface__msg__ImageMsg * data =
      (yolo_interface__msg__ImageMsg *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!yolo_interface__msg__ImageMsg__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          yolo_interface__msg__ImageMsg__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!yolo_interface__msg__ImageMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
