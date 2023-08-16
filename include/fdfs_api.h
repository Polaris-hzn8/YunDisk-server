/*
 Reviser: Polaris_hzn8
 Email: 3453851623@qq.com
 filename: fdfs_api.h
 Update Time: Wed 16 Aug 2023 23:44:57 CST
 brief: 
*/

#ifndef _FDFS_API_H
#define _FDFS_API_H

int fdfs_upload_file(const char* filename, char* fileid);
int fdfs_upload_file1(const char* filename, char* fileid, int size);

#endif

