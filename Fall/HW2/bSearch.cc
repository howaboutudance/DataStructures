#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
int rec(int comp, vector<int> &v){
	int l = 0, r = v.size() - 1;
	while(l <= r){
		int m = (l + r) / 2;

		if(v[m] < comp)
			l = m + 1;
		else if(v[m] > comp)
			r = m - 1;
		else
			return m;
	}
	return -1;
}

int main(){
	vector<int> a;
	for(int i = 0; i < 1000; i++)
		a.push_back(i);
	vector<int> b;
	b.push_back(2);
	b.push_back(4);

	time_t t;
	t = clock();
	cout << rec(3, b) << endl;
	t = clock() - t;
	cout << ((float)t)/CLOCKS_PER_SEC << " sec" << endl;
	return 0;
}
