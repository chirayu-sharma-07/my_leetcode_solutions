class Solution {
public:
    int minimumPushes(string word) {
        vector<int> frequency(26,0);
        int n=word.size();
        for(int e=0;e<n;e++){
            frequency[word[e]-'a']++;
        }
        sort(begin(frequency),end(frequency),[](int a,int b){return a>b;});
        int e=0;
        int result=0;
        while(e<8 && frequency[e]!=0){
            result+=frequency[e];
            e++;
        }
        if(e<8) return result;
        while(e<16 && frequency[e]!=0){
            result+=(frequency[e]*2);
            e++;
        }
        if(e<16) return result;
        while(e<24 && frequency[e]!=0){
            result+=(frequency[e]*3);
            e++;
        }
        if(e<24) return result;
        if(frequency[e]!=0) result+=(frequency[e]*4);
        e++;
        if(frequency[e]!=0) result+=(frequency[e]*4);
        return result;
    }
};