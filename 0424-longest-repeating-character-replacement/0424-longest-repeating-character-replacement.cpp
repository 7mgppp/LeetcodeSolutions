class Solution {
public:
    int characterReplacement(string s, int k) {
        //same as whatever i did prev;

        int left = 0;
        unordered_map<char, int>mp;
        int maxfreq = 0;
        int ans = 0;

        for(int i =0; i<s.size(); i++){
            mp[s[i]]++;
            maxfreq = max(maxfreq, mp[s[i]]);

            while((i-left+1) - maxfreq > k){
                mp[s[left]]--;
                left++;
            }

            ans = max(ans, i-left+1);

        }

        return ans;


        
    }
};