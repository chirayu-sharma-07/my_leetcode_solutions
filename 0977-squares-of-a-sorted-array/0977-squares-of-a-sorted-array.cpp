class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        // First Approach

        /*
        vector<int> array_for_negative_values;
        int n=nums.size();
        int e=0;
        for(;e<n && nums[e]<0;e++){
            array_for_negative_values.push_back(nums[e]*nums[e]);
        }
        if(e==n){
            sort(begin(array_for_negative_values),end(array_for_negative_values));
            return array_for_negative_values;
        }
        int f=e;
        while(e<n){
            nums[e]=nums[e]*nums[e];
            e++;
        }
        if(array_for_negative_values.size()==0) return nums;
        int m=array_for_negative_values.size();
        e=m-1;
        int g=0;
        for(;e>=0 && f<n;g++){
            if(nums[f]<array_for_negative_values[e]){
                nums[g]=nums[f];
                f++;
            }else{
                nums[g]=array_for_negative_values[e];
                e--;
            }
        }
        while(e>=0){
            nums[g]=array_for_negative_values[e];
            g++;
            e--;
        }
        while(f<n){
            nums[g]=nums[f];
            g++;
            f++;
        }
        return nums;
        */

        // Second approach

        /*
        int n=nums.size();
        for(int e=0;e<n;e++){
            nums[e]=nums[e]*nums[e];
        }
        sort(begin(nums),end(nums));
        return nums;
        */

        // Third approach

        int last_indexed_negative_number=-1;
        int n=nums.size();
        int e=0;
        for(;e<n;e++){
            if(nums[e]>=0){
                break;
            }
            nums[e]=nums[e]*nums[e];
        }
        while(e<n){
            nums[e]=nums[e]*nums[e];
            e++;
        }
        sort(begin(nums),end(nums));
        return nums;
        if(last_indexed_negative_number==-1 || last_indexed_negative_number==0) return nums;
        e=0;
        while(e<last_indexed_negative_number){
            int g=nums[e];
            nums[e]=nums[last_indexed_negative_number];
            nums[last_indexed_negative_number]=g;
            e++;
            last_indexed_negative_number--;
        }
        return nums;
    }
};