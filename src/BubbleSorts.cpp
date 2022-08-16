#include "Sorts.h"

void Sorts::BubbleSort01(vector<int>& v) {              //传统冒泡排序
	if (v.empty() || v.size() == 1) return;
	auto startTime = chrono::system_clock::now();

	for (int i(0); i <= v.size() - 1; ++i) {            //轮回size次
		for (int j(0); j < v.size() - 1 - i; ++j) {     //每次轮回对未排序的数值进行两两比较
			if (v.at(j) > v.at(j + 1)) {
				int temp(v.at(j));
				v.at(j) = v.at(j + 1);
				v.at(j + 1) = temp;
			}
		}
	}

	chrono::duration<double> runTime = chrono::system_clock::now() - startTime;
	cout << "冒泡排序耗时：" << to_string(runTime.count()) << " 秒" << endl;
}

void Sorts::BubbleSort02(vector<int>& v) {            //冒泡排序优化——设置标志位
	if (v.empty() || v.size() == 1) return;
	auto startTime = chrono::system_clock::now();

	bool hasSwap;                                    //创建标记并初始化为true，保证第一次遍历
	for (int i(0); i <= v.size() - 1; ++i) {                 //轮回size次
		hasSwap = false;                                    //复位
		for (int j(0); j < v.size() - 1 - i; ++j) {     //每次轮回对未排序的数值进行两两比较
			if (v.at(j) > v.at(j + 1)) {
				int temp(v.at(j));
				v.at(j) = v.at(j + 1);
				v.at(j + 1) = temp;
				hasSwap = true;                            //如果发生交换则把hasSwap设为true
			}
		}
		if (!hasSwap) break;                             //如果hasSwap为false，即该次遍历没有发生交换，则提前结束
	}

	chrono::duration<double> runTime = chrono::system_clock::now() - startTime;
	cout << "冒泡排序优化-标记法耗时：" << to_string(runTime.count()) << " 秒" << endl;
}

void Sorts::BubbleSort03(vector<int>& v) {            //冒泡排序优化——设置边界位
	if (v.empty() || v.size() == 1) return;
	auto startTime = chrono::system_clock::now();

	auto lastSwapPos = v.size() - 1;                        //初始化边界
	for (int i(0); i <= v.size() - 1; ++i) {            //轮回size次
		auto k = lastSwapPos;                        //因为在for循环中lastSwapPos是会变化的，需要额外的一个变量（常量）来支持循环
		for (int j(0); j < k; ++j) {                //每次轮回对未排序的数值进行两两比较
			if (v.at(j) > v.at(j + 1)) {
				int temp(v.at(j));
				v.at(j) = v.at(j + 1);
				v.at(j + 1) = temp;
				lastSwapPos = j;                        //最后一次交换的位置为新边界。边界之后的值都已经正确排序
			}
		}
	}

	chrono::duration<double> runTime = chrono::system_clock::now() - startTime;
	cout << "冒泡排序优化-边界法耗时：" << to_string(runTime.count()) << " 秒" << endl;
}

void Sorts::BubbleSort04(vector<int>& v) {              //冒泡排序优化——双向冒泡法
	if (v.empty() || v.size() == 1) return;
	auto startTime = chrono::system_clock::now();

	decltype(v.size()) left = 0;
	decltype(v.size()) right = v.size() - 1;

	while (left < right) {
		for (decltype(v.size()) i = left; i < right; i++) {                //把比较大的数冒泡到右边
			if (v.at(i) > v.at(i + 1)) {
				int temp(v.at(i));
				v.at(i) = v.at(i + 1);
				v.at(i + 1) = temp;
			}
		}
		right--;
		for (auto i = right; i > left; i--) {                //把比较小的数冒泡到左边
			if (v.at(i) < v.at(i - 1)) {
				int temp(v.at(i));
				v.at(i) = v.at(i - 1);
				v.at(i - 1) = temp;
			}
		}
		left++;                                                //right--\left++表示左右两端的数已经确定，接下来处理中间即可
	}

	chrono::duration<double> runTime = chrono::system_clock::now() - startTime;
	cout << "冒泡排序优化-双向法耗时：" << to_string(runTime.count()) << " 秒" << endl;
}

void Sorts::BubbleSort05(vector<int>& v) {              //冒泡排序优化——究极优化:标记法+边界法+双向法
	if (v.empty() || v.size() == 1) return;
	auto startTime = chrono::system_clock::now();

	bool hasSwap;
	decltype(v.size()) lastSwapPos = 0;
	decltype(v.size()) left = 0;
	decltype(v.size()) right = v.size() - 1;

	while (left < right) {
		hasSwap = false;
		for (auto i = left; i < right; i++) {
			if (v.at(i) > v.at(i + 1)) {
				int temp(v.at(i));
				v.at(i) = v.at(i + 1);
				v.at(i + 1) = temp;
				hasSwap = true;
				lastSwapPos = i;
			}
		}
		right = lastSwapPos;
		for (auto i = right; i > left; i--) {
			if (v.at(i) < v.at(i - 1)) {
				int temp(v.at(i));
				v.at(i) = v.at(i - 1);
				v.at(i - 1) = temp;
				hasSwap = true;
				lastSwapPos = i;
			}
		}
		left = lastSwapPos;
		if (!hasSwap) break;
	}

	chrono::duration<double> runTime = chrono::system_clock::now() - startTime;
	cout << "冒泡排序究极优化耗时：" << to_string(runTime.count()) << " 秒" << endl;
}

