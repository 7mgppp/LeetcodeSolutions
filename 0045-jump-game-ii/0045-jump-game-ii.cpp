class Solution {
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        int n = nums.size() - 1;
        int mini = INT_MAX;
        if (i >= n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        for (int j = 1; j <= nums[i]; j++) {
            int jump = solve(i + j, nums, dp);

            if (jump < INT_MAX) {
                mini = min(mini, 1 + jump);
            }
        }
        return dp[i] = mini;
    }

public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp);
    }
};