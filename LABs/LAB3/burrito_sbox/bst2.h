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
		class const_iterator{
			protected:
				list<Obj> elements;
				// SJS added typename. I was close! Didn't know I needed that.
				typename list<Obj>::const_iterator it;

			public:
				// SJS added elements.clear() and fixed the constructor. I understand the changes made.
				const_iterator(const bst &t){
					
					elements.clear();
					elements = t.inOrder(); it = elements.begin();
				}
				// SJS added.
				const_iterator(bst *t){
					it = elements.end();
				}
				const Obj & operator*() const{
					return *it;
				}
				const_iterator & operator++(int) {
					it++;
					return *this;
				}
				bool operator==(const const_iterator & rhs) const{
					return it == rhs.it;
				}
				// SJS added.
				bool operator!=(const const_iterator &rhs){
					return it != rhs.it;
				}
		};

		bst(){
			root = NULL;
		}
		const_iterator begin() const{
			// SJS changed.
			return const_iterator(*this);
		}
		const_iterator end() const{
			// SJS changed.
			return const_iterator(nullptr);
		}
		bool isEmpty(){
			return root == NULL;
		}
		void insert(const Obj &x){
			insert(x, root);
		}
		bool search(const Obj &x){
			if(isEmpty()){
				return false;
			} else 
				return search(x, root);
		}
		bstNode * findMin(){
			assert (!isEmpty());
			return findMin(root);
		}
		bstNode * findMax(){
			assert (!isEmpty());
		return findMax(root);
		}
		list<Obj> inOrder() const{
			list<Obj> lst;
			return inOrder(root, lst);
		}
		void remove(const Obj &x){
			remove(x, root);
		}
		int height(){
			return height(root);
		}
		int numNodes(){
			return numNodes(root);
		}
		int leaves(){
			return leaves(root);
		}
		int fullNodes(){
			return fullNodes(root);
		}
	private:
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
		list<Obj> inOrder(bstNode *n, list<Obj> &lst) const{
			if(n != NULL){
				inOrder(n->left, lst);
				lst.push_back(n->data);
				inOrder(n->right, lst);
			}
			return lst;
		}
		bstNode * findMin(bstNode *n){
			if(n->left == NULL){
				return n;
			} else {
				return findMin(n->left);
			}
		}
		bstNode * findMax(bstNode *n){
			if(n->right == NULL){
				return n;
			} else {
				return findMax(n->right);
			}
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
		int height(bstNode *n){
			if(n == NULL)
				return 0;
			return 1 + max(height(n->left), height(n->right));
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
		int leaves(bstNode *n){
			if(n == NULL)
				return 0;
			if(n->left == NULL && n->right == NULL)
				return 1;
			else
				return leaves(n->left) + leaves(n->right);
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
