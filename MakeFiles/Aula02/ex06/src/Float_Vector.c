#include "Float_Vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct float_vector{
    int capacity;
    int size;
    float *data;
} ;

bool isfull(const floatVector *vec){
    return (vec->size == vec->capacity);
}

floatVector *create(int capacidade){
    floatVector *vec = (floatVector *) malloc(sizeof(floatVector));
    vec->capacity=capacidade;
    vec->size=0;
    vec ->data= (float *) malloc(capacidade * sizeof(float));
    return vec;
}
void destroy(floatVector **vecRef){
    floatVector *vec = *vecRef;
    free(vec->data);
    free(vec);
    *vecRef = NULL;
}
int size(const floatVector *vector){
    return vector->size;
}
int capacity(const floatVector *vector){
    return vector->capacity;
    
}
float at(const floatVector *vec, int index){
    if(index < 0 || index >=vec->size){
        printf("Index errado");
        exit(EXIT_FAILURE);
    }
    return vec->data[index];
}
float get(const floatVector *vec, int index){
    return vec->data[index];
}

void append(floatVector *vec, float val){
    if(isfull(vec)){
        printf("Vetor cheio, impossivel adicionar\n");
        exit(EXIT_FAILURE);
    }
    vec->data[vec->size] = val;
    vec->size++;
}

void set(floatVector *vec, int index, float val){
    if(index < 0 || index >=vec->size){
        printf("Index errado");
        exit(EXIT_FAILURE);
    }
    vec->data[index]=val;
}
void print(const floatVector *vec){
    printf("Size: %d\n",vec->size);
    printf("Capacity: %d\n\n",vec->capacity);

    for(int i=0;i<vec->size;i++){
        printf("[%d] = %f\n",i,vec->data[i]);
    }
    printf("\n");

}

void floatVec_remove(const floatVector *vec,int index){
    if(index < 0 || index >=vec->size){
        printf("Index errado");
        exit(EXIT_FAILURE);
    }
    for(int i=vec->data[index];i<vec->size-1;i++){
        vec->data[i]=vec->data[i+1];
    }
    
}
