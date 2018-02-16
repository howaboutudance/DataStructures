/* Spectacularly Energizing Tyrannosaurus's
 * Data Structures
 * LAB 3'
 * Michelle Bergin
 */

#ifndef SET_H
#define SET_H

#include <iostream>
#include "bst2.h"
#include <list>

using namespace std;

template <typename Obj>
class set{
	public:
		set() {}
		~set(){
		}
		bool operator==(set & rhs){
			return subset(rhs) && subset(*this);
		}
		bool isEmpty(){
			return b.isEmpty();
		}
		int size(){
			return b.size();
		}
		void insert(const Obj &x){
			b.insert(x);
		}
		bool contains(const Obj &x) const{
			return b.search(x);
		}
		void remove(const Obj &x){
			b.remove(x);
		}
		//Set set_union(Set & vals)
		//Set set_inter(Set & vals)
		bool subset(set & s) const{
			auto it = s.begin();
			auto it_end = s.end();
			while(it != it_end){
				if(!this->contains(*it)){
					return false;
				}
				it++;
			}
			return true;
		}
		typename bst<Obj>::const_iterator begin(){
			return b.begin();
		}
		typename bst<Obj>::const_iterator end(){
			return b.end();
		}

	private:
		bst<Obj> b;
};

#endif
