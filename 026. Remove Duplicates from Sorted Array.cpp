class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int len = nums.size();
        int sub = 0;
        for (int i= 0, j = 0; i < len; j++, i++) {
            while ( (i != 0) && i < len && (nums[i-1] == nums[i]) ) {
                sub++;
                i++;
            }//this is to move to the first different num in nums array
            if (j != i){
                nums[j] = nums[i];
            }
            
            
        }
        return (len - sub);
    }
};
