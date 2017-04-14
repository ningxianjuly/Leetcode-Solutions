//This is the recurision version of the problem.
//It is a DFS based search
//The only difference is that this should be a mapping
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return res;
        helper(digits, string(""));
        return res;
    }
private:
    vector<string> res;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void helper(string digits, string prefix) {
        if (prefix.size() == digits.size()) {
            res.push_back(prefix);
            
        } else {
            for (int i = 0; i < mapping[digits[prefix.size()] - '0'].size();i++) {
                helper(digits, prefix+mapping[digits[prefix.size()] - '0'][i]);
            }
        }
    }
};


//This is the iteration version of the problem.
//It is a BFS based search
//the queue always maintain all the possible results got from the first k digits
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (digits.size() == 0) return res;
        queue<string> q;
        q.push("");
        for (int i = 0; i < digits.size(); i++) {
            int size = q.size();
            for (int j = 0; j < size; j++) {
                string temp = q.front();
                for (int k = 0; k < mapping[digits[i] - '0'].size(); k++) {
                    q.push(temp+mapping[digits[i] - '0'][k]);
                }
                q.pop();
            }
        }
        while(!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
        
    }
};

//This is the iteration version of the problem.
//It is a upadted BFS based search(do not use queue but use only vector and swap)
//the queue always maintain all the possible results got from the first k digits
//also, the swap here is amazing. vector<string>().swap(res);can be used to free all the memory that is used by res. Remember, clear() can only free the elements in vector but not the true space occurped by vector.
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) return vector<string>();
        static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        result.push_back("");   // add a seed for the initial case
        for(int i = 0 ; i < digits.size(); ++i) {
            int num = digits[i]-'0';
            if(num < 0 || num > 9) break;
            const string& candidate = v[num];
            if(candidate.empty()) continue;
            vector<string> tmp;
            for(int j = 0 ; j < candidate.size() ; ++j) {
                for(int k = 0 ; k < result.size() ; ++k) {
                    tmp.push_back(result[k] + candidate[j]);
                }
            }
            result.swap(tmp);
        }
        return result;
        
    }
};
