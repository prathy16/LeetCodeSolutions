// https://leetcode.com/problems/combination-sum-iv/
// Dynamic Programming approach

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            for(int x: nums){
                if(i >= x)
                    dp[i] += dp[i - x];
            }
        }
        return dp[target];
    }
};