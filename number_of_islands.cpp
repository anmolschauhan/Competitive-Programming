// https://leetcode.com/problems/number-of-islands/
// Approach to solution - DFS

class Solution {
public:
    void topol(vector<vector<char>>& grid, int i , int j, int &width, int &len) {
        grid[i][j] = '0';
        
        if(i!=0 && '0' != grid[i-1][j]) {
            topol(grid, i-1, j, width, len);
        }
        if(j!=0 && '0' != grid[i][j-1]) {
            topol(grid, i, j-1, width, len);
        }
        if(i!=len-1 && '0' != grid[i+1][j]) {
            topol(grid, i+1, j, width, len);
        }
        if(j!=width-1 && '0' != grid[i][j+1]) {
            topol(grid, i, j+1, width, len);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) {
            return 0;
        }
        int count = 0, len = grid.size(), width = grid[0].size();
        //cout << len << " " << width << endl;
        unordered_map<int , bool> visited;
        for(int i = 0 ; i < len ; ++i) {
            for(int j = 0 ; j < width ; ++j) {
                if('0' != grid[i][j]) {
                    topol(grid, i, j, width, len);
                    ++count;
                }
            }
        }
        return count;
    }
};
