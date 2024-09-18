class Solution {
public:
    void f(int idx, int target, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds){

        if(idx == nums.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        //pick
        if(nums[idx] <= target){
            ds.push_back(nums[idx]);
            f(idx, target - nums[idx], nums, ans, ds);
            ds.pop_back();
        }

        //not pick
        f(idx+1, target, nums, ans, ds);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        f(0, target, candidates, ans, ds);
        return ans;
    }
};