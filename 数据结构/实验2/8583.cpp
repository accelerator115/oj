#include<malloc.h>
#include<stdio.h>
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量

typedef int SElemType; // 定义栈元素类型
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等

struct SqStack
{
     SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
     SElemType *top; // 栈顶指针
     int stacksize; // 当前已分配的存储空间，以元素为单位
}; // 顺序栈

Status InitStack(SqStack &S)
{
    // 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
    S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base) return ERROR;
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status Push(SqStack &S,SElemType e)
{
    // 在栈S中插入元素e为新的栈顶元素
    if (S.top - S.base >= S.stacksize) {
        S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!S.base) return ERROR;
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *(S.top) = e;
    S.top++;
    return OK;
}

Status Pop(SqStack &S,SElemType &e)
{
    // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
    if (S.top == S.base) return ERROR;
    S.top--;
    e = *(S.top);
    return OK;
}

Status GetTop(SqStack S,SElemType &e)
{
    // 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
    if (S.top == S.base) return ERROR;
    e = *(S.top - 1);
    return OK;
}

int StackLength(SqStack S)
{
    // 返回栈S的元素个数
    return S.top - S.base;
}

Status StackTraverse(SqStack S)
{
    // 从栈顶到栈底依次输出栈中的每个元素
    SElemType *p = S.top - 1;
    if (S.top == S.base) printf("The Stack is Empty!");
    else
    {
        printf("The Stack is: ");
        while (p >= S.base)
        {
            printf("%d ", *p);
            p--;
        }
    }
    printf("\n");
    return OK;
}

int main()
{
    int a;
    SqStack S;
    SElemType x, e;
    if (InitStack(S))    // 判断顺序表是否创建成功
    {
        printf("A Stack Has Created.\n");
    }
    while(1)
    {
        printf("1:Push \n2:Pop \n3:Get the Top \n4:Return the Length of the Stack\n5:Load the Stack\n0:Exit\nPlease choose:\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1: scanf("%d", &x);
                    if (Push(S, x) == ERROR) printf("Push Error!\n");
                    else printf("The Element %d is Successfully Pushed!\n", x);
                    break;
            case 2: if (Pop(S, e) == ERROR) printf("Pop Error!\n");
                    else printf("The Element %d is Successfully Poped!\n", e);
                    break;
            case 3: if (GetTop(S, e) == ERROR) printf("Get Top Error!\n");
                    else printf("The Top Element is %d!\n", e);
                    break;
            case 4: printf("The Length of the Stack is %d!\n", StackLength(S));
                    break;
            case 5: StackTraverse(S);
                    break;
            case 0: return 1;
        }
    }
}