#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

void nafsh(void);

int main()
{
    nafsh();

    return (0);
}

void nafsh(void)
{
    char req[MAX];

    while (1)
    {
        printf("nafsh$ ");
        scanf(req);
        if (req == "exit")
        {
            break;
        }
        fflush(stdin);
    }
}
