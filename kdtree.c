#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "kdtree.h"
// #include "csv_reader.h"



void init_kdTree(kdTree * root){
    
    (*root) = NULL;
    return;   
}

kdTree recursive_insert(kdTree root , record * data , int depth);    

void  insert(kdTree  *root , record * data){
    
     
    *root =  recursive_insert(*root,data,0);
    return;
}

kdTree fileopen(FILE *fp, kdTree *root )

{


    // Substitute the full file path
    // for the string file_path
 
        
        char line [1024];
        char *data;
        
        
        while (fgets(line,1024, fp)) {
        // printf("\n%s",line);
        record *d = (record *)malloc(sizeof(record));
 
       data = strtok(line,DELIMITER);
	   strcpy( d->property_name,data); 

           data = strtok(NULL,DELIMITER);
           strcpy( d->property_id,data);
           
	   data = strtok(NULL,DELIMITER);
           strcpy( d->property_type,data);
           
 	   data = strtok(NULL,DELIMITER);
            strcpy( d->address,data);
          
	   
           
	   data = strtok(NULL,DELIMITER);
            strcpy( d->city,data);

	   data = strtok(NULL,DELIMITER);
           strcpy( d->state,data);

           data = strtok(NULL,DELIMITER);
           strcpy( d->country,data);

           data = strtok(NULL,DELIMITER);
           strcpy( d->hotel_category,data);

           
	   data = strtok(NULL,DELIMITER);
           d->hotel_star = atoi(data);
           
	   data = strtok(NULL,DELIMITER);
           d->coordinates[0] = atof(data);
           data = strtok(NULL,DELIMITER);
           d->coordinates[1] = atof(data);
           
           
      		
           insert(root,d);
        
	}

    return *root;
	
        
         

}
void print(record * d){
	
    	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    	printf("|");
    	printf("    HOTEL NAME     |   HOTEL TYPE   |    \tADDRESS\t     |  CITY  |  STATE  |  COUNTRY  |  HOTEL CATEGORY  |   HOTEL STAR  |  LATITIDE  |  LONGITUDE  |\n");
    	printf("|\n|");
	printf(" %s ||",d->property_name);
	//printf("%s \n",d->property_id);
	printf(" %s ||",d->property_type);
	printf("%s||",d->address);
	
	printf(" %s ||",d->city);
	printf(" %s ||",d->state);
	printf(" %s  ||",d->country);
	printf(" %s ||",d->hotel_category);
	
	
	printf(" %d ||",d->hotel_star);
	printf(" %f ||",d->coordinates[0]);
	printf(" %f |\n",d->coordinates[1]);
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");
       printf("\n\n");





}


      
kdTree recursive_insert(kdTree root ,record * data, int depth){
    
    kdTree nn  = (kdTree)malloc(sizeof(node));
    nn->data = data;
    
    nn->right = nn->left = NULL;
    if(root == NULL){
      root = nn;
    }
    
    
    int level = depth %  DIMENSION;
    
    
    double diff = (data->coordinates)[level] - (root->data->coordinates)[level];     
    
    if(diff < 0) 
      
      root->left = recursive_insert(root->left, data , depth + 1);           
    else if(diff > 0)
   
      root->right = recursive_insert(root->right, data, depth + 1);          
    
    return root;

    
    
}


void traverse(kdTree t){
    if(t == NULL){
        return;
        printf(" null ");
    }
    else{
    traverse(t->left);
    print(t->data);
    traverse(t->right);
    }

}
