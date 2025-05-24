// File: Stack.c
// Author: DP-Dev
// Definition of the stack API.
#include <GenUtils/CDLL.h>
#include <GenUtils/Stack.h>

// Create a stack.
GenUtils_Stack *GenUtils_StackCreate()
{
  return GenUtils_CDLLCreate();
}

// Verify if a stack was init.
bool GenUtils_StackWasInit(GenUtils_Stack *stack)
{
  return GenUtils_CDLLWasInit(stack);
}

// Destroy a stack.
void GenUtils_StackDestroy(GenUtils_Stack *stack)
{
  GenUtils_CDLLDestroy(stack);
}

// Get the size of a stack.
size_t GenUtils_StackGetSize(GenUtils_Stack *stack)
{
  return GenUtils_CDLLGetSize(stack);
}

// Query if a stack is empty.
bool GenUtils_StackEmpty(GenUtils_Stack *stack)
{
  return GenUtils_CDLLEmpty(stack);
}

// Push an element in the stack.
bool GenUtils_StackPush(
  GenUtils_Stack *stack, void *userdata)
{
  return GenUtils_CDLLPushBack(stack, userdata);
}

// Pop and return value.
bool GenUtils_StackPop(GenUtils_Stack *stack)
{
  return GenUtils_CDLLPopBack(stack);
}

// Pop an element from a stack.
bool GenUtils_StackPopBool(GenUtils_Stack *stack)
{
  return GenUtils_CDLLPopBackBool(stack);
}

// Get the element in the top of a stack.
void *GenUtils_StackTop(GenUtils_Stack *stack)
{
  if (GenUtils_CDLLWasInit(stack) &&
      !GenUtils_CDLLEmpty(stack))
  {
    return GenUtils_CDLLEnd(stack)->userdata;
  }
  return NULL;
}

// Clear a stack.
void GenUtils_StackClear(GenUtils_Stack *stack)
{
  GenUtils_CDLLClear(stack);
}
