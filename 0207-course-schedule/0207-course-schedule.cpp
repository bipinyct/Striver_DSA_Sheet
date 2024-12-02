class Solution {
public:
    bool topologicalsort(int n, vector<vector<int>>& adj, vector<int>& indegree) {
        queue<int> q;
        int count = 0;

        // Add all nodes with 0 indegree to the queue
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                count++;
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // Decrease the indegree of all neighbors
            for (int &v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                    count++;
                }
            }
        }

        // If all nodes are processed, return true
        return count == n;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create an adjacency list and indegree array
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build the graph and calculate indegrees
        for (auto& edge : prerequisites) {
            int a = edge[0];
            int b = edge[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        // Perform topological sort using Kahn's Algorithm
        return topologicalsort(numCourses, adj, indegree);
    }
};
