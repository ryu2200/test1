#include <stdio.h>
#include <iostream>
#include <time.h>
#include"Heap.h"
using namespace std;

int main(int argc, char** argv) {
	srand(time(0));
	//作成
	BinaryHeap<int,int> BinaryHeap(10000);
	int min = -1;
	//ヒープに格納するidを100個生成
	for (int i = 0; i < 100; i++) {
		int x = rand() % 100000;
		if (min < 0) {
			min = x;
		}
		else {
			if (min > x) {
				min = x;
			}
		}
		//ヒープにx(ノードidに当たる)を追加
		BinaryHeap.add(x);
		if (min != BinaryHeap.heap[0]) abort();
	}

	//取り出してきたヒープを出力する
	
	
	for (int i = 0; i <100; i++) {
		//min-HeapPropertyなので小さい順に出力される
		cout << BinaryHeap.pop() << endl;
	
		//cout << BinaryHeap.n;
		//cout << BinaryHeap.heap[0];
		//左の子が2n+1、右の子が2n
		//cout << BinaryHeap.heap[i] << endl;
	}
	//for (int i = 0; i <100; i++) {
	//	//min-HeapPropertyなので小さい順に出力される
	//	cout << BinaryHeap.pop() << endl;

	//	//cout << BinaryHeap.n;
	//	//cout << BinaryHeap.heap[0];
	//	//左の子が2n+1、右の子が2n
	//	//cout << BinaryHeap.heap[i] << endl;
	//}

}