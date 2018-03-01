#ifndef EXTREE_H
#define EXTREE_H
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class ExTree {

private:
	struct node {
		int variable;
		char oper;
		bool isOperator;
	};

	struct ExprNode {
		node data;
		ExprNode * left;
		ExprNode * right;
		
	
		ExprNode(int val) {
			data.variable = val;
			data.isOperator = false;
			left = right = NULL;
		}

		ExprNode(char val, ExprNode * l, ExprNode * r) {
			data.oper = val;
			data.isOperator = true;
			left = l;
			right = r;
		}
	};

	int eval(ExprNode *exp) {
		if (exp->data.isOperator){
			return apply(exp->data.oper, eval(exp->left), eval(exp->right));
		} else {
			 return exp->data.variable;
		}
	}

	void prnt(ExprNode *r){
		if(r != nullptr){
			if(r->data.isOperator){
				cout << r->data.oper;
			} else {
				cout << r->data.variable;
			}
			prnt(r->left); prnt(r->right);
			if(r->data.isOperator){
				cout << r->data.oper;
			} else {
				cout << r->data.variable;
			}
		}	
	}

	int apply(char oper, int a, int b){
		switch (oper) {
			case '+': 
				return a + b;
			case '-':
				return a - b;
			case '*':
				return a * b;
			case '/':
				return a / b;
		}
	}

	ExprNode *root;

public:
	ExTree () {
		root = NULL;
	}

	ExTree (int val) {
		root = new ExprNode(val);
	}

	ExTree (char val, ExTree & left, ExTree & right) {
		root = new ExprNode(val, left.root, right.root);
	}
	int eval(){
		eval(root);
	}
	void prnt(){
		prnt(root);
		cout << endl;
	}
};
#endif
