class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int>mp;
        mp[0] = -1;

        int curr = 0;
        int maxi = 0;

        for(int i =0; i<nums.size(); i++){
            if(nums[i] == 1){
                curr += nums[i];
            }
            else{
                curr -= 1;
            }

            if(mp.count(curr)){
                maxi = max(maxi, i - mp[curr]);
                
            }
            else{

            mp[curr] = i;
            }
        }

        return maxi;
    }
};