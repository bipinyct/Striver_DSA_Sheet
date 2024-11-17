class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;  // Queue to store {{row, col}, time}
        int vis[n][m];  // Visited matrix
        int freshCount = 0;  // To count fresh oranges

        // Initialize the queue with all rotten oranges and set up the vis matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;  // Mark as visited
                } else {
                    vis[i][j] = 0;  // Not visited
                    if (grid[i][j] == 1) {
                        freshCount++;  // Count fresh oranges
                    }
                }
            }
        }

        int tm = 0;  // Time taken to rot all oranges
        int delrow[] = {-1, 0, 1, 0};  // Row direction changes
        int delcol[] = {0, 1, 0, -1};  // Column direction changes

        // Perform BFS
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm, t);  // Update the time

            // Traverse in all four directions
            for (int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                // Check if the new position is within bounds and contains a fresh orange
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});  // Push the new rotten orange with time incremented
                    vis[nrow][ncol] = 2;  // Mark as visited (now rotten)
                    freshCount--;  // Decrease the count of fresh oranges
                }
            }
        }

        // If there are still fresh oranges left, return -1
        if (freshCount > 0) {
            return -1;
        }

        return tm;  // Return the total time taken
    }
};
