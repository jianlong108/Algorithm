//
//  main.m
//  SortingAlgorithm
//
//  Created by 大龙 on 2017/2/13.
//  Copyright © 2017年 JL.Com. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "BubbleSort.h"
#include "QuickSort.h"


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        int *p = getRandomList();
        
        int * p_sort = BubbleSort(p);
        for (int i = 0; i < 10; i++ )
        {
            printf( "冒泡*(p + %d) : %d\n", i, *(p_sort + i));
            
        }
        
        
        for (int i = 0; i < 10; i++ )
        {
            printf( "%d,", *(p + i));
            
        }
        QuickSort(p, 0, 9,true);
        for (int i = 0; i < 10; i++ )
        {
            printf( "快排降序*(p + %d) : %d\n", i, *(p + i));
            
        }
        
        QuickSort(p, 0, 9,false);
        for (int i = 0; i < 10; i++ )
        {
            printf( "快排升序*(p + %d) : %d\n", i, *(p + i));
            
        }
    }
    return 0;
}
