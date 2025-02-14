// File: Stack.c
// Author: DP-Dev
// Definition of the stack API.
#include <Utils/CDLL.h>
#include <Utils/Stack.h>

// Create a stack.
Utils_Stack *Utils_StackCreate()
{
  return Utils_CDLLCreate();
}

// Verify if a stack was init.
bool Utils_StackWasInit(Utils_Stack *stack)
{
  return Utils_CDLLWasInit(stack);
}

// Destroy a stack.
void Utils_StackDestroy(Utils_Stack *stack)
{
  Utils_CDLLDestroy(stack);
}

// Get the size of a stack.
size_t Utils_StackGetSize(Utils_Stack *stack)
{
  return Utils_CDLLGetSize(stack);
}

// Query if a stack is empty.
bool Utils_StackEmpty(Utils_Stack *stack)
{
  return Utils_CDLLEmpty(stack);
}

// Push an element in the stack.
bool Utils_StackPush(Utils_Stack *stack, void *userdata)
{
  return Utils_CDLLPushBack(stack, userdata);
}

// Pop an element from a stack.
bool Utils_StackPop(Utils_Stack *stack)
{
  return Utils_CDLLPopBack(stack);
}

// Get the element in the top of a stack.
void *Utils_StackTop(Utils_Stack *stack)
{
  if (Utils_CDLLWasInit(stack) && !Utils_CDLLEmpty(stack))
  {
    return Utils_CDLLEnd(stack)->userdata;
  }
  return NULL;
}

// Clear a stack.
void Utils_StackClear(Utils_Stack *stack)
{
  Utils_CDLLClear(stack);
}
