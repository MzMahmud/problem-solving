#include <iostream>
#include <list>

using namespace std;

int main() {
    int p,c,cn = 1;
    while(cin >> p >> c && (p || c)){
        cout << "Case " << (cn++) << ":\n";
        list<int> q;
        
        for(int i = 1;i <= p and i < 1005;++i)
            q.push_back(i);
        
        while(c--){
            char com;
            cin >> com;
            if(com == 'N'){
                cout << q.front() << endl;
                q.push_back(q.front());
                q.pop_front();
            }else{
                int num;
                cin  >> num;
                q.remove(num);
                q.push_front(num);
            }
            cin.ignore();
        }
    }
    return 0;
}