#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linksQueue.h"

linksQueue* createLinksQueue(){
	linksQueue* queue = malloc(sizeof(linksQueue));
	queue->size = 0;
	queue->first = NULL;
	queue->last = NULL;
	return queue;
}

void pushLinksQueue(linksQueue* queue,char* link){
	if(queue->size==0 || queue->first == NULL){
		queue->first = malloc(sizeof(linkNode));
		queue->first->link = malloc((strlen(link)+1)*sizeof(char));
		queue->first->next = NULL;
		strcpy(queue->first->link,link);
		queue->last = queue->first;
	}else{
		queue->last->next = malloc(sizeof(linkNode));
		queue->last->next->link = malloc((strlen(link)+1)*sizeof(char));
		queue->last->next->next = NULL;
		strcpy(queue->last->next->link,link);
		queue->last = queue->last->next;
	}
	queue->size++;
}

linkNode* popLinksQueue(linksQueue* queue){
	if(queue->size > 0){
		linkNode* firstNode = queue->first;
		queue->first = queue->first->next;
		queue->size--;
		return firstNode;
	}else{
		return NULL;
	}
}

void destroyLinksQueue(linksQueue** queue){
	linkNode* temp = (*queue)->first;
	for(int i=0;i<(*queue)->size;i++){
		free(temp->link);
		temp->link = NULL;
		free(temp);
		temp = temp->next;
	}
	(*queue)->last = NULL;
	(*queue)->size = 0;
	free(*queue);
	*queue = NULL;
}

void destroyLinkNode(linkNode** node){
	free((*node)->link);
	(*node)->link = NULL;
	(*node)->next = NULL;
	free(*node);
	*node = NULL;
}


int isEmptyLinksQueue(linksQueue* queue){
	if(queue->size == 0){
		return 1;
	}
	return 0;
}

void printLinksQueue(linksQueue* queue){
	linkNode* temp = queue->first;
	for(int i=0;i< queue->size;i++){
		printf("%d Node: '%s'\n",i,temp->link);
		temp = temp->next;
	}
}

char* convertToLink(char* startingUrl){
	char* token = strtok(startingUrl,"/");
	token = strtok(NULL,"/");
	token = strtok(NULL,"/");
	char* site = malloc((strlen(token)+1)*sizeof(char));
	strcpy(site,token);
	token = strtok(NULL,"/");
	char* page = malloc((strlen(token)+1)*sizeof(char));
	strcpy(page,token);
	char* link = malloc((strlen(site) + strlen(page) + 3)*sizeof(char));
	sprintf(link,"/%s/%s",site,page);
	free(site);
	site = NULL;
	free(page);
	page = NULL;
	return link;
}

char* createRequest(char* link, char* host){
	int lengthFirstLine = strlen("GET  HTTP/1.1\n") + strlen(link) + 1;
	int lengthHostLine = strlen("Host: \n") + strlen(host) + 1;
	int lengthAdditionalLines=strlen("User-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)\nAccept-Language: en-us\nAccept-Encoding: gzip, deflate\nConnection: Keep-Alive\n\n")+1;
	int fullLength = lengthFirstLine + lengthHostLine + lengthAdditionalLines;
	char* request = malloc(fullLength*sizeof(char));
	sprintf(request,"GET %s HTTP/1.1\nUser-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)\nHost: %s\nAccept-Language: en-us\nAccept-Encoding: gzip, deflate\nConnection: Keep-Alive\n",link,host);
	return request;
}

void insertLinksQueueContent(linksQueue* queue, char* content){
	char* linkStart = "<a href=";
	char* resultStart = strstr(content, linkStart);
	int positionStart = resultStart - linkStart;
	int substringLengthStart = strlen(linkStart) - positionStart;
	char* linkEnd = "</a>";
}