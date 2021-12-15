/*second order differential equation */
#include <stdio.h>
#include <math.h>
#define N 40
float f(float x,float y,float y1)
{ return((x+y+y1+2.0)/2.0); }
int main(void){
    int i,n;
    float h,x[N+1],y[N+1],y1[N+1],y2[N+1],r;
    h=0.2;
    x[0]=0.0;
    y[0]=0.0;
    y1[0]=0.0;
    i=0;
    printf(" x , y ( error )\n");
    do {
        y2[i]=f(x[i],y[i],y1[i]);
        x[i+1]=x[i]+h;
        y1[i+1]=y1[i]+h*y2[i];
        y[i+1]=y[i]+h*y1[i]+h*h*y2[i]/2.0;
        i++;
        r=exp(x[i])-x[i]-1.0;
        printf("%8.5f,%8.5f (%8.5f)\n",
        x[i],y[i],r-y[i]);
    } while(x[i]<1.0&&i<N);
}