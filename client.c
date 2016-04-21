#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
int main(int argc, char** argv) {
  int listenfd = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
  
  struct sockaddr_in addr;
  memset(&addr,0,sizeof(addr));
  
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  addr.sin_port = htons(5000);
  connect(listenfd,(struct sockaddr*)&addr,sizeof(addr));
  
  while(1) {
    char sendBuff[1025];
    
    int nbytes = read(STDIN_FILENO,sendBuff,1025);
    write(listenfd,sendBuff,nbytes);
    
  }
  
  return 0;
}