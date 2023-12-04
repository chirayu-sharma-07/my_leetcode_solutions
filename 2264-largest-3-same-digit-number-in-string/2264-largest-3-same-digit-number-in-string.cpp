class Solution {
public:
    string largestGoodInteger(string num) {
        int largest=0;
        string result="";
        int num_size=num.size();
        int flag=0;
        for(int e=0;e<num_size-2;e++){
            string s="";
            if(num[e]==num[e+1] && num[e]==num[e+2]){
                s+=num[e];
                s+=s;
                s+=num[e];
                if(s=="000") flag=1;
                if(largest<(stoi(s))) largest=(stoi(s));
            }
        }
        if(largest==0){
            if(flag==1) result+="000";
        }else{
            result+=to_string(largest);
        }
        return result;
    }
};