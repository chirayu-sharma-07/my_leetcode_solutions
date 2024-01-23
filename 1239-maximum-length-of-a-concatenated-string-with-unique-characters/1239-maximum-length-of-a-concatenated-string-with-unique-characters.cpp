class Solution {
public:

    // Approach one
    // Wrong approach because i used set, Instead i should i use temporary string

    /*
    int N=0;
    bool check(string s,unordered_set<char> &mySet){
        string temp_string="";
        int n=s.size();
        for(int e=0;e<n;e++){
            if(mySet.find(s[e])!=mySet.end()) return false;
            else{
                temp_string+=s[e];
            }
        }
        for(int e=0;e<n;e++){
            mySet.insert(temp_string[e]);
        }
        return true;
    }
    int myFunction(vector<string> &arr,int e,unordered_set<char> &mySet){
        if(e>=N) return mySet.size();
        int take=0;
        int skip=0;
        if(check(arr[e],mySet)) take=myFunction(arr,e+1,mySet);
        skip=myFunction(arr,e+1,mySet);
        return max(take,skip);
    }
    int maxLength(vector<string>& arr) {
        unordered_set<char> mySet;
        N=arr.size();
        return myFunction(arr,0,mySet);
    }
    */

    // Approach two

    /*
    int N=0;
    bool check(string s1,string s2){
        int freq[26]={0};
        for(char &ch:s1){
            if(freq[ch-'a']>0) return false;
            freq[ch-'a']++;
        }
        for(char &ch:s2){
            if(freq[ch-'a']>0) return false;
        }
        return true;
    }
    int myFunction(vector<string> &arr,int e,string temp_string){
        if(e>=N) return temp_string.size();
        int take=0;
        int skip=0;
        if(check(arr[e],temp_string)) take=myFunction(arr,e+1,temp_string+arr[e]);
        skip=myFunction(arr,e+1,temp_string);
        return max(take,skip);
    }
    int maxLength(vector<string> &arr){
        N=arr.size();
        return myFunction(arr,0,"");
    }
    */

    // Approach three
    // Recursion + Memoization

    int N=0;
    unordered_map<string,int> myMap;
    bool check(string first,string second){
        int freq[26]={0};
        for(char &ch:first){
            if(freq[ch-'a']!=0) return false;
            freq[ch-'a']++;
        }
        for(char &ch:second){
            if(freq[ch-'a']!=0) return false;
        }
        return true;
    }
    int myFunction(vector<string> &arr,int e,string temp_string){
        if(e>=N) return temp_string.size();
        if(myMap.find(temp_string)!=myMap.end()) return myMap[temp_string];
        int take=0;
        int skip=0;
        if(check(arr[e],temp_string)) take=myFunction(arr,e+1,temp_string+arr[e]);
        skip=myFunction(arr,e+1,temp_string);
        return myMap[temp_string]=(take>skip)?take:skip;
    }
    int maxLength(vector<string> &arr){
        N=arr.size();
        return myFunction(arr,0,"");
    }
};