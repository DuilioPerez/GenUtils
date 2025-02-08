/// @file CSLL.c
/// @author DP-Dev.
/// @brief Test for the implementation of CSLL.
#include <Utils/Utils_CSLL.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  Utils_CSLL *list = NULL;
  int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  size_t j = 0;
  Utils_SingleNode *currentNode = NULL;
  puts("Test for the implementation of a CSLL.");
  puts("Creating the test list...");
  list = Utils_CSLLCreate();
  if (!Utils_CSLLWasInit(list))
  {
    puts("Error creating the list.");
    return EXIT_FAILURE;
  }
  puts("List created successfully!");
  puts("Prending elements...");
  for (size_t i = 0; i < 5; i++)
  {
    printf("Prepending integer %d...\n", array[i]);
    if (!Utils_CSLLPushFront(list, &array[i]))
    {
      puts("Error prepending elements.");
      Utils_CSLLDestroy(list);
      return EXIT_FAILURE;
    }
    puts("Test list now is:");
    j = 0;
    currentNode = Utils_CSLLBegin(list);
    printf("{");
    while (j < Utils_CSLLGetSize(list))
    {
      if (j < Utils_CSLLGetSize(list) - 1)
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
    if (!Utils_CSLLPushBack(list, &array[5 + i]))
    {
      puts("Error appending elements.");
      Utils_CSLLDestroy(list);
      return EXIT_FAILURE;
    }
    puts("Test list now is:");
    j = 0;
    currentNode = Utils_CSLLBegin(list);
    printf("{");
    while (j < Utils_CSLLGetSize(list))
    {
      if (j < Utils_CSLLGetSize(list) - 1)
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
    if (!Utils_CSLLInsertAfter(
          list, Utils_CSLLBegin(list), &array[i + 3]))
    {
      puts("Error inserting elements.");
      Utils_CSLLDestroy(list);
      return EXIT_FAILURE;
    }
    puts("Test list now is:");
    j = 0;
    currentNode = Utils_CSLLBegin(list);
    printf("{");
    while (j < Utils_CSLLGetSize(list))
    {
      if (j < Utils_CSLLGetSize(list) - 1)
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
      *((int *)(Utils_CSLLBegin(list)->userdata)));
    if (!Utils_CSLLPopFront(list))
    {
      puts("Error popping elements.");
      Utils_CSLLDestroy(list);
      return EXIT_FAILURE;
    }
    puts("Test list now is:");
    j = 0;
    currentNode = Utils_CSLLBegin(list);
    printf("{");
    while (j < Utils_CSLLGetSize(list))
    {
      if (j < Utils_CSLLGetSize(list) - 1)
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
      *((int *)(Utils_CSLLEnd(list)->userdata)));
    if (!Utils_CSLLPopBack(list))
    {
      puts("Error popping elements.");
      Utils_CSLLDestroy(list);
      return EXIT_FAILURE;
    }
    puts("Test list now is:");
    j = 0;
    currentNode = Utils_CSLLBegin(list);
    printf("{");
    while (j < Utils_CSLLGetSize(list))
    {
      if (j < Utils_CSLLGetSize(list) - 1)
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
      *((int *)(Utils_CSLLEnd(list)->nextNode->userdata)));
    if (!Utils_CSLLRemoveAfter(list, Utils_CSLLBegin(list)))
    {
      puts("Error removing elements.");
      Utils_CSLLDestroy(list);
      return EXIT_FAILURE;
    }
    puts("Test list now is:");
    j = 0;
    currentNode = Utils_CSLLBegin(list);
    printf("{");
    while (j < Utils_CSLLGetSize(list))
    {
      if (j < Utils_CSLLGetSize(list) - 1)
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
  Utils_CSLLDestroy(list);
  puts("Test passed!");
}
