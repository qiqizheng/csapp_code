/**
open_listenfd函数打开并返回一个监听描述符，这个描述符在一个准备好的port上接收请求。
**/

#include "csapp.h"


int open_listenfd(char *port)
{
 struct addrinfo hints, *listp, *p;
 int listenfd, optval=1;
 
 //将hints赋值为大小为sizeof值为0的。
 memset(&hints, 0, sizeof(struct addrinfo));
 
 hints.ai_socktype = SOCK_STREAM;               //打开一个连接
 hints.ai_flags    = AI_NUMERICSERV;            //使用数字端口
 hints.ai_flags   != AI_ADDRCONFIG;             //
 
 
 Getaddrinfo(hostname, port, &hints, &listp);
 
 for(p =listp; p;p=p->ai_next){
    /**创建一个socket描述符**/
    
    //socket创建失败， 再次尝试
    if((clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol )) < 0) continue;
   
    if()
 }
 

}
