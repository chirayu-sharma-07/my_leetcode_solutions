class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int result=0;
        for(int e=0;e<nums.size();){
            int f=nums[e];
            e++;
            int count=1;
            while(e<nums.size() && f==nums[e]){
                count++;
                e++;
            }
            if(count==1) result+=f;
        }
        return result;
    }
};