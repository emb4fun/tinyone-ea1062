#ifndef TIME64_H
#    define TIME64_H

#include <time.h>
#include "time64_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Set our custom types */
typedef INT_64_T        Int64;
typedef Int64           Time64_T;
typedef Int64           Year;

#ifndef PRId64
# if (__WORDSIZE == 64) && !defined(__APPLE__)
#  define PRId64 "ld"
# else
#  define PRId64 "lld"
# endif
#endif

/* A copy of the tm struct but with a 64 bit year */
struct TM64 {
        int     tm_sec;
        int     tm_min;
        int     tm_hour;
        int     tm_mday;
        int     tm_mon;
        Year    tm_year;
        int     tm_wday;
        int     tm_yday;
        int     tm_isdst;

#ifdef HAS_TM_TM_GMTOFF
        long    tm_gmtoff;
#endif

#ifdef HAS_TM_TM_ZONE
        const char *tm_zone;
#endif
};


/* Decide which tm struct to use */
#ifdef USE_TM64
#define TM      TM64
#else
#define TM      tm
#endif


/* Declare public functions */
struct TM *gmtime64_r    (const Time64_T *, struct TM *);
struct TM *localtime64_r (const Time64_T *, struct TM *);
struct TM *gmtime64      (const Time64_T *);
struct TM *localtime64   (const Time64_T *);

char *asctime64          (const struct TM *);
char *asctime64_r        (const struct TM *, char *);

char *ctime64            (const Time64_T*);
char *ctime64_r          (const Time64_T*, char*);

Time64_T   timegm64      (const struct TM *);
Time64_T   mktime64      (struct TM *);
Time64_T   timelocal64   (struct TM *);


/* Not everyone has gm/localtime_r(), provide a replacement */
#ifdef HAS_LOCALTIME_R
#    define LOCALTIME_R(clock, result) localtime_r(clock, result)
#else
#    define LOCALTIME_R(clock, result) fake_localtime_r(clock, result)
#endif
#ifdef HAS_GMTIME_R
#    define GMTIME_R(clock, result)    gmtime_r(clock, result)
#else
#    define GMTIME_R(clock, result)    fake_gmtime_r(clock, result)
#endif


/* Use a different asctime format depending on how big the year is */
#ifdef USE_TM64
    #define TM64_ASCTIME_FORMAT "%.3s %.3s%3d %.2d:%.2d:%.2d %"PRId64"\n"
#else
    #define TM64_ASCTIME_FORMAT "%.3s %.3s%3d %.2d:%.2d:%.2d %d\n"
#endif

#ifdef __cplusplus
  };
#endif

#endif
