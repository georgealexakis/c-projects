#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 13

typedef struct node
{
  int data;
  struct node *next;
  struct node *previous;
} LNODE;

typedef struct list
{
  int size;
  LNODE *head;
} LIST;

typedef struct data
{
  char *data;
  double key;
} DICTIONARY;

DICTIONARY *hashTable[SIZE];

int insert(double key, char *data);
char *get(double key);
int removeValue(double key);
LIST *getRange(double fromKey, double toKey);
int computeHashCode(double key);
void printDictionary();
void makeHashTableEmpty();

void makeEmptyList(LIST *x);
int isEmptyList(LIST *x);
LNODE *createListNode(char *x);
void insertListNode(LIST *x, char *y);
void printList(LIST *x);
void printDivider();

int main(int argc, char *argv[])
{
  LIST *rangeList = (LIST *)malloc(sizeof(LIST));
  int choice = 0;
  float fromKey = 0.0;
  float toKey = 0.0;
  float tempKey = 0.0;
  char *tempValue = NULL;
  char *value = NULL;

  while (choice < 8)
  {
    printDivider();
    printf("Choose the task you want to do.\n1. Insert custom item to the table.\n2. Insert demo items to the table.\n3. Display table.\n4. Get range of items.\n5. Get item.\n6. Delete item.\n7. Delete all data.\n8. Exit.\nOption: ");
    scanf("%d", &choice);

    switch (choice)
    {

    case 1:
      tempValue = NULL;
      tempValue = malloc(20);
      printf("Type the key you want to insert: ");
      scanf("%f", &tempKey);
      printf("Type the value you want to insert: ");
      scanf("%s", tempValue);
      printDivider();
      if (insert(tempKey, tempValue))
      {
        printf("The data successfully inserted.\n");
      }
      else
      {
        printf("The data was not inserted.\n");
      }
      break;

    case 2:
      makeHashTableEmpty();
      printDivider();
      printf("The old data was deleted and demo data was inserted.\n");
      insert(18.0, "shoe");
      insert(41.0, "dress");
      insert(22.0, "coffee");
      insert(44.0, "milk");
      insert(59.0, "apple");
      insert(32.0, "computer");
      insert(31.0, "tablet");
      insert(73.0, "mouse");
      break;

    case 3:
      printDivider();
      printDictionary();
      break;

    case 4:
      printf("Type the key from you want to get: ");
      scanf("%f", &fromKey);
      printf("Type the key to you want to get: ");
      scanf("%f", &toKey);
      printDivider();
      printf("Values from %f key to %f key.\n", fromKey, toKey);
      makeEmptyList(rangeList);
      rangeList = getRange(fromKey, toKey);
      printList(rangeList);
      break;

    case 5:
      printf("Type the key you want to get: ");
      scanf("%f", &tempKey);
      printDivider();
      value = get(tempKey);
      if (value != NULL)
      {
        printf("Value : %s\n", value);
      }
      else
      {
        printf("Value not found.\n");
      }
      break;

    case 6:
      printf("Type the key you want to delete: ");
      scanf("%f", &tempKey);
      printDivider();
      if (removeValue(tempKey))
      {
        printf("Selected key and value deleted successfully.\n");
      }
      else
      {
        printf("Key not found.\n");
      }
      break;

    case 7:
      makeHashTableEmpty();
      printDivider();
      printf("The old data was deleted.\n");
      break;

    case 8:
      printf("Exit.");
      break;

    default:
      printf("Wrong input. Choose one of the tasks.\n");
      choice = 0;
      break;
    }
  }
  return 0;
}

int insert(double key, char *data)
{
  DICTIONARY *item = (DICTIONARY *)malloc(sizeof(DICTIONARY));
  item->data = data;
  item->key = key;
  int hashIndex = computeHashCode(key);
  int loop = 0;

  while (hashTable[hashIndex] != NULL)
  {
    if (hashTable[hashIndex]->key == key)
    {
      return 0;
    }
    ++hashIndex;
    hashIndex %= SIZE;
    if (loop == SIZE)
    {
      return 0;
    }
    loop++;
  }
  if (hashTable[hashIndex] = item)
    return 1;
  else
    return 0;
}

char *get(double key)
{
  int hashIndex = computeHashCode(key);
  while (hashTable[hashIndex] != NULL)
  {
    if (hashTable[hashIndex]->key == key)
      return hashTable[hashIndex]->data;
    ++hashIndex;
    hashIndex %= SIZE;
  }
  return NULL;
}

int removeValue(double key)
{
  int hashIndex = computeHashCode(key);

  while (hashTable[hashIndex] != NULL)
  {
    if (hashTable[hashIndex]->key == key)
    {
      hashTable[hashIndex] = NULL;
      return 1;
    }
    ++hashIndex;
    hashIndex %= SIZE;
  }
  return 0;
}

LIST *getRange(double fromKey, double toKey)
{
  LIST *tempList = (LIST *)malloc(sizeof(LIST));
  makeEmptyList(tempList);

  int hashIndexFrom = computeHashCode(fromKey);
  int hashIndexTo = computeHashCode(toKey);
  int i = 0;
  int tempTo = 0;

  while (hashTable[hashIndexFrom] != NULL || hashTable[hashIndexTo] != NULL)
  {
    if (hashTable[hashIndexFrom] != NULL && hashTable[hashIndexTo] == NULL)
    {
      if (hashTable[hashIndexFrom]->key == fromKey)
      {
        insertListNode(tempList, hashTable[hashIndexFrom]->data);
        return tempList;
      }
      ++hashIndexFrom;
      hashIndexFrom %= SIZE;
    }
    else if (hashTable[hashIndexFrom] == NULL && hashTable[hashIndexTo] != NULL)
    {
      if (hashTable[hashIndexTo]->key == toKey)
      {
        insertListNode(tempList, hashTable[hashIndexTo]->data);
        return tempList;
      }
      ++hashIndexTo;
      hashIndexTo %= SIZE;
    }
    else if (hashTable[hashIndexFrom] != NULL && hashTable[hashIndexTo] != NULL)
    {
      if (hashTable[hashIndexFrom]->key == fromKey)
      {
        insertListNode(tempList, hashTable[hashIndexFrom]->data);
        tempTo = hashIndexFrom;
        ++tempTo;
        tempTo %= SIZE;
        while (hashTable[tempTo] == NULL)
        {
          ++tempTo;
          tempTo %= SIZE;
        }
        while (hashTable[tempTo]->key != toKey)
        {
          insertListNode(tempList, hashTable[tempTo]->data);
          ++tempTo;
          tempTo %= SIZE;

          while (hashTable[tempTo] == NULL)
          {
            ++tempTo;
            tempTo %= SIZE;
          }
        }
        insertListNode(tempList, hashTable[tempTo]->data);
        return tempList;
      }
      else
      {
        ++hashIndexFrom;
        hashIndexFrom %= SIZE;
      }
    }
  }
  return tempList;
}

int computeHashCode(double key)
{
  return (int)key % SIZE;
}

void printDictionary()
{
  int i = 0;
  for (i = 0; i < SIZE; i++)
  {
    if (hashTable[i] != NULL)
      printf("Key : %f / Value : %s\n", hashTable[i]->key, hashTable[i]->data);
    else
      printf("Key : --------- / Value : ---------\n");
  }
}

void makeHashTableEmpty()
{
  int i = 0;
  for (i = 0; i < SIZE; i++)
  {
    hashTable[i] = NULL;
  }
}

void makeEmptyList(LIST *x)
{
  x->size = 0;
  x->head = NULL;
}

int isEmptyList(LIST *x)
{
  return (x->size == 0);
}

LNODE *createListNode(char *x)
{
  LNODE *newNode = NULL;
  newNode = (LNODE *)malloc(sizeof(LNODE));
  newNode->data = x;
  newNode->next = NULL;
  newNode->previous = NULL;
}

void insertListNode(LIST *x, char *y)
{
  LNODE *newNode = createListNode(y);
  LNODE *tmp = x->head;
  int i;

  if (x->size == 0)
  {
    x->head = newNode;
  }
  else
  {
    for (i = 1; i < x->size; i++)
    {
      tmp = tmp->next;
    }
    newNode->previous = tmp;
    tmp->next = newNode;
    newNode->next = (LNODE *)NULL;
  }
  x->size++;
}

void printList(LIST *x)
{
  LNODE *tmp = x->head;
  int i = 1;

  if (isEmptyList(x))
    printf("Values not found.\n");
  else
  {
    for (i = 1; i <= x->size; i++)
    {
      printf("%d. Value : %s\n", i, tmp->data);
      tmp = tmp->next;
    }
  }
}

void printDivider()
{
  int i = 0;
  for (i = 0; i < 70; i++)
  {
    printf("-");
  }
  printf("\n");
}
