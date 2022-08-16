#include "Sorts.h"
#include <cmath>

void Sorts::RadixSort(vector<int>& v) {
	if (v.empty() || v.size() == 1) return;
	auto startTime = chrono::system_clock::now();

	// 1、找出最大值,求出最大位数
	int maxNum = v.at(0);
	for (auto x : v) {
		if (maxNum < x) maxNum = x;
	}
	int bit = 0;
	while (maxNum) {
		++bit;
		maxNum /= 10;
	}
	// 2、对每个位进行计数排序
	for (int i = 0; i < bit; ++i) {
		// Ⅰ.定义一个保存数据量的数组、一个临时存放结果的数组、要求的位数辅助数
		int arr[10] = { 0 };
		vector<int> temp(v.size(), 0);
		int figure = pow(10, i);
		// Ⅱ.进行计数
		for (auto x : v) {
			++arr[(x / figure) % 10];
		}
		// Ⅲ.对计数表进行累计转换——便于瞬时查到数据的合理位置
		for (int i = 1; i < 10; ++i) {
			arr[i] += arr[i - 1];
		}
		// Ⅳ.对原数组进行从后往前的遍历，将值插入到临时的数组的正确位置上（从后往前是为了保持稳定性）
		// 同时注意temp的下标也是从0开始，下标要减一
		for (auto j = v.size() - 1; j >= 0 && j < v.size(); --j) {
			temp.at(arr[(v.at(j) / figure) % 10] - 1) = v.at(j);
			--arr[(v.at(j) / figure) % 10];
		}
		// Ⅴ.将排序好的数组覆盖原数组
		v = temp;
	}

	chrono::duration<double> runTime = chrono::system_clock::now() - startTime;
	cout << "基数排序耗时：" << to_string(runTime.count()) << " 秒" << endl;
}
