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