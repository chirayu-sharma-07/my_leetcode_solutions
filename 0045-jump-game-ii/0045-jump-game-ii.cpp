class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int result=0;
        int e=n-1;
        while(e>0){
            int newIndex=-1;
            int f=e-1;
            while(f>=0){
                if(nums[f]>=e-f){
                    newIndex=f;
                }
                f--;
            }
            e=newIndex;
            result++;
        }
        return result;
    }
};