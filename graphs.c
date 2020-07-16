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
