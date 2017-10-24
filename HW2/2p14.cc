#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int main(){
	vector<int> a;
	a.push_back(2);
	a.push_back(1);
	a.push_back(0);
	a.push_back(8);
	a.push_back(4);
	
	int x = 3;
	int poly = 0;
	
	clock_t t;
	t = clock();

	for(int i = a.size(); i >= 0; i--){
		poly = x * poly + a[i];
	}

	t = clock() -t;

	cout << ((float)t)/CLOCKS_PER_SEC << " sec" << endl;

	cout << poly << endl;

	return 0;
}
