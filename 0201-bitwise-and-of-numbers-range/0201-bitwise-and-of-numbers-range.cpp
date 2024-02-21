class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

        // First approach

        /*
        int shift_count=0;
        while(left!=right){
            left=(left>>1);
            right=(right>>1);
            shift_count++;
        }
        return (right<<shift_count);
        */

        // Second approach

        while(right>left) right=(right)&(right-1);
        return right;
    }
};