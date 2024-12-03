class Solution {
public:

    bool checkbipartiteDFS(vector<vector<int>>& graph, int curr, vector<int>& color, int currcolor){
        color[curr] = currcolor;

        for(int &v : graph[curr]){
            if(color[v] == color[curr]){
                return false;
            }

            if(color[v] == -1){
                int colorofV = 1 - currcolor;

                if(checkbipartiteDFS(graph, v, color, colorofV) == false){
                    return false;
                }
            }
        }
        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(checkbipartiteDFS(graph, i, color, 1) == false){
                    return false;
                }
            }
        }
        return true;
    }
};