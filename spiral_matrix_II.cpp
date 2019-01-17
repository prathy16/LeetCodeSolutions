# https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
        char dir = 'R';
        int num = 1;
        
        int min_row = 0, max_row = n-1, min_col = 0, max_col = n-1;
        
        while(min_row <= max_row && min_col <= max_col)
        {
            if(dir == 'R'){
                for(int j = min_col ; j <= max_col; j++){
                    matrix[min_row][j] = num++;
                }
                min_row += 1;
                dir = 'D';
                
            }
            else if(dir == 'D'){
                for(int j = min_row; j<= max_row; j++){
                    matrix[j][max_col] = num++;
                }
                max_col -= 1;
                dir = 'L';
            }
            else if(dir == 'L'){
                for(int j = max_col; j >= min_col; j--){
                    matrix[max_row][j] = num++;
                }
                max_row -= 1;
                dir = 'U';
            }
            else{
                for(int j = max_row; j >= min_row; j--){
                    matrix[j][min_col] = num++;
                }
                min_col += 1;
                dir = 'R';
            }
        }
        
        return matrix;
    }
};
