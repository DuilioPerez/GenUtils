/// @file GenUtils_types.h
/// @author DP-Dev.
/// @brief Common types for the library.
#ifndef GENUTILS_TYPES_H
#define GENUTILS_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

  /// @brief A node with just one pointer.
  typedef struct GenUtils_SingleNode
  {
    /// @brief The user data.
    void *userdata;
    /// @brief The next node.
    struct GenUtils_SingleNode *nextNode;
  } GenUtils_SingleNode;

  /// @brief A node with two pointers.
  typedef struct GenUtils_DoubleNode
  {
    /// @brief The user data.
    void *userdata;
    /// @brief The first pointer to node.
    struct GenUtils_DoubleNode *first;
    /// @brief The second pointer to node.
    struct GenUtils_DoubleNode *second;
  } GenUtils_DoubleNode;

#ifdef __cplusplus
}
#endif

#endif
