class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int start = 0;
        int end = 0;
        int res = 0;
        while (end < len) {
            if (end+1 == len) {
                res += prices[end] - prices[start];
                break;
            }
            if (prices[end] < prices[end+1]) {
                end++;
            } else {
                res += prices[end] - prices[start];
                start = end + 1;
                end++;
            }
        }
        return res;
        
    }
};
