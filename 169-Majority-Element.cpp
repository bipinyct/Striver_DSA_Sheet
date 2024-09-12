class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int cnt = 0;
        
        // First pass: Boyer-Moore Voting Algorithm to find the majority candidate
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {
                ele = nums[i];
                cnt = 1;
            } else if (nums[i] == ele) {
                cnt++;
            } else {
                cnt--;
            }
        }
        
        // Second pass: Verify if the candidate is actually the majority element
        int cnt1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == ele) cnt1++;
        }
        
        if (cnt1 > nums.size() / 2) {
            return ele;  // The candidate is indeed the majority element
        } else {
            return -1;  // No majority element (in case it's not guaranteed by the problem)
        }
    }
};
