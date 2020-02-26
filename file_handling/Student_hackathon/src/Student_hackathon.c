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
	char name[30];
	char address[30];
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
	char status[20];
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
		printf("\nEnter id :");
		scanf("%d",&p.id);
		printf("\nEnter Name :");
		scanf("%s",&p.name);
		printf("\nEnter Category :");
		scanf("%s",&p.category);
		printf("\nEnter Rate :");
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
		printf("\nID \t Name \t   Category \t Rate\n");
		while(fread(&p,sizeof(p),1,fp)== 1)
		{
			printf("\n%-7d %-10s  %-10s  %f",p.id,&p.name,&p.category,p.rate);

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

    struct Product *p=(struct Product*)p1, *p4=(struct Product*)p2;
	int diff=strcmp((char *)p->name, (char *)p4->name);
	return diff;
}
void sort_Product_By_Name()
{
	FILE *fp;
	int n, i = 0;
	char category[20];

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
		printf("\nEnter Category :");
		scanf("%s",&category);
		while(fread(&p, sizeof(Product_t), 1, fp) == 1)
		{
			if(strcmp(p.category,category)==0)
			{
			  arr[i]=p;
			  i++;
			}
		}


		qsort(arr,i,sizeof(Product_t),comp_product_By_name);
		printf("\n List Of product sorted by Name\n");
		printf("\nID \t Name \t   Category \t Rate\n");
		for(int j=0;j<i;j++)
		{
			printf("\n%-7d %-10s  %-10s  %f",arr[j].id,&arr[j].name,&arr[j].category,arr[j].rate);
		}
		printf("\n");
	}
}

int comp_product_By_price(const void *e1, const void *e2)
{

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
	char category[20];
	fp=fopen("product.db","rb");
	if(fp == NULL)
	{
		perror("\n failed to open");
		return;
	}
	else
	{
		printf("\nEnter Category :");
		scanf("%s",&category);
		while(fread(&p,sizeof(p),1,fp)==1)
		{
			if(strcmp(p.category,category)==0)
			{
			  arr[i]=p;
			  i++;
			}
		}
		qsort(arr,i,sizeof(struct Product),comp_product_By_price);
		printf("\nList of Product ascending order of price\n");
		printf("\nID \t Name \t   Category \t Rate\n");
		for(int j=0;j<i;j++)
		{
			printf("\n%-7d %-10s  %-10s  %f",arr[j].id,&arr[j].name,&arr[j].category,arr[j].rate);
		}
		printf("\n");

	}
}

void order_item()
{
	struct Order o;
	FILE *fp;
	fp=fopen("order.db","ab");
	if(fp==NULL)
	{
		perror("\n Failed to open...");
		return;
	}
	else
	{
		printf("\nEnter Order Details ....\n");
		printf("\nEnter order ID :");
		scanf("%d",&o.id);
		printf("\nEnter Customer ID :");
		scanf("%d",&o.customer_id);
		printf("\nEnter Product ID :");
		scanf("%d",&o.product_id);
		printf("\nEnter Quantity :");
		scanf("%d",&o.quantity);
		printf("\nEnter order status (pending):");
		scanf("%s",&o.status);
		printf("\nEnter order Date (dd/MM/yy) :");
		scanf("%d/%d/%d",&o.order_date.day,&o.order_date.month,&o.order_date.year);
		int n=fwrite(&o,sizeof(o),1,fp);
		if(n>0)
		{
			printf("\nOrder placed Successfully...");

		}
		else
		{
			printf("\nFailed to placed order...");
		}

	}
	fclose(fp);

}
void pending_order(int custid,char *cname)
{
	FILE *fp,*fs;
	int n;
	struct Order o;
	struct Product p;
	int flag=0;
	char status[20]="pending";
	fp=fopen("order.db","rb");
	fs=fopen("product.db","rb");
	if(fp==NULL && fs==NULL)
	{
		perror("\n Failed to open...");
		return;
	}
	else
	{
		printf("\n Welcome %s\n",cname);
		printf("\n List of Pending Orders...");
		printf("\nOrderID \t Name \t Qty\n");
		while(fread(&o,sizeof(o),1,fp)==1)
		{
			if(strcmp(o.status,status)==0 && o.customer_id==custid)
			{
				flag=1;
				while(fread(&p,sizeof(p),1,fs)==1)
				{
				   if(p.id==o.product_id)
				   {
					   printf("\n %-5d \t\t %-10s %-5d",o.id,p.name,o.quantity);
				   }
				}

			}
		}
	}
    if(flag==0)
    {
    	printf("\nNo pending Orders...\n");
    }
  fclose(fp);

}

void delivered_order(int custid,char *cname)
{
		FILE *fp,*fs;
		int n;
		struct Order o;
		struct Product p;
		int flag=0;
		char status[20]="delivered";
		fp=fopen("order.db","rb");
		fs=fopen("product.db","rb");
		if(fp==NULL && fs==NULL)
		{
			perror("\n Failed to open...");
			return;
		}
		else
		{
			printf("\n Welcome %s\n",cname);
			printf("\n List of Delivered Orders...");
			printf("\nOrderID \t Product ID \t Qty\n");
			while(fread(&o,sizeof(o),1,fp)!=0)
					{
				       // printf("\nwhile...");
						if(strcmp(o.status,status)==0 && o.customer_id==custid)
						{
							// printf("\nif...");
							   printf("\n %-5d \t\t %-10d %-5d",o.id,o.product_id,o.quantity);
							 flag=1;
//							while(fread(&p,sizeof(p),1,fs)==1)
//							{
//								printf("\np.while..");
//								printf("o:%d p:%d",o.product_id,p.id);
//							   if(p.id==o.product_id)
//							   {
//								   printf("\np while...");
//								   printf("\n %-5d \t\t %-10s %-5d",o.id,p.name,o.quantity);
//							   }
//							}

						}
					}
		}
	    if(flag==0)
	    {
	    	printf("\nNo delivered Orders...\n");
	    }
      fclose(fp);

}
void List_Pending_Orders()
{
	    FILE *fp;
		int n;
		struct Order o;

		int flag=0;
		char status[20]="pending";
		fp=fopen("order.db","rb");

		if(fp==NULL)
		{
			perror("\n Failed to open...");
			return;
		}
		else
		{

			printf("\n List of Pending Orders...\n");
			printf("\nOrderID \t ProductID\t Qty \t CustomerID \t Status \t OrderDate\n");
			while(fread(&o,sizeof(o),1,fp)==1)
			{
				if(strcmp(o.status,status)==0)
				{
					flag=1;
					printf("\n%-5d \t\t %-5d \t \t%d \t %d \t\t %-10s \t %d/%d/%d",o.id,o.product_id,o.quantity,o.customer_id,&o.status,o.order_date.day,o.order_date.month,o.order_date.year);



				}
			}
		}
	    if(flag==0)
	    {
	    	printf("\nNo pending Orders...\n");
	    }


}
void List_delivered_Orders()
{
	  FILE *fp;
			int n;
			struct Order o;

			int flag=0;
			char status[20]="delivered";
			fp=fopen("order.db","rb");

			if(fp==NULL)
			{
				perror("\n Failed to open...");
				return;
			}
			else
			{

				printf("\n List of Pending Orders...\n");
				printf("\nOrderID \t ProductID\t Qty \t CustomerID \t Status \t OrderDate\n");
				while(fread(&o,sizeof(o),1,fp)==1)
				{
					if(strcmp(o.status,status)==0)
					{
						flag=1;
						printf("\n%-5d \t\t %-5d \t \t%d \t %d \t\t %-10s \t %d/%d/%d",o.id,o.product_id,o.quantity,o.customer_id,&o.status,o.order_date.day,o.order_date.month,o.order_date.year);



					}
				}
			}
		    if(flag==0)
		    {
		    	printf("\nNo delivered Orders...\n");
		    }

}
void Delete_Product()
{

		FILE *fs, *fd;
		struct Product p;
		int id, found=0;
		printf("\nEnter  Product id to delete: ");
		scanf("%d", &id);
		fs = fopen("product.db", "rb");
		if(fs == NULL)
		{
			perror("\nfopen() failed");
			return;
		}
		fd = fopen("temp.db", "ab");
		if(fd == NULL)
		{
			perror("\nfopen() failed");
			return;
		}
		while(fread(&p, sizeof(p), 1, fs) != 0)
		{
			if(p.id == id)
				found = 1;
			else
				fwrite(&p, sizeof(p), 1, fd);
		}
		fclose(fd);
		fclose(fs);
		remove("product.db");
		rename("temp.db", "product.db");

		if(found == 0)
			printf("\nNo such product found...\n");
		else
		{
			printf("\n Product Deleted successfully..\n");
		}



}

void Edit_Product()
{
	FILE *fp;
	int n,productId;
	struct Product p;
	int flag=0;
	long size=sizeof(struct Product);
	fp=fopen("product.db","rb+");
	if(fp == NULL)
	{
		perror("\nFailed to open..");
		return;
	}
	else
	{
		printf("\n Enter Product ID to Find :");
		scanf("%d",&productId);
		while(fread(&p,sizeof(p),1,fp)!=0)
		{
			if(p.id==productId)
			{
				flag=1;
				printf("\n Old Record...");
				printf("\nId \t Name \t Category \t Rate");
				printf("\n%d\t %s \t %s \t %f",p.id,&p.name,&p.category,p.rate);
				printf("\nEnter id :");
				scanf("%d",&p.id);
				printf("\nEnter Name :");
				scanf("%s",&p.name);
				printf("\nEnter Category :");
				scanf("%s",&p.category);
				printf("\nEnter Rate :");
				scanf("%f",&p.rate);
				fseek(fp, -size, SEEK_CUR);
				n=fwrite(&p,sizeof(p),1,fp);
				if(n>0)
				printf("\nProduct update successfully..");
				else
				{
					printf("\nFail to update..");
				}

			}

		}
	}

	if(!flag)
	{
		printf("\nNo Product Find...\n");
	}
	fclose(fp);

}
void Dispatch_order()
{
	    FILE *fp;
		int n,orderId;
		struct Order o;
		int flag=0;
		char status[20]="pending";
		long size=sizeof(struct Order);
		fp=fopen("order.db","rb+");
		if(fp == NULL)
		{
			perror("\nFailed to open..");
			return;
		}
		else
		{
			printf("\n Enter Order ID to Find :");
			scanf("%d",&orderId);
			while(fread(&o,sizeof(o),1,fp)!=0)
			{
				if(o.id==orderId && strcmp(o.status,status)==0)
				{
					flag=1;

					printf("\nEnter Status :");
					scanf("%s",&o.status);

					fseek(fp, -size, SEEK_CUR);
					n=fwrite(&o,sizeof(o),1,fp);
					if(n>0)
					printf("\nOrder status update successfully..");
					else
					{
						printf("\nFail to update..");
					}

				}

			}
		}

		if(!flag)
		{
			printf("\nNo pending order Find...\n");
		}
		fclose(fp);

}
int main(void)
{
	int choice;


	while((choice=main_menu())!=0)
	{
		switch(choice)
		{
		case 0:
			printf("\n Logout.....");
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
	int flag=0;
	FILE *fp;
	struct Customer c;
	int n,custid;
	fp=fopen("customers.db","rb");
	if(fp == NULL)
	{
		perror("\n Failed to open file");
		exit(0);
	}
	else
	{
		printf("\nEnter Customer Id:");
		scanf("%d",&custid);

		while(fread(&c,sizeof(c),1,fp)==1)
		{
			if(c.id==custid)
			{
				flag=1;
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
				    return;
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
					order_item();
					break;
				case 5:
					pending_order(custid,c.name);
					break;
				case 6:
					delivered_order(custid,c.name);
					break;
				default:
					printf("\n Invalid choice....");
					break;
				}
			}while(choice!=0);
		 }
		}
    }
	if(flag==0)
	{
		printf("\n No customer Record Found...");
	}

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
			Edit_Product();
			break;
		case 6:
			Delete_Product();
			break;
		case 7:
			List_Pending_Orders();
			break;
		case 8:
			List_delivered_Orders();
			break;
		case 9:
			Dispatch_order();
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


