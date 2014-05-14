#include "sort.h"
#include <iostream>

using namespace std;

void InsertSort(int* arrData,int m)
{
	//从第2个元素开始进行插入操作
	for(int i=1;i<m;i++)
	{
		int j=i-1;
		int temp=arrData[i];//记录要插入的元素
		while(j>=0&&arrData[j]>temp)
		{
			arrData[j+1]=arrData[j];//向后移动
			j--;
		}
		if(j!=i-1)//如果有记录移动后
		{
			arrData[j+1]=temp;
		}
	}
}

void ShellInsert(int* arrData,int d,int m)
{
	for(int i=d;i<m;i++)
	{
		int j = i - d;  
        int temp = arrData[i];    //记录要插入的数据  
        while (j >= 0 && arrData[j] > temp)    //从后向前，找到比其小的数的位置  
        {  
            arrData[j+d] = arrData[j];    //向后挪动  
            j -= d;  
        }  
  
        if (j != i - d)    //存在比其小的数  
            arrData[j+d] = temp; 
	}
}
void ShellSort(int* arrData,int m)
{
	int d=m/2;//初始增量设为长度的一半
	while(d>=1)
	{
		ShellInsert(arrData,d,m);
		d=d/2;
	}
}

void BubbleSort(int* DataArr,int m)
{

	bool flag=false;//交换标志位
	for(int i=0;i<m;i++)
	{
		flag=false;
		for(int j=1;j<m-i;j++)
		{
			if(DataArr[j]<DataArr[j-1])//相邻元素进行比较
			{
				int temp=DataArr[j];
				DataArr[j]=DataArr[j-1];
				DataArr[j-1]=temp;
				flag=true;
			}
		}
		if(!flag)//如果一趟比较下来没有发生交换，则表明该序列意见排好序
			break;
	}
}
//冒泡排序的优化，假如出现这种情况：如果有一个100个大小的数组，其中前10个无序，后90个是有序的且都大于前面10个数，那么
//在第一趟排完序后，交换的位置肯定小于10，且这之后的数都排好序了，不需要遍历，记录下这个位置，等第二趟排序时就只需要从
//这个位置开始排序就好了，不需要再全部遍历。
void BubbleSort1(int* DataArr,int m)
{
	int k;//需要比较的个数
	int flag=m;//交换位置的标志
	while(flag>0)  
	{
		k=flag;
		flag=0;
		for(int j=1;j<k;j++)
			if(DataArr[j]<DataArr[j-1])
			{
				int temp=DataArr[j];
				DataArr[j]=DataArr[j-1];
				DataArr[j-1]=temp;
				flag=j;//标志发生交换的位置
			}
	}

}
//快速排序一次划分
int Partition(int* DataArr,int first,int end)
{
	int i=first,j=end;
	while(i<j)
	{
		//当j的关键码大于i的关键码时,j向前进
		while(i<j&&DataArr[i]<=DataArr[j])
			j--;
		//否则j的关键码不大于i的关键码，此时需要交换j和i的关键码,且把i向前移一个位置
		if(i<j)
		{
			int temp=DataArr[i];
			DataArr[i]=DataArr[j];
			DataArr[j]=temp;
			i++;
		}
		//当j的关键码大于i的关键码时，i向后进
		while(i<j&&DataArr[i]<=DataArr[j])
			i++;
		if(i<j)
		{
			int temp=DataArr[i];
			DataArr[i]=DataArr[j];
			DataArr[j]=temp;
			j--;
		}
	}
	return i;//返回最终记录的位置
}

void QuickSort(int* DataArr,int first,int end)
{
	int loc;
	if(first<end)
	{
		loc=Partition(DataArr,first,end);
		QuickSort(DataArr,first,loc-1);
		QuickSort(DataArr,loc+1,end);
	}
}

void SelectSort(int* DataArr,int m)
{
	int index;//记录无序区最小元素的位置
	for(int i=0;i<m;i++)
	{
		index=i;
		for(int j=i+1;j<m;j++)
		{
			if(DataArr[j]<DataArr[index])
				index=j;
		}
		if(index!=i)
		{
			int temp=DataArr[i];
			DataArr[i]=DataArr[index];
			DataArr[index]=temp;
		}
	}
}
