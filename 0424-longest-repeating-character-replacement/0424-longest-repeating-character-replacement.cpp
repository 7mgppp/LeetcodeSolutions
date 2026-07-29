class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int max_freq = 0;
        int main_maxi = 0;
        int left = 0;

        //valid condition
        for(int i =0; i<s.size(); i++){
            mp[s[i]]++;
            max_freq = max(max_freq, mp[s[i]]);
            
            //length of string till now - max occured char > k that means no more replacements can be made
            while(i-left+1 - max_freq > k){
                mp[s[left]]--;
                left++;
            } 

            main_maxi = max(main_maxi, i-left+1);

        }

        return main_maxi;

        
    }
};