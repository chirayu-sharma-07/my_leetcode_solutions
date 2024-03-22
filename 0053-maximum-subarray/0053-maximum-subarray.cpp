class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
        int n=nums.size();
        int result=INT_MIN;
        int sum=0;
        for(int e=0;e<n;e++){
            sum+=nums[e];
            if(sum>result) result=sum;
            if(sum<0) sum=0;
        }
        return result;
        */

        int n=nums.size();
        int left_index=-1;
        int right_index=-1;
        int result=INT_MIN;
        int sum=0;
        for(int e=0;e<n;e++){
            if(sum==0){
                left_index=e;
            }
            sum+=nums[e];
            if(result<sum){
                right_index=e;
                result=sum;
            }
            if(sum<0) sum=0;
        }
        while(left_index<=right_index){
            cout<<nums[left_index]<<endl;
            left_index++;
        }
        return result;
    }
};