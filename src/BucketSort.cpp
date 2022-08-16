#include "Sorts.h"
#include <vector>

//每个桶的范围设为1000
#define bucket_size 1000

void Sorts::BucketSort(vector<int>& v) {
	if (v.empty() || v.size() == 1) return;
	auto startTime = chrono::system_clock::now();

	// 1、找出最大值和最小值
	int maxNum, minNum;
	maxNum = minNum = v.at(0);
	for (auto x : v) {
		if (maxNum < x) maxNum = x;
		if (minNum > x) minNum = x;
	}
	// 2、定义桶
	int bucketNum = maxNum / bucket_size - minNum / bucket_size + 1;
	vector<vector<int>> bucket(bucketNum);
	// 3、遍历原数据，放入对应的桶中
	for (auto x : v) {
		bucket.at((x - minNum) / bucket_size).push_back(x);
	}
	// 4、将桶内的数据使用任意排序算法进行排序，这里用冒泡排序
	for (auto &x : bucket) {
		if (x.empty() || x.size() == 1) continue;
		bool hasSwap;
		decltype(x.size()) lastSwapPos = 0;
		decltype(x.size()) left = 0;
		decltype(x.size()) right = x.size() - 1;

		while (left < right) {
			hasSwap = false;
			for (auto i = left; i < right; i++) {
				if (x.at(i) > x.at(i + 1)) {
					int temp(x.at(i));
					x.at(i) = x.at(i + 1);
					x.at(i + 1) = temp;
					hasSwap = true;
					lastSwapPos = i;
				}
			}
			right = lastSwapPos;
			for (auto i = right; i > left; i--) {
				if (x.at(i) < x.at(i - 1)) {
					int temp(x.at(i));
					x.at(i) = x.at(i - 1);
					x.at(i - 1) = temp;
					hasSwap = true;
					lastSwapPos = i;
				}
			}
			left = lastSwapPos;
			if (!hasSwap) break;
		}
	}
	// 5、将桶内的数据按批次顺序替换到原数组中
	decltype(v.size()) pos = 0;
	for (auto i : bucket) {
		for (auto j : i) {
			v.at(pos) = j;
			++pos;
		}
	}

	chrono::duration<double> runTime = chrono::system_clock::now() - startTime;
	cout << "桶排序耗时：" << to_string(runTime.count()) << " 秒" << endl;
}

