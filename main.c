#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
	int n1 = 0;
	scanf("%d",&n1);
	int* a = (int*)malloc(sizeof(int)*n1);
	if (a == NULL)
	{
		printf("%s\n",strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < n1; i++)
		{
			*(a + i) = i;
		}
		for (i = 0; i < n1; i++)
		{
			printf("%d ",a[i]);
		}
	}
	free(a);
	a = NULL;
	printf("\n");
	int n2 = 0;
	scanf("%d",&n2);
	int* b = (int*)calloc(n2,sizeof(int));
	if (b == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < n2; i++)
		{
			printf("%d ", b[i]);
		}
	}
	printf("\n");
	int* c = realloc(b,sizeof(int)*(n2+5));
	if (c != NULL)
	{
		b = c;
		int i = 0;
		for (i = n2; i < (n2 + 5); i++)
		{
			*(b + i) = i;
		}
		for (i = 0; i < (n2 + 5); i++)
		{
			printf("%d ",*(b+i));
		}
	}

	free(b);
	b = NULL;
	c = NULL;
	return 0;
}
