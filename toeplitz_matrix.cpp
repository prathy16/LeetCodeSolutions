# https://leetcode.com/problems/toeplitz-matrix/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i = 0; i < n; i++){
            for(int k = 1; k < m && i+k < n; k++){
                if(matrix[0][i] != matrix[k][i+k])
                    return false;
            }
        }
        for(int i = 1; i < m; i++){
            for(int k = 1; k < n&&i+k<m; k++){
                if(matrix[i][0] != matrix[i+k][k])
                    return false;
            }
        }
        
        return true;
    }
};
