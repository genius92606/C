#include "stdlib.h"
#include "stdio.h"


int main()
{
	int number1, i, number2;
	scanf("%d", &number1);
	int **ptr2 = NULL;  //�إ߰ʺA�G���}�C
	int *ptr = NULL;
	int *total = NULL;
	total = (int*)malloc(sizeof(int*)*number1);
	ptr = (int*)malloc(sizeof(int*)*number1);
	ptr2 = (int**)malloc(sizeof(int*)*number1);    //���LROW�j�p
	for (i = 0; i < number1; i++)
	{
		scanf("%d", &number2);
		ptr2[i] = (int*)malloc(sizeof(int*)*number2);  //�H�ΩҦ�ROW��COL�j�p
		for (int k = 0; k < number2; k++)
		{
			scanf("%d", &ptr2[i][k]);
		}
		ptr[i] = number2;
	}
	int hotel;    //choose which hotel
	scanf("%d", &hotel);
	for (i = 0; i < hotel; i++)
		scanf("%d", &total[i]);    //�N��ܪ�HOTEL���X��iTOTAL�}�C��
	for (i = 0; i < hotel; i++)
	{
		for (int k = 0; k < ptr[total[i]-1]; k++)     //��1���ηN�b��Ĥ@��HOTEL����ƬO�s�b�}�C���s����m
		{
			printf("%d ", ptr2[total[i] - 1][k]);
		}
		printf("\n");
	}
	for (i = 0; i < number1; i++)
		free(ptr2[i]);      //����COL
	free(ptr2);    //����ROW
	free(ptr);
	free(total);
	system("pause");
	return 0;
}