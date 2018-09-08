#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Include time.h library to measure running time

void table_filling(int *x, int y);            //Fill the table pinakas_random with random values
void insertion_asc(int *x, int y);            //Insertion sort-Ascending sort function
void insertion_desc(int *x, int y);           //Insertion sort-Descending sort function
void selection_asc(int *x, int y);            //Selection sort-Ascending sort function
void selection_desc(int *x, int y);           //Selection sort-Descending sort function
void quick_asc(int *x, int m, int y);         //Quick sort-Ascending sort function
void quick_desc(int *x, int m, int y);        //Quick sort-Descending sort function
void alltasks(int *x, int *y, int *z, int j); //Run all functions

void copy(int *x, int *y, int *z, int j);                //Copy values from table pinakas_random to tables pinakas_asc and pinakas_desc
void printlist(int *x, char *y, int n, double c, int t); //Print only 10 sorted values. To see all sorted values, delete second if.
void swap(int *x, int *y);                               //Swap values
int choose_pivot(int i, int j);                          //Choose pivot of values i and j

int main(int argc, char *argv[])
{
  clock_t start2, end2, start3, end3, start4, end4, start5, end5, start6, end6, start7, end7; //Declaration of start and end clock
  double c2, c3, c4, c5, c6, c7;

  int x = 0, n = 0, i;
  char *s; //Put the name of every sorting function

  while (n == 0)
  {
    printf("Give the number of integers N:");
    scanf("%d", &n);
    if (n <= 0)
    {
      printf("Wrong value!\n");
      n = 0;
    }
  } //Get value of n>0

  int *pinakas_random = malloc(sizeof(int) * n); //Declaration of pinakas_random size
  int *pinakas_asc = malloc(sizeof(int) * n);    //Declaration of pinakas_asc size
  int *pinakas_desc = malloc(sizeof(int) * n);   //Declaration of pinakas_desc size

  while (x != 9)
  {
    printf("--------------------------------------------------------------------------------\n");
    printf("Choose one of the following tasks every time!\n\n");
    printf("1. Fill the table with random integers.\n2. Ascending sort (Insertion Sort).\n3. Ascending sort (Selection Sort).\n4. Ascending sort (Quick Sort).\n5. Descending sort (Insertion Sort).\n6. Descending sort (Selection Sort).\n7. Descending sort (Quick Sort).\n8. Execute all tasks.\n9. Exit.\n\n");
    printf("Give task:");
    scanf("%d", &x); //Scan the number of task
    switch (x)
    {
    case 1:
      table_filling(pinakas_random, n); //Fill the pinakas_random with random values
      printf("\n1. Pinakas_random fill with the values");
      for (i = 0; i < n; i++)
        printf(",%d", pinakas_random[i]);
      printf("\n\n");
      break;
    case 2:
      start2 = clock();                                   //Clock 2 starts here
      copy(pinakas_random, pinakas_asc, pinakas_desc, n); //Initialise tables pinakas_asc and pinakas_desc
      printf("2. Ascending sort-Insertion Sort(before sorting");
      for (i = 0; i < n; i++)
        printf(",%d", pinakas_asc[i]);
      printf(").\n\n");
      insertion_asc(pinakas_asc, n); //Sort the list
      end2 = clock();                //Clock 2 ends here
      c2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC;
      s = "Insertion Sort";
      printlist(pinakas_asc, s, n, c2, 1);
      break;
    case 3:
      start3 = clock();                                   //Clock 3 starts here
      copy(pinakas_random, pinakas_asc, pinakas_desc, n); //Initialise tables pinakas_asc and pinakas_desc
      printf("3. Ascending sort-Selection Sort(before sorting");
      for (i = 0; i < n; i++)
        printf(",%d", pinakas_asc[i]);
      printf(").\n\n");
      selection_asc(pinakas_asc, n); //Sort the list
      end3 = clock();                //Clock 3 ends here
      c3 = ((double)(end3 - start3)) / CLOCKS_PER_SEC;
      s = "Selection Sort";
      printlist(pinakas_asc, s, n, c3, 1);
      break;
    case 4:
      start4 = clock();                                   //Clock 4 starts here
      copy(pinakas_random, pinakas_asc, pinakas_desc, n); //Initialise tables pinakas_asc and pinakas_desc
      printf("4. Ascending sort-Quick Sort(before sorting");
      for (i = 0; i < n; i++)
        printf(",%d", pinakas_asc[i]);
      printf(").\n\n");
      quick_asc(pinakas_asc, 0, n - 1); //Sort the list
      end4 = clock();                   //Clock 4 ends here
      c4 = ((double)(end4 - start4)) / CLOCKS_PER_SEC;
      s = "Quick Sort    ";
      printlist(pinakas_asc, s, n, c4, 1);
      break;
    case 5:
      start5 = clock();                                   //Clock 5 starts here
      copy(pinakas_random, pinakas_asc, pinakas_desc, n); //Initialise tables pinakas_asc and pinakas_desc
      printf("5. Descending sort-Insertion Sort(before sorting");
      for (i = 0; i < n; i++)
        printf(",%d", pinakas_desc[i]);
      printf(").\n\n");
      insertion_desc(pinakas_desc, n); //Sort the list
      end5 = clock();                  //Clock 5 ends here
      c5 = ((double)(end5 - start5)) / CLOCKS_PER_SEC;
      s = "Insertion Sort";
      printlist(pinakas_desc, s, n, c5, 2);
      break;
    case 6:
      start6 = clock();                                   //Clock 6 starts here
      copy(pinakas_random, pinakas_asc, pinakas_desc, n); //Initialise tables pinakas_asc and pinakas_desc
      printf("6. Descending sort-Selection Sort(before sorting:");
      for (i = 0; i < n; i++)
        printf(",%d", pinakas_desc[i]);
      printf(").\n\n");
      selection_desc(pinakas_desc, n); //Sort the list
      end6 = clock();                  //Clock 6 ends here
      c6 = ((double)(end6 - start6)) / CLOCKS_PER_SEC;
      s = "Selection Sort";
      printlist(pinakas_desc, s, n, c6, 2);
      break;
    case 7:
      start7 = clock();                                   //Clock 7 starts here
      copy(pinakas_random, pinakas_asc, pinakas_desc, n); //Initialise tables pinakas_asc and pinakas_desc
      printf("7. Descending sort-Quick Sort(before sorting");
      for (i = 0; i < n; i++)
        printf(",%d", pinakas_desc[i]);
      printf(").\n\n");
      quick_desc(pinakas_desc, 0, n - 1); //Sort the list
      end7 = clock();                     //Clock 7 ends here
      c7 = ((double)(end7 - start7)) / CLOCKS_PER_SEC;
      s = "Quick Sort    ";
      printlist(pinakas_desc, s, n, c7, 2);
      break;
    case 8:
      printf("8. Execute all tasks(before sorting");
      for (i = 0; i < n; i++)
        printf(",%d", pinakas_random[i]);
      printf(").\n\n");
      alltasks(pinakas_random, pinakas_asc, pinakas_desc, n); //Run all sorting functions
      break;
    case 9:
      printf("Thank you... Close window of running program.\n");
      break;
    default:
      printf("Your choice does not exist.\n");
      printf("\n\n");
    } //End switch
  }   //End while
  system("PAUSE");
  return 0;
}

void table_filling(int *x, int y)
{
  int i;
  for (i = 0; i < y; i++)
    x[i] = rand() % 100;
}

void copy(int *x, int *y, int *z, int j)
{
  int i;
  for (i = 0; i < j; i++)
  {
    y[i] = x[i];
    z[i] = x[i];
  }
}

void insertion_asc(int a[], int n)
{
  int i, j, x, k;
  for (i = 1; i <= n - 1; i++)
  {
    j = i;
    x = a[i];
    while (a[j - 1] > x && j > 0)
    {
      a[j] = a[j - 1];
      j = j - 1;
    }
    a[j] = x;
    //printf("\nThe array after pass no.%d: ",i); Remove '//' to see steps of sorting
    for (k = 0; k <= n - 1; k++)
      ;
    //printf("%4d",a[k]); Remove '//' to see steps of sorting
  }
}

void insertion_desc(int a[], int n)
{
  int i, j, x, k;
  for (i = 1; i <= n - 1; i++)
  {
    j = i;
    x = a[i];
    while (a[j - 1] < x && j > 0)
    {
      a[j] = a[j - 1];
      j = j - 1;
    }
    a[j] = x;
    //printf("\nThe array after pass no.%d: ",i); Remove '//' to see steps of sorting
    for (k = 0; k <= n - 1; k++)
      ;
    //printf("%4d",a[k]); Remove '//' to see steps of sorting
  }
}

void selection_asc(int list[], int n)
{
  int i, j, min;

  for (i = 0; i < n - 1; i++)
  {
    min = i;
    for (j = i + 1; j < n; j++)
    {
      if (list[j] < list[min])
      {
        min = j;
      }
    }
    swap(&list[i], &list[min]);
  }
}

void selection_desc(int list[], int n)
{
  int i, j, min;

  for (i = 0; i < n - 1; i++)
  {
    min = i;
    for (j = i + 1; j < n; j++)
    {
      if (list[j] > list[min])
      {
        min = j;
      }
    }
    swap(&list[i], &list[min]);
  }
}

void quick_asc(int list[], int m, int n)
{
  int key, i, j, k;
  if (m < n)
  {
    k = choose_pivot(m, n);
    swap(&list[m], &list[k]);
    key = list[m];
    i = m + 1;
    j = n;
    while (i <= j)
    {
      while ((i <= n) && (list[i] <= key))
        i++;
      while ((j >= m) && (list[j] > key))
        j--;
      if (i < j)
        swap(&list[i], &list[j]);
    }
    // swap two elements
    swap(&list[m], &list[j]);
    // recursively sort the lesser list
    quick_asc(list, m, j - 1);
    quick_asc(list, j + 1, n);
  }
}

void quick_desc(int list[], int m, int n)
{
  int key, i, j, k;
  if (m < n)
  {
    k = choose_pivot(m, n);
    swap(&list[m], &list[k]);
    key = list[m];
    i = m + 1;
    j = n;
    while (i <= j)
    {
      while ((i <= n) && (list[i] >= key))
        i++;
      while ((j >= m) && (list[j] < key))
        j--;
      if (i < j)
        swap(&list[i], &list[j]);
    }
    // swap two elements
    swap(&list[m], &list[j]);
    // recursively sort the lesser list
    quick_desc(list, m, j - 1);
    quick_desc(list, j + 1, n);
  }
}

void alltasks(int *x, int *y, int *z, int j)
{
  clock_t start2, end2, start3, end3, start4, end4, start5, end5, start6, end6, start7, end7;
  double c2, c3, c4, c5, c6, c7;
  char *s;

  start2 = clock();
  copy(x, y, z, j);
  insertion_asc(y, j);
  s = "Insertion Sort";
  end2 = clock();
  c2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC;
  printlist(y, s, j, c2, 1);

  start3 = clock();
  copy(x, y, z, j);
  selection_asc(y, j);
  s = "Selection Sort";
  end3 = clock();
  c3 = ((double)(end3 - start3)) / CLOCKS_PER_SEC;
  printlist(y, s, j, c3, 1);

  start4 = clock();
  copy(x, y, z, j);
  quick_asc(y, 0, j - 1);
  s = "Quick Sort    ";
  end4 = clock();
  c4 = ((double)(end4 - start4)) / CLOCKS_PER_SEC;
  printlist(y, s, j, c4, 1);

  start5 = clock();
  copy(x, y, z, j);
  insertion_desc(z, j);
  s = "Insertion Sort";
  end5 = clock();
  c5 = ((double)(end5 - start5)) / CLOCKS_PER_SEC;
  printlist(z, s, j, c5, 2);

  start6 = clock();
  copy(x, y, z, j);
  selection_desc(z, j);
  s = "Selection Sort";
  end6 = clock();
  c6 = ((double)(end6 - start6)) / CLOCKS_PER_SEC;
  printlist(z, s, j, c6, 2);

  start7 = clock();
  copy(x, y, z, j);
  quick_desc(z, 0, j - 1);
  s = "Quick Sort    ";
  end7 = clock();
  c7 = ((double)(end7 - start7)) / CLOCKS_PER_SEC;
  printlist(z, s, j, c7, 2);
}

void swap(int *x, int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void printlist(int *x, char *y, int n, double c, int t)
{
  char *p;
  if (t == 1)
    p = "pinakas_asc";
  else
    p = "pinakas_desc";
  int i;
  printf(" N    Algorithm          Table              Values                    Time\n");
  printf("%d  %s    %s    ", n, y, p);
  for (i = 0; i < n; i++)
  {
    if (i == 0)
      printf("%d", x[i]);
    else
    {
      if (i < 10)
        printf(",%d", x[i]); //Print only the first sorted values. To see all values delete if
    }
  }
  printf("      %.0fms\n\n", c * 1000);
}

int choose_pivot(int i, int j)
{
  return ((i + j) / 2);
}
