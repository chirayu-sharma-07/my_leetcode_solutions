class Solution {
    public int[] rearrangeArray(int[] nums) {
        int[] result=new int[nums.length];
        for(int e=0,f=0,i=0,j=1;e<nums.length;i+=2,j+=2,e++,f++){
            while(e<nums.length && nums[e]<0) e++;
            if(e==nums.length) break;
            while(f<nums.length && nums[f]>=0) f++;
            if(f==nums.length) break;
            result[i]=nums[e];
            result[j]=nums[f];
        }
        return result;
    }
}