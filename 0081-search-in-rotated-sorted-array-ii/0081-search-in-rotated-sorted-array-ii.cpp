class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int e=0;
        int f=nums.size()-1;
        while(e<=f){
            int mid=e+(f-e)/2;
            if(target==nums[mid]) return true;
            if(nums[mid]==nums[e] && nums[mid]==nums[f]){
                e++;f--;
            }else{
                if(nums[e]<=nums[mid]){
                if(nums[e]<=target && nums[mid]>target) f=mid-1;
                else e=mid+1;
                }else{
                  if(nums[mid]<target && nums[f]>=target) e=mid+1;
                  else f=mid-1;  
                }
            }
        }
        return false;
    }
};