#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>


#define BUFLEN 1024
#define LISTENPORT 3333

int main()
{
  int sockfd, len, n;
  //char buffer[BUFLEN];
  
sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if(sockfd ==-1)
  {
    perror("socket system 1 call failed");
    exit(EXIT_FAILURE);
  }

//  memset(&receiverAddr, 0, sizeof(receiverAddr));
  //memset(&senderAddr, 0, sizeof(senderAddr));
struct sockaddr_in receiverAddr, senderAddr;

  receiverAddr.sin_family = AF_INET;
  receiverAddr.sin_addr.s_addr = INADDR_ANY;
  receiverAddr.sin_port = htons(LISTENPORT);

int b=bind(sockfd, (struct sockaddr *)&receiverAddr, sizeof(receiverAddr));
  if( b ==-1)
  {
    perror("bind syscall 1 failed");
    exit(EXIT_FAILURE);//exit(0);
  }

char buffer[BUFLEN];
while(1){
  len = sizeof(senderAddr);  //  use senderAddr
  printf("waiting for data to be received from usend_sys2: \n");
  n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *) &senderAddr, &len);
  buffer[n] = '\0';
  printf("data received from usend_sys2 : %s\n", buffer);
  if(strcmp(buffer,"exit")==0)
  break;
  }//printf("--------------\n");
  return 0;
}

