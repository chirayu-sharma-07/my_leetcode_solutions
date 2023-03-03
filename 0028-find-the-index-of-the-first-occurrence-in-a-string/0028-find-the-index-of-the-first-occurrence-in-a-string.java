class Solution {
    public int strStr(String haystack, String needle) {
        int result=-1;
        for(int e=0;e<haystack.length();){
            if(haystack.charAt(e)==needle.charAt(0)){
                result=e;
                int f=0;
                for(;e<haystack.length() && f<needle.length();f++,e++){
                    if(haystack.charAt(e)!=needle.charAt(f)) break;
                }
                if(f==needle.length()) return result;
                if(e==haystack.length()) return -1;
                e=result+1;
                result=-1;
            }else e++;
        }
        return result;
    }
}