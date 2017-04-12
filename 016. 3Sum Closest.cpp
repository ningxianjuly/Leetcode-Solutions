//一开始的时候将res赋值为了int_max,结果遇到了很多边界条件的问题，不好
//这种问题赋初值的时候可以选择数组中任意的几个元素，不会出现越界的问题
//同时注意跳过重复的元素，可以减少很多时间
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.empty()) {
            return 0;
        }
        std::sort(nums.begin(),nums.end());
        if(nums.size() <= 3) {
            return accumulate(nums.begin(), nums.end(), 0);
        }
        //accumulate, the third parameter is to set the initial value
        int res = nums[0]+nums[1]+nums[2];
        for (int i = 0; i < nums.size()-2; i++) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int front = i + 1;
            int end = nums.size() - 1;
            while(front < end) {
                int cur_sum = nums[front] + nums[end] + nums[i];
                if (cur_sum < target) {
                    front++;
                } else if (cur_sum > target) {
                    end--;
                } else {
                    return target;
                }
                if(abs(cur_sum - target) < abs(res - target)) {
                    res = cur_sum;
                }
            }
        }
        return res;
    }
};
