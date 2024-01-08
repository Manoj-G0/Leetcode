class Solution {
public:
    long long pow2r(int n){
        int c=0;
        if(n & n&(n-1)){
            c=-1;
        }
        while(n){
            c+=1;
            n>>=1;
        }
        return 1<<c;
    }
    int rangeBitwiseAnd(int left, int right) {
        if(left==0) return 0;
        if(right<=1) return right;
        if(left==right) return left;
        long long powr2=pow2r(right);
        if(powr2>left && powr2<=right) return 0;
        int s=left;
        for(long long i=left+1;i<=right;i++){
            s=s&i;
        }
        return s;
    }
};
