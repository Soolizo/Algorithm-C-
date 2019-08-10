#include <iostream>
using namespace std;



void swap(int& i, int& j) {
	int m = i;
	i = j;
	j = m;
}

void max2(int* A, int lo, int hi, int& m1, int& m2) {
	int mi = (lo + hi) / 2;
	int LM1, LM2, RM1, RM2;


	if (lo + 2 == hi) { 
		m1 =lo;
		m2 = hi - 1;
		if (A[lo] < A[hi - 1])
			swap(m1, m2);
		return; 
	}
	if (lo + 1 == hi) { m1 = lo; m2 = lo + 1; return; };

	max2(A, lo, mi, LM1, LM2);
	max2(A, mi , hi, RM1, RM2);

	if (A[LM1] > A[RM1])
	{
		m1 = LM1;
		m2 = A[LM2]> A[RM1] ? LM2 : RM1;
	}
	else
	{
		m1 = RM1;
		m2 = A[RM2] > A[LM1] ? RM2 : LM1;
	}
	
}

int main()
{
	int A[] = { 87,9,98,79,564,1,8,97,8,61,6,1,5,789,45 };
	int lo, hi;
	int x1, x2;
	
	cin >> lo >> hi;
	if (hi - lo == 0) {
		cout << A[lo];
		return 0;
	}
	max2(A, lo, hi, x1, x2);
		cout << "MAX1:A["<<x1<<"]="<<A[x1]<<", MAX2:A["<<x2<<"]="<<A[x2];
		return 0;
}