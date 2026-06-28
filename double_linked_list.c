#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left,*right;
};
 struct node*newnode,*head,*tail,*temp,*prev;
 void display(){
    temp=head;
while(temp!=0){
    printf("%d ",temp->data);
    temp=temp->right;
}
 }
 void insert(){
       newnode=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("enter data :");
    scanf("%d",&x);
    newnode->data=x;
 }
 void insert_at_begin(){
     insert();
    newnode->left=0;
    newnode->right=head;
    
    head->left=newnode;
    head=newnode;

 }
 void insert_at_end(){
 insert();
    newnode->right=0;
    
    tail->right=newnode;
    newnode->left=tail;
    tail=newnode;
    
 }
 void insert_at_pos(int count){
    insert();
    int pos,i=1;
    printf("\nenter position");
    scanf("%d",&pos);
    if(pos>count)
    printf("invalid");
    if(pos==1)
    insert_at_begin();
    temp=head;
    while(i<pos-1){
       temp=temp->right;
       i++;
    }
    newnode->left=temp;
    newnode->right=temp->right;
    temp->right->left=newnode;
    temp->right=newnode;
   
 }
 void delete_at_begin(){
    temp=head;
    head=head->right;
    free(temp);
 }
 void delete_at_pos(int count){
     int pos,i=1;
     temp=head;
    printf("\nenter position");
    scanf("%d",&pos);
    if(pos>count)
    printf("invalid");
    while(i<pos){
        prev=temp;
        temp=temp->right;
        i++;
    }
    prev->right=temp->right;
    prev->right->left=prev;
    free(temp);
 }
 void delete_at_end(){
    temp=tail;
    tail=tail->left;
    tail->right=0;
    free(temp);
 }
int main(){
   int c=1,count=0;
    head=0;
while(c==1){
   insert();
    newnode->left=0;
    newnode->right=0;
    if(head==0)
    head=tail=newnode;
    else{
        tail->right=newnode;
        newnode->left=tail;
        tail=newnode;
    }
    printf("\ndo you want to continue : ");
    scanf("%d",&c);
    count++;
}
int s=1;
while(s==1){
int choice;
printf("\n enter choice :  \n 1:insert_at_begin()\n 2:insert_at_pos\n3:insert_at_end\n4:display\n5:delete_at_begin()\n6:delete_at_pos\n7:delete_at_end()\n");
scanf("%d",&choice);
switch(choice){
    case 1:insert_at_begin();
    break;
    case 2:insert_at_pos(count);
    break;
    case 3:insert_at_end();
    break;
    case 4:display();
    break;
    case 5:delete_at_begin();
    break;
    case 6:delete_at_pos(count);
    break;
    case 7:delete_at_end();
    break;
    default:printf("please enter correct choice ");
    break;
}
printf("\ndo ypu  want to continue 1/0 : ");
scanf("%d",&s);
}
return 0;

}
