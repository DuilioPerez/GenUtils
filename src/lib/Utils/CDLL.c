// File: CDLL.c
// Author: DP-Dev
// Implementation of a CDLL.
#include <Utils/CDLL.h>

// Creates a CDLL struture.
Utils_CDLL *Utils_CDLLCreate()
{
  // Allocate memory for the new list.
  Utils_CDLL *list = malloc(sizeof(Utils_CDLL));
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
void Utils_CDLLDestroy(Utils_CDLL *list)
{
  Utils_CDLLClear(list);
  free(list);
}

// Get the size of a list.
size_t Utils_CDLLGetSize(Utils_CDLL *list)
{
  // Get the size of the list.
  if (Utils_CDLLWasInit(list))
  {
    return list->size;
  }
  return 0;
}

// Query if a list is empty.
bool Utils_CDLLEmpty(Utils_CDLL *list)
{
  // Check if the list is actually empty.
  if (Utils_CDLLWasInit(list) && list->size == 0)
  {
    return true;
  }
  return false;
}

// Check if a CDLL was initialized.
bool Utils_CDLLWasInit(Utils_CDLL *list)
{
  // Check if the list was initialized.
  if (list != NULL)
  {
    return true;
  }
  return false;
}

// Get the head of the list.
Utils_DoubleNode *Utils_CDLLBegin(Utils_CDLL *list)
{
  // Return the head pointer if is possible.
  if (!Utils_CDLLWasInit(list))
  {
    return NULL;
  }
  return list->head;
}

// Get the tail of the list.
Utils_DoubleNode *Utils_CDLLEnd(Utils_CDLL *list)
{
  // Return the tail node if possible.
  if (!Utils_CDLLWasInit(list) ||
      Utils_CDLLGetSize(list) == 0)
  {
    return NULL;
  }
  return list->head->prevNode;
}

// Insert data in a node.
bool Utils_CDLLInsert(
  Utils_CDLL *list, Utils_DoubleNode *node, void *userdata)
{
  // Create a temporal node.
  Utils_DoubleNode *tempNode = NULL;
  // Check the list and the node.
  if (!Utils_CDLLWasInit(list))
  {
    return false;
  }
  else if (Utils_CDLLGetSize(list) > 0 &&
           (node == NULL || node->nextNode == NULL))
  {
    return false;
  }
  // If the list is new, create the first node.
  if (list->size == 0)
  {
    tempNode = malloc(sizeof(Utils_DoubleNode));
    if (tempNode == NULL)
    {
      return false;
    }
    list->head = tempNode;
    tempNode->userdata = userdata;
    tempNode->nextNode = tempNode;
    tempNode->prevNode = tempNode;
    list->size = 1;
  }
  // Do additional logic in other case.
  else
  {
    tempNode = malloc(sizeof(Utils_DoubleNode));
    if (tempNode == NULL)
    {
      return false;
    }
    tempNode->userdata = userdata;
    tempNode->prevNode = node->prevNode;
    tempNode->nextNode = node;
    tempNode->prevNode->nextNode = tempNode;
    tempNode->nextNode->prevNode = tempNode;
    if (node == list->head)
    {
      list->head = tempNode;
    }
    list->size++;
  }
  return true;
}

// The same insertion algorithm with some ninor
// modifications.
bool Utils_CDLLInsertAfter(
  Utils_CDLL *list, Utils_DoubleNode *node, void *userdata)
{
  // Create a temporal node.
  Utils_DoubleNode *tempNode = NULL;
  // Check the list and the node.
  if (!Utils_CDLLWasInit(list))
  {
    return false;
  }
  else if (Utils_CDLLGetSize(list) > 0 &&
           (node == NULL || node->nextNode == NULL))
  {
    return false;
  }
  // If the list is new, create the first node.
  if (list->size == 0)
  {
    tempNode = malloc(sizeof(Utils_DoubleNode));
    if (tempNode == NULL)
    {
      return false;
    }
    list->head = tempNode;
    tempNode->userdata = userdata;
    tempNode->nextNode = tempNode;
    tempNode->prevNode = tempNode;
    list->size = 1;
  }
  // Do additional logic in other case.
  else
  {
    tempNode = malloc(sizeof(Utils_DoubleNode));
    if (tempNode == NULL)
    {
      return false;
    }
    tempNode->userdata = userdata;
    tempNode->prevNode = node;
    tempNode->nextNode = node->nextNode;
    tempNode->prevNode->nextNode = tempNode;
    tempNode->nextNode->prevNode = tempNode;
    list->size++;
  }
  return true;
}

// Remove a node.
bool Utils_CDLLRemove(
  Utils_CDLL *list, Utils_DoubleNode *node)
{
  // Check the list and the node.
  if (!Utils_CDLLWasInit(list) || node == NULL ||
      node->nextNode == NULL)
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
      list->head = list->head->nextNode;
    }
    node->prevNode->nextNode = node->nextNode;
    node->nextNode->prevNode = node->prevNode;
    free(node);
    list->size--;
  }
  return true;
}

// Remove the node next to one.
bool Utils_CDLLRemoveAfter(
  Utils_CDLL *list, Utils_DoubleNode *node)
{
  // Verify the node.
  if (node == NULL || node->nextNode == NULL)
  {
    return false;
  }
  return Utils_CDLLRemove(list, node->nextNode);
}

// Add data at the tail of the list.
bool Utils_CDLLPushBack(Utils_CDLL *list, void *userdata)
{
  return Utils_CDLLInsertAfter(
    list, Utils_CDLLEnd(list), userdata);
}

// Remove data from the tail of the list.
bool Utils_CDLLPopBack(Utils_CDLL *list)
{
  return Utils_CDLLRemove(list, Utils_CDLLEnd(list));
}

// Insert data at the head of the list.
bool Utils_CDLLPushFront(Utils_CDLL *list, void *userdata)
{
  return Utils_CDLLInsert(
    list, Utils_CDLLBegin(list), userdata);
}

// Remove data from the beginning of the list.
bool Utils_CDLLPopFront(Utils_CDLL *list)
{
  return Utils_CDLLRemove(list, Utils_CDLLBegin(list));
}

// Remove all the elements of a list.
void Utils_CDLLClear(Utils_CDLL *list)
{
  while (Utils_CDLLGetSize(list) > 0)
  {
    Utils_CDLLPopFront(list);
  }
}

// Iterate a list wth a function.
void Utils_CDLLIterate(Utils_CDLL *list, void *extradata,
  void (*function)(void *, void *))
{
  // The current node.
  Utils_DoubleNode *currentNode = Utils_CDLLBegin(list);
  // The index of the current element.
  size_t i = 0;
  // Verify the function.
  if (function == NULL)
  {
    return;
  }
  // Calls the function.
  while (i < Utils_CDLLGetSize(list))
  {
    function(currentNode->userdata, extradata);
    i++;
    currentNode = currentNode->nextNode;
  }
}
