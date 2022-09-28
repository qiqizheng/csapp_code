/**web服务器-tiny(csapp 11.6)**/

int main()
{
  int listenfd, connfd;
	
	if(argc != 2) {
		fprinf(stderr, "usage: %s <port>\n", argv[0]);
		exit(1);
	}
	
	//创建监听描述符， 监听客户端请求
	listenfd = open_listenfd(argv[1]);
	while(1){
	   clientlen = sizeof(clientaddr);
	   //检测到有客户端请求， 返回一个已连接描述符	
	   connfd    = Accept(listenfd, (SA *)&clientaddr, &clientlen);
	   //将描述符地址转换为主机地址	
           Getnameinfo (SA *) &clientaddr ,clientlen, hostname, MAXLINE, port, MAXLINE, 0);
	   printf("Accepted connection from (%s %s)\n", hostname , port);
	   doit(connfd);
	   Close(connfd);
	}
}

/**处理http事务
**/
void doit(int fd){
   int is_static;
   char buf[MAXLINE], method[MAXLINE], uri[MAXLINE], version[MAXLINE];
   char filename[MAXLINE], cgiargs[MAXLINE];
   rio_t rio;
	
   Rio_readinitb(&rio, fd);
   Rio_readlineb(&rio, buf, MAXLINE);

}
