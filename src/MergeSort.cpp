#include "Sorts.h"

void MergeFunction(vector<int>& v, decltype(v.size()) front, decltype(v.size()) end) {
	if (front < end) {
		// 1.将传入的数组划分成两个部分并继续递归划分
		auto mid = (front + end) / 2;
		MergeFunction(v, front, mid);
		MergeFunction(v, mid + 1, end);

		// 2.在划分完毕之后，对已排序的数组进行归并
		decltype(v.size()) left_index = front, right_index = mid + 1;            //对左右子数组的下标进行标记
		vector<int> temp(end - front + 1, 0);                                  //定义一个临时容器保存整理好的数
		int i = 0;
		//对左右子数组进行比较
		while (left_index <= mid && right_index <= end) {                //当左右子数组都有元素未排序时循环
			//比较左右子数组下标指向元素的大小，把比较大的存入临时容器中，且标记往后移动一位
			temp.at(i++) = v.at(left_index) < v.at(right_index) ? v.at(left_index++) : v.at(right_index++);
		}
		while (left_index <= mid)                  //当左或右子数组有一个已经将全部元素排好序时
			temp.at(i++) = v.at(left_index++);     //将另一边剩余的元素直接拷贝
		while (right_index <= end)
			temp.at(i++) = v.at(right_index++);

		// 3.将整理好的临时容器覆盖到原容器的对应位置
		for (i = 0; i < end - front + 1; ++i) {
			v.at(i + front) = temp.at(i);
		}
	}
}

void Sorts::MergeSort01(vector<int>& v) {
	if (v.empty() || v.size() == 1) return;
	auto startTime = chrono::system_clock::now();

	//进行分类
	MergeFunction(v, 0, v.size() - 1);

	chrono::duration<double> runTime = chrono::system_clock::now() - startTime;
	cout << "归并排序-递归法耗时：" << to_string(runTime.count()) << " 秒" << endl;
}

void Sorts::MergeSort02(vector<int>& v) {
	if (v.empty() || v.size() == 1) return;
	auto startTime = chrono::system_clock::now();

	auto temp = v;            //定义一个临时容器保存整理好的数
	for (decltype(v.size()) length = 1; length < v.size(); length += length) {       //设置等比的子数组的长度
		for (decltype(v.size()) start = 0; start < v.size(); start += (length + length)) { //每两个子数组形成一对
			decltype(v.size()) front1 = start, i = start,       //定义两个子数组的头尾和在原容器中的起始位置
			end1 = (start + length) < v.size() ? start + length : v.size(),
				front2 = end1,
				end2 = (start + length + length) < v.size() ? start + length + length : v.size();
			//进行对比排序
			while (front1 < end1 && front2 < end2) {          //当左右子数组都有元素未排序时循环
				temp.at(i++) = v.at(front1) < v.at(front2) ? v.at(front1++) : v.at(front2++);
			}
			while (front1 < end1)                    //当左或右子数组有一个已经将全部元素排好序时
				temp.at(i++) = v.at(front1++);        //将另一边剩余的元素直接拷贝
			while (front2 < end2)
				temp.at(i++) = v.at(front2++);
		}
		v = temp;                                //将排好序的临时容器覆盖原容器，进行下一个子数组长度的循环
	}

	chrono::duration<double> runTime = chrono::system_clock::now() - startTime;
	cout << "归并排序-迭代法耗时：" << to_string(runTime.count()) << " 秒" << endl;
}
