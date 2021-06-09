#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <time.h>
int main()
{

    Graph g;
    creategraph(&g);
    graphentry startpoint,target,newstartpoint;
    int shourtpath,n;
    int w,i,j;
    //welcome to my problem
    printf("\t\t\t\t\t\twormhole problem\n");
    printf("\t\t\t The Shortest Path between two planet( DIJKSTRA'S ALGORITHM) \n\n");
    //input the number of planets
    printf("\tEnter the number of planets :  ");
    scanf("%d",&n);
    graphentry vertexs[n];
    //input the names of planets
    printf("\tEnter your vertexs names.\n");
    for(int count=0 ; count<n; count++)
    {
        printf("\tVetex[%d]:",count+1);
        scanf("%s",vertexs[count]);
        AddVertex(&g,count,vertexs[count]); // add  Vertex to graph
    }
    //inputs all time costs of wormholes
    for(i =0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(j>i)
            {

               printf("\tthe Time_cost between %s and  %s: ",vertexs[i],vertexs[j]);
               scanf("%d",&w);
                if(w!=0)
                    AddEdge(&g,i,j,w); //add edge in my graph
            }
        }
    }
    //input the start planet and target planet
   printf("graph has built\n");
    printf("\n\tEnter your source : ");
    scanf("%s",startpoint);
    printf("\tEnter your target : ");
    scanf("%s",target);
    printf("\n\n\n");

        shourtpath = dijkstra(&g,startpoint,target);//calling Dijkstra algorithm to find shortest path
        printf("\n\n\n\t\t\t\tyour path will take : %d unit of time\n ",shourtpath); //out put the minimum time cost
        //malfunction part
        printf("\n\n\t if happen malfunction press 1  or 0 if you arrived :");
        scanf("%d",&i);
        if(i)
        {
            printf("\tplease enter your location : ");
            scanf("%s",newstartpoint);
            printf("\n\n\n");
            shourtpath = dijkstra(&g,newstartpoint,target); //calling Dijkstra algorithm to find shortest path
            printf("\n\n\n\t\t\t\tyour path will take : %d unit of time ",shourtpath);//out put the minimum time cost
        }

    printf("\n\n\n\t\t\t\t\t\tthanks\n\n\n");

}
