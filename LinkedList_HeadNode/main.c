//
//  main.c
//  LinkedList_HeadNode
//
//  Created by chenyufeng on 16/2/28.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

/**
 *  初始化、创建一个带头结点的单链表
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elemType;
typedef struct NodeList{

    int element;
    struct NodeList *next;
}Node;

//初始化带头结点的单链表
void InitialList(Node **pNode){

    *pNode = (Node *)malloc(sizeof(Node));
    (*pNode)->next = NULL;
    printf("%s函数执行，带头结点的单链表初始化完成\n",__FUNCTION__);
}

//创建带头结点的单链表
void CreateList(Node *pNode){

    Node *pInsert;
    Node *pMove;
    pInsert = (Node *)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->next = NULL;

    scanf("%d",&(pInsert->element));
    pMove = pNode;
    while (pInsert->element > 0) {

        pMove->next = pInsert;
        pMove = pInsert;

        pInsert = (Node *)malloc(sizeof(Node));
        memset(pInsert, 0, sizeof(Node));
        pInsert->next = NULL;

        scanf("%d",&(pInsert->element));
    }

    printf("%s函数执行,带头结点的单链表创建成功\n",__FUNCTION__);
}

int main(int argc, const char * argv[]) {

    Node *pList;

    InitialList(&pList);






    return 0;
}




