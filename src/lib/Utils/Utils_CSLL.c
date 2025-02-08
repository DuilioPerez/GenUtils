// File: Utils_CSLL.c
// Author: DP-Dev
// Implementation of a CSLL.
#include <Utils/Utils_CSLL.h>

// Creates a CSLL struture.
Utils_CSLL *Utils_CSLLCreate()
{
  // Allocate memory for the new list.
  Utils_CSLL *list = malloc(sizeof(Utils_CSLL));
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
void Utils_CSLLDestroy(Utils_CSLL *list)
{
  Utils_CSLLClear(list);
  free(list);
}

// Get the size of a list.
size_t Utils_CSLLGetSize(Utils_CSLL *list)
{
  // Get the size of the list.
  if (Utils_CSLLWasInit(list))
  {
    return list->size;
  }
  return 0;
}

// Query if a list is empty.
bool Utils_CSLLEmpty(Utils_CSLL *list)
{
  // Check if the list is actually empty.
  if (Utils_CSLLWasInit(list) && list->size == 0)
  {
    return true;
  }
  return false;
}

// Check if a CSLL was initialized.
bool Utils_CSLLWasInit(Utils_CSLL *list)
{
  // Check if the list was initialized.
  if (list != NULL)
  {
    return true;
  }
  return false;
}

// Get the head of the list.
Utils_SingleNode *Utils_CSLLBegin(Utils_CSLL *list)
{
  // Return the head pointer if is possible.
  if (!Utils_CSLLWasInit(list))
  {
    return NULL;
  }
  return list->head;
}

// Get the tail of the list.
Utils_SingleNode *Utils_CSLLEnd(Utils_CSLL *list)
{
  // Return the tail node if possible.
  if (!Utils_CSLLWasInit(list))
  {
    return NULL;
  }
  return list->tail;
}

// Insert data in a node.
bool Utils_CSLLInsert(
  Utils_CSLL *list, Utils_SingleNode *node, void *userdata)
{
  // Create a temporal node.
  Utils_SingleNode *tempNode = NULL;
  // Check the list and the node.
  if (!Utils_CSLLWasInit(list))
  {
    return false;
  }
  else if (Utils_CSLLGetSize(list) > 0 &&
           (node == NULL || node->nextNode == NULL))
  {
    return false;
  }
  // If the list is new, just append.
  if (list->size == 0)
  {
    tempNode = malloc(sizeof(Utils_SingleNode));
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
    tempNode = malloc(sizeof(Utils_SingleNode));
    if (tempNode == NULL)
    {
      return false;
    }
    tempNode->userdata = node->userdata;
    tempNode->nextNode = node->nextNode;
    node->nextNode = tempNode;
    node->userdata = userdata;
    list->size++;
    if (node == Utils_CSLLEnd(list))
    {
      list->tail = tempNode;
    }
  }
  return true;
}

// The same insertion algorithm with some minor
// modifications.
bool Utils_CSLLInsertAfter(
  Utils_CSLL *list, Utils_SingleNode *node, void *userdata)
{
  // Create a temporal node.
  Utils_SingleNode *tempNode = NULL;
  // Check the list and the node.
  if (!Utils_CSLLWasInit(list))
  {
    return false;
  }
  else if (Utils_CSLLGetSize(list) > 0 && node == NULL)
  {
    return false;
  }
  // If the list is new, just append.
  if (list->size == 0)
  {
    tempNode = malloc(sizeof(Utils_SingleNode));
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
    tempNode = malloc(sizeof(Utils_SingleNode));
    if (tempNode == NULL)
    {
      return false;
    }
    tempNode->userdata = userdata;
    tempNode->nextNode = node->nextNode;
    node->nextNode = tempNode;
    list->size++;
    if (node == Utils_CSLLEnd(list))
    {
      list->tail = tempNode;
    }
  }
  return true;
}

// Remove a node.
bool Utils_CSLLRemove(
  Utils_CSLL *list, Utils_SingleNode *node)
{
  // The sentinel node.
  Utils_SingleNode *currentNode = NULL;
  // Check the list and the node.
  if (!Utils_CSLLWasInit(list) || node == NULL ||
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
    currentNode = Utils_CSLLEnd(list);
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
bool Utils_CSLLRemoveAfter(
  Utils_CSLL *list, Utils_SingleNode *node)
{
  // The sentinel node.
  Utils_SingleNode *currentNode = NULL;
  // Check the list and the node.
  if (!Utils_CSLLWasInit(list) || node == NULL ||
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
bool Utils_CSLLPushBack(Utils_CSLL *list, void *userdata)
{
  return Utils_CSLLInsertAfter(
    list, Utils_CSLLEnd(list), userdata);
}

// Remove data from the tail of the list.
bool Utils_CSLLPopBack(Utils_CSLL *list)
{
  return Utils_CSLLRemove(list, Utils_CSLLEnd(list));
}

// Insert data at the head of the list.
bool Utils_CSLLPushFront(Utils_CSLL *list, void *userdata)
{
  return Utils_CSLLInsert(
    list, Utils_CSLLBegin(list), userdata);
}

// Remove data from the beginning of the list.
bool Utils_CSLLPopFront(Utils_CSLL *list)
{
  return Utils_CSLLRemove(list, Utils_CSLLBegin(list));
}

// Remove all the elements of a list.
void Utils_CSLLClear(Utils_CSLL *list)
{
  while (Utils_CSLLGetSize(list) > 0)
  {
    Utils_CSLLPopFront(list);
  }
}
