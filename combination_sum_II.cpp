// https://leetcode.com/problems/combination-sum-ii/
// Solution inspired from: https://leetcode.com/problems/combination-sum/discuss/16496/Accepted-16ms-c%2B%2B-solution-use-backtracking-easy-understand.

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> comb;
        _combinationSum2(candidates, target, ret, comb, 0);
        return ret;
    }
    
private:
    void _combinationSum2(vector<int>& candidates, int target, vector<vector<int>>& ret, vector<int>& comb, int begin){
        if(target == 0){
            ret.push_back(comb);
            return ;
        }
        
        for(int i = begin; i < candidates.size() && target >= candidates[i]; i++){
            if(i == begin || candidates[i] != candidates[i-1]){
                 comb.push_back(candidates[i]);
                _combinationSum2(candidates, target - candidates[i], ret, comb, i+1);
                comb.pop_back();   
            }
        }
    }
};
