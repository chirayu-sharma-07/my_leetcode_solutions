/*
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if(nums.size()==k){
            sort(nums.begin(),nums.end());
            result.push_back(nums[nums.size()-1]);
            return result;
        }
        int x=-1;
        int largest=INT_MIN;
        for(int e=0;e<=(nums.size()-k);e++){
            if(x<e){
                largest=INT_MIN;
                for(int f=e;f<(e+k);f++){
                    if(largest<nums[f]){
                        largest=nums[f];
                        x=f;
                    }
                }
                result.push_back(largest);
            }else{
                int j=(e+k)-1;
                if(nums[j]>largest){
                    x=j;
                    largest=nums[j];
                }
                result.push_back(largest);
            }
        }
        return result;
    }
};
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        deque<int> window;

        for (int i = 0; i < n; i++) {
            while (!window.empty() && window.front() < i - k + 1) {
                window.pop_front();
            }

            while (!window.empty() && nums[window.back()] < nums[i]) {
                window.pop_back();
            }

            window.push_back(i);

            if (i >= k - 1) {
                result.push_back(nums[window.front()]);
            }
        }

        return result;
    }
};