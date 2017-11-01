#include "head.h"


/*void print_data{{{*/
void print_data(double *x,int n)
{
   for(int i = 0;i < n;i++)
   {
       printf("%lf ",x[i]);
       
   }
   printf("\n");
   
}
/*}}}*/
/*void get_data{{{*/
void get_data(double *x,double *y,int n)
{

    FILE *fp;
    fp= fopen("data.txt","r");
    assert(fp != NULL);

    for(int i = 0;i < n;i++)
    {
        fscanf(fp,"%lf%lf",x+i,y+i);
        
    }
    
    fclose(fp);

}
/*}}}*/
/*double func{{{*/
double func(double value,double *para)
{
    return para[0]*exp(-value/para[1])+para[2];
}
/*}}}*/
/*void getDataY{{{*/
void getDataY(double *y,double *para,double *x,int n)
{
    for(int i = 0;i < n;i++)
    {
        y[i] = func(x[i],para);
    }
    
}
/*}}}*/
/*double getDiffA{{{*/
double getDiffA(double *x,double *y,double *dataY,double *para, int n)
{
    double res = 0.0;

    for(int i = 0;i < n;i++)
    {
       res += 2.0*(dataY[i] - y[i])*exp(-x[i]/para[1]);  
    }
    
    return res;

}
/*}}}*/
/*double getDiffB{{{*/
double getDiffB(double *x,double *y,double *dataY,double *para,int n)
{
    double res = 0.0;

    for(int i = 0;i < n;i++)
    {
       res += 2.0*(dataY[i] - y[i])*para[0]*exp(-x[i]/para[1])*
              x[i]/(para[1]*para[1]);  
    }
    
    return res;

}
/*}}}*/
/*double getDiffC{{{*/
double getDiffC(double *x,double *y,double *dataY,double *para,int n)
{
    double res = 0.0;

    for(int i = 0;i < n;i++)
    {
       res += 2.0*(dataY[i] - y[i]);
    }
    
    return res;

}
/*}}}*/
/*void update{{{*/
void update(double *x,double *y,double *dataY,double *para,int n,double eta)
{
    double tmp[3];

    tmp[0] = getDiffA(x,y,dataY,para,n);
    tmp[1] = getDiffB(x,y,dataY,para,n);
    tmp[2] = getDiffC(x,y,dataY,para,n);

    for(int i = 0;i < 3;i++)
    {
        para[i] -= eta*tmp[i]; 
    }
    
}
/*}}}*/
/*double checkCost{{{*/
double checkCost(double *y,double *dataY,double *para,int n)
{
    double cost = 0.0;

    double tmp;
    for(int i = 0;i < n;i++)
    {
        tmp = (dataY[i] - y[i]);
        cost +=  tmp*tmp;
    }

    return cost;
    
}
/*}}}*/
/*void run{{{*/
void run(double *x,double *y,int n)
{
    double para[3] = {1.0,- 20,1.0};

    double *dataY;
    dataY = (double *)malloc(sizeof(double)*n);

    double cost ;
    int freq = 200000;
    int cycles = 10000000;
    double eta = 1E-2;
    int i = 0;
    while (1)
    {
        i++;
        
        getDataY(dataY,para,x,n);
        update(x,y,dataY,para,n,eta);

        if ( cycles%freq ==  0  )
        {

            cost = checkCost(y,dataY,para,n);
            printf("parameters: %lf,%lf,%lf\n",para[0],para[1],para[2]);
            printf("%d ,cost is %lf\n",i,cost);
            if ( cost < 2E-2 )
            {
                eta = 1E-3;
            }
            else if ( cost < 2E-3 )
            {
                eta = 1E-4;
            }

        }
        
    }
    print_data(y,n);
    print_data(dataY,n);
    


    free(dataY);
}
/*}}}*/
/*void test{{{*/
void test(double *x,double *y,int n)
{
    print_data(x,n);
    print_data(y,n);
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    double *x,*y;
    int n  = 4;


    x = (double *)malloc(sizeof(double)*n);
    y = (double *)malloc(sizeof(double)*n);

    get_data(x,y,n);

    run(x,y,n);
    free(x);
}
/*}}}*/

