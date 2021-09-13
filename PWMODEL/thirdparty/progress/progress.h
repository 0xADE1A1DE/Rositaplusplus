#pragma once
typedef struct _progress_t
{
    int perc;
    int perc_incr;
    unsigned long last;
    unsigned long mod;
} progress_t;
#ifdef __cplusplus
extern "C" {
#endif
void progress_init(progress_t* pg, unsigned long max);
void progress_update(progress_t* pg, unsigned long current);
void progress_finit(progress_t* pg);
#ifdef __cplusplus
}
#endif

