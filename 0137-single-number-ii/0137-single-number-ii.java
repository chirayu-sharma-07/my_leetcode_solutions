class Solution {
    public int singleNumber(int[] nums) {
        if(nums.length==1) return nums[0];
        Arrays.sort(nums);
        for(int e=0;e<nums.length-2;e+=3){
            if(nums[e]!=nums[e+1]) return nums[e];
        }
        return nums[nums.length-1];
    }
}