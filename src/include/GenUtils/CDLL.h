/// @file CDLL.h
/// @author DP-Dev
/// @brief Implementation of a CDLL.
#ifndef GENUTILS_CDLL_H
#define GENUTILS_CDLL_H
#include <GenUtils/types.h>
#include <stdbool.h>
#include <stdlib.h>

#ifdef __cpluplus
extern "C"
{
#endif

  /// @brief An structure to represent a CDLL.
  typedef struct GenUtils_CDLL
  {
    /// @brief Head of the list.
    GenUtils_DoubleNode *head;
    /// @brief The number of elements of the list.
    size_t size;
  } GenUtils_CDLL;

  /// @brief Create a new CDLL.
  /// @return The new CDLL structure or NULL on error.
  GenUtils_CDLL *GenUtils_CDLLCreate();

  /// @brief Destroy a CDLL.
  /// @param list The list to destroy.
  void GenUtils_CDLLDestroy(GenUtils_CDLL *list);

  /// @brief Get the number of elements in a list.
  /// @param list The list to query.
  /// @return The number of elements in the list.
  size_t GenUtils_CDLLGetSize(GenUtils_CDLL *list);

  /// @brief Check if a list is empty.
  /// @param list The list to query.
  /// @return true if is empty.
  bool GenUtils_CDLLEmpty(GenUtils_CDLL *list);

  /// @brief Check if a list have been initialized.
  /// @param list The list to query.
  /// @return true if the list have been initialized.
  bool GenUtils_CDLLWasInit(GenUtils_CDLL *list);

  /// @brief Get first node in the list.
  /// @param list The list to query.
  /// @return A pointer to the head node or NULL if it have
  /// not been initialized or if it's size is 0.
  GenUtils_DoubleNode *GenUtils_CDLLBegin(
    GenUtils_CDLL *list);

  /// @brief Get the last node in a list.
  /// @param list The list to query.
  /// @return A pointer to the tail node or NULL if it have
  /// not been initialized or if it's size is 0.
  GenUtils_DoubleNode *GenUtils_CDLLEnd(
    GenUtils_CDLL *list);

  /// @brief Insert data in the specified node.
  /// @param list The list where to insert.
  /// @param node The node where the data will be inserted.
  /// @param userdata The data to insert, NULL is allowed.
  /// @return true in success.
  bool GenUtils_CDLLInsert(GenUtils_CDLL *list,
    GenUtils_DoubleNode *node, void *userdata);

  /// @brief Insert data after a specific node.
  /// @param list The list where data will be inserted.
  /// @param node The node where the data will be inserted.
  /// @param userdata The data to insert.
  /// @return true in success.
  bool GenUtils_CDLLInsertAfter(GenUtils_CDLL *list,
    GenUtils_DoubleNode *node, void *userdata);

  /// @brief Remove a node from a list.
  /// @param list The list where the node will be deleted.
  /// @param node The node to remove.
  /// @return true if the node was removed.
  bool GenUtils_CDLLRemove(
    GenUtils_CDLL *list, GenUtils_DoubleNode *node);

  /// @brief Remove the next node of another.
  /// @param list The list where the node will be removed.
  /// @param node The node taken as reference.
  /// @return true in success, false otherwise.
  bool GenUtils_CDLLRemoveAfter(
    GenUtils_CDLL *list, GenUtils_DoubleNode *node);

  /// @brief Insert data in the tail of a list.
  /// @param list The list where the data will be inserted.
  /// @param userdata The data to insert.
  /// @return true in success, false otherwise.
  bool GenUtils_CDLLPushBack(
    GenUtils_CDLL *list, void *userdata);

  /// @brief Insert data in the head of a list.
  /// @param list The list where the data will be inserted.
  /// @param userdata The data to insert.
  /// @return true in success, false otherwise.
  bool GenUtils_CDLLPushFront(
    GenUtils_CDLL *list, void *userdata);

  /// @brief Remove the tail of the list and returns its
  /// data.
  /// @param list The list where the data will be removed.
  /// @return The data at the tail of the list.
  void *GenUtils_CDLLPopBack(GenUtils_CDLL *list);

  /// @brief Remove data from the tail of a list.
  /// @param list The list where the data will removed.
  /// @return true if the operation.
  bool GenUtils_CDLLPopBackBool(GenUtils_CDLL *list);

  /// @brief Remove the head of the list and returns its
  /// data.
  /// @param list The list where the data will be removed.
  /// @return The data at the tail of the list.
  void *GenUtils_CDLLPopFront(GenUtils_CDLL *list);

  /// @brief Remove data from the head of a list.
  /// @param list The list where the data will be removed.
  /// @return true if the operation was successfully.
  bool GenUtils_CDLLPopFrontBool(GenUtils_CDLL *list);

  /// @brief Clear the content of a list.
  /// @param list The list to clear.
  void GenUtils_CDLLClear(GenUtils_CDLL *list);

  /// @brief Iterate through all the elements of a list.
  /// @param list The list where to be iterated.
  /// @param extradata Extradata to pass to the iterator
  /// function.
  /// @param function The iterator function.
  void GenUtils_CDLLIterate(GenUtils_CDLL *list,
    void *extradata, void (*function)(void *, void *));

#ifdef __cplusplus
}
#endif

#endif
