class Solution {
public:
    string sortVowels(string s) {
        if(s.size()==1) return s;
        int vowelsCountArray[10];
        int stringSize=s.size();
        vector<int> indexes;
        for(int e=0;e<10;e++) vowelsCountArray[e]=0;
        for(int e=0;e<stringSize;e++){
            if(s.at(e)=='A' || s.at(e)=='E' || s.at(e)=='I' || s.at(e)=='O' || s.at(e)=='U' || s.at(e)=='a' || s.at(e)=='e' || s.at(e)=='i' || s.at(e)=='o' || s.at(e)=='u'){
                indexes.push_back(e);
                if(s.at(e)=='A') vowelsCountArray[0]++;
                else if(s.at(e)=='E') vowelsCountArray[1]++;
                else if(s.at(e)=='I') vowelsCountArray[2]++;
                else if(s.at(e)=='O') vowelsCountArray[3]++;
                else if(s.at(e)=='U') vowelsCountArray[4]++;
                else if(s.at(e)=='a') vowelsCountArray[5]++;
                else if(s.at(e)=='e') vowelsCountArray[6]++;
                else if(s.at(e)=='i') vowelsCountArray[7]++;
                else if(s.at(e)=='o') vowelsCountArray[8]++;
                else if(s.at(e)=='u') vowelsCountArray[9]++;
            }
        }
        int indexesSize=indexes.size();
        for(int e=0,f=0;e<indexesSize;e++){
            if(vowelsCountArray[f]!=0){
                char c;
                if(f==0) c='A';
                else if(f==1) c='E';
                else  if(f==2) c='I';
                else  if(f==3) c='O';
                else  if(f==4) c='U';
                else  if(f==5) c='a';
                else  if(f==6) c='e';
                else  if(f==7) c='i';
                else  if(f==8) c='o';
                else  if(f==9) c='u';
                s.at(indexes[e])=c;
                vowelsCountArray[f]--;
            }else{
                f++;
                e--;
            }
        }
        return s;
    }
};