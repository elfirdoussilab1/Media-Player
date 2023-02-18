#include <iostream>
#include <sstream>
#include <map>
#include <vector>
using namespace std;
map<int, string> extract(stringstream & ss){
    map<int, string> m;
    int i = 0;
    string s;
    while (ss >> s ){
        m[i] = s;
        i++;
    }
    return m;
}


int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << v.at(0) << endl;
    cout << v[5] << endl;

    return 0;
}