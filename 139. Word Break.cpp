class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        vector<bool> Dp(size+1,false);
        Dp[0] = true;
        for (int i = 1; i <= size; i++) {
            for (int j = 0; j < i; j++) {
                if (Dp[j]) {
                    string temp = s.substr(j, i-j);
                    if (find(wordDict.begin(), wordDict.end(), temp) != wordDict.end()) {
                        Dp[i] = true;
                        break;
                    }
                }
            }
        }
        return Dp[size];
    }
};
