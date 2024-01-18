class Solution {
public:
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
};