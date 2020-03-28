class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums){
            int sum_4 = 0;
            if(tao(num,sum_4) == 4)
                sum += sum_4;
        }
        return sum;
    }
    int tao(int n,int &sum){
        int _tao = 0;
        for(int i = 1;i*i <= n;i++){
            if(!(n % i)){
                ++_tao;
                sum += i;
                if(i != (n / i)){
                    ++_tao;
                    sum += (n / i);
                }
            }
        }
        return _tao;
    }
};
