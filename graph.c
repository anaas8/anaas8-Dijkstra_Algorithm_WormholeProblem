#include "graph.h"

void creategraph(Graph *pg)
{
    for (int i =0 ; i<maxvertex; i++)
    {
        pg->entry[i].firstedge=NULL;
    }
    pg->n=0;
    pg->E=0;

}

int findindex(Graph *pg,graphentry point)
{
    for(int i=0; i< pg->n; i++)
    {
        if (strcmp(pg->entry[i].entry,point)==0)
        {
            return i ;
        }
    }
}
int dijkstra(Graph *pg,graphentry sourcename,graphentry targetname )
{
    int start= findindex(pg,sourcename);
    int target= findindex(pg,targetname);
    Edge *t = pg->entry[start].firstedge;
    int dist[pg->n],prev[pg->n],i,m,min,d,j=0;
    int selected[pg->n];
    graphentry path[pg->n];
    for(i=0; i< pg->n ; i++)  //complexity O(v)
    {
        dist[i] = IN;
        prev[i] = -1;
        selected[i]=0;
    }
    selected[start]=1;
    dist[start] = 0;

    while(!selected[target]&& j++ !=pg->n)//complexity sO(v) path on all Vertexes
    {
        min = IN;
        m = 1;
        while(t)  //complexity O(v-1) in case of complete graph
        {
            i=t->endpoint;
            d = dist[start] +t->cost;
            if(d< dist[i]&&(selected[i]==0))
            {
                dist[i] = d;
                prev[i] = start;
            }
            if(min>dist[i] && (selected[i]==0))
            {
                min = dist[i];
                m = i;
            }

            t=t->nextedge;
        }
        start = m;
        t=pg->entry[start].firstedge;
        selected[start] =1;
    }
    if (selected[target]){
        pathshow(pg,prev,path,target);
    }else{
       printf("\t\t\t\tthe target is isolated planet for your location");
    }

    return dist[target];
}

void pathshow(Graph *pg,int *prev,graphentry *path,int start ){

    int j=0;
    while(start != -1) //complexity O(v)
    {
        strcpy(path[j++],pg->entry[start].entry);
        start = prev[start];
    }

    printf("\t\t\t\tthe best path from %s",path[--j]);
    for(int i = j-1 ; i>=0; i--)
    {
        printf(" --to--> %s",path[i]);
    }

}

void AddEdge(Graph *pg,int startpoint,int endpoint,int cost)
{

    Edge *t = (Edge*)malloc(sizeof(Edge));
    t->endpoint=endpoint;
    t->cost=cost;

    Edge *q = (Edge*)malloc(sizeof(Edge));
    q->endpoint=startpoint;
    q->cost=cost;

    t->nextedge=pg->entry[startpoint].firstedge;
    pg->entry[startpoint].firstedge=t;
    q->nextedge=pg->entry[endpoint].firstedge;
    pg->entry[endpoint].firstedge=q;
    pg->E+=2;

}
void removeEdge(Graph *pg, graphentry start,graphentry end)
{
    int temp;
    int startpoint = findindex(&pg,start);
    int endpoint = findindex(&pg,end);
    for (int i=0; i<2; i++)
    {
        Edge *q=pg->entry[startpoint].firstedge;
        Edge *t;
        while(q->nextedge->endpoint != endpoint)
            q=q->nextedge;

        t=q->nextedge;
        q->nextedge=q->nextedge->nextedge;
        free(t);

        temp = startpoint;
        startpoint = endpoint ;
        endpoint = temp;
    }
 pg->E-=2;
}

void AddVertex(Graph *pg, int i,graphentry name)
{
    strcpy(pg->entry[i].entry,name);
    pg->n++;
}

void removeVertex(Graph *pg, graphentry vertex)
{
    int vertec_index=findindex(&pg,vertex);
    Edge *q=pg->entry[vertec_index].firstedge;
    while(q)
    {
        removeEdge(&pg,pg->entry[vertec_index].entry,pg->entry[q->endpoint].entry);
        q=q->nextedge;
    }
    pg->n --;
}
