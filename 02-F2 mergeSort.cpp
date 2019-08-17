#include <iostream>

using namespace std;

 void swap(int& i, int& j) {
	int m = i;
	i = j;
	j = m;
}

 template<typename T>
 void merge(T* A,int lo, int mi, int hi) {
	 int lb = mi - lo;
	 int lc = hi - mi;
	 T* a = A+lo;
	 T* b = new T [lb];
	 T* c = A + mi;
	 for (int i = 0; i < lb; i++)b[i] = a[i];
	 for (int i = 0, j = 0, k = 0; j<lb;)a[i++]= (lc<=k || (b[j] <= c[k])) ? b[j++] : c[k++];
	 delete[] b;
	return; 
 }

template <typename T>
void mergeSort(T * A, int lo, int hi){
	if ((hi - lo) < 2) return;
	int mi = (lo + hi) >>1;
	mergeSort(A, lo, mi);
	mergeSort(A, mi, hi);
	merge(A,lo, mi, hi);
}

int main() {
	int A[] = { 2,5,4,7,8,9,8,5,4,5,6,5,5,4,66,2 };
	mergeSort(A, 0, 16);
	for (int j = 0; j < 16; j++)
		cout << A[j] << ", ";
	return 0;
}