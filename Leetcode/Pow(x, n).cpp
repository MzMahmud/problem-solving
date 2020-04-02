class Solution {
public:
    double myPow(double x,int n){
  if(n < 0){
    unsigned int nn = n;
    return 1.0/power(x,-nn);
  }
  
  return power(x,n);
}

double power(double x,unsigned int n){
  if(x == 0.0)
    return 0.0;
  if(!n)
    return 1.0;  
  double ans = power(x,n>>1);
  ans *= ans;
  if(n&1) ans *= x;
  return ans;
}


   
};
