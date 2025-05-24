/// @file Stack.h
/// @author DP-Dev
/// @brief Implementation of a stack.
#ifndef GENUTILS_STACK_H
#define GENUTILS_STACK_H true
#ifdef __cplusplus
extern "C"
{
#endif
#include <stdbool.h>
#include <stdlib.h>

  /// @brief Define stack as a synonim of a CDLL.
  typedef struct GenUtils_CDLL GenUtils_Stack;

  /// @brief Create a stack.
  /// @return NULL in error or a valid pointer in success.
  GenUtils_Stack *GenUtils_StackCreate();

  /// @brief Query if  a stack was initialized.
  /// @param stack The stack to query.
  /// @return true if the stack was initialized.
  bool GenUtils_StackWasInit(GenUtils_Stack *stack);

  /// @brief Destroy a stack.
  /// @param stack The stack to destroy.
  void GenUtils_StackDestroy(GenUtils_Stack *stack);

  /// @brief Get the size of a stack.
  /// @param stack The stack to query.
  /// @return The number of elements in the stack.
  size_t GenUtils_StackGetSize(GenUtils_Stack *stack);

  /// @brief Query if a stack is empty.
  /// @param stack The stack to query.
  /// @return true if the stack is empty.
  bool GenUtils_StackEmpty(GenUtils_Stack *stack);

  /// @brief Push the element in the top of a stack.
  /// @param stack The stack where the data will be pushed.
  /// @param userdata The data to push.
  /// @return true in success, false otherwise.
  bool GenUtils_StackPush(
    GenUtils_Stack *stack, void *userdata);

  /// @brief Pop the element in the top of a stack and
  /// returns its value.
  /// @param stack The stack where the element will be
  /// popped.
  /// @return true in success, false otherwise.
  bool GenUtils_StackPop(GenUtils_Stack *stack);

  /// @brief Pop the element in the top of a stack.
  /// @param stack The stack where the element will be
  /// popped.
  /// @return true in success, false otherwise.
  bool GenUtils_StackPopBool(GenUtils_Stack *stack);

  /// @brief Get the element in the top of a stack.
  /// @param stack The stack to query.
  /// @return The element in the top. NULL if is empty or if
  /// the element is NULL. Call GenUtils_StackEmpty to be
  /// sure.
  void *GenUtils_StackTop(GenUtils_Stack *stack);

  /// @brief Clear a stack.
  /// @param stack The stack to clear.
  void GenUtils_StackClear(GenUtils_Stack *stack);

#ifdef __cplusplus
}
#endif
#endif
