#include"D:\VSProgram\Test\SortTest\sort.h"
int temp[10000] = { 0 };


int main() {
	char choice=0;
	while (1) {
		printf("请输入你的选择：（1-4）");
		do
		{
			scanf_s("%c", &choice,1);
			if (choice < '1' || choice>'5') {
				printf("输入错误，请重新输入\n");
				continue;
			}
		} while (choice < '1' || choice>'5');

		switch (choice)
		{
		case '1': {
			int* a1 = (int*)malloc(sizeof(int) * 10000);
			randomNumber(a1, 10000);

			clock_t start1 = clock();
			insertSort(a1, 10000);
			clock_t diff1 = clock() - start1;
			printf("插入排序用时为：%d ms\n", diff1);

			clock_t start2 = clock();
			QuickSort_Recursion(a1, 0,10000);
			clock_t diff2 = clock() - start2;
			printf("快速排序用时为： % d ms\n", diff2);

			clock_t start3 = clock();
			MergeSort(a1,0, 10000,temp);
			clock_t diff3 = clock() - start3;
			printf("归并排序用时为：%d ms\n", diff3);

			clock_t start4 = clock();
			printf("1\n");
			CountSort(a1, 10000,getMax(a1,10000));
			printf("2\n");
			clock_t diff4 = clock() - start4;
			printf("3\n");
			printf("计数排序用时为：%d ms", diff4);

			clock_t start5 = clock();
			RadixCountSort(a1, 10000);
			clock_t diff5 = clock() - start5;
			printf("基数排序用时为：%d ms", diff5);
			break;
		};
		case '2': {
			
		};
		case '3': {
//			int arr[200000] = { 0 };
		};
		case '4': {
//			int arr[100] = { 0 };
		}
		}
	}



	system("pause");

	return 0;
}