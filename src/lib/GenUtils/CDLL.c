// File: CDLL.c
// Author: DP-Dev
// Implementation of a CDLL.
#include <GenUtils/CDLL.h>

// Creates a CDLL struture.
GenUtils_CDLL *GenUtils_CDLLCreate()
{
  // Allocate memory for the new list.
  GenUtils_CDLL *list = malloc(sizeof(GenUtils_CDLL));
  // Return if was unable to allocate memory.
  if (list == NULL)
  {
    return NULL;
  }
  // Initialize the structure.
  list->head = NULL;
  list->size = 0;
  // Return the list.
  return list;
}

// Destroy a CDLL.
void GenUtils_CDLLDestroy(GenUtils_CDLL *list)
{
  GenUtils_CDLLClear(list);
  free(list);
}

// Get the size of a list.
size_t GenUtils_CDLLGetSize(GenUtils_CDLL *list)
{
  // Get the size of the list.
  if (GenUtils_CDLLWasInit(list))
  {
    return list->size;
  }
  return 0;
}

// Query if a list is empty.
bool GenUtils_CDLLEmpty(GenUtils_CDLL *list)
{
  // Check if the list is actually empty.
  if (GenUtils_CDLLWasInit(list) && list->size == 0)
  {
    return true;
  }
  return false;
}

// Check if a CDLL was initialized.
bool GenUtils_CDLLWasInit(GenUtils_CDLL *list)
{
  // Check if the list was initialized.
  if (list != NULL)
  {
    return true;
  }
  return false;
}

// Get the head of the list.
GenUtils_DoubleNode *GenUtils_CDLLBegin(GenUtils_CDLL *list)
{
  // Return the head pointer if is possible.
  if (!GenUtils_CDLLWasInit(list))
  {
    return NULL;
  }
  return list->head;
}

// Get the tail of the list.
GenUtils_DoubleNode *GenUtils_CDLLEnd(GenUtils_CDLL *list)
{
  // Return the tail node if possible.
  if (!GenUtils_CDLLWasInit(list) ||
      GenUtils_CDLLGetSize(list) == 0)
  {
    return NULL;
  }
  return list->head->first;
}

// Insert data in a node.
bool GenUtils_CDLLInsert(GenUtils_CDLL *list,
  GenUtils_DoubleNode *node, void *userdata)
{
  // Create a temporal node.
  GenUtils_DoubleNode *tempNode = NULL;
  // Check the list and the node.
  if (!GenUtils_CDLLWasInit(list))
  {
    return false;
  }
  else if (GenUtils_CDLLGetSize(list) > 0 &&
           (node == NULL || node->second == NULL))
  {
    return false;
  }
  // If the list is new, create the first node.
  if (list->size == 0)
  {
    tempNode = malloc(sizeof(GenUtils_DoubleNode));
    if (tempNode == NULL)
    {
      return false;
    }
    list->head = tempNode;
    tempNode->userdata = userdata;
    tempNode->second = tempNode;
    tempNode->first = tempNode;
    list->size = 1;
  }
  // Do additional logic in other case.
  else
  {
    tempNode = malloc(sizeof(GenUtils_DoubleNode));
    if (tempNode == NULL)
    {
      return false;
    }
    tempNode->userdata = userdata;
    tempNode->first = node->first;
    tempNode->second = node;
    tempNode->first->second = tempNode;
    tempNode->second->first = tempNode;
    if (node == list->head)
    {
      list->head = tempNode;
    }
    list->size++;
  }
  return true;
}

// The same insertion algorithm with some minor
// modifications.
bool GenUtils_CDLLInsertAfter(GenUtils_CDLL *list,
  GenUtils_DoubleNode *node, void *userdata)
{
  // Create a temporal node.
  GenUtils_DoubleNode *tempNode = NULL;
  // Check the list and the node.
  if (!GenUtils_CDLLWasInit(list))
  {
    return false;
  }
  else if (GenUtils_CDLLGetSize(list) > 0 &&
           (node == NULL || node->second == NULL))
  {
    return false;
  }
  // If the list is new, create the first node.
  if (list->size == 0)
  {
    tempNode = malloc(sizeof(GenUtils_DoubleNode));
    if (tempNode == NULL)
    {
      return false;
    }
    list->head = tempNode;
    tempNode->userdata = userdata;
    tempNode->second = tempNode;
    tempNode->first = tempNode;
    list->size = 1;
  }
  // Do additional logic in other case.
  else
  {
    tempNode = malloc(sizeof(GenUtils_DoubleNode));
    if (tempNode == NULL)
    {
      return false;
    }
    tempNode->userdata = userdata;
    tempNode->first = node;
    tempNode->second = node->second;
    tempNode->first->second = tempNode;
    tempNode->second->first = tempNode;
    list->size++;
  }
  return true;
}

// Remove a node.
bool GenUtils_CDLLRemove(
  GenUtils_CDLL *list, GenUtils_DoubleNode *node)
{
  // Check the list and the node.
  if (!GenUtils_CDLLWasInit(list) || node == NULL ||
      node->second == NULL)
  {
    return false;
  }
  // If the list have only one element, reset all.
  else if (list->size == 1)
  {
    free(list->head);
    list->head = NULL;
    list->size = 0;
  }
  // Do additional logic in other case.
  else
  {
    if (node == list->head)
    {
      list->head = list->head->second;
    }
    node->first->second = node->second;
    node->second->first = node->first;
    free(node);
    list->size--;
  }
  return true;
}

// Remove the node next to one.
bool GenUtils_CDLLRemoveAfter(
  GenUtils_CDLL *list, GenUtils_DoubleNode *node)
{
  // Verify the node.
  if (node == NULL || node->second == NULL)
  {
    return false;
  }
  return GenUtils_CDLLRemove(list, node->second);
}

// Add data at the tail of the list.
bool GenUtils_CDLLPushBack(
  GenUtils_CDLL *list, void *userdata)
{
  return GenUtils_CDLLInsertAfter(
    list, GenUtils_CDLLEnd(list), userdata);
}

// Insert data at the head of the list.
bool GenUtils_CDLLPushFront(
  GenUtils_CDLL *list, void *userdata)
{
  return GenUtils_CDLLInsert(
    list, GenUtils_CDLLBegin(list), userdata);
}

// Remove and return data from the tail of the list.
void *GenUtils_CDLLPopBack(GenUtils_CDLL *list)
{
  // Get the first node.
  GenUtils_SingleNode *node = GenUtils_CDLLEnd(list);
  // Data of the node.
  void *data = (node == NULL ? NULL : node->userdata);
  GenUtils_CDLLRemove(list, node);
  return data;
}

// Remove data from the tail of the list.
bool GenUtils_CDLLPopBackBool(GenUtils_CDLL *list)
{
  return GenUtils_CDLLRemove(list, GenUtils_CDLLEnd(list));
}

// Remove data from the beginning of the list.
bool GenUtils_CDLLPopFront(GenUtils_CDLL *list)
{
  return GenUtils_CDLLRemove(
    list, GenUtils_CDLLBegin(list));
}

// Remove all the elements of a list.
void GenUtils_CDLLClear(GenUtils_CDLL *list)
{
  while (GenUtils_CDLLGetSize(list) > 0)
  {
    GenUtils_CDLLPopFront(list);
  }
}

// Iterate a list wth a function.
void GenUtils_CDLLIterate(GenUtils_CDLL *list,
  void *extradata, void (*function)(void *, void *))
{
  // The current node.
  GenUtils_DoubleNode *currentNode =
    GenUtils_CDLLBegin(list);
  // The index of the current element.
  size_t i = 0;
  // Verify the function.
  if (function == NULL)
  {
    return;
  }
  // Calls the function.
  while (i < GenUtils_CDLLGetSize(list))
  {
    function(currentNode->userdata, extradata);
    i++;
    currentNode = currentNode->second;
  }
}
