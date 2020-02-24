/*
 ============================================================================
 Name        : write_textfile.c
 Author      : soniya shinde
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 fread() and fwrite()-write black of data binary file(refer when to write object of structure in file)
 fprintf() ,fputs(),fputc()-write data into text file used to write obejct of struct(fprintf())
 fgets(),fscanf(),fgetc()-read data from text file

 text file = -1 or EOF

 */

#include <stdio.h>
#include <stdlib.h>
struct emp
{
   int id;
   float sal;

};
int main1(void)
{

	//------------write mode using fwrite()------
	char str[10];
	int n;
	FILE *fp=NULL;
	fp=fopen("demo1.txt","w");
	if(fp==NULL)
	{
		printf("Error to open file");

	}
	else
	{
		printf("\n Enter String to write :");
		scanf("%s",&str);
		//gets(str);
	     printf("%s",str);
		n=fwrite(str,sizeof(char *),1,fp);//write data into txt file in binary format
		if(n>0)
			printf("data write successfully");
		else
			printf("fail to write");

	}


    return EXIT_SUCCESS;
}


int main2(void)
{



	//------------append mode write string using fputs()------
		char str[10];
		char *str2;
        char *fname;
		int n;
		FILE *fp=NULL;
		fp=fopen("demo2.txt","a");
		if(fp==NULL)
		{
			printf("Error to open file");

		}
		else
		{
			printf("\n Enter String to write :");
			scanf("%s",&str);

			str2=strcat(str,"\n");
		     printf("%s",str2);

			n=fputs(str2,fp);
			//n=fprintf(fp,str2);

			if(n>0)
				printf("data write successfully");
			else
				printf("fail to write");
			fclose(fp);

		}

		//----read data from text file


		fp=fopen("demo2.txt","r");
		str2=fgetc(fp);
		while(str2 != -1)
		{
			printf("%c",str2);
			str2=fgetc(fp);

		}
		fclose(fp);

	return EXIT_SUCCESS;
}


int main(void)
{



	//------------append mode write string using fputc() ------
		char str[10];
		char *str2;
        char *fname;
        char ch;
		int n;
		FILE *fp=NULL;
		fp=fopen("demo2.txt","a");
		if(fp==NULL)
		{
			printf("Error to open file");

		}
		else
		{
			printf("\n Enter String to write :");
			scanf("%s",&str);




			for(int i=0;i<strlen(str);i++)
			{
				n=fputc(str[i],fp);
			}
			fputc(10,fp);//10 is ascii value of \n

			if(n>0)
				printf("data write successfully\n");
			else
				printf("fail to write");
			fclose(fp);

		}

		//----read data from text file


		fp=fopen("demo2.txt","r");
		str2=fgetc(fp);
		while(str2 != -1)
		{
			printf("%c",str2);
			str2=fgetc(fp);

		}
		fclose(fp);

	return EXIT_SUCCESS;
}


