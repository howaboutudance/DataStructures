#include <iostream>
#include <string>
using namespace std;

/**
 * A class for simulating a memory cell.
 * operator<
 * operator<=
 * operator==
 * operator!=
 * operator<< using friend
 * operator<< using a member print function
 */
template <typename Object>
class MemoryCell{
	public:
		explicit MemoryCell(const Object & initialValue = Object{}){
			storedValue = new Object{initialValue};
		}
		~MemoryCell(){
			delete storedValue;
		}
		MemoryCell(const MemoryCell & rhs){
			storedValue = new Object{*rhs.storedValue};
		}
		MemoryCell & operator=(const MemoryCell & rhs){
			if(this != & rhs)
				*storedValue = *rhs.storedValue;
			return *this;
		}
		bool operator==(const MemoryCell & rhs) const{
			return *storedValue == *rhs.storedValue;
		}
		bool operator!=(const MemoryCell & rhs) const{
			return !(*storedValue == *rhs.storedValue);
		}
		bool operator<(const MemoryCell & rhs) const{
			return *storedValue < *rhs.storedValue;
		}
		bool operator<=(const MemoryCell & rhs) const{
			return *storedValue <= *rhs.storedValue;
		}
		const Object & read() const{
			return *storedValue;
		}
		void write(const Object & x){
			*storedValue = x;
		}
		friend ostream & operator<<(ostream & os, const MemoryCell & cell){
			os << *cell.storedValue << endl;
			return os;
		}

	private:
		Object *storedValue;
};

int main(){
	MemoryCell<int> m1;
	MemoryCell<int> m2;
	m1.write(4);
	m2.write(6);
	cout << "m1: " << m1.read() << " , m2: " << m2.read() << endl;
	m1 = m2;
	cout << "m1 = m2" << endl;
	cout << "m1: " << m1.read() << " , m2: " << m2.read() << endl;

	if(m1 == m2){
		cout << "m1 == m2" << endl;
	}
	m2.write(3);
	cout << "I made them different again. m1: " << m1.read() << " m2: " << m2.read() << endl;
	
	if(m1 != m2){
		cout << "m1 != m2" << endl;
	}

	if(m2 < m1){
		cout << "m2 < m1" << endl;
	}
	if(m1 < m2){
		cout << "m1 < m2" << endl;
	}
	cout << m1;
	return 0;
}
