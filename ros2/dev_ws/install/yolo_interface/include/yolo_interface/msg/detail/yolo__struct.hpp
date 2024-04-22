// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yolo_interface:msg/Yolo.idl
// generated code does not contain a copyright notice

#ifndef YOLO_INTERFACE__MSG__DETAIL__YOLO__STRUCT_HPP_
#define YOLO_INTERFACE__MSG__DETAIL__YOLO__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__yolo_interface__msg__Yolo __attribute__((deprecated))
#else
# define DEPRECATED__yolo_interface__msg__Yolo __declspec(deprecated)
#endif

namespace yolo_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Yolo_
{
  using Type = Yolo_<ContainerAllocator>;

  explicit Yolo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->detections = 0;
    }
  }

  explicit Yolo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->detections = 0;
    }
  }

  // field types and members
  using _detections_type =
    uint8_t;
  _detections_type detections;

  // setters for named parameter idiom
  Type & set__detections(
    const uint8_t & _arg)
  {
    this->detections = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yolo_interface::msg::Yolo_<ContainerAllocator> *;
  using ConstRawPtr =
    const yolo_interface::msg::Yolo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yolo_interface::msg::Yolo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yolo_interface::msg::Yolo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yolo_interface::msg::Yolo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yolo_interface::msg::Yolo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yolo_interface::msg::Yolo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yolo_interface::msg::Yolo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yolo_interface::msg::Yolo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yolo_interface::msg::Yolo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yolo_interface__msg__Yolo
    std::shared_ptr<yolo_interface::msg::Yolo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yolo_interface__msg__Yolo
    std::shared_ptr<yolo_interface::msg::Yolo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Yolo_ & other) const
  {
    if (this->detections != other.detections) {
      return false;
    }
    return true;
  }
  bool operator!=(const Yolo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Yolo_

// alias to use template instance with default allocator
using Yolo =
  yolo_interface::msg::Yolo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yolo_interface

#endif  // YOLO_INTERFACE__MSG__DETAIL__YOLO__STRUCT_HPP_
