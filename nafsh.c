#include <string.h>
#include "nafsh.h"

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
