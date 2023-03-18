class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> set=new HashSet<>();
        int length=0;
        int e=0;
        for(int f=0;f<s.length();f++){
            if(set.contains(s.charAt(f))){
                while(!(s.charAt(f)==s.charAt(e))){
                    set.remove(s.charAt(e));
                    e++;
                }
                set.remove(s.charAt(e));
                e++;
                set.add(s.charAt(f));
            }else{
                set.add(s.charAt(f));
                length=Math.max(length,f-e+1);
            }
        }
        return length;
    }
}