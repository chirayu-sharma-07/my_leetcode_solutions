class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> vec(31);
        for(auto e:nums){
            int f=0;
            while(e>0){
                int bit=(e&1);
                vec[f]+=bit;
                f++;
                e=(e>>1);
            }
        }
        int ans=0;
        for(int e=0;e<26;e++){
            if((vec[e]%2)==0){
                if(((k>>e)&1)==1){
                    ans++;
                }
            }
            else if(((k>>e)&1)==0) ans++;
        }
        return ans;
    }
};