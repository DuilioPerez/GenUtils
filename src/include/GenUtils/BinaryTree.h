/// @file BinaryTree.h
/// @author DP-Dev
/// @brief Implementation of a binary tree.
#ifndef GENUTILS_BYNARY_TREE
#define GENUTILS_BYNARY_TREE

#ifdef __cplusplus
extern "C"
{
#endif
#include <GenUtils/types.h>
#include <stdbool.h>
#include <stddef.h>

  /// @brief An structure to represent a Binary Tree.
  typedef struct GenUtils_BinaryTree
  {
    /// @brief Root node of the binary tree.
    GenUtils_DoubleNode *root;
    /// @brief The number of elements of the binary tree.
    size_t size;
  } GenUtils_BinaryTree;

  /// @brief Structure representing a key/value pair.
  typedef struct GenUtils_BinaryTreeKeyValue
  {
    /// @brief The key used as ID for the value.
    const char *key;
    /// @brief The value stored in this node.
    void *value;
  } GenUtils_BinaryTreeKeyValue;

  /// @brief Create a new binary tree.
  /// @return The new binary tree or NULL on error.
  GenUtils_BinaryTree *GenUtils_BinaryTreeCreate();

  /// @brief Destroy a binary tree.
  /// @param binaryTree The binary tree to destroy.
  void GenUtils_BinaryTreeDestroy(
    GenUtils_BinaryTree *binaryTree);

  /// @brief Check if a binary tree have been initialized.
  /// @param binaryTree The binary tree to query.
  /// @return true if the binary tree have been initialized.
  bool GenUtils_BinaryTreeWasInit(
    GenUtils_BinaryTree *binaryTree);

  /// @brief Get the number of elements in a binary tree.
  /// @param binaryTree The binary tree to query.
  /// @return The number of elements in the binary tree.
  size_t GenUtils_BinaryTreeGetSize(
    GenUtils_BinaryTree *binaryTree);

  /// @brief Check if a binary tree is empty.
  /// @param binaryTree The binary tree to query.
  /// @return true if is empty.
  bool GenUtils_BinaryTreeEmpty(
    GenUtils_BinaryTree *binaryTree);

  /// @brief Checks if a key exists.
  /// @param binaryTree The binary tree to search in.
  /// @param key The key to search for.
  /// @return true if the key already exists.
  bool GenUtils_BinaryTreeExist(
    GenUtils_BinaryTree *binaryTree, const char *key);

  /// @brief Get the value of a key in a binary tree.
  /// @param binaryTree The binary tree where the key will
  /// be searched.
  /// @param key The key associated with the value.
  /// @return The value associated with the key, or NULL on
  /// error.
  void *GenUtils_BinaryTreeGet(
    GenUtils_BinaryTree *binaryTree, const char *key);

  /// @brief Set the value of a node.
  /// @param binaryTree The binary tree to modify.
  /// @param keyValue The key to modify and the value to
  /// insert.
  /// @return true in success.
  bool GenUtils_BinaryTreeSet(
    GenUtils_BinaryTree *binaryTree,
    GenUtils_BinaryTreeKeyValue keyValue);

  /// @brief Get root node in a binary tree.
  /// @param binaryTree The binary tree to query.
  /// @return A pointer to the root node or NULL if it have
  /// not been initialized or if it's size is 0.
  GenUtils_DoubleNode *GenUtils_BinaryTreeRoot(
    GenUtils_BinaryTree *binaryTree);

  /// @brief Insert a key/value pair in a tree.
  /// @param binaryTree The binary tree where data will be
  /// inserted.
  /// @param keyValue Pair key value to insert. NULL in data
  /// is allowed.
  /// @return true in success.
  bool GenUtils_BinaryTreeInsert(
    GenUtils_BinaryTree *binaryTree,
    GenUtils_BinaryTreeKeyValue keyValue);

  /// @brief Remove a pair node from a binary tree and
  /// return its value.
  /// @param binaryTree The binary tree where the node will
  /// be deleted.
  /// @param key The ID of the element to remove.
  /// @return The value in the node.
  void *GenUtils_BinaryTreeRemove(
    GenUtils_BinaryTree *binaryTree, const char *key);

  /// @brief Remove a pair node from a binary tree.
  /// @param binaryTree The binary tree where the node will
  /// be deleted.
  /// @param key The ID of the element to remove.
  /// @return true if the node was removed.
  bool GenUtils_BinaryTreeRemoveBool(
    GenUtils_BinaryTree *binaryTree, const char *key);

  /// @brief Balance a binary tree.
  /// @param binaryTree The tree to balance.
  /// @return The new binary tree.
  GenUtils_BinaryTree *GenUtils_BinaryTreeBalance(
    GenUtils_BinaryTree *binaryTree);

  /// @brief Make a sorted array from a binary tree.
  /// @param tree The tree to convert into array.
  /// @return An array of key/value pairs.
  GenUtils_BinaryTreeKeyValue *GenUtils_BinaryTreeToArray(
    GenUtils_BinaryTree *tree);

  /// @brief Make a balanced tree from a sorted array.
  /// @param array The array that will be used to create the
  /// tree.
  /// @param size The size of the array.
  /// @return A new balanced tree.
  GenUtils_BinaryTree *GenUtils_BinaryTreeFromArray(
    GenUtils_BinaryTreeKeyValue *, size_t size);

  /// @brief Clear the content of a binary tree.
  /// @param binaryTree The binary tree to clear.
  void GenUtils_BinaryTreeClear(
    GenUtils_BinaryTree *binaryTree);

  /// @brief Iterate through all the elements of a binary
  /// tree in preorder mode.
  /// @param binaryTree The binary tree where to be
  /// iterated.
  /// @param extradata Extradata to pass to the iterator
  /// function.
  /// @param function The iterator function. It pass a
  /// pointer to key/value pair and extradata
  void GenUtils_BinaryTreePreorder(
    GenUtils_BinaryTree *binaryTree, void *extradata,
    void (*function)(
      const GenUtils_BinaryTreeKeyValue *, void *));

  /// @brief Iterate through all the elements of a binary
  /// tree in inorder mode.
  /// @param binaryTree The binary tree where to be
  /// iterated.
  /// @param extradata Extradata to pass to the iterator
  /// function.
  /// @param function The iterator function. It pass a
  /// pointer to key/value pair and extradata
  void GenUtils_BinaryTreeInorder(
    GenUtils_BinaryTree *binaryTree, void *extradata,
    void (*function)(
      const GenUtils_BinaryTreeKeyValue *, void *));

  /// @brief Iterate through all the elements of a binary
  /// tree in postorder mode.
  /// @param binaryTree The binary tree where to be
  /// iterated.
  /// @param extradata Extradata to pass to the iterator
  /// function.
  /// @param function The iterator function. It pass a
  /// pointer to key/value pair and extradata
  void GenUtils_BinaryTreePostorder(
    GenUtils_BinaryTree *binaryTree, void *extradata,
    void (*function)(
      const GenUtils_BinaryTreeKeyValue *, void *));

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* end of include guard: GENUTILS_BYNARY_TREE */
