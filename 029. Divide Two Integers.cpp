//This is to convert division into substraction.However, single substraction is too costing. So I use the left shift to make the sustraction has the better performance.
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 ) {
            return INT_MAX;
        }
        if (divisor == -1 && dividend == INT_MIN) {
            return INT_MAX;
        }
        int res = 0;
        int flag = 0;
        if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor >0)) {flag = 1;}
        long long div = labs(dividend);
        long long dis = labs(divisor);
        while (div >= dis) {
            long long temp = dis, cur_res = 1;
            while (div >= (temp << 1)) {
                temp = temp << 1;
                cur_res = cur_res << 1;
            }
            div -= temp;
            res += cur_res;
        }
        return flag == 1 ? res : -res ;
        
    }
};
