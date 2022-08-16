#include "Sorts.h"

void QuickSortFunc1(vector<int>& v, decltype(v.size()) front, decltype(v.size()) end) {
	if (front >= end) return;
	// 1、找出基准，一般为待排序数组首个元素或末个元素。这里取首元素
	int pivot = v.at(front);

	// 2、定义双“指针”并进行整理
	decltype(v.size()) i = front, j = end;
	while (i < j) {
		while (v.at(j) >= pivot && i < j) --j;      //先从右边开始找比基准小的，确保j在循环结束后指向的是最后一个比基准小的值
		while (v.at(i) <= pivot && i < j) ++i;      //这时j的位置就是基准的合理位置
		if (i < j) {
			int temp = v.at(i);
			v.at(i) = v.at(j);
			v.at(j) = temp;
		}
	}
	v.at(front) = v.at(j);        //循环结束后，j的位置就是基准正确的位置
	v.at(j) = pivot;

	// 3、递归，由于j是无符号长长整形，j >= 0，因此需要判断j - 1是否会越界
	if (j > 0) {
		QuickSortFunc1(v, front, j - 1);
	}
	QuickSortFunc1(v, j + 1, end);
}

//定义一个结构体，保存未排序的区段：front未区段头，end为区段尾
struct MyStack {
	MyStack(vector<int>::size_type i, vector<int>::size_type j) {
		front = i;
		end = j;
	}
	vector<int>::size_type front, end;
};

void QuickSortFunc2(vector<int>& v, decltype(v.size()) front, decltype(v.size()) end, vector<MyStack>* stack_ptr) {
	if (front >= end) {
		stack_ptr->pop_back();
		return;
	}
	// 1、找出基准，一般为待排序数组首个元素或末个元素。这里取首元素
	int pivot = v.at(front);

	// 2、定义双“指针”并进行整理
	decltype(v.size()) i = front, j = end;
	while (i < j) {
		while (v.at(j) >= pivot && i < j) --j;      //先从右边开始找比基准小的，确保j在循环结束后指向的是最后一个比基准小的值
		while (v.at(i) <= pivot && i < j) ++i;      //这时j的位置就是基准的合理位置
		if (i < j) {
			int temp = v.at(i);
			v.at(i) = v.at(j);
			v.at(j) = temp;
		}
	}
	v.at(front) = v.at(j);        //循环结束后，j的位置就是基准正确的位置
	v.at(j) = pivot;

	stack_ptr->pop_back();	//执行完毕这个区段后，这个区段出栈

	// 3、将未排序的两个子区段入栈，由于j是无符号长长整形，j >= 0，因此需要判断j - 1是否会越界
	if (j > 0) {
		stack_ptr->push_back(MyStack(front, j - 1));
	}
	stack_ptr->push_back(MyStack(j + 1, end));
}

void Sorts::QuickSort01(vector<int>& v) {
	if (v.empty() || v.size() == 1) return;
	auto startTime = chrono::system_clock::now();

	QuickSortFunc1(v, 0, v.size() - 1);

	chrono::duration<double> runTime = chrono::system_clock::now() - startTime;
	cout << "快速排序-递归法耗时：" << to_string(runTime.count()) << " 秒" << endl;
}

void Sorts::QuickSort02(vector<int>& v) {
	if (v.empty() || v.size() == 1) return;
	auto startTime = chrono::system_clock::now();

	//在堆区定义一个栈，保存未进行排序的区段
	vector<MyStack>* stack_ptr = new vector<MyStack>;
	//把v入栈
	stack_ptr->push_back(MyStack(0, v.size() - 1));
	//当栈不为空时，说明有区段未进行排序，取栈顶的子区段进行排序
	while (!stack_ptr->empty()) {
		QuickSortFunc2(v, (stack_ptr->end() - 1)->front, (stack_ptr->end() - 1)->end, stack_ptr);
	}
	delete stack_ptr;

	chrono::duration<double> runTime = chrono::system_clock::now() - startTime;
	cout << "快速排序-自定义栈法耗时：" << to_string(runTime.count()) << " 秒" << endl;
}
