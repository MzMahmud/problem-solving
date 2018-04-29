#include <bits/stdc++.h>

using namespace std;

int main(){
    int T,cn = 1;
    cin >> T;
    while(T--){
        int n,m,a;
        string com;
        deque <int> dq;
        cout << "Case " << cn++ << ":" << endl;
        cin >> n >> m;
        while(m--){
            cin >> com;
            if(com == "pushLeft"){
                cin >> a;
                if(dq.size() >= n)
                    cout << "The queue is full" << endl;
                else{
                    dq.push_front(a);
                    cout << "Pushed in left: " << a <<endl;
                }
            }
            else if(com == "pushRight"){
                cin >> a;
                if(dq.size() >= n)
                    cout << "The queue is full" << endl;
                else{
                    dq.push_back(a);
                    cout << "Pushed in right: " << a <<endl;
                }
            }
            else if(com == "popLeft"){
                if(dq.empty())
                    cout << "The queue is empty" << endl;
                else{
                    cout << "Popped from left: " << dq.front() << endl;
                    dq.pop_front();
                }
            }
            else if(com == "popRight"){
                if(dq.empty())
                    cout << "The queue is empty" << endl;
                else{
                    cout << "Popped from right: " << dq.back() << endl;
                    dq.pop_back();
                }
            }
        }
    }
    return 0;
}
