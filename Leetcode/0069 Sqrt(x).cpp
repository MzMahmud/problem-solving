class Solution {
public:
    int mySqrt(int x) {
        int lo = 0;
  int hi = x;
  int mid;
  
  int k = 10;
  
  while(lo <= hi){
    mid = (lo+hi) >> 1;
    
    long long mid2 = ((long long)mid)*mid;
    if(mid2 == x)
      return mid;
    if(mid2 < x)
      lo = mid + 1;
    else
      hi = mid - 1;
  }
  return (lo+hi)>>1;
    }
};
