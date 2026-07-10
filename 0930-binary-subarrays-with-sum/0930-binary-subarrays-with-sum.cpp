class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        mp[0] = 1;
        int count = 0;
        int PreSum = 0;
        for(int i =0; i<nums.size(); i++){
            PreSum+=nums[i];
            if(mp.count(PreSum-goal)){
                count+=mp[PreSum-goal];
            }
            mp[PreSum]++;
        }

        return count;
        
    }
};