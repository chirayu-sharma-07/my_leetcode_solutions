class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // First approach

        /*
        int result=INT_MIN;
        int sub_result=0;
        int n=nums.size();
        for(int e=0;e<n;e++){
            sub_result+=nums[e];
            if(result<sub_result) result=sub_result;
            if(sub_result<0) sub_result=0;
        }
        return result;
        */

        // Follow-up question (Print the elements of array having the largest sum)

        int n=nums.size();
        int result=INT_MIN;
        int sub_result=0;
        int startIndex=-1;
        int endIndex=-1;
        for(int e=0;e<n;e++){
            if(sub_result==0) startIndex=e;
            sub_result+=nums[e];
            if(result<sub_result){
                result=sub_result;
                endIndex=e;
            }
            if(sub_result<0) sub_result=0;
        }
        while(startIndex<=endIndex){
            cout<<nums[startIndex]<<endl;
            startIndex++;
        }
        return result;
    }
};