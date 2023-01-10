#include <stdio.h>
int get_pisano_period(int mod)
{
    int prev = 0;
    int curr = 1;
    int res = 0;
    for(int i = 0; i < mod * mod; i++)
    {
        int temp = 0;
        temp = curr;
        curr = (prev + curr) % mod;
        prev = temp;
        printf("%d,", curr);
        if (prev == 0 && curr == 1)
        {
            res = i + 1;
            break;
        }
    }
    return res;
}

int main()
{
    get_pisano_period(10);
    return 0;
}