### 11.17  HOSTINFO程序，使用getaddrinfo 和 getnameinfo展示出域名和它相关联的ip地址之间的映射
```
#include "csapp.h"

int main(int argc, char **argv)
{
   struct addrinfo *p, *listp, hints;
   char buf[MAXLINE];
   int rc,flags;
   
   if(argc != 2){
     fprintf(stderr, "");
     exit(0);
   }
   
   /****/
   memset(&hints, 0, sizeof(struct addrinfo)); //大小为addrinfo的0填充到内存hints的位置中
   hints.ai_family = AF_INET;                    
   hints.ai_socktype = SOCK_STREAM;
   if((rc = getaddrinfo(argv[1], NULL, &hints, &listp)) != 0){
      fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rc));
      exit(1);
   }
   
   flags = NI_NUMERICHOST;

}

```
