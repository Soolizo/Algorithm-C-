#include <iostream>
#include <stack>
using namespace std;


/////////////////////////////////////////////////////////////
//Use another stack to simulate stack shuffling.
bool stack_permutation(stack<int> A, int* test) {
	stack<int> B;
	stack<int> S;
	int i, num;
	
	for (i = 0, num = test[0];!(A.empty()) ; ) {
		S.push(A.top());
		A.pop();
		while (!(S.empty())&& num == S.top()){
			B.push(S.top());
			S.pop();
			num=i<3 ? test[++i]:test[i];
		}
	}
	if (S.empty()) return true;
	else return false;
}
///////////////////////////////////////////////////////////


int main() {
	stack<int> A;
	for (int i = 4; i >0; i--)
		A.push(i);//<1,2,3,4]
	int test[][4] = {// Test case, the top of the stack is on the right. 		
	1,2,3,4,		//The total number of (1 2 3 4)'s full permutation is 24, and there is only 14 stack permutation.
	1,2,4,3,
	1,3,2,4,
	1,3,4,2,
	1,4,2,3,
	1,4,3,2,

	2,1,3,4,
	2,1,4,3,
	2,3,1,4,
	2,3,4,1,
	2,4,1,3,
	2,4,3,1,

	3,1,4,2,
	3,1,2,4,
	3,2,1,4,
	3,2,4,1,
	3,4,1,2,
	3,4,2,1,

	4,3,2,1,
	4,3,1,2,
	4,2,1,3,
	4,2,3,1,
	4,1,3,2,
	4,1,2,3
	};
	for(int i=0;i<24;i++)
		cout << stack_permutation(A, test[i]) << "\n";
	return 0;

}
