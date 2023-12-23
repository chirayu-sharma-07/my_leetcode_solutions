class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // Brute force TLE
        /*
        int n=nums.size();
        for(int e=0;e<n;e++){
            for(int f=e+1;f<n;f++){
                if(nums[e]<nums[f]){
                    for(int g=e+1;g<f;g++){
                        if(nums[e]<nums[g] && nums[g]>nums[f]) return true;
                    }
                }
            }
        }
        return false;
        */

        // Second approach

        int n=nums.size();
        int num3=INT_MIN;
        stack<int> st;
        for(int e=n-1;e>=0;e--){
            if(nums[e]<num3) return true;
            while(!st.empty() && st.top()<nums[e]){
                num3=st.top();
                st.pop();
            }
            st.push(nums[e]);
        }
        return false;
    }
};