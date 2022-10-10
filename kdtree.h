#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
// #include 'csv_reader.h'
#define DIMENSION 2
#define DELIMITER ","
typedef struct record{
    char property_name[500];
    char property_id[100];
    char property_type[100];
    char address[500];
    char city[100];
    char state[100];
    char country[100];
    char hotel_category[100];
      
    int hotel_star;
    double coordinates[2];
    
}record;



typedef struct node{
     record * data;
    // int point[2];
    struct node *  right , * left;
    
}node;

typedef node *  kdTree;
void init_kdTree(kdTree * t);

kdTree fileopen(FILE *fp , kdTree *root);
void print(record *d);

// 
// void insert(kdTree *root , record * value);
void  insert(kdTree *root ,  record * value);
void traverse(kdTree t);
