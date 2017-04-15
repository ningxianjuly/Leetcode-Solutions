//Also a problem related to two pointers
//the optimization strategy is to detect whether we can skip the current loop(the remaining factors are too large or too small) Be careful if too large just end the program. If too small, continue to next loop.



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.empty() || nums.size() < 4) {
            return res;
        }
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-3; i++) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if (nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;
            for (int j = i+1; j < nums.size()-2; j++ ) {
                if (j != i+1 && nums[j] == nums[j-1]) continue;
                if (nums[j] + nums[j+1] + nums[j+2] + nums[i] > target) break;
                if (nums[j] + nums[i] + nums[n-1] + nums[n-2] < target) continue;
                int temp = target - nums[i] - nums[j];
                int front = j+1;
                int end = nums.size()-1;
                while (front < end) {
                    if (nums[front] + nums[end] < temp) {
                        front++;
                    } else if (nums[front] + nums[end] > temp) {
                        end--;
                    } else {
                        vector<int> temp_res;
                        temp_res.push_back(nums[i]);
                        temp_res.push_back(nums[j]);
                        temp_res.push_back(nums[front]);
                        temp_res.push_back(nums[end]);
                        res.push_back(temp_res);
                        while(front < end && nums[front] == nums[front+1]){
                            front++;
                        }
                        front++;
                    }
                }
            }
            
            
        }
        return res;
    }
};
