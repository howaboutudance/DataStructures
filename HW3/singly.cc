#ifndef LIST_H
#define LIST_H

using namespace std;

template <typename Object>
class Singly{
	private:
		struct Node{
			Object data;
			Node *next;
			Node(Object && d, Node *n = nullptr)
				: data{d}, next{n} {}
		}
	public:
		explicit Singly(Object iHead = nullptr, 
	private:
		Node *head;

		void
};
