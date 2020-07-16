#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#define V 50 
#define KOR 7
#define ADJSIZE 50

typedef struct graphs{
    
    int number_of_node_with_facility;
    int djkstra_result_per_facility[KOR];
    double payoffV;
    double payoffV2;
    double payoffV3;
    int distu2[KOR];
    bool nashv;
    bool nashu;

}graphs;


void dynamicpayoff2(graphs *pla,int n,int facilities,int a[facilities][n]){//dynamicpayoff2 start
    int i,k,j,min,line,repeat=0,total_repeat=1,size=0;    
double players[facilities];
 
int spc[n];//smaller numbers per column
int repeats[n];//how many times is the smallest number repeated

//find the smaller values in the array and 
for(i=0;i<n;i++){
    min=a[0][i];
      for(k=0;k<facilities;k++){
                
           if(a[k][i]<=min){
       
                    min=a[k][i];  
                    
                    line=k;  
                    repeat++; 
                    total_repeat++;
                
                         }  
                       }
                       spc[i]=min;
                       repeat=0;
      
      }
      
       for(i=0;i<n;i++){
      repeats[i]=0;
  }    
  
  
   for(k=0;k<facilities;k++){ 
 for(i=0;i<n;i++){
     
     if(spc[i]==a[k][i]){
         repeats[i]++;
     }  
}
}
     
     //sum the size of all the repeats
for(i=0;i<n;i++){
 
  size+=repeats[i];
  }  
  
  for(i=0;i<facilities;i++){
      players[i]=0;
  }  


 for(i=0;i<n;i++){ 
 for(k=0;k<facilities;k++){
     
     if(spc[i]==a[k][i]){
         players[k]+=1.0/((double)repeats[i]);
     }  
      
}
}
   for(i=0;i<facilities;i++){
  pla[i].payoffV    =players[i];
  
  }    
  
      printf("\n\n");
    printf("\nPayoff Matrix for this scenario:");    
    printf("\n");
    printf("\n===============================");
    
    for(i=0;i<facilities;i++){
    
    printf("\n=  pl1(%d)   =  %f    ",pla[i].number_of_node_with_facility,pla[i].payoffV);
    printf("\n===============================");
}
     
}//DYNAMICpayoff2 END


int minDistance(int dist[], int sptSet[],int size)
{//minDistance start
   int min = INT_MAX, min_index;
   int v;
   for (v = 0; v < size; v++)
     if (sptSet[v] == 0 && dist[v] <= min)
         min = dist[v], min_index = v;
 
   return min_index;
}//minDistance end

void dijkstra(int dist[V],int graph[V][V], int src,int size)
{//djkstra start
     int sptSet[size];
     int i;
     for (i = 0; i < size; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;

     dist[src] = 0;
     int count;
     for (count = 0; count < V-1; count++)
     {
       int u = minDistance(dist, sptSet,size);
       sptSet[u] = 1;
    int v;
       for (v = 0; v < size; v++)
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];

     }

}//djkstra end

void alternativepayoffu(graphs *pla,int n,int facilities,int a[facilities][n],int newthesis[facilities])
{
int i,k,j,min,line,repeat=0,total_repeat=1,size=0;    
double players[facilities];
 
int spc[n];//smaller numbers per column
int repeats[n];//how many times is the smallest number repeated

for(i=0;i<n;i++){
    min=a[0][i];
      for(k=0;k<facilities;k++){
                
           if(a[k][i]<=min){
        
                    min=a[k][i];  
                    
                    line=k;  
                    repeat++; 
                    total_repeat++;
                
                         }  
                       }
                       spc[i]=min;
                       repeat=0;
      
      }

for(i=0;i<n;i++){
      repeats[i]=0;
  }    

 for(k=0;k<facilities;k++){ 
 for(i=0;i<n;i++){
     
     if(spc[i]==a[k][i]){
         repeats[i]++;
     }  
}
}

 //sum the size of all the repeats
for(i=0;i<n;i++){
 
  size+=repeats[i];
  }  
  
  for(i=0;i<facilities;i++){
      players[i]=0;
  }  


 for(i=0;i<n;i++){ 
 for(k=0;k<facilities;k++){
     
     if(spc[i]==a[k][i]){
         players[k]+=1.0/((double)repeats[i]);
     }  
      
}
}

for(i=0;i<facilities;i++){
  pla[i].payoffV2    =players[i];
  
  }
  
  
 printf("\n\n");
    printf("\nPayoff Matrix for this scenario:");    
    printf("\n");
    printf("\n===============================");
    
    for(i=0;i<facilities;i++){
    
    printf("\n=  player(%d) on node (%d)  =  %f    ",(i+1),newthesis[i],pla[i].payoffV2);
    printf("\n===============================");
}

    }


