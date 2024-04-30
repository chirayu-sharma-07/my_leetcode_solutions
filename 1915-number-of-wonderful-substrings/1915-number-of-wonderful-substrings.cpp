class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<long long,long long> mp;
        mp[0]=1;
        int cum_xor=0;
        long long result=0;
        for(char &ch:word){
            int shift=ch-'a';
            cum_xor^=(1<<shift);
            result+=mp[cum_xor];
            for(char ch1='a';ch1<='j';ch1++){
                shift=ch1-'a';
                long long check_xor=(cum_xor^(1<<shift));
                result+=mp[check_xor];
            }
            mp[cum_xor]++;
        }
        return result;
    }
};