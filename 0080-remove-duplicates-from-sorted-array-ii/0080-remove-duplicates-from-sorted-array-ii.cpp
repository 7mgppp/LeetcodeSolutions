class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(); 
        int k = 1;
        int j = 0;

        for(int i =0; i<n; i++){
            int count = 0;
            int current = nums[i];
            while(j < n && nums[j] == current){
                count++;
                j++;
            }

            if (i != 0) {
                nums[k] = current;
                k++;
            }

            if(count >= 2){
                nums[k] = current;
                k++;
            }


            i = j-1;
        }

        return k;
    }
};