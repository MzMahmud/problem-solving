#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n+2);
  vector<int> prefix(n+2),suffix(n+2);
  
  a[0] = a[n+1] = 0;
  for(int i = 1;i <= n;i++)
     cin >> a[i];
     
  prefix[0]   = ~a[0];
  suffix[n+1] = ~a[n+1];
  
  for(int i = 1;i <= n;i++){
    prefix[i] = prefix[i-1] & (~a[i]);
    int j = n - i + 1;
    suffix[j] = suffix[j+1] & (~a[j]);
  }
  
  int max_val = -1,index;
  for(int i = 1;i <= n;i++){
    int val = prefix[i-1]
            & a[i] 
            & suffix[i+1];
    if(val > max_val){
      index = i;
      max_val = val;
    }
  }
  swap(a[1],a[index]);
  
  //cout << max_val << endl;
  
  for(int i = 1;i <= n;i++){
    cout << a[i] << (i == n?"\n":" ");
  }
  
  return 0;
}