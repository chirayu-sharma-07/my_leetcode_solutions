class Solution {
    public int search(int[] nums, int target) {
        if(target<nums[0] && target>nums[nums.length-1]) return -1;
        int e=0;
        int f=nums.length-1;
        while(e<=f){
            int mid=(e+f)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>=nums[0]){
                if(target>=nums[0] && target<=nums[mid]) f=mid-1;
                else e=mid+1;
            }else{
                if(target>=nums[mid] && target<=nums[nums.length-1]) e=mid+1;
                else f=mid-1;
            }
        }
        return -1;
    }
}