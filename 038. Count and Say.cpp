class Solution {
public:
    string countAndSay(int n) {
        string temp("1");
        for(int i = 0 ; i < n-1 ; i++) {
            temp = nextvalue(temp);
        }
        return temp;
        
    }
    
private:
    string nextvalue(string input) {
        string res("");
        int count = 1;
        for (int i = 0; i < input.size(); i++) {
            if (i+1 < input.size() && input[i] == input[i+1]) {
                count++;
            } else {
                res += to_string(count) + input[i];
                count = 1;
            }
        }
        return res;
        
    }
};
