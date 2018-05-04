#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

void readLine(char line[]){
  int c=0, i=0;
  while((c=getchar())!='\n'){
    line[i]=c;
    i++;
  }
  line[i]='\0';
}

int main(){
  printf("Enter IP: ");
  char IP[64];
  scanf("%s", IP);

  printf("Enter port: ");
  unsigned int port;
  scanf("%u", &port);

  printf("Enter user name: ");
  char userName[20];
  scanf("%s", userName);

  printf("\n*Chat Started*\n\n");

  int fd = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in address;
  memset(&address, 0, sizeof(address));
  address.sin_family = AF_INET;
  address.sin_port = htons(port);
  inet_pton(AF_INET, IP, &(address.sin_addr));

  connect(fd, (struct sockaddr*) &address, sizeof(address));

  char message[8192]="";
  char totalMsg[8192]="";
  
  getchar();
  while(strcmp(message, "quit") != 0){
    printf("%s: ", userName);
    readLine(message);

    sprintf(totalMsg, "%s: %s", userName, message);
    
    if(strcmp(message, "quit") != 0)
      send(fd, totalMsg, strlen(totalMsg), 0);
  }

  printf("\n*Chat Ended*\n");
  
  close(fd);
  return 0;
}
