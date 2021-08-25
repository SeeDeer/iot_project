/************************************************************************
 * @file: Do not edit
 * @author: xxx
 * @brief: xxx
 * @version: 1.0.0
 * @LastEditTime: 2021-08-25 22:24:04
 * @attention: https://zhuanlan.zhihu.com/p/42541704
 *************************************************************************/

#if 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  

#include "os_time.h"
#include "os_alg_data_sort.h"

#define TEST_DATA_SIZE  (1024 * 500)

int test_data[TEST_DATA_SIZE];

static void __print_all_array(int array[],int length);

int main(int argc, char **argv)
{
    TIME_POSIX_T start_time,cost_time;

    memset(test_data, 0, sizeof(test_data));
    srand((int)os_time_get_cur_posix_ms());

    int i = 0,j = 0;
    printf("开始生成若干个随机数:\n");
    for (i = 0; i < sizeof(test_data)/sizeof(test_data[0]); i++){
        test_data[i] = rand() % 100;
    }
    int data_size = i;
    printf("\n生成了 %d 个随机数. \n",i);

    // printf("开始排序随机数集合, 冒泡排序法：\n");
    // start_time = os_time_get_cur_posix_ms();
    // os_alg_bubble_sort(test_data,data_size,DN_ORDER_SORT);
    // cost_time = os_time_get_cur_posix_ms()-start_time;
    // printf("冒泡排序完成，花费时间 %d ms\n",cost_time);

    printf("开始排序随机数集合, 堆排序法：\n");
    start_time = os_time_get_cur_posix_ms();
    os_alg_heap_sort(test_data,data_size,UP_ORDER_SORT);
    cost_time = os_time_get_cur_posix_ms()-start_time;
    printf("堆排序完成，花费时间 %d ms\n",cost_time);
    // __print_all_array(test_data,data_size);

    printf("开始排序随机数集合, 冒泡排序法：\n");
    start_time = os_time_get_cur_posix_ms();
    os_alg_bubble_sort(test_data,data_size,UP_ORDER_SORT);
    cost_time = os_time_get_cur_posix_ms()-start_time;
    printf("冒泡排序完成，花费时间 %d ms\n",cost_time);

    // __print_all_array(test_data,data_size);

    return 0;
}

static void __print_all_array(int array[],int length)
{
    printf("\n************开始打印数组所有元素：\n");
    int i;
    for (i = 0; i < length; i++)
    {
        printf("%d \n",array[i]);
    }

    printf("\n************数组元素打印结束，总数量：%d \n",i);
}

#endif
