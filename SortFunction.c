#include"D:\VSProgram\Test\SortTest\sort.h"

//��������
void insertSort(int*a,int n){
	
	//���鳤��Ϊ1��������
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

//�������򣨵ݹ�棩
void QuickSort_Recursion(int* a, int begin, int end) {
	if (end < 1)return;		//���鳤��Ϊ1��������

	int length = end;
	int temp = a[0];		//ѡȡ����ߵ�����Ԫ��Ϊ������
	int flag = 1;			//�ж���Ҫ�ƶ�����ߣ�1Ϊ�����꣬0Ϊ������

	while (begin<end)
	{
		//�ƶ����±�����
		if (flag==1)
		{
			//���±�Ԫ�ص�ֵ���ڵ��������ᣬ�����ƶ����±�
			if (a[end] >= temp) {
				end--;
				continue;
			}

			//�����±�λ��Ԫ��С�������ᣬ������ֵ�������±�
			a[begin] = a[end];
			begin++;					//���±������ƶ�
			flag = 0;				//�´��ƶ����±�
			continue;
		}

		//�ƶ����±�
		if (flag==0)
		{
			//���±�Ԫ�ص�ֵ���ڵ��������ᣬ�����ƶ����±�
			if (a[begin]<=temp)
			{
				begin++;
				continue;
			}

			//�����±�λ��Ԫ��С�������ᣬ������ֵ�������±�
			a[end] = a[begin];
			end--;
			flag = 1;
			continue;
		}
	}
	//ѭ�����������������ֵ��������ָ���غϴ�
	a[begin] = temp;

	QuickSort_Recursion(a, 0,begin);
	QuickSort_Recursion(a + begin + 1,begin, length - begin - 1);
}

//�鲢����
void MergeArray(int* a, int begin, int mid, int end, int* temp) {
	//���鳤��Ϊ1����������
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

//��������
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

//������������
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

//��ɫ����
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

//��һ�������������ҵ���K�����
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


//���������
void randomNumber(int* a, int size){
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 100;
	}
}

//Ѱ�����ֵ
int getMax(int* a,int size) {
	int max = a[0];
	for (int i = 1; i <size ; i++)
	{
		if (max < a[i])max = a[i];
	}
	return max;
}
