class Solution(object):
    def findContentChildren(self, g, s):
        g.sort()
        s.sort()
        n=len(g)
        m=len(s)
        e=0
        f=0
        while e<n and f<m:
            if(g[e]<=s[f]):
                e+=1
            f+=1
        return e
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        