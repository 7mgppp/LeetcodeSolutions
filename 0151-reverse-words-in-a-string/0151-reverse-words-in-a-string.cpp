class Solution {
public:
    string reverseWords(string s) {
        stringstream str(s);
        vector<string> sentence;
        string word;
        while (str >> word){
            sentence.push_back(word);
        }

        int left = 0;
        int right = sentence.size()-1;

        while(left < right){
            swap(sentence[left], sentence[right]);
            left++;
            right--;
        }

        string ans = "";
        for(int i =0; i<sentence.size(); i++){
            ans+= sentence[i];
            if (i != sentence.size() - 1) {
                ans += " ";
            }
            
        }

        return ans;

        
    }
};