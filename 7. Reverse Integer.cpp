class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        for (; x != 0 ; x /= 10) {
            res = res*10 + x%10;
        }
        if (res < INT_MIN || res > INT_MAX) return 0;
        return res;
    }
};
