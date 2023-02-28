class Solution {
    public int findLucky(int[] arr) {
        int largest=Integer.MIN_VALUE;
        for(int e=0;e<arr.length;e++){
            if(arr[e]>largest) largest=arr[e];
        }
        int[] myArray=new int[largest+1];
        for(int e=0;e<myArray.length;e++) myArray[e]=0;
        for(int e=0;e<arr.length;e++){
            myArray[arr[e]]++;
        }
        for(int e=myArray.length-1;e>0;e--){
            if(myArray[e]==e) return e;
        }
        return -1;
    }
}