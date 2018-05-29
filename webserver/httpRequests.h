#ifndef _HTTP_REQUESTS_H_
#define _HTTP_REQUESTS_H_

int checkRequestInfo(char* request, char** file);
int checkHeader(char* header);
char* constructResponse(char* fullPath);
char* insertCurrentTime(int* length);
char* insertAdditionalHeaders(int* length,int contentLength, int size);
char* insertHtmlNotFound(int* length);
char* insertHtmlNotAuth(int* length);

#endif