class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi = 0;
        int left = 0;
        int ZeroCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                ZeroCount++;
                while (ZeroCount > k) {
                    if (nums[left] == 0) {
                        ZeroCount--;
                        left++;
                    }
                    else{
                        left++;
                    }
                    
                }
            }
            maxi = max(maxi, i - left + 1);
        }

        return maxi;
    }
};