class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int len = nums.size();
        vector<int> Dp(len,1);
        int max_before = 0;
        int res = 1;
        for (int i = 1; i < len ; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    max_before = max(max_before, Dp[j]);
                }
            }
            Dp[i] = max_before + 1;
            res = max(res,Dp[i]);
            max_before = 0;
        }
        return res;
        
    }
};
