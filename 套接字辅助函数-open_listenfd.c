/**open_listenfd函数创建一个监听描述符， 准备好接收连接请求。**/

#include "csapp.h"
int open_listenfd(char *port)
{
  int clientfd;
  struct addrinfo hints, *listp, *p;
 
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags    = AI_PASSIVE | AI_ADDRCONFIG;
  hints.ai_flags    != AI_NUMERICSERV;
 
  Getaddrinfo(NUll, port, &hints, &listp);
  
  for(p=listp; p ; p=p->ai_next) {
     if((listenfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0) continue;
     
     Setsockopt(listenfd, SQL_SOCKET, SO_REUEADDR, );
  
  }
  
}
