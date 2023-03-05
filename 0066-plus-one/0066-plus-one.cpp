class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size()-1]<9){
            digits[digits.size()-1]++;
            return digits;
        }
        int f=digits.size()-1;
        while(f!=-1 && digits[f]==9) f--;
        vector<int> result;
        if(f==-1){
            result.push_back(1);
            for(int e=0;e<digits.size();e++) result.push_back(0);
        }else{
            for(int e=0;e<f;e++) result.push_back(digits[e]);
            result.push_back(digits[f]+1);
            while(f<digits.size()-1){
                result.push_back(0);
                f++;
            }
        }
        return result;
    }
};