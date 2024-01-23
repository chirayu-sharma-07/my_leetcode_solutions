class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        // Approach one

        /*
        int n=nums.size();
        int e=0;
        for(int f=0;f<n;f++){
            if(nums[f]!=val){
                nums[e]=nums[f];
                e++;
            }
        }
        return e;
        */

        // Second approach
        
        int n=nums.size();
        int temp=0;
        for(int e=0;e<n;e++){
            if(nums[e]==val){
                temp++;
            }else{
                nums[e-temp]=nums[e];
            }
        }
        return n-temp;
    }
};