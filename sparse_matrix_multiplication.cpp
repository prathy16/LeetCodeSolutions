# https://leetcode.com/problems/sparse-matrix-multiplication/

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<pair<pair<int, int>, int>> mapA, mapB;
        
        int rows = A.size(), cols = B[0].size(), mid = B.size();
        vector<vector<int>> C(rows, vector<int>(cols));
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j< mid; j++){
                if(A[i][j] != 0){
                    mapA.push_back( {{i, j}, A[i][j]});
                }
            }
        }
        
        
        for(int i = 0; i < mid; i++){
            for(int j = 0; j < cols; j++){
                if(B[i][j] != 0){
                    mapB.push_back({{i, j}, B[i][j]});
                }
            }
        }
        
        for(int i = 0; i < mapA.size(); i++){
            for(int j = 0; j < mapB.size(); j++){
                if(mapA[i].first.second == mapB[j].first.first){
                    C[mapA[i].first.first][mapB[j].first.second] += mapA[i].second * mapB[j].second;
                }
            }
        }
        
        return C;
    }
};
