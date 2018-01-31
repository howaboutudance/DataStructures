/* Beautifully Scrumptious Tree
 * Data Structures
 * LAB 3'
 * Michelle Bergin
 */

#ifndef BST_H
#define BST_H

#include <iostream>
#include <assert.h>
#include <list>
#include <algorithm>
using namespace std;

template <typename Obj>
class bst{
	private:
		struct bstNode{
			Obj data;
			bstNode *left;
			bstNode *right;
			bstNode(const Obj &d, bstNode *l, bstNode *r)
			         : data(d), left(l), right(r) { }
		};
		bstNode *root;

	public:
		bst(){
			root = NULL;
		}
		bool isEmpty(){
			return root == NULL;
		}
		void insert(const Obj &x){
			insert(x, root);
		}
		void insert(const Obj &x, bstNode *&n){
			if(n == NULL){
				n = new bstNode(x, NULL, NULL);
			} else if(x > n->data){
				insert(x, n->right);
			} else if(x < n->data){
				insert(x, n->left);
			} else
				;
		}
		bool search(const Obj &x){
			if(isEmpty()){
				return false;
			} else 
				return search(x, root);
		}
		bool search(const Obj &x, bstNode *n){
			if(x == n->data){
				return true;
			} 
			if(x < n->data && n->left != NULL){
				return search(x, n->left);
			} else if(x > n->data && n->right != NULL){
				return search(x, n->right);
			} else {
				return false;
			}
		}
		bstNode * findMin(){
			assert (!isEmpty());
			return findMin(root);
		}
		bstNode * findMin(bstNode *n){
			if(n->left == NULL){
				return n;
			} else {
				return findMin(n->left);
			}
		}
		bstNode * findMax(){
			assert (!isEmpty());
			return findMax(root);
		}
		bstNode * findMax(bstNode *n){
			if(n->right == NULL){
				return n;
			} else {
				return findMax(n->right);
			}
		}
		list<Obj> inOrder(){
			list<Obj> lst;
			return inOrder(root, lst);
		}
		list<Obj> inOrder(bstNode *n, list<Obj> &lst){
			if(n != NULL){
				inOrder(n->left, lst);
				lst.push_back(n->data);
				inOrder(n->right, lst);
			}
			return lst;
		}
		void remove(const Obj &x){
			remove(x, root);
		}
		void remove(const Obj &x, bstNode *&n){
			if(n == NULL)
				return;
			if(x < n->data){
				remove(x, n->left);
			} else if(x > n->data){
				remove(x, n->right);
			} else if(n->left != NULL && n->right != NULL){
				n->data = findMin(n->right)->data;
				remove(n->data, n->right);
			} else {
				n = (n->left != NULL) ? n->left : n->right;
				return;
			}
		}
		int height(){
			return height(root);
		}
		int height(bstNode *n){
			if(n == NULL)
				return 0;
			return 1 + max(height(n->left), height(n->right));
		}
		const Obj * iterator(){
			list<Obj> l;
			l = inOrder();

		}

		//============================//
		int numNodes(){
			return numNodes(root);
		}
		int numNodes(bstNode *n){
			int count = 1;
			if(n->left != NULL){
				count += numNodes(n->left);
			}
			if(n->right != NULL){
				count += numNodes(n->right);
			}
			return count;
		}
		int leaves(){
			return leaves(root);
		}
		int leaves(bstNode *n){
			if(n == NULL)
				return 0;
			if(n->left == NULL && n->right == NULL)
				return 1;
			else
				return leaves(n->left) + leaves(n->right);
		}
		int fullNodes(){
			return fullNodes(root);
		}
		int fullNodes(bstNode *n){
			if(n == NULL)
				return 0;
			if(n->left != NULL && n->right != NULL)
				return 1;
			return fullNodes(n->left) + fullNodes(n->right);
		}
};

#endif
