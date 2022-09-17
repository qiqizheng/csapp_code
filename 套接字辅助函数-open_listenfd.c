/**open_listenfd函数创建一个监听描述符， 准备好接收连接请求。**/

#include "csapp.h"
int open_listenfd(char *port)
{
  int clientfd;
  struct addrinfo hints, *listp, *p;
 
  //复制值为0，字符数为sizeof(addrinfo)到hints中。
  memset(&hints, 0, sizeof(struct addrinfo));
  
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags    = AI_PASSIVE | AI_ADDRCONFIG;
  hints.ai_flags    != AI_NUMERICSERV;
 
  //将主机地址,端口号字符串转化为套接字地址结构
  Getaddrinfo(NUll, port, &hints, &listp);
  
  for(p=listp; p ; p=p->ai_next) {
    //创建一个描述符
     if((listenfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0) continue;
     
     Setsockopt(listenfd, SQL_SOCKET, SO_REUEADDR, (const void *)&optval, sizeof(int));
     
     //将创建的描述符和主机地址绑定
     if(bind(listenfd, p->ai_addr, p->ai_addrlen ) == 0) break; //success
     Close(listenfd);   
  
  }
  
  Freeaddrinfo(listp);
  if(!p) return -1;
  
  //将listenfd转换为一个监听描述符
  if(listen(listenfd, LISTENQ) < 0){
    close(listenfd);
    return -1;
  }
  return listenfd;
  
}
