#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//   declarations of functions

int search(int);
int SHOW();
int check(int);       //   for checking quantity
int value=0;
 //   build a node
struct node {
	int ID;
	char pNAME[100];
	double pPRICE;            //   product price
	int qnty;
struct    node* next;
};
struct node *head=NULL;

// ----------------------------------------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------LINK LIST METHOD---------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------------------------------

//      for entering(saving) 1st record in list
 void start(){
	system("cls");
	int id,quant;           //  quant    for quantity
	char name[100];
	double pre;            //  pre for price
	struct node *t =(struct node*) malloc(sizeof(struct node));

	printf("\t\t\tEnter product ID -->");
	scanf("%d",&id);
	t->ID=id;
	printf("\t\t\tEnter product Name -->");
	scanf("%s",name);
	for(int i=0;i<100;i++){
	t->pNAME[i]=name[i];}
	printf("\t\t\tEnter product price -->");
	scanf("%lf",&pre);
	t->pPRICE=pre;
	printf("\t\t\tEnter product quantity -->");
	scanf("%d",&quant);
	t->qnty=quant;
	t->next=head;
	head=t;
	system("cls");
		printf("\n\n\t\t\t\tThis product has been added to the stock!\n\n\n");
}



// for entering(saving) 2nd and onward records in list
void end(){
	system("cls");
	int id,quant;      
	char name[100];
	double pre;            //  pre = price
	struct node *t=(struct node*) malloc(sizeof(struct node));
	struct node *p=head;
	printf("\t\t\tEnter product ID -->");
	scanf("%d",&id);
	t->ID=id;
	printf("\t\t\tEnter product Name -->");
	scanf("%s",name);
	for(int i=0;i<100;i++){
	t->pNAME[i]=name[i];}
	printf("\t\t\tEnter product price -->");
	scanf("%lf",&pre);
	t->pPRICE=pre;
	printf("\t\t\tEnter product quantity -->");
	scanf("%d",&quant);
	t->qnty=quant;
		while(p->next!=NULL)
		{
		p=p->next;
		}
			p->next=t;
			t->next=NULL;
		system("cls");
		printf("\n\n\t\t\t\tThis product has been added to the stock!\n\n\n");
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------Delete Method--------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------------------------------

void deletePRO(){
		system("cls");
		SHOW();
		int id;
		struct node *current=head;
		struct node *pre=head;
		printf("\n\nEnter ID to delete that product:\n\n");
		scanf("%d",&id);
		 if (head == NULL)
        {
            system("cls");
            printf("Stock List is empty\n");
        }
	int pos=0;
	int count=SHOW();               //   for load no of nodes
	pos=search(id);                        //   for check weather desire node is exist or not
	if(pos<=count){

		while(current->ID!=id){                //  for delete middle area products
			pre=current;
			current=current->next;
}
		pre->next=current->next;
		system("cls");
		printf("\n*****item is deleted*****\n");
	}else{
		printf("\n**********Not found**********\n\n");
	}
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------Modify Method--------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------------------------------

void modifyPRO(){
		int id;
		double pre;        //    pre for price
		char pName[100];      //   pName for new name
		if (head == NULL)
    {
    	system("cls");
        printf("Stock List is empty\n");
    }else
	{
		printf("\n\nEnter ID to change product Name and its price:\n");
		scanf("%d",&id);
		struct node *current=head;
		int pos=0;
		int count=SHOW();               //   for load no of nodes
	pos=search(id);                        //   for check weather desire node is exist or not
	if(pos<=count){

		while(current->ID!=id){
			current=current->next;
		}
		printf("\nOld Name : ");
		printf("%s",current->pNAME);
		printf("\nOld Price : ");
		printf("%lf\n",current->pPRICE);
		printf("Enter new Name: ");
		scanf("%s",pName);
		for(int i=0;i<100;i++){
		current->pNAME[i]=pName[i];}
		printf("Enter new Price:");
		scanf("%lf",&pre);
		current->pPRICE=pre;
	}else{
	    printf("%d is *****Not found*****\n\n",id);
	}
	}
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------Print Method---------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------------------------------

int SHOW(){
		system("cls");
		int c=0;             //   c for count products
		struct node *p=head;
		printf("Existing products are:\n");
		printf("ID\t\tProduct Name\t\tPrice\t\tQuantity\n");
		while(p!=NULL)
		{
		    printf("%d\t\t%s\t\t\t%.2lf TK\t     ",p->ID,p->pNAME,p->pPRICE);//    call   check func and pass quantity
            if(check(p->qnty)<=0)
                printf("OUT OF STOCK!\n");
            else
                printf("%d\n",check(p->qnty));
			p=p->next;
			c=c+1;
		}
		printf("\nTotal products in our Market is : %d\n\n\n",c);
		return c;
	    }
int check(int quant){              //        check function
    int a = quant;
        if(quant<=0)
            return 0;
        else
	    	return quant;
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------Buy Method----------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------------------------------

void buy(){
	system("cls");
	int pay=0,no,price,id,i=1;
    if(head==NULL){
        printf("\n**********There is no items to buy**********\n\n");
	}
	else{
		printf("How many items you want to buy!\n");
        printf("-------------->> ");
		scanf("%d",&no);
		int count=SHOW();           //   for store no of nodes  in c
        while(i<=no){
            struct node *current=head;
            int quant;
            printf("Enter id of item that you want to buy --> ");
            int id,pos=0;
            scanf("%d",&id);
            pos=search(id);
            if(pos<=count){
                while(current->ID!=id){
                    current=current->next;
                }
                printf("How many quantities do you want --> ");
                scanf("%d",&quant);
                pay=pay+(current->pPRICE*quant);         //     calculate Bill
                current->qnty=current->qnty-quant;           //    change quantity
                i++;
                printf("\n\n\t\t\tYou have bought --> ");
                printf("%s\n\n",current->pNAME);
            }
            else{
            printf("\n***************This item is not available in our stock at this time***************\n\n");
            }
        }
    }
    price=pay*(0.90);         
	printf("\n\n\t\t\t\t\tOriginal price : %d TK\n",pay);
    printf("\t\t\t\t\twith 10 percent discount:   %d TK\n\t\t\t\t\tThank you! Please come again.\n\n",price);
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------Inner Search Method----------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------------------------------

int search(int id)                     //    for search item in list
 {
 	int count=1;
 	struct node *p=head;
 	while(p!=NULL)
 	{
 		if(p->ID==id)
 			break;
 		else
 			count++;
 			p=p->next;
	}
 	return count;
 }
// ----------------------------------------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------Main function--------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------------------------------

int main(){
    int f1,f2;
	printf("###################################################################\n");
    printf("########################   Isekai Market   ########################\n");
	printf("###################################################################\n\n\n");
	int temp=1;
	while(1){
		int ch1;
		f1=1;
		f2=1;
		printf("\t\tEnter 1 to Staff portal \n\n\t\tEnter 2 to Customer portal\n\n\t\tEnter 0 to exit\n\n");

		printf("-------------->> ");
		scanf("%d",&ch1);
        printf("\n");
		switch(ch1){
			case 1 :
			while(f1){
				int ch2;                     //            choice for below message
				printf("\t\tEnter 1 to ADD a new product \n\n\t\tEnter 2 to display all products \n\n\t\tEnter 3 to MODIFY Existing product\n\n");
				printf("\t\tEnter 4 to Delete particular product item\n\n\t\tEnter 0 to exit\n\n");
				printf("-------------->> ");
				scanf("%d",&ch2);
                printf("\n");
				switch(ch2){
					case 1:
						if (temp==0)             //    Second time and on ward this is only executed
							end();
						if(temp==1){
							value++;                   //    this will be executed only one time
							start();
							temp=0;
						}
							break;
					case 2:
						system("cls");
						SHOW();
						break;
					case 3:
						modifyPRO();
						break;
					case 4:
						deletePRO();
						break;
					case 0:
						printf("Exiting 3 2 1...\n");
						f1=0;                
						break;
					default:
						system("cls");
						printf("\t\t**********Choice Invalid!**********\n\n");
						break;
				}
			}
		break;
		case 2:
			while(f2){
				int ch3;
				printf("\n\n\t\tEnter 1 To buy something\n\n\t\tEnter 2 to exit\n\n");
				printf("-------------->> ");
				scanf("%d",&ch3);
                printf("\n");
				switch(ch3){
					case 1 :
						buy();
						break;
					case 2 :
						printf("Exiting 3 2 1...\n");
						f2 = 0;                    
						break;
					default: 
						system("cls");
						printf("\t\t**********Choice Invalid!**********\n\n");
						break;
				}
			}
			break;
		case 0 :
			printf("Exiting 3 2 1...\n");
			exit(1);                    
			break;
		default:
			system("cls");
			printf("\t\t**********Choice Invalid!**********\n\n");
			break;
		}
    }
}
