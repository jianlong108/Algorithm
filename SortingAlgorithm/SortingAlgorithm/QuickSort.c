//
//  QuickSort.c
//  SortingAlgorithm
//
//  Created by 大龙 on 2017/2/13.
//  Copyright © 2017年 JL.Com. All rights reserved.
//

#include "QuickSort.h"
#include <time.h>
#include <stdlib.h>



void freeListNum(){
//    free(list);
}
int* getRandomList()
{
    
    static int list[10];
    srand((int)time(NULL));
    
    //每次执行种子不同，生成不同的随机数
    for(int i=0; i<10; i++)
    {
        //因为执行太快，不到一秒钟，10个随机数是相通的，但是每次执行是不同的
        list[i]=rand()%100;
        
        printf("%d\n", list[i]);
        
    }
    return list;
}

#pragma mark - 从小到大排序
/**
 从小到大排序
 
 @param list 排序的数组
 @param left 左指针
 @param right 右指针
 */
int Division(int *list, int left, int right)
{
    //首先挑选一个基准元素
    int baseNum = list[left];
    
    while (left < right)
    {
        //从数组的右端开始向前找，一直找到比base小的数字为止(包括base同等数)
        while (left < right && list[right] >= baseNum)
            right = right - 1;
        
        //最终找到了比baseNum小的元素，要做的事情就是此元素放到base的位置
        list[left] = list[right];
        
        //从数组的左端开始向后找，一直找到比base大的数字为止（包括base同等数）
        while (left < right && list[left] <= baseNum)
            left = left + 1;
        
        
        //最终找到了比baseNum大的元素，要做的事情就是将此元素放到最后的位置
        list[right] = list[left];
    }
    //最后就是把baseNum放到该left的位置
    list[left] = baseNum;
    
    //最终，我们发现left位置的左侧数值部分比left小，left位置右侧数值比left大
    //至此，我们完成了第一篇排序
    return left;
}

#pragma mark - 从大到小排序

int Re_Division(int *list, int left, int right)
{
    //首先挑选一个基准元素
    int baseNum = list[left];
    
    while (left < right)
    {
        //从数组的右端开始向前找，一直找到比base小的数字为止(包括base同等数)
        while (left < right && list[right] <= baseNum)
            right = right - 1;
        
        //最终找到了比baseNum小的元素，要做的事情就是此元素放到base的位置
        list[left] = list[right];
        
        //从数组的左端开始向后找，一直找到比base大的数字为止（包括base同等数）
        while (left < right && list[left] >= baseNum)
            left = left + 1;
        
        
        //最终找到了比baseNum大的元素，要做的事情就是将此元素放到最后的位置
        list[right] = list[left];
    }
    //最后就是把baseNum放到该left的位置
    list[left] = baseNum;
    
    //最终，我们发现left位置的左侧数值部分比left小，left位置右侧数值比left大
    //至此，我们完成了第一篇排序
    return left;
}

void QuickSort(int *list, int left, int right,_Bool Descending)
{
    //左下标一定小于右下标，否则就超越了
    if (left < right)
    {
        int i;
        //对数组进行分割，取出下次分割的基准标号
        if (Descending) {
            i = Re_Division(list, left, right);
        }else{
            i = Division(list, left, right);
        }
        
        //对“基准标号“左侧的一组数值进行递归的切割，以至于将这些数值完整的排序
        QuickSort(list, left, i - 1,Descending);
        
        //对“基准标号“右侧的一组数值进行递归的切割，以至于将这些数值完整的排序
        QuickSort(list, i + 1, right,Descending);
    }
}




