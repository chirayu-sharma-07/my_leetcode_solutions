class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);
        for(int e=0,f=0,g=1;e<n;e++){
            if(nums[e]<0){
                result[g]=nums[e];
                g+=2;
            }else{
                result[f]=nums[e];
                f+=2;
            }
        }
        return result;
    }
};