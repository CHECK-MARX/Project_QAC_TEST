
#pragma PRQA_MESSAGES_OFF 776,1057,2216,3602,3625,3630

#ifndef _TIME_H
#define _TIME_H

#ifndef _SIZE_T
#define _SIZE_T
typedef PRQA_SIZE_T size_t;
#endif

#ifndef _WCHAR_T
#define _WCHAR_T
#ifdef PRQA_WCHAR_T
typedef PRQA_WCHAR_T wchar_t;
#endif
#endif

#ifndef NULL
#define NULL ((void *) 0)
#endif

#define CLOCKS_PER_SEC  100

typedef long clock_t;
typedef long time_t;

struct tm
{
  int tm_sec, tm_min, tm_hour, tm_mday, tm_mon, tm_year, tm_wday, tm_yday, tm_isdst;
};

struct timespec
{
  time_t tv_sec;
  long tv_nsec;
};

clock_t       clock (void);

double        difftime (time_t time1,
                        time_t time0);

time_t        mktime (struct tm * timeptr);

time_t        time (time_t * timer);

char *        asctime (const struct tm * timeptr);

char *        ctime (const time_t * timer);

struct tm *   gmtime (const time_t * timer);
struct tm *   gmtime_r (const time_t * timer, struct tm * buf);
struct tm *   gmtime_s (const time_t * restrict timer, struct tm * restrict buf);

struct tm *   localtime (const time_t * timer);
struct tm *   localtime_r (const time_t * timer, struct tm * buf);
struct tm *   localtime_s (const time_t * restrict timer, struct tm * restrict buf);

size_t        strftime (char *            restrict s,
                        size_t                     maxsize,
                        const char *      restrict format,
                        const struct tm * restrict timeptr);

int timespec_get (struct timespec * ts, int base);
#define TIME_UTC 0

size_t wcsftime (wchar_t * str, size_t count, wchar_t const * format, const struct tm * time);

#endif
