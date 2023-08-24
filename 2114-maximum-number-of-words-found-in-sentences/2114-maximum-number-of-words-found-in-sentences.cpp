class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int result=0;
        for(int e=0;e<sentences.size();e++){
            string s=sentences[e];
            int count=0;
            for(int f=0;f<s.size();f++){
                if(s[f]==' ') count++;
            }
            if(count>result) result=count;
        }
        return result+1;
    }
};