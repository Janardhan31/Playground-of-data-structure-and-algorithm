class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // brute force approach
        // for(int i =0;i<=nums.size()-1;i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]+nums[j]==target){
        //             return {i,j};
        //         }
        //     }
        // }
        // return {};

        // two pointer approach
        // sort(nums.begin(),nums.end());
        // int start = 0;
        // int end = nums.size()-1;
        // while(start<end){
        //     int sum = nums[start]+nums[end];
        //     if(sum<target){
        //         start++;
        //     }
        //     if(sum>target){
        //         end--;
        //     }
        //     else{
        //         return{nums[start],nums[end]};
        //     }
        // }
        // return {};
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if (mp.find(need) != mp.end()) {
                return {mp[need], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};