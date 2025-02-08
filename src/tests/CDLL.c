/// @file CDLL.c
/// @author DP-Dev.
/// @brief Test for the implementation of CDLL.
#include <Utils/Utils_CDLL.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  Utils_CDLL *list = NULL;
  int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  size_t j = 0;
  Utils_DoubleNode *currentNode = NULL;
  puts("Test for the implementation of a CDLL.");
  puts("Creating the test list...");
  list = Utils_CDLLCreate();
  if (!Utils_CDLLWasInit(list))
  {
    puts("Error creating the list.");
    return EXIT_FAILURE;
  }
  puts("List created successfully!");
  puts("Prending elements...");
  for (size_t i = 0; i < 5; i++)
  {
    printf("Prepending integer %d...\n", array[i]);
    if (!Utils_CDLLPushFront(list, &array[i]))
    {
      puts("Error prepending elements.");
      Utils_CDLLDestroy(list);
      return EXIT_FAILURE;
    }
    puts("Test list now is:");
    j = 0;
    currentNode = Utils_CDLLBegin(list);
    printf("{");
    while (j < Utils_CDLLGetSize(list))
    {
      if (j < Utils_CDLLGetSize(list) - 1)
      {
        printf("%d, ", *((int *)(currentNode->userdata)));
      }
      else
      {
        printf("%d", *((int *)(currentNode->userdata)));
      }
      currentNode = currentNode->nextNode;
      j++;
    }
    printf("}\n");
  }
  puts("Appending elements...");
  for (size_t i = 0; i < 5; i++)
  {
    printf("Appending integer %d...\n", array[i + 5]);
    if (!Utils_CDLLPushBack(list, &array[5 + i]))
    {
      puts("Error appending elements.");
      Utils_CDLLDestroy(list);
      return EXIT_FAILURE;
    }
    puts("Test list now is:");
    j = 0;
    currentNode = Utils_CDLLBegin(list);
    printf("{");
    while (j < Utils_CDLLGetSize(list))
    {
      if (j < Utils_CDLLGetSize(list) - 1)
      {
        printf("%d, ", *((int *)(currentNode->userdata)));
      }
      else
      {
        printf("%d", *((int *)(currentNode->userdata)));
      }
      currentNode = currentNode->nextNode;
      j++;
    }
    printf("}\n");
  }
  puts("Inserting elements after the first...");
  for (size_t i = 0; i < 5; i++)
  {
    printf("Inserting integer %d...\n", array[i + 3]);
    if (!Utils_CDLLInsertAfter(
          list, Utils_CDLLBegin(list), &array[i + 3]))
    {
      puts("Error inserting elements.");
      Utils_CDLLDestroy(list);
      return EXIT_FAILURE;
    }
    puts("Test list now is:");
    j = 0;
    currentNode = Utils_CDLLBegin(list);
    printf("{");
    while (j < Utils_CDLLGetSize(list))
    {
      if (j < Utils_CDLLGetSize(list) - 1)
      {
        printf("%d, ", *((int *)(currentNode->userdata)));
      }
      else
      {
        printf("%d", *((int *)(currentNode->userdata)));
      }
      currentNode = currentNode->nextNode;
      j++;
    }
    printf("}\n");
  }

  puts("Popping elements from the beggining...");
  for (size_t i = 0; i < 3; i++)
  {
    printf("Removing integer %d.\n",
      *((int *)(Utils_CDLLBegin(list)->userdata)));
    if (!Utils_CDLLPopFront(list))
    {
      puts("Error popping elements.");
      Utils_CDLLDestroy(list);
      return EXIT_FAILURE;
    }
    puts("Test list now is:");
    j = 0;
    currentNode = Utils_CDLLBegin(list);
    printf("{");
    while (j < Utils_CDLLGetSize(list))
    {
      if (j < Utils_CDLLGetSize(list) - 1)
      {
        printf("%d, ", *((int *)(currentNode->userdata)));
      }
      else
      {
        printf("%d", *((int *)(currentNode->userdata)));
      }
      currentNode = currentNode->nextNode;
      j++;
    }
    printf("}\n");
  }
  puts("Popping elements from the end...");
  for (size_t i = 0; i < 3; i++)
  {
    printf("Removing integer %d.\n",
      *((int *)(Utils_CDLLEnd(list)->userdata)));
    if (!Utils_CDLLPopBack(list))
    {
      puts("Error popping elements.");
      Utils_CDLLDestroy(list);
      return EXIT_FAILURE;
    }
    puts("Test list now is:");
    j = 0;
    currentNode = Utils_CDLLBegin(list);
    printf("{");
    while (j < Utils_CDLLGetSize(list))
    {
      if (j < Utils_CDLLGetSize(list) - 1)
      {
        printf("%d, ", *((int *)(currentNode->userdata)));
      }
      else
      {
        printf("%d", *((int *)(currentNode->userdata)));
      }
      currentNode = currentNode->nextNode;
      j++;
    }
    printf("}\n");
  }
  puts("Removing elements next to first...");
  for (size_t i = 0; i < 2; i++)
  {
    printf("Removing integer %d.\n",
      *((int *)(Utils_CDLLEnd(list)->nextNode->userdata)));
    if (!Utils_CDLLRemoveAfter(list, Utils_CDLLBegin(list)))
    {
      puts("Error removing elements.");
      Utils_CDLLDestroy(list);
      return EXIT_FAILURE;
    }
    puts("Test list now is:");
    j = 0;
    currentNode = Utils_CDLLBegin(list);
    printf("{");
    while (j < Utils_CDLLGetSize(list))
    {
      if (j < Utils_CDLLGetSize(list) - 1)
      {
        printf("%d, ", *((int *)(currentNode->userdata)));
      }
      else
      {
        printf("%d", *((int *)(currentNode->userdata)));
      }
      currentNode = currentNode->nextNode;
      j++;
    }
    printf("}\n");
  }
  puts("Detroying list...");
  Utils_CDLLDestroy(list);
  puts("Test passed!");
}
