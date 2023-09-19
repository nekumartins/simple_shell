#include "nafsh.h"

#define MAX 1024

void nafsh();

int main()
{
    nafsh();

    return (0);
}

void nafsh(void)
{
    char req[MAX];

    scanf("%c",&req[0]);
    printf("%c",req[0]);

    // while (1)
    // {
    //     printf("nafsh$ ");
    //     scanf(req);
    //     printf(req, "\n");
    //     if (strcmp(req, "exit") == 0)
    //     {
    //         break;
    //     }
    //     fflush(stdin);
    // }
}
