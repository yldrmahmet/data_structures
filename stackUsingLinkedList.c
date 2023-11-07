// linked list kullanarak stack uygulamasi
// hocanin yazdigi gibi global degisken kullanmadan yazildi, hocanin kodlarina benziyor

#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node* link;
};

void push (int eklenecekSayi, struct node **top)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data=eklenecekSayi;
	temp->link=*top;
	*top = temp; 
}

void pop ( struct node **top)
{
	struct node* temp;
	if(*top==NULL) return;
	temp = *top;
	*top = (*top)->link;
	free(temp);
}

void print (struct node *top)
{
	if(top==NULL) return;
	while(top!=NULL)
	{
		printf("%5d",top->data);
		top=top->link;
	}
	printf("\n");
}

int main ()
{
	struct node* top = NULL;
	push(5,&top);
	push(12,&top);
	print(top);
	pop(&top);
	push(8,&top);
	print(top);
}
