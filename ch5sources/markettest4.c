/* markettest4.c */
/* supermarket reordering simulation */	
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/* functions defined at the end of the program */
void reorder();/* Call a reorder function */
void updatefunc();/* Increase stock function */
void decreasefunc();/* Decrease stock function */

/* structure for each item in stock.*/
/* The "desc" part is the name of a type of cheese  */
/* "limit" is the minimum level of stock */
/* after which a re-order is required */
/* "numstock is the current level of the item */
/* "address" is where to get the order */

struct super {
   int ID;
   char desc[11];
   int limit;
   int numstock;
   char address[30];
   };

struct super s1;
struct super s2;
struct super st[17];
FILE *fp;
long int minusone = -1;
int i;

int main()
{
	 	
	int numread;
	int stockitemID,updateamount;
	char update;
	
	/* open the supermarket file */
	fp=fopen("superm.dat", "r");

	/* Read and print out all of the records on the file */
	printf("\nID     DESCRIPTION     LIMIT     NUMBER IN STOCK      ADDRESS   ");
	for(i=0;i<17;i++)
	{
		numread=fread(&s2, sizeof(s2), 1, fp);

		if(numread == 1)
		{
			printf("\n%2d    : %s       : %d          : %d         : %s", s2.ID,s2.desc,s2.limit,s2.numstock,s2.address); /* note the 2d as we want 2 digits */
		}
		else {
			/* If an error occurred on read then print  out message */
 
       			if (feof(fp))

          			printf("Error reading superm.dat : unexpected end of file fp is %p\n",fp);

       			else if (ferror(fp))
	 		{
         	 		perror("Error reading superm.dat");
      	 		}
		}

	
	}
	/* Close the file */

	fclose(fp);

	/* Ask the user what they want to do with the file */
	/* Increase or decrease the stock ? */

	printf("\nIs this a Stock update(increase) ? (y or n)  \n");
	scanf("%c", &update);
	printf("\n answer is %c\n",update);
	if(update == 'y')
	{
		/* User wants to update(increase) stock level */
		printf("\nenter ID   \n");
		scanf("%d", &stockitemID);	

		printf("\n ID is %d",stockitemID);

		printf("\nenter update amount   \n");
		scanf("%d", &updateamount);

		/* Call function to update the stock */	
		updatefunc(stockitemID,updateamount);
		

		return;
	}
	else if(update == 'n')
	{
		/* User wants to decrease stock level */
		printf("\nenter ID   \n");
		scanf("%d", &stockitemID);	

		printf("\n ID is %d",stockitemID);

		printf("\nenter number sold   \n");
		scanf("%d", &updateamount);	

		printf("\n number sold entered is %d",updateamount);
		
		/* Call function to decrease the stock */
		decreasefunc(stockitemID,updateamount);
		fclose(fp);

		return;
	}

			
	
}
void reorder()
{
	/* Function to say that you have reordered and the address */
	printf("\nreorder called");
	printf("\n  address is  is %s",s2.address);
}
void updatefunc(int stockitemID,int updateamount)
{

	/* Increase stock function */

	/* Function to update current level of stock */
	/* After you to a read the file pointer will be */
	/* pointing to the next record in the file */
	/* So we move the file pointer backwards to */
	/* Point to the record we have just read */
	/* using the fseek command */
	
	printf("\nupdate called");
	printf("\nstockitemID is %d updateamount is %d\n",stockitemID,updateamount);
	fp = fopen("superm.dat", "r+");
	for (i = 0;i < 17;i++)
	{
		/* Read each pressure data from file sequentially */

		fread(&s2, sizeof(s2), 1, fp);
		
		if(s2.ID == stockitemID)
		{
			/* We have found the one we want to update */
			s2.numstock = s2.numstock + updateamount;


			fseek(fp,minusone*sizeof(s2),SEEK_CUR);


			fwrite(&s2, sizeof(s2), 1, fp);

			printf("\n ID is %d",s2.ID);
			printf("\n limit is %d",s2.limit);
			printf("\n numstock is %d",s2.numstock);		
			printf("\n address is %s",s2.address);

			fclose(fp);
			break;
		}
	}
}
void decreasefunc(int stockitemID,int updateamount)
{

		/* Decrease stock function */

		/* After you to a read the file pointer  will be */
		/* pointing to the next record in the file */
		/* So we move the file pointer backwards to */
		/* Point to the record we have just read */
		/* using the fseek command */

		/* Open supermarket file */

		fp = fopen("superm.dat", "r+");
		for (i = 0;i < 17;i++)
		{
		
			fread(&s2, sizeof(s2), 1, fp);
		
			if(s2.ID == stockitemID)
			{
	
				st[i].ID = s2.ID;
				st[i].limit = s2.limit;
				st[i].numstock = s2.numstock;

				/*printf("\n numstock is %d",st[i].numstock);
				printf("\n limit is %d",s2.limit);
				printf("\n number sold is %d",updateamount);*/
				if(st[i].numstock == 0)
				{
					printf("\n Out of stock");

					printf("\n numstock is %d",st[i].numstock);
					printf("\n limit is %d",s2.limit);
					printf("\n number sold is %d",updateamount);

					break;
				}

		
				if(st[i].numstock  - updateamount <= 0)
				{
					/*After decrease, stock level is zero or below*/

					printf("\nStock update");
					st[i].numstock = 0;/* set to zero (negative is impossible) */
					s2.numstock = st[i].numstock;
				
					/*printf("\n numstock is %d",st[i].numstock);
					printf("\n limit is %d",s2.limit);
					printf("\n number sold is %d",updateamount);
					printf("\n numstock is %d",s2.numstock);
				
					fseek(fp,minusone*sizeof(s2),SEEK_CUR);

					fwrite(&s2, sizeof(s2), 1, fp);*/
					reorder();
				
				}
				else if(st[i].numstock  - updateamount <= s2.limit)
				{
					/*After decrease, stock level is below limit*/
					printf("\nStock update");
					s2.numstock = st[i].numstock-updateamount;
				
					/*printf("\n limit is %d",s2.limit);
					printf("\n number sold is %d",updateamount);
					printf("\n numstock is %d",s2.numstock);
				
					fseek(fp,minusone*sizeof(s2),SEEK_CUR);

					fwrite(&s2, sizeof(s2), 1, fp);*/
					reorder();
				}
				else
				{
					/*After decrease, stock level is above limit*/
					printf("\nStock update");
					st[i].numstock = st[i].numstock - updateamount;
					s2.numstock = st[i].numstock;
					/*fseek(fp,minusone*sizeof(s2),SEEK_CUR);
					printf("\n numstock is %d",s2.numstock);
					fwrite(&s2, sizeof(s2), 1, fp);*/
				}
				printf("\n limit is %d",s2.limit);
				printf("\n number sold is %d",updateamount);
				printf("\n numstock is %d",s2.numstock);
				
				/* Move the file pointer back by one record */
				fseek(fp,minusone*sizeof(s2),SEEK_CUR);

				fwrite(&s2, sizeof(s2), 1, fp);
				
				break;
			}
		}
		

}
