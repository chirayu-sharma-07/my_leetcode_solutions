class Solution {
public:
    int n=0;
    string temp="";
    void myFunction(string &s){
        int pos=s.find(temp);
        if(pos!=string::npos){
            s.erase(pos,n);
            myFunction(s);
        }else return;
    }
    string removeOccurrences(string s, string part) {

        // First approach

        /*
        int n=s.size();
        int m=part.size();
        string temp="";
        for(int e=0;e<n;e++){
            temp+=s[e];
            if(temp.size()>=m && temp.substr(temp.size()-m)==part){
                int f=m;
                while(f--) temp.pop_back();
            }
        }
        return temp;
        */

        // Second approach

        /*
        int pos=s.find(part);
        int n=part.size();
        while(pos!=string::npos){
            s.erase(pos,n);
            pos=s.find(part);
        }
        return s;
        */

        n=part.size();
        temp=part;
        myFunction(s);
        return s;
    }
};