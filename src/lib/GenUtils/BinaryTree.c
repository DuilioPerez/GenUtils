// File: BinaryTree.c
// Author: DP-Dev
// Implementation of a binary tree.
#include <GenUtils/BinaryTree.h>
#include <stdlib.h>
#include <string.h>

// Structure to store data to conver a tree to array.
typedef struct GenUtils_BinaryTreeInternalArrayInfo
{
  // Array of elements.
  GenUtils_BinaryTreeKeyValue *array;
  // Size of the array.
  size_t size;
  // Current index of the array.
  size_t i;
} GenUtils_BinaryTreeInternalArrayInfo;

// Internal prototype for auxiliar function to make an array
// from a binary tree.
static void GenUtils_BinaryTreeInternalToArray(
  const GenUtils_BinaryTreeKeyValue *, void *);

// Internal prototype for a function that removes all the
// nodes of a tree in a postorder traversal.
static void GenUtils_BinaryTreeInternalClear(
  GenUtils_DoubleNode *);

// Auxiliar internal function for preorder tree traversal.
static void GenUtils_BinaryTreeInternalPreorder(
  GenUtils_DoubleNode *, void *,
  void (*)(const GenUtils_BinaryTreeKeyValue *, void *));

// Auxiliar internal function for inorder tree traversal.
static void GenUtils_BinaryTreeInternalInorder(
  GenUtils_DoubleNode *, void *,
  void (*)(const GenUtils_BinaryTreeKeyValue *, void *));

// Auxiliar internal function for postorder tree traversal.
static void GenUtils_BinaryTreeInternalPostorder(
  GenUtils_DoubleNode *, void *,
  void (*)(const GenUtils_BinaryTreeKeyValue *, void *));

// Create a binary tree.
GenUtils_BinaryTree *GenUtils_BinaryTreeCreate()
{
  // Binary tree to create.
  GenUtils_BinaryTree *binaryTree =
    malloc(sizeof(GenUtils_BinaryTree));
  if (binaryTree != NULL)
  {
    binaryTree->root = NULL;
    binaryTree->size = 0;
  }
  return binaryTree;
}

// Destroy a binary tree.
void GenUtils_BinaryTreeDestroy(
  GenUtils_BinaryTree *binaryTree)
{
  // Deletes all its nodes.
  GenUtils_BinaryTreeClear(binaryTree);
  // Free the used memory.
  free(binaryTree);
}

// Check if a binary tree was initialized.
bool GenUtils_BinaryTreeWasInit(
  GenUtils_BinaryTree *binaryTree)
{
  if (binaryTree == NULL)
  {
    return false;
  }
  return true;
}

// Get the size of a binary tree.
size_t GenUtils_BinaryTreeGetSize(
  GenUtils_BinaryTree *binaryTree)
{
  if (GenUtils_BinaryTreeWasInit(binaryTree))
  {
    return binaryTree->size;
  }
  return 0;
}

// Check if a tree is empty.
bool GenUtils_BinaryTreeEmpty(
  GenUtils_BinaryTree *binaryTree)
{
  if (GenUtils_BinaryTreeWasInit(binaryTree) &&
      binaryTree->size == 0)
  {
    return true;
  }
  return false;
}

// Check if a key exists in a binary tree.
bool GenUtils_BinaryTreeExist(
  GenUtils_BinaryTree *binaryTree, const char *key)
{
  // Current node being processed.
  GenUtils_DoubleNode *currentNode =
    GenUtils_BinaryTreeRoot(binaryTree);
  // Current key/value pair.
  GenUtils_BinaryTreeKeyValue *keyValue = NULL;
  // Key's comparison result.
  int comparison = 0;
  // Search the key/value pair
  while (currentNode != NULL)
  {
    keyValue = currentNode->userdata;
    comparison = strcmp(keyValue->key, key);
    if (comparison < 0)
    {
      // If the current key is greater than the searched
      // key, look in the left subtree.
      currentNode = currentNode->first;
    }
    else if (comparison > 0)
    {
      // If is lesser, look in the right subtree.
      currentNode = currentNode->second;
    }
    else
    {
      // If is found, return true.
      return true;
    }
  }
  return false;
}

// Get the value of a key if exists.
void *GenUtils_BinaryTreeGet(
  GenUtils_BinaryTree *binaryTree, const char *key)
{
  // Current node being processed.
  GenUtils_DoubleNode *currentNode =
    GenUtils_BinaryTreeRoot(binaryTree);
  // Current key/value pair.
  GenUtils_BinaryTreeKeyValue *keyValue = NULL;
  // Key's comparison result.
  int comparison = 0;
  // Search the key/value pair
  while (currentNode != NULL)
  {
    keyValue = currentNode->userdata;
    comparison = strcmp(keyValue->key, key);
    if (comparison < 0)
    {
      // If the current key is greater than the searched
      // key, look in the left subtree.
      currentNode = currentNode->first;
    }
    else if (comparison > 0)
    {
      // If is lesser, look in the right subtree.
      currentNode = currentNode->second;
    }
    else
    {
      // If is found, return its value.
      return currentNode->userdata;
    }
  }
  return NULL;
}

// Set the value of a key if exists.
bool GenUtils_BinaryTreeSet(GenUtils_BinaryTree *binaryTree,
  GenUtils_BinaryTreeKeyValue keyValue)
{
  // Current node being processed.
  GenUtils_DoubleNode *currentNode =
    GenUtils_BinaryTreeRoot(binaryTree);
  // Current key/value pair.
  GenUtils_BinaryTreeKeyValue *currentKeyValue = NULL;
  // Key's comparison result.
  int comparison = 0;
  // Search the key/value pair
  while (currentNode != NULL)
  {
    currentKeyValue = currentNode->userdata;
    comparison = strcmp(keyValue.key, currentKeyValue->key);
    if (comparison < 0)
    {
      // If the current key is greater than the searched
      // key, look in the left subtree.
      currentNode = currentNode->first;
    }
    else if (comparison > 0)
    {
      // If is lesser, look in the right subtree.
      currentNode = currentNode->second;
    }
    else
    {
      // If is found, set the new value.
      currentKeyValue->value = keyValue.value;
      return true;
    }
  }
  return false;
}

// Get the root node of a binary tree.
GenUtils_DoubleNode *GenUtils_BinaryTreeRoot(
  GenUtils_BinaryTree *binaryTree)
{
  if (GenUtils_BinaryTreeWasInit(binaryTree))
  {
    return binaryTree->root;
  }
  return NULL;
}

// Insert a node in a binary tree.
bool GenUtils_BinaryTreeInsert(
  GenUtils_BinaryTree *binaryTree,
  GenUtils_BinaryTreeKeyValue keyValue)
{
  // The node being processed.
  GenUtils_DoubleNode *currentNode =
    GenUtils_BinaryTreeRoot(binaryTree);
  // Store the current key/value pair.
  GenUtils_BinaryTreeKeyValue *currentKeyValue = NULL;
  // Result of string comparison.
  int comparison = 0;
  // Look in the tree to insert a leaf if possible.
  while (currentNode != NULL)
  {
    // Set the current key/value pair.
    currentKeyValue = currentNode->userdata;
    // Make a string comparison.
    comparison = strcmp(currentKeyValue->key, keyValue.key);
    if (comparison == 0)
    {
      // If the key is found, return false.
      return false;
    }
    else if (comparison < 0)
    {
      // If there isn't a left child, insert a new node.
      if (currentNode->first == NULL)
      {
        currentNode->first =
          malloc(sizeof(GenUtils_DoubleNode));
        // Returns if it can't allocate memory.
        if (currentNode->first == NULL)
        {
          return false;
        }
        // Initialize the node.
        currentNode->first->first = NULL;
        currentNode->first->second = NULL;
        binaryTree->size++;
        return true;
      }
      else
      {
        // If the right node is used, follows it.
        currentNode = currentNode->first;
      }
    }
    else
    {
      // If there isn't a right child, insert a new node.
      if (currentNode->second == NULL)
      {
        currentNode->second =
          malloc(sizeof(GenUtils_DoubleNode));
        // Returns if it can't allocate memory.
        if (currentNode->second == NULL)
        {
          return false;
        }
        // Initialize the node.
        currentNode->second->first = NULL;
        currentNode->second->second = NULL;
        binaryTree->size++;
        return true;
      }
      else
      {
        // If the left node is used, follows it.
        currentNode = currentNode->second;
      }
    }
  }
  return false;
}

// Remove a node from a binary tree.
void *GenUtils_BinaryTreeRemove(
  GenUtils_BinaryTree *binaryTree, const char *key)
{
  // Current node being processed.
  GenUtils_DoubleNode *currentNode =
    GenUtils_BinaryTreeRoot(binaryTree);
  // Previous node.
  GenUtils_DoubleNode *previousNode = NULL;
  // The node that will replace the node.
  GenUtils_DoubleNode *replaceNode = NULL;
  // The node previous to replace node.
  GenUtils_DoubleNode *previousReplaceNode = NULL;
  // Pair of current key/value node.
  GenUtils_BinaryTreeKeyValue *keyValue = NULL;
  // String comparison result.
  int comparison = 0;
  // The value to return.
  void *value = NULL;
  // Search the key.
  while (currentNode != NULL)
  {
    // Get the current key/value pair of the current node.
    keyValue = currentNode->userdata;
    // Compare the keys.
    comparison = strcmp(key, keyValue->key);
    // Cases for key comparison.
    if (comparison < 0)
    {
      previousNode = currentNode;
      currentNode = currentNode->first;
    }
    else if (comparison > 0)
    {
      previousNode = currentNode;
      currentNode = currentNode->second;
    }
    else
    {
      // If the key is found, break the loop.
      break;
    }
  }
  // If the key is not found, return false.
  if (currentNode == NULL)
  {
    return false;
  }
  // If the node have almost one child.
  if (currentNode->first == NULL ||
      currentNode->second == NULL)
  {
    // Set the replace node to left if exists.
    if (currentNode->first != NULL)
    {
      replaceNode = currentNode->first;
    }
    else
    {
      // Set the replace node to right, even if it's NULL.
      replaceNode = currentNode->second;
    }
    // If the node to delete is the root node, set a new
    // root node.
    if (previousNode == NULL)
    {
      binaryTree->root = replaceNode;
    }
    else if (currentNode == previousNode->first)
    {
      // Set the pointer to the current node as the replace
      // node.
      previousNode->first = replaceNode;
    }
    else
    {
      // Same as before, but with the right node.
      previousNode->second = replaceNode;
    }
    // Free the node.
    free(currentNode);
  }
  else
  {
    // If the node have two childs.
    replaceNode = currentNode->first;
    while (replaceNode->second != NULL)
    {
      previousReplaceNode = replaceNode;
      replaceNode = replaceNode->second;
    }
    // Case depending on the previous node.
    if (previousNode == NULL)
    {
      // If the node to replace is the rootv set it as the
      // root.
      binaryTree->root = replaceNode;
    }
    else if (previousNode->first == currentNode)
    {
      previousNode->first = replaceNode;
    }
    else
    {
      previousNode->second = replaceNode;
    }
    // Set the new links of the replacing node.
    if (previousReplaceNode == NULL)
    {
      previousReplaceNode = currentNode->first;
    }
    previousReplaceNode->second = replaceNode->first;
    replaceNode->first = currentNode->first;
    replaceNode->second = currentNode->second;
    free(currentNode);
  }
  // Reduce the size of the tree.
  binaryTree->size--;
  return keyValue->value;
}

// Remove a node from a binary tree.
bool GenUtils_BinaryTreeRemoveBool(
  GenUtils_BinaryTree *binaryTree, const char *key)
{
  // Current node being processed.
  GenUtils_DoubleNode *currentNode =
    GenUtils_BinaryTreeRoot(binaryTree);
  // Previous node.
  GenUtils_DoubleNode *previousNode = NULL;
  // The node that will replace the node.
  GenUtils_DoubleNode *replaceNode = NULL;
  // The node previous to replace node.
  GenUtils_DoubleNode *previousReplaceNode = NULL;
  // Pair of current key/value node.
  GenUtils_BinaryTreeKeyValue *keyValue = NULL;
  // String comparison result.
  int comparison = 0;
  // Search the key.
  while (currentNode != NULL)
  {
    // Get the current key/value pair of the current node.
    keyValue = currentNode->userdata;
    // Compare the keys.
    comparison = strcmp(key, keyValue->key);
    // Cases for key comparison.
    if (comparison < 0)
    {
      previousNode = currentNode;
      currentNode = currentNode->first;
    }
    else if (comparison > 0)
    {
      previousNode = currentNode;
      currentNode = currentNode->second;
    }
    else
    {
      // If the key is found, break the loop.
      break;
    }
  }
  // If the key is not found, return false.
  if (currentNode == NULL)
  {
    return false;
  }
  // If the node have almost one child.
  if (currentNode->first == NULL ||
      currentNode->second == NULL)
  {
    // Set the replace node to left if exists.
    if (currentNode->first != NULL)
    {
      replaceNode = currentNode->first;
    }
    else
    {
      // Set the replace node to right, even if it's NULL.
      replaceNode = currentNode->second;
    }
    // If the node to delete is the root node, set a new
    // root node.
    if (previousNode == NULL)
    {
      binaryTree->root = replaceNode;
    }
    else if (currentNode == previousNode->first)
    {
      // Set the pointer to the current node as the replace
      // node.
      previousNode->first = replaceNode;
    }
    else
    {
      // Same as before, but with the right node.
      previousNode->second = replaceNode;
    }
    // Free the data and the node.
    free(currentNode->userdata);
    free(currentNode);
  }
  else
  {
    // If the node have two childs.
    replaceNode = currentNode->first;
    while (replaceNode->second != NULL)
    {
      previousReplaceNode = replaceNode;
      replaceNode = replaceNode->second;
    }
    // Case depending on the previous node.
    if (previousNode == NULL)
    {
      // If the node to replace is the rootv set it as the
      // root.
      binaryTree->root = replaceNode;
    }
    else if (previousNode->first == currentNode)
    {
      previousNode->first = replaceNode;
    }
    else
    {
      previousNode->second = replaceNode;
    }
    // Set the new links of the replacing node.
    if (previousReplaceNode == NULL)
    {
      previousReplaceNode = currentNode->first;
    }
    previousReplaceNode->second = replaceNode->first;
    replaceNode->first = currentNode->first;
    replaceNode->second = currentNode->second;
    free(currentNode->userdata);
    free(currentNode);
  }
  // Reduce the size of the tree.
  binaryTree->size--;
  return true;
}

// Make and return a sorted array from a binary tree.
GenUtils_BinaryTreeKeyValue *GenUtils_BinaryTreeToArray(
  GenUtils_BinaryTree *tree)
{
  // Information of the array to create.
  GenUtils_BinaryTreeInternalArrayInfo arrayInfo = {0};
  // Create the array.
  arrayInfo.array =
    malloc(sizeof(GenUtils_BinaryTreeKeyValue) *
           GenUtils_BinaryTreeGetSize(tree));
  // If can't create the array, return NULL.
  if (arrayInfo.array == NULL)
  {
    return NULL;
  }
  // Make the inorder traversal with internal function.
  GenUtils_BinaryTreeInorder(
    tree, &arrayInfo, GenUtils_BinaryTreeInternalToArray);
  // Return the array.
  return arrayInfo.array;
}

// Make a binary tree from an array.
GenUtils_BinaryTree *GenUtils_BinaryTreeFromArray(
  GenUtils_BinaryTreeKeyValue *array, size_t size)
{
  // Make a binary tree.
  GenUtils_BinaryTree *binaryTree =
    GenUtils_BinaryTreeCreate();
  // Insert every element in the binary tree.
  for (size_t i = 0; i < size; i++)
  {
    if (!GenUtils_BinaryTreeInsert(binaryTree, array[i]))
    {
      GenUtils_BinaryTreeDestroy(binaryTree);
      return NULL;
    }
  }
  return binaryTree;
}

// Make a balanced binary tree.
GenUtils_BinaryTree *GenUtils_BinaryTreeBalance(
  GenUtils_BinaryTree *binaryTree)
{
  // Sorted array of key/value pairs.
  GenUtils_BinaryTreeKeyValue *array = NULL;
  // The balanced tree.
  GenUtils_BinaryTree *balancedTree = NULL;
  // Make the sorted array.
  array = GenUtils_BinaryTreeToArray(binaryTree);
  // If the array was created, make the binary tree.
  if (array != NULL)
  {
    balancedTree =
      GenUtils_BinaryTreeFromArray(array, binaryTree->size);
  }
  else
  {
    return NULL;
  }
  // Return the new tree.
  free(array);
  GenUtils_BinaryTreeDestroy(binaryTree);
  return balancedTree;
}

// Removes all the nodes of a binary tree.
void GenUtils_BinaryTreeClear(
  GenUtils_BinaryTree *binaryTree)
{
  // Clear the tree.
  GenUtils_BinaryTreeInternalClear(
    GenUtils_BinaryTreeRoot(binaryTree));
  // Reset all the values.
  binaryTree->root = NULL;
  binaryTree->size = 0;
}

// Preorder traversal.
void GenUtils_BinaryTreePreorder(
  GenUtils_BinaryTree *binaryTree, void *extradata,
  void (*function)(
    const GenUtils_BinaryTreeKeyValue *, void *))
{
  GenUtils_BinaryTreeInternalPreorder(
    GenUtils_BinaryTreeRoot(binaryTree), extradata,
    function);
}

// Inorder traversal.
void GenUtils_BinaryTreeInorder(
  GenUtils_BinaryTree *binaryTree, void *extradata,
  void (*function)(
    const GenUtils_BinaryTreeKeyValue *, void *))
{
  GenUtils_BinaryTreeInternalInorder(
    GenUtils_BinaryTreeRoot(binaryTree), extradata,
    function);
}

// Postorder traversal.
void GenUtils_BinaryTreePostorder(
  GenUtils_BinaryTree *binaryTree, void *extradata,
  void (*function)(
    const GenUtils_BinaryTreeKeyValue *, void *))
{
  GenUtils_BinaryTreeInternalPostorder(
    GenUtils_BinaryTreeRoot(binaryTree), extradata,
    function);
}

// Internal function, do an inorder traversal to make an
// array.
static void GenUtils_BinaryTreeInternalToArray(
  const GenUtils_BinaryTreeKeyValue *keyValue, void *data)
{
  // Array info passed to the function.
  GenUtils_BinaryTreeInternalArrayInfo *arrayInfo = data;
  // Set the element of the array and increase it's index.
  arrayInfo->array[arrayInfo->i].key = keyValue->key;
  arrayInfo->array[arrayInfo->i].value = keyValue->value;
  arrayInfo->i++;
}

// Removes all the nodes of a binary tree.
static void GenUtils_BinaryTreeInternalClear(
  GenUtils_DoubleNode *root)
{
  // Base case.
  if (root != NULL)
  {
    GenUtils_BinaryTreeInternalClear(root->first);
    GenUtils_BinaryTreeInternalClear(root->second);
    free(root->userdata);
    free(root);
  }
}

// Auxiliar function for preorder tree traversal.
static void GenUtils_BinaryTreeInternalPreorder(
  GenUtils_DoubleNode *root, void *extradata,
  void (*function)(
    const GenUtils_BinaryTreeKeyValue *, void *))
{
  // Base case.
  if (root != NULL && function != NULL)
  {
    function(root->userdata, extradata);
    GenUtils_BinaryTreeInternalPreorder(
      root->first, function, extradata);
    GenUtils_BinaryTreeInternalPreorder(
      root->second, function, extradata);
  }
}

// Auxiliar function for inorder tree traversal.
static void GenUtils_BinaryTreeInternalInorder(
  GenUtils_DoubleNode *root, void *extradata,
  void (*function)(
    const GenUtils_BinaryTreeKeyValue *, void *))
{
  // Base case.
  if (root != NULL && function != NULL)
  {
    GenUtils_BinaryTreeInternalPreorder(
      root->first, function, extradata);
    function(root->userdata, extradata);
    GenUtils_BinaryTreeInternalPreorder(
      root->second, function, extradata);
  }
}

// Auxiliar function for postorder tree traversal.
static void GenUtils_BinaryTreeInternalPostorder(
  GenUtils_DoubleNode *root, void *extradata,
  void (*function)(
    const GenUtils_BinaryTreeKeyValue *, void *))
{
  // Base case.
  if (root != NULL && function != NULL)
  {
    GenUtils_BinaryTreeInternalPreorder(
      root->first, function, extradata);
    GenUtils_BinaryTreeInternalPreorder(
      root->second, function, extradata);
    function(root->userdata, extradata);
  }
}
