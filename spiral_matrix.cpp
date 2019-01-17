# https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        char dir = 'R';
        int m = matrix.size();
        if(m == 0) 
            return result;
        int n = matrix[0].size();
        
        int min_row = 0, max_row = m-1, min_col = 0, max_col = n-1;
        
        while(min_row <= max_row && min_col <= max_col)
        {
            if(dir == 'R'){
                for(int j = min_col ; j <= max_col; j++){
                    result.push_back(matrix[min_row][j]);
                }
                min_row += 1;
                dir = 'D';
                
            }
            else if(dir == 'D'){
                for(int j = min_row; j<= max_row; j++){
                    result.push_back(matrix[j][max_col]);
                }
                max_col -= 1;
                dir = 'L';
            }
            else if(dir == 'L'){
                for(int j = max_col; j >= min_col; j--){
                    result.push_back(matrix[max_row][j]);
                }
                max_row -= 1;
                dir = 'U';
            }
            else{
                for(int j = max_row; j >= min_row; j--){
                    result.push_back(matrix[j][min_col]);
                }
                min_col += 1;
                dir = 'R';
            }
        }
        
        return result;
    }
};
