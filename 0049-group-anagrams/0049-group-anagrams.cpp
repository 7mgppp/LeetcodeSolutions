class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        for(string s : strs){
            vector<int> count(26,0);

            for(char c : s){
                count[c-'a']++;
            }

            string key = "";

            for(int i =0; i<count.size(); i++){
                int x = count[i];
                key+= to_string(x) + ",";
            }

            mp[key].push_back(s);
        }

        vector<vector<string>>res;
        for(auto &it : mp){
            res.push_back(it.second);
        }

        return res;

        
    }
};