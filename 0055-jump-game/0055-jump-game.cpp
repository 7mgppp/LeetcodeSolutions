class Solution {
    bool solve(int i, vector<int>& nums, vector<int>& dp) {
        int n = nums.size() - 1;
        if (i >= n) {
            return true;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        for (int j = 1; j <= nums[i]; j++) {
            if (solve(i + j, nums, dp)) {
                return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp);
    }
};