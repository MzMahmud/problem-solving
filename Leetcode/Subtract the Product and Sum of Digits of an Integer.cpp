class Solution {
public:
    int subtractProductAndSum(int n) {
        return digit_prod(n) - digit_sum(n); 
    }
    
    int digit_sum(int n){
        if(n < 10) return n;
        return (n % 10) + digit_sum(n/10);
    }
    int digit_prod(int n){
        if(n < 10) return n;
        return (n % 10) * digit_prod(n/10);
    }
};
