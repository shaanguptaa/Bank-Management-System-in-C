#include<stdio.h>
#include<conio.h>
#include<string.h>
#define NO_OF_BOOKS 2

int i=0,book_no=0;
char a;
struct library          //***************Library structure**************//
{
	int id;
	char title[50];
	char author[50];
	char cat[20];
	int flag;
} book[NO_OF_BOOKS];

//********************* function declarations ******************//

void add_book();
void search_book();
void search_by_title();
void search_by_cat();
void search_by_id();
void edit_book();

//********************** main function *************************//

void main()
{
	clrscr();
	printf("\n1.  Add a new book\n");
	printf("\n2.  Search a book\n");
	printf("\n3.  Exit\n");
	printf("\n\nEnter your choice:");
	scanf("%d",&i);
	switch (i)
	{
		case 1: add_book();
				main();
		case 2: search_book();
				main();
		case 3: printf("\nPress any key to exit.....");
				getch();
				break;
		default: printf("\nEnter a valid choice\n\nPress any key to continue...\n");
				getch();
				main();
	}
}

//********************** add book function *********************//

void add_book()
{
	if (book_no<=NO_OF_BOOKS)
	{
	    clrscr();
		printf("\nEnter the id of the book:\n");
		scanf("%d",&book[book_no].id);
		printf("\nEnter the title of the book: (enter underscore instead of space)\n");
		scanf("%s",book[book_no].title);
		printf("\nEnter the name of the author: (enter underscore instead of space)\n");
		scanf("%s",book[book_no].author);
		printf("\nEnter the category of the book:\n");
		scanf("%s",book[book_no].cat);
		printf("\nIs the book available (y/n):");
		scanf("%s",&a);
		if(a=='y' || a=='Y')
			book[book_no].flag=0;
		else
			book[book_no].flag=1;
		clrscr();
		printf("\nID : %d\n",book[book_no].id);
		printf("\nTitle : %s\n",book[book_no].title);
		printf("\nAuthor : %s\n",book[book_no].author);
		printf("\nCategory : %s\n",book[book_no].cat);
		if (book[book_no].flag==0)
			printf("\nAvailability : Available\n\n");
		else
			printf("\nAvailability : Not Available\n\n");
		printf("\n\n\nBook added successfully...\n");
		printf("\n\nDo you want to edit the details of this book: (y/n)");
		scanf("%s",&a);
		if (a=='y' || a=='Y')
			edit_book();
		book_no++;
		printf("\n\nDo you want to add another book: (y/n)");
		scanf("%s",&a);
		if (a=='y' || a=='Y')
			add_book();
	}
	else
	{
		clrscr();
		printf("\n\nMax number of books reached....");
	}
}

//********************* search book function ***************************//

void search_book()
{
	clrscr();
	printf("\n1.  Search by title\n");
	printf("\n2.  Search by category\n");
	printf("\n3.  Search by ID\n");
	printf("\n4.  Back\n");
	printf("\n\nEnter your choice: ");
	scanf("%d",&i);
	switch (i)
	{
		case 1: search_by_title();
				search_book();
		case 2: search_by_cat();
				search_book();
		case 3: search_by_id();
				search_book();
		case 4: main();
	}
}

//******************** search by title ********************************//

void search_by_title()
{
	char title[50];
	clrscr();
	printf("\nEnter the Title of the book:\n");
	scanf("%s",title);
	for (i=0; i<NO_OF_BOOKS; i++)
	{
		if (strcmp(title,book[i].title)==0)
		{
			printf("\nID : %d\n",book[i].id);
			printf("\nTitle : %s\n",book[i].title);
			printf("\nAuthor : %s\n",book[i].author);
			printf("\nCategory : %s\n",book[book_no].cat);
			if (book[i].flag==0)
				printf("Availability : Available");
			else
				printf("Availability : Not Available");
			printf("\n\nDo you want to edit the details of this book: (y/n)");
			scanf("%s",&a);
			if (a=='y' || a=='Y')
				edit_book();
			break;
		}
		else if(i==NO_OF_BOOKS-1 && strcmp(title,book[i].title)!=0)
		{
			printf("\n\n\n\n\n\nBook not found....\n");
		}
	}
	getch();
}

//******************** search by category ****************************//

void search_by_cat()
{
	char cate[50];
	clrscr();
	printf("\nEnter the category:\n");
	scanf("%s",&cate);
	for(i=0;i<NO_OF_BOOKS;i++)
	{
		if (strcmp(cate,book[i].cat)==0)
		{
			printf("\nID : %d\n",book[i].id);
			printf("\nTitle : %s\n",book[i].title);
			printf("\nAuthor : %s\n",book[i].author);
			printf("\nCategory : %s\n",book[book_no].cat);
			if (book[i].flag==0)
				printf("Availability : Available");
			else
				printf("Availability : Not Available");
			printf("\n\nDo you want to edit the details of this book: (y/n)");
			scanf("%s",&a);
			if (a=='y' || a=='Y')
				edit_book();
			break;
		}
		else if(i==NO_OF_BOOKS-1 && strcmp(cate,book[i].cat)!=0)
		{
			printf("\n\n\n\n\n\n Book not found....\n");
		}
	}
	getch();
}

//************************************ search by ID *******************************//

void search_by_id()
{
	int ID;
	clrscr();
	printf("\nEnter the ID of the book:\n");
	scanf("%d",&ID);
	for(i=0;i<NO_OF_BOOKS;i++)
	{
		if (ID==book[i].id)
		{
			printf("\nID : %d\n",book[i].id);
			printf("\nTitle : %s\n",book[i].title);
			printf("\nAuthor : %s\n",book[i].author);
			printf("\nCategory : %s\n",book[book_no].cat);
			if (book[i].flag==0)
				printf("Availability : Available");
			else
				printf("Availability : Not Available");
			printf("\n\nDo you want to edit the details of this book: (y/n)");
			scanf("%s",&a);
			if (a=='y' || a=='Y')
				edit_book();
            break;
		}
		else if(i==NO_OF_BOOKS-1 && ID!=book[i].id)
		{
			printf("\n\n\n\n\n\n Book not found....\n");
		}
	}
	getch();
}

//************************** edit book *******************************//

void edit_book()
{
	int ce;
	clrscr();
	printf("\n1.  Change the Id\n");
	printf("\n2.  Edit the title\n");
	printf("\n3.  Change the name of author\n");
	printf("\n4.  Change the category of book\n");
	printf("\n5.  Change the availablity of book\n");
	printf("\n\n\nEnter your choice: ");
	scanf("%d",&ce);
	clrscr();
	switch (ce)
	{
		case 1: printf("\nEnter the new ID for the book:\n");
				scanf("%d",&book[book_no].id);
				break;
		case 2: printf("\nEnter the title of the book:\n");
				scanf("%s",book[book_no].title);
				break;
		case 3: printf("\nEnter the name of the author:\n");
				scanf("%s",book[book_no].author);
				break;
		case 4: printf("\nEnter the category of the book:\n");
				scanf("%s",book[book_no].cat);
				break;
		case 5: printf("\nIs the book available (y/n):");
				scanf("%s",a);
				book[book_no].flag=1;
				if (a=='y' || a=='Y')
				{
					book[book_no].flag=0;
				}
				break;
		default: printf("\nEnter valid choice");
				 printf("\n\nPress any key to continue....\n");
				 getch();
				 edit_book();
	}
	clrscr();
	printf("\nID : %d\n",book[book_no].id);
	printf("\nTitle : %s\n",book[book_no].title);
	printf("\nAuthor : %s\n",book[book_no].author);
	printf("\nCategory : %s\n",book[book_no].cat);
	if (book[book_no].flag==0)
		printf("Availability : Available");
	else
		printf("Availability : Not Available");
	if(ce==1)
		printf("\n\n\nID Changed Successfully...");
	else if (ce==2)
		printf("\n\n\nTitle Changed Successfully...");
	else if (ce==3)
		printf("\n\n\nName of Author Changed Successfully...");
	else if (ce==4)
		printf("\n\n\nCategory Changed Successfully...");
	else if (ce==5)
		printf("\n\n\nAvailability of Book Changed Successfully...");
	printf("\n\n\nDo you want to edit other details: (y/n) ");
	scanf("%s",&a);
	if (a=='y' || a=='Y')
		edit_book();
}
