class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest=INT_MIN;
        int n=nums.size();
        int largestIndex=-1;
        for(int e=0;e<n;e++){
            if(nums[e]>largest){
                largest=nums[e];
                largestIndex=e;
            }
        }
        for(int e=0;e<n;e++){
            if(nums[e]==largest && e!=largestIndex) return (largest-1)*(largest-1);
        }
        int secondLargest=INT_MIN;
        for(int e=0;e<n;e++){
            if(nums[e]>secondLargest && nums[e]<largest) secondLargest=nums[e];
        }
        return (largest-1)*(secondLargest-1);
    }
};