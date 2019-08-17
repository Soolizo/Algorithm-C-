#include <iostream>

using namespace std;

 void swap(int& i, int& j) {
	int m = i;
	i = j;
	j = m;
}

template <typename T>
void bubSort(T * A, int lo, int hi){
	for (int last = --hi; hi >lo; hi=last)
		for (int j = last=lo; j < hi; j++)
			if (A[j + 1] < A[j]) { swap(A[j + 1], A[j]); last = j; }//(last,hi] is sorted
return;
}

int main() {
	int A[] = { 1,3,6,4,7,2,5 };
	bubSort(A, 0, 7);
	for(int j=0;j<7;j++)
	cout << A[j]<<", ";
	return 0;
}