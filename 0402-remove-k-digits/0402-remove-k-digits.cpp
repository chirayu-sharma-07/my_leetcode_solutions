class Solution {
public:
    string removeKdigits(string nums, int k) {
        if(k==nums.size()) return "0";
        stack<int> st;
        int n=nums.size();
        for(int e=0;e<n;e++){
            int num=nums[e]-'0';
            if(k==0){
                while(e<n){
                    st.push(nums[e]-'0');
                    e++;
                }
                break;
            }else if(st.empty() || num>=st.top()){
                st.push(num);
            }else{
                while(k!=0 && !st.empty() && st.top()>num){
                    st.pop();
                    k--;
                }
                st.push(num);
            }
        }
        while(k>0){
            st.pop();
            k--;
        }
        nums="";
        while(!st.empty()){
            nums+=to_string(st.top());
            st.pop();
        }
        for(int e=0,f=nums.size()-1;e<f;e++,f--){
            char g=nums[e];
            nums[e]=nums[f];
            nums[f]=g;
        }
        int e=0;
        while(e<nums.size() && nums[e]=='0') e++;
        if(e==nums.size()) return "0";
        return nums.substr(e);
    }
};