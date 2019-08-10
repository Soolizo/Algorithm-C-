#include <iostream>
#include <algorithm>
using namespace std;



void swap(int& i, int& j) {
	int m = i;
	i = j;
	j = m;
}

int gsf(int* A, int lo, int hi, int& m1, int& m2) {
	int gs = A[lo], s = 0, i = hi, j = hi;
	while (i-- > lo) {
		s += A[i];
		if (gs < s) gs = s;
		if (s < 0) { s = 0; j--; }
	}
	return gs;
}

int gs(int* A, int lo, int hi, int& m1, int& m2) {
	if (hi - lo < 2) { m1 = lo; m2 = hi; return A[lo]; }
	int mi = (lo + hi) / 2;

	int gsl=A[mi-1], gsr=A[mi];
	int sl = 0, sr = 0;
	int i;

	for (i = mi - 1; i >= lo; i--) if (gsl < (sl += A[i])) { gsl = sl; m1 = i; }
	

	for (i = mi; i < hi; i++) if (gsr < (sr += A[i])) { gsr = sr; m2 = i+1; }
	

	return max(gsl + gsr, max(gs(A,lo,mi,m1 ,m2),gs(A,mi,hi,m1,m2)));
	
}

int main()
{
	int A[] = { 100,-1,99 ,-3,-4,-5,101,-6,-7};
	int lo, hi;
	int x1, x2;
	int max;
	cin >> lo >> hi;
	max = gsf(A, lo, hi, x1, x2);
	cout << max;// << "   [" << x1 << "," << x2 << ")";
		return 0;
}