class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result=0;
        for(int e=0;e<nums.size();e++){
            long long zeroCount=0;
            int flag=0;
            while(e<nums.size() && nums[e]==0){
                flag=1;
                zeroCount++;
                e++;
            }
            if(flag==1){
                e--;
                result+=(zeroCount*(zeroCount+1))/2;
            }
        }
        return result;
    }
};