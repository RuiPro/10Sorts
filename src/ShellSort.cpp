#include "Sorts.h"

void Sorts::ShellSort(vector<int>& v) {
	if (v.empty() || v.size() == 1) return;
	auto startTime = chrono::system_clock::now();

	decltype(v.size()) i, j, k, step;
	for (step = v.size() / 2; step > 0; step /= 2) {                //设置增量，初始为数组大小的1/2，每循环一次减半
		for (i = 0; i < step; ++i) {                                //对每一个增量进行分组
			for (j = i + step; j < v.size(); j += step) {            //对每组进行插入排序
				int key = v.at(j);                                    //即将要插入排序的数
				k = j - step;
				while (k >= 0 && v.at(k) > key) {                    //如果前面有值比要插入排序的数大
					v.at(k + step) = v.at(k);                        //将前面比要插入排序的数大的数都往后移一个增量
					if (k < step) {                                //因为k是无符号长整型，不能小于0，因此需要特殊照顾
						k -= step;
						break;
					}
					k -= step;
				}
				v.at(k + step) = key;                            //把要插入排序的数补入合适的位置
			}
		}
	}

	chrono::duration<double> runTime = chrono::system_clock::now() - startTime;
	cout << "希尔排序耗时：" << to_string(runTime.count()) << " 秒" << endl;
}
