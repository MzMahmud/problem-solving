#include <stdio.h>
#include <math.h>

int main(){
  int n;
  long long arrival;

  scanf("%d%lld", &n,&arrival);
  
  int index = -1;
  long long min_t;
  
  for(int i = 1;i <= n;i++){
    long long s,d;
    
    scanf("%lld%lld", &s,&d);
    
    int bus_index = 0;
    long long diff = arrival - s;
    
    if(diff > 0)
      bus_index = ceil( diff/(d + (long double).0) );
   
    long long t = s + d*bus_index;
    
    if(index < 0 || t < min_t){
      index = i;
      min_t = t;
    }
  }

  printf("%d", index);

  return 0;
}