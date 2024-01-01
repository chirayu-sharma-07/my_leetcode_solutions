/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var findContentChildren = function(g, s) {
    g.sort((a,b)=>a-b);
    s.sort((a,b)=>a-b);
    let n=g.length;
    let m=s.length;
    let e=0;
    for(let f=0;e<n && f<m;f++){
        if(g[e]<=s[f]) e++;
    }
    return e;
};