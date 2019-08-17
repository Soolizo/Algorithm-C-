#include <iostream>

using namespace std;


template <typename T>
int biSearch(T* A, T const& e, int lo, int hi) {
	for (; lo < hi;) {
		int mi = (hi + lo) >> 1;
		(e < A[mi]) ? hi = mi : lo = mi + 1;
	}
return --lo;
}


int main() {
	int A[] = { 1,2,3,3,3,3,3,3,4,5,6,7,8 };
	int e;
	cin >> e;
	cout << biSearch(A, e, 0, 13);
	return 0;
}