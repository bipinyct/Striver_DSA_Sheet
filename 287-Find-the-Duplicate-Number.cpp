class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!= fast);

        fast = nums[0];

        while(slow!= fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

    // unordered_map<int, int> mp;
    //     int i;

    //     for(i=0; i<nums.size(); i++){
    //         mp[nums[i]]++;
    //     }
    //     for(auto it:mp){
    //         if(it.second > 1) return it.first;
    //     }
    //     return -1;