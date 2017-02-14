//
//  BubbleSort.c
//  SortingAlgorithm
//
//  Created by Wangjianlong on 2017/2/14.
//  Copyright © 2017年 JL.Com. All rights reserved.
//

#include "BubbleSort.h"
        
//冒泡排序算法
int* BubbleSort(int * list)
{
    int count = 0;
    while (list[count]) {
        count++;
    }
    
    int temp;
    //第一层循环： 表明要比较的次数，比如list.count个数，肯定要比较count-1次
    for (int i = 0; i < count - 1; i++)
    {
        //list.count-1：取数据最后一个数下标，
        //j>i: 从后往前的的下标一定大于从前往后的下标，否则就超越了。
        for (int j = count - 1; j > i; j--)
        {
            //如果前面一个数大于后面一个数则交换
            if (list[j - 1] > list[j])
            {
                temp = list[j - 1];
                list[j - 1] = list[j];
                list[j] = temp;
            }
        }
    }
    return list;
}
