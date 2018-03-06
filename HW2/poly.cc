#include <iostream>
#include <list>
using namespace std;

class polynomial{
    private:
        struct poly{
            int coefficient;
            int exponent;
        };
        list<poly> *polynomials = new list<poly>{};
    public:
        polynomial(){
        }
        void insert(int c, int e){
            poly tmp;
            tmp.coefficient = c;
            tmp.exponent = e;
            polynomials->push_back(tmp);
        }
        void prnt(){
            if(!polynomials->empty()){
                cout << "[";
                for(list<poly>::const_iterator it = polynomials->begin(); it != polynomials->end(); it++){
                    cout << "(" << it->coefficient << ", " << it->exponent << "), "; 
                }
                cout << "]" << endl;
            }
        }
        polynomial *mult(polynomial &p){
            polynomial *n;
            list<poly>::const_iterator it = polynomials->begin();
            list<poly>::const_iterator it2 = p.polynomials->begin();
            while(it != polynomials->end() || it2 != p.polynomials->end()){
                
            }
            return n;
        }
};

int main(){
    polynomial p;
    p.insert(2,2);
    p.insert(2,3);
    p.prnt();
    polynomial t;
    t.insert(1,2);
    t.insert(4,3);
    polynomial *n;
    n = p.mult(t);
    n->prnt();
    return 0;
}
