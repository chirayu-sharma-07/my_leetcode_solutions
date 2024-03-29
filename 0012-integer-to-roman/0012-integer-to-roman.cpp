class Solution {
public:

    // Approach one
    // Brute force approach
    // But still having better space and time complexity

    /*
    string result="";
    int digit_count_four_hai(int num){
        while(num/1000!=0){
            num=num-1000;
            result+='M';
        }
        return num;
    }
    int digit_count_three_hai(int num){
        int number=num/100;
        if(number==9){
            num-=900;
            result+='C';
            result+='M';
            return num;
        }else if(number==4){
            num-=400;
            result+='C';
            result+='D';
            return num;
        }else{
            while(num/100!=0){
                if(num/100>=5){
                    num-=500;
                    result+='D';
                }else{
                    num-=100;
                    result+='C';
                }
            }
        }
        return num;
    }
    int digit_count_two_hai(int num){
        int number=num/10;
        if(number==9){
            num-=90;
            result+='X';
            result+='C';
            return num;
        }else if(number==4){
            num-=40;
            result+='X';
            result+='L';
            return num;
        }else{
            while(num/10!=0){
                if(num/10>=5){
                    num-=50;
                    result+='L';
                }else{
                    num-=10;
                    result+='X';
                }
            }
        }
        return num;
    }
    int digit_count_one_hai(int num){
        if(num==9){
            num-=9;
            result+='I';
            result+='X';
            return num;
        }else if(num==4){
            num-=4;
            result+='I';
            result+='V';
            return num;
        }else{
            while(num!=0){
                if(num>=5){
                    num-=5;
                    result+='V';
                }else{
                    num-=1;
                    result+='I';
                }
            }
        }
        return num;
    }
    string intToRoman(int num) {
        while(num!=0){
            if(num/1000!=0)
            {
                num=digit_count_four_hai(num);
            }
            else if(num/100!=0)
            {
                num=digit_count_three_hai(num);
            }
            else if(num/10!=0)
            {
                num=digit_count_two_hai(num);
            }
            else
            {
                num=digit_count_one_hai(num);
            }
        }
        return result;
    }
    */


    // Approach two
    // Simple approach
    
    string intToRoman(int num){
        static vector<int> myInteger{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        static vector<string> myString{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string result="";
        for(int e=0;e<13;e++){
            int times=num/myInteger[e];
            while(times--){
                result+=myString[e];
                num=num%myInteger[e];
            }
        }
        return result;
    }
};