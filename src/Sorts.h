#ifndef _SORTS_H_
#define _SORTS_H_

#include <vector>
#include <iostream>
#include <chrono>

using namespace std;

class Sorts {
 public:
	//冒泡排序
	static void BubbleSort01(vector<int>& v);
	static void BubbleSort02(vector<int>& v);
	static void BubbleSort03(vector<int>& v);
	static void BubbleSort04(vector<int>& v);
	static void BubbleSort05(vector<int>& v);
	//选择排序
	static void SelectionSort01(vector<int>& v);
	static void SelectionSort02(vector<int>& v);
	//插入排序
	static void InsertionSort(vector<int>& v);
	//希尔排序
	static void ShellSort(vector<int>& v);
	//希尔排序
	static void MergeSort01(vector<int>& v);
	static void MergeSort02(vector<int>& v);
	//快速排序
	static void QuickSort01(vector<int>& v);
	static void QuickSort02(vector<int>& v);
	//堆排序
	static void HeapSort(vector<int> &v);
	//计数排序
	static void CountSort(vector<int>& v);
	//桶排序
	static void BucketSort(vector<int> &v);
	//基数排序
	static void RadixSort(vector<int> &v);
};

#endif //_SORTS_H_
