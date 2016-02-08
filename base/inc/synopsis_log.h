#ifndef SYNOPSIS_LOG_H
#define SYNOPSIS_LOG_H

#include <stdio.h>

#define SYNOPSIS_LOG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define SYNOPSIS_ERR_LOG(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)


#ifdef SYNOPSIS_DEBUG
#define SYNOPSIS_DBG_LOG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define SYNOPSIS_DBG_ERR_LOG(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#else
#define SYNOPSIS_DBG_LOG(fmt, ...)
#define SYNOPSIS_DBG_ERR_LOG(fmt, ...)
#endif

#endif // SYNOPSIS_LOG_H
