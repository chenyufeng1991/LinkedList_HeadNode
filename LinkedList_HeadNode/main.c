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

//1.初始化带头结点的单链表
void InitialList(Node **pNode){

    //个人建议每一次malloc分配内存空间后，都要进行判断分配是否成功，也即判断是否为空；
    //此时的这个pNode就是一个头结点；
    //初始化成功后，其实相当于是一个正常的链表了；
    *pNode = (Node *)malloc(sizeof(Node));
    if (*pNode == NULL) {
        printf("%s函数执行，内存分配失败，初始化单链表失败",__FUNCTION__);
    }else{

        (*pNode)->next = NULL;
        printf("%s函数执行，带头结点的单链表初始化完成\n",__FUNCTION__);
    }
}

//2.创建带头结点的单链表
void CreateList(Node *pNode){

    /**
     *  就算一开始输入的数字小于等于0，带头结点的单链表都是会创建成功的，只是这个单链表为空而已，也就是里面除了头结点就没有其他节点了。
     */
    Node *pInsert;
    Node *pMove;
    pInsert = (Node *)malloc(sizeof(Node));//需要检测分配内存是否成功 pInsert == NULL  ?
    memset(pInsert, 0, sizeof(Node));
    pInsert->next = NULL;

    scanf("%d",&(pInsert->element));
    pMove = pNode;
    while (pInsert->element > 0) {

        pMove->next = pInsert;
        pMove = pInsert;

        pInsert = (Node *)malloc(sizeof(Node)); //需要检测分配内存是否成功 pInsert == NULL  ?
        memset(pInsert, 0, sizeof(Node));
        pInsert->next = NULL;

        scanf("%d",&(pInsert->element));
    }

    printf("%s函数执行,带头结点的单链表创建成功\n",__FUNCTION__);
}

//3.打印带头结点的单链表
void PrintList(Node *pNode){
    /**
     *  注意这里，如果单链表为空（只有一个头结点），我也让它打印（打印成功）。只是里面没有元素，打出来是空的而已,所以在控制台上就是一行空的；
     */
        Node *pMove;
        pMove = pNode->next;
        while (pMove != NULL) {
            printf("%d ",pMove->element);
            pMove = pMove->next;
        }

        printf("\n%s函数执行，打印带头结点的单链表成功\n",__FUNCTION__);
}

//4.清除线性表中的所有元素，即释放所有节点（除了头结点），使之成为一个空表
void ClearList(Node *pNode){

    Node *pMove;
    pMove = pNode->next;
    while (pMove != NULL) {

        pNode->next = pMove->next;
        free(pMove);
        pMove = pNode->next;
    }

    printf("%s函数执行，清空带头结点的链表成功\n",__FUNCTION__);
}

//5.返回带头结点的单链表的长度
int SizeList(Node *pNode){
    /**
     *  当只有一个头结点的时候，size = 0；头节点不计算到链表长度中。
     */
    int i = 0;
    Node *pMove;
    pMove = pNode->next;
    while (pMove != NULL) {
        i++;
        pMove = pMove->next;
    }

    printf("%s函数执行，带头结点的单链表的长度为：%d\n",__FUNCTION__,i);

    return i;
}


int main(int argc, const char * argv[]) {

    Node *pList;

    InitialList(&pList);

    CreateList(pList);
    PrintList(pList);

    SizeList(pList);

    ClearList(pList);
    PrintList(pList);

    return 0;
}














