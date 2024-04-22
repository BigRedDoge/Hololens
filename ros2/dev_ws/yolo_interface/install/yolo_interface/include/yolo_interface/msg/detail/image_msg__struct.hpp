// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yolo_interface:msg/ImageMsg.idl
// generated code does not contain a copyright notice

#ifndef YOLO_INTERFACE__MSG__DETAIL__IMAGE_MSG__STRUCT_HPP_
#define YOLO_INTERFACE__MSG__DETAIL__IMAGE_MSG__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__yolo_interface__msg__ImageMsg __attribute__((deprecated))
#else
# define DEPRECATED__yolo_interface__msg__ImageMsg __declspec(deprecated)
#endif

namespace yolo_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ImageMsg_
{
  using Type = ImageMsg_<ContainerAllocator>;

  explicit ImageMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->height = 0ul;
      this->width = 0ul;
      this->encoding = "";
      this->is_bigendian = 0;
      this->step = 0ul;
    }
  }

  explicit ImageMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : encoding(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->height = 0ul;
      this->width = 0ul;
      this->encoding = "";
      this->is_bigendian = 0;
      this->step = 0ul;
    }
  }

  // field types and members
  using _height_type =
    uint32_t;
  _height_type height;
  using _width_type =
    uint32_t;
  _width_type width;
  using _encoding_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _encoding_type encoding;
  using _is_bigendian_type =
    uint8_t;
  _is_bigendian_type is_bigendian;
  using _step_type =
    uint32_t;
  _step_type step;
  using _data_type =
    std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__height(
    const uint32_t & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__width(
    const uint32_t & _arg)
  {
    this->width = _arg;
    return *this;
  }
  Type & set__encoding(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->encoding = _arg;
    return *this;
  }
  Type & set__is_bigendian(
    const uint8_t & _arg)
  {
    this->is_bigendian = _arg;
    return *this;
  }
  Type & set__step(
    const uint32_t & _arg)
  {
    this->step = _arg;
    return *this;
  }
  Type & set__data(
    const std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yolo_interface::msg::ImageMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const yolo_interface::msg::ImageMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yolo_interface::msg::ImageMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yolo_interface::msg::ImageMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yolo_interface::msg::ImageMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yolo_interface::msg::ImageMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yolo_interface::msg::ImageMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yolo_interface::msg::ImageMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yolo_interface::msg::ImageMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yolo_interface::msg::ImageMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yolo_interface__msg__ImageMsg
    std::shared_ptr<yolo_interface::msg::ImageMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yolo_interface__msg__ImageMsg
    std::shared_ptr<yolo_interface::msg::ImageMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ImageMsg_ & other) const
  {
    if (this->height != other.height) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    if (this->encoding != other.encoding) {
      return false;
    }
    if (this->is_bigendian != other.is_bigendian) {
      return false;
    }
    if (this->step != other.step) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const ImageMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ImageMsg_

// alias to use template instance with default allocator
using ImageMsg =
  yolo_interface::msg::ImageMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yolo_interface

#endif  // YOLO_INTERFACE__MSG__DETAIL__IMAGE_MSG__STRUCT_HPP_
