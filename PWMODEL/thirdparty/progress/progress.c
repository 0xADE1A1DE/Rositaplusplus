#include "progress.h"
#include <stdio.h>

void progress_init(progress_t* pg, unsigned long max)
{
    pg->perc = 0;
    pg->perc_incr = 1;
    if (max < 10000)
    {
        pg->last = 1;
        pg->mod = 1;
        pg->perc_incr = 10000 / max;
    }
    else
    {
        pg->last = max / 10000;
        pg->mod = max / 10000;
    }
    printf("[  0.00%%]");
    fflush(stdout);
}
void progress_update(progress_t* pg, unsigned long current)
{
    if (current >= pg->last)
    {
        pg->perc += pg->perc_incr;

        printf("\r[%3d.%2d%%]", pg->perc / 100, pg->perc % 100);
        
        fflush(stdout);
        pg->last += pg->mod;
    }
}
void progress_finit(progress_t* pg)
{
    printf("\r[100.00%%]\n");
    fflush(stdout);
}
