class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        // Find the largest index `idx` such that nums[idx] < nums[idx + 1]
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        // If no such index exists, reverse the array (which means we are at the last permutation)
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find the largest index `i` greater than `idx` such that nums[i] > nums[idx]
        for(int i = n - 1; i > idx; i--) {
            if(nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }

        // Reverse the subarray nums[idx + 1] to the end to get the next lexicographical permutation
        reverse(nums.begin() + idx + 1, nums.end());
    }
};
