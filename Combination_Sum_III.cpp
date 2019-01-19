// https://leetcode.com/problems/combination-sum-iii/
// Solution inspired from: https://leetcode.com/problems/combination-sum/discuss/16496/Accepted-16ms-c%2B%2B-solution-use-backtracking-easy-understand.

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> comb;
        
        _combinationSum3(k, n, ret, comb, 1);
        return ret;
    }
    
private:
    void _combinationSum3(int k, int target, vector<vector<int>>& ret, vector<int>& comb, int begin){
        if(target == 0 && k == 0){
            ret.push_back(comb);
            return ;
        }
        
        for(int i = begin; i < 10 && target >= i; i++){
            comb.push_back(i);
            k--;
            _combinationSum3(k, target - i, ret, comb, i+1);
            k++;
            comb.pop_back();
        }
    }
};
