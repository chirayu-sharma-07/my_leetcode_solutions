class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int[] result=new int[nums.length];
        int e=0;
        for(int f=0;f<nums.length;f++){
            if(nums[f]<pivot){
                result[e]=nums[f];
                e++;
            }
        }
        for(int f=0;f<nums.length;f++){
            if(nums[f]==pivot){
                result[e]=nums[f];
                e++;
            }
        }
        for(int f=0;f<nums.length;f++){
            if(nums[f]>pivot){
                result[e]=nums[f];
                e++;
            }
        }
        return result;
    }
}