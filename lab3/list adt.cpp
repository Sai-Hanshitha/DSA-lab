#include<stdio.h>
#include<stdlib.h>

class list{
    int *arr;
    int n;
    int cur;

public:

    list(){
        cur=-1;
        n=5;
        arr=(int*)malloc(n*sizeof(int));

    }

    int insertionatbeg(int value);
    int insertionatend(int value);
    int insertionatpos(int value,int index);
    int deleteatbeg();
    int deleteatend();
    int deleteatpos(int index);
    int search(int target);
    void display();
    int rotate(int k);

};

int main(){
    int choice=1;
    list list1;

    while(choice!=10){
        printf("\n Choose an option\n");
        printf("1)Insert at beginning\n");
        printf("2)Insert at end\n");
        printf("3)Insert at position\n");
        printf("4)Delete at beginning\n");
        printf("5)Delete at end\n");
        printf("6)Delete at position\n");
        printf("7)Display\n");
        printf("8)Search\n");
        printf("9)Rotate\n");
        printf("10)Exit\n");

        printf("Enter your choice :");
        scanf("%d",&choice);

        int value,index,k,target;
        switch(choice){
            case 1:
                printf("Enter element to inset:\n");
                scanf("%d",&value);
                list1.insertionatbeg(value);
                list1.display();
                break;
            case 2:
                printf("Enter element to inset:\n");   
                scanf("%d",&value);
                list1.insertionatend(value);
                list1.display();
                break;
            case 3:
                printf("Enter element to inset:\n");
                scanf("%d",&value);
                printf("Enter index to insert:\n");
                scanf("%d",&index);
                list1.insertionatpos(value,index);
                list1.display();
                break;
            case 4:
                printf("Deleted element:%d\n",list1.deleteatbeg());
                list1.display();
                break;
            case 5:
                printf("Deleted element:%d\n",list1.deleteatend());
                list1.display();
                break;
            case 6:
                printf("Enter index to delete\n");
                scanf("%d",&index);
                printf("Deleted element:%d\n",list1.deleteatpos(index));
                list1.display();
                break;
            case 7:
                list1.display();
                break;
            case 8:
                printf("Enter element to search:");
                scanf("%d",&target);
                list1.search(target);
                list1.display();
                break;
            case 9:
                printf("Enter no of positions to rotate:\n");
                scanf("%d",&k);
                list1.rotate(k);
                list1.display();
                break;
            case 10:
                printf("Exit\n");
                break;
            default:
                printf("Enter valid choice\n");
        }
    }
return 0;
}

int list::insertionatbeg(int value){
    if(cur==n-1){
        printf("List is full\n");
        return -1;
    }
    for(int i=cur+1;i>0;i++){
        arr[i]=arr[i-1];
    }
    arr[0]=value;
    cur++;
    return 1;
}

int list::insertionatend(int value){
    if(cur==n-1){
        printf("List is full\n");
        return -1;
    }
    arr[cur+1]=value;
    cur++;
    return 1;
    
}

int list::insertionatpos(int value,int index){
    if(index>cur+1 || index<0){
        printf("Invalid index\n");
        return -1;
    }
    if(cur==n-1){
        printf("List is full\n");
        return -1;
    }
    for(int i=cur+1;i>index;i--){
        arr[i]=arr[i-1];
    }
    arr[index]=value;
    cur++;
    return 1;
}

int list::deleteatbeg(){
    if(cur==-1){
        printf("List is empty\n");
        return -1;
    }
    int temp=arr[0];
    for(int i=0;i<cur;i++){
        arr[i]=arr[i+1];
    }
    cur--;
    return temp;

}

int list::deleteatend(){
    if(cur==-1){
        printf("List is empty");
        return -1;
    }
    int temp=arr[cur];
    cur--;
    return temp;
}

int list::deleteatpos(int index){
    if(index>cur || index<0){
        printf("Index not found");
        return -1;
    }
    if(cur==-1){
        printf("List is empty");
        return -1;
    }
    int temp=arr[index];
    for(int i=index;i<cur;i++){
        arr[i]=arr[i+1];
    }
    cur--;
    return temp;

}

void list::display(){
    if(cur==-1){
        printf("List is empty\n");
        return ;
    }
    printf("List:");
    for(int i=0;i<=cur;i++){
        printf("%d\t",arr[i]);
    }

}

int list::search(int target){
    for(int i=0;i<=cur;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int list::rotate(int k){
    if(cur<=0){
    return -1;
    }
    for(int i=0;i<k;i++){
    int temp=arr[cur];
    
    for(int j=cur;j>0;j--){
        arr[j]=arr[j-1];
    }
    arr[0]=temp;
    }
    return 1;

}