class Solution {
public:
    int pivotInteger(int n) {
        int sum_of_all_the_digits_from_one_to_n=0;
        sum_of_all_the_digits_from_one_to_n=(n*(n+1)/2);
        double square_root_of_sum_of_all_the_digits_from_one_to_n=sqrt(sum_of_all_the_digits_from_one_to_n);
        if(square_root_of_sum_of_all_the_digits_from_one_to_n-ceil(square_root_of_sum_of_all_the_digits_from_one_to_n)==0) return (int)square_root_of_sum_of_all_the_digits_from_one_to_n;
        return -1;
    }
};