#include <iostream>

using namespace std;


template <typename T>
T biSearch(T * A, T e,int lo, int hi) {
	if (hi - lo < 1) return --lo;
	int mi = (hi + lo) >> 1;
	if (e < A[mi]) biSearch(A, e, lo, mi);
	else biSearch(A, e, mi+1, hi);//Be careful about this "+1"!
}

int main() {
	int A[] = { 1,2,3,3,3,3,3,3,4,5,6,7,8 };
	int e;
	cin >> e;
	cout << biSearch(A, e, 0, 13);
	return 0;
}