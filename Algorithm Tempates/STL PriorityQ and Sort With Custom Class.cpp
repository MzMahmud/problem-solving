#include <bits/stdc++.h>

using namespace std;

class Val{
    string data;
public:
    int key;
    Val(string a,int k){
        data = a;
        key  = k;
    }
    string getData(){return data;}
    int getKey(){return this->key;}
};

struct Comp{
    bool operator()(Val& a,Val& b){
        return a.getKey() > b.getKey();
    }
};

bool comp(Val a,Val b){
    return a.getKey() < b.getKey();
}
int main(){
    priority_queue<Val,vector<Val>,Comp> pq;
    Val a("Moaz",5);
    Val b("Mahmud",1);
    Val c("Tanvir",8);
    Val d("Abir",18);

    pq.push(a);
    pq.push(b);
    pq.push(c);
    pq.push(d);

    vector<Val> arr;
    arr.push_back(a);
    arr.push_back(c);
    arr.push_back(b);
    arr.push_back(d);

    for(int i = 0;i < arr.size();i++) cout << arr[i].getData() << " " << arr[i].key << endl;

    sort(arr.begin(),arr.end(),comp);

    cout << "After" << endl;

    for(int i = 0;i < arr.size();i++) cout << arr[i].getData() << " " << arr[i].key << endl;

    return 0;
}
