/************************************************************************
 * @file: Do not edit
 * @author: xxx
 * @brief: xxx
 * @version: 1.0.0
 * @LastEditTime: 2021-09-01 23:11:51
 * @attention: Do not edit
 *************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h> 

#include "iot_list.h"

struct test_list_s {
    IOT_LIST_HEAD_T head;
    uint32_t node_num;
};

typedef struct test_node_s {
    IOT_LIST_HEAD_T node;
    char data[64];
}NODE_T;

static struct test_list_s list1 = {0};

int main(int argc, char *argv[])
{
    INIT_LIST_HEAD(&list1.head);

    for (size_t i = 0; i < 10; i++){
        NODE_T *new_node = (NODE_T *)malloc(sizeof(NODE_T));
        if(new_node == NULL){
            printf("malloc failure\n");
            exit(1);
        }
        memset(new_node, 0, sizeof(NODE_T));
        snprintf(new_node->data, sizeof(new_node->data)-1,"base:%p node:%p data:%p",\
            new_node,&new_node->node,new_node->data);
        iot_list_add(&new_node->node,&list1.head);
        list1.node_num++;
    }

    printf("list node num: %d\n",list1.node_num);

    IOT_LIST_HEAD_T *pos = NULL;
    NODE_T *entry = NULL;
    IOT_LIST_FOR_EACH(pos,&list1.head){
        entry = IOT_LIST_ENTRY(pos,NODE_T,node);
        printf("node data: %s\n",entry->data);
    }

    return 0;
}
