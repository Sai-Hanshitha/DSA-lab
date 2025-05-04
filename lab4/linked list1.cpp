//Implementing list ADT using singly linked list

#include<cstdio>
#include<cstdlib>

class list{
    private:
    struct node{
        int data;
        struct node *next;
    };
    struct node *head;

    public:
    list(){
        head=NULL;
    }

    int insertatbeg(int value);
    int insertatend(int value);
    int insertatpos(int position,int value);
    int deleteatbeg();
    int deleteatend();
    int deleteatpos(int position);
    int search(int target);
    void display();
    void dispalyreverse();
    void reverse();
};

int main(){
    list list1;

    int choice;
    int value;
    int position;
    int target;
    int result;

    do{
        printf("\nMENU CARD\n");
        printf("Enter 1: To insert the node at beginning\n");
        printf("Enter 2: To insert the node at end\n");
        printf("Enter 3: To insert the node at given position\n");
        printf("Enter 4: To delete node at beginning\n");
        printf("Enter 5: To delete node at end\n");
        printf("Enter 6: To delete node at a given position\n");
        printf("Enter 7: To search an element\n");
        printf("Enter 8: To display the list\n");
        printf("Enter 9: To display the reverse of the list\n");
        printf("Enter 10:To reverse the list\n");
        printf("Enter 11:To exit\n");

        printf("Enter your choice :");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value to insert at beginning :");
                scanf("%d",&value);
                list1.insertatbeg(value);
                list1.display();
                printf("\n");
                break;
            case 2:
                printf("Enter value to insert at end:");
                scanf("%d",&value);
                list1.insertatend(value);
                list1.display();
                printf("\n");
                break;
            case 3:
                printf("Enter position to insert :");
                scanf("%d",&position);
                printf("Enter value to insert :");
                scanf("%d",&value);
                list1.insertatpos(value,position);
                list1.display();
                break;
            case 4:
                result=list1.deleteatbeg();
                printf("Deleted value is :%d",result);
                break;
            case 5:
                result=list1.deleteatend();
                printf("Deleted value is :%d\n",result);
                break;
            case 6:
                printf("Enter position to delete :");
                scanf("%d",&position);
                result=list1.deleteatpos(position);
                printf("Deleted value is :%d\n",result);
                break;
            case 7:
                printf("Enter element to search :");
                scanf("%d",&target);
                list1.search(target);
                break;
            case 8:
                printf("List :");
                list1.display();
                break;
            case 9:
                //list1.dispalyreverse();
                //list1.display();
                break;
            case 10:
                //list1.reverse();
                //list1.display();
                break;
            case 11:
                printf("Exit\n");
                break;
            default:
                printf("Enter valid choice\n");

        }
    }while(choice!=11);

    return 0;
}

// Insertion node at beginning

int list::insertatbeg(int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=head;
    head=newnode;
    printf("\n");
    return 1;
}

// Display of list

void list::display(){

    if(head==NULL){
        printf("List is empty\n");
        return ;
    }
    struct node *temp=head;
    while(temp->next!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

// Insert node at end

int list::insertatend(int value){
    if(head==NULL){
        insertatbeg(value);
        return 0;
    }
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;

    struct node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return 1;
}

// Insert node at given position

int list::insertatpos(int value,int position){
    if(position<0){
        printf("Invalid position\n");
        return -1;
    }
    if(position==1){
        insertatbeg(value);
        return 1;
    }
    int i=1;

    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;

    struct node *temp=head;
    while(i<position-1 && temp->next!=NULL){
        temp=temp->next;
        i++;
    }
        newnode->next=temp->next;
        temp->next=newnode;
    return 1;
}

// Delete a node at beginning

int list::deleteatbeg(){
    if(head==NULL){
        printf("List is empty\n");
        return -1;
    }
    struct node *temp=head;
    int result=temp->data;
    head=temp->next;
    free(temp);
    return result;

}

// Delete node at end

int list::deleteatend(){
    if(head==NULL){
        printf("List is empty\n");
        return -1;
    }
    struct node *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    struct node *del=temp->next;
    int result=del->data;
    temp->next=NULL;
    free(del);
    return result;

}

// Delete node at given position

int list::deleteatpos(int position){
    if(position<0){
        printf("Invalid position\n");
        return -1;
    }
    if(position==1){
        deleteatbeg();
        return 0;
    }
    int i=1;

    struct node *temp=head;
    while (i<position-1 && temp->next!=NULL){
        temp=temp->next;
        i++;
    }

    struct node *del=temp->next;
    int result=del->data;
    temp->next=del->next;
    free(del);
    return result;

}

// Search for given node in the list

int list::search(int target){
    if(head==NULL){
        printf("List is empty\n");
        return -1;
    }
    struct node *temp=head;

    int count=0;
    while(temp->next!=NULL){
        count++;
        if(temp->data==target){
            return count;
        }
        temp=temp->next;
    }
    return 1;

}

// Display reverse of the list

void list::dispalyreverse(){
    struct node *temp = head;
    int count =0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    for(int i = count;i>0;i--){
        temp = head;
        int j=i-1;
        while( j>0){
            temp = temp->next;
            j--;
        }
        printf("%d\n",temp->data);
    }
}

// Reversing the linked list

void list::reverse(){
    struct node *next1 = NULL;
    struct node *current = head;
    struct node *prev = NULL;
    while(current != NULL){
        next1 = current->next;
        current->next = prev;
        prev = current;
        current = next1;
    }
    head = prev;
}

