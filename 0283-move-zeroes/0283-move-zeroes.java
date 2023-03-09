class Solution {
    public void moveZeroes(int[] nums) {
        if(nums.length==1) return;
        int[] temp=new int[nums.length];
        int f=0;
        for(int e=0;e<nums.length;e++){
            if(nums[e]!=0){
                temp[f]=nums[e];
                f++;
            }
        }
        for(;f<nums.length;f++) temp[f]=0;
        for(f=0;f<nums.length;f++) nums[f]=temp[f];
    }
}