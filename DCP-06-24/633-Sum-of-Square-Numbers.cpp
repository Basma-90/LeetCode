class Solution {
public:
    bool check_square(long long n){
        int x=sqrt(n);
        if(x*x==n){
            return true;
        }
        return false;
    }
    bool judgeSquareSum(int c) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        long long x=sqrt(c);
        for(int i=0;i<=x;++i){
            if(check_square(c-(i*i)) && check_square(i*i)){
                return true;
            }
        }

        return false;
    }
};