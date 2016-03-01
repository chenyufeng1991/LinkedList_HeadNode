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

//6.判断带头结点的单链表是否为空，为空则返回1，否则返回0
int IsEmptyList(Node *pNode){
    /**
     *  当只有一个头结点的时候，该链表就为空
     */
    if (pNode->next == NULL) {
        printf("%s函数执行，带头结点的链表为空\n",__FUNCTION__);
        return 1;
    }

    printf("%s函数执行，带头结点的链表非空\n",__FUNCTION__);

    return 0;
}

//7.返回单链表中第pos个结点中的元素，若返回-1，表示没有找到
int GetElement(Node *pNode,int pos){

    int i = 1;

    Node *pMove;
    pMove = pNode->next;

    while (pMove != NULL) {
        if (i == pos) {

            printf("%s函数执行，pos=%d位置的值是%d\n",__FUNCTION__,pos,pMove->element);
            return pMove->element;
        }

        i++;
        pMove = pMove->next;
    }

    printf("%s函数执行，在pos=%d位置没有找到值\n",__FUNCTION__,pos);
    return -1;
}

//8.从单链表中查找具有给定值x的第一个元素，若查找成功则返回该结点data域的存储地址，否则返回NULL
elemType* GetElemAddr(Node *pNode,int x){

    Node *pMove;
    pMove = pNode->next;

    while (pMove != NULL) {
        if (pMove->element == x) {
            printf("%s函数执行，查找到x=%d的内存地址为:0x%x\n",__FUNCTION__,x,&(pMove->element));
            return &(pMove->element);
        }
        pMove = pMove->next;
    }

    printf("%s函数执行，在带头结点的单链表中没有找到x=%d的值，无法获得内存地址\n",__FUNCTION__,x);

    return NULL;
}

//9.把单链表中第pos个结点的值修改为x的值
Node* ModifyElem(Node *pNode,int pos,int x){

    int i = 1;
    Node *pMove;
    pMove = pNode->next;
    while (pMove != NULL) {
        if (i == pos) {
            pMove->element = x;
            printf("%s函数执行，把pos=%d位置的值改为%d成功\n",__FUNCTION__,pos,x);
            return pNode;
        }
        i++;
        pMove = pMove->next;
    }
    printf("%s函数执行，链表为空或者输入pos值非法，修改值失败\n",__FUNCTION__);

    return pNode;
}


int main(int argc, const char * argv[]) {

    Node *pList;

    InitialList(&pList);

    CreateList(pList);
    PrintList(pList);

    SizeList(pList);

    IsEmptyList(pList);

    GetElement(pList, 3);

    GetElemAddr(pList, 5);

    ModifyElem(pList, 2, 111);
    PrintList(pList);

    ClearList(pList);
    PrintList(pList);

    return 0;
}














