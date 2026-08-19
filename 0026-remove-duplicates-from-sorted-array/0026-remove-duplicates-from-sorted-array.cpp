class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j =0;
        int k = 1;
        int n = nums.size();
        for(int i =0; i<n ; i++){
            while(j < n && nums[j] == nums[i]){
                j++;
            }
            if( j < n){
                nums[i+1] = nums[j];
                j++;
                k++;
            }
        }

        return k;
        
    }
};