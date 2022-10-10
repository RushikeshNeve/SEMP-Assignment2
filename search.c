#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "search.h"
#define size 5
// #include 'csv_reader.h'
double calc_dist(double root_x, double root_y, double key_x, double key_y) {
    double dist;
    dist = sqrt(pow(root_x - key_x, 2) + pow(root_y - key_y, 2));
    return dist;
}


void recursive_NN_search(kdTree root, double key_coordinate[],double *nearest_dist, kdTree *nearest_node,int depth);
void recursive_NN_search(kdTree root, double key_coordinate[],double *nearest_dist, kdTree *nearest_node,int depth) {
    
    
	if (root) {
        
        double coordinates[2];
        // int coordinates[2];
        coordinates[0] = root->data->coordinates[0];
        coordinates[1] = root->data->coordinates[1];
    //   coordinates[0] = root->point[0];
    //   coordinates[1] = root->point[1];
        
        double curr_dist = calc_dist(coordinates[0], coordinates[1],key_coordinate[0], key_coordinate[1]);

        int level = depth % DIMENSION;

        double dim_dist = coordinates[level] - key_coordinate[level];
        
        if (curr_dist <= *nearest_dist) {
            *nearest_dist = curr_dist;
            *nearest_node = root;
        }
        
        if (dim_dist > 0) {
            /* Positive dim_dist indicates the current coordinate is to the 
                right of the key coordinate so search the left child instead */
            recursive_NN_search(root->left, key_coordinate, nearest_dist,
                                      nearest_node, depth + 1);
            
            if (dim_dist < *nearest_dist) {
                /* However, if the current coordinate lies inside the radius of
                    the nearest distance, searrecursive_NN_searchch right child as well */
                recursive_NN_search (root->right, key_coordinate, 
                                          nearest_dist, nearest_node, 
                                          depth + 1);
            }
        } else {
            /* Similar to the previous case but in opposite direction */
            recursive_NN_search(root->right, key_coordinate, 
                                          nearest_dist, nearest_node, 
                                          depth + 1);
            
            if (fabs(dim_dist) < *nearest_dist) {
                recursive_NN_search(root->left, key_coordinate, nearest_dist,
                                      nearest_node, depth + 1);
            }
        }
   }
}

/* Traverse the KD tree and find the nearest point to the given input 
    coordinate */
// record * nearest_neighbour_search_tree(kdtree root,  double coordinates[])    for record
kdTree nearest_neighbour_search_tree(kdTree root,  double coordinates[]) {
	if(root == NULL)
	    return NULL;
   
    
    double root_coordinates[2];
        
    root_coordinates[0] = root->data->coordinates[0];
    root_coordinates[1] = root->data->coordinates[1];
    /* Initialise the nearest distance with the distance between the key
        coordinate and the root coordinate */
    double nearest_dist;
     nearest_dist = calc_dist(root_coordinates[0], root_coordinates[1],
                                    coordinates[0], coordinates[1]);
    kdTree nearest_node = NULL;
    
    recursive_NN_search(root, coordinates, &nearest_dist,
                              &nearest_node,0);
    
    return nearest_node;
}

void recursive_radius_search(kdTree root, double key_coordinates[], double radius,int depth);
void recursive_radius_search(kdTree root, double key_coordinates[], double radius,int depth){
   if(root){
	double coordinates[2];
       
        coordinates[0] = root->data->coordinates[0];
        coordinates[1] = root->data->coordinates[1];
        
	        
        double curr_dist=calc_dist(coordinates[0],coordinates[1],key_coordinates[0],key_coordinates[1]);  

        int level = depth % DIMENSION;

        double dim_dist = coordinates[level] - key_coordinates[level];
        if (curr_dist <= radius) {
 
           print(root->data);           
            
        }
        
        if(dim_dist > 0){
         	recursive_radius_search(root->left,key_coordinates,radius,0);
        }
        else{
        	recursive_radius_search(root->right,key_coordinates,radius,0);
        }
   }     
}


void radius_search_tree(kdTree root,double key_coordinates[],double radius){
	if(root == NULL)
		return;
	
	
	recursive_radius_search(root,key_coordinates,radius,0);
	return;
	
}
void recursive_search_in_city(kdTree root,char city[],int depth);
void recursive_search_in_city(kdTree root,char city[],int depth){
	

}
void search_in_city(kdTree root,char city[]){
	if(root == NULL)
		
		return;
	
	if(!strcmp(root->data->city,city)) 
		print(root->data);
	search_in_city(root->left, city);
	search_in_city(root->right, city);
	
	
} 


