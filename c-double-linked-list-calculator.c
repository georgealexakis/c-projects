#include <stdio.h>
#include <stdlib.h>
#define NS 10 //Declaration of number size

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

void makeEmptyList(LIST *x);               //Delete data from list
int isEmptyList(LIST *x);                  //Check if list is empty
LNODE *createListNode(int x);              //Create node
void insertListNode(LIST *x, int y);       //Insert node to list
void printList(LIST *x);                   //Print lists
int converter(char x);                     //Convert string characters to integers
void calculator(LIST *x, LIST *y, char p); //Calculator for addition and subtraction

int main(int argc, char *argv[])
{
    LIST *sum1 = (LIST *)malloc(sizeof(LIST)); //Declaration of sum1
    LIST *sum2 = (LIST *)malloc(sizeof(LIST)); //Declaration of sum2
    makeEmptyList(sum1);                       //Make list sum1 empty
    makeEmptyList(sum2);                       //Make list sum2 empty
    int x = 0;
    int i;
    char ch1[NS]; //Temporary table for sum1
    char ch2[NS]; //Temporary table for sum2
    char p;       //The sign of the task '+' or '-'

    while (x < 5)
    {
        for (i = 0; i < 70; i++)
            printf("-");
        printf("\nChoose the task you want to do!\n1. Addition.\n2. Subtraction.\n3. Print lists.\n4. Information.\n5. Exit.\nOption: ");
        scanf("%d", &x);

        switch (x)
        {
        case 1: //Addition
            p = '+';
            makeEmptyList(sum1);
            makeEmptyList(sum2);
            printf("\nGive the first number of the addition: ");
            scanf("%s", ch1);
            printf("Give the second number of the addition: ");
            scanf("%s", ch2);
            for (i = 0; i < NS; i++)
            {
                insertListNode(sum1, converter(ch1[i]));
                insertListNode(sum2, converter(ch2[i]));
            }
            calculator(sum1, sum2, p); //Calculate the addition of sum1 and sum2
            printf("\n");
            break;
        case 2: //Subtraction
            p = '-';
            makeEmptyList(sum1);
            makeEmptyList(sum2);
            printf("\nGive the first number of the addition: ");
            scanf("%s", ch1);
            printf("Give the second number of the addition: ");
            scanf("%s", ch2);
            for (i = 0; i < NS; i++)
            {
                insertListNode(sum1, converter(ch1[i]));
                insertListNode(sum2, converter(ch2[i]));
            }
            calculator(sum1, sum2, p); //Calculate the subtraction of sum1 and sum2
            printf("\n");
            break;
        case 3: //Print the content of lists
            printf("\nList 1 data.\n");
            printList(sum1);
            printf("\nList 2 data.\n");
            printList(sum2);
            printf("\n");
            break;
        case 4: //Information
            printf("\nThe input numbers could be integer and decimal.\nExample input1: 9, input2: 10.\nExample input1: 9.111, input2: 10.345.\n");
            printf(". in list is declaring with -1 and the and of the list with -2.\n\n");
            break;
        case 5: //Exit
            printf("\nExit!\n");
            break;
        default: //Wrong input
            printf("\nWrong input!\n\n");
            x = 0;
            break;
        }
    }
    return 0;
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

LNODE *createListNode(int x)
{
    LNODE *newNode = NULL;
    newNode = (LNODE *)malloc(sizeof(LNODE));
    newNode->data = x;
    newNode->next = NULL;
    newNode->previous = NULL;
}

void insertListNode(LIST *x, int y)
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

int converter(char x) //Convert character to integer
{
    if (x == '.')       //Sign of float '.'
        return -1;      //Return -1 for '.'
    else if (x == '\0') //Sign of the string end
        return -2;      //Return -2 for the end of the string
    else
        return atoi(&x); //Return the integer
}

void printList(LIST *x)
{
    LNODE *tmp = x->head;
    int i = 1;

    if (isEmptyList(x))
        printf("The list is empty!\n");
    else
    {
        for (i = 1; i <= x->size; i++)
        {
            printf("%d. Data = %d\n", i, tmp->data);
            tmp = tmp->next;
        }
    }
}

void calculator(LIST *x, LIST *y, char p)
{
    LNODE *s1 = x->head;
    LNODE *s2 = y->head;

    int i, h = 0, k = 0;
    int gh = 0, fh = 0;

    int ts1;
    int ts2;

    float sol1 = 0.0;
    float sol2 = 0.0;

    if (p == '+')
    {
        for (i = 1; i <= x->size; i++)
        {
            if (s1->data != -2)
            {
                if (s1->data == -1)
                {
                    h = 1;
                    k = 1;
                    s1 = s1->next;
                }
                if (k == 1)
                {
                    h = h * 10;
                }
                ts1 = (s1->data);
                gh = (gh * 10) + ts1;
            }
            else
                break;
            s1 = s1->next;
        }
        if (h != 0)
        {
            sol1 = (float)gh / (float)h;
        }
        else
        {
            sol1 = (float)gh / 1.0;
        }

        h = 0;
        k = 0;

        for (i = 1; i <= y->size; i++)
        {
            if (s2->data != -2)
            {
                if (s2->data == -1)
                {
                    h = 1;
                    k = 1;
                    s2 = s2->next;
                }
                if (k == 1)
                {
                    h = h * 10;
                }
                ts2 = (s2->data);
                fh = (fh * 10) + ts2;
            }
            else
                break;
            s2 = s2->next;
        }
        if (h != 0)
        {
            sol2 = (float)fh / (float)h;
        }
        else
        {
            sol2 = (float)fh / 1.0;
        }
        printf("%f + %f = %f\n", sol1, sol2, sol1 + sol2);
    }

    h = 0;
    k = 0;

    if (p == '-')
    {
        for (i = 1; i <= x->size; i++)
        {
            if (s1->data != -2)
            {
                if (s1->data == -1)
                {
                    h = 1;
                    k = 1;
                    s1 = s1->next;
                }
                if (k == 1)
                {
                    h = h * 10;
                }
                ts1 = (s1->data);
                gh = (gh * 10) + ts1;
            }
            else
                break;
            s1 = s1->next;
        }
        if (h != 0)
        {
            sol1 = (float)gh / (float)h;
        }
        else
        {
            sol1 = (float)gh / 1.0;
        }

        h = 0;
        k = 0;

        for (i = 1; i <= y->size; i++)
        {
            if (s2->data != -2)
            {
                if (s2->data == -1)
                {
                    h = 1;
                    k = 1;
                    s2 = s2->next;
                }
                if (k == 1)
                {
                    h = h * 10;
                }
                ts2 = (s2->data);
                fh = (fh * 10) + ts2;
            }
            else
                break;
            s2 = s2->next;
        }
        if (h != 0)
        {
            sol2 = (float)fh / (float)h;
        }
        else
        {
            sol2 = (float)fh / 1.0;
        }

        if (sol1 > sol2)
        {
            printf("%f - %f = %f\n", sol1, sol2, sol1 - sol2);
        }
        else
        {
            printf("%f - %f = %f\n", sol2, sol1, sol2 - sol1);
        }
    }
}
