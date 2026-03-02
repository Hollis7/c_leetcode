#include <stdio.h>
int main()
{
    long mval = 3833;
    int *p = NULL;
    long long member = (p ? mval : -1);
    printf("member :%lld\n", member);
    return 0;
}