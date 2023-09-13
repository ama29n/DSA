// https://leetcode.com/problems/rotting-oranges/ 

class Solution {
private:
    vector<int> dir { 0, 1, 0, -1, 0 };
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int freshOranges = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({ i, j });
                } else if(grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }
        if(freshOranges == 0) return 0;
        if(q.empty()) return -1;
        int minutes = -1;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto [i, j] = q.front();
                q.pop();
                for(int d = 0; d < 4; d++) {
                    int x = i + dir[d]; 
                    int y = j + dir[d + 1];
                    if(x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push({ x, y });
                        freshOranges--;
                    }
                }
            }
            minutes++;
        }
        if(freshOranges > 0) return -1;
        return minutes;
    }
};