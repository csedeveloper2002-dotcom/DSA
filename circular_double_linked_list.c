#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*next;
};
struct node*newnode,*temp,*tail;
void display(){
temp=tail->next;
while(temp->next!=tail->next){
   printf("%d",temp->data);
   temp=temp->next;
}
printf("%d",temp->data);
}
int main(){
   int c=1;
   while(c==1){
   newnode=(struct node*)malloc(sizeof(struct node));

   printf("enter the data :");
   scanf("%d",&newnode->data);
   tail=0;
   newnode->next=0;
   if(tail==0){
   tail=newnode;
   tail->next=newnode;
   }
   else{
   newnode->next=tail->next;
   tail->next=newnode;
   tail=newnode;
   }
   printf("continue (1/0) :");
   scanf("%d",&c);
}
display();
return 0;
}
