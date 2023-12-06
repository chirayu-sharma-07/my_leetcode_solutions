class Solution {
public:
    int rob(vector<int>& nums) {
        //Bottom up approach (Dynamic Programming)
        if(nums.size()==1) return nums[0];
        int arr[nums.size()+1];
        for(int e=0;e<=nums.size();e++) arr[e]=0;
        arr[0]=0;
        arr[1]=nums[0];
        for(int e=2;e<=nums.size();e++){
            int take=nums[e-1]+arr[e-2];
            int skip=arr[e-1];
            arr[e]=max(take,skip);
        }
        return arr[nums.size()];
    }
};