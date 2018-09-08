#include "stdio.h"

void replaceR(char *x);
void mergeString(char *x, char *y);
void upperString(char *x);
void lowerString(char *x);
void reverseString(char *x);
int isPalindrome(char *x);

int main(int argc, char *argv[])
{
	int action = 0;
	char input[50];
	char temporaryInput[50];

	while (action < 7)
	{
		int i = 0;
		for (i = 0; i < 70; i++)
			printf(".");
		printf("\n");
		printf("1)Replace 'r' with '-'.\n2)Merge strings.\n3)String to uppercase.\n4)String to lowercase.\n5)Reverse string characters.\n6)Check if is palindrome.\n7)Exit.\n");
		printf("Choose the number of the action you want to do: ");
		scanf("%d", &action);
		switch (action)
		{
		case 1:
			printf("Insert string: ");
			scanf("%s", input);
			replaceR(input);
			printf("Result: %s\n", input);
			break;
		case 2:
			printf("Insert 1st string: ");
			scanf("%s", input);
			printf("Insert 2nd string: ");
			scanf("%s", temporaryInput);
			mergeString(input, temporaryInput);
			printf("Result: %s\n", input);
			break;
		case 3:
			printf("Insert string: ");
			scanf("%s", input);
			upperString(input);
			printf("Result: %s\n", input);
			break;
		case 4:
			printf("Insert string: ");
			scanf("%s", input);
			lowerString(input);
			printf("Result: %s\n", input);
			break;
		case 5:
			printf("Insert string: ");
			scanf("%s", input);
			reverseString(input);
			printf("Result: %s\n", input);
			break;
		case 6:
			printf("Insert string: ");
			scanf("%s", input);
			int palindrome = isPalindrome(input);
			if (palindrome == 1)
				printf("String %s is palindrome.\n", input);
			else
				printf("String %s is not palindrome.\n", input);
			break;
		case 7:
			printf("Bye!");
			break;
		default:
			printf("Wrong input. Choose one of the tasks.\n");
			action = 0;
			break;
		}
	}
}

void replaceR(char *x)
{
	while (*x != '\0')
	{
		if (*x == 'r' || *x == 'R')
			*x = '-';
		x++;
	}
}

void mergeString(char *x, char *y)
{
	int lengthX = strlen(x);
	int lengthY = strlen(y);
	int i = 0;
	int j = lengthX + lengthY;
	for (i = lengthX; i < j; i++)
		x[i] = y[i - lengthX];
	x[j] = '\0';
}

void upperString(char *x)
{
	while (*x != '\0')
	{
		if ((*x >= 97) && (*x <= 122))
			*x = *x - 32;
		x++;
	}
}

void lowerString(char *x)
{
	while (*x != '\0')
	{
		if ((*x >= 65) && (*x <= 90))
			*x = *x + 32;
		x++;
	}
}

void reverseString(char *x)
{
	int i;
	char *tmp;
	int cnt = strlen(x);
	for (i = 0; i < cnt; i++)
		tmp[i] = x[i];
	for (i = 1; i <= cnt; i++)
		x[i - 1] = tmp[cnt - i];
}

int isPalindrome(char *x)
{
	int i, cnt = 0;
	for (i = 0; *(x + i) != '\0'; i++)
		cnt++;
	for (i = 0; *(x + i) != '\0'; i++)
	{
		if (*(x + i) == *(x + cnt - 1 - i))
			return 1;
		else
			return 0;
	}
}
