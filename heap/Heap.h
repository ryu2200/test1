#ifndef _HEAP
#define _HEAP
#include<map>
#include<vector>
using namespace std;
//�o�C�i���q�[�v�ł͐e�m�[�h���q�m�[�h����min-heapProperty�ɏ]��
//�����Ȑ��l�������Ă���΂�������
template <typename ID, typename VAR>
class BinaryHeap {
public:
	//�m�[�hID���i�[����
	ID heap[10000];
	//����v�f�ɐU��ꂽ�ԍ�
	int n;
	//�m�[�h�R�X�g
	VAR* var;
	//�m�[�hid
	ID* id;
	////ID����m�[�h�R�X�g���Q�Ƃ���
	//map<ID, VAR> node1;
	////�m�[�h�R�X�g�J��ID���Q��
	//map<ID, VAR> nodes;
	////�q�[�v�Ƀm�[�h��ǉ�����
	//void add(ID id, VAR var){
	//	node1[id] = var;
	//	node2[var] = id;
	//};
	//�q�[�v�̍ő�̃T�C�Y�����肷��
	BinaryHeap(int max){
		//�C���f�b�N�X��0����n�܂�
		n = 0;
		//�C���f�b�N�X�̍ő�l������
		//heap.resize(max);
	};
	//���[�g�Ɋi�[����Ă���m�[�hid�����o��
	//���̎��o�C�i���E�q�[�v����ŏ��l����菜�����ꍇ�A
	//��͂�A�e���q���傫�Ȑ��l�����悤�ɁA �e�Ǝq����ꂩ���܂��B
	ID pop() {
		//���[�g�����o��
		ID ans = heap[0];
		//���[�̗v�f���擾
		heap[0] = heap[--n];
		int i = 0;
		while (true) {
			//���̎q
			int leftChild = i * 2 + 1;
			//�E�̎q
			int rightChild = i * 2 + 2;
			if (leftChild >= n) break;
			if (rightChild >= n) rightChild = leftChild;
			int minChild;
			//���E�ǂ���̎q�̕�����������
			if (heap[leftChild] < heap[rightChild]){
				minChild = leftChild;
				
			}
			else minChild = rightChild;
			//min-heapProperty��ۂ���
			//�e�����E�̏������q���傫����Ό���
			//���[�̒l���擾���Ă��邽��
			if (heap[minChild] < heap[i]) {
				//������heap[0]�̒l�����������
				swap(i, minChild);
				i = minChild;
			}
			else {
				break;
			}
		}
		
		return ans;
	}
	
	//�C���f�b�N�X�����Ƀm�[�hID���擾
	//���[�g�ȊO�̃m�[�h���C���f�b�N�X����Q�Ƃ�����
	ID pop(int& index){
		return heap[index];
	};
	//�i�[����Ă���l����������
	inline void swap(int i1, int i2) {
		int tmp = heap[i1];
		heap[i1] = heap[i2];
		heap[i2] = tmp;
	}

	//�e���q���傫�Ȑ��l�����Ƃ������������藧�Ƃ���܂ŁA
	//�Q���؂��̓o��A �e�Ǝq����ꂩ���Ă���
	void exchange(int n) {
		while (true) {
			//���[�g�ł���ΏI��
			if (n == 0) break;
			//�e�̃C���f�b�N�X�����߂�
			int parent = (n - 1) / 2;
			//min-heapProperty��ۂ��ߊi�[���ꂽ�l���e�������������Ƃ������
			//�e�Ǝq�����ւ���
			if (heap[n] < heap[parent]) {
				swap(n, parent);
				n = parent;
			}
			else {
				break;
			}
		}
	}
	//�q�[�v�Ƀm�[�hID��������
	void add(ID ndid) {
		//�q�[�v��id���i�[
		heap[n] = ndid;
		//min-heapProperty�ɔ�����ꍇ�e�Ǝq�����ւ���
		exchange(n);
		//�ԍ�������₷
		n++;
	}

	//����p���X�V����邲�ƂɃ��[�g�Ƀm�[�h��}������
	void insert(int depth,ID ndid){

	}
	void up(int n)
	{
		int m;

		if ((size == 0) || (n == 0)) return;
		m = (n + 1) / 2 - 1;
		if (heap[m] < heap[n]) {

			swap(m, n);
			up(m);

		}
		return;
	}
	void down(int n)
	{
		int m;

		if ((size == 0) || (n >= size)) return;
		m = (n + 1) * 2 - 1;
		if (m >= size) return;
		if (m + 1 >= size) {

			if (heap[m] > heap[n])
				swap(m, n);
			return;

		}
		if (heap[m] < heap[m + 1])
			m = m + 1;
		if (heap[m] > heap[n]) {

			swap(m, n);
			down(m);

		}

		return;
	}
};

#endif