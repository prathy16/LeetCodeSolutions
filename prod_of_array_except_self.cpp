# https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), prod_from_begin = 1, prod_from_last = 1;
        vector<int> res(n, 1);
        
        for(int i = 0; i < n; i++){
            res[i] *= prod_from_begin;
            prod_from_begin *= nums[i];
            
            res[n-1-i] *= prod_from_last;
            prod_from_last *= nums[n-1-i];
        }
        
        return res;
    }
};
