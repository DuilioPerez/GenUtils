/// @file Utils_types.h
/// @author DP-Dev.
/// @brief Common types for the library.
#ifndef UTILS_TYPES_H
#define UTILS_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

  /// @brief A node with just one pointer.
  typedef struct Utils_SingleNode
  {
    /// @brief The user data.
    void *userdata;
    /// @brief The next node.
    struct Utils_SingleNode *nextNode;
  } Utils_SingleNode;

  /// @brief A node with two pointers.
  typedef struct Utils_DoubleNode
  {
    /// @brief The user data.
    void *userdata;
    /// @brief The previous node.
    struct Utils_DoubleNode *prevNode;
    /// @brief The next node.
    struct Utils_DoubleNode *nextNode;
  } Utils_DoubleNode;

#ifdef __cplusplus
}
#endif

#endif
