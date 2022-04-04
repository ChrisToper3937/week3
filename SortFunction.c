#include"D:\VSProgram\Test\SortTest\sort.h"

//插入排序
void insertSort(int*a,int n){
	
	//数组长度为1无需排序
	if (n < 2)return;

	int temp=0, i, j ;
	clock_t start = clock();

	for ( i=1; i < n; i++)
	{
		temp = a[i];
		for ( j = i-1; j>=0; j--)
		{
			if (a[j] <= temp)break;
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
}

//快速排序（递归版）
void QuickSort_Recursion(int* a, int begin, int end) {
	if (end < 1)return;		//数组长度为1无需排序

	int length = end;
	int temp = a[0];		//选取最左边的数组元素为中心轴
	int flag = 1;			//判断需要移动的左边，1为右坐标，0为左坐标

	while (begin<end)
	{
		//移动右下标的情况
		if (flag==1)
		{
			//右下标元素的值大于等于中心轴，继续移动右下标
			if (a[end] >= temp) {
				end--;
				continue;
			}

			//若右下标位置元素小于中心轴，把它的值赋给左下标
			a[begin] = a[end];
			begin++;					//左下标向右移动
			flag = 0;				//下次移动左下标
			continue;
		}

		//移动左下标
		if (flag==0)
		{
			//左下标元素的值大于等于中心轴，继续移动右下标
			if (a[begin]<=temp)
			{
				begin++;
				continue;
			}

			//若左下标位置元素小于中心轴，把它的值赋给左下标
			a[end] = a[begin];
			end--;
			flag = 1;
			continue;
		}
	}
	//循环结束，将中心轴的值赋给左右指针重合处
	a[begin] = temp;

	QuickSort_Recursion(a, 0,begin);
	QuickSort_Recursion(a + begin + 1,begin, length - begin - 1);
}

//归并排序
void MergeArray(int* a, int begin, int mid, int end, int* temp) {
	//数组长度为1则无需排序
	if (begin >= end)return;

	int count = begin;
	
	int leftbegin = begin, leftend = mid,leftmid=leftbegin+(leftend-leftbegin)/2;
	int rightbegin = mid + 1, rightend = end, rightmid = rightbegin + (rightend - rightbegin) / 2;

	MergeArray(a, leftbegin, leftmid, leftend, temp);
	MergeArray(a, rightbegin,rightmid , rightend, temp);

	while (leftbegin <= leftend && rightbegin <= rightend)
		temp[count++] = a[leftbegin] < a[rightbegin] ? a[leftbegin++] : a[rightbegin++];
	while (leftbegin <= leftend)
		temp[count++] = a[leftbegin++];
	while (rightbegin <= rightend)
		temp[count++] = a[rightbegin++];
	for (int i = 0; i < end+1; i++)
	{
		a[i] = temp[i];
	}
	
}

void MergeSort(int* a, int begin, int end, int* temp) {
	if (end<=1)return;
	int mid = begin + (end - begin)/2;
	MergeArray(a, begin,mid, end,temp);
}

//计数排序
void CountSort(int* a, int size, int max) {
	if (size < 2)return;

	int* temp = (int*)malloc(max + 1 * sizeof(int));
	int i;
	for ( i = 0; i < size; i++)
	{
		temp[a[i]]++;
	}
	i = 0;
	for (int j = 0; j < max+1; j++)
	{
		for (int k = 0; k < temp[j]; k++)
		{
			a[i++] = j;
		}
	}
}

//基数计数排序
void RadixCountSort(int* a, int size) {
	int i, x = 1;
	int tmp = 1;
	int* radix = (int*)malloc(sizeof(int) * size);
	if (radix == NULL)return;  

	while (x)
	{
		tmp = tmp * 10;
		x = 0;

		for (i = 0; i < size; i++)
		{
			radix[i] = a[i] % tmp;
			radix[i] = radix[i] / (tmp / 10);
			if (a[i] / tmp > 0)
			{
				x = 1;
			}
		}
		int i;
		int* count = (int*)malloc(sizeof(int) * 10);
		if (count == NULL)return;

		for (i = 0; i < 10; i++)
		{
			count[i] = 0;
		}

		for (i = 0; i < size; i++)
		{
			count[radix[i]] ++;
		}

		for (i = 1; i < 10; i++)
		{
			count[i] = count[i] + count[i - 1];
		}

		int* sort = (int*)malloc(sizeof(int) * size);

		for (i = size - 1; i >= 0; i--)
		{
			count[radix[i]] --;
			sort[count[radix[i]]] = a[i];
		}

		for (i = 0; i < size; i++)
		{
			a[i] = sort[i];
		}

		free(sort);
		free(count);
	}
	free(radix);
}

//颜色排序
void ColorSort(int* a, int size) {
	int i= 0;
	int temp[3]={ 0 };
	for ( i = 0; i < size; i++)
	{
		if (a[i] == 0) {
			temp[a[i]]++;
		}
		if (a[i] == 1) {
			temp[a[i]]++;
		}
		if (a[i] == 2) {
			temp[a[i]]++;
		}
	}
	i = 0;
	for ( int j= 0; j < 3; j++)
	{
		for (int k = 0; k < temp[j]; k++)
		{
			a[i++] = j;
		}
	}
}

//在一个无序序列中找到第K大的数
void FindNumberInArr(int* a, int size, int k) {
	if (k == size) k = size - 1;
	int flag;
	for (int i = 0; i < k; i++) {
		flag = 0;
		for (int j = 0; j < size - i - 1; j++) {
			if (a[j] > a[j + 1]) {	
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				if (!flag) flag = 1;
			}
		}
		if (!flag) break;
	}
	printf("%d\n", a[k - 1]);
}


//生成随机数
void randomNumber(int* a, int size){
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 100;
	}
}

//寻找最大值
int getMax(int* a,int size) {
	int max = a[0];
	for (int i = 1; i <size ; i++)
	{
		if (max < a[i])max = a[i];
	}
	return max;
}
