int findContentChildren(int* g, int gSize, int* s, int sSize) {
    int e=0;
    int f=0;
    for(;e<gSize-1;e++){
        for(f=e+1;f<gSize;f++){
            if(g[e]>g[f]){
                int h=g[e];
                g[e]=g[f];
                g[f]=h;
            }
        }
    }
    for(e=0;e<sSize-1;e++){
        for(f=e+1;f<sSize;f++){
            if(s[e]>s[f]){
                int h=s[e];
                s[e]=s[f];
                s[f]=h;
            }
        }
    }
    e=0;
    f=0;
    while(e<gSize && f<sSize){
        if(g[e]<=s[f]) e++;
        f++;
    }
    return e;
}