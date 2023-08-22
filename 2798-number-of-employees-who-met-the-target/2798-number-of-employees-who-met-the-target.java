class Solution {
    public int numberOfEmployeesWhoMetTarget(int[] hours, int target) {
        int result=0;
        for(int e=0;e<hours.length;e++){
            if(hours[e]>=target) result++;
        }
        return result;
    }
}