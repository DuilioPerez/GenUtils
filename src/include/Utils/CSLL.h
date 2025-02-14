/// @file CSLL.h
/// @author DP-Dev
/// @brief Implementation of a CSLL.
#ifndef UTILS_CSLL_H
#define UTILS_CSLL_H
#include <Utils/types.h>
#include <stdbool.h>
#include <stdlib.h>

#ifdef __cpluplus
extern "C"
{
#endif

  /// @brief An structure to represent a CSLL.
  typedef struct Utils_CSLL
  {
    /// @brief Head of the list.
    Utils_SingleNode *head;
    /// @brief Tail of the list.
    Utils_SingleNode *tail;
    /// @brief The number of elements in the list.
    size_t size;
  } Utils_CSLL;

  /// @brief Create a new CSLL.
  /// @return The new CSLL structure or NULL on error.
  Utils_CSLL *Utils_CSLLCreate();

  /// @brief Destroy a CSLL.
  /// @param list The list to destroy.
  void Utils_CSLLDestroy(Utils_CSLL *list);

  /// @brief Get the numbers of elements in a list.
  /// @param list The list to query.
  /// @return The number of elements in the list.
  size_t Utils_CSLLGetSize(Utils_CSLL *list);

  /// @brief Check if a list is empty.
  /// @param list The list to query.
  /// @return true if is empty.
  bool Utils_CSLLEmpty(Utils_CSLL *list);

  /// @brief Check if a list have been initialized.
  /// @param list The list to query.
  /// @return true if the list have been initialized.
  bool Utils_CSLLWasInit(Utils_CSLL *list);

  /// @brief Get first node in a list.
  /// @param list The list to query.
  /// @return A pointer to the head node or NULL if it have
  /// not been initialized or if it's size is 0.
  Utils_SingleNode *Utils_CSLLBegin(Utils_CSLL *list);

  /// @brief Get the last node in a list.
  /// @param list The list to query.
  /// @return A pointer to the tail node or NULL if it have
  /// not been initialized or if it's size is 0.
  Utils_SingleNode *Utils_CSLLEnd(Utils_CSLL *list);

  /// @brief Insert data in the specified node.
  /// @param list The list where the data will be insert.
  /// @param node The node where the data will be inserted.
  /// @param userdata The data to insert, NULL is allowed.
  /// @return true in success.
  bool Utils_CSLLInsert(Utils_CSLL *list,
    Utils_SingleNode *node, void *userdata);

  /// @brief Insert data after a specific node.
  /// @param list The list where the data will be inserted.
  /// @param node The node where the data will be inserted.
  /// @param userdata The data to insert.
  /// @return true in success.
  bool Utils_CSLLInsertAfter(Utils_CSLL *list,
    Utils_SingleNode *node, void *userdata);

  /// @brief Remove a node from a list.
  /// @param list The list where the node will be deleted.
  /// @param node The node to remove.
  /// @return true if the node was removed.
  ///
  /// Warning: This operation is slow in this type of list.
  /// Use CDLL list type instead.
  bool Utils_CSLLRemove(
    Utils_CSLL *list, Utils_SingleNode *node);

  /// @brief Remove the next node of another.
  /// @param list The list where the node will be removed.
  /// @param node The node taken as reference.
  /// @return true if the node was removed.
  bool Utils_CSLLRemoveAfter(
    Utils_CSLL *list, Utils_SingleNode *node);

  /// @brief Insert data in the tail of a list.
  /// @param list The list where the data will be inserted.
  /// @param userdata The data to insert.
  /// @return true in success, false otherwise.
  bool Utils_CSLLPushBack(Utils_CSLL *list, void *userdata);

  /// @brief Insert data in the head of a list.
  /// @param list The list where the data will be inserted.
  /// @param userdata The data to insert.
  /// @return true in success, false otherwise.
  bool Utils_CSLLPushFront(
    Utils_CSLL *list, void *userdata);

  /// @brief Remove data from the tail of the list.
  /// @param list The list where the data will be removed.
  /// @return true if the operation.
  bool Utils_CSLLPopBack(Utils_CSLL *list);

  /// @brief Remove data from the head of the list.
  /// @param list The list where the data will be removed.
  /// @return true if the operation was successfully.
  bool Utils_CSLLPopFront(Utils_CSLL *list);

  /// @brief Clear the content of a list.
  /// @param list The list to clear.
  void Utils_CSLLClear(Utils_CSLL *list);

  /// @brief Iterate through all the elements of a list.
  /// @param list The list where to be iterated.
  /// @param extradata Extradata to pass to the iterator
  /// function.
  /// @param function The iterator function.
  void Utils_CSLLIterate(Utils_CSLL *list, void *extradata,
    void (*function)(void *, void *));

#ifdef __cplusplus
}
#endif

#endif
