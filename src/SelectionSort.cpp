#include "Sorts.h"

void Sorts::SelectionSort01(vector<int>& v) {
	if (v.empty() || v.size() == 1) return;
	auto startTime = chrono::system_clock::now();

	decltype(v.size()) minPos;
	for (decltype(v.size()) i(0); i < v.size() - 1; ++i) {
		minPos = i;                                                //初始化最小值的位置
		for (decltype(v.size()) j(i + 1); j <= v.size() - 1; ++j) {  //找出最小值的位置
			if (v.at(j) < v.at(minPos)) {
				minPos = j;
			}
		}
		if (minPos != i) {
			int temp = v.at(i);                                  //将最小值调到前面
			v.at(i) = v.at(minPos);
			v.at(minPos) = temp;
		}
	}

	chrono::duration<double> runTime = chrono::system_clock::now() - startTime;

	cout << "选择排序耗时：" << to_string(runTime.count()) << " 秒" << endl;
}

void Sorts::SelectionSort02(vector<int>& v) {
	if (v.empty() || v.size() == 1) return;
	auto startTime = chrono::system_clock::now();

	decltype(v.size()) minPos, maxPos;
	for (decltype(v.size()) i(0); i < v.size() - 1 - i; ++i) {
		minPos = i;                                                //初始化最小值、最大值的位置
		maxPos = v.size() - 1 - i;
		for (decltype(v.size()) j(i); j <= v.size() - 1 - i; ++j) {   //找出最小值、最大值的位置
			if (v.at(j) < v.at(minPos)) {
				minPos = j;
			}
			if (v.at(j) > v.at(maxPos)) {
				maxPos = j;
			}
		}
		if (minPos != i && maxPos == i) {                //最大值位置处于最小值即将替换的位置时，需要特殊处理
			int temp = v.at(i);                //如对{5，3，4}和{3，2，1}进行排序时，由于最大值的位置已经变化，需要重新定位
			v.at(i) = v.at(minPos);
			v.at(minPos) = temp;
			maxPos = minPos;
			minPos = i;						//最小值已经交换，为了避免下面重复进行交换导致出错
		}
		if (minPos != i) {
			int temp = v.at(i);                                        //将最小值调到前面
			v.at(i) = v.at(minPos);
			v.at(minPos) = temp;
		}
		if (maxPos != v.size() - 1 - i) {
			int temp = v.at(v.size() - 1 - i);                            //将最大值调到后面
			v.at(v.size() - 1 - i) = v.at(maxPos);
			v.at(maxPos) = temp;
		}
	}

	chrono::duration<double> runTime = chrono::system_clock::now() - startTime;
	cout << "选择排序优化耗时：" << to_string(runTime.count()) << " 秒" << endl;
}

