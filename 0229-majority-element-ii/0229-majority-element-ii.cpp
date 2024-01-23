class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int m=n/3;
        vector<int> result;
        sort(begin(nums),end(nums));
        for(int e=0;e<n;e++){
            int num=nums[e];
            e++;
            int count=1;
            while(e<n && nums[e]==num){
                count++;
                e++;
            }
            if(count>m) result.push_back(num);
            e--;
        }
        return result;
    }
};