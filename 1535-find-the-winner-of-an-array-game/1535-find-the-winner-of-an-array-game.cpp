/*
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int largest=-1;
        for(int e=0;e<arr.size();e++){
            if(arr[e]>largest) largest=arr[e];
        }
        if(k>=arr.size()) return largest;
        int myArray[largest+1];
        for(int e=0;e<=largest;e++){
            myArray[e]=0;
        }
        for(int e=1;e<arr.size();e++){
            if(arr[0]<arr[e]){
                int g=arr[0];
                arr[0]=arr[e];
                arr[e]=g;
            }
            myArray[arr[0]]++;
            if(myArray[arr[0]]==k) return arr[0];
        }
        return arr[0];
    }
};
*/
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k>=arr.size()) return *std::max_element(arr.begin(),arr.end());
        int curr=arr[0];
        int winner=0;
        for(int e=1;e<arr.size();e++){
            if(arr[e]>curr){
                curr=arr[e];
                winner=0;
            }
            if(++winner==k) return curr;
        }
        return curr;
    }
};