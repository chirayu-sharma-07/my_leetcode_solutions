class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        if(flowerbed.size()==1){
            if(n>1) return false;
            if(flowerbed[0]==0) return true;
            else return false;
        }
        if(flowerbed.size()==2){
            if(n>1) return false;
            if(flowerbed[0]==0 && flowerbed[1]==0) return true;
            else return false;
        }
        if(flowerbed[0]==0 && flowerbed[1]==0){
            flowerbed[0]=1;
            n--;
        }
        if(n==0) return true;
        if(flowerbed[flowerbed.size()-1]==0 && flowerbed[flowerbed.size()-2]==0){
            flowerbed[flowerbed.size()-1]=1;
            n--;
        }
        if(n==0) return true;
        for(int e=1;n!=0 && e<flowerbed.size()-1;e++){
            if(flowerbed[e]!=1){
                if(flowerbed[e-1]==0 && flowerbed[e+1]==0){
                    flowerbed[e]=1;
                    n--;
                }
            }
        }
        if(n==0) return true;
        return false;
    }
};