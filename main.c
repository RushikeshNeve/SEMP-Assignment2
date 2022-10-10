#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "search.h"

int main()
{   kdTree t;
    init_kdTree(&t);
    
    FILE* fp = fopen("data2.csv", "r");
 
    if (!fp)
        printf("Can't open file\n");
 
   else{ 
    t = fileopen(fp,&t);
    while(1){
        printf("\nEnter the digits to execute command\n");
        printf("1.Find Hotels Near Me. \n2.Find Hotels At Some Distance From Me.\n3.Find Hotels In My City \n4.Exit\n");
        int input;
        scanf("%d",&input);
        if(input<1 || input>5){
            printf("Enter a valid number to proceed.");
            continue;
        }

        else if(input==1){
            double coordinates[2];
            printf("For Hotels Near You  :\n");
            printf("Enter Your Location : ");
            for(int i = 0 ; i< 2 ; i++){
            	scanf("%lf",&coordinates[i]);
             }
            kdTree n  = nearest_neighbour_search_tree(t,  coordinates);
            print(n->data);
            printf("\n");
        }

        else if(input==2){
            double coordinates[2];
            printf("For Hotels Near You  :\n");
            printf("Enter Your Location : ");
            for(int i = 0 ; i< 2 ; i++){
            	scanf("%lf",&coordinates[i]);
             }
            double radius;
            printf("Enter the Radius of Search : ");
            scanf("%lf",&radius);
            radius_search_tree(t,coordinates,radius);
            printf("\n");
             
        }

        else if(input==3){
            char city[100];
            printf("For Hotels In Your City:\n");
            printf("Enter Your City Name : ");
            
            scanf("%s",city);
            search_in_city(t, city);
            
        }

        else{
            break;
        }
    }
    return 0;       
 }
}
