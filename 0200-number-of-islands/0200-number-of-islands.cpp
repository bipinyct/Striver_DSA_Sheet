class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1; // starting point
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // traverse in the neighbours and mark them in vis
            for (int deltarow = -1; deltarow <= 1; deltarow++) {
                for (int deltacol = -1; deltacol <= 1; deltacol++) {
                    int nrow = row + deltarow; // neighbour_row
                    int ncol = col + deltacol; // neighbour_col
                    // check for out of bound cases - abs waali condition
                    // striver missed
                    if ((abs(deltarow - deltacol) == 1) && nrow >= 0 &&
                        nrow < n && ncol >= 0 && ncol < m &&
                        grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0) {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    count++;
                    bfs(row, col, grid, vis);
                }
            }
        }
        return count;
    }
};