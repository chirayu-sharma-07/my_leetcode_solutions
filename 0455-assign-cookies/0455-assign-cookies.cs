public class Solution {
    public int FindContentChildren(int[] g, int[] s) {
        Array.Sort(g);
        Array.Sort(s);
        int n=g.Length;
        int m=s.Length;
        int e=0;
        for(int f=0;e<n && f<m;f++){
            if(g[e]<=s[f]) e++;
        }
        return e;
    }
}