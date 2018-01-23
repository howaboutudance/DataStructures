#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main(){
	vector<int> v;

	for(int i = 0; i < 100; i++){
		v.push_back(rand() % 100 + 1);
	}

	int a, b, c, d = 0;

	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v.size(); j++){
			if(v[i] <= v[j]){
				a += v[j] + v[i];
				b += v[j] - v[i];
				c += v[j] * v[i];
				d += v[j] / v[i];
			}
		}
	}
	cout << "a) Max sum " << a << endl;
	cout << "b) Max minus " << b << endl;
	cout << "c) Max times " << c << endl;
	cout << "d) Max division " << d << endl;

	return 0;
}
