#ifndef _HEAP
#define _HEAP
#include<map>
#include<vector>
using namespace std;
//バイナリヒープでは親ノードが子ノードよりもmin-heapPropertyに従い
//小さな数値を持っていればいいだけ
template <typename ID, typename VAR>
class BinaryHeap {
public:
	//ノードIDを格納する
	ID heap[10000];
	//ある要素に振られた番号
	int n;
	//ノードコスト
	VAR* var;
	//ノードid
	ID* id;
	////IDからノードコストを参照する
	//map<ID, VAR> node1;
	////ノードコストカラIDを参照
	//map<ID, VAR> nodes;
	////ヒープにノードを追加する
	//void add(ID id, VAR var){
	//	node1[id] = var;
	//	node2[var] = id;
	//};
	//ヒープの最大のサイズを決定する
	BinaryHeap(int max){
		//インデックスは0から始まる
		n = 0;
		//インデックスの最大値を決定
		//heap.resize(max);
	};
	//ルートに格納されているノードidを取り出す
	//この時バイナリ・ヒープから最小値を取り除いた場合、
	//やはり、親が子より大きな数値を持つように、 親と子を入れかえます。
	ID pop() {
		//ルートを取り出す
		ID ans = heap[0];
		//末端の要素を取得
		heap[0] = heap[--n];
		int i = 0;
		while (true) {
			//左の子
			int leftChild = i * 2 + 1;
			//右の子
			int rightChild = i * 2 + 2;
			if (leftChild >= n) break;
			if (rightChild >= n) rightChild = leftChild;
			int minChild;
			//左右どちらの子の方が小さいか
			if (heap[leftChild] < heap[rightChild]){
				minChild = leftChild;
				
			}
			else minChild = rightChild;
			//min-heapPropertyを保つため
			//親が左右の小さい子より大きければ交換
			//末端の値を取得しているため
			if (heap[minChild] < heap[i]) {
				//ここでheap[0]の値が交換される
				swap(i, minChild);
				i = minChild;
			}
			else {
				break;
			}
		}
		
		return ans;
	}
	
	//インデックスを元にノードIDを取得
	//ルート以外のノードもインデックスから参照したい
	ID pop(int& index){
		return heap[index];
	};
	//格納されている値を交換する
	inline void swap(int i1, int i2) {
		int tmp = heap[i1];
		heap[i1] = heap[i2];
		heap[i2] = tmp;
	}

	//親が子より大きな数値を持つという条件が成り立つところまで、
	//２分木をの登りつつ、 親と子を入れかえていく
	void exchange(int n) {
		while (true) {
			//ルートであれば終了
			if (n == 0) break;
			//親のインデックスを求める
			int parent = (n - 1) / 2;
			//min-heapPropertyを保つため格納された値が親よりも小さいことがあれば
			//親と子を入れ替える
			if (heap[n] < heap[parent]) {
				swap(n, parent);
				n = parent;
			}
			else {
				break;
			}
		}
	}
	//ヒープにノードIDを加える
	void add(ID ndid) {
		//ヒープにidを格納
		heap[n] = ndid;
		//min-heapPropertyに反する場合親と子を入れ替える
		exchange(n);
		//番号を一つ増やす
		n++;
	}

	//仮費用が更新されるごとにルートにノードを挿入する
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