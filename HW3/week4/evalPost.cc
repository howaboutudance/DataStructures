#include <iostream>
#include <typeinfo>
#include <stack>
#include <string>
#include <map>

using namespace std;

class postParse{
	private:
		typedef int (*_fPoint)(int,int);
		map<string, _fPoint> mfp;
	
	public:
		void add(string id, _fPoint f){
			mfp[id] = f;
		}
		int call(string func, int l, int r){
			return mfp[func](l, r);
		}
};

int a(int r, int l){
	return l + r;
}
int sub(int r, int l){
	return l - r;
}
int mult(int r, int l){
	return l * r;
}
int divi(int r, int l){
	return (l / r);
}

int main(){
	postParse p;
	p.add("+", a);
	p.add("-", sub);
	p.add("*", mult);
	p.add("/", divi);

	string userInput;
	cout << "Write your equation in post fix, int only" << endl;
	getline(cin, userInput);
	stack<int> post;
	int r;
	int l;

	

	/* for(string::iterator it = userInput.begin(); it != userInput.end(); ++it){
		if(*it == ' ')
			continue;
		if((int)*it > 47 && (int)*it < 58){
			post.push((int)*it - 48);
		}else{
			r = post.top();
			cout << r << endl;
			post.pop();
			l = post.top();
			cout << l << endl;
			post.pop();
			string s = to_string(*it);
			p.call(s,r,l);
			cout << "test" << endl;
		}
	}
	*/

	return 0;
}
