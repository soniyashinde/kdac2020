/*
 ============================================================================
 Name        : write_textfile.c
 Author      : soniya shinde
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 fread() and fwrite()-binary file(refer when to write object of structure in file)
 fprintf() ,fputs(),fputc()-write data into text file
 fgets(),fscanf(),fgetc()-read data from text file

 text file = -1 or EOF

 */

#include <stdio.h>
#include <stdlib.h>

int main1(void)
{

	//------------write mode------
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
		n=fwrite(str,sizeof(char *),1,fp);
		if(n>0)
			printf("data write successfully");
		else
			printf("fail to write");

	}


    return EXIT_SUCCESS;
}


int main2(void)
{



	//------------append mode write string ------
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



	//------------append mode write string ------
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
