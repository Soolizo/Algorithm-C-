#include <iostream>

using namespace std;


template <typename T>
T intSearch(T * A, T e,int lo, int hi) {
	if (hi - lo < 1) return --lo;
	int mi = lo+((hi - lo) * (e - A[lo]) / (A[hi] - A[lo]));
	if (e < A[mi]) intSearch(A, e, lo, mi);
	else intSearch(A, e, mi+1, hi);//Be careful about this "+1"!
}

int main() {
	int A[] = { 5,10,12,14,19,23,29,36,39,41,44,51,54,59,72,79,82,86,92 };
	int e;
	cin >> e;
	cout << intSearch(A, e, 0, 18);
	return 0;
}