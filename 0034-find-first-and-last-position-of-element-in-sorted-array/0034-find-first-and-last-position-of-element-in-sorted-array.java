class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] result=new int[2];
        result[0]=-1;
        result[1]=-1;
        if(nums.length==0) return result;
        int e=0;
        int f=nums.length-1;
        int mid=0;
        while(e<=f){
            mid=e+((f-e)/2);
            if(target==nums[mid]) break;
            if(target<nums[mid]) f=mid-1;
            else e=mid+1;
        }
        if(target!=nums[mid]) return result;
        e=f=mid;
        while(e>=0 && nums[e]==target) e--;
        e++;
        while(f<nums.length && nums[f]==target) f++;
        f--;
        result[0]=e;
        result[1]=f;
        return result;
    }
}