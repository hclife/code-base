#include <iostream>
using namespace std;

#define QUEUE_LOOP	0
#define QSIZE		1024

#define queue_init	(head=tail=len=0)
#define queue_is_empty	(head==tail)
#define queue_is_full	(head==(tail+1)%QSIZE)

#ifndef QUEUE_LOOP
#define en_queue(x)	(queue[tail++]=(x))
#define de_queue	(queue[head++])
#endif

typedef struct point {
    int data;
} point;

int head,tail,len;
struct point queue[QSIZE];

#ifdef QUEUE_LOOP
void en_queue(struct point x) {
    if (queue_is_full) return;
    queue[tail++]=x;
    tail%=QSIZE;
    ++len;
}

struct point de_queue() {
    struct point x={0};
    if (queue_is_empty) return x;
    x=queue[head++];
    head%=QSIZE;
    --len;
    return x;
}
#endif

struct point get_data() {
    struct point x={0};
    if (queue_is_empty) return x;
    return x=queue[head];
}

int main() {
    return 0;
}
