#include "Sorts.h"

void Heapify(vector<int>& v, decltype(v.size()) n, decltype(v.size()) i) {
	//n是元素的个数，i是要进行大顶堆操作的父节点
	//找出父节点和两个子节点中最大的值，放在父节点的位置上
	auto maxPos = i;
	auto leftChild = 2 * i + 1;
	auto rightChild = 2 * i + 2;
	if (leftChild < n && v.at(leftChild) > v.at(maxPos)) {
		maxPos = leftChild;
	}
	if (rightChild < n && v.at(rightChild) > v.at(maxPos)) {
		maxPos = rightChild;
	}
	if (maxPos != i) {
		int temp = v.at(i);
		v.at(i) = v.at(maxPos);
		v.at(maxPos) = temp;
		Heapify(v, n, maxPos);        //如果发生了子节点替换父节点的情况，该子节点往下的大顶堆结构都可能被破坏，需要重新排序
	}
}

void Sorts::HeapSort(vector<int>& v) {
	if (v.empty() || v.size() == 1) return;
	auto startTime = chrono::system_clock::now();

	//由杂乱的数组构建成一个大顶堆
	//(v.size() - 1 - 1) / 2求最后一个子节点的父节点，也就是随后一个非叶节点
	for (auto i = (v.size() - 1 - 1) / 2; i >= 0 && i < v.size(); --i) {
		Heapify(v, v.size(), i);
	}

	//进行堆排序：大顶堆的首元素肯定是最大的，把这个最大的元素和尾元素交换，再进行大顶堆操作
	//在交换后，尾元素已经在正确的位置上，无需再参与大顶堆操作，传入i来控制
	for(auto i = v.size() - 1; i > 0  && i < v.size(); --i){
		int temp = v.at(i);
		v.at(i) = v.at(0);
		v.at(0) = temp;
		Heapify(v, i, 0);
	}

	chrono::duration<double> runTime = chrono::system_clock::now() - startTime;
	cout << "堆序耗时：" << to_string(runTime.count()) << " 秒" << endl;
}


