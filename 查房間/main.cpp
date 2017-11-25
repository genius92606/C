#include "stdlib.h"
#include "stdio.h"


int main()
{
	int number1, i, number2;
	scanf("%d", &number1);
	int **ptr2 = NULL;  //建立動態二維陣列
	int *ptr = NULL;
	int *total = NULL;
	total = (int*)malloc(sizeof(int*)*number1);
	ptr = (int*)malloc(sizeof(int*)*number1);
	ptr2 = (int**)malloc(sizeof(int*)*number1);    //給他ROW大小
	for (i = 0; i < number1; i++)
	{
		scanf("%d", &number2);
		ptr2[i] = (int*)malloc(sizeof(int*)*number2);  //以及所有ROW的COL大小
		for (int k = 0; k < number2; k++)
		{
			scanf("%d", &ptr2[i][k]);
		}
		ptr[i] = number2;
	}
	int hotel;    //choose which hotel
	scanf("%d", &hotel);
	for (i = 0; i < hotel; i++)
		scanf("%d", &total[i]);    //將選擇的HOTEL號碼放進TOTAL陣列裡
	for (i = 0; i < hotel; i++)
	{
		for (int k = 0; k < ptr[total[i]-1]; k++)     //減1的用意在於第一間HOTEL的資料是存在陣列的零號位置
		{
			printf("%d ", ptr2[total[i] - 1][k]);
		}
		printf("\n");
	}
	for (i = 0; i < number1; i++)
		free(ptr2[i]);      //釋放COL
	free(ptr2);    //釋放ROW
	free(ptr);
	free(total);
	system("pause");
	return 0;
}