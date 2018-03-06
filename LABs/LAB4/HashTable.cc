#include <string>
#include <list>
#include <vector>
#include <iterator>
using namespace std;

template <typename HashedObj>
class HashTable{
    public:
        explicit HashTable(int size = 101) : theLists(size), currentSize(0) {
            for(int i = 0; i < size; i++){
                theLists[i] = *new list<HashedObj>();
            }
        }
        //bool contains(const HashedObj & x) const{
            
        //}
        void makeEmpty(){
            for(int i = 0; i < theLists.size(); i++){
                theLists[i].clear();
            }
        }
        void insert(const HashedObj & x){
            theLists[hash(x) % theLists.size()].push_back(x);
        }
        //void remove(const HashedObj & x);

    private:
        vector<list<HashedObj>> theLists;
        int  currentSize;
        //void rehash();
        //int myhash(const HashedObj & x) const;
};
