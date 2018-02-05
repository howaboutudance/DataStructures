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
				// SJS added typename. I was close! Didn't know I needed that.
				typename list<Obj>::const_iterator it;

			public:
				// SJS added elements.clear() and fixed the constructor. I understand the changes made.
				// removed const from arg
				// since i moved elements to the bst
				// instead of the iterator
				// so the const_iterator changes
				// the underlying bst
				const_iterator(bst &t){
					
					t.elements->clear();
					t.elements = t.inOrder();
					it = t.elements->begin();
				}
				// SJS added.
				// instead of passing in nullptr
				// pass in the actual elements list
				const_iterator(list<Obj> *l){
					it = l->end();
				}
				const Obj & operator*() const{
					return *it;
				}
				// SJS: the operator++(int) is the post
				// increment. the operator++() is the pre
				// increment
				// preincrement will increment the
				// pointer first and then return 
				// post increment will have to
				// save the old pointer, then do the
				// increment, then return the saved pointer
				// In this case, since we have a box
				// that holds the iterator, it's a little
				// awkward to distinguish, since the actual
				// pointer belongs to the list! not the
				// tree. This really only makes a difference
				// when you do *it++ vs *(++it). Ie
				// in *it++ you want to get the value
				// pointed to by *it before the inc.
				// while in *(++it) you want the value
				// pointed to by the iterator after you
				// did the increment. In either case,
				// the result is the value pointed to by
				// the iterator.
				// I'm changing the type here from
				// returning a reference to returning
				// const_iterator itself since we need
				// a copy of the iterator to keep track
				// of the old iterator.
				
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
				// SJS added.
				bool operator!=(const const_iterator &rhs){
					return it != rhs.it;
				}
		};

		bst(){
			root = NULL;
		}
		// SJS removed the const since the iterator now
		// changes the bst to refer to the elements list
		const_iterator begin() {
			// SJS changed.
			return const_iterator(*this);
		}
		// SJS removed const see above comment on begin()
		// we pass the elements list to the iterator
		// so that both begin and end refer to the same
		// elements list.
		const_iterator end() {
			// SJS changed.
			return const_iterator(elements);
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
		list<Obj> * inOrder() {
			elements->clear();
			return inOrder(root);
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
		// SJS added elements to bst instead of to the iterator
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
		list<Obj> * inOrder(bstNode *n) {
			if(n != NULL){
				inOrder(n->left);
				elements->push_back(n->data);
				inOrder(n->right);
			}
			return elements;
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
