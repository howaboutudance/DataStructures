#include <iostream>
#include <fstream>
#include <string>
#include "Importing.h"

using namespace std;

int main(){
	
	fstream file1("Importing.h");
	fstream file2("readWriteFile.cpp");
	fstream writeFile("oputText.txt");

	string line1;
	string line2;
	
	if(file2.is_open() && file1.is_open()){
		while(getline(file2, line2)){
			//writeFile.write(line2, line2.capacity());
			if(!line2.compare(0,22,"#include \"Importing.h\"")){
				while(getline(file1, line1)){
					cout << line1 << endl;
					//writeFile.write(line1, 1);
				}	
			}
		}
		file1.close();
		file2.close();
		writeFile.close();
	} else {
		cout << "Sucks dunnit!" << endl;
	}

	return 0;
}
