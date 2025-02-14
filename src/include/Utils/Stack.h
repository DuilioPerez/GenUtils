/// @file Stack.h
/// @author DP-Dev
/// @brief Implementation of a stack.
#ifndef UTILS_STACK_H
#define UTILS_STACK_H true
#ifdef __cplusplus
extern "C"
{
#endif
#include <stdbool.h>
#include <stdlib.h>

  /// @brief Define stack as a synonim of a CDLL.
  typedef struct Utils_CDLL Utils_Stack;

  /// @brief Create a stack.
  /// @return NULL in error or a valid pointer in success.
  Utils_Stack *Utils_StackCreate();

  /// @brief Query if  a stack was initialized.
  /// @param stack The stack to query.
  /// @return true if the stack was initialized.
  bool Utils_StackWasInit(Utils_Stack *stack);

  /// @brief Destroy a stack.
  /// @param stack The stack to destroy.
  void Utils_StackDestroy(Utils_Stack *stack);

  /// @brief Get the size of a stack.
  /// @param stack The stack to query.
  /// @return The number of elements in the stack.
  size_t Utils_StackGetSize(Utils_Stack *stack);

  /// @brief Query if a stack is empty.
  /// @param stack The stack to query.
  /// @return true if the stack is empty.
  bool Utils_StackEmpty(Utils_Stack *stack);

  /// @brief Push the element in the top of a stack.
  /// @param stack The stack where the data will be pushed.
  /// @param userdata The data to push.
  /// @return true in success, false otherwise.
  bool Utils_StackPush(Utils_Stack *stack, void *userdata);

  /// @brief Pop the element in the top of a stack.
  /// @param stack The stack where the element will be
  /// popped.
  /// @return true in success, false otherwise.
  bool Utils_StackPop(Utils_Stack *stack);

  /// @brief Get the element in the top of a stack.
  /// @param stack The stack to query.
  /// @return The element in the top. NULL if is empty or if
  /// the element is NULL. Call Utils_StackEmpty to be sure.
  void *Utils_StackTop(Utils_Stack *stack);

  /// @brief Clear a stack.
  /// @param stack The stack to clear.
  void Utils_StackClear(Utils_Stack *stack);

#ifdef __cplusplus
}
#endif
#endif
