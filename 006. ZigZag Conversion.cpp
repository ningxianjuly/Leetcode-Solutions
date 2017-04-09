//the first version:

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 0 || numRows == 1) {
            return s;
        }
        vector<string> temp_res(numRows);
        int denom = 2*numRows -2;
        for (int i = 0; i < s.size(); i++) {
            int ans = i % denom;
            if (ans < numRows) {
                temp_res[ans] =  temp_res[ans] + s[i];
            } else {
                temp_res[numRows - ans + numRows - 2] =  temp_res[numRows - ans + numRows - 2] + s[i];
            }
        }
        string res = "";
        for (auto item : temp_res) {
            res += item;
        }
        return res;
    }
};

// this verision is very straight forward. use the vector to store the infromation of the each row
// this version realizes that the cycle is numRow but fails to realazie the realtion between first element and second element in each row. Thus the space complexity is O(2n)  

//updated version 
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 0 || numRows == 1) {
            return s;
        }
        string res = "";
        int cycle = 2*numRows - 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < s.size(); ) {
                res += s[j];
                int secondj = j-i+cycle-i;
                if (i != 0 && i != numRows-1 && secondj < s.size()) {
                    res += s[secondj];
                }
                j = j + cycle;
                    
            }
        }
        return res;
    }
};