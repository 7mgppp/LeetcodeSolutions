class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {

        int maxi = INT_MIN;
        for(int i =0; i<nums.size(); i++){
            maxi = max(nums[i], maxi);
        }

        int low = 0;
        int high = maxi;
        int ans = -1;




        while(low <= high){

            int bouquet = 0;
            int count = 0;
            int mid = (low + high)/2;

            for(int i =0; i<nums.size(); i++){
                if(nums[i] <= mid){
                    count++;
                    if(count == k){
                        bouquet++;
                        count = 0;
                    }

                }

                else{
                    count = 0;
                }
            }

            if(bouquet >= m){
                high = mid - 1;
                ans = mid;
            }

            else{
                low = mid +1;
            }



        }

        return ans;

        
    }
};