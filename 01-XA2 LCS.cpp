#include <iostream>
#include <string>

using namespace std;

int LCS(string a, string b);
//int LCS_recursion(string a, string b);
inline int max(int a, int b) { 
	if (a > b) return a; 
	else return b; 
}

int main()
{
	string a = "didactical";
	string b = "advantage";
	cout << LCS(a,b) << endl;
	return 0;
}

int LCS(string a, string b) {
	int la = a.length();
	int lb = b.length();
	int j, i;
	int** p;
	p = new int* [lb+1];
	for (j = 0; j < lb+1; j++) {
		p[j] = new int[la+1];
	}//lb row, la column

	
	for (j = 0; j < la+1; j++)  p[0][j] = 0;
	for (j = 1; j < lb+1; j++)  p[j][0] = 0;

	for (i = 1; i < lb + 1; i++) {
		for (j = 1; j < la + 1; j++) {
			if (a[j-1] == b[i-1]) p[i][j] = 1 + p[i - 1][j - 1];
			else p[i][j] = max(p[i][j - 1], p[i - 1][j]);
		}
	}
	return p[lb][la];
}

/*
int LCS_recursion(string a, string b) {
	return 0;
}*/