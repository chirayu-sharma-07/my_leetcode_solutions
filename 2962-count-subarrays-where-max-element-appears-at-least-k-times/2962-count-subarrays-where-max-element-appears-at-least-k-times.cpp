class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        // First approach (TLE)

        /*
        int n=nums.size();
        long long result=0;
        int largest=INT_MIN;
        int largest_count=0;
        for(int &e:nums){
            if(e>largest) largest=e;
        }
        for(int &e:nums){
            if(e==largest) largest_count++;
        }
        if(largest_count<k) return 0;
        for(int e=0;e<n;e++){
            int freq=0;
            for(int f=e;f<n;f++){
                if(nums[f]==largest) freq++;
                if(freq>=k) result++;
            }
        }
        return result;
        */

        // Second approach

        /*
        long long result=0;
        int sub_result=0;
        int max_count=0;
        int max_element=INT_MIN;
        for(int &e:nums){
            if(e>max_element) max_element=e;
        }
        int n=nums.size();
        for(int e=0;e<n;e++){
            if(nums[e]==max_element){
                max_count++;
            }
            if(max_count>=k){
                result++;
            }
        }
        if(result==0) return result;
        sub_result=(int)result;
        for(int e=0;e<n;e++){
            if(nums[e]==max_element){
                max_count--;
                sub_result--;
            }
            if(max_count<k) return result;
            result+=sub_result;
        }
        return result;
        */

        // Third approach

        int max_ele=*max_element(begin(nums),end(nums));
        int n=nums.size();
        long long result=0;
        int e=0;
        int f=e;
        int max_element_count=0;
        while(f<n){
            if(nums[f]==max_ele) max_element_count++;
            while(max_element_count>=k){
                result+=(n-f);
                if(nums[e]==max_ele) max_element_count--;
                e++;
            }
            f++;
        }
        return result;
    }
};