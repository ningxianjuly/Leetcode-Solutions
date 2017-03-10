class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while (visited.find(n) == visited.end()){
            visited.insert(n);
            string s = to_string(n);
            int temp_res = 0;
            for (char i:s) {
                temp_res += (i-'0')*(i-'0');
            }
            n = temp_res;
            if (n == 1) {
                return true;
            }
        }
        return false;
    }
};
