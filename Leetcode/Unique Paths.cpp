class Solution {
public:
    int uniquePaths(int M, int N) {
        // there will be exactly M-1 R,N-1 D
		// example, m = 4,n = 3
		// RRRDD,RRDRD, and so on
        // so to permute M-1+N-1 objects where M-1 of them is R and N-1 of them is R.
		// (M-1+N-1)!/(M-1)!(R-1)! = C(M-1+N-1,M-1) = C(M-1+N-1,N-1)
		
        int n = M + N - 2;
        int r = min(M,N) - 1;
        
        //C(n,r)
        long long nCr = 1;
        for(int i = 0;i < r;i++)
            nCr = nCr*(n-i)/(i+1);
        return nCr;
    }
};
