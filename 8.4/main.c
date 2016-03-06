//
//  main.c
//  8.4
//
//  Created by zph on 16/3/6.
//  Copyright © 2016年 zph. All rights reserved.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int * ReadDate(char filename[])
{
    int i = 0;
    int r[20000];
    FILE *fp;
    int result = 0;
    char StrLine[8];             //每行最大读取的字符数
    if((fp = fopen(filename,"r")) == NULL) //判断文件是否存在及可读
    {
        printf("error!");
        return -1;
    }
    while (!feof(fp))
    {
        fgets(StrLine,6,fp);  //读取一行
        //printf("%s", StrLine);
        result=atoi(StrLine);
        if(result!=0)
        {
           r[i] =result;
            i++;
        }
        
    }
    fclose(fp);
    //关闭文件
    printf("success\n");
    return r;
}

int max(int a, int b)
{
    return a>b?a:b;
}

int MaxSubsequence(int n,int x[])
{
    
    int maxsofar = 0;
    int maxendinghere = 0;
    for( int i =0;i < n ;i++)
    {
        maxendinghere = max(maxendinghere + x[i], 0);
        maxsofar = max(maxsofar,maxendinghere);
    }
    return  maxsofar;
}

int main(int argc, const char * argv[])
{
    clock_t start_time, end_time;
    double  duration_time;
    start_time=clock();

    //int a[] = {-2,11,-4,13,-5,-2};
    //printf("%d\n",MaxSubsequence(6,a));
    
    int *p;
    //int i;
    p = ReadDate("/Users/zph/XcodeProject/编程珠玑/8.4/8.4/data.txt");
    //for ( i = 0; i < 10; i++ )
    //{
    //    printf( "*(p + %d) : %d\n", i, *(p + i));
    //}
    printf("%d\n",MaxSubsequence(10000,p));
    
    end_time = clock();
    duration_time = (double)(end_time-start_time) / CLOCKS_PER_SEC;
    printf( "duration: %lf seconds\n", duration_time );
    return 0;
}

