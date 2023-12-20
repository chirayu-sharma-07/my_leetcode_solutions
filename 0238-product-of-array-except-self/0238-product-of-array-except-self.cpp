class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int e=0;
        int zeroIndex=-1;
        for(;e<n;e++){
            if(nums[e]==0){
                zeroIndex=e;
                break;
            }
        }
        long long multiplication=1;
        if(zeroIndex!=-1){
            for(e=zeroIndex+1;e<n;e++){
                if(nums[e]==0){
                    fill(begin(nums),end(nums),0);
                    return nums;
                }
            }
            for(e=0;e<n;e++){
                if(e==zeroIndex) continue;
                multiplication*=(long long)nums[e];
            }
        }else{
            for(e=0;e<n;e++){
                multiplication*=(long long)nums[e];
            }
        }
        if(zeroIndex!=-1){
            fill(begin(nums),end(nums),0);
            nums[zeroIndex]=(int)multiplication;
            return nums;
        }else{
            for(e=0;e<n;e++){
                nums[e]=(int)multiplication/nums[e];
            }
        }
        return nums;
    }
};