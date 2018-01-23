#include <iostream>
using namespace std;

class IntCell{
	public: 
		explicit IntCell(int initialValue = 0){
			storedValue = new int{initialValue};
		}
		~IntCell(){
			delete storedValue;
		}
		IntCell(const IntCell & rhs){
			storedValue = new int{*rhs.storedValue};
		}
		IntCell & operator=(const IntCell & rhs){
			if(this != & rhs)
				*storedValue = *rhs.storedValue;
			return *this;
		}
		int read() const{
			return *storedValue;
		}
		void write(int x){
			*storedValue = x;
		}
		friend void print(IntCell cell){
			cout << *cell.storedValue << endl;
		}
	private:
		int *storedValue;
};

int main(){
	
	IntCell arrOne[6];
	IntCell *arrPoint[6];

	int size = 6;

	for(int i = 0; i < size; i++){
		arrOne[i].write(i);
	}
	for(int i = 0; i < size; i++){
		arrPoint[i] = &arrOne[i];
	}
	for(int i = 0; i < size; i++){
		cout << arrPoint[i]->read() << endl;
	}
	arrOne[3].write(82828);
	cout << arrPoint[3]->read() << endl;
	arrPoint[2]->write(2843);
	cout << arrOne[2].read() << endl;
	print(arrOne[1]);

	return 0;
}
