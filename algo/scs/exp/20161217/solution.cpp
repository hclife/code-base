#include <cstdio>
#include <cstring>

#define FLOOR		10000
#define HOUSE		10000
#define SIZE		10024
#define MAXP		20000
#define SHELTER		3
#define PEOPLE		10
#define ABS(x)		((x)>=0?(x):-(x))
#define queue_init	(head=tail=0)
#define queue_is_empty	(head==tail)
#define queue_if_full	(head==(tail+1)%SIZE)
#define rint		register int


struct point {
	int sht,idx,step,dir;
};

int head,tail;
int vis[HOUSE];
int people[SHELTER];
int shelter[SHELTER],dist[SHELTER];
struct point queue[SIZE];

void en_queue(struct point in)
{
	if (queue_is_full) return;
	queue[tail]=in;
	tail=(tail+1)%SIZE;
}

struct point de_queue()
{
	struct point p={0};
	if (queue_is_empty) return p;
	p=queue[head];
	head=(head+1)%SIZE;
	return p;
}

void bfs(int house[HOUSE])
{
	struct point in,out;queue_init;
	for (rint i=0;i<SHELTER;++i) {
		in.idx=shelter[in.sht=i];in.step=in.dir=0;
		vis[in.idx]=1;en_queue(in);
	}
	while (!queue_is_empty) {
		out=de_queue();
		switch (out.dir) {
		case 0:	printf("The initial shelter point\n");
			if (out.idx>0 && !vis[out.idx-1]) {
				in.sht=out.sht;in.idx=out.idx-1;
				in.dir=1;in.step=out.step+1;
				vis[in.idx]=1;people[in.sht]-=house[in.idx];
				house[in.idx]=shelter[in.sht];en_queue(in);
			}
			if (out.idx<HOUSE-1 && !vis[out.idx+1]) {
				in.sht=out.sht;in.idx=out.idx+1;
				in.dir=2;in.step=out.step+1;
				vis[in.idx]=1;people[in.sht]-=house[in.idx];
				house[in.idx]=shelter[in.sht];en_queue(in);
			}
			break;
		case 1:	printf("Heading Left\n");
			if (out.idx<=0 || vis[out.idx-1]) break;
			if (out.sht>=0 && house[out.idx-1]<=people[out.sht]) {
				in.sht=out.sht;in.idx=out.idx-1;
				in.dir=1;in.step=out.step+1;
				vis[in.idx]=1;people[in.sht]-=house[in.idx];
				house[in.idx]=shelter[in.sht];en_queue(in);
				break;
			}
			int min_sht=-1,min_dist=-1,now_idx=out.idx-1;
			for (rint i=0;i<SHELTER;++i) dist[i]=ABS(shelter[i]-now_idx);
			for (rint i=0;i<SHELTER;++i) {
				if (house[now_idx]>people[i]) continue;
				if (min_dist<0 || min_dist>dist[i]) min_dist=dist[min_sht=i];
			}
			in.sht=min_sht;in.idx=now_idx;in.dir=1;in.step=out.step+1;
			vis[in.idx]=1;if (min_sht>=0) people[min_sht]-=house[in.idx];
			house[in.idx]=min_sht>=0?shelter[min_sht]:-1;en_queue(in);
			break;
		case 2: printf("Heading Right\n");
			if (out.idx>=HOUSE-1 || vis[out.idx+1]) break;
			if (out.sht>=0 && house[out.idx+1]<=people[out.sht]) {
				in.sht=out.sht;in.idx=out.idx+1;
				in.dir=2;in.step=out.step+1;
				vis[in.idx]=1;people[in.sht]-=house[in.idx];
				house[in.idx]=shelter[in.sht];en_queue(in);
				break;
			}
			int min_sht=-1,min_dist=-1,now_idx=out.idx+1;
			for (rint i=0;i<SHELTER;++i) dist[i]=ABS(shelter[i]-now_idx);
			for (rint i=0;i<SHELTER;++i) {
				if (house[now_idx]>people[i]) continue;
				if (min_dist<0 || min_dist>dist[i]) min_dist=dist[min_sht=i];
			}
			in.sht=min_sht;in.idx=now_idx;in.dir=2;in.step=out.step+1;
			vis[in.idx]=1;if (min_sht>=0) people[min_sht]-=house[in.idx];
			house[in.idx]=min_sht>=0?shelter[min_sht]:-1;en_queue(in);
			break;
		default:
			printf("impossible out.dir=%d\n",out.dir);
			return;
		}
	}
}

void assign(int house[FLOOR][HOUSE])
{
	for (rint f=0;f<FLOOR;++f) {
		for (rint h=0;h<HOUSE;++h) vis[h]=0;
		for (rint i=0,h=0;h<HOUSE;++h)
		if (!house[f][h]) shelter[i++]=h;
		for (rint i=0;i<SHELTER;++i) people[i]=MAXP;
		bfs(house[f]);
	}
}
