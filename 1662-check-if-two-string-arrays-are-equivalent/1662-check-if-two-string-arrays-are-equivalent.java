class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        String s1="";
        String s2="";
        int word_one_size=word1.length;
        int word_two_size=word2.length;
        for(int e=0;e<word_one_size;e++){
            s1=s1.concat(word1[e]);
        }
        for(int e=0;e<word_two_size;e++){
            s2=s2.concat(word2[e]);
        }
        if(s1.equals(s2)) return true;
        return false;
    }
}