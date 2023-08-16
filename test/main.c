/*
 Reviser: Polaris_hzn8
 Email: 3453851623@qq.com
 filename: main.c
 Update Time: Wed 16 Aug 2023 18:12:23 CST
 brief: 
*/

#include "fdfs_api.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char* argv[])
{
    char buf[1024] = { 0 };
    fdfs_upload_file(argv[1], buf);
    printf("fileId = %s\n", buf);

    printf("=========================\n");
    memset(buf, 0, sizeof(buf));
    fdfs_upload_file1(argv[1], buf, sizeof(buf));
    printf("fileId = %s\n", buf);

    return 0;
}
