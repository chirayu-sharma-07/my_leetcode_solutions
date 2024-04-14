class Solution {
public:
    bool isPrime(int num) {
        if(num<=1){
            return false;
        }
        for(int e=2;e*e<=num;e++) {
            if(num%e==0) {
                return false;
            }
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int n=nums.size();
        int e=0;
        while(e<n){
            if(isPrime(nums[e])) break;
            e++;
        }
        n--;
        while(n>=0){
            if(isPrime(nums[n])) break;
            n--;
        }
        return n-e;
    }
};