/// @file Utils_CDLL.h
/// @author DP-Dev
/// @brief Implementation of a CDLL.
#ifndef UTILS_CDLL_H
#define UTILS_CDLL_H
#include <Utils/Utils_types.h>
#include <stdbool.h>
#include <stdlib.h>

#ifdef __cpluplus
extern "C"
{
#endif

  /// @brief An structure to represent a CDLL.
  typedef struct Utils_CDLL
  {
    /// @brief Head of the list.
    Utils_DoubleNode *head;
    /// @brief The number of elements of the list.
    size_t size;
  } Utils_CDLL;

  /// @brief Create a new CDLL.
  /// @return The new CDLL structure or NULL on error.
  Utils_CDLL *Utils_CDLLCreate();

  /// @brief Destroy a CDLL.
  /// @param list The list to destroy.
  void Utils_CDLLDestroy(Utils_CDLL *list);

  /// @brief Get the number of elements in a list.
  /// @param list The list to query.
  /// @return The number of elements in the list.
  size_t Utils_CDLLGetSize(Utils_CDLL *list);

  /// @brief Check if a list is empty.
  /// @param list The list to query.
  /// @return true if is empty.
  bool Utils_CDLLEmpty(Utils_CDLL *list);

  /// @brief Check if a list have been initialized.
  /// @param list The list to query.
  /// @return true if the list have been initialized.
  bool Utils_CDLLWasInit(Utils_CDLL *list);

  /// @brief Get first node in the list.
  /// @param list The list to query.
  /// @return A pointer to the head node or NULL if it have
  /// not been initialized or if it's size is 0.
  Utils_DoubleNode *Utils_CDLLBegin(Utils_CDLL *list);

  /// @brief Get the last node in a list.
  /// @param list The list to query.
  /// @return A pointer to the tail node or NULL if it have
  /// not been initialized or if it's size is 0.
  Utils_DoubleNode *Utils_CDLLEnd(Utils_CDLL *list);

  /// @brief Insert data in the specified node.
  /// @param list The list where to insert.
  /// @param node The node where the data will be inserted.
  /// @param userdata The data to insert, NULL is allowed.
  /// @return true in success.
  bool Utils_CDLLInsert(Utils_CDLL *list,
    Utils_DoubleNode *node, void *userdata);

  /// @brief Insert data after a specific node.
  /// @param list The list where data will be inserted.
  /// @param node The node where the data will be inserted.
  /// @param userdata The data to insert.
  /// @return true in success.
  bool Utils_CDLLInsertAfter(Utils_CDLL *list,
    Utils_DoubleNode *node, void *userdata);

  /// @brief Remove a node from a list.
  /// @param list The list where the node will be deleted.
  /// @param node The node to remove.
  /// @return true if the node was removed.
  bool Utils_CDLLRemove(
    Utils_CDLL *list, Utils_DoubleNode *node);

  /// @brief Remove the next node of another.
  /// @param list The list where the node will be removed.
  /// @param node The node taken as reference.
  /// @return true in success, false otherwise.
  bool Utils_CDLLRemoveAfter(
    Utils_CDLL *list, Utils_DoubleNode *node);

  /// @brief Insert data in the tail of a list.
  /// @param list The list where the data will be inserted.
  /// @param userdata The data to insert.
  /// @return true in success, false otherwise.
  bool Utils_CDLLPushBack(Utils_CDLL *list, void *userdata);

  /// @brief Insert data in the head of a list.
  /// @param list The list where the data will be inserted.
  /// @param userdata The data to insert.
  /// @return true in success, false otherwise.
  bool Utils_CDLLPushFront(
    Utils_CDLL *list, void *userdata);

  /// @brief Remove data from the tail of a list.
  /// @param list The list where the data will removed.
  /// @return true if the operation.
  bool Utils_CDLLPopBack(Utils_CDLL *list);

  /// @brief Remove data from the head of a list.
  /// @param list The list where the data will be removed.
  /// @return true if the operation was successfully.
  bool Utils_CDLLPopFront(Utils_CDLL *list);

  /// @brief Clear the content of a list.
  /// @param list The list to clear.
  void Utils_CDLLClear(Utils_CDLL *list);

#ifdef __cplusplus
}
#endif

#endif
