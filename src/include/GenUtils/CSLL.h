/// @file CSLL.h
/// @author DP-Dev
/// @brief Implementation of a CSLL.
#ifndef GENUTILS_CSLL_H
#define GENUTILS_CSLL_H
#include <GenUtils/types.h>
#include <stdbool.h>
#include <stdlib.h>

#ifdef __cpluplus
extern "C"
{
#endif

  /// @brief An structure to represent a CSLL.
  typedef struct GenUtils_CSLL
  {
    /// @brief Head of the list.
    GenUtils_SingleNode *head;
    /// @brief Tail of the list.
    GenUtils_SingleNode *tail;
    /// @brief The number of elements in the list.
    size_t size;
  } GenUtils_CSLL;

  /// @brief Create a new CSLL.
  /// @return The new CSLL structure or NULL on error.
  GenUtils_CSLL *GenUtils_CSLLCreate();

  /// @brief Destroy a CSLL.
  /// @param list The list to destroy.
  void GenUtils_CSLLDestroy(GenUtils_CSLL *list);

  /// @brief Get the numbers of elements in a list.
  /// @param list The list to query.
  /// @return The number of elements in the list.
  size_t GenUtils_CSLLGetSize(GenUtils_CSLL *list);

  /// @brief Check if a list is empty.
  /// @param list The list to query.
  /// @return true if is empty.
  bool GenUtils_CSLLEmpty(GenUtils_CSLL *list);

  /// @brief Check if a list have been initialized.
  /// @param list The list to query.
  /// @return true if the list have been initialized.
  bool GenUtils_CSLLWasInit(GenUtils_CSLL *list);

  /// @brief Get first node in a list.
  /// @param list The list to query.
  /// @return A pointer to the head node or NULL if it have
  /// not been initialized or if it's size is 0.
  GenUtils_SingleNode *GenUtils_CSLLBegin(
    GenUtils_CSLL *list);

  /// @brief Get the last node in a list.
  /// @param list The list to query.
  /// @return A pointer to the tail node or NULL if it have
  /// not been initialized or if it's size is 0.
  GenUtils_SingleNode *GenUtils_CSLLEnd(
    GenUtils_CSLL *list);

  /// @brief Insert data in the specified node.
  /// @param list The list where the data will be insert.
  /// @param node The node where the data will be inserted.
  /// @param userdata The data to insert, NULL is allowed.
  /// @return true in success.
  bool GenUtils_CSLLInsert(GenUtils_CSLL *list,
    GenUtils_SingleNode *node, void *userdata);

  /// @brief Insert data after a specific node.
  /// @param list The list where the data will be inserted.
  /// @param node The node where the data will be inserted.
  /// @param userdata The data to insert.
  /// @return true in success.
  bool GenUtils_CSLLInsertAfter(GenUtils_CSLL *list,
    GenUtils_SingleNode *node, void *userdata);

  /// @brief Remove a node from a list.
  /// @param list The list where the node will be deleted.
  /// @param node The node to remove.
  /// @return true if the node was removed.
  ///
  /// Warning: This operation is slow in this type of list.
  /// Use CDLL list type instead.
  bool GenUtils_CSLLRemove(
    GenUtils_CSLL *list, GenUtils_SingleNode *node);

  /// @brief Remove the next node of another.
  /// @param list The list where the node will be removed.
  /// @param node The node taken as reference.
  /// @return true if the node was removed.
  bool GenUtils_CSLLRemoveAfter(
    GenUtils_CSLL *list, GenUtils_SingleNode *node);

  /// @brief Insert data in the tail of a list.
  /// @param list The list where the data will be inserted.
  /// @param userdata The data to insert.
  /// @return true in success, false otherwise.
  bool GenUtils_CSLLPushBack(
    GenUtils_CSLL *list, void *userdata);

  /// @brief Insert data in the head of a list.
  /// @param list The list where the data will be inserted.
  /// @param userdata The data to insert.
  /// @return true in success, false otherwise.
  bool GenUtils_CSLLPushFront(
    GenUtils_CSLL *list, void *userdata);

  /// @brief Remove data from the tail of the list.
  /// @param list The list where the data will be removed.
  /// @return true if the operation.
  bool GenUtils_CSLLPopBackBool(GenUtils_CSLL *list);

  /// @brief Remove data from the head of the list.
  /// @param list The list where the data will be removed.
  /// @return true if the operation was successfully.
  bool GenUtils_CSLLPopFrontBool(GenUtils_CSLL *list);

  /// @brief Remove data from the tail of the list.
  /// @param list The list where the data will be removed.
  /// @return The content in the tail of the list.
  void *GenUtils_CSLLPopBack(GenUtils_CSLL *list);

  /// @brief Remove data from the head of the list.
  /// @param list The list where the data will be removed.
  /// @return The content of the head of the list.
  void *GenUtils_CSLLPopFront(GenUtils_CSLL *list);

  /// @brief Clear the content of a list.
  /// @param list The list to clear.
  void GenUtils_CSLLClear(GenUtils_CSLL *list);

  /// @brief Iterate through all the elements of a list.
  /// @param list The list where to be iterated.
  /// @param extradata Extradata to pass to the iterator
  /// function.
  /// @param function The iterator function.
  void GenUtils_CSLLIterate(GenUtils_CSLL *list,
    void *extradata, void (*function)(void *, void *));

#ifdef __cplusplus
}
#endif

#endif
