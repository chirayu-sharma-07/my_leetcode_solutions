class Solution {
public:
    int heightChecker(vector<int>& heights) {

        // Approach one 

        /*
        vector<int> expected;
        for(int i=0;i<heights.size();i++){
            expected.push_back(heights[i]);
        }
        for(int e=0;e<expected.size()-1;e++){
            for(int f=e+1;f<expected.size();f++){
                if(expected[e]>expected[f]){
                    int g=expected[e];
                    expected[e]=expected[f];
                    expected[f]=g;
                }
            }
        }
        int count=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=expected[i]) count++;
        }
        return count;
        */

        // Approach two

        /*
        int n=heights.size();
        vector<int> expected=heights;
        sort(begin(expected),end(expected));
        int result=0;
        for(int e=0;e<n;e++){
            if(expected[e]!=heights[e]) result++;
        }
        return result;
        */

        // Approach three

        int n=heights.size();
        int largest=INT_MIN;
        for(int e=0;e<n;e++){
            if(heights[e]>largest) largest=heights[e];
        }
        vector<int> frequency(largest+1,0);
        for(int e=0;e<n;e++){
            frequency[heights[e]]++;
        }
        int result=0;
        for(int e=0,f=1;e<n;){
            if(frequency[f]!=0){
                if(heights[e]!=f) result++;
                frequency[f]--;
                e++;
            }else f++;
        }
        return result;
    }
};