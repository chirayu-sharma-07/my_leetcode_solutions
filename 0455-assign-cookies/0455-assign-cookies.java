class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int n=g.length;
        int m=s.length;
        int e=0;
        for(int f=0;e<n && f<m;f++){
            if(g[e]<=s[f]) e++;
        }
        return e;
    }
}