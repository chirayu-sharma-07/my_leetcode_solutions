class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int e=0;
        int f=nums.size();
        while(e<f){
            if(nums[e]>0 && nums[e]<=f && nums[nums[e]-1]!=nums[e]){
                int g=nums[nums[e]-1];
                nums[nums[e]-1]=nums[e];
                nums[e]=g;
            }else e++;
        }
        for(e=0;e<f;e++){
            if(nums[e]!=e+1) return e+1;
        }
        return f+1;
    }
};