class Solution {
public:
    int climbStairs(int n) {
        int prev = 0;
        vector<int>climb(n+1, 1);
        for(int i = n-1; i>=0; i--){
            climb[i] = climb[i+1] + prev;
            prev = climb[i+1];
        }

        return climb[0];
        
    }
};