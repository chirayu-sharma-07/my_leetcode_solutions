class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        // Brute force approach

        /*
        unordered_map<int,int> um;
        int n=numbers.size();
        for(int e=0;e<n;e++){
            if(um.find(target-numbers[e])==um.end()){
                um[numbers[e]]=e;
            }else return {um[target-numbers[e]]+1,e+1};
        }
        return {-1,-1};
        */

        // Optimized approach
        // Two pointer approach

        int f=numbers.size()-1;
        int e=0;
        while(e<f){
            if(numbers[e]+numbers[f]==target) return {e+1,f+1};
            else if(numbers[e]+numbers[f]<target) e++;
            else f--;
        }
        return {-1,-1};
    }
};