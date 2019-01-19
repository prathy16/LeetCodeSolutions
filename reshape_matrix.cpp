// https://leetcode.com/problems/reshape-the-matrix/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int R = nums.size(), C = nums[0].size();
        if(R*C != r*c) 
            return nums;
        
        int count = 1;
        int p = 0, q = 0;
        vector<vector<int>> res(r, vector<int>(c));
        
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(count%c != 0){
                    res[p][q++] = nums[i][j];
                    count++;
                }
                else{
                    res[p][q] = nums[i][j];
                    p = p+1;
                    q = 0;
                    count = 1;
                }
            }
        }
        
        return res;
    }
};
