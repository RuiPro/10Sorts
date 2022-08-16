#include "Sorts.h"

/*由于计数排序不适用于完全随机数，此处仅实现但不使用*/

void Sorts::CountSort(vector<int>& v) {
	if (v.empty() || v.size() == 1) return;
	auto startTime = chrono::system_clock::now();

	//找出最大值和最小值
	int maxNum, minNum;
	maxNum = minNum = v.at(0);
	for (auto x : v) {
		if (maxNum < x) maxNum = x;
		if (minNum > x) minNum = x;
	}
	//定义一个保存数据量的数组、一个临时存放结果的数组
	//考虑到可能会爆栈把这俩都放在堆区
	int *parr = new int[maxNum - minNum + 1];
	for (int i = 0; i < maxNum - minNum + 1; ++i) {
		parr[i] = 0;
	}
	vector<int>* temp = new vector<int> (v.size(), 0);
	//进行计数
	for (auto x : v) {
		++parr[x - minNum];
	}
	//对计数表进行累计转换——便于瞬时查到数据的合理位置
	for (int i = 1; i < maxNum - minNum + 1; ++i) {
		parr[i] += parr[i - 1];
	}
	//对原数组进行从后往前的遍历，将值插入到临时的数组的正确位置上（从后往前是为了保持稳定性）
	for (auto j = v.size() - 1; j >= 0 && j < v.size(); --j) {
		temp->at(parr[v.at(j) - minNum] - 1) = v.at(j);
		--parr[v.at(j)  - minNum];
	}
	//将排序好的数组覆盖原数组
	v = *temp;

	delete[] parr;
	delete temp;

	chrono::duration<double> runTime = chrono::system_clock::now() - startTime;
	cout << "计数序耗时：" << to_string(runTime.count()) << " 秒" << endl;
}


