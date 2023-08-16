/*
 Reviser: Polaris_hzn8
 Email: 3453851623@qq.com
 filename: make_log.h
 Update Time: Wed 16 Aug 2023 17:56:47 CST
 brief: 
*/

#ifndef _MAKE_LOG_H_
#define _MAKE_LOG_H
#include "pthread.h"

int out_put_file(char* path, char* buf);
int make_path(char* path, char* module_name, char* proc_name);
int dumpmsg_to_file(char* module_name, char* proc_name, const char* filename,
    int line, const char* funcname, char* fmt, ...);
#ifndef _LOG
#define LOG(module_name, proc_name, x...)                                               \
    do {                                                                                \
        dumpmsg_to_file(module_name, proc_name, __FILE__, __LINE__, __FUNCTION__, ##x); \
    } while (0)
#else
#define LOG(module_name, proc_name, x...)
#endif

extern pthread_mutex_t ca_log_lock;

#endif
