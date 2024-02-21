class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift_count=0;
        while(left!=right){
            left=(left>>1);
            right=(right>>1);
            shift_count++;
        }
        return (right<<shift_count);
    }
};