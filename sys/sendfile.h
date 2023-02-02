#ifndef _SYS_SENDFILE_H
#define _SYS_SENDFILE_H
#if 0

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>
#include <unistd.h>

ssize_t sendfile(int, int, off_t *, size_t);

#if defined(_LARGEFILE64_SOURCE) || defined(_GNU_SOURCE)
#define sendfile64 sendfile
#define off64_t off_t
#endif

#ifdef __cplusplus
}
#endif

#endif /* #if 0 */
#endif
