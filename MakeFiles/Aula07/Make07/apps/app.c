#include "Float_Vector.h"
#include <stdio.h>


int main(){
    floatVector *vec=create(10);
    print(vec);
    for(int i=0;i<10;i++)
        append(vec,i);
    print(vec);  
    destroy(&vec);
    return 0;
}