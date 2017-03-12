class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int target = nums[end];
        while (start+1 < end){
            int mid = start + (end - start)/2;
            if (nums[mid] < target) {
                end = mid;
            } else if (nums[mid] > target) {
                start = mid;
            }
            
        }
        if (nums[start] < nums[end]) {
            return nums[start];
        } else {
            return nums[end];
        }
    }
};
