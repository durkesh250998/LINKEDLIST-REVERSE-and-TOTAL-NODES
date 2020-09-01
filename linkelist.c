#include<stdio.h>
#include<stdlib.h>
void beginning();
void display();
void end();
void specified();
void delete_b();
void delete_end();
void specified_d();
void total_nodes();
void reverse();
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;
struct node *new=NULL;
struct node *temp=NULL;
struct node *current=NULL;
struct node *prev=NULL;
struct node *next=NULL;
int main(){
    int n;
    
    printf("enter the total nodes");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        new=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&new->data);
        if(head==NULL){
                    head=new;
                    tail=new;
        }
        else{
            tail->next=new;
            tail=new;
        }
    }
    display();
    beginning();
    end();
    specified();
    delete_b();
    delete_end();
    specified_d();
    total_nodes();
    reverse();
    }
void display(){
    temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }

}
void beginning(){
    
    printf("enter element to add at beginning\n");
    
    new=(struct node*)malloc(sizeof(struct node));     
    scanf("%d",&new->data);
    new->next=head;
    head=new;
    display();
}
void end(){
    printf("enter element to add at end\n");
    new=(struct node*)malloc(sizeof(struct node));              
    scanf("%d",&new->data);
    tail->next=new;
    new->next=NULL;
    tail=new;
    display();
}
void specified(){
    int p;
    printf("enter specified position to insert");
    scanf("%d",&p);
    new=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&new->data);
    temp=head;
    for(int i=0;i<p-2;i++){
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;
    display();
}
void delete_b(){
    temp=head;
    head=head->next;
    temp->next=NULL;   
    printf("Node Deleted at the Beginning\n");
    display();
}
void delete_end(){
    
   
    temp=head;
    while(temp->next!=tail){
        temp=temp->next;
        } 
                
    temp->next=NULL;
    tail=temp;
    printf("Node Deleted at the END\n");
    display();
}
void specified_d(){
    int pos=0;
    printf("\nEnter the position to delete the element");
    scanf("%d",&pos);
    temp=head;
    for(int i=0;i<pos-2;i++){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    printf("Node Deleted\n");
    display();
}
void total_nodes(){
    temp=head;
    int count=0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
              }
    printf("TOTAL NUMBER OF NODES %d\n",count);
}
void reverse(){
    current=head;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    display();
}