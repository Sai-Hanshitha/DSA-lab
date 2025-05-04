// Implementing stack ADT using a singly linked list

#include<cstdio>
#include<cstdlib>

class list{
    private:
    struct node{
        char data;
        struct node *next;
    };
    struct node *top;
    public:
    list(){
        top=NULL;
    }
    int push(int);
    int pop();
    int peek();    
    int is_empty();

};

int main(){
    list obj;
    int choice,value;

    do{
        printf("\nMENU\n");
        printf("1)Push\n");
        printf("2)Pop\n");
        printf("3)Peek\n");
        printf("4)Exit\n");

        printf("Enter your choice :");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value to push :");
                scanf("%d",&value);
                obj.push(value);
                break;
            
            case 2:
                value=obj.pop();
                if(value!=0){
                    printf("Popped element is :%d",value);
                }
                break;
            
            case 3:
                value=obj.peek();
                if(value!=0){
                    printf("Peek value of stack is :%d",value);
                }
                break;

            case 4:
                printf("Exiting\n");
                break;
            
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=4);
    return 0;
}

int list:: is_empty(){
    if(top == NULL){
        return 1;
    }
    return 0;
}


// Pushing a value into stack

int list::push(int value){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Stack underflow\n");
        return -1;
    }
    newnode->data=value;
    newnode->next=top;
    top=newnode;

    return 0;
}

// Pop a value from a stack

int list::pop(){
    if(top==NULL){
        printf("Stack is empty\n");
        return -1;
    }
    struct node *temp=top;
    int value=top->data;
    top=top->next;

    free(temp);
    return value;
    
}

// Peek value of a stack

int list::peek(){
    if(top==NULL){
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

