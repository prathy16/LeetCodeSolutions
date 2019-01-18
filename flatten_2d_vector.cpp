// https://leetcode.com/problems/flatten-2d-vector/

// Solution from https://leetcode.com/problems/flatten-2d-vector/discuss/67652/7-9-lines-added-Java-and-C%2B%2B-O(1)-space.

class Vector2D {
    vector<vector<int>>::iterator iBegin, iEnd;
    int col = 0;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        iBegin = vec2d.begin();
        iEnd   = vec2d.end(); 
    }

    int next() {
        return (*iBegin)[col++];
        
    }

    bool hasNext() {
        while(iBegin != iEnd && col == (*iBegin).size()) 
            iBegin++, col = 0;

        return iBegin != iEnd;
    }

};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
