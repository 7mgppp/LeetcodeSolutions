class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int length = INT_MAX;
        int sum = 0;
        for(int i =0; i<nums.size(); i++){
            sum += nums[i];
            while(sum >= target){
                length = min(length, i-l+1);
                sum-=nums[l];
                l++;
            }
        }

        if(length == INT_MAX){
            return 0;
        }
        else{
            return length;
        }

         
        
    }
};