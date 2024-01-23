class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int e=0;
        for(int f=0;f<n;f++){
            if(nums[f]!=val){
                nums[e]=nums[f];
                e++;
            }
        }
        return e;
    }
};