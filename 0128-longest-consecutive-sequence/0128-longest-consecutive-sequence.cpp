class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(), nums.end());
        int maxi = 0;

        for(int num : st){
            if(!st.count(num-1)){
                int current = num;
                int len = 1;

            while(st.count(current+1)){
                current++;
                len++;
            }

            maxi = max(len, maxi);
        }    
    }


        return maxi;

        
    }
};