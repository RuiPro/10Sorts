#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

#include "Sorts.h"

using namespace std;

int main() {
#ifdef _WIN32
	std::cout << "===== You are running on Windows! =====\n";
	system("chcp 65001 > nul");				//在windows控制台下输出UTF-8不乱码
#elif __linux__
	std::cout << "===== You are running on Linux! =====\n";
#endif

	//生成随机数
	int num(10000);
	vector<int> vec;
	vec.reserve(num);                //预申请空间
	default_random_engine randomEngine;
	//vec = {3000,200,10};		//debug
	for (int i(0); i < num; ++i) {
		vec.push_back(randomEngine());
		//vec.push_back(i);
	}
	int n(16);
	vector<vector<int>> v_arr(n, vec);

	//使用标准库的排序方法做校准
	auto startTime = chrono::system_clock::now();
	std::sort(vec.begin(), vec.end());
	chrono::duration<double> runTime = chrono::system_clock::now() - startTime;
	cout << "标准库sort()分类排序耗时：" << to_string(runTime.count()) << " 秒" << endl;

	//冒泡排序
	Sorts::BubbleSort01(v_arr.at(0));

	//冒泡排序优化1
	Sorts::BubbleSort02(v_arr.at(1));

	//冒泡排序优化2
	Sorts::BubbleSort03(v_arr.at(2));

	//冒泡排序优化3
	Sorts::BubbleSort04(v_arr.at(3));

	//冒泡排序究极优化
	Sorts::BubbleSort05(v_arr.at(4));

	//选择排序
	Sorts::SelectionSort01(v_arr.at(5));

	//选择排序优化
	Sorts::SelectionSort02(v_arr.at(6));

	//插入排序
	Sorts::InsertionSort(v_arr.at(7));

	//希尔排序
	Sorts::ShellSort(v_arr.at(8));

	//归并排序递归版
	Sorts::MergeSort01(v_arr.at(9));

	//归并排序迭代版
	Sorts::MergeSort02(v_arr.at(10));

	//快速排序
	Sorts::QuickSort01(v_arr.at(11));
	Sorts::QuickSort02(v_arr.at(12));

	//堆排序
	Sorts::HeapSort(v_arr.at(13));

	//桶排序
	Sorts::BucketSort(v_arr.at(14));

	//基数排序
	Sorts::RadixSort(v_arr.at(15));

	//计数排序，随机数容易导致分配内存失败，如果需要排序随机的int正类型，需要(4*INT_MAX)/(1024*1024) = 8191 MB内存
	//Sorts::CountSort(v_arr.at(17));

	for (int i(0); i < n; ++i) {
		if (v_arr[i] != vec) {
			cout << "v_arr[" << i << "]的整理结果不正确！！" << endl;
		}
	}

	return 0;
}