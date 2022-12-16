## SBUF 生产者-消费者程序

```
#include "csapp.h"
#include "sbuf.h"

void sbuf_init(sbuf_t *sp, int n)
{
   sp->buf = Calloc(n, sizeof(int));
   sp->n   = n;
   sp->front = sp->rear = 0;
   
}

```
