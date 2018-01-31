// ifstream constructor.
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <string>
using namespace std;
int main () {
	
	string poop = "poop.txt";
  	ifstream ifs (poop, ifstream::binary);

  	char c = ifs.get();

  	while (ifs.good()) {
    	cout << c;
    	c = ifs.get();
  	}

  	ifs.close();

  	return 0;
}
