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
   
   /**获取addrinfo的列表**/
   memset(&hints, 0, sizeof(struct addrinfo)); //填充大小为addrinfo，值为0的字符到内存hints处。
   hints.ai_family = AF_INET;
   hints.ai_socktype = SOCK_STREAM;
   
   if((rc = getaddrinfo(argv[1] , NULL, &hints, &listp)) !=0){
      fprintf(stderr, "getaddinfo error: %s\n", gai_strerror(rc));
      exit(1);
   }
   
   /*遍历列表，并显示每个IP地址*/
   flags = NI_NUMERICHOST;
   for(p=listp; p; p=p->ai_next) {
      getnameinfo(p->ai_addr, p->ai_addrlen, buf, MAXLINE, NULL, 0, flags);
      printf("%s\n", buf);
   }
   
   /**清除listp**/
   freeaddrinfo(listp);
   
   exit(0);
}

```

编译后，
执行 ./11 baidu.com
![image](https://user-images.githubusercontent.com/18367460/200820981-10dce790-47e9-4704-ac7b-cd3d3f07f45d.png)
