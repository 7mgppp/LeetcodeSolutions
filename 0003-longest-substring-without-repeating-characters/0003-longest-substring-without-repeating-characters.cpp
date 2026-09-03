class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;
        int length = INT_MIN;
        int l = 0;

        for(int i =0; i<s.size(); i++){
            mp[s[i]]++;
            while(mp[s[i]] == 2){
                mp[s[l]]--;
                l++;
            }

            length = max(length, i-l+1);
        }

        if(length == INT_MIN){
            return 0;
        }
        else{
            return length;
        }

        
    }
};