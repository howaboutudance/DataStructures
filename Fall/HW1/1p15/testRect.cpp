/**
 * write a main that creates an array of Rectangle and finds the largest 
 * Rectangle first on the basis of area and then on the basis of perimeter.
 */

#include <iostream>
#include <vector>
using namespace std;

template <typename Object, typename Comparator>
const Object & findMax(const vector<Object> & arr, Comparator cmp){
	int maxIndex = 0;
	for(int i = 1; i < arr.size(); i++)
		if(cmp.isLessThan(arr[maxIndex], arr[i]))
			maxIndex = i;
	return arr[maxIndex];
}
class Rectangle{
	public:
		explicit Rectangle(int iV1 = 0, int iV2 = 0){
			width = new int{iV1};
			height = new int{iV2};
		}
		~Rectangle(){
			delete width;
			delete height;
		}
		Rectangle(const Rectangle & rhs){
			width = new int{*rhs.width};
			height = new int{*rhs.height};
		}
		Rectangle & operator=(const Rectangle & rhs){
			if(this != & rhs)
				*width = *rhs.width;
				*height = *rhs.height;
			return *this;
		}
		bool operator==(const Rectangle & rhs){
			return ((this->area() == rhs.area())&&(this->perimeter() == rhs.perimeter()));
		}
		int getHeight() const{
			return *height;
		}
		void writeWidth(int w){
			*width = w;
		}
		void writeHeight(int h){
			*height = h;
		}
		int area() const{
			return (*width) * (*height);
		}
		int perimeter() const{
			return (*width * 2) + (*height * 2);
		}
	private:
		int *width;
		int *height;
};
class peri{
	public:
		bool isLessThan(const Rectangle &lhs, const Rectangle &rhs) const{
			return lhs.perimeter() < rhs.perimeter();
		}
};
class areaMax{
	public:
		bool isLessThan(const Rectangle &lhs, const Rectangle &rhs) const{
			return lhs.area() < rhs.area();
		}
};

int main(){
	Rectangle rect4(4,6);
	Rectangle rect5(884,22);
	Rectangle rect6(1,2);
	vector<Rectangle> arr(3);
	arr.push_back(rect4);
	arr.push_back(rect5);
	arr.push_back(rect6);
	Rectangle rect1(3,4);
	Rectangle rect2(3,4);
	Rectangle rect3(4,5);
	if(rect1 == rect2)
		cout << "rect1 == rect2" << endl;
	if(rect1 == rect3)
		cout << "I should not see this" << endl;
	cout << findMax(arr, peri{}).perimeter() << " is the biggest perimeter" << endl;
	cout << findMax(arr, areaMax{}).area() << " is the biggest area" << endl;

	return 0;
}
