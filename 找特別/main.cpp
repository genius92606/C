#include "stdlib.h"
#include "stdio.h"

int main()
{
	int number1,i,number2;
	scanf("%d", &number1);
	int **ptr2 = NULL;  //建立動態二維陣列
	int *ptr = NULL;
	int *end = NULL;
	end = (int*)malloc(sizeof(int*)*number1);
	ptr = (int*)malloc(sizeof(int*)*number1);
	ptr2 = (int**)malloc(sizeof(int*)*number1);    //給他ROW大小
	for (i = 0; i < number1; i++)
	{
		scanf("%d", &number2);
		ptr2[i] = (int*)malloc(sizeof(int*)*number2);  //以及所有ROW的COL大小
		for (int k = 0; k < number2; k++)
			scanf("%d", &ptr2[i][k]);
		ptr[i] = number2;
	}
	/*for (i = 0; i < number1; i++)
	{
		for (int k = 0; k < ptr[i]; k++)
			printf("%d ", ptr2[i][k]);          //全部顯示出來
		printf("\n");
	}*/
	int repeat;
	int a;
	for (i = 0; i < number1; i++)
	{
		for (int k = 0; k < ptr[i]; k++)
		{
			repeat = 0;
			int temp = ptr2[i][k];
			for (int j =0; j < ptr[i]; j++)
			{
				if (j == k)
					a = 1;
				else
					if (temp == ptr2[i][j])
					{
						repeat = 1;
					}
				if (repeat == 1)
					break;
				
			}
			if (repeat == 0)
			{
				end[i] = ptr2[i][k];
				break;
			}
		}
	}
	for (i = 0; i < number1; i++)
		printf("%d ", end[i]);
	printf("\n");
	for (i = 0; i < number1; i++)
		free(ptr2[i]);      //釋放COL
	free(ptr2);    //釋放ROW
	free(ptr);
	system("pause");
	return 0;
}