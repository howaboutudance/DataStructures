#include <iostream>
#include <vector>
using namespace std;

void prnt(vector<int> &v){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << ", ";
    }
    cout << endl;
}

void merge(vector<int> &v, int l, int m, int r){
    if(!(m <= 1)){
        for(int i = 0; i <= m; i++){
            cout << i << endl;
            if(v[l + i] > v[r - i]){
                int tmp = v[l + i];
                v[l + i] = v[r - i];
                v[r - i] = tmp;
            }
        }
    }
}
void mergeSort(vector<int> &v, int l, int r){
    if((r - l) > 1){
        int m = (r - l) / 2;
        cout << "Got here" << endl;
        merge(v, l, m, r);
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
    }
}

int main(){
    vector<int> vec;
    vec.push_back(4); vec.push_back(13); vec.push_back(1); vec.push_back(555); vec.push_back(42); vec.push_back(2); vec.push_back(55); vec.push_back(30); vec.push_back(18); vec.push_back(31); vec.push_back(9);
    prnt(vec);
    cout << "Merging... " << endl;
    mergeSort(vec, 0, vec.size() - 1);
    prnt(vec);
    return 0;
}
