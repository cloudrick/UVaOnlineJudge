
#include <string.h>
#include <stdio.h>

bool map[510][510];

struct rect
{
        int x1,x2,y1,y2;
}box;

inline void swap(int &a,int &b)
{
        int tmp;
        tmp=b;
        b=a;
        a=tmp;
}

int main()
{
        int W,H,N ;
        while(1)
        {
                scanf("%d %d %d",&W,&H,&N);
                if (H==W && H==N && N==0)
                        break;
                memset(map,0,sizeof(map));
                for (int i=1;i<=N;i++)
                {
                        scanf("%d %d %d %d",&box.x1,&box.y1,&box.x2,&box.y2);
                        if (box.x1 > box.x2)
                                swap(box.x1,box.x2);
                        if (box.y1 > box.y2)
                                swap(box.y1,box.y2);
						for (int j=box.x1 ;j<=box.x2;j++)
                        {
							memset(&map[j][box.y1],1,box.y2-box.y1+1);
                        }
                }
                int total=0;
                for(int k=1;k<=W;k++)
                {
                        for(int n=1;n<=H;n++)
                        {
                                if(map[k][n]==0)
                                        total++;
                        }
                }
                if (total==0)
                        printf("There is no empty spots.\n");
                else if (total==1)
                        printf("There is one empty spot.\n");
                else
                        printf("There are %d empty spots.\n",total);

        }
		
        return 0;
}