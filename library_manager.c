#include<stdio.h>
#include<string.h>
int k=0,j=0;
struct book{
   char name[50];
   char author[20];
   int year;
   int price;
   int rent;
}b[100];
struct issue{
   char name[50];
   int number[20];
    int days;
   char book[50];
}b1[100];
void Book_entry(void);
void Issue_entry(void);
void search(void);
void dispaly_books(void);
void calculation(void);

int main()
{  
    printf("Welcome to library manager\n");
    int n;
    do{
    printf("1. Book Entry\n");
    printf("2. Issuer entry\n");
    printf("3. Search books\n");
    printf("4. Display books\n");
    printf("5. Calculation of book rent and price\n");
    printf("6. Exit \n");
    printf("Select the option:  ");
    scanf("%d",&n);
      switch(n)
    {   
        case 1:{
        Book_entry();
        break;
        }
        case 2:{
        Issue_entry();
        break;
        }
        case 3:{
        search();
        break;
        }
        case 4:{
        dispaly_books();
        break;
        }
        case 5:{
           calculation();
           break;
           }
        case 6:{
            break;
        }

    }
    
    }while(n!=8);
   return 0;
}


void Book_entry(void)
{   int n,i; 
    FILE *fo;
    struct book b[100];
    fo=fopen("data.txt","a+");
   printf("enter the number of entries:  ");
   scanf("%d",&n);
   if(fo==NULL)
   {
    printf("file is not opening");
   }
   else
   {
   for(i=0;i<n;i++)
   { 
    printf("Book name: ");
     scanf(" %s",b[i].name);
     printf("Author name: ");
     scanf(" %s",b[i].author);
     printf("Book publising year: ");
     scanf("%d",&b[i].year);
     printf("Book price: ");
     scanf("%d",&b[i].price);
     printf("Book rent: ");
     scanf("%d",&b[i].rent);

    fprintf(fo, "%d\n%s\n%s\n%d\n%d\n%d\n\n", i + 1, b[i].name, b[i].author, b[i].year, b[i].price, b[i].rent);

    
   }

   printf("The entries are made sucessfully in the data file\n\n");
    fclose(fo);
   }
}

void Issue_entry(void)
{
    int n,i;
    FILE *fe;
    fe=fopen("isuue_data.txt","a+");
    printf("enter the number of entires:  ");
    scanf("%d",&n);
    if(fe==NULL)
    {
        printf("file is not opening");
    }
    else
    {
    for(i=0;i<n;i++)
    {
        printf("enter the name:  ");
        scanf("%s",b1[k].name);
        printf("enter the Phone number;  ");
        scanf("%d",&b1[k].number);
        printf("enter the number of days:  ");
        scanf("%d",&b1[k].days);
        printf("enter the book name:  ");
        scanf("%s",b1[k].book);

        fprintf(fe,"\n%d. %s\n%d\n%d\n%s\n\n",k+1,b1[k].name,b1[k].number,b1[k].days,b1[k].book);
        k++;
    }
    fclose(fe);
    printf("all entries were made successfully\n\n");
    }
}

void search(void)
{   
    FILE *fo;
    char book[50],author[50];
    int n,i,count=0,year;
    fo=fopen("data.txt","r");
    printf("1. search by book name\n");
    printf("2. search by author's name\n");
    printf("3. search by publishing year\n");
    printf("select an option:  ");
    scanf("%d",&n);
    if(n==1)
    {
        printf("enter the Book name:  ");
        scanf("%s",book);
        for(i=0;i<j;i++)
        {
            if((strcmp(book,b[i].name))==0)
            {
                printf("\n%d. %s\n%s\n%d\n%d\n%d\n",i+1,b[i].name,b[i].author,b[i].year,b[i].price,b[i].rent);
                break;
            }
        }
    }
    if(n==2)
    {
          printf("enter the author's name:  ");
        scanf("%s",author);
        for(i=0;i<j;i++)
        {
            if((strcmp(author,b[i].author))==0)
            {   count++;
                printf("\n%d. %s\n%s\n%d\n%d\n%d\n",i+1,b[i].name,b[i].author,b[i].year,b[i].price,b[i].rent);
            }
        }
        if(count==0)
        {
            printf("entry not found");
        }

    }
        if(n==3)
    {
          printf("enter the publising year:  ");
        scanf("%d",&year);
        for(i=0;i<j;i++)
        {
            if(year==b[i].year)
            {   count++;
                printf("\n%d. %s\n%s\n%d\n%d\n%d\n",i+1,b[i].name,b[i].author,b[i].year,b[i].price,b[i].rent);
            }
        }
        if(count==0)
        {
            printf("entry not found");
        }

    }
}
 
void dispaly_books(void)
{
    int i;
    for(i=0;i<j;i++)
    {
    printf("\n%d. %s\n%s\n%d\n%d\n%d\n",i+1,b[i].name,b[i].author,b[i].year,b[i].price,b[i].rent);
    }
}

void calculation(void)
{
    int i,n,m,x;
    char name[50];
    char note[50];
    printf("enter the issuer name: ");
    scanf("%s",name);
    printf("enter the book name: ");
    scanf("%s",note);
    printf("enter the number of days: ");
    scanf("%d",&n);
    for(x=0;x<k;x++)
    {
        if(strcmp(name,b1[x].name)==0)
        {
        m=b1[x].days;
        break;
        }
    }
   for(i=0;i<j;i++)
   {
    
    if(strcmp(note,b[i].name)==0)
        {
        printf("book name: %s\n",b[i].name);
        printf("issuer name:%s\n",name);
        printf("book rent : %d\n",b[i].rent*m);
        printf("Penelty:%d\n",(n-m)*10);
        printf("total:%d\n",(b[i].rent*m)+((n-m)*10));
        break;
        }
    
    else
    {
        printf("entry not found");
        break;
    }
   }
}