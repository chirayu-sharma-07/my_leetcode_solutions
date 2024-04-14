class Solution {
public:
    int dayOfYear(string date) {
        int year,month,day;
        year=stoi(date.substr(0,4));
        month=stoi(date.substr(5,2));
        day=stoi(date.substr(8));
        int result=day;
        int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if(year%4==0 && (year%100!=0 || year%400==0)) months[1]=29;
        month--;
        while(month!=0){
            result+=months[month-1];
            month--;
        }
        return result;
    }
};