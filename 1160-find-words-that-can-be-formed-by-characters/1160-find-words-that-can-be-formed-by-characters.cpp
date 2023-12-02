class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int result=0;
        int frequency_array[26];
        for(int e=0;e<26;e++) frequency_array[e]=0;
        int chars_ki_size=chars.size();
        for(int e=0;e<chars_ki_size;e++){
            frequency_array[(int)(chars[e]-97)]++;
        }
        int words_ki_size=words.size();
        for(int e=0;e<words_ki_size;e++){
            string s=words[e];
            int s_ki_size=s.size();
            int small_frequency_array[26];
            for(int e=0;e<26;e++) small_frequency_array[e]=0;
            for(int f=0;f<s_ki_size;f++){
                small_frequency_array[(int)(s[f]-97)]++;
            }
            int f=0;
            for(;f<26;f++){
                if(small_frequency_array[f]>frequency_array[f]) break;
            }
            if(f==26) result+=s_ki_size;
        }
        return result;
    }
};