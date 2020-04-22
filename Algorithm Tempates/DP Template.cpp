/*
 A guid to write your DP in C++
 
 Step 1. Come up with a recurance
 Step 2. Code it with the recurrance
 Step 3. If overlapping sub problem Occurs then apply DP
 Step 4. If possible write a bottom up Dp
 
 Example:
    Find n-th fibonacci number
    
 Solution:
    You may wany to use the math formula 
    C(n,r) = n!/(r!(n-r)!) = (n(n-1)(n-2)...(n-r+1))/(1*2*..*r)
    But this leads to over flow for large number because of multiplication.
    But C(n,r) is always an integer. So there must be a way to solve it effectively
    
 */ 
#include <iostream>

using namespace std;

/*
Step 1: Come up with a recurance
        You shuld know
            C(n,r) = C(n-1,r) + C(n-1,r-1)
        
        Base Case:
            C(n,0) = C(n,n) = 1
*/

/*
Step 2: Code the recurance
*/

int C_rec(int n,int r){
    // Base Case
    if(r == 0 || n == r)
        return 1;
        
    return C_rec(n - 1,r) + C_rec(n - 1,r - 1);
}

/*
Step 3: Lets examine

                       C(5,3)
            C(4,3)                 C(4,2)
        C(3,3)    C(3,2)       C(3,2)   C(3,1)
          1   C(2,2)  C(2,1)
          
        You can see C(3,2) calculated multiple times
        So dp can be applied
*/


/*
    Let 0 <= n <= 20
    So we know that n's maximum value is 20
    So lets create global dp arrsy atmost 20 
*/


#define MAXN 20
// The purpose of this define is if you need MAXN 30
// then you have to change it in only one placed

int dp[MAXN + 3][MAXN + 3];
// if max_n = 10 , dp index is 0,1,...,n so dp size have to be atleast n + 1
// The purpose of defining MAXN + 3 is just safety for indexing  

int C_dp(int n,int r){
    // Base case
    if(r == 0 || n == r){
        dp[n][r] = 1;
        return dp[n][r];
        // note this two lines can be combined
        // return dp[n][r] = 1;
        // this first assigns dp[n][r] = 1 then return it
    }
    
    /* 
    This part is tricky. In this part if dp[n][r] is not calculated,then calculate dp[n][r].
    But how do we know its not calculated! In this problem we initilized all dp[n][r] = -1
    because C(n,r) can't be negative. 
    So if dp[n][r] < 0 this means dp[n][r] has not wet been calculated.
    For other problem think about this case. For what value its not calculated.
    There is also a way to solve this by declaring a struct
    struct Node{
        int val;
        bool calculated;
    }
    Node dp[MAXN][MAXN];
    and initialize like this
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            dp[i][j].calculated = false;
    
    In that case his check would be
    
    if(dp[n][r].calculated == false)
    
    Also remember to make dp[n][r].calculated true after calculating
    
    */
    if(dp[n][r] < 0){
        dp[n][r] = C_dp(n - 1,r) + C_dp(n - 1,r - 1);
        // This is important
        // recurrsively call C_dp() and store the result to dp[n][r]
        // people mistakenly write,dp[n][r] = dp[n - 1][r] + dp[n - 1][r - 1]
        // This is wrong because you don't yet have the value of dp[n - 1][r],dp[n - 1][r - 1]
        // Then you may wonder how does dp work! For the first time it calculates and stores
        // Form then of dp[n][r] < 0 would be false and the value would be returned directly
    }
    
    return dp[n][r]; 
}


int main() {
    
    cout << C_rec(7,4) << endl;
    
    /*
        Step 3: Initilization
    */
    for(int i = 0;i <= MAXN;i++)
        for(int j = 0;j <= MAXN;j++)
            dp[i][j] = -1;
    // Notice: i <= MAXN and j <= MAXN. 
    //         Equal sign because if MAXN = 10,dp[10][10] can be queried
    cout << C_dp(7,4) << endl;
    
    /* Step 4: Bottom UP DP
       Notice what we are doing in DP,
       We are starting with dp[0][0] and building upto dp[n][r].
       This can also be done using array
    */
    int nCr[MAXN + 3][MAXN + 3];
    for(int n = 0;n <= MAXN;n++){
        for(int r = 0;r <= MAXN;r++){
            // Implement the base case and logic here
            // Base case
            if(n == r || r == 0){
                nCr[n][r] = 1;
            }else{
                nCr[n][r] = nCr[n - 1][r] + nCr[n - 1][r - 1];
                // This works because nCr[n - 1][r],nCr[n - 1][r - 1] has already 
                // been calculated in the previous iteration of loop
            }
        }    
    }
    cout << nCr[7][4] << endl;
    
    return 0;
}