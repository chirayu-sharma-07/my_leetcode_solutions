class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s=to_string(1);
        int count=2;
        vector<int> result;
        while(true){
            if(count==10) break;
            s+=to_string(count);
            string temp_string=s;
            int temp_count=count;
            while(true){
                temp_count++;
                if(temp_count==11) break;
                int e=stoi(temp_string);
                if(e>=low && e<=high) result.push_back(e);
                temp_string=temp_string.substr(1);
                temp_string+=to_string(temp_count);
            }
            count++;
        }
        return result;
    }
};