class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len);
        res[0] = nums[0];
        for (int i = 1; i < len; i++) {
            if (res[i-1] <= 0) {
                res[i] = nums[i];
            } else {
                res[i] = nums[i] + res[i-1];
            }
        }
        int max_val = INT_MIN;
        for (int item:res) {
            max_val = max(max_val,item);
        }
        return max_val;
        
    }
};
