#include <string>
#include <iostream>
#include "expr.h"

using namespace std;

int main(){
    string s = "12+345+**";
    ExTree e;
    e.insert(s);
    return 0;   
}
