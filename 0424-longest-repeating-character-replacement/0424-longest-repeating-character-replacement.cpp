class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxi = 0;
        int maxFreq = 0;
        unordered_map<int,int>mp;

        for(int i =0; i<s.size(); i++){
            mp[s[i]]++;
            maxFreq = max(maxFreq, mp[s[i]]);

            while(i-left+1 - maxFreq > k){  // invalid condition
                mp[s[left]]--;
                left++;
            }

            maxi = max(maxi, i-left+1);
        }

        return maxi;
        
    }
};