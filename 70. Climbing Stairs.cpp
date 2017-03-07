class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        vector<int> Dp(n,0);
        Dp[0]=1;
        Dp[1]=2;
        for (int i = 2; i < n; i++){
            Dp[i] = Dp[i-1] + Dp[i-2];
        }
        return Dp[n-1];
    }
};
