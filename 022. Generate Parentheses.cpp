//This is the recursion mode for this problem
//A general DFS approach with the cutting edge
//My idea is to count how many parentheses have been used. This may lead to the complex logic of deciding whether the current result is legal.
//Another method is to do it from the different direction. Record the number of parentheses that need to be added.
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        helper(0,0,n,"");
        return res;
    }
private:
    vector<string> res;
    void helper(int l_num, int r_num, int n, string temp) {
        if (l_num == r_num && l_num == n) {
            res.push_back(temp);
        } else if (l_num < r_num || l_num + r_num == 2*n) {
            return;
        } else {
            helper (l_num+1, r_num,n,temp+"(");
            helper (l_num, r_num+1,n,temp+")");
        }
    }
};
