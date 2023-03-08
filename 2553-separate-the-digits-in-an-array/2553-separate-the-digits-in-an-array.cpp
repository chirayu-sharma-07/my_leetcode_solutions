class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        for(int e=0;e<nums.size();e++){
            int num=nums[e];
            int multiplier=1;
            while(num>9){
                multiplier*=10;
                num/=10;
            }
            num=nums[e];
            while(multiplier!=0){
                result.push_back(num/multiplier);
                num=num-((num/multiplier)*multiplier);
                multiplier/=10;
            }
        }
        return result;
    }
};