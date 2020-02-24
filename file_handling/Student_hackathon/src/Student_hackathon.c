/*
 ============================================================================
 Name        : Student_hackathon.c
 Author      : soniya shinde
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer
{
	int id;
	char *name;
	char *address;
};
typedef struct Product
{
	int id;
	char name[20];
	char category[20];
	float rate;
}Product_t;
struct Date
{
	int day,month,year;

};
struct Order
{
	int id,customer_id,product_id,quantity;
	char *status;
	struct Date order_date;
};
void Register_customer()
{
	FILE *fp;
	struct Customer c;
	int n;
	fp=fopen("customers.db","ab");
	if(fp == NULL)
	{
		perror("\n Failed to open file");
		exit(0);
	}
	else
	{
		printf("\nEnter id");
		scanf("%d",&c.id);
		printf("\nEnter Name");
		scanf("%s",&c.name);
		printf("\nEnter Address");
		scanf("%s",&c.address);
		n=fwrite(&c,sizeof(struct Customer),1,fp);
		if(n>0)
		{
			printf("\n Customer added ....");

		}
		else
		{
			printf("\ncustomer Failed to add...");
		}
		fclose(fp);
	}
}
int main_menu()

{
	fflush(stdin);
	int choice;
	printf("\nMain Menu..\n0.Exit\n1.Register Customer\n2.Customer\n3.Admin\n");
	printf("\nEnter your choice:");
	scanf("%d",&choice);
	return choice;
}
void List_Product_categories()
{
	FILE *fp;
	char ch;
	fp=fopen("categories.txt","r");
	if(fp == NULL)
	{
		perror("\n Failed to open file");
		return;
	}
	else
	{
		printf("\n.......Available Categories......\n");
		ch=fgetc(fp);
		while(ch != EOF)
		{
			printf("%c",ch);
			ch=fgetc(fp);
		}
		fclose(fp);

	}

}
void Add_Product_Category()
{
	FILE *fp;
	char category[20];
	char *str;
	int n;
	fp=fopen("categories.txt","a");
	if(fp == NULL)
	{
		perror("\n Failed to open");

	}
	else
	{
		printf("\n Enter New Category :");
		scanf("%s",&category);
		str=strcat(category,"\n");
		printf("%s",str);
		n=fputs(str,fp);
		if(n>0)
		{
			printf("\ncategory added...");

		}
		else
		{
			printf("\nFailed to add category");
		}
	}
	fclose(fp);//to save data into file file pointer must be closed
}
void Add_Product()
{
	FILE *fp;
	struct Product p;
	int n;
	fp=fopen("product.db","ab");
	if(fp == NULL)
	{
		perror("\n Failed to open file");

	}
	else
	{
		printf("\nEnter id");
		scanf("%d",&p.id);
		printf("\nEnter Name");
		scanf("%s",&p.name);
		printf("\nEnter Category");
		scanf("%s",&p.category);
		printf("\nEnter Rate");
		scanf("%f",&p.rate);
		n=fwrite(&p,sizeof(p),1,fp);
		if(n>0)
		{
			printf("\n Product added....");
		}
		else
		{
			printf("\n Failed to  add....");
		}
	}
	fclose(fp);

}


void List_Products()
{
	FILE *fp;
	struct Product p;
	printf("\n List of products...\n");
	fp = fopen("product.db", "rb");
	if(fp == NULL)
	{
		perror("fopen() failed");
		return;
	}
	else
	{
		printf("\nID \t Name \t\t Category \t\t Rate");
		while(fread(&p,sizeof(p),1,fp)== 1)
		{
			printf("\n%d\t %s \t\t %s \t\t %f",p.id,&p.name,&p.category,p.rate);

		}
	}
	fclose(fp);

}

void Find_Product_by_name()
{
	char pname[20];
	FILE *fp;
	struct Product p;
	int flag=0;
	fp=fopen("product.db","rb");
	if(fp == NULL)
	{
		perror("\n Failed to open");
		return;
	}
	else
	{
		printf("\n Enter Product Name to find :");
		scanf("%s",&pname);

		while(fread(&p,sizeof(p),1,fp) == 1)
		{
			if(strcmp(&p.name,pname)==0)
			{

				printf("\n%d\t %s \t\t %s \t\t %f",p.id,&p.name,&p.category,p.rate);
				flag=1;
			}

		}
		if(flag==0)
		{
			printf("\n No Record Found....");
		}
	}
}

int comp_product_By_name(const void *p1, const void *p2)
{
	printf("hello");
//	struct Product *p=(struct Product*)p1;
//	struct Product *p4=(struct Product*)p2;

//	Product_t *p=(Product_t *)p1;
//	Product_t *p4=(Product_t *)p2;

	struct Product *p=(struct Product*)p1, *p4=(struct Product*)p2;
	int diff=strcmp((char *)p->name, (char *)p4->name);
	return diff;
}
void sort_Product_By_Name()
{
	FILE *fp;
	int n, i = 0;
	//struct Product arr[10];
	//struct Product p;
	Product_t arr[10];
	Product_t  p;
	fp=fopen("product.db","rb");
	if(fp == NULL)
	{
		perror("\n failed to open");
		return;
	}
	else
	{
		while(fread(&p, sizeof(Product_t), 1, fp) == 1)
		{
			arr[i]=p;
			i++;
		}


		qsort(arr,i,sizeof(Product_t),comp_product_By_name);
		printf("\n List Of product sorted by Name\n");
		printf("\nId \t Name \t Category \t Price\n");
		for(int j=0;j<i;j++)
		{
			printf("\n %d \t %s \t %s \t %f",arr[j].id,&arr[j].name,&arr[j].category,arr[j].rate);
		}

	}
}

int comp_product_By_price(const void *e1, const void *e2)
{
	printf("hello");
	struct Product *p1=(struct Product*)e1, *p2=(struct Product*)e2;
	double diff = p1->rate - p2->rate;
	if(diff > 0)
		return +1;
	if(diff < 0)
		return -1;
	return 0;
}

void sort_Product_By_Price()
{
	FILE *fp;
	int i=0,n;
	struct Product arr[10];
	struct Product p;
	fp=fopen("product.db","rb");
	if(fp == NULL)
	{
		perror("\n failed to open");
		return;
	}
	else
	{
		while(fread(&p,sizeof(p),1,fp)==1)
		{
			arr[i++]=p;
		}
		qsort(arr,i,sizeof(struct Product),comp_product_By_price);
		printf("\nList of Product ascending order of price\n");
		printf("\nId \t Name \t Category \t Price\n");
		for(int j=0;j<i;j++)
		{
			printf("\n %d \t %s \t %s \t %f",arr[j].id,&arr[j].name,&arr[j].category,arr[j].rate);
		}

	}
}


int main(void)
{
	int choice;


	while((choice=main_menu())!=0)
	{
		switch(choice)
		{
		case 0:
			exit(0);
			break;
		case 1:
			Register_customer();
			break;
		case 2:
			Customer();
			break;
		case 3:
			Admin();
			break;
		default:
			printf("\n Invalid choice....");
			break;
		}
	}
	return EXIT_SUCCESS;
}

void Customer(void)
{
	int choice;
	do
	{
		printf("\n0.Exit\n"
				"1.List Product categories\n"
				"2.Product items per category(sorted by name)\n"
				"3.Product items per category(sorted by price)\n"
				"4.Order an item\n"
				"5.List pending orders\n"
				"6.List delivered orders\n");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
		case 0:
			exit(0);
			break;
		case 1:
			List_Product_categories();
			break;
		case 2:
			sort_Product_By_Name();
			break;
		case 3:
			sort_Product_By_Price();
			break;
		case 4:
			//order_item();
			break;
		case 5:
			//pending_order();
			break;
		case 6:
			//delivered_order();
			break;
		default:
			printf("\n Invalid choice....");
			break;
		}
	}while(choice!=0);

}
int sub_menu_admin()
{
	int choice;
	fflush(stdin);
	printf("\n\n0.Exit\n"
			"1.List Product categories\n"
			"2.Add Product Categories\n"
			"3.List all Products\n"
			"4.Find Product by name\n"
			"5.Edit Product\n"
			"6.Delete Product\n"
			"7.List pending orders\n"
			"8.List delivered orders\n"
			"9.Dispatch Order\n"
			"10.Add Product\n");
	printf("\nAdmin ...\nEnter your choice:");
	scanf("%d",&choice);
	return choice;

}
void Admin(void)
{
	int choice;

	while((choice=sub_menu_admin()) != 0)
	{
		switch(choice)
		{
		case 0:
			return;
			break;
		case 1:
			List_Product_categories();
			break;
		case 2:
			Add_Product_Category();
			break;
		case 3:
			List_Products();
			break;
		case 4:
			Find_Product_by_name();
			break;
		case 5:
			//Edit_Product();
			break;
		case 6:
			//Delete_Product();
			break;
		case 7:
			//List_Pending_Orders();
			break;
		case 8:
			//List_delivered_Orders();
			break;
		case 10:
			Add_Product();
			break;
		default:
			printf("\n Invalid choice....");
			break;
		}
	}

}


