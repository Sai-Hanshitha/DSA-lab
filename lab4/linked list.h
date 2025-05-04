//Header file 
#include <cstdio>
#include <cstdlib>
class list{
    private:
    struct node {
        int data;
        struct node *next;
    }*head;
    struct node* gethead(){
        return head;
    }
    public:
    list (){
        head = nullptr;
    }
    int insert(int value);
    list merge(list lst1,list lst2);
    void display();
};

