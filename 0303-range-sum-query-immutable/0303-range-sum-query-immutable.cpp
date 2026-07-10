class NumArray {
public:
vector<int> nums;
    NumArray(vector<int>& nums) {
        this->nums = nums;

        for(int i =1; i< this->nums.size(); i++){
            this->nums[i] = this->nums[i-1] + this->nums[i];
        } 
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return nums[right];
        return nums[right] - nums[left - 1];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */