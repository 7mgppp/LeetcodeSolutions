class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i =0; i<nums.size();i++){
            nums[i]%=2;
        }
        
        unordered_map<int,int>mp;
        mp[0] = 1;
        int count = 0;
        int PreSum = 0;

        for(int i =0; i<nums.size();i++){
            PreSum+=nums[i];
            if(mp.count(PreSum-k)){
                count+=mp[PreSum-k];
            }
            mp[PreSum]++;
        }
        return count;
    }
};