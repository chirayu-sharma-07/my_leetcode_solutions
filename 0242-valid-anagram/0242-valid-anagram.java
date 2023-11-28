class Solution {
    public boolean isAnagram(String s, String t) {
        int[] frequency_array=new int[26];
        int s_size=s.length();
        int t_size=t.length();
        s.toUpperCase();
        t.toUpperCase();
        for(int e=0;e<s_size;e++){
            int c=s.charAt(e);
            int f=(int)c;
            f-=97;
            frequency_array[f]++;
        }
        for(int e=0;e<t_size;e++){
            int c=t.charAt(e);
            int f=(int)c;
            f-=97;
            frequency_array[f]--;
        }
        int e=0;
        for(;e<26;e++){
            if(frequency_array[e]!=0) break;
        }
        if(e==26) return true;
        return false;
    }
}