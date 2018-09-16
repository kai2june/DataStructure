#include<stdio.h>
#include<limits.h>

int rangeBitwiseAnd(int m, int n) {
    unsigned int mask = INT_MAX;
    for( ; m<=n; m++)
        mask &= m;
    
    return mask;
}

int main(int argc, char* argv[]){
    
    int rlt = rangeBitwiseAnd(5,7);
    printf("%d\n", rlt);

    return 0;
}