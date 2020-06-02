#include <stdio.h>

int main(void)
{

    // variable declarations
    int i_nrl = 5;
    float f_nrl = 3.9f;
    double d_nrl = 8.041997;
    char c_nrl = 'A';
    
	//code
    printf("\n\n");
    
    printf("i_nrl = %d_nrl\n", i_nrl);
    printf("f_nrl = %f_nrl\n", f_nrl);
    printf("d_nrl = %lf\n", d_nrl);
    printf("c_nrl = %c_nrl\n", c_nrl);

    printf("\n\n");

    i_nrl = 43;
    f_nrl = 6.54f;
    d_nrl = 26.1294;
    c_nrl = 'P';
    
    printf("i_nrl = %d_nrl\n", i_nrl);
    printf("f_nrl = %f_nrl\n", f_nrl);
    printf("d_nrl = %lf\n", d_nrl);
    printf("c_nrl = %c_nrl\n", c_nrl);

    printf("\n\n");

    return(0);
}



