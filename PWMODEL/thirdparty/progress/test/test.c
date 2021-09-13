#include "progress.h"
#include <unistd.h>
int main()
{
    int max = 10100;
    int i=0;
    progress_t pg;
    progress_init(&pg, max);
    for (;i<max;i++)
    {
        usleep(1000);
        progress_update(&pg, i);
    }
    progress_finit(&pg);
    return 0;
}


