class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int start = 0;
        double maxSum = INT_MIN;
        double sum = 0;
        for(int i =0; i<k; i++){
            sum+= nums[i];
            maxSum = sum/k;
        }

        for(int i = k; i < nums.size(); i++){
            sum+= nums[i];
            sum-= nums[start];
            start++;
            maxSum = max(maxSum, sum/k);
        }

        maxSum = max(maxSum, sum/k);

        return maxSum;




        
    }
};