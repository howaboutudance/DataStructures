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
		// SJS: again, this should be const
		// but since use the iterator which alters
		// the elements list in bst it isn't
		bool operator==(set & rhs) {
			return subset(rhs) && subset(*this);
		}
		bool isEmpty() const{
			return b.isEmpty();
		}
		int size() const{
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
		// SJS: subset ought to be const, but since
		// the iterator for bst is not const
		// and this implementation uses the iterator
		// it can't be const either.
		// Note this does subset in the opposite direction
		// to what I would expect. Ie the arg is subset of the
		// receiver? vs the receiver subset of the arg.
		// but that's ok.
		bool subset(set & s) {
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
        set & set_union(set & s) {
            auto it = s.begin();
            auto itEnd = s.end();
            while (it != itEnd) {
                b.insert(*it++);
            }
            return *this;
        }
        set * set_inter(set & s){
            auto newSet = new set<Obj>{};
            auto it = s.begin();
            auto itEnd = s.end();
            while(it != itEnd){
                if(this->contains(*it)){
                    newSet->b.insert(*it);
                }
                it++;
            }
            return newSet;
        }
		// SJS no const again for same reason as above.
		typename bst<Obj>::const_iterator begin() {
			return b.begin();
		}
		typename bst<Obj>::const_iterator end() const{
			return b.end();
		}

	private:
		bst<Obj> b;
};

#endif
