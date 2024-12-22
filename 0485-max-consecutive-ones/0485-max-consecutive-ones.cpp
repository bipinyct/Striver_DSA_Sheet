class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int sum = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                sum++;
                count = max(sum,count);
            }
            else{
                sum=0;
            }
        }
        return count;
    }
};