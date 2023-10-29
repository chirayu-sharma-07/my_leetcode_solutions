class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int noOfTrials=(minutesToTest/minutesToDie)+1;
        int result=0;
        while(pow(noOfTrials,result)<buckets) result++;
        return result;
    }
};