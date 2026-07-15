class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int index = nums.size()-1;
        vector<int>v(nums.size());

        while(left <= right){
            int leftsq = nums[left] * nums[left];
            int rightsq = nums[right] * nums[right];

            if(leftsq > rightsq){
                v[index] = leftsq;
                left++;
            }
            else{
                v[index] = rightsq;
                right--;
            }
            index--;
        }
        return v;
        
    }
};