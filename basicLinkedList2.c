// global degisken kullanarak temel bagli liste islemlerinin yapilmasi

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* head; // listenin basini gosteren isaretci

// liste icin yeni node olusturma
struct node* create (int key)
{
	struct node *temp;
	temp =(struct node*)malloc(sizeof(struct node));
	temp->data=key; // (*temp).data=key;
	temp->next=NULL; // (*temp).next=NULL;
	return temp;
}

// listenin basina eleman ekleme
void insert (int key)
{
	struct node *temp = create(key);
	if(head!=NULL) temp->next=head;
	head=temp;
}

// listeye sira belirterek eleman ekleme
void insert2 (int key, int order)
{
	struct node* temp1 = create(key);
	if(order==1) // listenin basina eleman eklenecekse
	{
		temp1->next=head;
		head=temp1;
		return;
	}
	// listenin ortalarina ve sonuna eleman eklenecekse
	struct node* temp2 = head;
	int i;
	for(i=0;i<order-2;i++)
	temp2=temp2->next;
	temp1->next = temp2->next;
	temp2->next = temp1;
}

// listenin sonuna eleman ekleme
void insert3 (int key)
{
	struct node* temp1 = create(key);
	if(head==NULL)
	{
		/*listede eleman yoksa insert1==insert3*/
		head = temp1; //insert(key); 
		return;
	}
	struct node* temp2 = head;
	while(temp2->next!=NULL)
	temp2=temp2->next;
	temp2->next=temp1;
}

// listeden eleman silme, anahtara gore
void delete (int key)
{
	if(head==NULL) return; // hic node yok
	struct node* temp1 = head;
	if(head->data==key) // listenin basi silinecekse
	{
		temp1 = head;
		head=head->next;
		free(temp1);
		return;
	}
	while(temp1->next != NULL && temp1->next->data!=key)
	{
		temp1=temp1->next;
	}
	if(temp1->next==NULL)  return;
	struct node* temp2 = temp1->next;
	temp1->next=temp2->next;
	temp2->next=NULL;
	free(temp2);
}

// hocanin yazdigi silme fonksiyonu
void delete2(int key){
    struct node *temp=head;
    struct node *once;
    while(temp!=NULL && temp->data!=key){
        once = temp;
        temp=temp->next;
    }
    if(temp==NULL) return; // LISTEDEN OLMAYAN BI ELEMAN GIRILMISSE DIYE ONLEM ALINMIS
    else {
		if(temp==head) head=head->next; //LISTE BASINDAN ELEMAN SILME
        else once->next=temp->next; // LISTE SONUNDAN VE ARADAN ELEMEN SILME
        free(temp);
    }       
}

// listeden siraya gore eleman silme 
void delete3 (int order)
{
	struct node* temp1 = head;
	if (order==1) // ilk eleman silinecekse
	{
		head = temp1->next;
		free(temp1);
		return;
	}
	int i;
	for (i=0; i<order-2;i++)
	temp1=temp1->next; // silinecek elemanin bir onceki elemanina isaret ettiriyoruz bu dongu sayesinde
	struct node* temp2 = temp1->next;
	temp1->next=temp2->next; /* silinecek elemanin bir onceki elemanini yine silinecek elemanin 
	bir sonraki elemanina isaret ettiriyoruz bundan sonra artik silme islemini yapabiliriz*/
	free(temp2);
	
}

void print ()
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%5d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main () 
{
	head=NULL; // liste bos
	insert3(1);insert3(2);insert3(3);insert3(4);insert3(5);reverse();
	print(); // liste yazdir
}
