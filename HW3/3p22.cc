/*
 * Michelle Bergin
 * HW3 Q3.22
 *
 * Evaluate a postfix expression
 *
 */

#include <iostream>
#include <stack>
#include <string>
#include <math.h>

using namespace std;
double postParse(string &s){
	stack<double> stck;
	double a, b;
	for(int i = 0; i < s.size(); i++){
		if((int)s[i] > 47 && (int)s[i] < 58){
			stck.push((double)((int)s[i] - 48));
		} else {
			if(s[i] == ' '){
				continue;
			} else if(s[i] == '+'){
				a = stck.top();
				stck.pop();
				b = stck.top();
				stck.pop();
				stck.push(a + b);
			} else if(s[i] == '*'){
				a = stck.top();
				stck.pop();
				b = stck.top();
				stck.pop();
				stck.push(a * b);
			} else if(s[i] == '/'){
				a = stck.top();
				stck.pop();
				b = stck.top();
				stck.pop();
				stck.push(b / a);
			} else if(s[i] == '^'){
				a = stck.top();
				stck.pop();
				b = stck.top();
				stck.pop();
				stck.push(pow(b, a));
			} else if(s[i] == '-'){
				a = stck.top();
				stck.pop();
				b = stck.top();
				stck.pop();
				stck.push(b - a);
			}
		}
	}
	return stck.top();
}
int main(){
	string str = "1 2 + 3 * 6 + 2 3 + /";
	string str2 = "9 5 3 + 2 4 ^ - +";

	cout << str << " is the postfix expression" << endl;
	cout << postParse(str) << " is the answer\n" << endl;
	
	cout << str2 << " is the postfix expression" << endl;
	cout << postParse(str2) << " is the answer\n" << endl;

	return 0;
}
