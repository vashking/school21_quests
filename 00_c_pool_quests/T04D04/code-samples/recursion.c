/// Launch Me ///

#include <stdio.h>

// Pay attention to how this function is called
int recursive_function(int i)
{
    int res = i;
    i -= 1;
    
    if (i > 0)
        res = recursive_function(i);
        
    printf("%d\n", res);
    
    return res + 1;
}

int main()
{
    recursive_function(5);

    return 0;
}
