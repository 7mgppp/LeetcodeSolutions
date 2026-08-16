class Solution {
    int solve(int i, vector<int>& nums, vector<int>&dp){
        
        if(nums.size() <= i){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        return dp[i] = max(nums[i]+solve(i+2, nums, dp), solve(i+1, nums, dp));
    }
public:
    int rob(vector<int>& nums) {

        vector<int>dp(nums.size(), -1);
        return solve(0, nums, dp);
        
    }
};