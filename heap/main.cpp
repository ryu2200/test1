#include <stdio.h>
#include <iostream>
#include <time.h>
#include"Heap.h"
using namespace std;

int main(int argc, char** argv) {
	srand(time(0));
	//�쐬
	BinaryHeap<int,int> BinaryHeap(10000);
	int min = -1;
	//�q�[�v�Ɋi�[����id��100����
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
		//�q�[�v��x(�m�[�hid�ɓ�����)��ǉ�
		BinaryHeap.add(x);
		if (min != BinaryHeap.heap[0]) abort();
	}

	//���o���Ă����q�[�v���o�͂���
	
	
	for (int i = 0; i <100; i++) {
		//min-HeapProperty�Ȃ̂ŏ��������ɏo�͂����
		cout << BinaryHeap.pop() << endl;
	
		//cout << BinaryHeap.n;
		//cout << BinaryHeap.heap[0];
		//���̎q��2n+1�A�E�̎q��2n
		//cout << BinaryHeap.heap[i] << endl;
	}
	//for (int i = 0; i <100; i++) {
	//	//min-HeapProperty�Ȃ̂ŏ��������ɏo�͂����
	//	cout << BinaryHeap.pop() << endl;

	//	//cout << BinaryHeap.n;
	//	//cout << BinaryHeap.heap[0];
	//	//���̎q��2n+1�A�E�̎q��2n
	//	//cout << BinaryHeap.heap[i] << endl;
	//}

}