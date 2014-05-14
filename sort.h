/*排序技术汇总
	插入排序：直接插入排序和希尔排序
	交换排序：冒泡排序和快速排序
	选择排序：简单选择排序和堆排序
	归并排序
*/
//直接插入排序
void InsertSort(int* arrData,int m);
//希尔排序
void ShellSort(int *arrData,int m);

//冒泡排序
void BubbleSort(int* DataArr,int m);
//冒泡排序优化
void BubbleSort1(int* DataArr,int m);
//快速排序

int Partition(int* DataArr,int first,int end);
void QuickSort(int* DataArr,int first,int end);


//简单选择排序
void SelectSort(int* DataArr,int m);
//堆排序
void HeapSort(int* DataArr,int m);
//堆调整算法
void Sift(int*DataArr,int k,int m);
