#ifndef SLIST_H
#define SLIST_H

#include <algorithm>
using namespace std;

template <typename Object>
class SList{
	private:
		struct Node{
			Object data;
			Node *next;

			Node(const Object &d = Object{}, Node *n = nullptr)
				: data{d}, next{n} {}

			Node(Object &&d, Node *n = nullptr)
				: data{std::move(d)}, next{n} {}
		};

	public:
		class const_iterator{
			public:
				const_iterator() : current{nullptr}
					{}
				const Object & operator*() const{
					return retrieve();
				}
				const_iterator & operator++(){
					current = current->next;
					return *this;
				}
				const_iterator operator++(int){
					const_iterator old = *this;
					++(*this);
					return old;
				}
				bool operator==(const const_iterator &rhs) const{
					return current == rhs.current;
				}
				bool operator!=(const const_iterator &rhs) const{
					return !(*this == rhs);
				}

			protected:
				Node *current;

				Object & retrieve() const{
					return current->data;
				}
				const_iterator(Node *p) : current{p}
					{}

				friend class SList<Object>;
			};

			class iterator : public const_iterator{
			
				public:
					iterator()
						{}
					Object & operator*(){
						return const_iterator::retrieve();
					}
					const Object & operator*() const{
						return const_iterator::operator*();
					}
					iterator & operator++(){
						this->current = this->current->next;
						return *this;
					}
					iterator operator++(int){
						iterator old = *this;
						++(*this);
						return old;
					}
			
				protected:
					iterator(Node *p) : const_iterator{p}
						{}

					friend class SList<Object>;
			};

		public:
			SList()
				{init();}
			~SList(){
				clear();
				delete head;
			}
			SList(const SList & rhs){
				init();
				for(auto & x : rhs)
					push_back(x);
			}
			SList & operator=(const SList & rhs){
				SList copy = rhs;
				std::swap(*this, copy);
				return *this;
			}
			SList(SList && rhs)
				: head{rhs.head}
			{
				rhs.head = nullptr;
			}
			SList & operator=(SList && rhs){
				std::swap(head, rhs.head);
				return *this;
			}
			iterator begin(){
				return iterator(head->next);
			}
			const_iterator begin() const{
				return const_iterator(head->next);
			}
			
			Object & front(){
				return *begin();
			}
			const Object & front() const{
				return *begin();
			}
			void push_front(const Object &x){
				insert(begin(), x);
			}
			void push_front(Object && x){
				insert(begin(), std::move(x));
			}
			void pop_front(){
				erase(begin());
			}
			
		private:
			Node *head;

			void init(){
				head = new Node;
				head->next = nullptr;
			}
};

#endif
