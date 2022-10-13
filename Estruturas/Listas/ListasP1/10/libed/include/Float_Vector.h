#ifndef TAD1_H
#define TAD1_H

typedef struct float_vector floatVector;

floatVector *create(int capacidade);
void destroy(floatVector **vecRef);
int size(const floatVector *vector);
int capacity(const floatVector *vector);
float at(const floatVector *vec, int index);
float get(const floatVector *vec, int index);
void append(floatVector *vec, float val);
void set(floatVector *vec, int index, float val);
void print(const floatVector *vec);
void floatVec_remove(const floatVector *vec,int index);



#endif