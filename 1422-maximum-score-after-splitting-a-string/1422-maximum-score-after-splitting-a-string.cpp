class Solution {
public:
    int maxScore(string s) {

        // First approach

        /*
        int n=s.size();
        int oneCount=0;
        int zeroCount=0;
        for(int e=0;e<n;e++){
            if(s[e]=='1') oneCount++;
            else zeroCount++;
        }
        if(oneCount==0 || zeroCount==0){
            return (oneCount==0)?zeroCount-1:oneCount-1;
        }
        int e=0;
        int f=n-1;
        while(s[e]=='1') e++;
        while(s[f]=='0') f--;
        if(e>f) return 0;
        int i=e;
        for(;i<=f && s[i]=='0';i++);
        for(;i<=f && s[i]=='1';i++);
        if(i==f+1) return zeroCount+oneCount;
        int result=0;
        for(;e<=f;e++){
            if(s[e]=='0'){
                zeroCount--;
            }else oneCount--;
            result=max(result,zeroCount+oneCount);
        }
        return result;
        */

        // Second approach
        
        /*

        int n=s.size();
        vector<int> trackier(n,0);
        bool isZeroExist=false;
        bool isOneExist=false;
        for(int e=0,count=1;e<n;e++){
            if(s[e]=='0'){
                isZeroExist=true;
                trackier[e]=count;
                count++;
            }
        }
        for(int e=n-1,count=-1;e>=0;e--){
            if(trackier[e]==0){
                isOneExist=true;
                trackier[e]=count;
                count--;
            }
        }
        if(!isZeroExist || !isOneExist){
            return n-1;
        }
        int i=0;
        int onesCount=0;
        int zerosCount=0;
        while(i<n && trackier[i]<0){
            onesCount++;
            i++;
        }
        while(i<n && trackier[i]>0){
            zerosCount++;
            i++;
        }
        if(i==n){
            if(onesCount>zerosCount) return onesCount-1;
            else return zerosCount-1;
        }
        int result=0;
        for(int e=0;e<n-1;e++){
            if(trackier[e]>0 && trackier[e+1]<0){
                result=max(result,((-1)*(trackier[e+1])+trackier[e]));
            }
        }
        return result;
        
        */
        
        //Third approach
        
        int n=s.size();
        int result=INT_MIN;
        for(int e=0;e<n-1;e++){
            int zerosCount=0;
            for(int f=0;f<=e;f++){
                if(s[f]=='0') zerosCount++;
            }
            int onesCount=0;
            for(int f=e+1;f<n;f++){
                if(s[f]=='1') onesCount++;
            }
            result=max(result,zerosCount+onesCount);
        }
        return result;
    }
};