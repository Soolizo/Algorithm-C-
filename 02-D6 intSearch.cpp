#include <iostream>

using namespace std;


template <typename T>
int intSearch(T* A, T const& e, int lo, int hi) {
	for (; lo < hi;) {
		int mi = (((e - A[lo]) / (A[hi] - A[lo])) * (hi - lo)) + lo;
		(e < A[mi]) ? hi = mi : lo = mi + 1;
	}
	return --lo;
}

int main() {
	int A[] = { 5,10,12,14,19,23,29,36,39,41,44,51,54,59,72,79,82,86,92 };
	int e;
	cin >> e;
	cout << intSearch(A, e, 0, 18);
	return 0;
}