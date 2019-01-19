// https://leetcode.com/problems/shortest-word-distance/

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int p1 = INT_MAX, p2=INT_MAX;
        int diff = INT_MAX;
        
        for(int i = 0; i < words.size(); i++){
            if(words[i] == word1){
                p1 = i;
                diff = min(diff, abs(p2-p1));
            }
            if(words[i] == word2){
                p2 = i;
                diff = min(diff, abs(p2-p1));
            }
        }
        return diff;
    }
};
