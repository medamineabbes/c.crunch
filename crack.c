#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//b  9oua a
int power(int a,int b)
{
    int i,p;
    p=1;
    for(i=0;i<a;i++)
        p*=b;
    return p;
}

int main(int argc, char *argv[])
{
    FILE *fp;
    int i,b,*trace,numbre_char,min,c,j,max;
    char *pwd,*chara;
    char *PATH;
    if(argc<=2)
    {
    	printf("usage: crack [min length] [max length] [caractere in passwd] [file to save (optional)]\n");
    	return 0;
    }
    PATH=malloc(sizeof(char*));
    if(argc==5)
    PATH=argv[4];
    min=*argv[1]-48;
    max=*argv[2]-48;
    chara=argv[3];
    numbre_char=strlen(chara);
    if(argc==5)
    fp=fopen(PATH,"w");
    for(;min<=max;min++)
    {
        trace=malloc(sizeof(int)*min);
        pwd=malloc(sizeof(char)*min);

        for(i=0;i<min;i++)
        {
            *(pwd+i)=' ';
            *(trace+i)=1;
        }
        b=1;
        while(b)
        {
            b=0;
            for(i=0;i<min;i++)
            {
                *(pwd+i)=chara[trace[i]-1];
            }
            *(pwd+min)='\0';
            if(argc==5)
            fprintf(fp,"%s\n",pwd);
            printf("%s\n",pwd);
            for(i=0;i<min;i++)
            {
                if(trace[i]%numbre_char != 0)
                { 
                b=1;
                }
            }
            trace[min-1]++;
            c=min-1;
            while(trace[c]%(numbre_char+1)==0)
            {
                trace[c]=1;
                trace[c-1]++;
                c--;
            }
        }
    }
    return 0;
}
