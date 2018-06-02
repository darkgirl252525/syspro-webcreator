#ifndef _GENERAL_INFO_H_
#define _GENERAL_INFO_H_

typedef struct generalInfo{
	int millis;
	long startTime;
	int pagesServed;
	long bytesServed;
}generalInfo;

generalInfo* createGeneralInfo();
void printStats(generalInfo* info, int newsock);

#endif