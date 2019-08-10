#include <iostream>
using namespace std;



void swap(int& i, int& j) {
	int m = i;
	i = j;
	j = m;
}

void reverse(int* A, int lo, int hi) {
	if (lo < hi) {
		swap(A[lo], A[hi]);
		reverse(A, lo + 1, hi - 1);
	}
	else return;
}

int main()
{
	int A[] = { 1,2,3,4,5,6,7,8,9 };
	int lo, hi;

	cin >> lo >> hi;
	reverse(A, lo, hi);
	for (int j = 0; j <= 8; j++)
		cout << A[j]<<" ";
		return 0;
}