#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
 struct node* head=NULL;
 
 void insert_at_beg()
 {
 	struct node*ptr = (struct node*)malloc (sizeof(struct node));
 	int item;
 	printf("enter the new data ");
 	scanf("%d",&item);
 	ptr->data= item;
 	ptr->link=NULL;
 	if(ptr==NULL){
 		printf("node is not created");
 		
	 }
 	if(head==NULL){
 		head=ptr;
	 }
	 else
	 {
	 	ptr->link = head;
	 	head=ptr;
	 }
}


void insert_at_end()
{
	struct node*ptr=(struct node*)malloc(sizeof(struct node));
	struct node*ptr1;
	int item;
	printf("Enter the new data ");
	scanf("%d",&item);
	ptr->data=item;
	ptr->link=NULL;
	if (head == NULL)
    {
        head = ptr;
    }
    else if(head->link == NULL)
    {
    	head->link=ptr;
	}
	else
	{
		ptr1 = head;
		while(ptr1->link != NULL)
		{
			ptr1=ptr1->link;
		}
		ptr1->link=ptr;
		printf("Data insert successfull");
	}
}


void insert_at_any()
{     struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* ptr1;
    int item, pos, count = 1;
    printf("Enter the new data: ");
    scanf("%d", &item);
    printf("Enter the position: ");
    scanf("%d", &pos);
	if(head==NULL){
		head=ptr;
	}
	if(pos==1){
		ptr->link=head;
		head=ptr;
		
	}
	ptr1=head;
	count=1;
	while(ptr1->link!=NULL && count <pos-1){
		ptr1=ptr1->link;
		count=count+1;
	}
	if(ptr1->link== NULL && count!=pos-1){
		printf("Position does not exist");
		
	}
	ptr->link=ptr1->link;
	ptr1->link=ptr;
	
}


void delete_from_beg()
{
	if(head == NULL){
		printf("list not exist");
	}
	else
	{
	
	struct node* ptr = head;
	ptr=head;
	head=ptr->link;
	ptr->link= NULL;
	printf(" Deleted : %d",ptr->data);
}
   
}


 void delete_from_end()
 {
 	struct node* ptr;
 	struct node* ptr1;
 	
 	if(head== NULL){
 		printf("node not created");
	 }
	 if(head->link == NULL){
	 	ptr=head;
	 	head=NULL;
	 }
	 else
	 {
	 	ptr1=head;
		while(ptr1->link->link != NULL){
			ptr1=ptr1->link;
			ptr=ptr1->link;
		}
		ptr1->link= NULL;
		printf("%d",ptr1->data);
	 }
 }
 
 
 void delete_from_any()
 {
 	struct node* ptr1;
 	struct node* ptr;
 	int pos, count;
 	if(head == NULL){
 		printf("node not created");
	 }
	 scanf("%d",& pos);
	 if(pos ==1){
	 	delete_from_beg();
	 }
	 else
	 {
	 	count=1;
	 	ptr1=head;
	 	while(ptr1->link!=NULL && count < pos-1 ){
	 		ptr1=ptr1->link;
	 		count = count +1;
	 		if(ptr1->link == NULL && count != pos -1){
	 			printf("position not exists");
			 }
			 else
			ptr = ptr1 ->link;
			ptr1->link = ptr->link;
			ptr->link = NULL;
			printf("%d",ptr->data);
		 }
		 
	 }
	 
 }
void display() {
    struct node* ptr = head;
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

int main()
{
	int n;
	do
	{
		
			printf("\nMenu:\n 1. insert at beg\n 2. Insert at End\n 3.Insert at any position\n 4. Delete from beg\n 5. Delete from end\n 6.Delete from any\n 7. Display\n 8. Exit\n");
		printf("Enter your choice ");
	scanf("%d",&n);

	switch(n)
	{
		case 1:
			insert_at_beg();
		 break;
		case 2:
			insert_at_end();
			break;
		case 3:
			insert_at_any();
			break;
		case 4:
			delete_from_beg();
			break;
		case 5:
			delete_from_end();
			break;
		case 6:
			delete_from_any();
			break;
		case 7:
			display();
			break;
		case 8:
			exit(0);
		
			
		default:
                printf("Invalid choice! Please try again.\n");
	}
	}
	while(1);
	return 0;
}
