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
    void insert (string s){
        /*stack<ExprNode> expStack;
        for(auto it = s.begin(); it < s.end(); it++){
            if(((int)*it >= 40 && (int)*it <= 47) || (int)*it == 61 || (int)*it == 94){
                ExprNode right = expStack.pop();
                ExprNode left = expStack.pop();
                ExprNode tmp = new ExprNode(*it,left, right);
                expStack.push(tmp);
            } else {
                ExprNode *tmp;
                *tmp->data = *it;
                expStack.push(tmp);
            }
        }*/

    }
};
#endif
