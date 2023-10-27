class Solution {
private:
    vector<int> expandAroundCentre(string s,int e,int f){
        while(e>=0 && f<s.size() && s.at(e)==s.at(f)){
            e--;
            f++;
        }
        return {e+1,f-1};
    }
public:
    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        vector<int> resultantSubstringIndices={0,0};
        for(int e=0;e<s.size();e++){
            vector<int> palindromicSubstringIndices=expandAroundCentre(s,e,e);
            if((palindromicSubstringIndices[1]-palindromicSubstringIndices[0])>(resultantSubstringIndices[1]-resultantSubstringIndices[0])){
                resultantSubstringIndices=palindromicSubstringIndices;
            }
            if(e+1<s.size() && s.at(e)==s.at(e+1)){
                vector<int> evenLengthPalindromicSubstringIndices=expandAroundCentre(s,e,e+1);
                if(evenLengthPalindromicSubstringIndices[1]-evenLengthPalindromicSubstringIndices[0]>resultantSubstringIndices[1]-resultantSubstringIndices[0]){
                    resultantSubstringIndices=evenLengthPalindromicSubstringIndices;
                }
            }
        }
        return s.substr(resultantSubstringIndices[0],resultantSubstringIndices[1]-resultantSubstringIndices[0]+1);
    }
};