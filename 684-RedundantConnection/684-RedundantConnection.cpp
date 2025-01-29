#include <stdio.h>

int power(int num, int exp)
{
    if (exp == 0)
    {
        return 1;
    }
    return num * power(num, /* your code */); // replace the comment with required logic
}

int main()
{
    printf("%d", power(2, 11));     // 11 = 3, op: 8
    printf("%d", power(2, 10));     // 10 = 2, op: 4
}