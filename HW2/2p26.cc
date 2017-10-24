#include <iostream>
#include <map>
#include <vector>
using namespace std;
int howMany(map<int, int> &m, vector<int> &v){
	int place = 0;
	if(v.size() > 0){
		for(int i = 0; i < v.size(); i++){
			m[v[i]] ++;
		}
		int numb = 0;
		for(auto& x : m){
			if(x.second > numb){
				place = x.first;
				numb = x.second;
			}
		}
		return place;
	}	
	return 0;
}
int main(){
	map<int, int> m;
	
	vector<int> v;
	v.push_back(3);
	v.push_back(3);
	v.push_back(4);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);

	vector<int> vNO;
	vNO.push_back(3);
	vNO.push_back(3);
	vNO.push_back(4);
	vNO.push_back(2);
	vNO.push_back(4);
	vNO.push_back(4);
	vNO.push_back(2);
	vNO.push_back(4);

	vector<int> small;
	small.push_back(2);

	int place = howMany(m,small);

	if(m.find(place)->second > (small.size() / 2)){
		cout << m.find(place)->second << endl;}
	else{cout << "none were the majority element" << endl;}

	return 0;
}
