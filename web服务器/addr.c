/**web服务器-tiny(csapp 11.6)**/

int main()
{
  int listenfd, connfd;
	
	if(argc != 2) {
		fprinf(stderr, "usage: %s <port>\n", argv[0]);
		exit(1);
	}
	
	//
	listenfd = open_listenfd(argv[1]);
	while(1){
	   clientlen = sizeof(clientaddr);
	   connfd    = Accept(listenfd, (SA *)&clientaddr, &clientlen);
    Getnameinfo 
	}
}
