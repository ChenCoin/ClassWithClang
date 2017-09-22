#include <stdio.h>
#include <stdlib.h>
#include "Class.h"

/* create class */
crtClass(
    	List
    ,(
		int value;
		struct ListData *next;
	),(
		int (*add)(int);
		int (*addIndex)(int, int);
		int (*addAll)(List);
		int (*remove)(int);
		int (*removeAll)();
		int (*get)(int);
		int (*set)(int, int);
		int (*length)();
    )
    
);

/* class func */
int checkIndex(int index){//参数检查，private
    if( index<1 || index>this(List)->value )
        return -1;
    return 0;
}

int _add(int value){
    List p = this(List);
    List item = (List)malloc(1);
    item->value = value;
    item->next = NULL;
    p->value ++;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = item;
    return 0;
}
int _addIndex(int index,int value){
    if(checkIndex(index))
        return -1;
        
    int i;
    List p = this(List);
    for(i=1; i<index; i++)
        p = p->next;
        
    List item = (List)malloc(1);
    item->value = value;
    item->next = p->next;
    
    p->next = item;
    
    this(List)->value ++;
    return 0;
}
int _addAll(List list){
    List p = this(List);
    p->value += list->value;
    while(p->next != NULL)
        p = p->next;
    p->next = list->next;
    return 0;
}
int _remove(int index){
    if(checkIndex(index))
        return -1;
    int i;
    List p = this(List);
    for(i=1; i<index; i++){
        p = p->next;
    }
    List trash = p->next;
    p->next = (p->next)->next;
    free(trash);
    this(List)->value --;
    return 0;
}
int _removeAll(){
    this(List)->value = 0;
    this(List)->next = NULL;
    return 0;
}
int _get(int index){
    if(checkIndex(index))
        return -1;
    List p = this(List);
    int i;
    for(i=0; i<index; i++){
        p = p->next;
    }
    return p->value;
}
int _set(int index,int value){
    if(checkIndex(index))
        return -1;
    List p = this(List);
    int i;
    for(i=0; i<index; i++)
        p = p->next;
    p->value = value;
    return 0;
}
int _length(){
    return this(List)->value;
}

/* init class */
initClass(
    	List
    ,(
		this(List)->value = 0;
		this(List)->next = NULL;
    ),(
		_add,
		_addIndex,
		_addAll,
		_remove,
		_removeAll,
		_get,
		_set,
		_length
    )
);

/* main func */
int main()
{
    int printList(List);
    List mlist = new(List);
    $(mlist).add(6);
    $(mlist).add(5);
    $(mlist).add(4);
    $(mlist).add(3);
    $(mlist).add(2);
    $(mlist).add(1);
    $(mlist).set(3,100);
    $(mlist).addIndex(5,120);
    $(mlist).remove(1);
    printList(mlist);
    
    List list2 = new(List);
    $(list2).add(12);
    $(list2).add(34);
    $(list2).add(56);
    $(mlist).addAll(list2);
    printList(mlist);
	
    $(mlist).removeAll();
    printList(mlist);
    
    printf("\n\n");
    return 0;
}

int printList(List list){
    int i, k;
    int length = $(list).length();
    printf("----------");
    printf("\n一共有%d个数，分别为：\n",length);
    for(i=0; i<length; i++){
        k = $(list).get(i+1);
        printf("  %3d\n",k);
    }
    printf("----------");
    return 0;
}


