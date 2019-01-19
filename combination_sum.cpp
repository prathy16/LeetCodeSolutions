// https://leetcode.com/problems/combination-sum/
// Solution inspired from: https://leetcode.com/problems/combination-sum/discuss/16496/Accepted-16ms-c%2B%2B-solution-use-backtracking-easy-understand.

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        _combinationSum(candidates, target, ret, comb, 0);
        return ret;
    }
    
private:
    void _combinationSum(vector<int>& candidates, int target, vector<vector<int>>& ret, vector<int>& comb, int begin){
        if(target == 0){
            ret.push_back(comb);
            return ;
        }
        
        for(int i = begin; i < candidates.size() && target >= candidates[i]; i++){
            comb.push_back(candidates[i]);
            _combinationSum(candidates, target - candidates[i], ret, comb, i);
            comb.pop_back();
        }
    }
};
