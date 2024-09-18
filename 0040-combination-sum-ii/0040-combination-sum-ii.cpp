class Solution {
public:
    void f(int idx, int target, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds){

        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i =idx; i<nums.size(); i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;
            ds.push_back(nums[i]);
            f(i+1, target - nums[i], nums, ans, ds);
            ds.pop_back();

        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        f(0, target, candidates, ans, ds);
        return ans;
    }
};