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

    /**
     *  就算一开始输入的数字小于等于0，带头结点的单链表都是会创建成功的，只是这个单链表为空而已，也就是里面除了头结点就没有其他节点了。
     */
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

//打印带头结点的单链表
void PrintList(Node *pNode){
    /**
     *  注意这里，如果单链表为空（只有一个头结点），我也让它打印（打印成功）。只是里面没有元素，打出来是空的而已。
     */
        Node *pMove;
        pMove = pNode->next;
        while (pMove != NULL) {
            printf("%d ",pMove->element);
            pMove = pMove->next;
        }

        printf("\n%s函数执行，打印带头结点的单链表成功\n",__FUNCTION__);
}

int main(int argc, const char * argv[]) {

    Node *pList;

    InitialList(&pList);

    CreateList(pList);
    PrintList(pList);

    return 0;
}









