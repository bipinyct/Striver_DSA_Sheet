class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int last_int = INT_MIN;
        int longest =1;
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] - 1 == last_int){
                cnt++;
                last_int = nums[i];
            }
            else if (last_int != nums[i]){
                cnt = 1;
                last_int = nums[i];
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};