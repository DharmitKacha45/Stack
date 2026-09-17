#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};
int isempty(struct stack*ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(struct stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push( struct stack* ptr,int val){
    if(isfull(ptr)){
        printf("stack overflow! cannot push %d to the stack \n",val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int pop(struct stack*ptr){
    if(isempty(ptr)){
        printf("stack underflow! cannot pop from the stack \n");
        return -1;
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack*sp,int i){
    int arrayind=sp->top-i+1;
    if(arrayind <0){
        printf("not a valid position for the stack\n");
        return -1;
    }
    else{
        return sp->arr[arrayind];
    }
}
int stacktop(struct stack*sp){
    return sp->arr[sp->top];
}

int stackbottom(struct stack*sp){
    return sp->arr[0];
}
int main(){
struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
sp->size=10;
sp->top=-1;
sp->arr=(int *)malloc(sp->size * sizeof(int));

printf(" before pushing, full:%d \n",isfull(sp));
printf(" before pushing, empty:%d \n",isempty(sp));

push(sp,56);
push(sp,5);
push(sp,6);
push(sp,5766);
push(sp,76);
push(sp,9876);
push(sp,6);
push(sp,8);
push(sp,86);
push(sp,83546);

printf(" after pushing, full:%d \n",isfull(sp));
printf(" after pushing, empty:%d \n",isempty(sp));

/*printf("popped %d from the stack\n ",pop(sp));
printf("popped %d from the stack\n ",pop(sp));
printf("popped %d from the stack\n ",pop(sp));
printf("popped %d from the stack\n ",pop(sp));
printf("popped %d from the stack\n ",pop(sp));
printf("popped %d from the stack\n ",pop(sp));
printf("popped %d from the stack\n ",pop(sp));
printf("popped %d from the stack\n ",pop(sp));
printf("popped %d from the stack\n ",pop(sp));
printf("popped %d from the stack\n ",pop(sp)); */

printing values from the stack

for(int j=1; j <= sp->top + 1 ;j++){
    printf("the value at position  %d is %d \n",j,peek(sp,j));
}

printf("the value of top of stack is %d \n",stacktop(sp));
printf("the value of bottom of stack is %d \n",stackbottom(sp));
    return 0;
}
