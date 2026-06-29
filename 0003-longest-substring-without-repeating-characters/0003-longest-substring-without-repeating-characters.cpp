class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int maxi = 0;
        int left = 0;

        for(int right = 0; right<s.size(); right++){
                mp[s[right]]++;

            while(mp[s[right]] == 2){ //invalid condition ? -> when freq s[right] == 2 
                mp[s[left]]--;
                left++;
            }

            maxi = max(maxi, right - left + 1); 

        }

        return maxi;


    }
};