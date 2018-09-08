#include <stdio.h>
#define N 2  //Shares
#define M 12 //Days
#define D 10 //The days for counting average price

struct share
{
  char na[6];  //Name of share
  float pr[M]; //The closing price of share
  int ex[M];   //The amount of exchanges of share
};

int main(void)
{
  struct share m[N]; //Declare the variable type structure
  int i, j, s, l, k, o = 0;

  float sum[N]; //The average of the share prices

  int p[M];      //The share with the maximum amount of exchanges of every day
  int maxex = 0; //Put share with the maximum amount of exchanges

  float b[N];      //The share with the maximum price increase percent
  float maxpr = 0; //Put share with the maximum price increase percent
  float y = 0;
  int d[N];

  char ch;

  printf("#################################################################\n");
  for (i = 0; i < N; i++)
  {
    printf("Give the name of the share: ");
    gets(m[i].na);

    printf("Give the closing prices of the shares and the amount of exchanges.\n\n");

    s = 1;
    sum[i] = 0;
    p[i] = 0;
    b[i] = 0;
    maxpr = 0;

    for (j = (M - 1); j >= 0; j--)
    {
      printf("Day %d shares price: ", s + j);
      scanf("%f", &m[i].pr[j]); //Input closing price of share

      if (j < D)
        sum[i] = sum[i] + m[i].pr[j]; //Count the average prices the last 10days
      if (j < (M - 1))
      {
        if (m[i].pr[j + 1] > m[i].pr[j]) //Count the share with the maximum price increase percent
        {
          if ((m[i].pr[j + 1] - m[i].pr[j]) > maxpr)
          {
            maxpr = (m[i].pr[j] / m[i].pr[j + 1]) * 100;
            d[i] = j + 1;
          }
        }
        else
        {
          if ((m[i].pr[j] - m[i].pr[j + 1]) > maxpr)
          {
            maxpr = (m[i].pr[j + 1] / m[i].pr[j]) * 100;
            d[i] = j + 1;
          }
        }
        b[i] = maxpr;
      }

      printf("Day %d share amount of exchanges: ", s + j);
      scanf("%d", &m[i].ex[j]); //Input the amount of exchanges of share

      if (m[i].ex[j] > p[i])
        p[i] = m[i].ex[j]; //Count the share with the maximum amount of exchanges
      printf("\n");
    }
    if (p[i] > maxex)
    {
      maxex = p[i];
      l = i;
    }
    if (b[i] > y)
    {
      y = b[i];
      o = i;
    }

    printf("#################################################################\n");
    while ((ch = getchar()) == ' ')
      ;
  }

  printf("Results\n");
  printf("The average prices the last 10days.\n");
  for (i = 0; i < N; i++)
  {
    printf("The average price of the %s share is %.2f.\n", m[i].na, sum[i] / D);
  }

  printf("\nThe share with the maximum amount of exchanges is %s with %d exchanges.\n", m[l].na, maxex);
  printf("Day %d, share of %s is the share with the maximum \nprice increase with %.2f%% increment.\n\n", d[o], m[o].na, b[o]);

  system("PAUSE");
  return 0;
}
