class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> data(n+2, 0);
        for(auto x : edges){
            data[x[0]]++;
            data[x[1]]++;
        }

        for(int i=1; i<=n+1; i++){
            if(data[i] == edges.size()) return i;
        }
        return -1;
    }
};