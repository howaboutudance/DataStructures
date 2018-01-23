#ifndef Btree_H
#define Btree_H
#include <iostream>
#include <set>

using namespace std;

template <typename Object>

class Btree{
    private:
        struct node{
            Object data;
            struct node *left;
            struct node *right;
            node(Object ele, node *lt, node *rt)
              : data{ele},left{lt}, right{rt} {}
        };
		node *root;
		void add(Object &x, node *n){
            if(n == nullptr){
                n = new node(x, nullptr, nullptr);
            }
            else if(x < n->data)
                add(x, n->left);
            else if(x > n->data)
                add(x, n->right);
		}
	public:
		Btree() : root{nullptr}{
		}

		~Btree(){
			//someday
		}

		void add(Object &x){
			add(x, root);
		}
};
#endif
