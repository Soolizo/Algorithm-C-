#include<iostream>
#include<stack>

using namespace std;

class BinNode {
public:
	int data;
	BinNode* lc;
	BinNode* rc;
	BinNode* parent;
	BinNode(int i) { data = i; lc = NULL; rc = NULL; parent = NULL; }
	BinNode* insertLCwith( BinNode* );
	BinNode* insertRCwith( BinNode* );
	void travPre();
	void travIn();
	void travAfter();
	void travAfter1();
};

BinNode* BinNode::insertLCwith( BinNode* a) {
	this->lc = a;
	a->parent =this;
	return a;
}

BinNode* BinNode::insertRCwith(BinNode* a) {
	this->rc = a;
	a->parent = this;
	return a;
}


void BinNode::travPre() {
	stack<BinNode*> s;
	BinNode* x = this;
	while (true) {
		while (x) {
			cout << x->data << endl;
			s.push(x->rc);
			x = x->lc;
		}
		if (s.empty()) break;
		x = s.top();
		s.pop();
	}
}

void BinNode::travIn() {
	stack<BinNode*> s;
	BinNode* x = this;
	while (true) {
		while (x) {
			s.push(x);
			x = x->lc;
		}
		if (s.empty()) break;
		x = s.top();
		s.pop();
		cout << x->data << endl;
		x = x->rc;
	}
}

void BinNode:: travAfter() {
	BinNode* x = this;
	stack<BinNode*> s1;
	stack<BinNode*> s2;
	s1.push(x);
	while (!s1.empty()) {
		x = s1.top();
		s1.pop();
		if(x->lc) s1.push(x->lc);
		if (x->rc) s1.push(x->rc);
		s2.push(x);
	}
	while (!s2.empty()) {
		x = s2.top(); s2.pop();
		cout << x->data << endl;
	}
}

void BinNode::travAfter1() {
	stack<BinNode*> s;
	BinNode* x = this;
	if (x) s.push(x);
	while (!s.empty()) {
		if(s.top()!=x->parent){
			while (BinNode * t = s.top()) {
				if (t->lc) {
					if (t->rc)
						s.push(t->rc);
					s.push(t->lc);
				}
				else s.push( t->rc);
			}
			s.pop();
		}
		x = s.top();
		s.pop();
		cout << x->data << endl;
	}
}

int main() {
	BinNode a(1);
	BinNode b(2);
	BinNode c(3);
	BinNode d(4);
	BinNode e(5);
	BinNode f(6);
	a.insertLCwith( &b);
	a.insertRCwith( &c);
	b.insertLCwith (&d);
	b.insertRCwith (&e);
	c.insertRCwith (&f);

	cout << "travPre"<<endl;
	a.travPre();

	cout << "travIn" << endl;
	a.travIn();

	cout << "travAfter" << endl;
	a.travAfter();

	cout << "travAfter1" << endl;
	a.travAfter1();

	return 0;
}