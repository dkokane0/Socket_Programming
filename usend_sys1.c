#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define REMOTEPORT 4444
#define BUFLEN 1024

int main()
{
  int sockfd;
  system("clear");
 // char buffer[BUFLEN];
  //char messageStr;
  
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if(sockfd ==-1)
  {
    perror("socket system 1 call failed");
    exit(EXIT_FAILURE);
  }
  //memset(&receiverAddr, 0, sizeof(receiverAddr));
  struct sockaddr_in   receiverAddr;

  receiverAddr.sin_family = AF_INET;
  receiverAddr.sin_port = htons(REMOTEPORT);
  receiverAddr.sin_addr.s_addr = INADDR_ANY;

  char buffer[BUFLEN],messageStr[BUFLEN];
 while(1)
 { printf("Enter message you want to send to urecv_sys2(recever)  :  ");
  scanf("%s",messageStr);
  
  sendto(sockfd, messageStr, strlen(messageStr), 0, (const struct sockaddr *) &receiverAddr, sizeof(receiverAddr));
  if(strcmp(messageStr,"exit")==0)
  break;
    
}
  close(sockfd);
  return 0;
}

