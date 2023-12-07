class Solution {
    public String largestOddNumber(String num) {
        int n=num.length();
        int e=n-1;
        while(e>=0 && (int)(num.charAt(e))%2==0) e--;
        if(e==-1) return "";
        return num.substring(0,e+1);
    }
}