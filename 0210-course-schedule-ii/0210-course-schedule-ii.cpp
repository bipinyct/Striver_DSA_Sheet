class Solution {
public:

    vector<int> topologicalsort(vector<vector<int>>& adj, int n, vector<int>& indegree){
        queue<int> q;

        vector<int> result;
        int count = 0;

        for(int i=0; i<n; i++){
            if(indegree[i] ==0){
                result.push_back(i);
                count++;
                q.push(i);

            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    result.push_back(v);
                    count++;
                    q.push(v);
                }
            }
        }
        if(count == n){
            return result;
        }

        return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(auto &vec : prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        return topologicalsort(adj, numCourses, indegree);
    }
};