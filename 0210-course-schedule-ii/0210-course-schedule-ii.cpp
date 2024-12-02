class Solution {
public:
    vector<int> topologicalsort(vector<vector<int>>& adj, int n, vector<int>& indegree) {
        queue<int> q;
        vector<int> result;
        int count = 0;

        // Push nodes with 0 indegree into the queue
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                result.push_back(i);
                count++;
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int &v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                    result.push_back(v);
                    count++;
                }
            }
        }

        // If we processed all nodes, return the result
        if (count == n) {
            return result;
        }

        // Otherwise, return an empty vector indicating a cycle
        return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        // Build the adjacency list and calculate indegrees
        for (auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        // Perform topological sorting
        return topologicalsort(adj, numCourses, indegree);
    }
};
