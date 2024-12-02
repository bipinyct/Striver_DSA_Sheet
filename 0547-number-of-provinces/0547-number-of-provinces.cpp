class Solution {
public:
    int n;
    void BFS(vector<vector<int>>& isConnected, int u, vector<bool>& visited){
        queue<int> q;
        q.push(u);
        visited[u] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int v=0; v<n; v++){
                if(!visited[v] && isConnected[u][v] == 1){
                    BFS(isConnected, v, visited);
                }

            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();

        vector<bool> visited(n, false);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                BFS(isConnected, i, visited);
                count++;
            }
        }
        return count;
    }
};