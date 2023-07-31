#include <stdio.h>
#include <stdlib.h>

//insert, delete, retrieve, replace, isEmpty
// current라는 변수를 기준으로 위의 함수들을 시행
//declare node
typedef struct Lnode{
    int data;
    struct Lnode* next;
    struct Lnode* before;
}listNode;

//declare DoubleLinkedList
typedef struct DList{
    struct Lnode* first;
    struct Lnode* current;
    int length;
}DoubleList;

//function init DoubleLinkedList
DoubleList* initList(){
    DoubleList* tmp = malloc(sizeof(DoubleList));
    tmp->first = NULL;
    tmp->length = 0;
    tmp->current = NULL;
    return tmp;
}
// using head node
/*
DoubleList* initList(){
    DoubleList* tmp = malloc(sizeof(DoubleList));
    tmp->first = malloc(sizeof(listNode)); // tmp-> first == head node
    tmp->length = 0;
    tmp->current = tmp->first;
    return tmp;
}
이렇게 하면 insertNode에서 if문으로 구분 안해도됨
*/
// function isEmpty
// is current node empty?
int isEmpty(DoubleList* list){
    if(list->current == NULL){
        return 1;
    }else{
        return 0;
    }
}

//function insert into DoubleLinkedList
int insertDList(DoubleList* list, int data){
    listNode* tmp = malloc(sizeof(listNode));
    tmp->data = data;
    tmp->next = NULL;

    // list is Empty
    if(isEmpty(list)){
        list->first = tmp;
        tmp->before = NULL; // 첫번쨰 원소는 before에 뭐 넣지
        list->current = tmp;
    }else{ // list is not empty( current tmp currentnext)
        list->current->next->before = tmp;
        tmp->next = list->current->next;
        tmp->before = list->current;
        list->current->next = tmp;
    }

    list->current = tmp;
    list->length = list->length + 1;

    return 0;
}


// function deleteDList
// 책엔 current의 다음 노드를 삭제해버리는데?
int deleteDList(DoubleList* list){
    listNode* beforeN = list->current->before;
    listNode* nextN = list->current->next;
    if(list->current==NULL){
        printf("Error\n");
        return -1;
    }
    int dData = list->current->data;
    // before current next
    beforeN->next = nextN;
    nextN->before = beforeN;
    
    free(list->current);
    list->current = beforeN;

    return dData; 
}
// searchDList
int searchDList(DoubleList* list, int key){
    listNode* tmp=list->first;
    while(tmp!=NULL){
        if(tmp->data == key){
            list->current = tmp;
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;

}

//printDList
void printDList(DoubleList* list){
// insertList Test
    listNode* tmp=list->first;
    while(tmp!=NULL){
        printf(" %d",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}


//main
int main(){

    DoubleList *A=initList();

    insertDList(A,1);
    insertDList(A,2);
    insertDList(A,3);
    insertDList(A,4);
    insertDList(A,5);
    insertDList(A,6);

    deleteDList(A);// Delete 6
    if(searchDList(A,1)){
        printf("Success\n");
    }else{
        printf("Error\n");
    }
    if(searchDList(A,6)){
        printf("Success\n");
    }else{
        printf("Error\n");
    }

    printDList(A);


    return 0;
}