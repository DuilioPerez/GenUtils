// File: CSLL.c
// Author: DP-Dev
// Implementation of a CSLL.
#include <GenUtils/CSLL.h>

// Creates a CSLL struture.
GenUtils_CSLL *GenUtils_CSLLCreate()
{
  // Allocate memory for the new list.
  GenUtils_CSLL *list = malloc(sizeof(GenUtils_CSLL));
  // Return if was unable to allocate memory.
  if (list == NULL)
  {
    return NULL;
  }
  // Initialize the structure.
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  // Return the list.
  return list;
}

// Destroy a CSLL.
void GenUtils_CSLLDestroy(GenUtils_CSLL *list)
{
  GenUtils_CSLLClear(list);
  free(list);
}

// Get the size of a list.
size_t GenUtils_CSLLGetSize(GenUtils_CSLL *list)
{
  // Get the size of the list.
  if (GenUtils_CSLLWasInit(list))
  {
    return list->size;
  }
  return 0;
}

// Query if a list is empty.
bool GenUtils_CSLLEmpty(GenUtils_CSLL *list)
{
  // Check if the list is actually empty.
  if (GenUtils_CSLLWasInit(list) && list->size == 0)
  {
    return true;
  }
  return false;
}

// Check if a CSLL was initialized.
bool GenUtils_CSLLWasInit(GenUtils_CSLL *list)
{
  // Check if the list was initialized.
  if (list != NULL)
  {
    return true;
  }
  return false;
}

// Get the head of the list.
GenUtils_SingleNode *GenUtils_CSLLBegin(GenUtils_CSLL *list)
{
  // Return the head pointer if is possible.
  if (!GenUtils_CSLLWasInit(list))
  {
    return NULL;
  }
  return list->head;
}

// Get the tail of the list.
GenUtils_SingleNode *GenUtils_CSLLEnd(GenUtils_CSLL *list)
{
  // Return the tail node if possible.
  if (!GenUtils_CSLLWasInit(list))
  {
    return NULL;
  }
  return list->tail;
}

// Insert data in a node.
bool GenUtils_CSLLInsert(GenUtils_CSLL *list,
  GenUtils_SingleNode *node, void *userdata)
{
  // Create a temporal node.
  GenUtils_SingleNode *tempNode = NULL;
  // Check the list and the node.
  if (!GenUtils_CSLLWasInit(list))
  {
    return false;
  }
  else if (GenUtils_CSLLGetSize(list) > 0 &&
           (node == NULL || node->nextNode == NULL))
  {
    return false;
  }
  // If the list is new, just append.
  if (list->size == 0)
  {
    tempNode = malloc(sizeof(GenUtils_SingleNode));
    if (tempNode == NULL)
    {
      return false;
    }
    list->head = tempNode;
    list->tail = tempNode;
    tempNode->userdata = userdata;
    tempNode->nextNode = tempNode;
    list->size = 1;
  }
  // Do additional logic in other case.
  else
  {
    tempNode = malloc(sizeof(GenUtils_SingleNode));
    if (tempNode == NULL)
    {
      return false;
    }
    tempNode->userdata = node->userdata;
    tempNode->nextNode = node->nextNode;
    node->nextNode = tempNode;
    node->userdata = userdata;
    list->size++;
    if (node == GenUtils_CSLLEnd(list))
    {
      list->tail = tempNode;
    }
  }
  return true;
}

// The same insertion algorithm with some minor
// modifications.
bool GenUtils_CSLLInsertAfter(GenUtils_CSLL *list,
  GenUtils_SingleNode *node, void *userdata)
{
  // Create a temporal node.
  GenUtils_SingleNode *tempNode = NULL;
  // Check the list and the node.
  if (!GenUtils_CSLLWasInit(list))
  {
    return false;
  }
  else if (GenUtils_CSLLGetSize(list) > 0 && node == NULL)
  {
    return false;
  }
  // If the list is new, just append.
  if (list->size == 0)
  {
    tempNode = malloc(sizeof(GenUtils_SingleNode));
    if (tempNode == NULL)
    {
      return false;
    }
    list->head = tempNode;
    list->tail = tempNode;
    tempNode->userdata = userdata;
    tempNode->nextNode = tempNode;
    list->size = 1;
  }
  // Do additional logic in other case.
  else
  {
    tempNode = malloc(sizeof(GenUtils_SingleNode));
    if (tempNode == NULL)
    {
      return false;
    }
    tempNode->userdata = userdata;
    tempNode->nextNode = node->nextNode;
    node->nextNode = tempNode;
    list->size++;
    if (node == GenUtils_CSLLEnd(list))
    {
      list->tail = tempNode;
    }
  }
  return true;
}

// Remove a node.
bool GenUtils_CSLLRemove(
  GenUtils_CSLL *list, GenUtils_SingleNode *node)
{
  // The sentinel node.
  GenUtils_SingleNode *currentNode = NULL;
  // Check the list and the node.
  if (!GenUtils_CSLLWasInit(list) || node == NULL ||
      node->nextNode == NULL)
  {
    return false;
  }
  // If the list have only one element, reset all.
  else if (list->size == 1)
  {
    free(list->head);
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
  }
  // Do additional logic in other case.
  else
  {
    currentNode = GenUtils_CSLLEnd(list);
    while (currentNode->nextNode != node)
    {
      currentNode = currentNode->nextNode;
    }
    if (node == list->head)
    {
      list->head = list->head->nextNode;
    }
    else if (node == list->tail)
    {
      list->tail = currentNode;
    }
    currentNode->nextNode = node->nextNode;
    free(node);
    list->size--;
  }
  return true;
}

// Remove the node next to one.
bool GenUtils_CSLLRemoveAfter(
  GenUtils_CSLL *list, GenUtils_SingleNode *node)
{
  // The sentinel node.
  GenUtils_SingleNode *currentNode = NULL;
  // Check the list and the node.
  if (!GenUtils_CSLLWasInit(list) || node == NULL ||
      node->nextNode == NULL)
  {
    return false;
  }
  // If the list have only one element, reset all.
  else if (list->size == 1)
  {
    free(list->head);
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return true;
  }
  // Do additional logic in other case.
  else
  {
    currentNode = node;
    node = node->nextNode;
    if (node == list->tail)
    {
      list->tail = currentNode;
    }
    else if (node == list->head)
    {
      list->head = list->head->nextNode;
    }
    currentNode->nextNode = node->nextNode;
    free(node);
    list->size--;
  }
  return true;
}

// Add data at the tail of the list.
bool GenUtils_CSLLPushBack(
  GenUtils_CSLL *list, void *userdata)
{
  return GenUtils_CSLLInsertAfter(
    list, GenUtils_CSLLEnd(list), userdata);
}

// Insert data at the head of the list.
bool GenUtils_CSLLPushFront(
  GenUtils_CSLL *list, void *userdata)
{
  return GenUtils_CSLLInsert(
    list, GenUtils_CSLLBegin(list), userdata);
}

// Remove and return data from the tail of the list.
void *GenUtils_CSLLPopBack(GenUtils_CSLL *list)
{
  // Get the last node.
  GenUtils_SingleNode *node = GenUtils_CSLLEnd(list);
  // Data of the node.
  void *data = (node == NULL ? NULL : node->userdata);
  GenUtils_CSLLRemove(list, node);
  return data;
}

// Remove data from the tail of the list.
bool GenUtils_CSLLPopBackBool(GenUtils_CSLL *list)
{
  return GenUtils_CSLLRemove(list, GenUtils_CSLLEnd(list));
}

// Remove and return data from the head of the list.
void *GenUtils_CSLLPopFront(GenUtils_CSLL *list)
{
  // Get the first node.
  GenUtils_SingleNode *node = GenUtils_CSLLBegin(list);
  // Data of the node.
  void *data = (node == NULL ? NULL : node->userdata);
  GenUtils_CSLLRemove(list, node);
  return data;
}

// Remove data from the beginning of the list.
bool GenUtils_CSLLPopFrontBool(GenUtils_CSLL *list)
{
  return GenUtils_CSLLRemove(
    list, GenUtils_CSLLBegin(list));
}

// Remove all the elements of a list.
void GenUtils_CSLLClear(GenUtils_CSLL *list)
{
  while (GenUtils_CSLLGetSize(list) > 0)
  {
    GenUtils_CSLLPopFront(list);
  }
}

// Iterate a list wth a function.
void GenUtils_CSLLIterate(GenUtils_CSLL *list,
  void *extradata, void (*function)(void *, void *))
{
  // The current node.
  GenUtils_SingleNode *currentNode =
    GenUtils_CSLLBegin(list);
  // The index of the current element.
  size_t i = 0;
  // Verify the function.
  if (function == NULL)
  {
    return;
  }
  // Calls the function.
  while (i < GenUtils_CSLLGetSize(list))
  {
    function(currentNode->userdata, extradata);
    i++;
    currentNode = currentNode->nextNode;
  }
}
