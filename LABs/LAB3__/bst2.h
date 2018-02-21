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
				typename list<Obj>::const_iterator it;

			public:
			// SJS no const on the arg since
			// it alters the elements list in the tree
				const_iterator(bst &t) {
					
					t.elements->clear();
					t.elements = t.inOrder();
					it = t.elements->begin();
				}
				const_iterator(const list<Obj> *l) {
					it = l->end();
				}
				const Obj & operator*() const{
					return *it;
				}
				
				const_iterator operator++(int) { // post
					const_iterator old = *this;
					it++;
					return old;
				}
				const_iterator operator++() {	// pre
					it++;
					return *this;
				}

				bool operator==(const const_iterator & rhs) const{
					return it == rhs.it;
				}
				bool operator!=(const const_iterator &rhs)const {
					return it != rhs.it;
				}
		};

		bst(){
			root = NULL;
		}
		// SJS no const on the begin iterator since
		// it alters the elements list in the tree
		const_iterator begin() {
			return const_iterator(*this);
		}
		const_iterator end() const {
			return const_iterator(elements);
		}
		bool isEmpty() const{
			return root == NULL;
		}
		void insert(const Obj &x){
			insert(x, root);
		}
		bool search(const Obj &x) const{
			if(isEmpty()){
				return false;
			} else 
				return search(x, root);
		}
		Obj & findMin() const{
			assert (!isEmpty());
			return findMin(root);
		}
		Obj & findMax() const{
			assert (!isEmpty());
			return findMax(root);
		}
		list<Obj> * inOrder() const{
			elements->clear();
			return inOrder(root);
		}
		void remove(const Obj &x){
			remove(x, root);
		}
		int height() const{
			return height(root);
		}
		int numNodes() const{
			return numNodes(root);
		}
		int leaves() const{
			return leaves(root);
		}
		int fullNodes() const{
			return fullNodes(root);
		}
		int size() const{
			return inOrder()->size();
		}
	private:
		list<Obj> * elements = new list<Obj>{};	//elements list for inorder traverse
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
		bool search(const Obj &x, bstNode *n) const{
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
		list<Obj> * inOrder(bstNode *n) const{
			if(n != NULL){
				inOrder(n->left);
				elements->push_back(n->data);
				inOrder(n->right);
			}
			return elements;
		}
		Obj & findMin(bstNode *n) const{
			if(n->left != NULL)
				return findMin(n->left);
			// SJS need the return for both the if and the else
			// SJS otherwise you return to the point of the
			// SJS recursion and return n->data from the point
			// SJS of recursion!
			return n->data;
		}
		Obj & findMax(bstNode *n) const{
			if(n->right != NULL){
			// SJS same comment on the return findMax recusion
				return findMax(n->right);
			}
			return n->data;
		}
		void remove(const Obj &x, bstNode *&n){
			if(n == NULL)
				return;
			if(x < n->data){
				remove(x, n->left);
			} else if(x > n->data){
				remove(x, n->right);
			} else if(n->left != NULL && n->right != NULL){
				n->data = findMin(n->right);
				remove(n->data, n->right);
			} else {
				n = (n->left != NULL) ? n->left : n->right;
				return;
			}
		}
		int height(bstNode *n) const{
			if(n == NULL)
				return 0;
			return 1 + max(height(n->left), height(n->right));
		}
		int numNodes(bstNode *n) const{
			int count = 1;
			if(n->left != NULL){
				count += numNodes(n->left);
			}
			if(n->right != NULL){
				count += numNodes(n->right);
			}
			return count;
		}
		int leaves(bstNode *n) const {
			if(n == NULL)
				return 0;
			if(n->left == NULL && n->right == NULL)
				return 1;
			else
				return leaves(n->left) + leaves(n->right);
		}
		int fullNodes(bstNode *n)const {
			if(n == NULL)
				return 0;
			if(n->left != NULL && n->right != NULL)
				return 1;
			return fullNodes(n->left) + fullNodes(n->right);
		}
};

#endif
