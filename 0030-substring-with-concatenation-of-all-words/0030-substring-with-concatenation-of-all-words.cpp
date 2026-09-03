class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        // What words and frequencies do we NEED?
        unordered_map<string, int> required;

        for (string word : words) {
            required[word]++;
        }

        // Try every possible starting alignment
        for (int i = 0; i < wordLen; i++) {

            int left = i;
            int right = i;

            
            unordered_map<string, int> current;

            int count = 0;

            while (right + wordLen <= s.size()) {

                string word = s.substr(right, wordLen);
                right += wordLen;

                
                if (required.find(word) == required.end()) {
                    current.clear();
                    count = 0;
                    left = right;
                    continue;
                }

                current[word]++;
                count++;

                
                while (current[word] > required[word]) {

                    string leftWord = s.substr(left, wordLen);

                    current[leftWord]--;
                    left += wordLen;
                    count--;
                }

                
                if (count == wordCount) {
                    ans.push_back(left);

                    
                    string leftWord = s.substr(left, wordLen);
                    current[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};