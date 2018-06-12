#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define MAX 101


struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue)
{  return (queue->size == queue->capacity);  }

int isEmpty(struct Queue* queue)
{  return (queue->size == 0); }

void push(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int pop(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}



char grid[MAX][MAX];
int d[MAX][MAX][3], R, C;
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

void findstart(int *r, int *c) {
	int i, j;
	*r = *c = -1;
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			if(grid[i][j]=='H') {
				*r = i, *c = j;
				return;
			}
		}
	}
}

int inside(int a, int b, int c) {
	return (a <= b && b <= c);
}

int bfs(int r, int c) {
	if(r==R-1 || r==0 || c==0 || c==C-1) return 0;
	int i, rr, cc, fl, now;

    struct Queue* q = createQueue(1000);
	push(q,r), push(q,c), push(q,0);

	d[r][c][0] = 0;

	while(!isEmpty(q)) {

		r = pop(q);
		c = pop(q);
		fl = pop(q);

		for(i = 0; i < 4; i++) {

			rr = r + dr[i];
			cc = c + dc[i];
			if(inside(0,rr,R-1) && inside(0,cc,C-1) && grid[rr][cc] != 'W') {
				if(fl != 1 && grid[rr][cc]=='M') continue;
				if(rr==0 || rr==R-1 || cc==0 || cc==C-1) return d[r][c][fl] + 1;
				if(grid[rr][cc] == 'D') now = 1;
				else if(grid[rr][cc] == 'A') now = 2;
				else now = fl;
				if(d[rr][cc][now] > d[r][c][fl] + 1) {
					push(q,rr), push(q,cc), push(q,now);
					d[rr][cc][now] = d[r][c][fl] + 1;
				}
			}
		}
	}
	return -2;
}

int main() {
	int i, r, c, ret;
	scanf("%d %d", &R, &C);

    for(i = 0; i < R; i++)
        scanf("%s", grid[i]);

    memset(d, 127, sizeof(d));
    findstart(&r, &c);
    printf("%d\n", bfs(r, c) + 1);

	return 0;
}
