class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        vector<int>res;
        
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        while(k > 0){
            int maxi = 0;
            int number = -1;

            for (auto it : mp){
                if (it.second > maxi){
                    maxi = it.second;
                    number = number = it.first;
                }
            }

            res.push_back(number);
            mp.erase(number);
            k--;
        }

        return res;

    }
};