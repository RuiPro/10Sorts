#include "Sorts.h"

void Sorts::InsertionSort(vector<int>& v) {
	if (v.empty() || v.size() == 1) return;
	auto startTime = chrono::system_clock::now();

	decltype(v.size()) i, j;
	int key;
	for (i = 1; i < v.size(); i++) {
		key = v.at(i);                                //即将要插入排序的数
		j = i - 1;
		while (j >= 0 && j < v.size() && v.at(j) > key) {   //如果前面有值比要插入排序的数大
			v.at(j + 1) = v.at(j);                    //将前面比要插入排序的数大的数都往后移一位
			--j;
		}
		v.at(j + 1) = key;                            //把要插入排序的数补入合适的位置
	}

	chrono::duration<double> runTime = chrono::system_clock::now() - startTime;
	cout << "插入排序耗时：" << to_string(runTime.count()) << " 秒" << endl;
}