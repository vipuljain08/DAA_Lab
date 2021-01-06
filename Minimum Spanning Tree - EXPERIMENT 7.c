#define infinity 9999
#define MAX 20
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
int G[MAX][MAX],spanning[MAX][MAX],n;
void prims();
void kruskal();
void main()
{
	int i,j,op;
	clrscr();
	do {
	    printf("\n\n1)Create\n2)Prim's\n3)Kruskal\n4)Quit");
	    printf("\nEnter Your Choice : ");
	    scanf("%d",&op);
	    switch(op)
	     { case 1:
		      printf("\nEnter No. of vertices : ");
		      scanf("%d",&n);
		      printf("\nEnter the adjacency matrix :");
		      for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			  scanf("%d",&G[i][j]);
		       break;
		case 2: prims();break;
		case 3: kruskal();break;

	      }
	 }while(op!=4);
}
void prims()
{
	int cost[MAX][MAX];
	int u,v,min_distance,distance[MAX],from[MAX];
	int visited[MAX],no_of_edges,i,min_cost,j;
//	create cost[][] matrix ,spanning[][]
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(G[i][j]==0)
				cost[i][j]=infinity;
			else
				cost[i][j]=G[i][j];
		       spanning[i][j]=0;
		}
//	initialise visited[],distance[] and from[]
	distance[0]=0;visited[0]=1;
	for(i=1;i<n;i++)
	{
		distance[i]=cost[0][i];
		from[i]=0;
		visited[i]=0;
	}
	min_cost=0;            //cost of spanning tree
	no_of_edges=n-1;       //no.of edges to be added
	while(no_of_edges>0)
	{
		//find the vertex at minimum distance from the tree
		min_distance=infinity;
		for(i=1;i<n;i++)
			if(visited[i]==0 && distance[i] < min_distance)
			{
				v=i;
				min_distance=distance[i];
			}
		u=from[v];
		// insert the edge in spanning tree
		spanning[u][v]=distance[v];
		spanning[v][u]=distance[v];
		no_of_edges--;
		visited[v]=1;
		// update the distance[] array
		for(i=1;i<n;i++)
			if(visited[i]==0 && cost[i][v] < distance[i])
			{
				distance[i]=cost[i][v];
				from[i]=v;
			}
		min_cost=min_cost+cost[u][v];
	}

	printf("spanning tree Edges(Prims) : \n");
	for(i=0;i<n;i++)
	 for(j=i+1;j<n;j++)
	    if(spanning[i][j] != 0)
	       printf("\n%d - %d cost= %d",i,j,spanning[i][j]);
	printf("\nTotal cost of spanning tree=%d",min_cost);
}

/**** Functions and structures used for Kruskal's Algorithm */
typedef struct edge
{ int u,v,w;
}edge;

typedef struct edgelist
 { edge data[30];
   int n;
 }edgelist;
edgelist elist,spanlist;
int find(int belongs[],int vertexno);
void sort();
void union1(int belongs[],int c1,int c2);
void print();
void kruskal()
{  int belongs[MAX],i,j,cno1,cno2;
   /*create a list of edges */
   elist.n=0;
   for(i=0;i<n;i++)
     for(j=0;j<n;j++)
       if(G[i][j]!=0)
	 { elist.data[elist.n].u=i;
	   elist.data[elist.n].v=j;
	   elist.data[elist.n].w=G[i][j];
	   elist.n++;
	 }
   sort();
 // create the spanning tree with n components
 for(i=0;i<n;i++)
  belongs[i]=i;
 spanlist.n=0;
 // add edges one by one to spanning tree
 for(i=0;i<elist.n;i++)
  { cno1=find(belongs,elist.data[i].u);
    cno2=find(belongs,elist.data[i].v);
    if(cno1 != cno2) // if the edge does not cause a cycle
      { spanlist.data[spanlist.n++]=elist.data[i];
	union1(belongs,cno1,cno2);
      }
   }
 //print the spanning tree
  print();
}

int find(int belongs[] ,int vertexno)
 { return(belongs[vertexno]);
 }

void union1(int belongs[], int c1 , int c2)
 { int i;
   for(i=0;i<n;i++)
    if(belongs[i]==c2) // merge two components
      belongs[i]=c1;
 }
void sort()
 { int i,j;
   edge temp;
   for(i=1;i<elist.n;i++)
     for(j=0;j<elist.n-i;j++)
       if(elist.data[j].w > elist.data[j+1].w)
	  { temp=elist.data[j];
	    elist.data[j]=elist.data[j+1];
	    elist.data[j+1]=temp;
	  }
  }

void print()
 { int i,cost=0;
   for(i=0;i<spanlist.n;i++)
     { printf("\n%d - %d cost= %d",spanlist.data[i].u,spanlist.data[i].v,
				   spanlist.data[i].w);
       cost=cost+spanlist.data[i].w;
     }
   printf("\nCost of the spanning tree : %d",cost);
}
