class Solution {
public:
    int myFunction(vector<int> &nums,int left,int right){
        if(left>right) return 0;
        int result=0;
            int mid=left+(right-left)/2;
            int increment=0;
            if(mid-1>=0 && nums[mid]==nums[mid-1]) increment++;
            if(mid+1<nums.size() && nums[mid]==nums[mid+1]) increment++;
            if(increment==0) return nums[mid];
            result+=myFunction(nums,left,mid-1);
            result+=myFunction(nums,mid+1,right);
        return result;
    }
    int singleNonDuplicate(vector<int>& nums) {
        // Brute force approach
        /*
        if(nums.size()==1) return nums[0];
        for(int e=0;e<nums.size()-1;e+=2){
            if(nums[e]!=nums[e+1]) return nums[e];
        }
        if(nums[nums.size()-1]!=nums[nums.size()-2]) return nums[nums.size()-1];
        return 0;
        */

        return myFunction(nums,0,nums.size()-1);
    }
};