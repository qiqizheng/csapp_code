/**open_listenfd函数打开并返回一个监听描述符，这个描述符在一个准备好的port上接收请求。**/

#include "csapp.h"
int open_listenfd(char *port)
{
 struct addrinfo hints, *listp, *p;
  int listend, optval =1;
  
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_socktype = SOCK_STREAM;
  
  
}
