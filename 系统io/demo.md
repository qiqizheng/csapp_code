
练习题10.2
假设磁盘文件 foobar.txt 由6个ASCII码字符“foobar”组成。 那么，下列程序的输出是什么？
```
#include "csapp.h"
int main(){
  int fd1, fd2;
 char c;

 fd1 = open("foobar.txt", O_RDONLY, 0);
 fd2 = open("foobar.txt", O_RDONLY, 0);

 read(fd1, &c, 1);
 read(fd2, &c, 1);

 printf("c = %c\n", c);
 exit(0);

}
```

实验结果：![image](https://user-images.githubusercontent.com/18367460/197399720-afb85df8-93de-48ec-88bf-f14e30d2e966.png)

考察点： fd1,fd2是不同的描述符，都有自己的位置。


练习题10.3
假设磁盘文件 foobar.txt 由6个ASCII码字符“foobar”组成。 那么，下列程序的输出是什么？
```
#include "csapp.h"

int main(){

 int fd;
 char c;

 fd = open("foobar.txt", O_RDONLY, 0);
 if(fork() == 0){
  read(fd, &c, 1);
  exit(0);
 }

 wait(NULL);
 read(fd, &c, 1);

 printf("c = %c\n", c);
 exit(0);

}

```

实验结果：![image](https://user-images.githubusercontent.com/18367460/197401260-d2be390d-c329-4e56-860d-d2fc8dc0dc2c.png)

考察点： 子进程会调用父进程的描述符表，所以在描述符fd被调用了2次，第二次读取的是第二次字节o


练习题10.4
如何用dup2 将标准输入重定向到描述符5？

```
dup2(5,0);
```

考察点：重定向得的基本使用


练习题10.5
假设磁盘文件 foobar.txt由6个ASCII码字符“foobar”组成， 那么下列程序的输出是什么？

```
#include "csapp.h"

int main()
{
  int fd1, fd2;
  char c;

  fd1 = open("foobar.txt", O_RDONLY, 0);
  fd2 = open("foobar.txt", O_RDONLY, 0);
  //读取fd2的第一个字符到 内存的c所在位置
   read(fd2, &c, 1);

//fd1描述符 重定向到描述符fd2
  dup2(fd2, fd1);

  //读取fd1的第一个字符到 内存的c所在位置
  read(fd1, &c, 1);

  printf("c = %c\n", c);
  exit(0);

}


```

结果：指向第二个o![image](https://user-images.githubusercontent.com/18367460/198215100-206010e3-c256-4035-923d-0faf8a8ad48a.png)

考察点：read读取数据后描述符位置的变化， dup2重定向fd2,fd1


``` 
#include "csapp.h"

int main()
{
  int fd1, fd2, fd3;
  fd1 = open("foo.txt", O_RDONLY, 0);
  fd2 = open("bar.txt", O_RDONLY, 0);
  close(fd2);

  printf("fd2 = %d\n", fd2);
  fd3 = open("baz.txt", O_RDONLY, 0);
  printf("fd3 = %d\n", fd3);
  exit(0);

}
