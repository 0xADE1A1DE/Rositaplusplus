

typedef long unsigned int size_t;

typedef __builtin_va_list __gnuc_va_list;


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;

typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;

typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;

typedef long int __quad_t;
typedef unsigned long int __u_quad_t;

typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;

typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct
{
    int __val[2];
} __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;

typedef int __daddr_t;
typedef int __key_t;

typedef int __clockid_t;

typedef void* __timer_t;

typedef long int __blksize_t;

typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;

typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;

typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;

typedef long int __fsword_t;

typedef long int __ssize_t;

typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;

typedef __off64_t __loff_t;
typedef char* __caddr_t;

typedef long int __intptr_t;

typedef unsigned int __socklen_t;

typedef int __sig_atomic_t;

typedef struct
{
    int __count;
    union
    {
        unsigned int __wch;
        char __wchb[4];
    } __value;
} __mbstate_t;

typedef struct _G_fpos_t
{
    __off_t __pos;
    __mbstate_t __state;
} __fpos_t;
typedef struct _G_fpos64_t
{
    __off64_t __pos;
    __mbstate_t __state;
} __fpos64_t;

struct _IO_FILE;
typedef struct _IO_FILE __FILE;

struct _IO_FILE;

typedef struct _IO_FILE FILE;
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;

typedef void _IO_lock_t;

struct _IO_FILE
{
    int _flags;

    char* _IO_read_ptr;
    char* _IO_read_end;
    char* _IO_read_base;
    char* _IO_write_base;
    char* _IO_write_ptr;
    char* _IO_write_end;
    char* _IO_buf_base;
    char* _IO_buf_end;

    char* _IO_save_base;
    char* _IO_backup_base;
    char* _IO_save_end;

    struct _IO_marker* _markers;

    struct _IO_FILE* _chain;

    int _fileno;
    int _flags2;
    __off_t _old_offset;

    unsigned short _cur_column;
    signed char _vtable_offset;
    char _shortbuf[1];

    _IO_lock_t* _lock;

    __off64_t _offset;

    struct _IO_codecvt* _codecvt;
    struct _IO_wide_data* _wide_data;
    struct _IO_FILE* _freeres_list;
    void* _freeres_buf;
    size_t __pad5;
    int _mode;

    char _unused2[15 * sizeof(int) - 4 * sizeof(void*) - sizeof(size_t)];
};
typedef __gnuc_va_list va_list;
typedef __off_t off_t;
typedef __ssize_t ssize_t;

typedef __fpos_t fpos_t;

extern FILE* stdin;
extern FILE* stdout;
extern FILE* stderr;

extern int
remove(const char* __filename) __attribute__((__nothrow__, __leaf__));

extern int
rename(const char* __old, const char* __new)
  __attribute__((__nothrow__, __leaf__));

extern int
renameat(int __oldfd, const char* __old, int __newfd, const char* __new)
  __attribute__((__nothrow__, __leaf__));
extern FILE*
tmpfile(void);
extern char*
tmpnam(char* __s) __attribute__((__nothrow__, __leaf__));

extern char*
tmpnam_r(char* __s) __attribute__((__nothrow__, __leaf__));
extern char*
tempnam(const char* __dir, const char* __pfx)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__));

extern int
fclose(FILE* __stream);

extern int
fflush(FILE* __stream);
extern int
fflush_unlocked(FILE* __stream);
extern FILE*
fopen(const char* __restrict __filename, const char* __restrict __modes);

extern FILE*
freopen(const char* __restrict __filename,
        const char* __restrict __modes,
        FILE* __restrict __stream);
extern FILE*
fdopen(int __fd, const char* __modes) __attribute__((__nothrow__, __leaf__));
extern FILE*
fmemopen(void* __s, size_t __len, const char* __modes)
  __attribute__((__nothrow__, __leaf__));

extern FILE*
open_memstream(char** __bufloc, size_t* __sizeloc)
  __attribute__((__nothrow__, __leaf__));

extern void
setbuf(FILE* __restrict __stream, char* __restrict __buf)
  __attribute__((__nothrow__, __leaf__));

extern int
setvbuf(FILE* __restrict __stream,
        char* __restrict __buf,
        int __modes,
        size_t __n) __attribute__((__nothrow__, __leaf__));

extern void
setbuffer(FILE* __restrict __stream, char* __restrict __buf, size_t __size)
  __attribute__((__nothrow__, __leaf__));

extern void
setlinebuf(FILE* __stream) __attribute__((__nothrow__, __leaf__));

extern int
fprintf(FILE* __restrict __stream, const char* __restrict __format, ...);

extern int
printf(const char* __restrict __format, ...);

extern int
sprintf(char* __restrict __s, const char* __restrict __format, ...)
  __attribute__((__nothrow__));

extern int
vfprintf(FILE* __restrict __s,
         const char* __restrict __format,
         __gnuc_va_list __arg);

extern int
vprintf(const char* __restrict __format, __gnuc_va_list __arg);

extern int
vsprintf(char* __restrict __s,
         const char* __restrict __format,
         __gnuc_va_list __arg) __attribute__((__nothrow__));

extern int
snprintf(char* __restrict __s,
         size_t __maxlen,
         const char* __restrict __format,
         ...) __attribute__((__nothrow__))
__attribute__((__format__(__printf__, 3, 4)));

extern int
vsnprintf(char* __restrict __s,
          size_t __maxlen,
          const char* __restrict __format,
          __gnuc_va_list __arg) __attribute__((__nothrow__))
__attribute__((__format__(__printf__, 3, 0)));
extern int
vdprintf(int __fd, const char* __restrict __fmt, __gnuc_va_list __arg)
  __attribute__((__format__(__printf__, 2, 0)));
extern int
dprintf(int __fd, const char* __restrict __fmt, ...)
  __attribute__((__format__(__printf__, 2, 3)));

extern int
fscanf(FILE* __restrict __stream, const char* __restrict __format, ...);

extern int
scanf(const char* __restrict __format, ...);

extern int
sscanf(const char* __restrict __s, const char* __restrict __format, ...)
  __attribute__((__nothrow__, __leaf__));

extern int
fscanf(FILE* __restrict __stream,
       const char* __restrict __format,
       ...) __asm__(""
                    "__isoc99_fscanf")

  ;
extern int
scanf(const char* __restrict __format, ...) __asm__(""
                                                    "__isoc99_scanf");
extern int
sscanf(const char* __restrict __s,
       const char* __restrict __format,
       ...) __asm__(""
                    "__isoc99_sscanf") __attribute__((__nothrow__, __leaf__))

;
extern int
vfscanf(FILE* __restrict __s,
        const char* __restrict __format,
        __gnuc_va_list __arg) __attribute__((__format__(__scanf__, 2, 0)));

extern int
vscanf(const char* __restrict __format, __gnuc_va_list __arg)
  __attribute__((__format__(__scanf__, 1, 0)));

extern int
vsscanf(const char* __restrict __s,
        const char* __restrict __format,
        __gnuc_va_list __arg) __attribute__((__nothrow__, __leaf__))
__attribute__((__format__(__scanf__, 2, 0)));

extern int
vfscanf(FILE* __restrict __s,
        const char* __restrict __format,
        __gnuc_va_list __arg) __asm__(""
                                      "__isoc99_vfscanf")

  __attribute__((__format__(__scanf__, 2, 0)));
extern int
vscanf(const char* __restrict __format,
       __gnuc_va_list __arg) __asm__(""
                                     "__isoc99_vscanf")

  __attribute__((__format__(__scanf__, 1, 0)));
extern int
vsscanf(const char* __restrict __s,
        const char* __restrict __format,
        __gnuc_va_list __arg) __asm__(""
                                      "__isoc99_vsscanf")
  __attribute__((__nothrow__, __leaf__))

  __attribute__((__format__(__scanf__, 2, 0)));
extern int
fgetc(FILE* __stream);
extern int
getc(FILE* __stream);

extern int
getchar(void);

extern int
getc_unlocked(FILE* __stream);
extern int
getchar_unlocked(void);
extern int
fgetc_unlocked(FILE* __stream);
extern int
fputc(int __c, FILE* __stream);
extern int
putc(int __c, FILE* __stream);

extern int
putchar(int __c);
extern int
fputc_unlocked(int __c, FILE* __stream);

extern int
putc_unlocked(int __c, FILE* __stream);
extern int
putchar_unlocked(int __c);

extern int
getw(FILE* __stream);

extern int
putw(int __w, FILE* __stream);

extern char*
fgets(char* __restrict __s, int __n, FILE* __restrict __stream);
extern __ssize_t
__getdelim(char** __restrict __lineptr,
           size_t* __restrict __n,
           int __delimiter,
           FILE* __restrict __stream);
extern __ssize_t
getdelim(char** __restrict __lineptr,
         size_t* __restrict __n,
         int __delimiter,
         FILE* __restrict __stream);

extern __ssize_t
getline(char** __restrict __lineptr,
        size_t* __restrict __n,
        FILE* __restrict __stream);

extern int
fputs(const char* __restrict __s, FILE* __restrict __stream);

extern int
puts(const char* __s);

extern int
ungetc(int __c, FILE* __stream);

extern size_t
fread(void* __restrict __ptr,
      size_t __size,
      size_t __n,
      FILE* __restrict __stream);

extern size_t
fwrite(const void* __restrict __ptr,
       size_t __size,
       size_t __n,
       FILE* __restrict __s);
extern size_t
fread_unlocked(void* __restrict __ptr,
               size_t __size,
               size_t __n,
               FILE* __restrict __stream);
extern size_t
fwrite_unlocked(const void* __restrict __ptr,
                size_t __size,
                size_t __n,
                FILE* __restrict __stream);

extern int
fseek(FILE* __stream, long int __off, int __whence);

extern long int
ftell(FILE* __stream);

extern void
rewind(FILE* __stream);
extern int
fseeko(FILE* __stream, __off_t __off, int __whence);

extern __off_t
ftello(FILE* __stream);
extern int
fgetpos(FILE* __restrict __stream, fpos_t* __restrict __pos);

extern int
fsetpos(FILE* __stream, const fpos_t* __pos);
extern void
clearerr(FILE* __stream) __attribute__((__nothrow__, __leaf__));

extern int
feof(FILE* __stream) __attribute__((__nothrow__, __leaf__));

extern int
ferror(FILE* __stream) __attribute__((__nothrow__, __leaf__));

extern void
clearerr_unlocked(FILE* __stream) __attribute__((__nothrow__, __leaf__));
extern int
feof_unlocked(FILE* __stream) __attribute__((__nothrow__, __leaf__));
extern int
ferror_unlocked(FILE* __stream) __attribute__((__nothrow__, __leaf__));

extern void
perror(const char* __s);

extern int sys_nerr;
extern const char* const sys_errlist[];

extern int
fileno(FILE* __stream) __attribute__((__nothrow__, __leaf__));

extern int
fileno_unlocked(FILE* __stream) __attribute__((__nothrow__, __leaf__));
extern FILE*
popen(const char* __command, const char* __modes);

extern int
pclose(FILE* __stream);

extern char*
ctermid(char* __s) __attribute__((__nothrow__, __leaf__));
extern void
flockfile(FILE* __stream) __attribute__((__nothrow__, __leaf__));

extern int
ftrylockfile(FILE* __stream) __attribute__((__nothrow__, __leaf__));

extern void
funlockfile(FILE* __stream) __attribute__((__nothrow__, __leaf__));
extern int
__uflow(FILE*);
extern int
__overflow(FILE*, int);


extern void*
memcpy(void* __restrict __dest, const void* __restrict __src, size_t __n)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern void*
memmove(void* __dest, const void* __src, size_t __n)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern void*
memccpy(void* __restrict __dest,
        const void* __restrict __src,
        int __c,
        size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));

extern void*
memset(void* __s, int __c, size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern int
memcmp(const void* __s1, const void* __s2, size_t __n)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
  __attribute__((__nonnull__(1, 2)));
extern void*
memchr(const void* __s, int __c, size_t __n)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
  __attribute__((__nonnull__(1)));
extern char*
strcpy(char* __restrict __dest, const char* __restrict __src)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern char*
strncpy(char* __restrict __dest, const char* __restrict __src, size_t __n)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern char*
strcat(char* __restrict __dest, const char* __restrict __src)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern char*
strncat(char* __restrict __dest, const char* __restrict __src, size_t __n)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int
strcmp(const char* __s1, const char* __s2)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
  __attribute__((__nonnull__(1, 2)));

extern int
strncmp(const char* __s1, const char* __s2, size_t __n)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
  __attribute__((__nonnull__(1, 2)));

extern int
strcoll(const char* __s1, const char* __s2)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
  __attribute__((__nonnull__(1, 2)));

extern size_t
strxfrm(char* __restrict __dest, const char* __restrict __src, size_t __n)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

struct __locale_struct
{

    struct __locale_data* __locales[13];

    const unsigned short int* __ctype_b;
    const int* __ctype_tolower;
    const int* __ctype_toupper;

    const char* __names[13];
};

typedef struct __locale_struct* __locale_t;

typedef __locale_t locale_t;

extern int
strcoll_l(const char* __s1, const char* __s2, locale_t __l)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
  __attribute__((__nonnull__(1, 2, 3)));

extern size_t
strxfrm_l(char* __dest, const char* __src, size_t __n, locale_t __l)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 4)));

extern char*
strdup(const char* __s) __attribute__((__nothrow__, __leaf__))
__attribute__((__malloc__)) __attribute__((__nonnull__(1)));

extern char*
strndup(const char* __string, size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__malloc__)) __attribute__((__nonnull__(1)));
extern char*
strchr(const char* __s, int __c) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern char*
strrchr(const char* __s, int __c) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern size_t
strcspn(const char* __s, const char* __reject)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
  __attribute__((__nonnull__(1, 2)));

extern size_t
strspn(const char* __s, const char* __accept)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
  __attribute__((__nonnull__(1, 2)));
extern char*
strpbrk(const char* __s, const char* __accept)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
  __attribute__((__nonnull__(1, 2)));
extern char*
strstr(const char* __haystack, const char* __needle)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
  __attribute__((__nonnull__(1, 2)));

extern char*
strtok(char* __restrict __s, const char* __restrict __delim)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

extern char*
__strtok_r(char* __restrict __s,
           const char* __restrict __delim,
           char** __restrict __save_ptr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2, 3)));

extern char*
strtok_r(char* __restrict __s,
         const char* __restrict __delim,
         char** __restrict __save_ptr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2, 3)));
extern size_t
strlen(const char* __s) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));

extern size_t
strnlen(const char* __string, size_t __maxlen)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
  __attribute__((__nonnull__(1)));

extern char*
strerror(int __errnum) __attribute__((__nothrow__, __leaf__));
extern int
strerror_r(int __errnum,
           char* __buf,
           size_t __buflen) __asm__(""
                                    "__xpg_strerror_r")
  __attribute__((__nothrow__, __leaf__))

  __attribute__((__nonnull__(2)));
extern char*
strerror_l(int __errnum, locale_t __l) __attribute__((__nothrow__, __leaf__));


extern int
bcmp(const void* __s1, const void* __s2, size_t __n)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
  __attribute__((__nonnull__(1, 2)));

extern void
bcopy(const void* __src, void* __dest, size_t __n)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern void
bzero(void* __s, size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern char*
index(const char* __s, int __c) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern char*
rindex(const char* __s, int __c) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));

extern int
ffs(int __i) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));

extern int
ffsl(long int __l) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
__extension__ extern int
ffsll(long long int __ll) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));

extern int
strcasecmp(const char* __s1, const char* __s2)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
  __attribute__((__nonnull__(1, 2)));

extern int
strncasecmp(const char* __s1, const char* __s2, size_t __n)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
  __attribute__((__nonnull__(1, 2)));

extern int
strcasecmp_l(const char* __s1, const char* __s2, locale_t __loc)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
  __attribute__((__nonnull__(1, 2, 3)));

extern int
strncasecmp_l(const char* __s1, const char* __s2, size_t __n, locale_t __loc)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
  __attribute__((__nonnull__(1, 2, 4)));


extern void
explicit_bzero(void* __s, size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern char*
strsep(char** __restrict __stringp, const char* __restrict __delim)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern char*
strsignal(int __sig) __attribute__((__nothrow__, __leaf__));

extern char*
__stpcpy(char* __restrict __dest, const char* __restrict __src)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern char*
stpcpy(char* __restrict __dest, const char* __restrict __src)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern char*
__stpncpy(char* __restrict __dest, const char* __restrict __src, size_t __n)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern char*
stpncpy(char* __restrict __dest, const char* __restrict __src, size_t __n)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));



typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;

typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;

typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;

typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;

typedef signed char int_fast8_t;

typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;

typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef long int intptr_t;

typedef unsigned long int uintptr_t;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;

typedef int wchar_t;

typedef enum
{
    P_ALL,
    P_PID,
    P_PGID
} idtype_t;

typedef struct
{
    int quot;
    int rem;
} div_t;

typedef struct
{
    long int quot;
    long int rem;
} ldiv_t;

__extension__ typedef struct
{
    long long int quot;
    long long int rem;
} lldiv_t;
extern size_t
__ctype_get_mb_cur_max(void) __attribute__((__nothrow__, __leaf__));

extern double
atof(const char* __nptr) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));

extern int
atoi(const char* __nptr) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));

extern long int
atol(const char* __nptr) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));

__extension__ extern long long int
atoll(const char* __nptr) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));

extern double
strtod(const char* __restrict __nptr, char** __restrict __endptr)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern float
strtof(const char* __restrict __nptr, char** __restrict __endptr)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern long double
strtold(const char* __restrict __nptr, char** __restrict __endptr)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern long int
strtol(const char* __restrict __nptr, char** __restrict __endptr, int __base)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern unsigned long int
strtoul(const char* __restrict __nptr, char** __restrict __endptr, int __base)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

__extension__ extern long long int
strtoq(const char* __restrict __nptr, char** __restrict __endptr, int __base)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

__extension__ extern unsigned long long int
strtouq(const char* __restrict __nptr, char** __restrict __endptr, int __base)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

__extension__ extern long long int
strtoll(const char* __restrict __nptr, char** __restrict __endptr, int __base)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

__extension__ extern unsigned long long int
strtoull(const char* __restrict __nptr, char** __restrict __endptr, int __base)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern char*
l64a(long int __n) __attribute__((__nothrow__, __leaf__));

extern long int
a64l(const char* __s) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));


typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;

typedef __loff_t loff_t;

typedef __ino_t ino_t;
typedef __dev_t dev_t;

typedef __gid_t gid_t;

typedef __mode_t mode_t;

typedef __nlink_t nlink_t;

typedef __uid_t uid_t;
typedef __pid_t pid_t;

typedef __id_t id_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;

typedef __key_t key_t;


typedef __clock_t clock_t;


typedef __clockid_t clockid_t;

typedef __time_t time_t;

typedef __timer_t timer_t;

typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;

typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;

typedef int register_t __attribute__((__mode__(__word__)));
static __inline __uint16_t
__bswap_16(__uint16_t __bsx)
{

    return __builtin_bswap16(__bsx);
}

static __inline __uint32_t
__bswap_32(__uint32_t __bsx)
{

    return __builtin_bswap32(__bsx);
}
__extension__ static __inline __uint64_t
__bswap_64(__uint64_t __bsx)
{

    return __builtin_bswap64(__bsx);
}
static __inline __uint16_t
__uint16_identity(__uint16_t __x)
{
    return __x;
}

static __inline __uint32_t
__uint32_identity(__uint32_t __x)
{
    return __x;
}

static __inline __uint64_t
__uint64_identity(__uint64_t __x)
{
    return __x;
}




typedef struct
{
    unsigned long int __val[(1024 / (8 * sizeof(unsigned long int)))];
} __sigset_t;

typedef __sigset_t sigset_t;


struct timeval
{
    __time_t tv_sec;
    __suseconds_t tv_usec;
};

struct timespec
{
    __time_t tv_sec;

    __syscall_slong_t tv_nsec;
};

typedef __suseconds_t suseconds_t;

typedef long int __fd_mask;
typedef struct
{

    __fd_mask __fds_bits[1024 / (8 * (int)sizeof(__fd_mask))];

} fd_set;

typedef __fd_mask fd_mask;

extern int
select(int __nfds,
       fd_set* __restrict __readfds,
       fd_set* __restrict __writefds,
       fd_set* __restrict __exceptfds,
       struct timeval* __restrict __timeout);
extern int
pselect(int __nfds,
        fd_set* __restrict __readfds,
        fd_set* __restrict __writefds,
        fd_set* __restrict __exceptfds,
        const struct timespec* __restrict __timeout,
        const __sigset_t* __restrict __sigmask);


typedef __blksize_t blksize_t;

typedef __blkcnt_t blkcnt_t;

typedef __fsblkcnt_t fsblkcnt_t;

typedef __fsfilcnt_t fsfilcnt_t;

typedef struct __pthread_internal_list
{
    struct __pthread_internal_list* __prev;
    struct __pthread_internal_list* __next;
} __pthread_list_t;

typedef struct __pthread_internal_slist
{
    struct __pthread_internal_slist* __next;
} __pthread_slist_t;
struct __pthread_mutex_s
{
    int __lock;
    unsigned int __count;
    int __owner;

    unsigned int __nusers;

    int __kind;

    short __spins;
    short __elision;
    __pthread_list_t __list;
};
struct __pthread_rwlock_arch_t
{
    unsigned int __readers;
    unsigned int __writers;
    unsigned int __wrphase_futex;
    unsigned int __writers_futex;
    unsigned int __pad3;
    unsigned int __pad4;

    int __cur_writer;
    int __shared;
    signed char __rwelision;

    unsigned char __pad1[7];

    unsigned long int __pad2;

    unsigned int __flags;
};

struct __pthread_cond_s
{
    __extension__ union
    {
        __extension__ unsigned long long int __wseq;
        struct
        {
            unsigned int __low;
            unsigned int __high;
        } __wseq32;
    };
    __extension__ union
    {
        __extension__ unsigned long long int __g1_start;
        struct
        {
            unsigned int __low;
            unsigned int __high;
        } __g1_start32;
    };
    unsigned int __g_refs[2];
    unsigned int __g_size[2];
    unsigned int __g1_orig_size;
    unsigned int __wrefs;
    unsigned int __g_signals[2];
};

typedef unsigned long int pthread_t;

typedef union
{
    char __size[4];
    int __align;
} pthread_mutexattr_t;

typedef union
{
    char __size[4];
    int __align;
} pthread_condattr_t;

typedef unsigned int pthread_key_t;

typedef int pthread_once_t;

union pthread_attr_t
{
    char __size[56];
    long int __align;
};

typedef union pthread_attr_t pthread_attr_t;

typedef union
{
    struct __pthread_mutex_s __data;
    char __size[40];
    long int __align;
} pthread_mutex_t;

typedef union
{
    struct __pthread_cond_s __data;
    char __size[48];
    __extension__ long long int __align;
} pthread_cond_t;

typedef union
{
    struct __pthread_rwlock_arch_t __data;
    char __size[56];
    long int __align;
} pthread_rwlock_t;

typedef union
{
    char __size[8];
    long int __align;
} pthread_rwlockattr_t;

typedef volatile int pthread_spinlock_t;

typedef union
{
    char __size[32];
    long int __align;
} pthread_barrier_t;

typedef union
{
    char __size[4];
    int __align;
} pthread_barrierattr_t;


extern long int
random(void) __attribute__((__nothrow__, __leaf__));

extern void
srandom(unsigned int __seed) __attribute__((__nothrow__, __leaf__));

extern char*
initstate(unsigned int __seed, char* __statebuf, size_t __statelen)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

extern char*
setstate(char* __statebuf) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

struct random_data
{
    int32_t* fptr;
    int32_t* rptr;
    int32_t* state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t* end_ptr;
};

extern int
random_r(struct random_data* __restrict __buf, int32_t* __restrict __result)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int
srandom_r(unsigned int __seed, struct random_data* __buf)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

extern int
initstate_r(unsigned int __seed,
            char* __restrict __statebuf,
            size_t __statelen,
            struct random_data* __restrict __buf)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 4)));

extern int
setstate_r(char* __restrict __statebuf, struct random_data* __restrict __buf)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int
rand(void) __attribute__((__nothrow__, __leaf__));

extern void
srand(unsigned int __seed) __attribute__((__nothrow__, __leaf__));

extern int
rand_r(unsigned int* __seed) __attribute__((__nothrow__, __leaf__));

extern double
drand48(void) __attribute__((__nothrow__, __leaf__));
extern double
erand48(unsigned short int __xsubi[3]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern long int
lrand48(void) __attribute__((__nothrow__, __leaf__));
extern long int
nrand48(unsigned short int __xsubi[3]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern long int
mrand48(void) __attribute__((__nothrow__, __leaf__));
extern long int
jrand48(unsigned short int __xsubi[3]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern void
srand48(long int __seedval) __attribute__((__nothrow__, __leaf__));
extern unsigned short int*
seed48(unsigned short int __seed16v[3]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern void
lcong48(unsigned short int __param[7]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

struct drand48_data
{
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;
};

extern int
drand48_r(struct drand48_data* __restrict __buffer, double* __restrict __result)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int
erand48_r(unsigned short int __xsubi[3],
          struct drand48_data* __restrict __buffer,
          double* __restrict __result) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));

extern int
lrand48_r(struct drand48_data* __restrict __buffer,
          long int* __restrict __result) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int
nrand48_r(unsigned short int __xsubi[3],
          struct drand48_data* __restrict __buffer,
          long int* __restrict __result) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));

extern int
mrand48_r(struct drand48_data* __restrict __buffer,
          long int* __restrict __result) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int
jrand48_r(unsigned short int __xsubi[3],
          struct drand48_data* __restrict __buffer,
          long int* __restrict __result) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));

extern int
srand48_r(long int __seedval, struct drand48_data* __buffer)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

extern int
seed48_r(unsigned short int __seed16v[3], struct drand48_data* __buffer)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int
lcong48_r(unsigned short int __param[7], struct drand48_data* __buffer)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern void*
malloc(size_t __size) __attribute__((__nothrow__, __leaf__))
__attribute__((__malloc__)) __attribute__((__alloc_size__(1)));

extern void*
calloc(size_t __nmemb, size_t __size) __attribute__((__nothrow__, __leaf__))
__attribute__((__malloc__)) __attribute__((__alloc_size__(1, 2)));

extern void*
realloc(void* __ptr, size_t __size) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__)) __attribute__((__alloc_size__(2)));

extern void*
reallocarray(void* __ptr, size_t __nmemb, size_t __size)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__warn_unused_result__))
  __attribute__((__alloc_size__(2, 3)));

extern void
free(void* __ptr) __attribute__((__nothrow__, __leaf__));


extern void*
alloca(size_t __size) __attribute__((__nothrow__, __leaf__));


extern void*
valloc(size_t __size) __attribute__((__nothrow__, __leaf__))
__attribute__((__malloc__)) __attribute__((__alloc_size__(1)));

extern int
posix_memalign(void** __memptr, size_t __alignment, size_t __size)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern void*
aligned_alloc(size_t __alignment, size_t __size)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
  __attribute__((__alloc_size__(2)));

extern void
abort(void) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));

extern int
atexit(void (*__func)(void)) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern int
at_quick_exit(void (*__func)(void)) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern int
on_exit(void (*__func)(int __status, void* __arg), void* __arg)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern void
exit(int __status) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));

extern void
quick_exit(int __status) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));

extern void
_Exit(int __status) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));

extern char*
getenv(const char* __name) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int
putenv(char* __string) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern int
setenv(const char* __name, const char* __value, int __replace)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

extern int
unsetenv(const char* __name) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern int
clearenv(void) __attribute__((__nothrow__, __leaf__));
extern char*
mktemp(char* __template) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int
mkstemp(char* __template) __attribute__((__nonnull__(1)));
extern int
mkstemps(char* __template, int __suffixlen) __attribute__((__nonnull__(1)));
extern char*
mkdtemp(char* __template) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int
system(const char* __command);
extern char*
realpath(const char* __restrict __name, char* __restrict __resolved)
  __attribute__((__nothrow__, __leaf__));

typedef int (*__compar_fn_t)(const void*, const void*);
extern void*
bsearch(const void* __key,
        const void* __base,
        size_t __nmemb,
        size_t __size,
        __compar_fn_t __compar) __attribute__((__nonnull__(1, 2, 5)));

extern void
qsort(void* __base, size_t __nmemb, size_t __size, __compar_fn_t __compar)
  __attribute__((__nonnull__(1, 4)));
extern int
abs(int __x) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern long int
labs(long int __x) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));

__extension__ extern long long int
llabs(long long int __x) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));

extern div_t
div(int __numer, int __denom) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
extern ldiv_t
ldiv(long int __numer, long int __denom) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));

__extension__ extern lldiv_t
lldiv(long long int __numer, long long int __denom)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern char*
ecvt(double __value,
     int __ndigit,
     int* __restrict __decpt,
     int* __restrict __sign) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3, 4)));

extern char*
fcvt(double __value,
     int __ndigit,
     int* __restrict __decpt,
     int* __restrict __sign) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3, 4)));

extern char*
gcvt(double __value, int __ndigit, char* __buf)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));

extern char*
qecvt(long double __value,
      int __ndigit,
      int* __restrict __decpt,
      int* __restrict __sign) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3, 4)));
extern char*
qfcvt(long double __value,
      int __ndigit,
      int* __restrict __decpt,
      int* __restrict __sign) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3, 4)));
extern char*
qgcvt(long double __value, int __ndigit, char* __buf)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));

extern int
ecvt_r(double __value,
       int __ndigit,
       int* __restrict __decpt,
       int* __restrict __sign,
       char* __restrict __buf,
       size_t __len) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3, 4, 5)));
extern int
fcvt_r(double __value,
       int __ndigit,
       int* __restrict __decpt,
       int* __restrict __sign,
       char* __restrict __buf,
       size_t __len) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3, 4, 5)));

extern int
qecvt_r(long double __value,
        int __ndigit,
        int* __restrict __decpt,
        int* __restrict __sign,
        char* __restrict __buf,
        size_t __len) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3, 4, 5)));
extern int
qfcvt_r(long double __value,
        int __ndigit,
        int* __restrict __decpt,
        int* __restrict __sign,
        char* __restrict __buf,
        size_t __len) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3, 4, 5)));

extern int
mblen(const char* __s, size_t __n) __attribute__((__nothrow__, __leaf__));

extern int
mbtowc(wchar_t* __restrict __pwc, const char* __restrict __s, size_t __n)
  __attribute__((__nothrow__, __leaf__));

extern int
wctomb(char* __s, wchar_t __wchar) __attribute__((__nothrow__, __leaf__));

extern size_t
mbstowcs(wchar_t* __restrict __pwcs, const char* __restrict __s, size_t __n)
  __attribute__((__nothrow__, __leaf__));

extern size_t
wcstombs(char* __restrict __s, const wchar_t* __restrict __pwcs, size_t __n)
  __attribute__((__nothrow__, __leaf__));

extern int
rpmatch(const char* __response) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int
getsubopt(char** __restrict __optionp,
          char* const* __restrict __tokens,
          char** __restrict __valuep) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2, 3)));
extern int
getloadavg(double __loadavg[], int __nelem)
  __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));


typedef uint32_t tXoodooLane;

void
Xoodoo_Initialize(uint32_t* state);
void
Xoodoo_Permute_12rounds(uint32_t* state, uint32_t* masks);
uint32_t XoodooMask[24];

void
Xoodoo_Initialize(uint32_t* state)
{
    memset(state, 0, (4 * 3) * sizeof(tXoodooLane));
}

void
Xoodoo_Initialize_Masks0(uint32_t* masks)
{
    masks[0] = 0;
    masks[1] = 0;
    masks[2] = 0;
    masks[3] = 0;
}

void
Xoodoo_Initialize_Masks(uint32_t* masks)
{
    int i;
    for (i = 0; i < 96; i++) {
        randbyte(&(((uint8_t*)masks)[i]));
    }
}

void
Xoodoo_AddBytes(void* argState,
                const unsigned char* argdata,
                unsigned int offset,
                unsigned int length)
{

    if (length == (3 * 4 * 4)) {
        uint32_t* state = (uint32_t*)argState;
        uint32_t* data = (uint32_t*)argdata;
        state[0] ^= data[0];
        state[1] ^= data[1];
        state[2] ^= data[2];
        state[3] ^= data[3];
        state[4] ^= data[4];
        state[5] ^= data[5];
        state[6] ^= data[6];
        state[7] ^= data[7];
        state[8] ^= data[8];
        state[9] ^= data[9];
        state[10] ^= data[10];
        state[11] ^= data[11];
    } else {
        unsigned int sizeLeft = length;
        unsigned int lanePosition = offset / 4;
        unsigned int offsetInLane = offset % 4;
        const unsigned char* curData = argdata;
        uint32_t* state = (uint32_t*)argState;

        state += lanePosition;
        if ((sizeLeft > 0) && (offsetInLane != 0)) {
            unsigned int bytesInLane = 4 - offsetInLane;
            uint32_t lane = 0;
            if (bytesInLane > sizeLeft)
                bytesInLane = sizeLeft;
            memcpy((unsigned char*)&lane + offsetInLane, curData, bytesInLane);
            *state++ ^= lane;
            sizeLeft -= bytesInLane;
            curData += bytesInLane;
        }

        while (sizeLeft >= 4) {
            *state++ ^= (*((const uint32_t*)(curData)));
            sizeLeft -= 4;
            curData += 4;
        }

        if (sizeLeft > 0) {
            uint32_t lane = 0;
            memcpy(&lane, curData, sizeLeft);
            *state ^= lane;
        }
    }
}

void
Xoodoo_OverwriteBytes(void* argstate,
                      const unsigned char* argdata,
                      unsigned int offset,
                      unsigned int length)
{

    if (length == (3 * 4 * 4)) {
        uint32_t* state = (uint32_t*)argstate;
        uint32_t* data = (uint32_t*)argdata;
        state[0] = data[0];
        state[1] = data[1];
        state[2] = data[2];
        state[3] = data[3];
        state[4] = data[4];
        state[5] = data[5];
        state[6] = data[6];
        state[7] = data[7];
        state[8] = data[8];
        state[9] = data[9];
        state[10] = data[10];
        state[11] = data[11];
    } else
        memcpy((unsigned char*)argstate + offset, argdata, length);
}

void
Xoodoo_OverwriteWithZeroes(void* argstate, unsigned int byteCount)
{

    memset(argstate, 0, byteCount);
}

void
Xoodoo_ExtractBytes(const void* state,
                    unsigned char* data,
                    unsigned int offset,
                    unsigned int length)
{

    memcpy(data, (unsigned char*)state + offset, length);
}

void
Xoodoo_ExtractAndAddBytes(const void* argState,
                          const unsigned char* input,
                          unsigned char* output,
                          unsigned int offset,
                          unsigned int length)
{

    if (length == (3 * 4 * 4)) {
        uint32_t* state = (uint32_t*)argState;
        const uint32_t* ii = (const uint32_t*)input;
        uint32_t* oo = (uint32_t*)output;

        oo[0] = state[0] ^ ii[0];
        oo[1] = state[1] ^ ii[1];
        oo[2] = state[2] ^ ii[2];
        oo[3] = state[3] ^ ii[3];
        oo[4] = state[4] ^ ii[4];
        oo[5] = state[5] ^ ii[5];
        oo[6] = state[6] ^ ii[6];
        oo[7] = state[7] ^ ii[7];
        oo[8] = state[8] ^ ii[8];
        oo[9] = state[9] ^ ii[9];
        oo[10] = state[10] ^ ii[10];
        oo[11] = state[11] ^ ii[11];
    } else {
        unsigned int sizeLeft = length;
        unsigned int lanePosition = offset / 4;
        unsigned int offsetInLane = offset % 4;
        const unsigned char* curInput = input;
        unsigned char* curOutput = output;
        const uint32_t* state = (const uint32_t*)argState;

        state += lanePosition;
        if ((sizeLeft > 0) && (offsetInLane != 0)) {
            unsigned int bytesInLane = 4 - offsetInLane;
            uint32_t lane = *state++ >> (offsetInLane * 8);
            if (bytesInLane > sizeLeft)
                bytesInLane = sizeLeft;
            sizeLeft -= bytesInLane;
            do {
                *curOutput++ = (*curInput++) ^ (unsigned char)lane;
                lane >>= 8;
            } while (--bytesInLane != 0);
        }

        while (sizeLeft >= 4) {
            (*((uint32_t*)(curOutput)) =
               ((*((const uint32_t*)(curInput))) ^ *state++));
            sizeLeft -= 4;
            curInput += 4;
            curOutput += 4;
        }

        if (sizeLeft > 0) {
            uint32_t lane = *state;
            do {
                *curOutput++ = (*curInput++) ^ (unsigned char)lane;
                lane >>= 8;
            } while (--sizeLeft != 0);
        }
    }
}
static const uint32_t RC[12] = {
    0x00000058, 0x00000038, 0x000003C0, 0x000000D0, 0x00000120, 0x00000014,
    0x00000060, 0x0000002C, 0x00000380, 0x000000F0, 0x000001A0, 0x00000012
};

void
Xoodoo_Permute_Nrounds(uint32_t* state, uint32_t nr)
{
    uint32_t a00, a01, a02, a03;
    uint32_t a10, a11, a12, a13;
    uint32_t a20, a21, a22, a23;
    uint32_t va1, va2;
    uint32_t b00, b01, b02, b03;
    uint32_t b10, b11, b12, b13;
    uint32_t b20, b21, b22, b23;
    uint32_t vb1, vb2;
    uint32_t c00, c01, c02, c03;
    uint32_t c10, c11, c12, c13;
    uint32_t c20, c21, c22, c23;
    uint32_t vc1, vc2;
    ;
    uint32_t i;
    uint32_t* masks = (uint32_t*)XoodooMask;
    a00 = state[0 + 0], a01 = state[0 + 1], a02 = state[0 + 2],
    a03 = state[0 + 3];
    a10 = state[4 + 0], a11 = state[4 + 1], a12 = state[4 + 2],
    a13 = state[4 + 3];
    a20 = state[8 + 0], a21 = state[8 + 1], a22 = state[8 + 2],
    a23 = state[8 + 3];
    b00 = masks[0 + 0], b01 = masks[0 + 1], b02 = masks[0 + 2],
    b03 = masks[0 + 3];
    b10 = masks[4 + 0], b11 = masks[4 + 1], b12 = masks[4 + 2],
    b13 = masks[4 + 3];
    b20 = masks[8 + 0], b21 = masks[8 + 1], b22 = masks[8 + 2],
    b23 = masks[8 + 3];
    c00 = masks[12 + 0], c01 = masks[12 + 1], c02 = masks[12 + 2],
    c03 = masks[12 + 3];
    c10 = masks[16 + 0], c11 = masks[16 + 1], c12 = masks[16 + 2],
    c13 = masks[16 + 3];
    c20 = masks[20 + 0], c21 = masks[20 + 1], c22 = masks[20 + 2],
    c23 = masks[20 + 3];
    ;
    for (i = 12 - nr; i < 12; ++i) {
        va1 = a03 ^ a13 ^ a23;
        va2 = a00 ^ a10 ^ a20;
        va1 = ((((uint32_t)va1) << ((5) % 32)) ^
               (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
              ((((uint32_t)va1) << ((14) % 32)) ^
               (((uint32_t)va1) >> ((32 - (14)) % 32)));
        a00 ^= va1;
        a10 ^= va1;
        a20 ^= va1;
        va1 = a01 ^ a11 ^ a21;
        va2 = ((((uint32_t)va2) << ((5) % 32)) ^
               (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
              ((((uint32_t)va2) << ((14) % 32)) ^
               (((uint32_t)va2) >> ((32 - (14)) % 32)));
        a01 ^= va2;
        a11 ^= va2;
        a21 ^= va2;
        va2 = a02 ^ a12 ^ a22;
        va1 = ((((uint32_t)va1) << ((5) % 32)) ^
               (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
              ((((uint32_t)va1) << ((14) % 32)) ^
               (((uint32_t)va1) >> ((32 - (14)) % 32)));
        a02 ^= va1;
        a12 ^= va1;
        a22 ^= va1;
        va2 = ((((uint32_t)va2) << ((5) % 32)) ^
               (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
              ((((uint32_t)va2) << ((14) % 32)) ^
               (((uint32_t)va2) >> ((32 - (14)) % 32)));
        a03 ^= va2;
        a13 ^= va2;
        a23 ^= va2;
        vb1 = b03 ^ b13 ^ b23;
        vb2 = b00 ^ b10 ^ b20;
        vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
               (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
              ((((uint32_t)vb1) << ((14) % 32)) ^
               (((uint32_t)vb1) >> ((32 - (14)) % 32)));
        b00 ^= vb1;
        b10 ^= vb1;
        b20 ^= vb1;
        vb1 = b01 ^ b11 ^ b21;
        vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
               (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
              ((((uint32_t)vb2) << ((14) % 32)) ^
               (((uint32_t)vb2) >> ((32 - (14)) % 32)));
        b01 ^= vb2;
        b11 ^= vb2;
        b21 ^= vb2;
        vb2 = b02 ^ b12 ^ b22;
        vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
               (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
              ((((uint32_t)vb1) << ((14) % 32)) ^
               (((uint32_t)vb1) >> ((32 - (14)) % 32)));
        b02 ^= vb1;
        b12 ^= vb1;
        b22 ^= vb1;
        vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
               (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
              ((((uint32_t)vb2) << ((14) % 32)) ^
               (((uint32_t)vb2) >> ((32 - (14)) % 32)));
        b03 ^= vb2;
        b13 ^= vb2;
        b23 ^= vb2;
        vc1 = c03 ^ c13 ^ c23;
        vc2 = c00 ^ c10 ^ c20;
        vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
               (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
              ((((uint32_t)vc1) << ((14) % 32)) ^
               (((uint32_t)vc1) >> ((32 - (14)) % 32)));
        c00 ^= vc1;
        c10 ^= vc1;
        c20 ^= vc1;
        vc1 = c01 ^ c11 ^ c21;
        vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
               (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
              ((((uint32_t)vc2) << ((14) % 32)) ^
               (((uint32_t)vc2) >> ((32 - (14)) % 32)));
        c01 ^= vc2;
        c11 ^= vc2;
        c21 ^= vc2;
        vc2 = c02 ^ c12 ^ c22;
        vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
               (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
              ((((uint32_t)vc1) << ((14) % 32)) ^
               (((uint32_t)vc1) >> ((32 - (14)) % 32)));
        c02 ^= vc1;
        c12 ^= vc1;
        c22 ^= vc1;
        vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
               (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
              ((((uint32_t)vc2) << ((14) % 32)) ^
               (((uint32_t)vc2) >> ((32 - (14)) % 32)));
        c03 ^= vc2;
        c13 ^= vc2;
        c23 ^= vc2;
        ;
        a20 = ((((uint32_t)a20) << ((11) % 32)) ^
               (((uint32_t)a20) >> ((32 - (11)) % 32)));
        a21 = ((((uint32_t)a21) << ((11) % 32)) ^
               (((uint32_t)a21) >> ((32 - (11)) % 32)));
        a22 = ((((uint32_t)a22) << ((11) % 32)) ^
               (((uint32_t)a22) >> ((32 - (11)) % 32)));
        a23 = ((((uint32_t)a23) << ((11) % 32)) ^
               (((uint32_t)a23) >> ((32 - (11)) % 32)));
        va1 = a13;
        a13 = a12;
        a12 = a11;
        a11 = a10;
        a10 = va1;
        b20 = ((((uint32_t)b20) << ((11) % 32)) ^
               (((uint32_t)b20) >> ((32 - (11)) % 32)));
        b21 = ((((uint32_t)b21) << ((11) % 32)) ^
               (((uint32_t)b21) >> ((32 - (11)) % 32)));
        b22 = ((((uint32_t)b22) << ((11) % 32)) ^
               (((uint32_t)b22) >> ((32 - (11)) % 32)));
        b23 = ((((uint32_t)b23) << ((11) % 32)) ^
               (((uint32_t)b23) >> ((32 - (11)) % 32)));
        vb1 = b13;
        b13 = b12;
        b12 = b11;
        b11 = b10;
        b10 = vb1;
        c20 = ((((uint32_t)c20) << ((11) % 32)) ^
               (((uint32_t)c20) >> ((32 - (11)) % 32)));
        c21 = ((((uint32_t)c21) << ((11) % 32)) ^
               (((uint32_t)c21) >> ((32 - (11)) % 32)));
        c22 = ((((uint32_t)c22) << ((11) % 32)) ^
               (((uint32_t)c22) >> ((32 - (11)) % 32)));
        c23 = ((((uint32_t)c23) << ((11) % 32)) ^
               (((uint32_t)c23) >> ((32 - (11)) % 32)));
        vc1 = c13;
        c13 = c12;
        c12 = c11;
        c11 = c10;
        c10 = vc1;
        ;
        a00 ^= RC[i];
        ;
        a00 ^= (~a10 & a20) ^ (a10 & b20) ^ (b10 & a20);
        b00 ^= (~b10 & b20) ^ (b10 & c20) ^ (c10 & b20);
        c00 ^= (~c10 & c20) ^ (c10 & a20) ^ (a10 & c20);
        a01 ^= (~a11 & a21) ^ (a11 & b21) ^ (b11 & a21);
        b01 ^= (~b11 & b21) ^ (b11 & c21) ^ (c11 & b21);
        c01 ^= (~c11 & c21) ^ (c11 & a21) ^ (a11 & c21);
        a02 ^= (~a12 & a22) ^ (a12 & b22) ^ (b12 & a22);
        b02 ^= (~b12 & b22) ^ (b12 & c22) ^ (c12 & b22);
        c02 ^= (~c12 & c22) ^ (c12 & a22) ^ (a12 & c22);
        a03 ^= (~a13 & a23) ^ (a13 & b23) ^ (b13 & a23);
        b03 ^= (~b13 & b23) ^ (b13 & c23) ^ (c13 & b23);
        c03 ^= (~c13 & c23) ^ (c13 & a23) ^ (a13 & c23);
        a10 ^= (~a20 & a00) ^ (a20 & b00) ^ (b20 & a00);
        b10 ^= (~b20 & b00) ^ (b20 & c00) ^ (c20 & b00);
        c10 ^= (~c20 & c00) ^ (c20 & a00) ^ (a20 & c00);
        a11 ^= (~a21 & a01) ^ (a21 & b01) ^ (b21 & a01);
        b11 ^= (~b21 & b01) ^ (b21 & c01) ^ (c21 & b01);
        c11 ^= (~c21 & c01) ^ (c21 & a01) ^ (a21 & c01);
        a12 ^= (~a22 & a02) ^ (a22 & b02) ^ (b22 & a02);
        b12 ^= (~b22 & b02) ^ (b22 & c02) ^ (c22 & b02);
        c12 ^= (~c22 & c02) ^ (c22 & a02) ^ (a22 & c02);
        a13 ^= (~a23 & a03) ^ (a23 & b03) ^ (b23 & a03);
        b13 ^= (~b23 & b03) ^ (b23 & c03) ^ (c23 & b03);
        c13 ^= (~c23 & c03) ^ (c23 & a03) ^ (a23 & c03);
        a20 ^= (~a00 & a10) ^ (a00 & b10) ^ (b00 & a10);
        b20 ^= (~b00 & b10) ^ (b00 & c10) ^ (c00 & b10);
        c20 ^= (~c00 & c10) ^ (c00 & a10) ^ (a00 & c10);
        a21 ^= (~a01 & a11) ^ (a01 & b11) ^ (b01 & a11);
        b21 ^= (~b01 & b11) ^ (b01 & c11) ^ (c01 & b11);
        c21 ^= (~c01 & c11) ^ (c01 & a11) ^ (a01 & c11);
        a22 ^= (~a02 & a12) ^ (a02 & b12) ^ (b02 & a12);
        b22 ^= (~b02 & b12) ^ (b02 & c12) ^ (c02 & b12);
        c22 ^= (~c02 & c12) ^ (c02 & a12) ^ (a02 & c12);
        a23 ^= (~a03 & a13) ^ (a03 & b13) ^ (b03 & a13);
        b23 ^= (~b03 & b13) ^ (b03 & c13) ^ (c03 & b13);
        c23 ^= (~c03 & c13) ^ (c03 & a13) ^ (a03 & c13);
        ;
        ;
        a10 = ((((uint32_t)a10) << ((1) % 32)) ^
               (((uint32_t)a10) >> ((32 - (1)) % 32)));
        a11 = ((((uint32_t)a11) << ((1) % 32)) ^
               (((uint32_t)a11) >> ((32 - (1)) % 32)));
        a12 = ((((uint32_t)a12) << ((1) % 32)) ^
               (((uint32_t)a12) >> ((32 - (1)) % 32)));
        a13 = ((((uint32_t)a13) << ((1) % 32)) ^
               (((uint32_t)a13) >> ((32 - (1)) % 32)));
        va1 = ((((uint32_t)a23) << ((8) % 32)) ^
               (((uint32_t)a23) >> ((32 - (8)) % 32)));
        a23 = ((((uint32_t)a21) << ((8) % 32)) ^
               (((uint32_t)a21) >> ((32 - (8)) % 32)));
        a21 = va1;
        va1 = ((((uint32_t)a22) << ((8) % 32)) ^
               (((uint32_t)a22) >> ((32 - (8)) % 32)));
        a22 = ((((uint32_t)a20) << ((8) % 32)) ^
               (((uint32_t)a20) >> ((32 - (8)) % 32)));
        a20 = va1;
        b10 = ((((uint32_t)b10) << ((1) % 32)) ^
               (((uint32_t)b10) >> ((32 - (1)) % 32)));
        b11 = ((((uint32_t)b11) << ((1) % 32)) ^
               (((uint32_t)b11) >> ((32 - (1)) % 32)));
        b12 = ((((uint32_t)b12) << ((1) % 32)) ^
               (((uint32_t)b12) >> ((32 - (1)) % 32)));
        b13 = ((((uint32_t)b13) << ((1) % 32)) ^
               (((uint32_t)b13) >> ((32 - (1)) % 32)));
        vb1 = ((((uint32_t)b23) << ((8) % 32)) ^
               (((uint32_t)b23) >> ((32 - (8)) % 32)));
        b23 = ((((uint32_t)b21) << ((8) % 32)) ^
               (((uint32_t)b21) >> ((32 - (8)) % 32)));
        b21 = vb1;
        vb1 = ((((uint32_t)b22) << ((8) % 32)) ^
               (((uint32_t)b22) >> ((32 - (8)) % 32)));
        b22 = ((((uint32_t)b20) << ((8) % 32)) ^
               (((uint32_t)b20) >> ((32 - (8)) % 32)));
        b20 = vb1;
        c10 = ((((uint32_t)c10) << ((1) % 32)) ^
               (((uint32_t)c10) >> ((32 - (1)) % 32)));
        c11 = ((((uint32_t)c11) << ((1) % 32)) ^
               (((uint32_t)c11) >> ((32 - (1)) % 32)));
        c12 = ((((uint32_t)c12) << ((1) % 32)) ^
               (((uint32_t)c12) >> ((32 - (1)) % 32)));
        c13 = ((((uint32_t)c13) << ((1) % 32)) ^
               (((uint32_t)c13) >> ((32 - (1)) % 32)));
        vc1 = ((((uint32_t)c23) << ((8) % 32)) ^
               (((uint32_t)c23) >> ((32 - (8)) % 32)));
        c23 = ((((uint32_t)c21) << ((8) % 32)) ^
               (((uint32_t)c21) >> ((32 - (8)) % 32)));
        c21 = vc1;
        vc1 = ((((uint32_t)c22) << ((8) % 32)) ^
               (((uint32_t)c22) >> ((32 - (8)) % 32)));
        c22 = ((((uint32_t)c20) << ((8) % 32)) ^
               (((uint32_t)c20) >> ((32 - (8)) % 32)));
        c20 = vc1;
        ;
        ;
    };
    state[0 + 0] = a00, state[0 + 1] = a01, state[0 + 2] = a02,
              state[0 + 3] = a03;
    state[4 + 0] = a10, state[4 + 1] = a11, state[4 + 2] = a12,
              state[4 + 3] = a13;
    state[8 + 0] = a20, state[8 + 1] = a21, state[8 + 2] = a22,
              state[8 + 3] = a23;
    ;
}

void
Xoodoo_Permute_6rounds(uint32_t* state)
{
    uint32_t a00, a01, a02, a03;
    uint32_t a10, a11, a12, a13;
    uint32_t a20, a21, a22, a23;
    uint32_t va1, va2;
    uint32_t b00, b01, b02, b03;
    uint32_t b10, b11, b12, b13;
    uint32_t b20, b21, b22, b23;
    uint32_t vb1, vb2;
    uint32_t c00, c01, c02, c03;
    uint32_t c10, c11, c12, c13;
    uint32_t c20, c21, c22, c23;
    uint32_t vc1, vc2;
    ;
    uint32_t* masks = (uint32_t*)XoodooMask;
    a00 = state[0 + 0], a01 = state[0 + 1], a02 = state[0 + 2],
    a03 = state[0 + 3];
    a10 = state[4 + 0], a11 = state[4 + 1], a12 = state[4 + 2],
    a13 = state[4 + 3];
    a20 = state[8 + 0], a21 = state[8 + 1], a22 = state[8 + 2],
    a23 = state[8 + 3];
    b00 = masks[0 + 0], b01 = masks[0 + 1], b02 = masks[0 + 2],
    b03 = masks[0 + 3];
    b10 = masks[4 + 0], b11 = masks[4 + 1], b12 = masks[4 + 2],
    b13 = masks[4 + 3];
    b20 = masks[8 + 0], b21 = masks[8 + 1], b22 = masks[8 + 2],
    b23 = masks[8 + 3];
    c00 = masks[12 + 0], c01 = masks[12 + 1], c02 = masks[12 + 2],
    c03 = masks[12 + 3];
    c10 = masks[16 + 0], c11 = masks[16 + 1], c12 = masks[16 + 2],
    c13 = masks[16 + 3];
    c20 = masks[20 + 0], c21 = masks[20 + 1], c22 = masks[20 + 2],
    c23 = masks[20 + 3];
    ;
    va1 = a03 ^ a13 ^ a23;
    va2 = a00 ^ a10 ^ a20;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a00 ^= va1;
    a10 ^= va1;
    a20 ^= va1;
    va1 = a01 ^ a11 ^ a21;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a01 ^= va2;
    a11 ^= va2;
    a21 ^= va2;
    va2 = a02 ^ a12 ^ a22;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a02 ^= va1;
    a12 ^= va1;
    a22 ^= va1;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a03 ^= va2;
    a13 ^= va2;
    a23 ^= va2;
    vb1 = b03 ^ b13 ^ b23;
    vb2 = b00 ^ b10 ^ b20;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b00 ^= vb1;
    b10 ^= vb1;
    b20 ^= vb1;
    vb1 = b01 ^ b11 ^ b21;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b01 ^= vb2;
    b11 ^= vb2;
    b21 ^= vb2;
    vb2 = b02 ^ b12 ^ b22;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b02 ^= vb1;
    b12 ^= vb1;
    b22 ^= vb1;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b03 ^= vb2;
    b13 ^= vb2;
    b23 ^= vb2;
    vc1 = c03 ^ c13 ^ c23;
    vc2 = c00 ^ c10 ^ c20;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c00 ^= vc1;
    c10 ^= vc1;
    c20 ^= vc1;
    vc1 = c01 ^ c11 ^ c21;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c01 ^= vc2;
    c11 ^= vc2;
    c21 ^= vc2;
    vc2 = c02 ^ c12 ^ c22;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c02 ^= vc1;
    c12 ^= vc1;
    c22 ^= vc1;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c03 ^= vc2;
    c13 ^= vc2;
    c23 ^= vc2;
    ;
    a20 = ((((uint32_t)a20) << ((11) % 32)) ^
           (((uint32_t)a20) >> ((32 - (11)) % 32)));
    a21 = ((((uint32_t)a21) << ((11) % 32)) ^
           (((uint32_t)a21) >> ((32 - (11)) % 32)));
    a22 = ((((uint32_t)a22) << ((11) % 32)) ^
           (((uint32_t)a22) >> ((32 - (11)) % 32)));
    a23 = ((((uint32_t)a23) << ((11) % 32)) ^
           (((uint32_t)a23) >> ((32 - (11)) % 32)));
    va1 = a13;
    a13 = a12;
    a12 = a11;
    a11 = a10;
    a10 = va1;
    b20 = ((((uint32_t)b20) << ((11) % 32)) ^
           (((uint32_t)b20) >> ((32 - (11)) % 32)));
    b21 = ((((uint32_t)b21) << ((11) % 32)) ^
           (((uint32_t)b21) >> ((32 - (11)) % 32)));
    b22 = ((((uint32_t)b22) << ((11) % 32)) ^
           (((uint32_t)b22) >> ((32 - (11)) % 32)));
    b23 = ((((uint32_t)b23) << ((11) % 32)) ^
           (((uint32_t)b23) >> ((32 - (11)) % 32)));
    vb1 = b13;
    b13 = b12;
    b12 = b11;
    b11 = b10;
    b10 = vb1;
    c20 = ((((uint32_t)c20) << ((11) % 32)) ^
           (((uint32_t)c20) >> ((32 - (11)) % 32)));
    c21 = ((((uint32_t)c21) << ((11) % 32)) ^
           (((uint32_t)c21) >> ((32 - (11)) % 32)));
    c22 = ((((uint32_t)c22) << ((11) % 32)) ^
           (((uint32_t)c22) >> ((32 - (11)) % 32)));
    c23 = ((((uint32_t)c23) << ((11) % 32)) ^
           (((uint32_t)c23) >> ((32 - (11)) % 32)));
    vc1 = c13;
    c13 = c12;
    c12 = c11;
    c11 = c10;
    c10 = vc1;
    ;
    a00 ^= 0x00000060;
    ;
    a00 ^= (~a10 & a20) ^ (a10 & b20) ^ (b10 & a20);
    b00 ^= (~b10 & b20) ^ (b10 & c20) ^ (c10 & b20);
    c00 ^= (~c10 & c20) ^ (c10 & a20) ^ (a10 & c20);
    a01 ^= (~a11 & a21) ^ (a11 & b21) ^ (b11 & a21);
    b01 ^= (~b11 & b21) ^ (b11 & c21) ^ (c11 & b21);
    c01 ^= (~c11 & c21) ^ (c11 & a21) ^ (a11 & c21);
    a02 ^= (~a12 & a22) ^ (a12 & b22) ^ (b12 & a22);
    b02 ^= (~b12 & b22) ^ (b12 & c22) ^ (c12 & b22);
    c02 ^= (~c12 & c22) ^ (c12 & a22) ^ (a12 & c22);
    a03 ^= (~a13 & a23) ^ (a13 & b23) ^ (b13 & a23);
    b03 ^= (~b13 & b23) ^ (b13 & c23) ^ (c13 & b23);
    c03 ^= (~c13 & c23) ^ (c13 & a23) ^ (a13 & c23);
    a10 ^= (~a20 & a00) ^ (a20 & b00) ^ (b20 & a00);
    b10 ^= (~b20 & b00) ^ (b20 & c00) ^ (c20 & b00);
    c10 ^= (~c20 & c00) ^ (c20 & a00) ^ (a20 & c00);
    a11 ^= (~a21 & a01) ^ (a21 & b01) ^ (b21 & a01);
    b11 ^= (~b21 & b01) ^ (b21 & c01) ^ (c21 & b01);
    c11 ^= (~c21 & c01) ^ (c21 & a01) ^ (a21 & c01);
    a12 ^= (~a22 & a02) ^ (a22 & b02) ^ (b22 & a02);
    b12 ^= (~b22 & b02) ^ (b22 & c02) ^ (c22 & b02);
    c12 ^= (~c22 & c02) ^ (c22 & a02) ^ (a22 & c02);
    a13 ^= (~a23 & a03) ^ (a23 & b03) ^ (b23 & a03);
    b13 ^= (~b23 & b03) ^ (b23 & c03) ^ (c23 & b03);
    c13 ^= (~c23 & c03) ^ (c23 & a03) ^ (a23 & c03);
    a20 ^= (~a00 & a10) ^ (a00 & b10) ^ (b00 & a10);
    b20 ^= (~b00 & b10) ^ (b00 & c10) ^ (c00 & b10);
    c20 ^= (~c00 & c10) ^ (c00 & a10) ^ (a00 & c10);
    a21 ^= (~a01 & a11) ^ (a01 & b11) ^ (b01 & a11);
    b21 ^= (~b01 & b11) ^ (b01 & c11) ^ (c01 & b11);
    c21 ^= (~c01 & c11) ^ (c01 & a11) ^ (a01 & c11);
    a22 ^= (~a02 & a12) ^ (a02 & b12) ^ (b02 & a12);
    b22 ^= (~b02 & b12) ^ (b02 & c12) ^ (c02 & b12);
    c22 ^= (~c02 & c12) ^ (c02 & a12) ^ (a02 & c12);
    a23 ^= (~a03 & a13) ^ (a03 & b13) ^ (b03 & a13);
    b23 ^= (~b03 & b13) ^ (b03 & c13) ^ (c03 & b13);
    c23 ^= (~c03 & c13) ^ (c03 & a13) ^ (a03 & c13);
    ;
    ;
    a10 = ((((uint32_t)a10) << ((1) % 32)) ^
           (((uint32_t)a10) >> ((32 - (1)) % 32)));
    a11 = ((((uint32_t)a11) << ((1) % 32)) ^
           (((uint32_t)a11) >> ((32 - (1)) % 32)));
    a12 = ((((uint32_t)a12) << ((1) % 32)) ^
           (((uint32_t)a12) >> ((32 - (1)) % 32)));
    a13 = ((((uint32_t)a13) << ((1) % 32)) ^
           (((uint32_t)a13) >> ((32 - (1)) % 32)));
    va1 = ((((uint32_t)a23) << ((8) % 32)) ^
           (((uint32_t)a23) >> ((32 - (8)) % 32)));
    a23 = ((((uint32_t)a21) << ((8) % 32)) ^
           (((uint32_t)a21) >> ((32 - (8)) % 32)));
    a21 = va1;
    va1 = ((((uint32_t)a22) << ((8) % 32)) ^
           (((uint32_t)a22) >> ((32 - (8)) % 32)));
    a22 = ((((uint32_t)a20) << ((8) % 32)) ^
           (((uint32_t)a20) >> ((32 - (8)) % 32)));
    a20 = va1;
    b10 = ((((uint32_t)b10) << ((1) % 32)) ^
           (((uint32_t)b10) >> ((32 - (1)) % 32)));
    b11 = ((((uint32_t)b11) << ((1) % 32)) ^
           (((uint32_t)b11) >> ((32 - (1)) % 32)));
    b12 = ((((uint32_t)b12) << ((1) % 32)) ^
           (((uint32_t)b12) >> ((32 - (1)) % 32)));
    b13 = ((((uint32_t)b13) << ((1) % 32)) ^
           (((uint32_t)b13) >> ((32 - (1)) % 32)));
    vb1 = ((((uint32_t)b23) << ((8) % 32)) ^
           (((uint32_t)b23) >> ((32 - (8)) % 32)));
    b23 = ((((uint32_t)b21) << ((8) % 32)) ^
           (((uint32_t)b21) >> ((32 - (8)) % 32)));
    b21 = vb1;
    vb1 = ((((uint32_t)b22) << ((8) % 32)) ^
           (((uint32_t)b22) >> ((32 - (8)) % 32)));
    b22 = ((((uint32_t)b20) << ((8) % 32)) ^
           (((uint32_t)b20) >> ((32 - (8)) % 32)));
    b20 = vb1;
    c10 = ((((uint32_t)c10) << ((1) % 32)) ^
           (((uint32_t)c10) >> ((32 - (1)) % 32)));
    c11 = ((((uint32_t)c11) << ((1) % 32)) ^
           (((uint32_t)c11) >> ((32 - (1)) % 32)));
    c12 = ((((uint32_t)c12) << ((1) % 32)) ^
           (((uint32_t)c12) >> ((32 - (1)) % 32)));
    c13 = ((((uint32_t)c13) << ((1) % 32)) ^
           (((uint32_t)c13) >> ((32 - (1)) % 32)));
    vc1 = ((((uint32_t)c23) << ((8) % 32)) ^
           (((uint32_t)c23) >> ((32 - (8)) % 32)));
    c23 = ((((uint32_t)c21) << ((8) % 32)) ^
           (((uint32_t)c21) >> ((32 - (8)) % 32)));
    c21 = vc1;
    vc1 = ((((uint32_t)c22) << ((8) % 32)) ^
           (((uint32_t)c22) >> ((32 - (8)) % 32)));
    c22 = ((((uint32_t)c20) << ((8) % 32)) ^
           (((uint32_t)c20) >> ((32 - (8)) % 32)));
    c20 = vc1;
    ;
    va1 = a03 ^ a13 ^ a23;
    va2 = a00 ^ a10 ^ a20;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a00 ^= va1;
    a10 ^= va1;
    a20 ^= va1;
    va1 = a01 ^ a11 ^ a21;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a01 ^= va2;
    a11 ^= va2;
    a21 ^= va2;
    va2 = a02 ^ a12 ^ a22;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a02 ^= va1;
    a12 ^= va1;
    a22 ^= va1;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a03 ^= va2;
    a13 ^= va2;
    a23 ^= va2;
    vb1 = b03 ^ b13 ^ b23;
    vb2 = b00 ^ b10 ^ b20;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b00 ^= vb1;
    b10 ^= vb1;
    b20 ^= vb1;
    vb1 = b01 ^ b11 ^ b21;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b01 ^= vb2;
    b11 ^= vb2;
    b21 ^= vb2;
    vb2 = b02 ^ b12 ^ b22;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b02 ^= vb1;
    b12 ^= vb1;
    b22 ^= vb1;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b03 ^= vb2;
    b13 ^= vb2;
    b23 ^= vb2;
    vc1 = c03 ^ c13 ^ c23;
    vc2 = c00 ^ c10 ^ c20;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c00 ^= vc1;
    c10 ^= vc1;
    c20 ^= vc1;
    vc1 = c01 ^ c11 ^ c21;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c01 ^= vc2;
    c11 ^= vc2;
    c21 ^= vc2;
    vc2 = c02 ^ c12 ^ c22;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c02 ^= vc1;
    c12 ^= vc1;
    c22 ^= vc1;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c03 ^= vc2;
    c13 ^= vc2;
    c23 ^= vc2;
    ;
    a20 = ((((uint32_t)a20) << ((11) % 32)) ^
           (((uint32_t)a20) >> ((32 - (11)) % 32)));
    a21 = ((((uint32_t)a21) << ((11) % 32)) ^
           (((uint32_t)a21) >> ((32 - (11)) % 32)));
    a22 = ((((uint32_t)a22) << ((11) % 32)) ^
           (((uint32_t)a22) >> ((32 - (11)) % 32)));
    a23 = ((((uint32_t)a23) << ((11) % 32)) ^
           (((uint32_t)a23) >> ((32 - (11)) % 32)));
    va1 = a13;
    a13 = a12;
    a12 = a11;
    a11 = a10;
    a10 = va1;
    b20 = ((((uint32_t)b20) << ((11) % 32)) ^
           (((uint32_t)b20) >> ((32 - (11)) % 32)));
    b21 = ((((uint32_t)b21) << ((11) % 32)) ^
           (((uint32_t)b21) >> ((32 - (11)) % 32)));
    b22 = ((((uint32_t)b22) << ((11) % 32)) ^
           (((uint32_t)b22) >> ((32 - (11)) % 32)));
    b23 = ((((uint32_t)b23) << ((11) % 32)) ^
           (((uint32_t)b23) >> ((32 - (11)) % 32)));
    vb1 = b13;
    b13 = b12;
    b12 = b11;
    b11 = b10;
    b10 = vb1;
    c20 = ((((uint32_t)c20) << ((11) % 32)) ^
           (((uint32_t)c20) >> ((32 - (11)) % 32)));
    c21 = ((((uint32_t)c21) << ((11) % 32)) ^
           (((uint32_t)c21) >> ((32 - (11)) % 32)));
    c22 = ((((uint32_t)c22) << ((11) % 32)) ^
           (((uint32_t)c22) >> ((32 - (11)) % 32)));
    c23 = ((((uint32_t)c23) << ((11) % 32)) ^
           (((uint32_t)c23) >> ((32 - (11)) % 32)));
    vc1 = c13;
    c13 = c12;
    c12 = c11;
    c11 = c10;
    c10 = vc1;
    ;
    a00 ^= 0x0000002C;
    ;
    a00 ^= (~a10 & a20) ^ (a10 & b20) ^ (b10 & a20);
    b00 ^= (~b10 & b20) ^ (b10 & c20) ^ (c10 & b20);
    c00 ^= (~c10 & c20) ^ (c10 & a20) ^ (a10 & c20);
    a01 ^= (~a11 & a21) ^ (a11 & b21) ^ (b11 & a21);
    b01 ^= (~b11 & b21) ^ (b11 & c21) ^ (c11 & b21);
    c01 ^= (~c11 & c21) ^ (c11 & a21) ^ (a11 & c21);
    a02 ^= (~a12 & a22) ^ (a12 & b22) ^ (b12 & a22);
    b02 ^= (~b12 & b22) ^ (b12 & c22) ^ (c12 & b22);
    c02 ^= (~c12 & c22) ^ (c12 & a22) ^ (a12 & c22);
    a03 ^= (~a13 & a23) ^ (a13 & b23) ^ (b13 & a23);
    b03 ^= (~b13 & b23) ^ (b13 & c23) ^ (c13 & b23);
    c03 ^= (~c13 & c23) ^ (c13 & a23) ^ (a13 & c23);
    a10 ^= (~a20 & a00) ^ (a20 & b00) ^ (b20 & a00);
    b10 ^= (~b20 & b00) ^ (b20 & c00) ^ (c20 & b00);
    c10 ^= (~c20 & c00) ^ (c20 & a00) ^ (a20 & c00);
    a11 ^= (~a21 & a01) ^ (a21 & b01) ^ (b21 & a01);
    b11 ^= (~b21 & b01) ^ (b21 & c01) ^ (c21 & b01);
    c11 ^= (~c21 & c01) ^ (c21 & a01) ^ (a21 & c01);
    a12 ^= (~a22 & a02) ^ (a22 & b02) ^ (b22 & a02);
    b12 ^= (~b22 & b02) ^ (b22 & c02) ^ (c22 & b02);
    c12 ^= (~c22 & c02) ^ (c22 & a02) ^ (a22 & c02);
    a13 ^= (~a23 & a03) ^ (a23 & b03) ^ (b23 & a03);
    b13 ^= (~b23 & b03) ^ (b23 & c03) ^ (c23 & b03);
    c13 ^= (~c23 & c03) ^ (c23 & a03) ^ (a23 & c03);
    a20 ^= (~a00 & a10) ^ (a00 & b10) ^ (b00 & a10);
    b20 ^= (~b00 & b10) ^ (b00 & c10) ^ (c00 & b10);
    c20 ^= (~c00 & c10) ^ (c00 & a10) ^ (a00 & c10);
    a21 ^= (~a01 & a11) ^ (a01 & b11) ^ (b01 & a11);
    b21 ^= (~b01 & b11) ^ (b01 & c11) ^ (c01 & b11);
    c21 ^= (~c01 & c11) ^ (c01 & a11) ^ (a01 & c11);
    a22 ^= (~a02 & a12) ^ (a02 & b12) ^ (b02 & a12);
    b22 ^= (~b02 & b12) ^ (b02 & c12) ^ (c02 & b12);
    c22 ^= (~c02 & c12) ^ (c02 & a12) ^ (a02 & c12);
    a23 ^= (~a03 & a13) ^ (a03 & b13) ^ (b03 & a13);
    b23 ^= (~b03 & b13) ^ (b03 & c13) ^ (c03 & b13);
    c23 ^= (~c03 & c13) ^ (c03 & a13) ^ (a03 & c13);
    ;
    ;
    a10 = ((((uint32_t)a10) << ((1) % 32)) ^
           (((uint32_t)a10) >> ((32 - (1)) % 32)));
    a11 = ((((uint32_t)a11) << ((1) % 32)) ^
           (((uint32_t)a11) >> ((32 - (1)) % 32)));
    a12 = ((((uint32_t)a12) << ((1) % 32)) ^
           (((uint32_t)a12) >> ((32 - (1)) % 32)));
    a13 = ((((uint32_t)a13) << ((1) % 32)) ^
           (((uint32_t)a13) >> ((32 - (1)) % 32)));
    va1 = ((((uint32_t)a23) << ((8) % 32)) ^
           (((uint32_t)a23) >> ((32 - (8)) % 32)));
    a23 = ((((uint32_t)a21) << ((8) % 32)) ^
           (((uint32_t)a21) >> ((32 - (8)) % 32)));
    a21 = va1;
    va1 = ((((uint32_t)a22) << ((8) % 32)) ^
           (((uint32_t)a22) >> ((32 - (8)) % 32)));
    a22 = ((((uint32_t)a20) << ((8) % 32)) ^
           (((uint32_t)a20) >> ((32 - (8)) % 32)));
    a20 = va1;
    b10 = ((((uint32_t)b10) << ((1) % 32)) ^
           (((uint32_t)b10) >> ((32 - (1)) % 32)));
    b11 = ((((uint32_t)b11) << ((1) % 32)) ^
           (((uint32_t)b11) >> ((32 - (1)) % 32)));
    b12 = ((((uint32_t)b12) << ((1) % 32)) ^
           (((uint32_t)b12) >> ((32 - (1)) % 32)));
    b13 = ((((uint32_t)b13) << ((1) % 32)) ^
           (((uint32_t)b13) >> ((32 - (1)) % 32)));
    vb1 = ((((uint32_t)b23) << ((8) % 32)) ^
           (((uint32_t)b23) >> ((32 - (8)) % 32)));
    b23 = ((((uint32_t)b21) << ((8) % 32)) ^
           (((uint32_t)b21) >> ((32 - (8)) % 32)));
    b21 = vb1;
    vb1 = ((((uint32_t)b22) << ((8) % 32)) ^
           (((uint32_t)b22) >> ((32 - (8)) % 32)));
    b22 = ((((uint32_t)b20) << ((8) % 32)) ^
           (((uint32_t)b20) >> ((32 - (8)) % 32)));
    b20 = vb1;
    c10 = ((((uint32_t)c10) << ((1) % 32)) ^
           (((uint32_t)c10) >> ((32 - (1)) % 32)));
    c11 = ((((uint32_t)c11) << ((1) % 32)) ^
           (((uint32_t)c11) >> ((32 - (1)) % 32)));
    c12 = ((((uint32_t)c12) << ((1) % 32)) ^
           (((uint32_t)c12) >> ((32 - (1)) % 32)));
    c13 = ((((uint32_t)c13) << ((1) % 32)) ^
           (((uint32_t)c13) >> ((32 - (1)) % 32)));
    vc1 = ((((uint32_t)c23) << ((8) % 32)) ^
           (((uint32_t)c23) >> ((32 - (8)) % 32)));
    c23 = ((((uint32_t)c21) << ((8) % 32)) ^
           (((uint32_t)c21) >> ((32 - (8)) % 32)));
    c21 = vc1;
    vc1 = ((((uint32_t)c22) << ((8) % 32)) ^
           (((uint32_t)c22) >> ((32 - (8)) % 32)));
    c22 = ((((uint32_t)c20) << ((8) % 32)) ^
           (((uint32_t)c20) >> ((32 - (8)) % 32)));
    c20 = vc1;
    ;
    va1 = a03 ^ a13 ^ a23;
    va2 = a00 ^ a10 ^ a20;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a00 ^= va1;
    a10 ^= va1;
    a20 ^= va1;
    va1 = a01 ^ a11 ^ a21;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a01 ^= va2;
    a11 ^= va2;
    a21 ^= va2;
    va2 = a02 ^ a12 ^ a22;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a02 ^= va1;
    a12 ^= va1;
    a22 ^= va1;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a03 ^= va2;
    a13 ^= va2;
    a23 ^= va2;
    vb1 = b03 ^ b13 ^ b23;
    vb2 = b00 ^ b10 ^ b20;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b00 ^= vb1;
    b10 ^= vb1;
    b20 ^= vb1;
    vb1 = b01 ^ b11 ^ b21;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b01 ^= vb2;
    b11 ^= vb2;
    b21 ^= vb2;
    vb2 = b02 ^ b12 ^ b22;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b02 ^= vb1;
    b12 ^= vb1;
    b22 ^= vb1;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b03 ^= vb2;
    b13 ^= vb2;
    b23 ^= vb2;
    vc1 = c03 ^ c13 ^ c23;
    vc2 = c00 ^ c10 ^ c20;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c00 ^= vc1;
    c10 ^= vc1;
    c20 ^= vc1;
    vc1 = c01 ^ c11 ^ c21;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c01 ^= vc2;
    c11 ^= vc2;
    c21 ^= vc2;
    vc2 = c02 ^ c12 ^ c22;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c02 ^= vc1;
    c12 ^= vc1;
    c22 ^= vc1;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c03 ^= vc2;
    c13 ^= vc2;
    c23 ^= vc2;
    ;
    a20 = ((((uint32_t)a20) << ((11) % 32)) ^
           (((uint32_t)a20) >> ((32 - (11)) % 32)));
    a21 = ((((uint32_t)a21) << ((11) % 32)) ^
           (((uint32_t)a21) >> ((32 - (11)) % 32)));
    a22 = ((((uint32_t)a22) << ((11) % 32)) ^
           (((uint32_t)a22) >> ((32 - (11)) % 32)));
    a23 = ((((uint32_t)a23) << ((11) % 32)) ^
           (((uint32_t)a23) >> ((32 - (11)) % 32)));
    va1 = a13;
    a13 = a12;
    a12 = a11;
    a11 = a10;
    a10 = va1;
    b20 = ((((uint32_t)b20) << ((11) % 32)) ^
           (((uint32_t)b20) >> ((32 - (11)) % 32)));
    b21 = ((((uint32_t)b21) << ((11) % 32)) ^
           (((uint32_t)b21) >> ((32 - (11)) % 32)));
    b22 = ((((uint32_t)b22) << ((11) % 32)) ^
           (((uint32_t)b22) >> ((32 - (11)) % 32)));
    b23 = ((((uint32_t)b23) << ((11) % 32)) ^
           (((uint32_t)b23) >> ((32 - (11)) % 32)));
    vb1 = b13;
    b13 = b12;
    b12 = b11;
    b11 = b10;
    b10 = vb1;
    c20 = ((((uint32_t)c20) << ((11) % 32)) ^
           (((uint32_t)c20) >> ((32 - (11)) % 32)));
    c21 = ((((uint32_t)c21) << ((11) % 32)) ^
           (((uint32_t)c21) >> ((32 - (11)) % 32)));
    c22 = ((((uint32_t)c22) << ((11) % 32)) ^
           (((uint32_t)c22) >> ((32 - (11)) % 32)));
    c23 = ((((uint32_t)c23) << ((11) % 32)) ^
           (((uint32_t)c23) >> ((32 - (11)) % 32)));
    vc1 = c13;
    c13 = c12;
    c12 = c11;
    c11 = c10;
    c10 = vc1;
    ;
    a00 ^= 0x00000380;
    ;
    a00 ^= (~a10 & a20) ^ (a10 & b20) ^ (b10 & a20);
    b00 ^= (~b10 & b20) ^ (b10 & c20) ^ (c10 & b20);
    c00 ^= (~c10 & c20) ^ (c10 & a20) ^ (a10 & c20);
    a01 ^= (~a11 & a21) ^ (a11 & b21) ^ (b11 & a21);
    b01 ^= (~b11 & b21) ^ (b11 & c21) ^ (c11 & b21);
    c01 ^= (~c11 & c21) ^ (c11 & a21) ^ (a11 & c21);
    a02 ^= (~a12 & a22) ^ (a12 & b22) ^ (b12 & a22);
    b02 ^= (~b12 & b22) ^ (b12 & c22) ^ (c12 & b22);
    c02 ^= (~c12 & c22) ^ (c12 & a22) ^ (a12 & c22);
    a03 ^= (~a13 & a23) ^ (a13 & b23) ^ (b13 & a23);
    b03 ^= (~b13 & b23) ^ (b13 & c23) ^ (c13 & b23);
    c03 ^= (~c13 & c23) ^ (c13 & a23) ^ (a13 & c23);
    a10 ^= (~a20 & a00) ^ (a20 & b00) ^ (b20 & a00);
    b10 ^= (~b20 & b00) ^ (b20 & c00) ^ (c20 & b00);
    c10 ^= (~c20 & c00) ^ (c20 & a00) ^ (a20 & c00);
    a11 ^= (~a21 & a01) ^ (a21 & b01) ^ (b21 & a01);
    b11 ^= (~b21 & b01) ^ (b21 & c01) ^ (c21 & b01);
    c11 ^= (~c21 & c01) ^ (c21 & a01) ^ (a21 & c01);
    a12 ^= (~a22 & a02) ^ (a22 & b02) ^ (b22 & a02);
    b12 ^= (~b22 & b02) ^ (b22 & c02) ^ (c22 & b02);
    c12 ^= (~c22 & c02) ^ (c22 & a02) ^ (a22 & c02);
    a13 ^= (~a23 & a03) ^ (a23 & b03) ^ (b23 & a03);
    b13 ^= (~b23 & b03) ^ (b23 & c03) ^ (c23 & b03);
    c13 ^= (~c23 & c03) ^ (c23 & a03) ^ (a23 & c03);
    a20 ^= (~a00 & a10) ^ (a00 & b10) ^ (b00 & a10);
    b20 ^= (~b00 & b10) ^ (b00 & c10) ^ (c00 & b10);
    c20 ^= (~c00 & c10) ^ (c00 & a10) ^ (a00 & c10);
    a21 ^= (~a01 & a11) ^ (a01 & b11) ^ (b01 & a11);
    b21 ^= (~b01 & b11) ^ (b01 & c11) ^ (c01 & b11);
    c21 ^= (~c01 & c11) ^ (c01 & a11) ^ (a01 & c11);
    a22 ^= (~a02 & a12) ^ (a02 & b12) ^ (b02 & a12);
    b22 ^= (~b02 & b12) ^ (b02 & c12) ^ (c02 & b12);
    c22 ^= (~c02 & c12) ^ (c02 & a12) ^ (a02 & c12);
    a23 ^= (~a03 & a13) ^ (a03 & b13) ^ (b03 & a13);
    b23 ^= (~b03 & b13) ^ (b03 & c13) ^ (c03 & b13);
    c23 ^= (~c03 & c13) ^ (c03 & a13) ^ (a03 & c13);
    ;
    ;
    a10 = ((((uint32_t)a10) << ((1) % 32)) ^
           (((uint32_t)a10) >> ((32 - (1)) % 32)));
    a11 = ((((uint32_t)a11) << ((1) % 32)) ^
           (((uint32_t)a11) >> ((32 - (1)) % 32)));
    a12 = ((((uint32_t)a12) << ((1) % 32)) ^
           (((uint32_t)a12) >> ((32 - (1)) % 32)));
    a13 = ((((uint32_t)a13) << ((1) % 32)) ^
           (((uint32_t)a13) >> ((32 - (1)) % 32)));
    va1 = ((((uint32_t)a23) << ((8) % 32)) ^
           (((uint32_t)a23) >> ((32 - (8)) % 32)));
    a23 = ((((uint32_t)a21) << ((8) % 32)) ^
           (((uint32_t)a21) >> ((32 - (8)) % 32)));
    a21 = va1;
    va1 = ((((uint32_t)a22) << ((8) % 32)) ^
           (((uint32_t)a22) >> ((32 - (8)) % 32)));
    a22 = ((((uint32_t)a20) << ((8) % 32)) ^
           (((uint32_t)a20) >> ((32 - (8)) % 32)));
    a20 = va1;
    b10 = ((((uint32_t)b10) << ((1) % 32)) ^
           (((uint32_t)b10) >> ((32 - (1)) % 32)));
    b11 = ((((uint32_t)b11) << ((1) % 32)) ^
           (((uint32_t)b11) >> ((32 - (1)) % 32)));
    b12 = ((((uint32_t)b12) << ((1) % 32)) ^
           (((uint32_t)b12) >> ((32 - (1)) % 32)));
    b13 = ((((uint32_t)b13) << ((1) % 32)) ^
           (((uint32_t)b13) >> ((32 - (1)) % 32)));
    vb1 = ((((uint32_t)b23) << ((8) % 32)) ^
           (((uint32_t)b23) >> ((32 - (8)) % 32)));
    b23 = ((((uint32_t)b21) << ((8) % 32)) ^
           (((uint32_t)b21) >> ((32 - (8)) % 32)));
    b21 = vb1;
    vb1 = ((((uint32_t)b22) << ((8) % 32)) ^
           (((uint32_t)b22) >> ((32 - (8)) % 32)));
    b22 = ((((uint32_t)b20) << ((8) % 32)) ^
           (((uint32_t)b20) >> ((32 - (8)) % 32)));
    b20 = vb1;
    c10 = ((((uint32_t)c10) << ((1) % 32)) ^
           (((uint32_t)c10) >> ((32 - (1)) % 32)));
    c11 = ((((uint32_t)c11) << ((1) % 32)) ^
           (((uint32_t)c11) >> ((32 - (1)) % 32)));
    c12 = ((((uint32_t)c12) << ((1) % 32)) ^
           (((uint32_t)c12) >> ((32 - (1)) % 32)));
    c13 = ((((uint32_t)c13) << ((1) % 32)) ^
           (((uint32_t)c13) >> ((32 - (1)) % 32)));
    vc1 = ((((uint32_t)c23) << ((8) % 32)) ^
           (((uint32_t)c23) >> ((32 - (8)) % 32)));
    c23 = ((((uint32_t)c21) << ((8) % 32)) ^
           (((uint32_t)c21) >> ((32 - (8)) % 32)));
    c21 = vc1;
    vc1 = ((((uint32_t)c22) << ((8) % 32)) ^
           (((uint32_t)c22) >> ((32 - (8)) % 32)));
    c22 = ((((uint32_t)c20) << ((8) % 32)) ^
           (((uint32_t)c20) >> ((32 - (8)) % 32)));
    c20 = vc1;
    ;
    va1 = a03 ^ a13 ^ a23;
    va2 = a00 ^ a10 ^ a20;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a00 ^= va1;
    a10 ^= va1;
    a20 ^= va1;
    va1 = a01 ^ a11 ^ a21;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a01 ^= va2;
    a11 ^= va2;
    a21 ^= va2;
    va2 = a02 ^ a12 ^ a22;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a02 ^= va1;
    a12 ^= va1;
    a22 ^= va1;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a03 ^= va2;
    a13 ^= va2;
    a23 ^= va2;
    vb1 = b03 ^ b13 ^ b23;
    vb2 = b00 ^ b10 ^ b20;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b00 ^= vb1;
    b10 ^= vb1;
    b20 ^= vb1;
    vb1 = b01 ^ b11 ^ b21;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b01 ^= vb2;
    b11 ^= vb2;
    b21 ^= vb2;
    vb2 = b02 ^ b12 ^ b22;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b02 ^= vb1;
    b12 ^= vb1;
    b22 ^= vb1;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b03 ^= vb2;
    b13 ^= vb2;
    b23 ^= vb2;
    vc1 = c03 ^ c13 ^ c23;
    vc2 = c00 ^ c10 ^ c20;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c00 ^= vc1;
    c10 ^= vc1;
    c20 ^= vc1;
    vc1 = c01 ^ c11 ^ c21;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c01 ^= vc2;
    c11 ^= vc2;
    c21 ^= vc2;
    vc2 = c02 ^ c12 ^ c22;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c02 ^= vc1;
    c12 ^= vc1;
    c22 ^= vc1;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c03 ^= vc2;
    c13 ^= vc2;
    c23 ^= vc2;
    ;
    a20 = ((((uint32_t)a20) << ((11) % 32)) ^
           (((uint32_t)a20) >> ((32 - (11)) % 32)));
    a21 = ((((uint32_t)a21) << ((11) % 32)) ^
           (((uint32_t)a21) >> ((32 - (11)) % 32)));
    a22 = ((((uint32_t)a22) << ((11) % 32)) ^
           (((uint32_t)a22) >> ((32 - (11)) % 32)));
    a23 = ((((uint32_t)a23) << ((11) % 32)) ^
           (((uint32_t)a23) >> ((32 - (11)) % 32)));
    va1 = a13;
    a13 = a12;
    a12 = a11;
    a11 = a10;
    a10 = va1;
    b20 = ((((uint32_t)b20) << ((11) % 32)) ^
           (((uint32_t)b20) >> ((32 - (11)) % 32)));
    b21 = ((((uint32_t)b21) << ((11) % 32)) ^
           (((uint32_t)b21) >> ((32 - (11)) % 32)));
    b22 = ((((uint32_t)b22) << ((11) % 32)) ^
           (((uint32_t)b22) >> ((32 - (11)) % 32)));
    b23 = ((((uint32_t)b23) << ((11) % 32)) ^
           (((uint32_t)b23) >> ((32 - (11)) % 32)));
    vb1 = b13;
    b13 = b12;
    b12 = b11;
    b11 = b10;
    b10 = vb1;
    c20 = ((((uint32_t)c20) << ((11) % 32)) ^
           (((uint32_t)c20) >> ((32 - (11)) % 32)));
    c21 = ((((uint32_t)c21) << ((11) % 32)) ^
           (((uint32_t)c21) >> ((32 - (11)) % 32)));
    c22 = ((((uint32_t)c22) << ((11) % 32)) ^
           (((uint32_t)c22) >> ((32 - (11)) % 32)));
    c23 = ((((uint32_t)c23) << ((11) % 32)) ^
           (((uint32_t)c23) >> ((32 - (11)) % 32)));
    vc1 = c13;
    c13 = c12;
    c12 = c11;
    c11 = c10;
    c10 = vc1;
    ;
    a00 ^= 0x000000F0;
    ;
    a00 ^= (~a10 & a20) ^ (a10 & b20) ^ (b10 & a20);
    b00 ^= (~b10 & b20) ^ (b10 & c20) ^ (c10 & b20);
    c00 ^= (~c10 & c20) ^ (c10 & a20) ^ (a10 & c20);
    a01 ^= (~a11 & a21) ^ (a11 & b21) ^ (b11 & a21);
    b01 ^= (~b11 & b21) ^ (b11 & c21) ^ (c11 & b21);
    c01 ^= (~c11 & c21) ^ (c11 & a21) ^ (a11 & c21);
    a02 ^= (~a12 & a22) ^ (a12 & b22) ^ (b12 & a22);
    b02 ^= (~b12 & b22) ^ (b12 & c22) ^ (c12 & b22);
    c02 ^= (~c12 & c22) ^ (c12 & a22) ^ (a12 & c22);
    a03 ^= (~a13 & a23) ^ (a13 & b23) ^ (b13 & a23);
    b03 ^= (~b13 & b23) ^ (b13 & c23) ^ (c13 & b23);
    c03 ^= (~c13 & c23) ^ (c13 & a23) ^ (a13 & c23);
    a10 ^= (~a20 & a00) ^ (a20 & b00) ^ (b20 & a00);
    b10 ^= (~b20 & b00) ^ (b20 & c00) ^ (c20 & b00);
    c10 ^= (~c20 & c00) ^ (c20 & a00) ^ (a20 & c00);
    a11 ^= (~a21 & a01) ^ (a21 & b01) ^ (b21 & a01);
    b11 ^= (~b21 & b01) ^ (b21 & c01) ^ (c21 & b01);
    c11 ^= (~c21 & c01) ^ (c21 & a01) ^ (a21 & c01);
    a12 ^= (~a22 & a02) ^ (a22 & b02) ^ (b22 & a02);
    b12 ^= (~b22 & b02) ^ (b22 & c02) ^ (c22 & b02);
    c12 ^= (~c22 & c02) ^ (c22 & a02) ^ (a22 & c02);
    a13 ^= (~a23 & a03) ^ (a23 & b03) ^ (b23 & a03);
    b13 ^= (~b23 & b03) ^ (b23 & c03) ^ (c23 & b03);
    c13 ^= (~c23 & c03) ^ (c23 & a03) ^ (a23 & c03);
    a20 ^= (~a00 & a10) ^ (a00 & b10) ^ (b00 & a10);
    b20 ^= (~b00 & b10) ^ (b00 & c10) ^ (c00 & b10);
    c20 ^= (~c00 & c10) ^ (c00 & a10) ^ (a00 & c10);
    a21 ^= (~a01 & a11) ^ (a01 & b11) ^ (b01 & a11);
    b21 ^= (~b01 & b11) ^ (b01 & c11) ^ (c01 & b11);
    c21 ^= (~c01 & c11) ^ (c01 & a11) ^ (a01 & c11);
    a22 ^= (~a02 & a12) ^ (a02 & b12) ^ (b02 & a12);
    b22 ^= (~b02 & b12) ^ (b02 & c12) ^ (c02 & b12);
    c22 ^= (~c02 & c12) ^ (c02 & a12) ^ (a02 & c12);
    a23 ^= (~a03 & a13) ^ (a03 & b13) ^ (b03 & a13);
    b23 ^= (~b03 & b13) ^ (b03 & c13) ^ (c03 & b13);
    c23 ^= (~c03 & c13) ^ (c03 & a13) ^ (a03 & c13);
    ;
    ;
    a10 = ((((uint32_t)a10) << ((1) % 32)) ^
           (((uint32_t)a10) >> ((32 - (1)) % 32)));
    a11 = ((((uint32_t)a11) << ((1) % 32)) ^
           (((uint32_t)a11) >> ((32 - (1)) % 32)));
    a12 = ((((uint32_t)a12) << ((1) % 32)) ^
           (((uint32_t)a12) >> ((32 - (1)) % 32)));
    a13 = ((((uint32_t)a13) << ((1) % 32)) ^
           (((uint32_t)a13) >> ((32 - (1)) % 32)));
    va1 = ((((uint32_t)a23) << ((8) % 32)) ^
           (((uint32_t)a23) >> ((32 - (8)) % 32)));
    a23 = ((((uint32_t)a21) << ((8) % 32)) ^
           (((uint32_t)a21) >> ((32 - (8)) % 32)));
    a21 = va1;
    va1 = ((((uint32_t)a22) << ((8) % 32)) ^
           (((uint32_t)a22) >> ((32 - (8)) % 32)));
    a22 = ((((uint32_t)a20) << ((8) % 32)) ^
           (((uint32_t)a20) >> ((32 - (8)) % 32)));
    a20 = va1;
    b10 = ((((uint32_t)b10) << ((1) % 32)) ^
           (((uint32_t)b10) >> ((32 - (1)) % 32)));
    b11 = ((((uint32_t)b11) << ((1) % 32)) ^
           (((uint32_t)b11) >> ((32 - (1)) % 32)));
    b12 = ((((uint32_t)b12) << ((1) % 32)) ^
           (((uint32_t)b12) >> ((32 - (1)) % 32)));
    b13 = ((((uint32_t)b13) << ((1) % 32)) ^
           (((uint32_t)b13) >> ((32 - (1)) % 32)));
    vb1 = ((((uint32_t)b23) << ((8) % 32)) ^
           (((uint32_t)b23) >> ((32 - (8)) % 32)));
    b23 = ((((uint32_t)b21) << ((8) % 32)) ^
           (((uint32_t)b21) >> ((32 - (8)) % 32)));
    b21 = vb1;
    vb1 = ((((uint32_t)b22) << ((8) % 32)) ^
           (((uint32_t)b22) >> ((32 - (8)) % 32)));
    b22 = ((((uint32_t)b20) << ((8) % 32)) ^
           (((uint32_t)b20) >> ((32 - (8)) % 32)));
    b20 = vb1;
    c10 = ((((uint32_t)c10) << ((1) % 32)) ^
           (((uint32_t)c10) >> ((32 - (1)) % 32)));
    c11 = ((((uint32_t)c11) << ((1) % 32)) ^
           (((uint32_t)c11) >> ((32 - (1)) % 32)));
    c12 = ((((uint32_t)c12) << ((1) % 32)) ^
           (((uint32_t)c12) >> ((32 - (1)) % 32)));
    c13 = ((((uint32_t)c13) << ((1) % 32)) ^
           (((uint32_t)c13) >> ((32 - (1)) % 32)));
    vc1 = ((((uint32_t)c23) << ((8) % 32)) ^
           (((uint32_t)c23) >> ((32 - (8)) % 32)));
    c23 = ((((uint32_t)c21) << ((8) % 32)) ^
           (((uint32_t)c21) >> ((32 - (8)) % 32)));
    c21 = vc1;
    vc1 = ((((uint32_t)c22) << ((8) % 32)) ^
           (((uint32_t)c22) >> ((32 - (8)) % 32)));
    c22 = ((((uint32_t)c20) << ((8) % 32)) ^
           (((uint32_t)c20) >> ((32 - (8)) % 32)));
    c20 = vc1;
    ;
    va1 = a03 ^ a13 ^ a23;
    va2 = a00 ^ a10 ^ a20;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a00 ^= va1;
    a10 ^= va1;
    a20 ^= va1;
    va1 = a01 ^ a11 ^ a21;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a01 ^= va2;
    a11 ^= va2;
    a21 ^= va2;
    va2 = a02 ^ a12 ^ a22;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a02 ^= va1;
    a12 ^= va1;
    a22 ^= va1;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a03 ^= va2;
    a13 ^= va2;
    a23 ^= va2;
    vb1 = b03 ^ b13 ^ b23;
    vb2 = b00 ^ b10 ^ b20;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b00 ^= vb1;
    b10 ^= vb1;
    b20 ^= vb1;
    vb1 = b01 ^ b11 ^ b21;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b01 ^= vb2;
    b11 ^= vb2;
    b21 ^= vb2;
    vb2 = b02 ^ b12 ^ b22;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b02 ^= vb1;
    b12 ^= vb1;
    b22 ^= vb1;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b03 ^= vb2;
    b13 ^= vb2;
    b23 ^= vb2;
    vc1 = c03 ^ c13 ^ c23;
    vc2 = c00 ^ c10 ^ c20;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c00 ^= vc1;
    c10 ^= vc1;
    c20 ^= vc1;
    vc1 = c01 ^ c11 ^ c21;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c01 ^= vc2;
    c11 ^= vc2;
    c21 ^= vc2;
    vc2 = c02 ^ c12 ^ c22;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c02 ^= vc1;
    c12 ^= vc1;
    c22 ^= vc1;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c03 ^= vc2;
    c13 ^= vc2;
    c23 ^= vc2;
    ;
    a20 = ((((uint32_t)a20) << ((11) % 32)) ^
           (((uint32_t)a20) >> ((32 - (11)) % 32)));
    a21 = ((((uint32_t)a21) << ((11) % 32)) ^
           (((uint32_t)a21) >> ((32 - (11)) % 32)));
    a22 = ((((uint32_t)a22) << ((11) % 32)) ^
           (((uint32_t)a22) >> ((32 - (11)) % 32)));
    a23 = ((((uint32_t)a23) << ((11) % 32)) ^
           (((uint32_t)a23) >> ((32 - (11)) % 32)));
    va1 = a13;
    a13 = a12;
    a12 = a11;
    a11 = a10;
    a10 = va1;
    b20 = ((((uint32_t)b20) << ((11) % 32)) ^
           (((uint32_t)b20) >> ((32 - (11)) % 32)));
    b21 = ((((uint32_t)b21) << ((11) % 32)) ^
           (((uint32_t)b21) >> ((32 - (11)) % 32)));
    b22 = ((((uint32_t)b22) << ((11) % 32)) ^
           (((uint32_t)b22) >> ((32 - (11)) % 32)));
    b23 = ((((uint32_t)b23) << ((11) % 32)) ^
           (((uint32_t)b23) >> ((32 - (11)) % 32)));
    vb1 = b13;
    b13 = b12;
    b12 = b11;
    b11 = b10;
    b10 = vb1;
    c20 = ((((uint32_t)c20) << ((11) % 32)) ^
           (((uint32_t)c20) >> ((32 - (11)) % 32)));
    c21 = ((((uint32_t)c21) << ((11) % 32)) ^
           (((uint32_t)c21) >> ((32 - (11)) % 32)));
    c22 = ((((uint32_t)c22) << ((11) % 32)) ^
           (((uint32_t)c22) >> ((32 - (11)) % 32)));
    c23 = ((((uint32_t)c23) << ((11) % 32)) ^
           (((uint32_t)c23) >> ((32 - (11)) % 32)));
    vc1 = c13;
    c13 = c12;
    c12 = c11;
    c11 = c10;
    c10 = vc1;
    ;
    a00 ^= 0x000001A0;
    ;
    a00 ^= (~a10 & a20) ^ (a10 & b20) ^ (b10 & a20);
    b00 ^= (~b10 & b20) ^ (b10 & c20) ^ (c10 & b20);
    c00 ^= (~c10 & c20) ^ (c10 & a20) ^ (a10 & c20);
    a01 ^= (~a11 & a21) ^ (a11 & b21) ^ (b11 & a21);
    b01 ^= (~b11 & b21) ^ (b11 & c21) ^ (c11 & b21);
    c01 ^= (~c11 & c21) ^ (c11 & a21) ^ (a11 & c21);
    a02 ^= (~a12 & a22) ^ (a12 & b22) ^ (b12 & a22);
    b02 ^= (~b12 & b22) ^ (b12 & c22) ^ (c12 & b22);
    c02 ^= (~c12 & c22) ^ (c12 & a22) ^ (a12 & c22);
    a03 ^= (~a13 & a23) ^ (a13 & b23) ^ (b13 & a23);
    b03 ^= (~b13 & b23) ^ (b13 & c23) ^ (c13 & b23);
    c03 ^= (~c13 & c23) ^ (c13 & a23) ^ (a13 & c23);
    a10 ^= (~a20 & a00) ^ (a20 & b00) ^ (b20 & a00);
    b10 ^= (~b20 & b00) ^ (b20 & c00) ^ (c20 & b00);
    c10 ^= (~c20 & c00) ^ (c20 & a00) ^ (a20 & c00);
    a11 ^= (~a21 & a01) ^ (a21 & b01) ^ (b21 & a01);
    b11 ^= (~b21 & b01) ^ (b21 & c01) ^ (c21 & b01);
    c11 ^= (~c21 & c01) ^ (c21 & a01) ^ (a21 & c01);
    a12 ^= (~a22 & a02) ^ (a22 & b02) ^ (b22 & a02);
    b12 ^= (~b22 & b02) ^ (b22 & c02) ^ (c22 & b02);
    c12 ^= (~c22 & c02) ^ (c22 & a02) ^ (a22 & c02);
    a13 ^= (~a23 & a03) ^ (a23 & b03) ^ (b23 & a03);
    b13 ^= (~b23 & b03) ^ (b23 & c03) ^ (c23 & b03);
    c13 ^= (~c23 & c03) ^ (c23 & a03) ^ (a23 & c03);
    a20 ^= (~a00 & a10) ^ (a00 & b10) ^ (b00 & a10);
    b20 ^= (~b00 & b10) ^ (b00 & c10) ^ (c00 & b10);
    c20 ^= (~c00 & c10) ^ (c00 & a10) ^ (a00 & c10);
    a21 ^= (~a01 & a11) ^ (a01 & b11) ^ (b01 & a11);
    b21 ^= (~b01 & b11) ^ (b01 & c11) ^ (c01 & b11);
    c21 ^= (~c01 & c11) ^ (c01 & a11) ^ (a01 & c11);
    a22 ^= (~a02 & a12) ^ (a02 & b12) ^ (b02 & a12);
    b22 ^= (~b02 & b12) ^ (b02 & c12) ^ (c02 & b12);
    c22 ^= (~c02 & c12) ^ (c02 & a12) ^ (a02 & c12);
    a23 ^= (~a03 & a13) ^ (a03 & b13) ^ (b03 & a13);
    b23 ^= (~b03 & b13) ^ (b03 & c13) ^ (c03 & b13);
    c23 ^= (~c03 & c13) ^ (c03 & a13) ^ (a03 & c13);
    ;
    ;
    a10 = ((((uint32_t)a10) << ((1) % 32)) ^
           (((uint32_t)a10) >> ((32 - (1)) % 32)));
    a11 = ((((uint32_t)a11) << ((1) % 32)) ^
           (((uint32_t)a11) >> ((32 - (1)) % 32)));
    a12 = ((((uint32_t)a12) << ((1) % 32)) ^
           (((uint32_t)a12) >> ((32 - (1)) % 32)));
    a13 = ((((uint32_t)a13) << ((1) % 32)) ^
           (((uint32_t)a13) >> ((32 - (1)) % 32)));
    va1 = ((((uint32_t)a23) << ((8) % 32)) ^
           (((uint32_t)a23) >> ((32 - (8)) % 32)));
    a23 = ((((uint32_t)a21) << ((8) % 32)) ^
           (((uint32_t)a21) >> ((32 - (8)) % 32)));
    a21 = va1;
    va1 = ((((uint32_t)a22) << ((8) % 32)) ^
           (((uint32_t)a22) >> ((32 - (8)) % 32)));
    a22 = ((((uint32_t)a20) << ((8) % 32)) ^
           (((uint32_t)a20) >> ((32 - (8)) % 32)));
    a20 = va1;
    b10 = ((((uint32_t)b10) << ((1) % 32)) ^
           (((uint32_t)b10) >> ((32 - (1)) % 32)));
    b11 = ((((uint32_t)b11) << ((1) % 32)) ^
           (((uint32_t)b11) >> ((32 - (1)) % 32)));
    b12 = ((((uint32_t)b12) << ((1) % 32)) ^
           (((uint32_t)b12) >> ((32 - (1)) % 32)));
    b13 = ((((uint32_t)b13) << ((1) % 32)) ^
           (((uint32_t)b13) >> ((32 - (1)) % 32)));
    vb1 = ((((uint32_t)b23) << ((8) % 32)) ^
           (((uint32_t)b23) >> ((32 - (8)) % 32)));
    b23 = ((((uint32_t)b21) << ((8) % 32)) ^
           (((uint32_t)b21) >> ((32 - (8)) % 32)));
    b21 = vb1;
    vb1 = ((((uint32_t)b22) << ((8) % 32)) ^
           (((uint32_t)b22) >> ((32 - (8)) % 32)));
    b22 = ((((uint32_t)b20) << ((8) % 32)) ^
           (((uint32_t)b20) >> ((32 - (8)) % 32)));
    b20 = vb1;
    c10 = ((((uint32_t)c10) << ((1) % 32)) ^
           (((uint32_t)c10) >> ((32 - (1)) % 32)));
    c11 = ((((uint32_t)c11) << ((1) % 32)) ^
           (((uint32_t)c11) >> ((32 - (1)) % 32)));
    c12 = ((((uint32_t)c12) << ((1) % 32)) ^
           (((uint32_t)c12) >> ((32 - (1)) % 32)));
    c13 = ((((uint32_t)c13) << ((1) % 32)) ^
           (((uint32_t)c13) >> ((32 - (1)) % 32)));
    vc1 = ((((uint32_t)c23) << ((8) % 32)) ^
           (((uint32_t)c23) >> ((32 - (8)) % 32)));
    c23 = ((((uint32_t)c21) << ((8) % 32)) ^
           (((uint32_t)c21) >> ((32 - (8)) % 32)));
    c21 = vc1;
    vc1 = ((((uint32_t)c22) << ((8) % 32)) ^
           (((uint32_t)c22) >> ((32 - (8)) % 32)));
    c22 = ((((uint32_t)c20) << ((8) % 32)) ^
           (((uint32_t)c20) >> ((32 - (8)) % 32)));
    c20 = vc1;
    ;
    va1 = a03 ^ a13 ^ a23;
    va2 = a00 ^ a10 ^ a20;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a00 ^= va1;
    a10 ^= va1;
    a20 ^= va1;
    va1 = a01 ^ a11 ^ a21;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a01 ^= va2;
    a11 ^= va2;
    a21 ^= va2;
    va2 = a02 ^ a12 ^ a22;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a02 ^= va1;
    a12 ^= va1;
    a22 ^= va1;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a03 ^= va2;
    a13 ^= va2;
    a23 ^= va2;
    vb1 = b03 ^ b13 ^ b23;
    vb2 = b00 ^ b10 ^ b20;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b00 ^= vb1;
    b10 ^= vb1;
    b20 ^= vb1;
    vb1 = b01 ^ b11 ^ b21;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b01 ^= vb2;
    b11 ^= vb2;
    b21 ^= vb2;
    vb2 = b02 ^ b12 ^ b22;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b02 ^= vb1;
    b12 ^= vb1;
    b22 ^= vb1;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b03 ^= vb2;
    b13 ^= vb2;
    b23 ^= vb2;
    vc1 = c03 ^ c13 ^ c23;
    vc2 = c00 ^ c10 ^ c20;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c00 ^= vc1;
    c10 ^= vc1;
    c20 ^= vc1;
    vc1 = c01 ^ c11 ^ c21;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c01 ^= vc2;
    c11 ^= vc2;
    c21 ^= vc2;
    vc2 = c02 ^ c12 ^ c22;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c02 ^= vc1;
    c12 ^= vc1;
    c22 ^= vc1;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c03 ^= vc2;
    c13 ^= vc2;
    c23 ^= vc2;
    ;
    a20 = ((((uint32_t)a20) << ((11) % 32)) ^
           (((uint32_t)a20) >> ((32 - (11)) % 32)));
    a21 = ((((uint32_t)a21) << ((11) % 32)) ^
           (((uint32_t)a21) >> ((32 - (11)) % 32)));
    a22 = ((((uint32_t)a22) << ((11) % 32)) ^
           (((uint32_t)a22) >> ((32 - (11)) % 32)));
    a23 = ((((uint32_t)a23) << ((11) % 32)) ^
           (((uint32_t)a23) >> ((32 - (11)) % 32)));
    va1 = a13;
    a13 = a12;
    a12 = a11;
    a11 = a10;
    a10 = va1;
    b20 = ((((uint32_t)b20) << ((11) % 32)) ^
           (((uint32_t)b20) >> ((32 - (11)) % 32)));
    b21 = ((((uint32_t)b21) << ((11) % 32)) ^
           (((uint32_t)b21) >> ((32 - (11)) % 32)));
    b22 = ((((uint32_t)b22) << ((11) % 32)) ^
           (((uint32_t)b22) >> ((32 - (11)) % 32)));
    b23 = ((((uint32_t)b23) << ((11) % 32)) ^
           (((uint32_t)b23) >> ((32 - (11)) % 32)));
    vb1 = b13;
    b13 = b12;
    b12 = b11;
    b11 = b10;
    b10 = vb1;
    c20 = ((((uint32_t)c20) << ((11) % 32)) ^
           (((uint32_t)c20) >> ((32 - (11)) % 32)));
    c21 = ((((uint32_t)c21) << ((11) % 32)) ^
           (((uint32_t)c21) >> ((32 - (11)) % 32)));
    c22 = ((((uint32_t)c22) << ((11) % 32)) ^
           (((uint32_t)c22) >> ((32 - (11)) % 32)));
    c23 = ((((uint32_t)c23) << ((11) % 32)) ^
           (((uint32_t)c23) >> ((32 - (11)) % 32)));
    vc1 = c13;
    c13 = c12;
    c12 = c11;
    c11 = c10;
    c10 = vc1;
    ;
    a00 ^= 0x00000012;
    ;
    a00 ^= (~a10 & a20) ^ (a10 & b20) ^ (b10 & a20);
    b00 ^= (~b10 & b20) ^ (b10 & c20) ^ (c10 & b20);
    c00 ^= (~c10 & c20) ^ (c10 & a20) ^ (a10 & c20);
    a01 ^= (~a11 & a21) ^ (a11 & b21) ^ (b11 & a21);
    b01 ^= (~b11 & b21) ^ (b11 & c21) ^ (c11 & b21);
    c01 ^= (~c11 & c21) ^ (c11 & a21) ^ (a11 & c21);
    a02 ^= (~a12 & a22) ^ (a12 & b22) ^ (b12 & a22);
    b02 ^= (~b12 & b22) ^ (b12 & c22) ^ (c12 & b22);
    c02 ^= (~c12 & c22) ^ (c12 & a22) ^ (a12 & c22);
    a03 ^= (~a13 & a23) ^ (a13 & b23) ^ (b13 & a23);
    b03 ^= (~b13 & b23) ^ (b13 & c23) ^ (c13 & b23);
    c03 ^= (~c13 & c23) ^ (c13 & a23) ^ (a13 & c23);
    a10 ^= (~a20 & a00) ^ (a20 & b00) ^ (b20 & a00);
    b10 ^= (~b20 & b00) ^ (b20 & c00) ^ (c20 & b00);
    c10 ^= (~c20 & c00) ^ (c20 & a00) ^ (a20 & c00);
    a11 ^= (~a21 & a01) ^ (a21 & b01) ^ (b21 & a01);
    b11 ^= (~b21 & b01) ^ (b21 & c01) ^ (c21 & b01);
    c11 ^= (~c21 & c01) ^ (c21 & a01) ^ (a21 & c01);
    a12 ^= (~a22 & a02) ^ (a22 & b02) ^ (b22 & a02);
    b12 ^= (~b22 & b02) ^ (b22 & c02) ^ (c22 & b02);
    c12 ^= (~c22 & c02) ^ (c22 & a02) ^ (a22 & c02);
    a13 ^= (~a23 & a03) ^ (a23 & b03) ^ (b23 & a03);
    b13 ^= (~b23 & b03) ^ (b23 & c03) ^ (c23 & b03);
    c13 ^= (~c23 & c03) ^ (c23 & a03) ^ (a23 & c03);
    a20 ^= (~a00 & a10) ^ (a00 & b10) ^ (b00 & a10);
    b20 ^= (~b00 & b10) ^ (b00 & c10) ^ (c00 & b10);
    c20 ^= (~c00 & c10) ^ (c00 & a10) ^ (a00 & c10);
    a21 ^= (~a01 & a11) ^ (a01 & b11) ^ (b01 & a11);
    b21 ^= (~b01 & b11) ^ (b01 & c11) ^ (c01 & b11);
    c21 ^= (~c01 & c11) ^ (c01 & a11) ^ (a01 & c11);
    a22 ^= (~a02 & a12) ^ (a02 & b12) ^ (b02 & a12);
    b22 ^= (~b02 & b12) ^ (b02 & c12) ^ (c02 & b12);
    c22 ^= (~c02 & c12) ^ (c02 & a12) ^ (a02 & c12);
    a23 ^= (~a03 & a13) ^ (a03 & b13) ^ (b03 & a13);
    b23 ^= (~b03 & b13) ^ (b03 & c13) ^ (c03 & b13);
    c23 ^= (~c03 & c13) ^ (c03 & a13) ^ (a03 & c13);
    ;
    ;
    a10 = ((((uint32_t)a10) << ((1) % 32)) ^
           (((uint32_t)a10) >> ((32 - (1)) % 32)));
    a11 = ((((uint32_t)a11) << ((1) % 32)) ^
           (((uint32_t)a11) >> ((32 - (1)) % 32)));
    a12 = ((((uint32_t)a12) << ((1) % 32)) ^
           (((uint32_t)a12) >> ((32 - (1)) % 32)));
    a13 = ((((uint32_t)a13) << ((1) % 32)) ^
           (((uint32_t)a13) >> ((32 - (1)) % 32)));
    va1 = ((((uint32_t)a23) << ((8) % 32)) ^
           (((uint32_t)a23) >> ((32 - (8)) % 32)));
    a23 = ((((uint32_t)a21) << ((8) % 32)) ^
           (((uint32_t)a21) >> ((32 - (8)) % 32)));
    a21 = va1;
    va1 = ((((uint32_t)a22) << ((8) % 32)) ^
           (((uint32_t)a22) >> ((32 - (8)) % 32)));
    a22 = ((((uint32_t)a20) << ((8) % 32)) ^
           (((uint32_t)a20) >> ((32 - (8)) % 32)));
    a20 = va1;
    b10 = ((((uint32_t)b10) << ((1) % 32)) ^
           (((uint32_t)b10) >> ((32 - (1)) % 32)));
    b11 = ((((uint32_t)b11) << ((1) % 32)) ^
           (((uint32_t)b11) >> ((32 - (1)) % 32)));
    b12 = ((((uint32_t)b12) << ((1) % 32)) ^
           (((uint32_t)b12) >> ((32 - (1)) % 32)));
    b13 = ((((uint32_t)b13) << ((1) % 32)) ^
           (((uint32_t)b13) >> ((32 - (1)) % 32)));
    vb1 = ((((uint32_t)b23) << ((8) % 32)) ^
           (((uint32_t)b23) >> ((32 - (8)) % 32)));
    b23 = ((((uint32_t)b21) << ((8) % 32)) ^
           (((uint32_t)b21) >> ((32 - (8)) % 32)));
    b21 = vb1;
    vb1 = ((((uint32_t)b22) << ((8) % 32)) ^
           (((uint32_t)b22) >> ((32 - (8)) % 32)));
    b22 = ((((uint32_t)b20) << ((8) % 32)) ^
           (((uint32_t)b20) >> ((32 - (8)) % 32)));
    b20 = vb1;
    c10 = ((((uint32_t)c10) << ((1) % 32)) ^
           (((uint32_t)c10) >> ((32 - (1)) % 32)));
    c11 = ((((uint32_t)c11) << ((1) % 32)) ^
           (((uint32_t)c11) >> ((32 - (1)) % 32)));
    c12 = ((((uint32_t)c12) << ((1) % 32)) ^
           (((uint32_t)c12) >> ((32 - (1)) % 32)));
    c13 = ((((uint32_t)c13) << ((1) % 32)) ^
           (((uint32_t)c13) >> ((32 - (1)) % 32)));
    vc1 = ((((uint32_t)c23) << ((8) % 32)) ^
           (((uint32_t)c23) >> ((32 - (8)) % 32)));
    c23 = ((((uint32_t)c21) << ((8) % 32)) ^
           (((uint32_t)c21) >> ((32 - (8)) % 32)));
    c21 = vc1;
    vc1 = ((((uint32_t)c22) << ((8) % 32)) ^
           (((uint32_t)c22) >> ((32 - (8)) % 32)));
    c22 = ((((uint32_t)c20) << ((8) % 32)) ^
           (((uint32_t)c20) >> ((32 - (8)) % 32)));
    c20 = vc1;
    ;
    ;
    state[0 + 0] = a00, state[0 + 1] = a01, state[0 + 2] = a02,
              state[0 + 3] = a03;
    state[4 + 0] = a10, state[4 + 1] = a11, state[4 + 2] = a12,
              state[4 + 3] = a13;
    state[8 + 0] = a20, state[8 + 1] = a21, state[8 + 2] = a22,
              state[8 + 3] = a23;
    ;
}
uint32_t ax[12],bx[12],cx[12];

#define VOLT 
void
Xoodoo_Permute_12rounds(uint32_t* state, uint32_t* masks)
{
    VOLT uint32_t a00, a01, a02, a03;
    VOLT uint32_t a10, a11, a12, a13;
    VOLT uint32_t a20, a21, a22, a23;
    VOLT uint32_t va1, va2;
    VOLT uint32_t b00, b01, b02, b03;
    VOLT uint32_t b10, b11, b12, b13;
    VOLT uint32_t b20, b21, b22, b23;
    VOLT uint32_t vb1, vb2;
    VOLT uint32_t c00, c01, c02, c03;
    VOLT uint32_t c10, c11, c12, c13;
    VOLT uint32_t c20, c21, c22, c23;
    VOLT uint32_t vc1, vc2;
    ;
    a00 = state[0 + 0], a01 = state[0 + 1], a02 = state[0 + 2],
    a03 = state[0 + 3];
    a10 = state[4 + 0], a11 = state[4 + 1], a12 = state[4 + 2],
    a13 = state[4 + 3];
    a20 = state[8 + 0], a21 = state[8 + 1], a22 = state[8 + 2],
    a23 = state[8 + 3];
    b00 = masks[0 + 0], b01 = masks[0 + 1], b02 = masks[0 + 2],
    b03 = masks[0 + 3];
    b10 = masks[4 + 0], b11 = masks[4 + 1], b12 = masks[4 + 2],
    b13 = masks[4 + 3];
    b20 = masks[8 + 0], b21 = masks[8 + 1], b22 = masks[8 + 2],
    b23 = masks[8 + 3];
    c00 = masks[12 + 0], c01 = masks[12 + 1], c02 = masks[12 + 2],
    c03 = masks[12 + 3];
    c10 = masks[16 + 0], c11 = masks[16 + 1], c12 = masks[16 + 2],
    c13 = masks[16 + 3];
    c20 = masks[20 + 0], c21 = masks[20 + 1], c22 = masks[20 + 2],
    c23 = masks[20 + 3];
    ;

    a00 ^= b00 ^ c00;
    a01 ^= b01 ^ c01;
    a02 ^= b02 ^ c02;
    a03 ^= b03 ^ c03;
    a10 ^= b10 ^ c10;
    a11 ^= b11 ^ c11;
    a12 ^= b12 ^ c12;
    a13 ^= b13 ^ c13;
    a20 ^= b20 ^ c20;
    a21 ^= b21 ^ c21;
    a22 ^= b22 ^ c22;
    a23 ^= b23 ^ c23;

    va1 = a03 ^ a13 ^ a23;
    va2 = a00 ^ a10 ^ a20;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a00 ^= va1;
    a10 ^= va1;
    a20 ^= va1;
    va1 = a01 ^ a11 ^ a21;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a01 ^= va2;
    a11 ^= va2;
    a21 ^= va2;
    va2 = a02 ^ a12 ^ a22;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a02 ^= va1;
    a12 ^= va1;
    a22 ^= va1;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a03 ^= va2;
    a13 ^= va2;
    a23 ^= va2;
    vb1 = b03 ^ b13 ^ b23;
    vb2 = b00 ^ b10 ^ b20;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b00 ^= vb1;
    b10 ^= vb1;
    b20 ^= vb1;
    vb1 = b01 ^ b11 ^ b21;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b01 ^= vb2;
    b11 ^= vb2;
    b21 ^= vb2;
    vb2 = b02 ^ b12 ^ b22;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b02 ^= vb1;
    b12 ^= vb1;
    b22 ^= vb1;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b03 ^= vb2;
    b13 ^= vb2;
    b23 ^= vb2;
    vc1 = c03 ^ c13 ^ c23;
    vc2 = c00 ^ c10 ^ c20;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c00 ^= vc1;
    c10 ^= vc1;
    c20 ^= vc1;
    vc1 = c01 ^ c11 ^ c21;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c01 ^= vc2;
    c11 ^= vc2;
    c21 ^= vc2;
    vc2 = c02 ^ c12 ^ c22;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c02 ^= vc1;
    c12 ^= vc1;
    c22 ^= vc1;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c03 ^= vc2;
    c13 ^= vc2;
    c23 ^= vc2;
    ;
    a20 = ((((uint32_t)a20) << ((11) % 32)) ^
           (((uint32_t)a20) >> ((32 - (11)) % 32)));
    a21 = ((((uint32_t)a21) << ((11) % 32)) ^
           (((uint32_t)a21) >> ((32 - (11)) % 32)));
    a22 = ((((uint32_t)a22) << ((11) % 32)) ^
           (((uint32_t)a22) >> ((32 - (11)) % 32)));
    a23 = ((((uint32_t)a23) << ((11) % 32)) ^
           (((uint32_t)a23) >> ((32 - (11)) % 32)));
    va1 = a13;
    a13 = a12;
    a12 = a11;
    a11 = a10;
    a10 = va1;
    b20 = ((((uint32_t)b20) << ((11) % 32)) ^
           (((uint32_t)b20) >> ((32 - (11)) % 32)));
    b21 = ((((uint32_t)b21) << ((11) % 32)) ^
           (((uint32_t)b21) >> ((32 - (11)) % 32)));
    b22 = ((((uint32_t)b22) << ((11) % 32)) ^
           (((uint32_t)b22) >> ((32 - (11)) % 32)));
    b23 = ((((uint32_t)b23) << ((11) % 32)) ^
           (((uint32_t)b23) >> ((32 - (11)) % 32)));
    vb1 = b13;
    b13 = b12;
    b12 = b11;
    b11 = b10;
    b10 = vb1;
    c20 = ((((uint32_t)c20) << ((11) % 32)) ^
           (((uint32_t)c20) >> ((32 - (11)) % 32)));
    c21 = ((((uint32_t)c21) << ((11) % 32)) ^
           (((uint32_t)c21) >> ((32 - (11)) % 32)));
    c22 = ((((uint32_t)c22) << ((11) % 32)) ^
           (((uint32_t)c22) >> ((32 - (11)) % 32)));
    c23 = ((((uint32_t)c23) << ((11) % 32)) ^
           (((uint32_t)c23) >> ((32 - (11)) % 32)));
    vc1 = c13;
    c13 = c12;
    c12 = c11;
    c11 = c10;
    c10 = vc1;
    ;
    a00 ^= 0x00000058;
    ;

#define FF(_v,_x) \
    asm volatile ("" : :"r" (_v##_x##0), "r" (_v##_x##1), "r" (_v##_x##2), "r" (_v##_x##3));
    

FF(a, 0);
FF(a, 1);
FF(a, 2);
FF(b, 0);
FF(b, 1);
FF(b, 2);               
FF(c, 0);
FF(c, 1);
FF(c, 2);


    (ax)[0] = a00;
    (ax)[1] = a01;
    (ax)[2] = a02;
    (ax)[3] = a03;
    (ax)[4] = a10;
    (ax)[5] = a11;
    (ax)[6] = a12;
    (ax)[7] = a13;
    (ax)[8] = a20;
    (ax)[9] = a21;
    (ax)[10] = a22;
    (ax)[11] = a23;

    (bx)[0] = b00;
    (bx)[1] = b01;
    (bx)[2] = b02;
    (bx)[3] = b03;
    (bx)[4] = b10;
    (bx)[5] = b11;
    (bx)[6] = b12;
    (bx)[7] = b13;
    (bx)[8] = b20;
    (bx)[9] = b21;
    (bx)[10] = b22;
    (bx)[11] = b23;

    (cx)[0] = c00;
    (cx)[1] = c01;
    (cx)[2] = c02;
    (cx)[3] = c03;
    (cx)[4] = c10;
    (cx)[5] = c11;
    (cx)[6] = c12;
    (cx)[7] = c13;
    (cx)[8] = c20;
    (cx)[9] = c21;
    (cx)[10] = c22;
    (cx)[11] = c23;
    
    maskedchi(ax, bx, cx);

    a00 = (ax)[0];
    a01 = (ax)[1];
    a02 = (ax)[2];
    a03 = (ax)[3];
    a10 = (ax)[4];
    a11 = (ax)[5];
    a12 = (ax)[6];
    a13 = (ax)[7];
    a20 = (ax)[8];
    a21 = (ax)[9];
    a22 = (ax)[10];
    a23 = (ax)[11];

    b00 = (bx)[0];
    b01 = (bx)[1];
    b02 = (bx)[2];
    b03 = (bx)[3];
    b10 = (bx)[4];
    b11 = (bx)[5];
    b12 = (bx)[6];
    b13 = (bx)[7];
    b20 = (bx)[8];
    b21 = (bx)[9];
    b22 = (bx)[10];
    b23 = (bx)[11];

    c00 = (cx)[0];
    c01 = (cx)[1];
    c02 = (cx)[2];
    c03 = (cx)[3];
    c10 = (cx)[4];
    c11 = (cx)[5];
    c12 = (cx)[6];
    c13 = (cx)[7];
    c20 = (cx)[8];
    c21 = (cx)[9];
    c22 = (cx)[10];
    c23 = (cx)[11];

/*

    a00 ^= (~a10 & a20) ^ (a10 & b20) ^ (b10 & a20);
    //asm volatile ("" : :"r" (a00));
    b00 ^= (~b10 & b20) ^ (b10 & c20) ^ (c10 & b20);
    //asm volatile ("" : :"r" (b00));
    c00 ^= (~c10 & c20) ^ (c10 & a20) ^ (a10 & c20);
    //asm volatile ("" : :"r" (c00));
    a01 ^= (~a11 & a21) ^ (a11 & b21) ^ (b11 & a21);
    //asm volatile ("" : :"r" (a01));
    b01 ^= (~b11 & b21) ^ (b11 & c21) ^ (c11 & b21);
    //asm volatile ("" : :"r" (b01));
    c01 ^= (~c11 & c21) ^ (c11 & a21) ^ (a11 & c21);
    //asm volatile ("" : :"r" (c01));
    a02 ^= (~a12 & a22) ^ (a12 & b22) ^ (b12 & a22);
    //asm volatile ("" : :"r" (a02));
    b02 ^= (~b12 & b22) ^ (b12 & c22) ^ (c12 & b22);
    //asm volatile ("" : :"r" (b02));
    c02 ^= (~c12 & c22) ^ (c12 & a22) ^ (a12 & c22);
    //asm volatile ("" : :"r" (c02));
    a03 ^= (~a13 & a23) ^ (a13 & b23) ^ (b13 & a23);
    //asm volatile ("" : :"r" (a03));
    b03 ^= (~b13 & b23) ^ (b13 & c23) ^ (c13 & b23);
    //asm volatile ("" : :"r" (b03));
    c03 ^= (~c13 & c23) ^ (c13 & a23) ^ (a13 & c23);
    //asm volatile ("" : :"r" (c03));
    a10 ^= (~a20 & a00) ^ (a20 & b00) ^ (b20 & a00);
    //asm volatile ("" : :"r" (a10));
    b10 ^= (~b20 & b00) ^ (b20 & c00) ^ (c20 & b00);
    //asm volatile ("" : :"r" (b10));
    c10 ^= (~c20 & c00) ^ (c20 & a00) ^ (a20 & c00);
    //asm volatile ("" : :"r" (c10));
    a11 ^= (~a21 & a01) ^ (a21 & b01) ^ (b21 & a01);
    //asm volatile ("" : :"r" (a11));
    b11 ^= (~b21 & b01) ^ (b21 & c01) ^ (c21 & b01);
    //asm volatile ("" : :"r" (b11));
    c11 ^= (~c21 & c01) ^ (c21 & a01) ^ (a21 & c01);
    //asm volatile ("" : :"r" (c11));
    a12 ^= (~a22 & a02) ^ (a22 & b02) ^ (b22 & a02);
    //asm volatile ("" : :"r" (a12));
    b12 ^= (~b22 & b02) ^ (b22 & c02) ^ (c22 & b02);
    //asm volatile ("" : :"r" (b12));
    c12 ^= (~c22 & c02) ^ (c22 & a02) ^ (a22 & c02);
    //asm volatile ("" : :"r" (c12));
    a13 ^= (~a23 & a03) ^ (a23 & b03) ^ (b23 & a03);
    //asm volatile ("" : :"r" (a13));
    b13 ^= (~b23 & b03) ^ (b23 & c03) ^ (c23 & b03);
    //asm volatile ("" : :"r" (b13));
    c13 ^= (~c23 & c03) ^ (c23 & a03) ^ (a23 & c03);
    //asm volatile ("" : :"r" (c13));
    a20 ^= (~a00 & a10) ^ (a00 & b10) ^ (b00 & a10);
    //asm volatile ("" : :"r" (a20));
    b20 ^= (~b00 & b10) ^ (b00 & c10) ^ (c00 & b10);
    //asm volatile ("" : :"r" (b20));
    c20 ^= (~c00 & c10) ^ (c00 & a10) ^ (a00 & c10);
    //asm volatile ("" : :"r" (c20));
    a21 ^= (~a01 & a11) ^ (a01 & b11) ^ (b01 & a11);
    //asm volatile ("" : :"r" (a21));
    b21 ^= (~b01 & b11) ^ (b01 & c11) ^ (c01 & b11);
    //asm volatile ("" : :"r" (b21));
    c21 ^= (~c01 & c11) ^ (c01 & a11) ^ (a01 & c11);
    //asm volatile ("" : :"r" (c21));
    a22 ^= (~a02 & a12) ^ (a02 & b12) ^ (b02 & a12);
    //asm volatile ("" : :"r" (a22));
    b22 ^= (~b02 & b12) ^ (b02 & c12) ^ (c02 & b12);
    //asm volatile ("" : :"r" (b22));
    c22 ^= (~c02 & c12) ^ (c02 & a12) ^ (a02 & c12);
    //asm volatile ("" : :"r" (c22));
    a23 ^= (~a03 & a13) ^ (a03 & b13) ^ (b03 & a13);
    //asm volatile ("" : :"r" (a23));
    b23 ^= (~b03 & b13) ^ (b03 & c13) ^ (c03 & b13);
    //asm volatile ("" : :"r" (b23));
    c23 ^= (~c03 & c13) ^ (c03 & a13) ^ (a03 & c13);
    //asm volatile ("" : :"r" (c23));
    ;
    ;
*/
    
    a10 = ((((uint32_t)a10) << ((1) % 32)) ^
           (((uint32_t)a10) >> ((32 - (1)) % 32)));
    a11 = ((((uint32_t)a11) << ((1) % 32)) ^
           (((uint32_t)a11) >> ((32 - (1)) % 32)));
    a12 = ((((uint32_t)a12) << ((1) % 32)) ^
           (((uint32_t)a12) >> ((32 - (1)) % 32)));
    a13 = ((((uint32_t)a13) << ((1) % 32)) ^
           (((uint32_t)a13) >> ((32 - (1)) % 32)));
    va1 = ((((uint32_t)a23) << ((8) % 32)) ^
           (((uint32_t)a23) >> ((32 - (8)) % 32)));
    a23 = ((((uint32_t)a21) << ((8) % 32)) ^
           (((uint32_t)a21) >> ((32 - (8)) % 32)));
    a21 = va1;
    va1 = ((((uint32_t)a22) << ((8) % 32)) ^
           (((uint32_t)a22) >> ((32 - (8)) % 32)));
    a22 = ((((uint32_t)a20) << ((8) % 32)) ^
           (((uint32_t)a20) >> ((32 - (8)) % 32)));
    a20 = va1;
    b10 = ((((uint32_t)b10) << ((1) % 32)) ^
           (((uint32_t)b10) >> ((32 - (1)) % 32)));
    b11 = ((((uint32_t)b11) << ((1) % 32)) ^
           (((uint32_t)b11) >> ((32 - (1)) % 32)));
    b12 = ((((uint32_t)b12) << ((1) % 32)) ^
           (((uint32_t)b12) >> ((32 - (1)) % 32)));
    b13 = ((((uint32_t)b13) << ((1) % 32)) ^
           (((uint32_t)b13) >> ((32 - (1)) % 32)));
    vb1 = ((((uint32_t)b23) << ((8) % 32)) ^
           (((uint32_t)b23) >> ((32 - (8)) % 32)));
    b23 = ((((uint32_t)b21) << ((8) % 32)) ^
           (((uint32_t)b21) >> ((32 - (8)) % 32)));
    b21 = vb1;
    vb1 = ((((uint32_t)b22) << ((8) % 32)) ^
           (((uint32_t)b22) >> ((32 - (8)) % 32)));
    b22 = ((((uint32_t)b20) << ((8) % 32)) ^
           (((uint32_t)b20) >> ((32 - (8)) % 32)));
    b20 = vb1;
    c10 = ((((uint32_t)c10) << ((1) % 32)) ^
           (((uint32_t)c10) >> ((32 - (1)) % 32)));
    c11 = ((((uint32_t)c11) << ((1) % 32)) ^
           (((uint32_t)c11) >> ((32 - (1)) % 32)));
    c12 = ((((uint32_t)c12) << ((1) % 32)) ^
           (((uint32_t)c12) >> ((32 - (1)) % 32)));
    c13 = ((((uint32_t)c13) << ((1) % 32)) ^
           (((uint32_t)c13) >> ((32 - (1)) % 32)));
    vc1 = ((((uint32_t)c23) << ((8) % 32)) ^
           (((uint32_t)c23) >> ((32 - (8)) % 32)));
    c23 = ((((uint32_t)c21) << ((8) % 32)) ^
           (((uint32_t)c21) >> ((32 - (8)) % 32)));
    c21 = vc1;
    vc1 = ((((uint32_t)c22) << ((8) % 32)) ^
           (((uint32_t)c22) >> ((32 - (8)) % 32)));
    c22 = ((((uint32_t)c20) << ((8) % 32)) ^
           (((uint32_t)c20) >> ((32 - (8)) % 32)));
    c20 = vc1;
    ;

    va1 = a03 ^ a13 ^ a23;
    va2 = a00 ^ a10 ^ a20;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a00 ^= va1;
    a10 ^= va1;
    a20 ^= va1;
    va1 = a01 ^ a11 ^ a21;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a01 ^= va2;
    a11 ^= va2;
    a21 ^= va2;
    va2 = a02 ^ a12 ^ a22;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a02 ^= va1;
    a12 ^= va1;
    a22 ^= va1;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a03 ^= va2;
    a13 ^= va2;
    a23 ^= va2;
    vb1 = b03 ^ b13 ^ b23;
    vb2 = b00 ^ b10 ^ b20;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b00 ^= vb1;
    b10 ^= vb1;
    b20 ^= vb1;
    vb1 = b01 ^ b11 ^ b21;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b01 ^= vb2;
    b11 ^= vb2;
    b21 ^= vb2;
    vb2 = b02 ^ b12 ^ b22;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b02 ^= vb1;
    b12 ^= vb1;
    b22 ^= vb1;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b03 ^= vb2;
    b13 ^= vb2;
    b23 ^= vb2;
    vc1 = c03 ^ c13 ^ c23;
    vc2 = c00 ^ c10 ^ c20;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c00 ^= vc1;
    c10 ^= vc1;
    c20 ^= vc1;
    vc1 = c01 ^ c11 ^ c21;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c01 ^= vc2;
    c11 ^= vc2;
    c21 ^= vc2;
    vc2 = c02 ^ c12 ^ c22;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c02 ^= vc1;
    c12 ^= vc1;
    c22 ^= vc1;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c03 ^= vc2;
    c13 ^= vc2;
    c23 ^= vc2;
    ;
    a20 = ((((uint32_t)a20) << ((11) % 32)) ^
           (((uint32_t)a20) >> ((32 - (11)) % 32)));
    a21 = ((((uint32_t)a21) << ((11) % 32)) ^
           (((uint32_t)a21) >> ((32 - (11)) % 32)));
    a22 = ((((uint32_t)a22) << ((11) % 32)) ^
           (((uint32_t)a22) >> ((32 - (11)) % 32)));
    a23 = ((((uint32_t)a23) << ((11) % 32)) ^
           (((uint32_t)a23) >> ((32 - (11)) % 32)));
    va1 = a13;
    a13 = a12;
    a12 = a11;
    a11 = a10;
    a10 = va1;
    b20 = ((((uint32_t)b20) << ((11) % 32)) ^
           (((uint32_t)b20) >> ((32 - (11)) % 32)));
    b21 = ((((uint32_t)b21) << ((11) % 32)) ^
           (((uint32_t)b21) >> ((32 - (11)) % 32)));
    b22 = ((((uint32_t)b22) << ((11) % 32)) ^
           (((uint32_t)b22) >> ((32 - (11)) % 32)));
    b23 = ((((uint32_t)b23) << ((11) % 32)) ^
           (((uint32_t)b23) >> ((32 - (11)) % 32)));
    vb1 = b13;
    b13 = b12;
    b12 = b11;
    b11 = b10;
    b10 = vb1;
    c20 = ((((uint32_t)c20) << ((11) % 32)) ^
           (((uint32_t)c20) >> ((32 - (11)) % 32)));
    c21 = ((((uint32_t)c21) << ((11) % 32)) ^
           (((uint32_t)c21) >> ((32 - (11)) % 32)));
    c22 = ((((uint32_t)c22) << ((11) % 32)) ^
           (((uint32_t)c22) >> ((32 - (11)) % 32)));
    c23 = ((((uint32_t)c23) << ((11) % 32)) ^
           (((uint32_t)c23) >> ((32 - (11)) % 32)));
    vc1 = c13;
    c13 = c12;
    c12 = c11;
    c11 = c10;
    c10 = vc1;
    ;
    a00 ^= 0x00000038;
    ;
    a00 ^= (~a10 & a20) ^ (a10 & b20) ^ (b10 & a20);
    b00 ^= (~b10 & b20) ^ (b10 & c20) ^ (c10 & b20);
    c00 ^= (~c10 & c20) ^ (c10 & a20) ^ (a10 & c20);
    a01 ^= (~a11 & a21) ^ (a11 & b21) ^ (b11 & a21);
    b01 ^= (~b11 & b21) ^ (b11 & c21) ^ (c11 & b21);
    c01 ^= (~c11 & c21) ^ (c11 & a21) ^ (a11 & c21);
    a02 ^= (~a12 & a22) ^ (a12 & b22) ^ (b12 & a22);
    b02 ^= (~b12 & b22) ^ (b12 & c22) ^ (c12 & b22);
    c02 ^= (~c12 & c22) ^ (c12 & a22) ^ (a12 & c22);
    a03 ^= (~a13 & a23) ^ (a13 & b23) ^ (b13 & a23);
    b03 ^= (~b13 & b23) ^ (b13 & c23) ^ (c13 & b23);
    c03 ^= (~c13 & c23) ^ (c13 & a23) ^ (a13 & c23);
    a10 ^= (~a20 & a00) ^ (a20 & b00) ^ (b20 & a00);
    b10 ^= (~b20 & b00) ^ (b20 & c00) ^ (c20 & b00);
    c10 ^= (~c20 & c00) ^ (c20 & a00) ^ (a20 & c00);
    a11 ^= (~a21 & a01) ^ (a21 & b01) ^ (b21 & a01);
    b11 ^= (~b21 & b01) ^ (b21 & c01) ^ (c21 & b01);
    c11 ^= (~c21 & c01) ^ (c21 & a01) ^ (a21 & c01);
    a12 ^= (~a22 & a02) ^ (a22 & b02) ^ (b22 & a02);
    b12 ^= (~b22 & b02) ^ (b22 & c02) ^ (c22 & b02);
    c12 ^= (~c22 & c02) ^ (c22 & a02) ^ (a22 & c02);
    a13 ^= (~a23 & a03) ^ (a23 & b03) ^ (b23 & a03);
    b13 ^= (~b23 & b03) ^ (b23 & c03) ^ (c23 & b03);
    c13 ^= (~c23 & c03) ^ (c23 & a03) ^ (a23 & c03);
    a20 ^= (~a00 & a10) ^ (a00 & b10) ^ (b00 & a10);
    b20 ^= (~b00 & b10) ^ (b00 & c10) ^ (c00 & b10);
    c20 ^= (~c00 & c10) ^ (c00 & a10) ^ (a00 & c10);
    a21 ^= (~a01 & a11) ^ (a01 & b11) ^ (b01 & a11);
    b21 ^= (~b01 & b11) ^ (b01 & c11) ^ (c01 & b11);
    c21 ^= (~c01 & c11) ^ (c01 & a11) ^ (a01 & c11);
    a22 ^= (~a02 & a12) ^ (a02 & b12) ^ (b02 & a12);
    b22 ^= (~b02 & b12) ^ (b02 & c12) ^ (c02 & b12);
    c22 ^= (~c02 & c12) ^ (c02 & a12) ^ (a02 & c12);
    a23 ^= (~a03 & a13) ^ (a03 & b13) ^ (b03 & a13);
    b23 ^= (~b03 & b13) ^ (b03 & c13) ^ (c03 & b13);
    c23 ^= (~c03 & c13) ^ (c03 & a13) ^ (a03 & c13);
    ;
    ;
    a10 = ((((uint32_t)a10) << ((1) % 32)) ^
           (((uint32_t)a10) >> ((32 - (1)) % 32)));
    a11 = ((((uint32_t)a11) << ((1) % 32)) ^
           (((uint32_t)a11) >> ((32 - (1)) % 32)));
    a12 = ((((uint32_t)a12) << ((1) % 32)) ^
           (((uint32_t)a12) >> ((32 - (1)) % 32)));
    a13 = ((((uint32_t)a13) << ((1) % 32)) ^
           (((uint32_t)a13) >> ((32 - (1)) % 32)));
    va1 = ((((uint32_t)a23) << ((8) % 32)) ^
           (((uint32_t)a23) >> ((32 - (8)) % 32)));
    a23 = ((((uint32_t)a21) << ((8) % 32)) ^
           (((uint32_t)a21) >> ((32 - (8)) % 32)));
    a21 = va1;
    va1 = ((((uint32_t)a22) << ((8) % 32)) ^
           (((uint32_t)a22) >> ((32 - (8)) % 32)));
    a22 = ((((uint32_t)a20) << ((8) % 32)) ^
           (((uint32_t)a20) >> ((32 - (8)) % 32)));
    a20 = va1;
    b10 = ((((uint32_t)b10) << ((1) % 32)) ^
           (((uint32_t)b10) >> ((32 - (1)) % 32)));
    b11 = ((((uint32_t)b11) << ((1) % 32)) ^
           (((uint32_t)b11) >> ((32 - (1)) % 32)));
    b12 = ((((uint32_t)b12) << ((1) % 32)) ^
           (((uint32_t)b12) >> ((32 - (1)) % 32)));
    b13 = ((((uint32_t)b13) << ((1) % 32)) ^
           (((uint32_t)b13) >> ((32 - (1)) % 32)));
    vb1 = ((((uint32_t)b23) << ((8) % 32)) ^
           (((uint32_t)b23) >> ((32 - (8)) % 32)));
    b23 = ((((uint32_t)b21) << ((8) % 32)) ^
           (((uint32_t)b21) >> ((32 - (8)) % 32)));
    b21 = vb1;
    vb1 = ((((uint32_t)b22) << ((8) % 32)) ^
           (((uint32_t)b22) >> ((32 - (8)) % 32)));
    b22 = ((((uint32_t)b20) << ((8) % 32)) ^
           (((uint32_t)b20) >> ((32 - (8)) % 32)));
    b20 = vb1;
    c10 = ((((uint32_t)c10) << ((1) % 32)) ^
           (((uint32_t)c10) >> ((32 - (1)) % 32)));
    c11 = ((((uint32_t)c11) << ((1) % 32)) ^
           (((uint32_t)c11) >> ((32 - (1)) % 32)));
    c12 = ((((uint32_t)c12) << ((1) % 32)) ^
           (((uint32_t)c12) >> ((32 - (1)) % 32)));
    c13 = ((((uint32_t)c13) << ((1) % 32)) ^
           (((uint32_t)c13) >> ((32 - (1)) % 32)));
    vc1 = ((((uint32_t)c23) << ((8) % 32)) ^
           (((uint32_t)c23) >> ((32 - (8)) % 32)));
    c23 = ((((uint32_t)c21) << ((8) % 32)) ^
           (((uint32_t)c21) >> ((32 - (8)) % 32)));
    c21 = vc1;
    vc1 = ((((uint32_t)c22) << ((8) % 32)) ^
           (((uint32_t)c22) >> ((32 - (8)) % 32)));
    c22 = ((((uint32_t)c20) << ((8) % 32)) ^
           (((uint32_t)c20) >> ((32 - (8)) % 32)));
    c20 = vc1;
    ;
    va1 = a03 ^ a13 ^ a23;
    va2 = a00 ^ a10 ^ a20;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a00 ^= va1;
    a10 ^= va1;
    a20 ^= va1;
    va1 = a01 ^ a11 ^ a21;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a01 ^= va2;
    a11 ^= va2;
    a21 ^= va2;
    va2 = a02 ^ a12 ^ a22;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a02 ^= va1;
    a12 ^= va1;
    a22 ^= va1;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a03 ^= va2;
    a13 ^= va2;
    a23 ^= va2;
    vb1 = b03 ^ b13 ^ b23;
    vb2 = b00 ^ b10 ^ b20;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b00 ^= vb1;
    b10 ^= vb1;
    b20 ^= vb1;
    vb1 = b01 ^ b11 ^ b21;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b01 ^= vb2;
    b11 ^= vb2;
    b21 ^= vb2;
    vb2 = b02 ^ b12 ^ b22;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b02 ^= vb1;
    b12 ^= vb1;
    b22 ^= vb1;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b03 ^= vb2;
    b13 ^= vb2;
    b23 ^= vb2;
    vc1 = c03 ^ c13 ^ c23;
    vc2 = c00 ^ c10 ^ c20;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c00 ^= vc1;
    c10 ^= vc1;
    c20 ^= vc1;
    vc1 = c01 ^ c11 ^ c21;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c01 ^= vc2;
    c11 ^= vc2;
    c21 ^= vc2;
    vc2 = c02 ^ c12 ^ c22;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c02 ^= vc1;
    c12 ^= vc1;
    c22 ^= vc1;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c03 ^= vc2;
    c13 ^= vc2;
    c23 ^= vc2;
    ;
    a20 = ((((uint32_t)a20) << ((11) % 32)) ^
           (((uint32_t)a20) >> ((32 - (11)) % 32)));
    a21 = ((((uint32_t)a21) << ((11) % 32)) ^
           (((uint32_t)a21) >> ((32 - (11)) % 32)));
    a22 = ((((uint32_t)a22) << ((11) % 32)) ^
           (((uint32_t)a22) >> ((32 - (11)) % 32)));
    a23 = ((((uint32_t)a23) << ((11) % 32)) ^
           (((uint32_t)a23) >> ((32 - (11)) % 32)));
    va1 = a13;
    a13 = a12;
    a12 = a11;
    a11 = a10;
    a10 = va1;
    b20 = ((((uint32_t)b20) << ((11) % 32)) ^
           (((uint32_t)b20) >> ((32 - (11)) % 32)));
    b21 = ((((uint32_t)b21) << ((11) % 32)) ^
           (((uint32_t)b21) >> ((32 - (11)) % 32)));
    b22 = ((((uint32_t)b22) << ((11) % 32)) ^
           (((uint32_t)b22) >> ((32 - (11)) % 32)));
    b23 = ((((uint32_t)b23) << ((11) % 32)) ^
           (((uint32_t)b23) >> ((32 - (11)) % 32)));
    vb1 = b13;
    b13 = b12;
    b12 = b11;
    b11 = b10;
    b10 = vb1;
    c20 = ((((uint32_t)c20) << ((11) % 32)) ^
           (((uint32_t)c20) >> ((32 - (11)) % 32)));
    c21 = ((((uint32_t)c21) << ((11) % 32)) ^
           (((uint32_t)c21) >> ((32 - (11)) % 32)));
    c22 = ((((uint32_t)c22) << ((11) % 32)) ^
           (((uint32_t)c22) >> ((32 - (11)) % 32)));
    c23 = ((((uint32_t)c23) << ((11) % 32)) ^
           (((uint32_t)c23) >> ((32 - (11)) % 32)));
    vc1 = c13;
    c13 = c12;
    c12 = c11;
    c11 = c10;
    c10 = vc1;
    ;
    a00 ^= 0x000003C0;
    ;
    a00 ^= (~a10 & a20) ^ (a10 & b20) ^ (b10 & a20);
    b00 ^= (~b10 & b20) ^ (b10 & c20) ^ (c10 & b20);
    c00 ^= (~c10 & c20) ^ (c10 & a20) ^ (a10 & c20);
    a01 ^= (~a11 & a21) ^ (a11 & b21) ^ (b11 & a21);
    b01 ^= (~b11 & b21) ^ (b11 & c21) ^ (c11 & b21);
    c01 ^= (~c11 & c21) ^ (c11 & a21) ^ (a11 & c21);
    a02 ^= (~a12 & a22) ^ (a12 & b22) ^ (b12 & a22);
    b02 ^= (~b12 & b22) ^ (b12 & c22) ^ (c12 & b22);
    c02 ^= (~c12 & c22) ^ (c12 & a22) ^ (a12 & c22);
    a03 ^= (~a13 & a23) ^ (a13 & b23) ^ (b13 & a23);
    b03 ^= (~b13 & b23) ^ (b13 & c23) ^ (c13 & b23);
    c03 ^= (~c13 & c23) ^ (c13 & a23) ^ (a13 & c23);
    a10 ^= (~a20 & a00) ^ (a20 & b00) ^ (b20 & a00);
    b10 ^= (~b20 & b00) ^ (b20 & c00) ^ (c20 & b00);
    c10 ^= (~c20 & c00) ^ (c20 & a00) ^ (a20 & c00);
    a11 ^= (~a21 & a01) ^ (a21 & b01) ^ (b21 & a01);
    b11 ^= (~b21 & b01) ^ (b21 & c01) ^ (c21 & b01);
    c11 ^= (~c21 & c01) ^ (c21 & a01) ^ (a21 & c01);
    a12 ^= (~a22 & a02) ^ (a22 & b02) ^ (b22 & a02);
    b12 ^= (~b22 & b02) ^ (b22 & c02) ^ (c22 & b02);
    c12 ^= (~c22 & c02) ^ (c22 & a02) ^ (a22 & c02);
    a13 ^= (~a23 & a03) ^ (a23 & b03) ^ (b23 & a03);
    b13 ^= (~b23 & b03) ^ (b23 & c03) ^ (c23 & b03);
    c13 ^= (~c23 & c03) ^ (c23 & a03) ^ (a23 & c03);
    a20 ^= (~a00 & a10) ^ (a00 & b10) ^ (b00 & a10);
    b20 ^= (~b00 & b10) ^ (b00 & c10) ^ (c00 & b10);
    c20 ^= (~c00 & c10) ^ (c00 & a10) ^ (a00 & c10);
    a21 ^= (~a01 & a11) ^ (a01 & b11) ^ (b01 & a11);
    b21 ^= (~b01 & b11) ^ (b01 & c11) ^ (c01 & b11);
    c21 ^= (~c01 & c11) ^ (c01 & a11) ^ (a01 & c11);
    a22 ^= (~a02 & a12) ^ (a02 & b12) ^ (b02 & a12);
    b22 ^= (~b02 & b12) ^ (b02 & c12) ^ (c02 & b12);
    c22 ^= (~c02 & c12) ^ (c02 & a12) ^ (a02 & c12);
    a23 ^= (~a03 & a13) ^ (a03 & b13) ^ (b03 & a13);
    b23 ^= (~b03 & b13) ^ (b03 & c13) ^ (c03 & b13);
    c23 ^= (~c03 & c13) ^ (c03 & a13) ^ (a03 & c13);
    ;
    ;
    a10 = ((((uint32_t)a10) << ((1) % 32)) ^
           (((uint32_t)a10) >> ((32 - (1)) % 32)));
    a11 = ((((uint32_t)a11) << ((1) % 32)) ^
           (((uint32_t)a11) >> ((32 - (1)) % 32)));
    a12 = ((((uint32_t)a12) << ((1) % 32)) ^
           (((uint32_t)a12) >> ((32 - (1)) % 32)));
    a13 = ((((uint32_t)a13) << ((1) % 32)) ^
           (((uint32_t)a13) >> ((32 - (1)) % 32)));
    va1 = ((((uint32_t)a23) << ((8) % 32)) ^
           (((uint32_t)a23) >> ((32 - (8)) % 32)));
    a23 = ((((uint32_t)a21) << ((8) % 32)) ^
           (((uint32_t)a21) >> ((32 - (8)) % 32)));
    a21 = va1;
    va1 = ((((uint32_t)a22) << ((8) % 32)) ^
           (((uint32_t)a22) >> ((32 - (8)) % 32)));
    a22 = ((((uint32_t)a20) << ((8) % 32)) ^
           (((uint32_t)a20) >> ((32 - (8)) % 32)));
    a20 = va1;
    b10 = ((((uint32_t)b10) << ((1) % 32)) ^
           (((uint32_t)b10) >> ((32 - (1)) % 32)));
    b11 = ((((uint32_t)b11) << ((1) % 32)) ^
           (((uint32_t)b11) >> ((32 - (1)) % 32)));
    b12 = ((((uint32_t)b12) << ((1) % 32)) ^
           (((uint32_t)b12) >> ((32 - (1)) % 32)));
    b13 = ((((uint32_t)b13) << ((1) % 32)) ^
           (((uint32_t)b13) >> ((32 - (1)) % 32)));
    vb1 = ((((uint32_t)b23) << ((8) % 32)) ^
           (((uint32_t)b23) >> ((32 - (8)) % 32)));
    b23 = ((((uint32_t)b21) << ((8) % 32)) ^
           (((uint32_t)b21) >> ((32 - (8)) % 32)));
    b21 = vb1;
    vb1 = ((((uint32_t)b22) << ((8) % 32)) ^
           (((uint32_t)b22) >> ((32 - (8)) % 32)));
    b22 = ((((uint32_t)b20) << ((8) % 32)) ^
           (((uint32_t)b20) >> ((32 - (8)) % 32)));
    b20 = vb1;
    c10 = ((((uint32_t)c10) << ((1) % 32)) ^
           (((uint32_t)c10) >> ((32 - (1)) % 32)));
    c11 = ((((uint32_t)c11) << ((1) % 32)) ^
           (((uint32_t)c11) >> ((32 - (1)) % 32)));
    c12 = ((((uint32_t)c12) << ((1) % 32)) ^
           (((uint32_t)c12) >> ((32 - (1)) % 32)));
    c13 = ((((uint32_t)c13) << ((1) % 32)) ^
           (((uint32_t)c13) >> ((32 - (1)) % 32)));
    vc1 = ((((uint32_t)c23) << ((8) % 32)) ^
           (((uint32_t)c23) >> ((32 - (8)) % 32)));
    c23 = ((((uint32_t)c21) << ((8) % 32)) ^
           (((uint32_t)c21) >> ((32 - (8)) % 32)));
    c21 = vc1;
    vc1 = ((((uint32_t)c22) << ((8) % 32)) ^
           (((uint32_t)c22) >> ((32 - (8)) % 32)));
    c22 = ((((uint32_t)c20) << ((8) % 32)) ^
           (((uint32_t)c20) >> ((32 - (8)) % 32)));
    c20 = vc1;
    ;
    va1 = a03 ^ a13 ^ a23;
    va2 = a00 ^ a10 ^ a20;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a00 ^= va1;
    a10 ^= va1;
    a20 ^= va1;
    va1 = a01 ^ a11 ^ a21;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a01 ^= va2;
    a11 ^= va2;
    a21 ^= va2;
    va2 = a02 ^ a12 ^ a22;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a02 ^= va1;
    a12 ^= va1;
    a22 ^= va1;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a03 ^= va2;
    a13 ^= va2;
    a23 ^= va2;
    vb1 = b03 ^ b13 ^ b23;
    vb2 = b00 ^ b10 ^ b20;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b00 ^= vb1;
    b10 ^= vb1;
    b20 ^= vb1;
    vb1 = b01 ^ b11 ^ b21;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b01 ^= vb2;
    b11 ^= vb2;
    b21 ^= vb2;
    vb2 = b02 ^ b12 ^ b22;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b02 ^= vb1;
    b12 ^= vb1;
    b22 ^= vb1;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b03 ^= vb2;
    b13 ^= vb2;
    b23 ^= vb2;
    vc1 = c03 ^ c13 ^ c23;
    vc2 = c00 ^ c10 ^ c20;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c00 ^= vc1;
    c10 ^= vc1;
    c20 ^= vc1;
    vc1 = c01 ^ c11 ^ c21;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c01 ^= vc2;
    c11 ^= vc2;
    c21 ^= vc2;
    vc2 = c02 ^ c12 ^ c22;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c02 ^= vc1;
    c12 ^= vc1;
    c22 ^= vc1;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c03 ^= vc2;
    c13 ^= vc2;
    c23 ^= vc2;
    ;
    a20 = ((((uint32_t)a20) << ((11) % 32)) ^
           (((uint32_t)a20) >> ((32 - (11)) % 32)));
    a21 = ((((uint32_t)a21) << ((11) % 32)) ^
           (((uint32_t)a21) >> ((32 - (11)) % 32)));
    a22 = ((((uint32_t)a22) << ((11) % 32)) ^
           (((uint32_t)a22) >> ((32 - (11)) % 32)));
    a23 = ((((uint32_t)a23) << ((11) % 32)) ^
           (((uint32_t)a23) >> ((32 - (11)) % 32)));
    va1 = a13;
    a13 = a12;
    a12 = a11;
    a11 = a10;
    a10 = va1;
    b20 = ((((uint32_t)b20) << ((11) % 32)) ^
           (((uint32_t)b20) >> ((32 - (11)) % 32)));
    b21 = ((((uint32_t)b21) << ((11) % 32)) ^
           (((uint32_t)b21) >> ((32 - (11)) % 32)));
    b22 = ((((uint32_t)b22) << ((11) % 32)) ^
           (((uint32_t)b22) >> ((32 - (11)) % 32)));
    b23 = ((((uint32_t)b23) << ((11) % 32)) ^
           (((uint32_t)b23) >> ((32 - (11)) % 32)));
    vb1 = b13;
    b13 = b12;
    b12 = b11;
    b11 = b10;
    b10 = vb1;
    c20 = ((((uint32_t)c20) << ((11) % 32)) ^
           (((uint32_t)c20) >> ((32 - (11)) % 32)));
    c21 = ((((uint32_t)c21) << ((11) % 32)) ^
           (((uint32_t)c21) >> ((32 - (11)) % 32)));
    c22 = ((((uint32_t)c22) << ((11) % 32)) ^
           (((uint32_t)c22) >> ((32 - (11)) % 32)));
    c23 = ((((uint32_t)c23) << ((11) % 32)) ^
           (((uint32_t)c23) >> ((32 - (11)) % 32)));
    vc1 = c13;
    c13 = c12;
    c12 = c11;
    c11 = c10;
    c10 = vc1;
    ;
    a00 ^= 0x000000D0;
    ;
    a00 ^= (~a10 & a20) ^ (a10 & b20) ^ (b10 & a20);
    b00 ^= (~b10 & b20) ^ (b10 & c20) ^ (c10 & b20);
    c00 ^= (~c10 & c20) ^ (c10 & a20) ^ (a10 & c20);
    a01 ^= (~a11 & a21) ^ (a11 & b21) ^ (b11 & a21);
    b01 ^= (~b11 & b21) ^ (b11 & c21) ^ (c11 & b21);
    c01 ^= (~c11 & c21) ^ (c11 & a21) ^ (a11 & c21);
    a02 ^= (~a12 & a22) ^ (a12 & b22) ^ (b12 & a22);
    b02 ^= (~b12 & b22) ^ (b12 & c22) ^ (c12 & b22);
    c02 ^= (~c12 & c22) ^ (c12 & a22) ^ (a12 & c22);
    a03 ^= (~a13 & a23) ^ (a13 & b23) ^ (b13 & a23);
    b03 ^= (~b13 & b23) ^ (b13 & c23) ^ (c13 & b23);
    c03 ^= (~c13 & c23) ^ (c13 & a23) ^ (a13 & c23);
    a10 ^= (~a20 & a00) ^ (a20 & b00) ^ (b20 & a00);
    b10 ^= (~b20 & b00) ^ (b20 & c00) ^ (c20 & b00);
    c10 ^= (~c20 & c00) ^ (c20 & a00) ^ (a20 & c00);
    a11 ^= (~a21 & a01) ^ (a21 & b01) ^ (b21 & a01);
    b11 ^= (~b21 & b01) ^ (b21 & c01) ^ (c21 & b01);
    c11 ^= (~c21 & c01) ^ (c21 & a01) ^ (a21 & c01);
    a12 ^= (~a22 & a02) ^ (a22 & b02) ^ (b22 & a02);
    b12 ^= (~b22 & b02) ^ (b22 & c02) ^ (c22 & b02);
    c12 ^= (~c22 & c02) ^ (c22 & a02) ^ (a22 & c02);
    a13 ^= (~a23 & a03) ^ (a23 & b03) ^ (b23 & a03);
    b13 ^= (~b23 & b03) ^ (b23 & c03) ^ (c23 & b03);
    c13 ^= (~c23 & c03) ^ (c23 & a03) ^ (a23 & c03);
    a20 ^= (~a00 & a10) ^ (a00 & b10) ^ (b00 & a10);
    b20 ^= (~b00 & b10) ^ (b00 & c10) ^ (c00 & b10);
    c20 ^= (~c00 & c10) ^ (c00 & a10) ^ (a00 & c10);
    a21 ^= (~a01 & a11) ^ (a01 & b11) ^ (b01 & a11);
    b21 ^= (~b01 & b11) ^ (b01 & c11) ^ (c01 & b11);
    c21 ^= (~c01 & c11) ^ (c01 & a11) ^ (a01 & c11);
    a22 ^= (~a02 & a12) ^ (a02 & b12) ^ (b02 & a12);
    b22 ^= (~b02 & b12) ^ (b02 & c12) ^ (c02 & b12);
    c22 ^= (~c02 & c12) ^ (c02 & a12) ^ (a02 & c12);
    a23 ^= (~a03 & a13) ^ (a03 & b13) ^ (b03 & a13);
    b23 ^= (~b03 & b13) ^ (b03 & c13) ^ (c03 & b13);
    c23 ^= (~c03 & c13) ^ (c03 & a13) ^ (a03 & c13);
    ;
    ;
    a10 = ((((uint32_t)a10) << ((1) % 32)) ^
           (((uint32_t)a10) >> ((32 - (1)) % 32)));
    a11 = ((((uint32_t)a11) << ((1) % 32)) ^
           (((uint32_t)a11) >> ((32 - (1)) % 32)));
    a12 = ((((uint32_t)a12) << ((1) % 32)) ^
           (((uint32_t)a12) >> ((32 - (1)) % 32)));
    a13 = ((((uint32_t)a13) << ((1) % 32)) ^
           (((uint32_t)a13) >> ((32 - (1)) % 32)));
    va1 = ((((uint32_t)a23) << ((8) % 32)) ^
           (((uint32_t)a23) >> ((32 - (8)) % 32)));
    a23 = ((((uint32_t)a21) << ((8) % 32)) ^
           (((uint32_t)a21) >> ((32 - (8)) % 32)));
    a21 = va1;
    va1 = ((((uint32_t)a22) << ((8) % 32)) ^
           (((uint32_t)a22) >> ((32 - (8)) % 32)));
    a22 = ((((uint32_t)a20) << ((8) % 32)) ^
           (((uint32_t)a20) >> ((32 - (8)) % 32)));
    a20 = va1;
    b10 = ((((uint32_t)b10) << ((1) % 32)) ^
           (((uint32_t)b10) >> ((32 - (1)) % 32)));
    b11 = ((((uint32_t)b11) << ((1) % 32)) ^
           (((uint32_t)b11) >> ((32 - (1)) % 32)));
    b12 = ((((uint32_t)b12) << ((1) % 32)) ^
           (((uint32_t)b12) >> ((32 - (1)) % 32)));
    b13 = ((((uint32_t)b13) << ((1) % 32)) ^
           (((uint32_t)b13) >> ((32 - (1)) % 32)));
    vb1 = ((((uint32_t)b23) << ((8) % 32)) ^
           (((uint32_t)b23) >> ((32 - (8)) % 32)));
    b23 = ((((uint32_t)b21) << ((8) % 32)) ^
           (((uint32_t)b21) >> ((32 - (8)) % 32)));
    b21 = vb1;
    vb1 = ((((uint32_t)b22) << ((8) % 32)) ^
           (((uint32_t)b22) >> ((32 - (8)) % 32)));
    b22 = ((((uint32_t)b20) << ((8) % 32)) ^
           (((uint32_t)b20) >> ((32 - (8)) % 32)));
    b20 = vb1;
    c10 = ((((uint32_t)c10) << ((1) % 32)) ^
           (((uint32_t)c10) >> ((32 - (1)) % 32)));
    c11 = ((((uint32_t)c11) << ((1) % 32)) ^
           (((uint32_t)c11) >> ((32 - (1)) % 32)));
    c12 = ((((uint32_t)c12) << ((1) % 32)) ^
           (((uint32_t)c12) >> ((32 - (1)) % 32)));
    c13 = ((((uint32_t)c13) << ((1) % 32)) ^
           (((uint32_t)c13) >> ((32 - (1)) % 32)));
    vc1 = ((((uint32_t)c23) << ((8) % 32)) ^
           (((uint32_t)c23) >> ((32 - (8)) % 32)));
    c23 = ((((uint32_t)c21) << ((8) % 32)) ^
           (((uint32_t)c21) >> ((32 - (8)) % 32)));
    c21 = vc1;
    vc1 = ((((uint32_t)c22) << ((8) % 32)) ^
           (((uint32_t)c22) >> ((32 - (8)) % 32)));
    c22 = ((((uint32_t)c20) << ((8) % 32)) ^
           (((uint32_t)c20) >> ((32 - (8)) % 32)));
    c20 = vc1;
    ;
    va1 = a03 ^ a13 ^ a23;
    va2 = a00 ^ a10 ^ a20;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a00 ^= va1;
    a10 ^= va1;
    a20 ^= va1;
    va1 = a01 ^ a11 ^ a21;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a01 ^= va2;
    a11 ^= va2;
    a21 ^= va2;
    va2 = a02 ^ a12 ^ a22;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a02 ^= va1;
    a12 ^= va1;
    a22 ^= va1;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a03 ^= va2;
    a13 ^= va2;
    a23 ^= va2;
    vb1 = b03 ^ b13 ^ b23;
    vb2 = b00 ^ b10 ^ b20;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b00 ^= vb1;
    b10 ^= vb1;
    b20 ^= vb1;
    vb1 = b01 ^ b11 ^ b21;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b01 ^= vb2;
    b11 ^= vb2;
    b21 ^= vb2;
    vb2 = b02 ^ b12 ^ b22;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b02 ^= vb1;
    b12 ^= vb1;
    b22 ^= vb1;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b03 ^= vb2;
    b13 ^= vb2;
    b23 ^= vb2;
    vc1 = c03 ^ c13 ^ c23;
    vc2 = c00 ^ c10 ^ c20;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c00 ^= vc1;
    c10 ^= vc1;
    c20 ^= vc1;
    vc1 = c01 ^ c11 ^ c21;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c01 ^= vc2;
    c11 ^= vc2;
    c21 ^= vc2;
    vc2 = c02 ^ c12 ^ c22;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c02 ^= vc1;
    c12 ^= vc1;
    c22 ^= vc1;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c03 ^= vc2;
    c13 ^= vc2;
    c23 ^= vc2;
    ;
    a20 = ((((uint32_t)a20) << ((11) % 32)) ^
           (((uint32_t)a20) >> ((32 - (11)) % 32)));
    a21 = ((((uint32_t)a21) << ((11) % 32)) ^
           (((uint32_t)a21) >> ((32 - (11)) % 32)));
    a22 = ((((uint32_t)a22) << ((11) % 32)) ^
           (((uint32_t)a22) >> ((32 - (11)) % 32)));
    a23 = ((((uint32_t)a23) << ((11) % 32)) ^
           (((uint32_t)a23) >> ((32 - (11)) % 32)));
    va1 = a13;
    a13 = a12;
    a12 = a11;
    a11 = a10;
    a10 = va1;
    b20 = ((((uint32_t)b20) << ((11) % 32)) ^
           (((uint32_t)b20) >> ((32 - (11)) % 32)));
    b21 = ((((uint32_t)b21) << ((11) % 32)) ^
           (((uint32_t)b21) >> ((32 - (11)) % 32)));
    b22 = ((((uint32_t)b22) << ((11) % 32)) ^
           (((uint32_t)b22) >> ((32 - (11)) % 32)));
    b23 = ((((uint32_t)b23) << ((11) % 32)) ^
           (((uint32_t)b23) >> ((32 - (11)) % 32)));
    vb1 = b13;
    b13 = b12;
    b12 = b11;
    b11 = b10;
    b10 = vb1;
    c20 = ((((uint32_t)c20) << ((11) % 32)) ^
           (((uint32_t)c20) >> ((32 - (11)) % 32)));
    c21 = ((((uint32_t)c21) << ((11) % 32)) ^
           (((uint32_t)c21) >> ((32 - (11)) % 32)));
    c22 = ((((uint32_t)c22) << ((11) % 32)) ^
           (((uint32_t)c22) >> ((32 - (11)) % 32)));
    c23 = ((((uint32_t)c23) << ((11) % 32)) ^
           (((uint32_t)c23) >> ((32 - (11)) % 32)));
    vc1 = c13;
    c13 = c12;
    c12 = c11;
    c11 = c10;
    c10 = vc1;
    ;
    a00 ^= 0x00000120;
    ;
    a00 ^= (~a10 & a20) ^ (a10 & b20) ^ (b10 & a20);
    b00 ^= (~b10 & b20) ^ (b10 & c20) ^ (c10 & b20);
    c00 ^= (~c10 & c20) ^ (c10 & a20) ^ (a10 & c20);
    a01 ^= (~a11 & a21) ^ (a11 & b21) ^ (b11 & a21);
    b01 ^= (~b11 & b21) ^ (b11 & c21) ^ (c11 & b21);
    c01 ^= (~c11 & c21) ^ (c11 & a21) ^ (a11 & c21);
    a02 ^= (~a12 & a22) ^ (a12 & b22) ^ (b12 & a22);
    b02 ^= (~b12 & b22) ^ (b12 & c22) ^ (c12 & b22);
    c02 ^= (~c12 & c22) ^ (c12 & a22) ^ (a12 & c22);
    a03 ^= (~a13 & a23) ^ (a13 & b23) ^ (b13 & a23);
    b03 ^= (~b13 & b23) ^ (b13 & c23) ^ (c13 & b23);
    c03 ^= (~c13 & c23) ^ (c13 & a23) ^ (a13 & c23);
    a10 ^= (~a20 & a00) ^ (a20 & b00) ^ (b20 & a00);
    b10 ^= (~b20 & b00) ^ (b20 & c00) ^ (c20 & b00);
    c10 ^= (~c20 & c00) ^ (c20 & a00) ^ (a20 & c00);
    a11 ^= (~a21 & a01) ^ (a21 & b01) ^ (b21 & a01);
    b11 ^= (~b21 & b01) ^ (b21 & c01) ^ (c21 & b01);
    c11 ^= (~c21 & c01) ^ (c21 & a01) ^ (a21 & c01);
    a12 ^= (~a22 & a02) ^ (a22 & b02) ^ (b22 & a02);
    b12 ^= (~b22 & b02) ^ (b22 & c02) ^ (c22 & b02);
    c12 ^= (~c22 & c02) ^ (c22 & a02) ^ (a22 & c02);
    a13 ^= (~a23 & a03) ^ (a23 & b03) ^ (b23 & a03);
    b13 ^= (~b23 & b03) ^ (b23 & c03) ^ (c23 & b03);
    c13 ^= (~c23 & c03) ^ (c23 & a03) ^ (a23 & c03);
    a20 ^= (~a00 & a10) ^ (a00 & b10) ^ (b00 & a10);
    b20 ^= (~b00 & b10) ^ (b00 & c10) ^ (c00 & b10);
    c20 ^= (~c00 & c10) ^ (c00 & a10) ^ (a00 & c10);
    a21 ^= (~a01 & a11) ^ (a01 & b11) ^ (b01 & a11);
    b21 ^= (~b01 & b11) ^ (b01 & c11) ^ (c01 & b11);
    c21 ^= (~c01 & c11) ^ (c01 & a11) ^ (a01 & c11);
    a22 ^= (~a02 & a12) ^ (a02 & b12) ^ (b02 & a12);
    b22 ^= (~b02 & b12) ^ (b02 & c12) ^ (c02 & b12);
    c22 ^= (~c02 & c12) ^ (c02 & a12) ^ (a02 & c12);
    a23 ^= (~a03 & a13) ^ (a03 & b13) ^ (b03 & a13);
    b23 ^= (~b03 & b13) ^ (b03 & c13) ^ (c03 & b13);
    c23 ^= (~c03 & c13) ^ (c03 & a13) ^ (a03 & c13);
    ;
    ;
    a10 = ((((uint32_t)a10) << ((1) % 32)) ^
           (((uint32_t)a10) >> ((32 - (1)) % 32)));
    a11 = ((((uint32_t)a11) << ((1) % 32)) ^
           (((uint32_t)a11) >> ((32 - (1)) % 32)));
    a12 = ((((uint32_t)a12) << ((1) % 32)) ^
           (((uint32_t)a12) >> ((32 - (1)) % 32)));
    a13 = ((((uint32_t)a13) << ((1) % 32)) ^
           (((uint32_t)a13) >> ((32 - (1)) % 32)));
    va1 = ((((uint32_t)a23) << ((8) % 32)) ^
           (((uint32_t)a23) >> ((32 - (8)) % 32)));
    a23 = ((((uint32_t)a21) << ((8) % 32)) ^
           (((uint32_t)a21) >> ((32 - (8)) % 32)));
    a21 = va1;
    va1 = ((((uint32_t)a22) << ((8) % 32)) ^
           (((uint32_t)a22) >> ((32 - (8)) % 32)));
    a22 = ((((uint32_t)a20) << ((8) % 32)) ^
           (((uint32_t)a20) >> ((32 - (8)) % 32)));
    a20 = va1;
    b10 = ((((uint32_t)b10) << ((1) % 32)) ^
           (((uint32_t)b10) >> ((32 - (1)) % 32)));
    b11 = ((((uint32_t)b11) << ((1) % 32)) ^
           (((uint32_t)b11) >> ((32 - (1)) % 32)));
    b12 = ((((uint32_t)b12) << ((1) % 32)) ^
           (((uint32_t)b12) >> ((32 - (1)) % 32)));
    b13 = ((((uint32_t)b13) << ((1) % 32)) ^
           (((uint32_t)b13) >> ((32 - (1)) % 32)));
    vb1 = ((((uint32_t)b23) << ((8) % 32)) ^
           (((uint32_t)b23) >> ((32 - (8)) % 32)));
    b23 = ((((uint32_t)b21) << ((8) % 32)) ^
           (((uint32_t)b21) >> ((32 - (8)) % 32)));
    b21 = vb1;
    vb1 = ((((uint32_t)b22) << ((8) % 32)) ^
           (((uint32_t)b22) >> ((32 - (8)) % 32)));
    b22 = ((((uint32_t)b20) << ((8) % 32)) ^
           (((uint32_t)b20) >> ((32 - (8)) % 32)));
    b20 = vb1;
    c10 = ((((uint32_t)c10) << ((1) % 32)) ^
           (((uint32_t)c10) >> ((32 - (1)) % 32)));
    c11 = ((((uint32_t)c11) << ((1) % 32)) ^
           (((uint32_t)c11) >> ((32 - (1)) % 32)));
    c12 = ((((uint32_t)c12) << ((1) % 32)) ^
           (((uint32_t)c12) >> ((32 - (1)) % 32)));
    c13 = ((((uint32_t)c13) << ((1) % 32)) ^
           (((uint32_t)c13) >> ((32 - (1)) % 32)));
    vc1 = ((((uint32_t)c23) << ((8) % 32)) ^
           (((uint32_t)c23) >> ((32 - (8)) % 32)));
    c23 = ((((uint32_t)c21) << ((8) % 32)) ^
           (((uint32_t)c21) >> ((32 - (8)) % 32)));
    c21 = vc1;
    vc1 = ((((uint32_t)c22) << ((8) % 32)) ^
           (((uint32_t)c22) >> ((32 - (8)) % 32)));
    c22 = ((((uint32_t)c20) << ((8) % 32)) ^
           (((uint32_t)c20) >> ((32 - (8)) % 32)));
    c20 = vc1;
    ;
    va1 = a03 ^ a13 ^ a23;
    va2 = a00 ^ a10 ^ a20;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a00 ^= va1;
    a10 ^= va1;
    a20 ^= va1;
    va1 = a01 ^ a11 ^ a21;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a01 ^= va2;
    a11 ^= va2;
    a21 ^= va2;
    va2 = a02 ^ a12 ^ a22;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a02 ^= va1;
    a12 ^= va1;
    a22 ^= va1;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a03 ^= va2;
    a13 ^= va2;
    a23 ^= va2;
    vb1 = b03 ^ b13 ^ b23;
    vb2 = b00 ^ b10 ^ b20;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b00 ^= vb1;
    b10 ^= vb1;
    b20 ^= vb1;
    vb1 = b01 ^ b11 ^ b21;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b01 ^= vb2;
    b11 ^= vb2;
    b21 ^= vb2;
    vb2 = b02 ^ b12 ^ b22;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b02 ^= vb1;
    b12 ^= vb1;
    b22 ^= vb1;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b03 ^= vb2;
    b13 ^= vb2;
    b23 ^= vb2;
    vc1 = c03 ^ c13 ^ c23;
    vc2 = c00 ^ c10 ^ c20;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c00 ^= vc1;
    c10 ^= vc1;
    c20 ^= vc1;
    vc1 = c01 ^ c11 ^ c21;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c01 ^= vc2;
    c11 ^= vc2;
    c21 ^= vc2;
    vc2 = c02 ^ c12 ^ c22;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c02 ^= vc1;
    c12 ^= vc1;
    c22 ^= vc1;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c03 ^= vc2;
    c13 ^= vc2;
    c23 ^= vc2;
    ;
    a20 = ((((uint32_t)a20) << ((11) % 32)) ^
           (((uint32_t)a20) >> ((32 - (11)) % 32)));
    a21 = ((((uint32_t)a21) << ((11) % 32)) ^
           (((uint32_t)a21) >> ((32 - (11)) % 32)));
    a22 = ((((uint32_t)a22) << ((11) % 32)) ^
           (((uint32_t)a22) >> ((32 - (11)) % 32)));
    a23 = ((((uint32_t)a23) << ((11) % 32)) ^
           (((uint32_t)a23) >> ((32 - (11)) % 32)));
    va1 = a13;
    a13 = a12;
    a12 = a11;
    a11 = a10;
    a10 = va1;
    b20 = ((((uint32_t)b20) << ((11) % 32)) ^
           (((uint32_t)b20) >> ((32 - (11)) % 32)));
    b21 = ((((uint32_t)b21) << ((11) % 32)) ^
           (((uint32_t)b21) >> ((32 - (11)) % 32)));
    b22 = ((((uint32_t)b22) << ((11) % 32)) ^
           (((uint32_t)b22) >> ((32 - (11)) % 32)));
    b23 = ((((uint32_t)b23) << ((11) % 32)) ^
           (((uint32_t)b23) >> ((32 - (11)) % 32)));
    vb1 = b13;
    b13 = b12;
    b12 = b11;
    b11 = b10;
    b10 = vb1;
    c20 = ((((uint32_t)c20) << ((11) % 32)) ^
           (((uint32_t)c20) >> ((32 - (11)) % 32)));
    c21 = ((((uint32_t)c21) << ((11) % 32)) ^
           (((uint32_t)c21) >> ((32 - (11)) % 32)));
    c22 = ((((uint32_t)c22) << ((11) % 32)) ^
           (((uint32_t)c22) >> ((32 - (11)) % 32)));
    c23 = ((((uint32_t)c23) << ((11) % 32)) ^
           (((uint32_t)c23) >> ((32 - (11)) % 32)));
    vc1 = c13;
    c13 = c12;
    c12 = c11;
    c11 = c10;
    c10 = vc1;
    ;
    a00 ^= 0x00000014;
    ;
    a00 ^= (~a10 & a20) ^ (a10 & b20) ^ (b10 & a20);
    b00 ^= (~b10 & b20) ^ (b10 & c20) ^ (c10 & b20);
    c00 ^= (~c10 & c20) ^ (c10 & a20) ^ (a10 & c20);
    a01 ^= (~a11 & a21) ^ (a11 & b21) ^ (b11 & a21);
    b01 ^= (~b11 & b21) ^ (b11 & c21) ^ (c11 & b21);
    c01 ^= (~c11 & c21) ^ (c11 & a21) ^ (a11 & c21);
    a02 ^= (~a12 & a22) ^ (a12 & b22) ^ (b12 & a22);
    b02 ^= (~b12 & b22) ^ (b12 & c22) ^ (c12 & b22);
    c02 ^= (~c12 & c22) ^ (c12 & a22) ^ (a12 & c22);
    a03 ^= (~a13 & a23) ^ (a13 & b23) ^ (b13 & a23);
    b03 ^= (~b13 & b23) ^ (b13 & c23) ^ (c13 & b23);
    c03 ^= (~c13 & c23) ^ (c13 & a23) ^ (a13 & c23);
    a10 ^= (~a20 & a00) ^ (a20 & b00) ^ (b20 & a00);
    b10 ^= (~b20 & b00) ^ (b20 & c00) ^ (c20 & b00);
    c10 ^= (~c20 & c00) ^ (c20 & a00) ^ (a20 & c00);
    a11 ^= (~a21 & a01) ^ (a21 & b01) ^ (b21 & a01);
    b11 ^= (~b21 & b01) ^ (b21 & c01) ^ (c21 & b01);
    c11 ^= (~c21 & c01) ^ (c21 & a01) ^ (a21 & c01);
    a12 ^= (~a22 & a02) ^ (a22 & b02) ^ (b22 & a02);
    b12 ^= (~b22 & b02) ^ (b22 & c02) ^ (c22 & b02);
    c12 ^= (~c22 & c02) ^ (c22 & a02) ^ (a22 & c02);
    a13 ^= (~a23 & a03) ^ (a23 & b03) ^ (b23 & a03);
    b13 ^= (~b23 & b03) ^ (b23 & c03) ^ (c23 & b03);
    c13 ^= (~c23 & c03) ^ (c23 & a03) ^ (a23 & c03);
    a20 ^= (~a00 & a10) ^ (a00 & b10) ^ (b00 & a10);
    b20 ^= (~b00 & b10) ^ (b00 & c10) ^ (c00 & b10);
    c20 ^= (~c00 & c10) ^ (c00 & a10) ^ (a00 & c10);
    a21 ^= (~a01 & a11) ^ (a01 & b11) ^ (b01 & a11);
    b21 ^= (~b01 & b11) ^ (b01 & c11) ^ (c01 & b11);
    c21 ^= (~c01 & c11) ^ (c01 & a11) ^ (a01 & c11);
    a22 ^= (~a02 & a12) ^ (a02 & b12) ^ (b02 & a12);
    b22 ^= (~b02 & b12) ^ (b02 & c12) ^ (c02 & b12);
    c22 ^= (~c02 & c12) ^ (c02 & a12) ^ (a02 & c12);
    a23 ^= (~a03 & a13) ^ (a03 & b13) ^ (b03 & a13);
    b23 ^= (~b03 & b13) ^ (b03 & c13) ^ (c03 & b13);
    c23 ^= (~c03 & c13) ^ (c03 & a13) ^ (a03 & c13);
    ;
    ;
    a10 = ((((uint32_t)a10) << ((1) % 32)) ^
           (((uint32_t)a10) >> ((32 - (1)) % 32)));
    a11 = ((((uint32_t)a11) << ((1) % 32)) ^
           (((uint32_t)a11) >> ((32 - (1)) % 32)));
    a12 = ((((uint32_t)a12) << ((1) % 32)) ^
           (((uint32_t)a12) >> ((32 - (1)) % 32)));
    a13 = ((((uint32_t)a13) << ((1) % 32)) ^
           (((uint32_t)a13) >> ((32 - (1)) % 32)));
    va1 = ((((uint32_t)a23) << ((8) % 32)) ^
           (((uint32_t)a23) >> ((32 - (8)) % 32)));
    a23 = ((((uint32_t)a21) << ((8) % 32)) ^
           (((uint32_t)a21) >> ((32 - (8)) % 32)));
    a21 = va1;
    va1 = ((((uint32_t)a22) << ((8) % 32)) ^
           (((uint32_t)a22) >> ((32 - (8)) % 32)));
    a22 = ((((uint32_t)a20) << ((8) % 32)) ^
           (((uint32_t)a20) >> ((32 - (8)) % 32)));
    a20 = va1;
    b10 = ((((uint32_t)b10) << ((1) % 32)) ^
           (((uint32_t)b10) >> ((32 - (1)) % 32)));
    b11 = ((((uint32_t)b11) << ((1) % 32)) ^
           (((uint32_t)b11) >> ((32 - (1)) % 32)));
    b12 = ((((uint32_t)b12) << ((1) % 32)) ^
           (((uint32_t)b12) >> ((32 - (1)) % 32)));
    b13 = ((((uint32_t)b13) << ((1) % 32)) ^
           (((uint32_t)b13) >> ((32 - (1)) % 32)));
    vb1 = ((((uint32_t)b23) << ((8) % 32)) ^
           (((uint32_t)b23) >> ((32 - (8)) % 32)));
    b23 = ((((uint32_t)b21) << ((8) % 32)) ^
           (((uint32_t)b21) >> ((32 - (8)) % 32)));
    b21 = vb1;
    vb1 = ((((uint32_t)b22) << ((8) % 32)) ^
           (((uint32_t)b22) >> ((32 - (8)) % 32)));
    b22 = ((((uint32_t)b20) << ((8) % 32)) ^
           (((uint32_t)b20) >> ((32 - (8)) % 32)));
    b20 = vb1;
    c10 = ((((uint32_t)c10) << ((1) % 32)) ^
           (((uint32_t)c10) >> ((32 - (1)) % 32)));
    c11 = ((((uint32_t)c11) << ((1) % 32)) ^
           (((uint32_t)c11) >> ((32 - (1)) % 32)));
    c12 = ((((uint32_t)c12) << ((1) % 32)) ^
           (((uint32_t)c12) >> ((32 - (1)) % 32)));
    c13 = ((((uint32_t)c13) << ((1) % 32)) ^
           (((uint32_t)c13) >> ((32 - (1)) % 32)));
    vc1 = ((((uint32_t)c23) << ((8) % 32)) ^
           (((uint32_t)c23) >> ((32 - (8)) % 32)));
    c23 = ((((uint32_t)c21) << ((8) % 32)) ^
           (((uint32_t)c21) >> ((32 - (8)) % 32)));
    c21 = vc1;
    vc1 = ((((uint32_t)c22) << ((8) % 32)) ^
           (((uint32_t)c22) >> ((32 - (8)) % 32)));
    c22 = ((((uint32_t)c20) << ((8) % 32)) ^
           (((uint32_t)c20) >> ((32 - (8)) % 32)));
    c20 = vc1;
    ;
    va1 = a03 ^ a13 ^ a23;
    va2 = a00 ^ a10 ^ a20;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a00 ^= va1;
    a10 ^= va1;
    a20 ^= va1;
    va1 = a01 ^ a11 ^ a21;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a01 ^= va2;
    a11 ^= va2;
    a21 ^= va2;
    va2 = a02 ^ a12 ^ a22;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a02 ^= va1;
    a12 ^= va1;
    a22 ^= va1;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a03 ^= va2;
    a13 ^= va2;
    a23 ^= va2;
    vb1 = b03 ^ b13 ^ b23;
    vb2 = b00 ^ b10 ^ b20;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b00 ^= vb1;
    b10 ^= vb1;
    b20 ^= vb1;
    vb1 = b01 ^ b11 ^ b21;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b01 ^= vb2;
    b11 ^= vb2;
    b21 ^= vb2;
    vb2 = b02 ^ b12 ^ b22;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b02 ^= vb1;
    b12 ^= vb1;
    b22 ^= vb1;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b03 ^= vb2;
    b13 ^= vb2;
    b23 ^= vb2;
    vc1 = c03 ^ c13 ^ c23;
    vc2 = c00 ^ c10 ^ c20;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c00 ^= vc1;
    c10 ^= vc1;
    c20 ^= vc1;
    vc1 = c01 ^ c11 ^ c21;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c01 ^= vc2;
    c11 ^= vc2;
    c21 ^= vc2;
    vc2 = c02 ^ c12 ^ c22;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c02 ^= vc1;
    c12 ^= vc1;
    c22 ^= vc1;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c03 ^= vc2;
    c13 ^= vc2;
    c23 ^= vc2;
    ;
    a20 = ((((uint32_t)a20) << ((11) % 32)) ^
           (((uint32_t)a20) >> ((32 - (11)) % 32)));
    a21 = ((((uint32_t)a21) << ((11) % 32)) ^
           (((uint32_t)a21) >> ((32 - (11)) % 32)));
    a22 = ((((uint32_t)a22) << ((11) % 32)) ^
           (((uint32_t)a22) >> ((32 - (11)) % 32)));
    a23 = ((((uint32_t)a23) << ((11) % 32)) ^
           (((uint32_t)a23) >> ((32 - (11)) % 32)));
    va1 = a13;
    a13 = a12;
    a12 = a11;
    a11 = a10;
    a10 = va1;
    b20 = ((((uint32_t)b20) << ((11) % 32)) ^
           (((uint32_t)b20) >> ((32 - (11)) % 32)));
    b21 = ((((uint32_t)b21) << ((11) % 32)) ^
           (((uint32_t)b21) >> ((32 - (11)) % 32)));
    b22 = ((((uint32_t)b22) << ((11) % 32)) ^
           (((uint32_t)b22) >> ((32 - (11)) % 32)));
    b23 = ((((uint32_t)b23) << ((11) % 32)) ^
           (((uint32_t)b23) >> ((32 - (11)) % 32)));
    vb1 = b13;
    b13 = b12;
    b12 = b11;
    b11 = b10;
    b10 = vb1;
    c20 = ((((uint32_t)c20) << ((11) % 32)) ^
           (((uint32_t)c20) >> ((32 - (11)) % 32)));
    c21 = ((((uint32_t)c21) << ((11) % 32)) ^
           (((uint32_t)c21) >> ((32 - (11)) % 32)));
    c22 = ((((uint32_t)c22) << ((11) % 32)) ^
           (((uint32_t)c22) >> ((32 - (11)) % 32)));
    c23 = ((((uint32_t)c23) << ((11) % 32)) ^
           (((uint32_t)c23) >> ((32 - (11)) % 32)));
    vc1 = c13;
    c13 = c12;
    c12 = c11;
    c11 = c10;
    c10 = vc1;
    ;
    a00 ^= 0x00000060;
    ;
    a00 ^= (~a10 & a20) ^ (a10 & b20) ^ (b10 & a20);
    b00 ^= (~b10 & b20) ^ (b10 & c20) ^ (c10 & b20);
    c00 ^= (~c10 & c20) ^ (c10 & a20) ^ (a10 & c20);
    a01 ^= (~a11 & a21) ^ (a11 & b21) ^ (b11 & a21);
    b01 ^= (~b11 & b21) ^ (b11 & c21) ^ (c11 & b21);
    c01 ^= (~c11 & c21) ^ (c11 & a21) ^ (a11 & c21);
    a02 ^= (~a12 & a22) ^ (a12 & b22) ^ (b12 & a22);
    b02 ^= (~b12 & b22) ^ (b12 & c22) ^ (c12 & b22);
    c02 ^= (~c12 & c22) ^ (c12 & a22) ^ (a12 & c22);
    a03 ^= (~a13 & a23) ^ (a13 & b23) ^ (b13 & a23);
    b03 ^= (~b13 & b23) ^ (b13 & c23) ^ (c13 & b23);
    c03 ^= (~c13 & c23) ^ (c13 & a23) ^ (a13 & c23);
    a10 ^= (~a20 & a00) ^ (a20 & b00) ^ (b20 & a00);
    b10 ^= (~b20 & b00) ^ (b20 & c00) ^ (c20 & b00);
    c10 ^= (~c20 & c00) ^ (c20 & a00) ^ (a20 & c00);
    a11 ^= (~a21 & a01) ^ (a21 & b01) ^ (b21 & a01);
    b11 ^= (~b21 & b01) ^ (b21 & c01) ^ (c21 & b01);
    c11 ^= (~c21 & c01) ^ (c21 & a01) ^ (a21 & c01);
    a12 ^= (~a22 & a02) ^ (a22 & b02) ^ (b22 & a02);
    b12 ^= (~b22 & b02) ^ (b22 & c02) ^ (c22 & b02);
    c12 ^= (~c22 & c02) ^ (c22 & a02) ^ (a22 & c02);
    a13 ^= (~a23 & a03) ^ (a23 & b03) ^ (b23 & a03);
    b13 ^= (~b23 & b03) ^ (b23 & c03) ^ (c23 & b03);
    c13 ^= (~c23 & c03) ^ (c23 & a03) ^ (a23 & c03);
    a20 ^= (~a00 & a10) ^ (a00 & b10) ^ (b00 & a10);
    b20 ^= (~b00 & b10) ^ (b00 & c10) ^ (c00 & b10);
    c20 ^= (~c00 & c10) ^ (c00 & a10) ^ (a00 & c10);
    a21 ^= (~a01 & a11) ^ (a01 & b11) ^ (b01 & a11);
    b21 ^= (~b01 & b11) ^ (b01 & c11) ^ (c01 & b11);
    c21 ^= (~c01 & c11) ^ (c01 & a11) ^ (a01 & c11);
    a22 ^= (~a02 & a12) ^ (a02 & b12) ^ (b02 & a12);
    b22 ^= (~b02 & b12) ^ (b02 & c12) ^ (c02 & b12);
    c22 ^= (~c02 & c12) ^ (c02 & a12) ^ (a02 & c12);
    a23 ^= (~a03 & a13) ^ (a03 & b13) ^ (b03 & a13);
    b23 ^= (~b03 & b13) ^ (b03 & c13) ^ (c03 & b13);
    c23 ^= (~c03 & c13) ^ (c03 & a13) ^ (a03 & c13);
    ;
    ;
    a10 = ((((uint32_t)a10) << ((1) % 32)) ^
           (((uint32_t)a10) >> ((32 - (1)) % 32)));
    a11 = ((((uint32_t)a11) << ((1) % 32)) ^
           (((uint32_t)a11) >> ((32 - (1)) % 32)));
    a12 = ((((uint32_t)a12) << ((1) % 32)) ^
           (((uint32_t)a12) >> ((32 - (1)) % 32)));
    a13 = ((((uint32_t)a13) << ((1) % 32)) ^
           (((uint32_t)a13) >> ((32 - (1)) % 32)));
    va1 = ((((uint32_t)a23) << ((8) % 32)) ^
           (((uint32_t)a23) >> ((32 - (8)) % 32)));
    a23 = ((((uint32_t)a21) << ((8) % 32)) ^
           (((uint32_t)a21) >> ((32 - (8)) % 32)));
    a21 = va1;
    va1 = ((((uint32_t)a22) << ((8) % 32)) ^
           (((uint32_t)a22) >> ((32 - (8)) % 32)));
    a22 = ((((uint32_t)a20) << ((8) % 32)) ^
           (((uint32_t)a20) >> ((32 - (8)) % 32)));
    a20 = va1;
    b10 = ((((uint32_t)b10) << ((1) % 32)) ^
           (((uint32_t)b10) >> ((32 - (1)) % 32)));
    b11 = ((((uint32_t)b11) << ((1) % 32)) ^
           (((uint32_t)b11) >> ((32 - (1)) % 32)));
    b12 = ((((uint32_t)b12) << ((1) % 32)) ^
           (((uint32_t)b12) >> ((32 - (1)) % 32)));
    b13 = ((((uint32_t)b13) << ((1) % 32)) ^
           (((uint32_t)b13) >> ((32 - (1)) % 32)));
    vb1 = ((((uint32_t)b23) << ((8) % 32)) ^
           (((uint32_t)b23) >> ((32 - (8)) % 32)));
    b23 = ((((uint32_t)b21) << ((8) % 32)) ^
           (((uint32_t)b21) >> ((32 - (8)) % 32)));
    b21 = vb1;
    vb1 = ((((uint32_t)b22) << ((8) % 32)) ^
           (((uint32_t)b22) >> ((32 - (8)) % 32)));
    b22 = ((((uint32_t)b20) << ((8) % 32)) ^
           (((uint32_t)b20) >> ((32 - (8)) % 32)));
    b20 = vb1;
    c10 = ((((uint32_t)c10) << ((1) % 32)) ^
           (((uint32_t)c10) >> ((32 - (1)) % 32)));
    c11 = ((((uint32_t)c11) << ((1) % 32)) ^
           (((uint32_t)c11) >> ((32 - (1)) % 32)));
    c12 = ((((uint32_t)c12) << ((1) % 32)) ^
           (((uint32_t)c12) >> ((32 - (1)) % 32)));
    c13 = ((((uint32_t)c13) << ((1) % 32)) ^
           (((uint32_t)c13) >> ((32 - (1)) % 32)));
    vc1 = ((((uint32_t)c23) << ((8) % 32)) ^
           (((uint32_t)c23) >> ((32 - (8)) % 32)));
    c23 = ((((uint32_t)c21) << ((8) % 32)) ^
           (((uint32_t)c21) >> ((32 - (8)) % 32)));
    c21 = vc1;
    vc1 = ((((uint32_t)c22) << ((8) % 32)) ^
           (((uint32_t)c22) >> ((32 - (8)) % 32)));
    c22 = ((((uint32_t)c20) << ((8) % 32)) ^
           (((uint32_t)c20) >> ((32 - (8)) % 32)));
    c20 = vc1;
    ;
    va1 = a03 ^ a13 ^ a23;
    va2 = a00 ^ a10 ^ a20;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a00 ^= va1;
    a10 ^= va1;
    a20 ^= va1;
    va1 = a01 ^ a11 ^ a21;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a01 ^= va2;
    a11 ^= va2;
    a21 ^= va2;
    va2 = a02 ^ a12 ^ a22;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a02 ^= va1;
    a12 ^= va1;
    a22 ^= va1;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a03 ^= va2;
    a13 ^= va2;
    a23 ^= va2;
    vb1 = b03 ^ b13 ^ b23;
    vb2 = b00 ^ b10 ^ b20;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b00 ^= vb1;
    b10 ^= vb1;
    b20 ^= vb1;
    vb1 = b01 ^ b11 ^ b21;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b01 ^= vb2;
    b11 ^= vb2;
    b21 ^= vb2;
    vb2 = b02 ^ b12 ^ b22;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b02 ^= vb1;
    b12 ^= vb1;
    b22 ^= vb1;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b03 ^= vb2;
    b13 ^= vb2;
    b23 ^= vb2;
    vc1 = c03 ^ c13 ^ c23;
    vc2 = c00 ^ c10 ^ c20;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c00 ^= vc1;
    c10 ^= vc1;
    c20 ^= vc1;
    vc1 = c01 ^ c11 ^ c21;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c01 ^= vc2;
    c11 ^= vc2;
    c21 ^= vc2;
    vc2 = c02 ^ c12 ^ c22;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c02 ^= vc1;
    c12 ^= vc1;
    c22 ^= vc1;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c03 ^= vc2;
    c13 ^= vc2;
    c23 ^= vc2;
    ;
    a20 = ((((uint32_t)a20) << ((11) % 32)) ^
           (((uint32_t)a20) >> ((32 - (11)) % 32)));
    a21 = ((((uint32_t)a21) << ((11) % 32)) ^
           (((uint32_t)a21) >> ((32 - (11)) % 32)));
    a22 = ((((uint32_t)a22) << ((11) % 32)) ^
           (((uint32_t)a22) >> ((32 - (11)) % 32)));
    a23 = ((((uint32_t)a23) << ((11) % 32)) ^
           (((uint32_t)a23) >> ((32 - (11)) % 32)));
    va1 = a13;
    a13 = a12;
    a12 = a11;
    a11 = a10;
    a10 = va1;
    b20 = ((((uint32_t)b20) << ((11) % 32)) ^
           (((uint32_t)b20) >> ((32 - (11)) % 32)));
    b21 = ((((uint32_t)b21) << ((11) % 32)) ^
           (((uint32_t)b21) >> ((32 - (11)) % 32)));
    b22 = ((((uint32_t)b22) << ((11) % 32)) ^
           (((uint32_t)b22) >> ((32 - (11)) % 32)));
    b23 = ((((uint32_t)b23) << ((11) % 32)) ^
           (((uint32_t)b23) >> ((32 - (11)) % 32)));
    vb1 = b13;
    b13 = b12;
    b12 = b11;
    b11 = b10;
    b10 = vb1;
    c20 = ((((uint32_t)c20) << ((11) % 32)) ^
           (((uint32_t)c20) >> ((32 - (11)) % 32)));
    c21 = ((((uint32_t)c21) << ((11) % 32)) ^
           (((uint32_t)c21) >> ((32 - (11)) % 32)));
    c22 = ((((uint32_t)c22) << ((11) % 32)) ^
           (((uint32_t)c22) >> ((32 - (11)) % 32)));
    c23 = ((((uint32_t)c23) << ((11) % 32)) ^
           (((uint32_t)c23) >> ((32 - (11)) % 32)));
    vc1 = c13;
    c13 = c12;
    c12 = c11;
    c11 = c10;
    c10 = vc1;
    ;
    a00 ^= 0x0000002C;
    ;
    a00 ^= (~a10 & a20) ^ (a10 & b20) ^ (b10 & a20);
    b00 ^= (~b10 & b20) ^ (b10 & c20) ^ (c10 & b20);
    c00 ^= (~c10 & c20) ^ (c10 & a20) ^ (a10 & c20);
    a01 ^= (~a11 & a21) ^ (a11 & b21) ^ (b11 & a21);
    b01 ^= (~b11 & b21) ^ (b11 & c21) ^ (c11 & b21);
    c01 ^= (~c11 & c21) ^ (c11 & a21) ^ (a11 & c21);
    a02 ^= (~a12 & a22) ^ (a12 & b22) ^ (b12 & a22);
    b02 ^= (~b12 & b22) ^ (b12 & c22) ^ (c12 & b22);
    c02 ^= (~c12 & c22) ^ (c12 & a22) ^ (a12 & c22);
    a03 ^= (~a13 & a23) ^ (a13 & b23) ^ (b13 & a23);
    b03 ^= (~b13 & b23) ^ (b13 & c23) ^ (c13 & b23);
    c03 ^= (~c13 & c23) ^ (c13 & a23) ^ (a13 & c23);
    a10 ^= (~a20 & a00) ^ (a20 & b00) ^ (b20 & a00);
    b10 ^= (~b20 & b00) ^ (b20 & c00) ^ (c20 & b00);
    c10 ^= (~c20 & c00) ^ (c20 & a00) ^ (a20 & c00);
    a11 ^= (~a21 & a01) ^ (a21 & b01) ^ (b21 & a01);
    b11 ^= (~b21 & b01) ^ (b21 & c01) ^ (c21 & b01);
    c11 ^= (~c21 & c01) ^ (c21 & a01) ^ (a21 & c01);
    a12 ^= (~a22 & a02) ^ (a22 & b02) ^ (b22 & a02);
    b12 ^= (~b22 & b02) ^ (b22 & c02) ^ (c22 & b02);
    c12 ^= (~c22 & c02) ^ (c22 & a02) ^ (a22 & c02);
    a13 ^= (~a23 & a03) ^ (a23 & b03) ^ (b23 & a03);
    b13 ^= (~b23 & b03) ^ (b23 & c03) ^ (c23 & b03);
    c13 ^= (~c23 & c03) ^ (c23 & a03) ^ (a23 & c03);
    a20 ^= (~a00 & a10) ^ (a00 & b10) ^ (b00 & a10);
    b20 ^= (~b00 & b10) ^ (b00 & c10) ^ (c00 & b10);
    c20 ^= (~c00 & c10) ^ (c00 & a10) ^ (a00 & c10);
    a21 ^= (~a01 & a11) ^ (a01 & b11) ^ (b01 & a11);
    b21 ^= (~b01 & b11) ^ (b01 & c11) ^ (c01 & b11);
    c21 ^= (~c01 & c11) ^ (c01 & a11) ^ (a01 & c11);
    a22 ^= (~a02 & a12) ^ (a02 & b12) ^ (b02 & a12);
    b22 ^= (~b02 & b12) ^ (b02 & c12) ^ (c02 & b12);
    c22 ^= (~c02 & c12) ^ (c02 & a12) ^ (a02 & c12);
    a23 ^= (~a03 & a13) ^ (a03 & b13) ^ (b03 & a13);
    b23 ^= (~b03 & b13) ^ (b03 & c13) ^ (c03 & b13);
    c23 ^= (~c03 & c13) ^ (c03 & a13) ^ (a03 & c13);
    ;
    ;
    a10 = ((((uint32_t)a10) << ((1) % 32)) ^
           (((uint32_t)a10) >> ((32 - (1)) % 32)));
    a11 = ((((uint32_t)a11) << ((1) % 32)) ^
           (((uint32_t)a11) >> ((32 - (1)) % 32)));
    a12 = ((((uint32_t)a12) << ((1) % 32)) ^
           (((uint32_t)a12) >> ((32 - (1)) % 32)));
    a13 = ((((uint32_t)a13) << ((1) % 32)) ^
           (((uint32_t)a13) >> ((32 - (1)) % 32)));
    va1 = ((((uint32_t)a23) << ((8) % 32)) ^
           (((uint32_t)a23) >> ((32 - (8)) % 32)));
    a23 = ((((uint32_t)a21) << ((8) % 32)) ^
           (((uint32_t)a21) >> ((32 - (8)) % 32)));
    a21 = va1;
    va1 = ((((uint32_t)a22) << ((8) % 32)) ^
           (((uint32_t)a22) >> ((32 - (8)) % 32)));
    a22 = ((((uint32_t)a20) << ((8) % 32)) ^
           (((uint32_t)a20) >> ((32 - (8)) % 32)));
    a20 = va1;
    b10 = ((((uint32_t)b10) << ((1) % 32)) ^
           (((uint32_t)b10) >> ((32 - (1)) % 32)));
    b11 = ((((uint32_t)b11) << ((1) % 32)) ^
           (((uint32_t)b11) >> ((32 - (1)) % 32)));
    b12 = ((((uint32_t)b12) << ((1) % 32)) ^
           (((uint32_t)b12) >> ((32 - (1)) % 32)));
    b13 = ((((uint32_t)b13) << ((1) % 32)) ^
           (((uint32_t)b13) >> ((32 - (1)) % 32)));
    vb1 = ((((uint32_t)b23) << ((8) % 32)) ^
           (((uint32_t)b23) >> ((32 - (8)) % 32)));
    b23 = ((((uint32_t)b21) << ((8) % 32)) ^
           (((uint32_t)b21) >> ((32 - (8)) % 32)));
    b21 = vb1;
    vb1 = ((((uint32_t)b22) << ((8) % 32)) ^
           (((uint32_t)b22) >> ((32 - (8)) % 32)));
    b22 = ((((uint32_t)b20) << ((8) % 32)) ^
           (((uint32_t)b20) >> ((32 - (8)) % 32)));
    b20 = vb1;
    c10 = ((((uint32_t)c10) << ((1) % 32)) ^
           (((uint32_t)c10) >> ((32 - (1)) % 32)));
    c11 = ((((uint32_t)c11) << ((1) % 32)) ^
           (((uint32_t)c11) >> ((32 - (1)) % 32)));
    c12 = ((((uint32_t)c12) << ((1) % 32)) ^
           (((uint32_t)c12) >> ((32 - (1)) % 32)));
    c13 = ((((uint32_t)c13) << ((1) % 32)) ^
           (((uint32_t)c13) >> ((32 - (1)) % 32)));
    vc1 = ((((uint32_t)c23) << ((8) % 32)) ^
           (((uint32_t)c23) >> ((32 - (8)) % 32)));
    c23 = ((((uint32_t)c21) << ((8) % 32)) ^
           (((uint32_t)c21) >> ((32 - (8)) % 32)));
    c21 = vc1;
    vc1 = ((((uint32_t)c22) << ((8) % 32)) ^
           (((uint32_t)c22) >> ((32 - (8)) % 32)));
    c22 = ((((uint32_t)c20) << ((8) % 32)) ^
           (((uint32_t)c20) >> ((32 - (8)) % 32)));
    c20 = vc1;
    ;
    va1 = a03 ^ a13 ^ a23;
    va2 = a00 ^ a10 ^ a20;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a00 ^= va1;
    a10 ^= va1;
    a20 ^= va1;
    va1 = a01 ^ a11 ^ a21;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a01 ^= va2;
    a11 ^= va2;
    a21 ^= va2;
    va2 = a02 ^ a12 ^ a22;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a02 ^= va1;
    a12 ^= va1;
    a22 ^= va1;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a03 ^= va2;
    a13 ^= va2;
    a23 ^= va2;
    vb1 = b03 ^ b13 ^ b23;
    vb2 = b00 ^ b10 ^ b20;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b00 ^= vb1;
    b10 ^= vb1;
    b20 ^= vb1;
    vb1 = b01 ^ b11 ^ b21;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b01 ^= vb2;
    b11 ^= vb2;
    b21 ^= vb2;
    vb2 = b02 ^ b12 ^ b22;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b02 ^= vb1;
    b12 ^= vb1;
    b22 ^= vb1;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b03 ^= vb2;
    b13 ^= vb2;
    b23 ^= vb2;
    vc1 = c03 ^ c13 ^ c23;
    vc2 = c00 ^ c10 ^ c20;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c00 ^= vc1;
    c10 ^= vc1;
    c20 ^= vc1;
    vc1 = c01 ^ c11 ^ c21;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c01 ^= vc2;
    c11 ^= vc2;
    c21 ^= vc2;
    vc2 = c02 ^ c12 ^ c22;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c02 ^= vc1;
    c12 ^= vc1;
    c22 ^= vc1;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c03 ^= vc2;
    c13 ^= vc2;
    c23 ^= vc2;
    ;
    a20 = ((((uint32_t)a20) << ((11) % 32)) ^
           (((uint32_t)a20) >> ((32 - (11)) % 32)));
    a21 = ((((uint32_t)a21) << ((11) % 32)) ^
           (((uint32_t)a21) >> ((32 - (11)) % 32)));
    a22 = ((((uint32_t)a22) << ((11) % 32)) ^
           (((uint32_t)a22) >> ((32 - (11)) % 32)));
    a23 = ((((uint32_t)a23) << ((11) % 32)) ^
           (((uint32_t)a23) >> ((32 - (11)) % 32)));
    va1 = a13;
    a13 = a12;
    a12 = a11;
    a11 = a10;
    a10 = va1;
    b20 = ((((uint32_t)b20) << ((11) % 32)) ^
           (((uint32_t)b20) >> ((32 - (11)) % 32)));
    b21 = ((((uint32_t)b21) << ((11) % 32)) ^
           (((uint32_t)b21) >> ((32 - (11)) % 32)));
    b22 = ((((uint32_t)b22) << ((11) % 32)) ^
           (((uint32_t)b22) >> ((32 - (11)) % 32)));
    b23 = ((((uint32_t)b23) << ((11) % 32)) ^
           (((uint32_t)b23) >> ((32 - (11)) % 32)));
    vb1 = b13;
    b13 = b12;
    b12 = b11;
    b11 = b10;
    b10 = vb1;
    c20 = ((((uint32_t)c20) << ((11) % 32)) ^
           (((uint32_t)c20) >> ((32 - (11)) % 32)));
    c21 = ((((uint32_t)c21) << ((11) % 32)) ^
           (((uint32_t)c21) >> ((32 - (11)) % 32)));
    c22 = ((((uint32_t)c22) << ((11) % 32)) ^
           (((uint32_t)c22) >> ((32 - (11)) % 32)));
    c23 = ((((uint32_t)c23) << ((11) % 32)) ^
           (((uint32_t)c23) >> ((32 - (11)) % 32)));
    vc1 = c13;
    c13 = c12;
    c12 = c11;
    c11 = c10;
    c10 = vc1;
    ;
    a00 ^= 0x00000380;
    ;
    a00 ^= (~a10 & a20) ^ (a10 & b20) ^ (b10 & a20);
    b00 ^= (~b10 & b20) ^ (b10 & c20) ^ (c10 & b20);
    c00 ^= (~c10 & c20) ^ (c10 & a20) ^ (a10 & c20);
    a01 ^= (~a11 & a21) ^ (a11 & b21) ^ (b11 & a21);
    b01 ^= (~b11 & b21) ^ (b11 & c21) ^ (c11 & b21);
    c01 ^= (~c11 & c21) ^ (c11 & a21) ^ (a11 & c21);
    a02 ^= (~a12 & a22) ^ (a12 & b22) ^ (b12 & a22);
    b02 ^= (~b12 & b22) ^ (b12 & c22) ^ (c12 & b22);
    c02 ^= (~c12 & c22) ^ (c12 & a22) ^ (a12 & c22);
    a03 ^= (~a13 & a23) ^ (a13 & b23) ^ (b13 & a23);
    b03 ^= (~b13 & b23) ^ (b13 & c23) ^ (c13 & b23);
    c03 ^= (~c13 & c23) ^ (c13 & a23) ^ (a13 & c23);
    a10 ^= (~a20 & a00) ^ (a20 & b00) ^ (b20 & a00);
    b10 ^= (~b20 & b00) ^ (b20 & c00) ^ (c20 & b00);
    c10 ^= (~c20 & c00) ^ (c20 & a00) ^ (a20 & c00);
    a11 ^= (~a21 & a01) ^ (a21 & b01) ^ (b21 & a01);
    b11 ^= (~b21 & b01) ^ (b21 & c01) ^ (c21 & b01);
    c11 ^= (~c21 & c01) ^ (c21 & a01) ^ (a21 & c01);
    a12 ^= (~a22 & a02) ^ (a22 & b02) ^ (b22 & a02);
    b12 ^= (~b22 & b02) ^ (b22 & c02) ^ (c22 & b02);
    c12 ^= (~c22 & c02) ^ (c22 & a02) ^ (a22 & c02);
    a13 ^= (~a23 & a03) ^ (a23 & b03) ^ (b23 & a03);
    b13 ^= (~b23 & b03) ^ (b23 & c03) ^ (c23 & b03);
    c13 ^= (~c23 & c03) ^ (c23 & a03) ^ (a23 & c03);
    a20 ^= (~a00 & a10) ^ (a00 & b10) ^ (b00 & a10);
    b20 ^= (~b00 & b10) ^ (b00 & c10) ^ (c00 & b10);
    c20 ^= (~c00 & c10) ^ (c00 & a10) ^ (a00 & c10);
    a21 ^= (~a01 & a11) ^ (a01 & b11) ^ (b01 & a11);
    b21 ^= (~b01 & b11) ^ (b01 & c11) ^ (c01 & b11);
    c21 ^= (~c01 & c11) ^ (c01 & a11) ^ (a01 & c11);
    a22 ^= (~a02 & a12) ^ (a02 & b12) ^ (b02 & a12);
    b22 ^= (~b02 & b12) ^ (b02 & c12) ^ (c02 & b12);
    c22 ^= (~c02 & c12) ^ (c02 & a12) ^ (a02 & c12);
    a23 ^= (~a03 & a13) ^ (a03 & b13) ^ (b03 & a13);
    b23 ^= (~b03 & b13) ^ (b03 & c13) ^ (c03 & b13);
    c23 ^= (~c03 & c13) ^ (c03 & a13) ^ (a03 & c13);
    ;
    ;
    a10 = ((((uint32_t)a10) << ((1) % 32)) ^
           (((uint32_t)a10) >> ((32 - (1)) % 32)));
    a11 = ((((uint32_t)a11) << ((1) % 32)) ^
           (((uint32_t)a11) >> ((32 - (1)) % 32)));
    a12 = ((((uint32_t)a12) << ((1) % 32)) ^
           (((uint32_t)a12) >> ((32 - (1)) % 32)));
    a13 = ((((uint32_t)a13) << ((1) % 32)) ^
           (((uint32_t)a13) >> ((32 - (1)) % 32)));
    va1 = ((((uint32_t)a23) << ((8) % 32)) ^
           (((uint32_t)a23) >> ((32 - (8)) % 32)));
    a23 = ((((uint32_t)a21) << ((8) % 32)) ^
           (((uint32_t)a21) >> ((32 - (8)) % 32)));
    a21 = va1;
    va1 = ((((uint32_t)a22) << ((8) % 32)) ^
           (((uint32_t)a22) >> ((32 - (8)) % 32)));
    a22 = ((((uint32_t)a20) << ((8) % 32)) ^
           (((uint32_t)a20) >> ((32 - (8)) % 32)));
    a20 = va1;
    b10 = ((((uint32_t)b10) << ((1) % 32)) ^
           (((uint32_t)b10) >> ((32 - (1)) % 32)));
    b11 = ((((uint32_t)b11) << ((1) % 32)) ^
           (((uint32_t)b11) >> ((32 - (1)) % 32)));
    b12 = ((((uint32_t)b12) << ((1) % 32)) ^
           (((uint32_t)b12) >> ((32 - (1)) % 32)));
    b13 = ((((uint32_t)b13) << ((1) % 32)) ^
           (((uint32_t)b13) >> ((32 - (1)) % 32)));
    vb1 = ((((uint32_t)b23) << ((8) % 32)) ^
           (((uint32_t)b23) >> ((32 - (8)) % 32)));
    b23 = ((((uint32_t)b21) << ((8) % 32)) ^
           (((uint32_t)b21) >> ((32 - (8)) % 32)));
    b21 = vb1;
    vb1 = ((((uint32_t)b22) << ((8) % 32)) ^
           (((uint32_t)b22) >> ((32 - (8)) % 32)));
    b22 = ((((uint32_t)b20) << ((8) % 32)) ^
           (((uint32_t)b20) >> ((32 - (8)) % 32)));
    b20 = vb1;
    c10 = ((((uint32_t)c10) << ((1) % 32)) ^
           (((uint32_t)c10) >> ((32 - (1)) % 32)));
    c11 = ((((uint32_t)c11) << ((1) % 32)) ^
           (((uint32_t)c11) >> ((32 - (1)) % 32)));
    c12 = ((((uint32_t)c12) << ((1) % 32)) ^
           (((uint32_t)c12) >> ((32 - (1)) % 32)));
    c13 = ((((uint32_t)c13) << ((1) % 32)) ^
           (((uint32_t)c13) >> ((32 - (1)) % 32)));
    vc1 = ((((uint32_t)c23) << ((8) % 32)) ^
           (((uint32_t)c23) >> ((32 - (8)) % 32)));
    c23 = ((((uint32_t)c21) << ((8) % 32)) ^
           (((uint32_t)c21) >> ((32 - (8)) % 32)));
    c21 = vc1;
    vc1 = ((((uint32_t)c22) << ((8) % 32)) ^
           (((uint32_t)c22) >> ((32 - (8)) % 32)));
    c22 = ((((uint32_t)c20) << ((8) % 32)) ^
           (((uint32_t)c20) >> ((32 - (8)) % 32)));
    c20 = vc1;
    ;
    va1 = a03 ^ a13 ^ a23;
    va2 = a00 ^ a10 ^ a20;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a00 ^= va1;
    a10 ^= va1;
    a20 ^= va1;
    va1 = a01 ^ a11 ^ a21;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a01 ^= va2;
    a11 ^= va2;
    a21 ^= va2;
    va2 = a02 ^ a12 ^ a22;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a02 ^= va1;
    a12 ^= va1;
    a22 ^= va1;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a03 ^= va2;
    a13 ^= va2;
    a23 ^= va2;
    vb1 = b03 ^ b13 ^ b23;
    vb2 = b00 ^ b10 ^ b20;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b00 ^= vb1;
    b10 ^= vb1;
    b20 ^= vb1;
    vb1 = b01 ^ b11 ^ b21;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b01 ^= vb2;
    b11 ^= vb2;
    b21 ^= vb2;
    vb2 = b02 ^ b12 ^ b22;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b02 ^= vb1;
    b12 ^= vb1;
    b22 ^= vb1;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b03 ^= vb2;
    b13 ^= vb2;
    b23 ^= vb2;
    vc1 = c03 ^ c13 ^ c23;
    vc2 = c00 ^ c10 ^ c20;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c00 ^= vc1;
    c10 ^= vc1;
    c20 ^= vc1;
    vc1 = c01 ^ c11 ^ c21;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c01 ^= vc2;
    c11 ^= vc2;
    c21 ^= vc2;
    vc2 = c02 ^ c12 ^ c22;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c02 ^= vc1;
    c12 ^= vc1;
    c22 ^= vc1;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c03 ^= vc2;
    c13 ^= vc2;
    c23 ^= vc2;
    ;
    a20 = ((((uint32_t)a20) << ((11) % 32)) ^
           (((uint32_t)a20) >> ((32 - (11)) % 32)));
    a21 = ((((uint32_t)a21) << ((11) % 32)) ^
           (((uint32_t)a21) >> ((32 - (11)) % 32)));
    a22 = ((((uint32_t)a22) << ((11) % 32)) ^
           (((uint32_t)a22) >> ((32 - (11)) % 32)));
    a23 = ((((uint32_t)a23) << ((11) % 32)) ^
           (((uint32_t)a23) >> ((32 - (11)) % 32)));
    va1 = a13;
    a13 = a12;
    a12 = a11;
    a11 = a10;
    a10 = va1;
    b20 = ((((uint32_t)b20) << ((11) % 32)) ^
           (((uint32_t)b20) >> ((32 - (11)) % 32)));
    b21 = ((((uint32_t)b21) << ((11) % 32)) ^
           (((uint32_t)b21) >> ((32 - (11)) % 32)));
    b22 = ((((uint32_t)b22) << ((11) % 32)) ^
           (((uint32_t)b22) >> ((32 - (11)) % 32)));
    b23 = ((((uint32_t)b23) << ((11) % 32)) ^
           (((uint32_t)b23) >> ((32 - (11)) % 32)));
    vb1 = b13;
    b13 = b12;
    b12 = b11;
    b11 = b10;
    b10 = vb1;
    c20 = ((((uint32_t)c20) << ((11) % 32)) ^
           (((uint32_t)c20) >> ((32 - (11)) % 32)));
    c21 = ((((uint32_t)c21) << ((11) % 32)) ^
           (((uint32_t)c21) >> ((32 - (11)) % 32)));
    c22 = ((((uint32_t)c22) << ((11) % 32)) ^
           (((uint32_t)c22) >> ((32 - (11)) % 32)));
    c23 = ((((uint32_t)c23) << ((11) % 32)) ^
           (((uint32_t)c23) >> ((32 - (11)) % 32)));
    vc1 = c13;
    c13 = c12;
    c12 = c11;
    c11 = c10;
    c10 = vc1;
    ;
    a00 ^= 0x000000F0;
    ;
    a00 ^= (~a10 & a20) ^ (a10 & b20) ^ (b10 & a20);
    b00 ^= (~b10 & b20) ^ (b10 & c20) ^ (c10 & b20);
    c00 ^= (~c10 & c20) ^ (c10 & a20) ^ (a10 & c20);
    a01 ^= (~a11 & a21) ^ (a11 & b21) ^ (b11 & a21);
    b01 ^= (~b11 & b21) ^ (b11 & c21) ^ (c11 & b21);
    c01 ^= (~c11 & c21) ^ (c11 & a21) ^ (a11 & c21);
    a02 ^= (~a12 & a22) ^ (a12 & b22) ^ (b12 & a22);
    b02 ^= (~b12 & b22) ^ (b12 & c22) ^ (c12 & b22);
    c02 ^= (~c12 & c22) ^ (c12 & a22) ^ (a12 & c22);
    a03 ^= (~a13 & a23) ^ (a13 & b23) ^ (b13 & a23);
    b03 ^= (~b13 & b23) ^ (b13 & c23) ^ (c13 & b23);
    c03 ^= (~c13 & c23) ^ (c13 & a23) ^ (a13 & c23);
    a10 ^= (~a20 & a00) ^ (a20 & b00) ^ (b20 & a00);
    b10 ^= (~b20 & b00) ^ (b20 & c00) ^ (c20 & b00);
    c10 ^= (~c20 & c00) ^ (c20 & a00) ^ (a20 & c00);
    a11 ^= (~a21 & a01) ^ (a21 & b01) ^ (b21 & a01);
    b11 ^= (~b21 & b01) ^ (b21 & c01) ^ (c21 & b01);
    c11 ^= (~c21 & c01) ^ (c21 & a01) ^ (a21 & c01);
    a12 ^= (~a22 & a02) ^ (a22 & b02) ^ (b22 & a02);
    b12 ^= (~b22 & b02) ^ (b22 & c02) ^ (c22 & b02);
    c12 ^= (~c22 & c02) ^ (c22 & a02) ^ (a22 & c02);
    a13 ^= (~a23 & a03) ^ (a23 & b03) ^ (b23 & a03);
    b13 ^= (~b23 & b03) ^ (b23 & c03) ^ (c23 & b03);
    c13 ^= (~c23 & c03) ^ (c23 & a03) ^ (a23 & c03);
    a20 ^= (~a00 & a10) ^ (a00 & b10) ^ (b00 & a10);
    b20 ^= (~b00 & b10) ^ (b00 & c10) ^ (c00 & b10);
    c20 ^= (~c00 & c10) ^ (c00 & a10) ^ (a00 & c10);
    a21 ^= (~a01 & a11) ^ (a01 & b11) ^ (b01 & a11);
    b21 ^= (~b01 & b11) ^ (b01 & c11) ^ (c01 & b11);
    c21 ^= (~c01 & c11) ^ (c01 & a11) ^ (a01 & c11);
    a22 ^= (~a02 & a12) ^ (a02 & b12) ^ (b02 & a12);
    b22 ^= (~b02 & b12) ^ (b02 & c12) ^ (c02 & b12);
    c22 ^= (~c02 & c12) ^ (c02 & a12) ^ (a02 & c12);
    a23 ^= (~a03 & a13) ^ (a03 & b13) ^ (b03 & a13);
    b23 ^= (~b03 & b13) ^ (b03 & c13) ^ (c03 & b13);
    c23 ^= (~c03 & c13) ^ (c03 & a13) ^ (a03 & c13);
    ;
    ;
    a10 = ((((uint32_t)a10) << ((1) % 32)) ^
           (((uint32_t)a10) >> ((32 - (1)) % 32)));
    a11 = ((((uint32_t)a11) << ((1) % 32)) ^
           (((uint32_t)a11) >> ((32 - (1)) % 32)));
    a12 = ((((uint32_t)a12) << ((1) % 32)) ^
           (((uint32_t)a12) >> ((32 - (1)) % 32)));
    a13 = ((((uint32_t)a13) << ((1) % 32)) ^
           (((uint32_t)a13) >> ((32 - (1)) % 32)));
    va1 = ((((uint32_t)a23) << ((8) % 32)) ^
           (((uint32_t)a23) >> ((32 - (8)) % 32)));
    a23 = ((((uint32_t)a21) << ((8) % 32)) ^
           (((uint32_t)a21) >> ((32 - (8)) % 32)));
    a21 = va1;
    va1 = ((((uint32_t)a22) << ((8) % 32)) ^
           (((uint32_t)a22) >> ((32 - (8)) % 32)));
    a22 = ((((uint32_t)a20) << ((8) % 32)) ^
           (((uint32_t)a20) >> ((32 - (8)) % 32)));
    a20 = va1;
    b10 = ((((uint32_t)b10) << ((1) % 32)) ^
           (((uint32_t)b10) >> ((32 - (1)) % 32)));
    b11 = ((((uint32_t)b11) << ((1) % 32)) ^
           (((uint32_t)b11) >> ((32 - (1)) % 32)));
    b12 = ((((uint32_t)b12) << ((1) % 32)) ^
           (((uint32_t)b12) >> ((32 - (1)) % 32)));
    b13 = ((((uint32_t)b13) << ((1) % 32)) ^
           (((uint32_t)b13) >> ((32 - (1)) % 32)));
    vb1 = ((((uint32_t)b23) << ((8) % 32)) ^
           (((uint32_t)b23) >> ((32 - (8)) % 32)));
    b23 = ((((uint32_t)b21) << ((8) % 32)) ^
           (((uint32_t)b21) >> ((32 - (8)) % 32)));
    b21 = vb1;
    vb1 = ((((uint32_t)b22) << ((8) % 32)) ^
           (((uint32_t)b22) >> ((32 - (8)) % 32)));
    b22 = ((((uint32_t)b20) << ((8) % 32)) ^
           (((uint32_t)b20) >> ((32 - (8)) % 32)));
    b20 = vb1;
    c10 = ((((uint32_t)c10) << ((1) % 32)) ^
           (((uint32_t)c10) >> ((32 - (1)) % 32)));
    c11 = ((((uint32_t)c11) << ((1) % 32)) ^
           (((uint32_t)c11) >> ((32 - (1)) % 32)));
    c12 = ((((uint32_t)c12) << ((1) % 32)) ^
           (((uint32_t)c12) >> ((32 - (1)) % 32)));
    c13 = ((((uint32_t)c13) << ((1) % 32)) ^
           (((uint32_t)c13) >> ((32 - (1)) % 32)));
    vc1 = ((((uint32_t)c23) << ((8) % 32)) ^
           (((uint32_t)c23) >> ((32 - (8)) % 32)));
    c23 = ((((uint32_t)c21) << ((8) % 32)) ^
           (((uint32_t)c21) >> ((32 - (8)) % 32)));
    c21 = vc1;
    vc1 = ((((uint32_t)c22) << ((8) % 32)) ^
           (((uint32_t)c22) >> ((32 - (8)) % 32)));
    c22 = ((((uint32_t)c20) << ((8) % 32)) ^
           (((uint32_t)c20) >> ((32 - (8)) % 32)));
    c20 = vc1;
    ;
    va1 = a03 ^ a13 ^ a23;
    va2 = a00 ^ a10 ^ a20;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a00 ^= va1;
    a10 ^= va1;
    a20 ^= va1;
    va1 = a01 ^ a11 ^ a21;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a01 ^= va2;
    a11 ^= va2;
    a21 ^= va2;
    va2 = a02 ^ a12 ^ a22;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a02 ^= va1;
    a12 ^= va1;
    a22 ^= va1;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a03 ^= va2;
    a13 ^= va2;
    a23 ^= va2;
    vb1 = b03 ^ b13 ^ b23;
    vb2 = b00 ^ b10 ^ b20;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b00 ^= vb1;
    b10 ^= vb1;
    b20 ^= vb1;
    vb1 = b01 ^ b11 ^ b21;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b01 ^= vb2;
    b11 ^= vb2;
    b21 ^= vb2;
    vb2 = b02 ^ b12 ^ b22;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b02 ^= vb1;
    b12 ^= vb1;
    b22 ^= vb1;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b03 ^= vb2;
    b13 ^= vb2;
    b23 ^= vb2;
    vc1 = c03 ^ c13 ^ c23;
    vc2 = c00 ^ c10 ^ c20;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c00 ^= vc1;
    c10 ^= vc1;
    c20 ^= vc1;
    vc1 = c01 ^ c11 ^ c21;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c01 ^= vc2;
    c11 ^= vc2;
    c21 ^= vc2;
    vc2 = c02 ^ c12 ^ c22;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c02 ^= vc1;
    c12 ^= vc1;
    c22 ^= vc1;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c03 ^= vc2;
    c13 ^= vc2;
    c23 ^= vc2;
    ;
    a20 = ((((uint32_t)a20) << ((11) % 32)) ^
           (((uint32_t)a20) >> ((32 - (11)) % 32)));
    a21 = ((((uint32_t)a21) << ((11) % 32)) ^
           (((uint32_t)a21) >> ((32 - (11)) % 32)));
    a22 = ((((uint32_t)a22) << ((11) % 32)) ^
           (((uint32_t)a22) >> ((32 - (11)) % 32)));
    a23 = ((((uint32_t)a23) << ((11) % 32)) ^
           (((uint32_t)a23) >> ((32 - (11)) % 32)));
    va1 = a13;
    a13 = a12;
    a12 = a11;
    a11 = a10;
    a10 = va1;
    b20 = ((((uint32_t)b20) << ((11) % 32)) ^
           (((uint32_t)b20) >> ((32 - (11)) % 32)));
    b21 = ((((uint32_t)b21) << ((11) % 32)) ^
           (((uint32_t)b21) >> ((32 - (11)) % 32)));
    b22 = ((((uint32_t)b22) << ((11) % 32)) ^
           (((uint32_t)b22) >> ((32 - (11)) % 32)));
    b23 = ((((uint32_t)b23) << ((11) % 32)) ^
           (((uint32_t)b23) >> ((32 - (11)) % 32)));
    vb1 = b13;
    b13 = b12;
    b12 = b11;
    b11 = b10;
    b10 = vb1;
    c20 = ((((uint32_t)c20) << ((11) % 32)) ^
           (((uint32_t)c20) >> ((32 - (11)) % 32)));
    c21 = ((((uint32_t)c21) << ((11) % 32)) ^
           (((uint32_t)c21) >> ((32 - (11)) % 32)));
    c22 = ((((uint32_t)c22) << ((11) % 32)) ^
           (((uint32_t)c22) >> ((32 - (11)) % 32)));
    c23 = ((((uint32_t)c23) << ((11) % 32)) ^
           (((uint32_t)c23) >> ((32 - (11)) % 32)));
    vc1 = c13;
    c13 = c12;
    c12 = c11;
    c11 = c10;
    c10 = vc1;
    ;
    a00 ^= 0x000001A0;
    ;
    a00 ^= (~a10 & a20) ^ (a10 & b20) ^ (b10 & a20);
    b00 ^= (~b10 & b20) ^ (b10 & c20) ^ (c10 & b20);
    c00 ^= (~c10 & c20) ^ (c10 & a20) ^ (a10 & c20);
    a01 ^= (~a11 & a21) ^ (a11 & b21) ^ (b11 & a21);
    b01 ^= (~b11 & b21) ^ (b11 & c21) ^ (c11 & b21);
    c01 ^= (~c11 & c21) ^ (c11 & a21) ^ (a11 & c21);
    a02 ^= (~a12 & a22) ^ (a12 & b22) ^ (b12 & a22);
    b02 ^= (~b12 & b22) ^ (b12 & c22) ^ (c12 & b22);
    c02 ^= (~c12 & c22) ^ (c12 & a22) ^ (a12 & c22);
    a03 ^= (~a13 & a23) ^ (a13 & b23) ^ (b13 & a23);
    b03 ^= (~b13 & b23) ^ (b13 & c23) ^ (c13 & b23);
    c03 ^= (~c13 & c23) ^ (c13 & a23) ^ (a13 & c23);
    a10 ^= (~a20 & a00) ^ (a20 & b00) ^ (b20 & a00);
    b10 ^= (~b20 & b00) ^ (b20 & c00) ^ (c20 & b00);
    c10 ^= (~c20 & c00) ^ (c20 & a00) ^ (a20 & c00);
    a11 ^= (~a21 & a01) ^ (a21 & b01) ^ (b21 & a01);
    b11 ^= (~b21 & b01) ^ (b21 & c01) ^ (c21 & b01);
    c11 ^= (~c21 & c01) ^ (c21 & a01) ^ (a21 & c01);
    a12 ^= (~a22 & a02) ^ (a22 & b02) ^ (b22 & a02);
    b12 ^= (~b22 & b02) ^ (b22 & c02) ^ (c22 & b02);
    c12 ^= (~c22 & c02) ^ (c22 & a02) ^ (a22 & c02);
    a13 ^= (~a23 & a03) ^ (a23 & b03) ^ (b23 & a03);
    b13 ^= (~b23 & b03) ^ (b23 & c03) ^ (c23 & b03);
    c13 ^= (~c23 & c03) ^ (c23 & a03) ^ (a23 & c03);
    a20 ^= (~a00 & a10) ^ (a00 & b10) ^ (b00 & a10);
    b20 ^= (~b00 & b10) ^ (b00 & c10) ^ (c00 & b10);
    c20 ^= (~c00 & c10) ^ (c00 & a10) ^ (a00 & c10);
    a21 ^= (~a01 & a11) ^ (a01 & b11) ^ (b01 & a11);
    b21 ^= (~b01 & b11) ^ (b01 & c11) ^ (c01 & b11);
    c21 ^= (~c01 & c11) ^ (c01 & a11) ^ (a01 & c11);
    a22 ^= (~a02 & a12) ^ (a02 & b12) ^ (b02 & a12);
    b22 ^= (~b02 & b12) ^ (b02 & c12) ^ (c02 & b12);
    c22 ^= (~c02 & c12) ^ (c02 & a12) ^ (a02 & c12);
    a23 ^= (~a03 & a13) ^ (a03 & b13) ^ (b03 & a13);
    b23 ^= (~b03 & b13) ^ (b03 & c13) ^ (c03 & b13);
    c23 ^= (~c03 & c13) ^ (c03 & a13) ^ (a03 & c13);
    ;
    ;
    a10 = ((((uint32_t)a10) << ((1) % 32)) ^
           (((uint32_t)a10) >> ((32 - (1)) % 32)));
    a11 = ((((uint32_t)a11) << ((1) % 32)) ^
           (((uint32_t)a11) >> ((32 - (1)) % 32)));
    a12 = ((((uint32_t)a12) << ((1) % 32)) ^
           (((uint32_t)a12) >> ((32 - (1)) % 32)));
    a13 = ((((uint32_t)a13) << ((1) % 32)) ^
           (((uint32_t)a13) >> ((32 - (1)) % 32)));
    va1 = ((((uint32_t)a23) << ((8) % 32)) ^
           (((uint32_t)a23) >> ((32 - (8)) % 32)));
    a23 = ((((uint32_t)a21) << ((8) % 32)) ^
           (((uint32_t)a21) >> ((32 - (8)) % 32)));
    a21 = va1;
    va1 = ((((uint32_t)a22) << ((8) % 32)) ^
           (((uint32_t)a22) >> ((32 - (8)) % 32)));
    a22 = ((((uint32_t)a20) << ((8) % 32)) ^
           (((uint32_t)a20) >> ((32 - (8)) % 32)));
    a20 = va1;
    b10 = ((((uint32_t)b10) << ((1) % 32)) ^
           (((uint32_t)b10) >> ((32 - (1)) % 32)));
    b11 = ((((uint32_t)b11) << ((1) % 32)) ^
           (((uint32_t)b11) >> ((32 - (1)) % 32)));
    b12 = ((((uint32_t)b12) << ((1) % 32)) ^
           (((uint32_t)b12) >> ((32 - (1)) % 32)));
    b13 = ((((uint32_t)b13) << ((1) % 32)) ^
           (((uint32_t)b13) >> ((32 - (1)) % 32)));
    vb1 = ((((uint32_t)b23) << ((8) % 32)) ^
           (((uint32_t)b23) >> ((32 - (8)) % 32)));
    b23 = ((((uint32_t)b21) << ((8) % 32)) ^
           (((uint32_t)b21) >> ((32 - (8)) % 32)));
    b21 = vb1;
    vb1 = ((((uint32_t)b22) << ((8) % 32)) ^
           (((uint32_t)b22) >> ((32 - (8)) % 32)));
    b22 = ((((uint32_t)b20) << ((8) % 32)) ^
           (((uint32_t)b20) >> ((32 - (8)) % 32)));
    b20 = vb1;
    c10 = ((((uint32_t)c10) << ((1) % 32)) ^
           (((uint32_t)c10) >> ((32 - (1)) % 32)));
    c11 = ((((uint32_t)c11) << ((1) % 32)) ^
           (((uint32_t)c11) >> ((32 - (1)) % 32)));
    c12 = ((((uint32_t)c12) << ((1) % 32)) ^
           (((uint32_t)c12) >> ((32 - (1)) % 32)));
    c13 = ((((uint32_t)c13) << ((1) % 32)) ^
           (((uint32_t)c13) >> ((32 - (1)) % 32)));
    vc1 = ((((uint32_t)c23) << ((8) % 32)) ^
           (((uint32_t)c23) >> ((32 - (8)) % 32)));
    c23 = ((((uint32_t)c21) << ((8) % 32)) ^
           (((uint32_t)c21) >> ((32 - (8)) % 32)));
    c21 = vc1;
    vc1 = ((((uint32_t)c22) << ((8) % 32)) ^
           (((uint32_t)c22) >> ((32 - (8)) % 32)));
    c22 = ((((uint32_t)c20) << ((8) % 32)) ^
           (((uint32_t)c20) >> ((32 - (8)) % 32)));
    c20 = vc1;
    ;
    va1 = a03 ^ a13 ^ a23;
    va2 = a00 ^ a10 ^ a20;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a00 ^= va1;
    a10 ^= va1;
    a20 ^= va1;
    va1 = a01 ^ a11 ^ a21;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a01 ^= va2;
    a11 ^= va2;
    a21 ^= va2;
    va2 = a02 ^ a12 ^ a22;
    va1 = ((((uint32_t)va1) << ((5) % 32)) ^
           (((uint32_t)va1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va1) << ((14) % 32)) ^
           (((uint32_t)va1) >> ((32 - (14)) % 32)));
    a02 ^= va1;
    a12 ^= va1;
    a22 ^= va1;
    va2 = ((((uint32_t)va2) << ((5) % 32)) ^
           (((uint32_t)va2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)va2) << ((14) % 32)) ^
           (((uint32_t)va2) >> ((32 - (14)) % 32)));
    a03 ^= va2;
    a13 ^= va2;
    a23 ^= va2;
    vb1 = b03 ^ b13 ^ b23;
    vb2 = b00 ^ b10 ^ b20;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b00 ^= vb1;
    b10 ^= vb1;
    b20 ^= vb1;
    vb1 = b01 ^ b11 ^ b21;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b01 ^= vb2;
    b11 ^= vb2;
    b21 ^= vb2;
    vb2 = b02 ^ b12 ^ b22;
    vb1 = ((((uint32_t)vb1) << ((5) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb1) << ((14) % 32)) ^
           (((uint32_t)vb1) >> ((32 - (14)) % 32)));
    b02 ^= vb1;
    b12 ^= vb1;
    b22 ^= vb1;
    vb2 = ((((uint32_t)vb2) << ((5) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vb2) << ((14) % 32)) ^
           (((uint32_t)vb2) >> ((32 - (14)) % 32)));
    b03 ^= vb2;
    b13 ^= vb2;
    b23 ^= vb2;
    vc1 = c03 ^ c13 ^ c23;
    vc2 = c00 ^ c10 ^ c20;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c00 ^= vc1;
    c10 ^= vc1;
    c20 ^= vc1;
    vc1 = c01 ^ c11 ^ c21;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c01 ^= vc2;
    c11 ^= vc2;
    c21 ^= vc2;
    vc2 = c02 ^ c12 ^ c22;
    vc1 = ((((uint32_t)vc1) << ((5) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc1) << ((14) % 32)) ^
           (((uint32_t)vc1) >> ((32 - (14)) % 32)));
    c02 ^= vc1;
    c12 ^= vc1;
    c22 ^= vc1;
    vc2 = ((((uint32_t)vc2) << ((5) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (5)) % 32))) ^
          ((((uint32_t)vc2) << ((14) % 32)) ^
           (((uint32_t)vc2) >> ((32 - (14)) % 32)));
    c03 ^= vc2;
    c13 ^= vc2;
    c23 ^= vc2;
    ;
    a20 = ((((uint32_t)a20) << ((11) % 32)) ^
           (((uint32_t)a20) >> ((32 - (11)) % 32)));
    a21 = ((((uint32_t)a21) << ((11) % 32)) ^
           (((uint32_t)a21) >> ((32 - (11)) % 32)));
    a22 = ((((uint32_t)a22) << ((11) % 32)) ^
           (((uint32_t)a22) >> ((32 - (11)) % 32)));
    a23 = ((((uint32_t)a23) << ((11) % 32)) ^
           (((uint32_t)a23) >> ((32 - (11)) % 32)));
    va1 = a13;
    a13 = a12;
    a12 = a11;
    a11 = a10;
    a10 = va1;
    b20 = ((((uint32_t)b20) << ((11) % 32)) ^
           (((uint32_t)b20) >> ((32 - (11)) % 32)));
    b21 = ((((uint32_t)b21) << ((11) % 32)) ^
           (((uint32_t)b21) >> ((32 - (11)) % 32)));
    b22 = ((((uint32_t)b22) << ((11) % 32)) ^
           (((uint32_t)b22) >> ((32 - (11)) % 32)));
    b23 = ((((uint32_t)b23) << ((11) % 32)) ^
           (((uint32_t)b23) >> ((32 - (11)) % 32)));
    vb1 = b13;
    b13 = b12;
    b12 = b11;
    b11 = b10;
    b10 = vb1;
    c20 = ((((uint32_t)c20) << ((11) % 32)) ^
           (((uint32_t)c20) >> ((32 - (11)) % 32)));
    c21 = ((((uint32_t)c21) << ((11) % 32)) ^
           (((uint32_t)c21) >> ((32 - (11)) % 32)));
    c22 = ((((uint32_t)c22) << ((11) % 32)) ^
           (((uint32_t)c22) >> ((32 - (11)) % 32)));
    c23 = ((((uint32_t)c23) << ((11) % 32)) ^
           (((uint32_t)c23) >> ((32 - (11)) % 32)));
    vc1 = c13;
    c13 = c12;
    c12 = c11;
    c11 = c10;
    c10 = vc1;
    ;
    a00 ^= 0x00000012;
    ;
    a00 ^= (~a10 & a20) ^ (a10 & b20) ^ (b10 & a20);
    b00 ^= (~b10 & b20) ^ (b10 & c20) ^ (c10 & b20);
    c00 ^= (~c10 & c20) ^ (c10 & a20) ^ (a10 & c20);
    a01 ^= (~a11 & a21) ^ (a11 & b21) ^ (b11 & a21);
    b01 ^= (~b11 & b21) ^ (b11 & c21) ^ (c11 & b21);
    c01 ^= (~c11 & c21) ^ (c11 & a21) ^ (a11 & c21);
    a02 ^= (~a12 & a22) ^ (a12 & b22) ^ (b12 & a22);
    b02 ^= (~b12 & b22) ^ (b12 & c22) ^ (c12 & b22);
    c02 ^= (~c12 & c22) ^ (c12 & a22) ^ (a12 & c22);
    a03 ^= (~a13 & a23) ^ (a13 & b23) ^ (b13 & a23);
    b03 ^= (~b13 & b23) ^ (b13 & c23) ^ (c13 & b23);
    c03 ^= (~c13 & c23) ^ (c13 & a23) ^ (a13 & c23);
    a10 ^= (~a20 & a00) ^ (a20 & b00) ^ (b20 & a00);
    b10 ^= (~b20 & b00) ^ (b20 & c00) ^ (c20 & b00);
    c10 ^= (~c20 & c00) ^ (c20 & a00) ^ (a20 & c00);
    a11 ^= (~a21 & a01) ^ (a21 & b01) ^ (b21 & a01);
    b11 ^= (~b21 & b01) ^ (b21 & c01) ^ (c21 & b01);
    c11 ^= (~c21 & c01) ^ (c21 & a01) ^ (a21 & c01);
    a12 ^= (~a22 & a02) ^ (a22 & b02) ^ (b22 & a02);
    b12 ^= (~b22 & b02) ^ (b22 & c02) ^ (c22 & b02);
    c12 ^= (~c22 & c02) ^ (c22 & a02) ^ (a22 & c02);
    a13 ^= (~a23 & a03) ^ (a23 & b03) ^ (b23 & a03);
    b13 ^= (~b23 & b03) ^ (b23 & c03) ^ (c23 & b03);
    c13 ^= (~c23 & c03) ^ (c23 & a03) ^ (a23 & c03);
    a20 ^= (~a00 & a10) ^ (a00 & b10) ^ (b00 & a10);
    b20 ^= (~b00 & b10) ^ (b00 & c10) ^ (c00 & b10);
    c20 ^= (~c00 & c10) ^ (c00 & a10) ^ (a00 & c10);
    a21 ^= (~a01 & a11) ^ (a01 & b11) ^ (b01 & a11);
    b21 ^= (~b01 & b11) ^ (b01 & c11) ^ (c01 & b11);
    c21 ^= (~c01 & c11) ^ (c01 & a11) ^ (a01 & c11);
    a22 ^= (~a02 & a12) ^ (a02 & b12) ^ (b02 & a12);
    b22 ^= (~b02 & b12) ^ (b02 & c12) ^ (c02 & b12);
    c22 ^= (~c02 & c12) ^ (c02 & a12) ^ (a02 & c12);
    a23 ^= (~a03 & a13) ^ (a03 & b13) ^ (b03 & a13);
    b23 ^= (~b03 & b13) ^ (b03 & c13) ^ (c03 & b13);
    c23 ^= (~c03 & c13) ^ (c03 & a13) ^ (a03 & c13);
    ;
    ;
    a10 = ((((uint32_t)a10) << ((1) % 32)) ^
           (((uint32_t)a10) >> ((32 - (1)) % 32)));
    a11 = ((((uint32_t)a11) << ((1) % 32)) ^
           (((uint32_t)a11) >> ((32 - (1)) % 32)));
    a12 = ((((uint32_t)a12) << ((1) % 32)) ^
           (((uint32_t)a12) >> ((32 - (1)) % 32)));
    a13 = ((((uint32_t)a13) << ((1) % 32)) ^
           (((uint32_t)a13) >> ((32 - (1)) % 32)));
    va1 = ((((uint32_t)a23) << ((8) % 32)) ^
           (((uint32_t)a23) >> ((32 - (8)) % 32)));
    a23 = ((((uint32_t)a21) << ((8) % 32)) ^
           (((uint32_t)a21) >> ((32 - (8)) % 32)));
    a21 = va1;
    va1 = ((((uint32_t)a22) << ((8) % 32)) ^
           (((uint32_t)a22) >> ((32 - (8)) % 32)));
    a22 = ((((uint32_t)a20) << ((8) % 32)) ^
           (((uint32_t)a20) >> ((32 - (8)) % 32)));
    a20 = va1;
    b10 = ((((uint32_t)b10) << ((1) % 32)) ^
           (((uint32_t)b10) >> ((32 - (1)) % 32)));
    b11 = ((((uint32_t)b11) << ((1) % 32)) ^
           (((uint32_t)b11) >> ((32 - (1)) % 32)));
    b12 = ((((uint32_t)b12) << ((1) % 32)) ^
           (((uint32_t)b12) >> ((32 - (1)) % 32)));
    b13 = ((((uint32_t)b13) << ((1) % 32)) ^
           (((uint32_t)b13) >> ((32 - (1)) % 32)));
    vb1 = ((((uint32_t)b23) << ((8) % 32)) ^
           (((uint32_t)b23) >> ((32 - (8)) % 32)));
    b23 = ((((uint32_t)b21) << ((8) % 32)) ^
           (((uint32_t)b21) >> ((32 - (8)) % 32)));
    b21 = vb1;
    vb1 = ((((uint32_t)b22) << ((8) % 32)) ^
           (((uint32_t)b22) >> ((32 - (8)) % 32)));
    b22 = ((((uint32_t)b20) << ((8) % 32)) ^
           (((uint32_t)b20) >> ((32 - (8)) % 32)));
    b20 = vb1;
    c10 = ((((uint32_t)c10) << ((1) % 32)) ^
           (((uint32_t)c10) >> ((32 - (1)) % 32)));
    c11 = ((((uint32_t)c11) << ((1) % 32)) ^
           (((uint32_t)c11) >> ((32 - (1)) % 32)));
    c12 = ((((uint32_t)c12) << ((1) % 32)) ^
           (((uint32_t)c12) >> ((32 - (1)) % 32)));
    c13 = ((((uint32_t)c13) << ((1) % 32)) ^
           (((uint32_t)c13) >> ((32 - (1)) % 32)));
    vc1 = ((((uint32_t)c23) << ((8) % 32)) ^
           (((uint32_t)c23) >> ((32 - (8)) % 32)));
    c23 = ((((uint32_t)c21) << ((8) % 32)) ^
           (((uint32_t)c21) >> ((32 - (8)) % 32)));
    c21 = vc1;
    vc1 = ((((uint32_t)c22) << ((8) % 32)) ^
           (((uint32_t)c22) >> ((32 - (8)) % 32)));
    c22 = ((((uint32_t)c20) << ((8) % 32)) ^
           (((uint32_t)c20) >> ((32 - (8)) % 32)));
    c20 = vc1;
    ;
    ;

    a00 ^= b00 ^ c00;
    a01 ^= b01 ^ c01;
    a02 ^= b02 ^ c02;
    a03 ^= b03 ^ c03;
    a10 ^= b10 ^ c10;
    a11 ^= b11 ^ c11;
    a12 ^= b12 ^ c12;
    a13 ^= b13 ^ c13;
    a20 ^= b20 ^ c20;
    a21 ^= b21 ^ c21;
    a22 ^= b22 ^ c22;
    a23 ^= b23 ^ c23;
    state[0 + 0] = a00, state[0 + 1] = a01, state[0 + 2] = a02,
              state[0 + 3] = a03;
    state[4 + 0] = a10, state[4 + 1] = a11, state[4 + 2] = a12,
              state[4 + 3] = a13;
    state[8 + 0] = a20, state[8 + 1] = a21, state[8 + 2] = a22,
              state[8 + 3] = a23;
    ;
}
