class Solution {
public:
    int countPalindromicSubsequence(string s) {
        set<char> mySet;
        int result;
        int string_size=s.size();
        for(char stringCharacter:s){
            if(mySet.find(stringCharacter)==mySet.end()) mySet.insert(stringCharacter);
        }
        for(char setCharacter:mySet){
            int first_position_of_character=0;
            int last_position_of_character=string_size-1;
            set<char> sub_set_of_my_set;
            for(int e=0;e<string_size;e++){
                if(s[e]==setCharacter){
                    first_position_of_character=e;
                    break;
                }
            }
            for(int e=string_size-1;e>=0;e--){
                if(s[e]==setCharacter){
                    last_position_of_character=e;
                    break;
                }
            }
            if(first_position_of_character!=last_position_of_character){
                first_position_of_character++;
                while(first_position_of_character<last_position_of_character){
                    char e=s[first_position_of_character];
                    if(sub_set_of_my_set.find(e)==sub_set_of_my_set.end()) sub_set_of_my_set.insert(e);
                    first_position_of_character++;
                }
                cout<<sub_set_of_my_set.size()<<endl;
                result+=sub_set_of_my_set.size();
            }
            mySet.erase(setCharacter);
        }
        return result;
    }
};