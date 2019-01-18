# https://leetcode.com/problems/pour-water/

class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        
        while(V--)
        {
            int i = K;
            for(int j = K-1; j >= 0; j--)
            {
                if(heights[i] < heights[j])
                    break;
                else if(heights[j] < heights[i]) 
                    i = j;
            }
            
            if(i == K)
            {
                for(int j = K+1; j < heights.size(); j++)
                {
                    if(heights[j] > heights[i])
                        break;
                    else if(heights[j] < heights[i]) 
                        i = j;
                }
            }
            
            heights[i]++;
        }
        
        return heights;
    }
};
