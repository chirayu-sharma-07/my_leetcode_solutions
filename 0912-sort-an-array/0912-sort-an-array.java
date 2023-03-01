class Solution {
    public static void conquer(int[] nums,int e,int mid, int f){
        int[] myArray=new int[(f-e)+1];
        int i=e;
        int j=mid+1;
        int k=0;
        while(i<=mid && j<=f){
            if(nums[i]<nums[j]){
                myArray[k]=nums[i];
                i++;
            }else{
                myArray[k]=nums[j];
                j++;
            }
            k++;
        }
        while(i<=mid){
            myArray[k]=nums[i];
            i++;
            k++;
        }
        while(j<=f){
            myArray[k]=nums[j];
            k++;
            j++;
        }
        for(int x=0;x<myArray.length;x++,e++) nums[e]=myArray[x];
    }
    public static void divide(int[] nums,int e,int f){
        if(e>=f) return;
        int mid=e+((f-e)/2);
        divide(nums,e,mid);
        divide(nums,mid+1,f);
        conquer(nums,e,mid,f);
    }
    public int[] sortArray(int[] nums) {
        divide(nums,0,nums.length-1);
        return nums;
    }
}