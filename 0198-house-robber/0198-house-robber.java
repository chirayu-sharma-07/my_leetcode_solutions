class Solution {
    public int rob(int[] nums) {
        if(nums.length==1) return nums[0];
        if(nums.length==2) return (nums[0]<nums[1])?nums[1]:nums[0];
        /*
        int a=nums[0];
        int b=nums[1];
        int n=nums.length;
        for(int e=2;e<n-1;e+=2){
            nums[e]=nums[e]+a;
            a=nums[e];
            nums[e+1]=nums[e+1]+b;
            b=nums[e+1];
        }
        if(n%2==1) nums[n-1]+=a;
        return (nums[n-1]<nums[n-2])?nums[n-2]:nums[n-1];
        */

        int n=nums.length;
        int a=0;
        int b=nums[0];
        int c=0;
        for(int e=2;e<=n;e++){
            c=(nums[e-1]+a<b)?b:nums[e-1]+a;
            a=b;
            b=c;
        }
        return c;
    }
}