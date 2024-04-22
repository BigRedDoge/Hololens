// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from yolo_interface:msg/Yolo.idl
// generated code does not contain a copyright notice
#include "yolo_interface/msg/detail/yolo__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
yolo_interface__msg__Yolo__init(yolo_interface__msg__Yolo * msg)
{
  if (!msg) {
    return false;
  }
  // detections
  return true;
}

void
yolo_interface__msg__Yolo__fini(yolo_interface__msg__Yolo * msg)
{
  if (!msg) {
    return;
  }
  // detections
}

bool
yolo_interface__msg__Yolo__are_equal(const yolo_interface__msg__Yolo * lhs, const yolo_interface__msg__Yolo * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // detections
  if (lhs->detections != rhs->detections) {
    return false;
  }
  return true;
}

bool
yolo_interface__msg__Yolo__copy(
  const yolo_interface__msg__Yolo * input,
  yolo_interface__msg__Yolo * output)
{
  if (!input || !output) {
    return false;
  }
  // detections
  output->detections = input->detections;
  return true;
}

yolo_interface__msg__Yolo *
yolo_interface__msg__Yolo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolo_interface__msg__Yolo * msg = (yolo_interface__msg__Yolo *)allocator.allocate(sizeof(yolo_interface__msg__Yolo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(yolo_interface__msg__Yolo));
  bool success = yolo_interface__msg__Yolo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
yolo_interface__msg__Yolo__destroy(yolo_interface__msg__Yolo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    yolo_interface__msg__Yolo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
yolo_interface__msg__Yolo__Sequence__init(yolo_interface__msg__Yolo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolo_interface__msg__Yolo * data = NULL;

  if (size) {
    data = (yolo_interface__msg__Yolo *)allocator.zero_allocate(size, sizeof(yolo_interface__msg__Yolo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = yolo_interface__msg__Yolo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        yolo_interface__msg__Yolo__fini(&data[i - 1]);
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
yolo_interface__msg__Yolo__Sequence__fini(yolo_interface__msg__Yolo__Sequence * array)
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
      yolo_interface__msg__Yolo__fini(&array->data[i]);
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

yolo_interface__msg__Yolo__Sequence *
yolo_interface__msg__Yolo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolo_interface__msg__Yolo__Sequence * array = (yolo_interface__msg__Yolo__Sequence *)allocator.allocate(sizeof(yolo_interface__msg__Yolo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = yolo_interface__msg__Yolo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
yolo_interface__msg__Yolo__Sequence__destroy(yolo_interface__msg__Yolo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    yolo_interface__msg__Yolo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
yolo_interface__msg__Yolo__Sequence__are_equal(const yolo_interface__msg__Yolo__Sequence * lhs, const yolo_interface__msg__Yolo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!yolo_interface__msg__Yolo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
yolo_interface__msg__Yolo__Sequence__copy(
  const yolo_interface__msg__Yolo__Sequence * input,
  yolo_interface__msg__Yolo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(yolo_interface__msg__Yolo);
    yolo_interface__msg__Yolo * data =
      (yolo_interface__msg__Yolo *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!yolo_interface__msg__Yolo__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          yolo_interface__msg__Yolo__fini(&data[i]);
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
    if (!yolo_interface__msg__Yolo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}