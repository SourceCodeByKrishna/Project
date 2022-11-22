#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<time.h>
struct Products
{
	int ID;
	char Name[50];
	char Description[50];
	int Quantity;
	struct Products *Next;
};

struct Sales
{
	int  SaleID;
	int  NoItems;
	char DateTime[25];
	char Cart[20][10];
	struct Sales *Next;
};
struct Products *Head;
struct Sales *SalesHead;

void Options();
void Register();
int  Login();
void Menu();
int  MenuOptions();
void Product();
int  ProductOptions();
void AddProduct();
void UpdateProduct();
void ShowProducts();
void DeleteProduct();
void Sale();
int  SaleOptions();
void MakeSale();
void SaleDisplay();
void ProductReport();
void SalesReport();
void UpdateProductFile();
void LoadProductFile();
void UpdateSalesFile();
void EffectProducts(int, int);
char *JoinStrings(char [],char []);
char *GetTime();

void main()
{
	
	LoadProductFile();
	Options();
	UpdateProductFile();
	UpdateSalesFile();
	return;
}

void Options()
{
	int Option;
	int Log=0;
	do
	{
		printf("\n Do you want to");
		printf("\n \t 1. Register");
		printf("\n \t 2. Login");
		printf("\n \t 0. Exit");
		scanf("%d",&Option);
		switch(Option)
		{
			case 1:
				Register();
			break;
			case 2:
				Log = Login();
				if(Log==1)
					Menu();
				else
					printf("\n Please try again...");
			break;
			case 0: return;
			break;
			default: printf("Invalid");
			break;
		}
	}while(Option!=0);
	
}

//Register
void Register()
{
	int ID;
	int PASSWORD;
	int REENTRY;
	printf("\n Enter Your ID:");
	scanf("%d",&ID);
	printf("\n Enter Your Password");
	scanf("%d", &PASSWORD);
	printf("\n Re-enter Your Password");
	scanf("%d", &REENTRY);
	return;
}

//Login
int Login()
{
	int ID;
	int PASSWORD;
	printf("\n Enter Your ID:");
	scanf("%d",&ID);
	printf("\n Enter Your Password");
	scanf("%d", &PASSWORD);
	return 1;
}

//Menu
void Menu()
{
	int Option;
	
	do{
		Option = MenuOptions();
		switch(Option)
		{
			case 1: Product();
			break;
			case 2: Sale();
			break;
			case 3: ProductReport();
			break;
			case 4: SalesReport();
			break;
			case 0: return;
			default: printf("\n Invalid Option \n");
			break;
		}
	}while(Option!=0);
	
	return;
}

//Menu Display
int MenuOptions()
{
	int Option;
	printf("\n ###########INVENTORY CONTROL###########");
	printf("\n 1. Product");
	printf("\n 2. Sale");
	printf("\n 3. Get the Sale Report");
	printf("\n 4. Get the Product Report \n");
	scanf("%d", &Option);
	return Option;	
}

/* #########Product Section########## */

//Product
void Product()
{
	int Option = ProductOptions();
	switch(Option)
	{
		case 1: AddProduct();
		break;
		case 2: UpdateProduct();
		break;
		case 3: ShowProducts();
		break;
		case 4: DeleteProduct();
		break;
	}
}

//Product Options
int ProductOptions()
{
	int Option;
	printf("\n ###########PRODUCT OPTIONS###########");
	printf("\n 1. Add a product");
	printf("\n 2. Update a product");
	printf("\n 3. Display the Product");
	printf("\n 4. Delete a product \n");
	scanf("%d",&Option);
	return Option;
}

//Add Product
void AddProduct()
{
	int ID, Quantity;
	char Name[50], Description[50];
	printf("\n#########ADD PRODUCT#############");
	printf("\n Enter product ID:");
	scanf("%d",&ID);
	printf("\n Enter new name:");
	scanf("%s",Name);
	printf("\n Enter description:");
	scanf("%s",Description);
	printf("\n Enter Quantity:");
	scanf("%d",&Quantity);
	
	struct Products *D = (struct Products*)malloc(sizeof(struct Products));
 		D->ID= ID;
 		strcpy(D->Name, Name);
 		strcpy(D->Description,Description);
 		D->Quantity= Quantity;
 		D->Next=NULL;
	
	if(Head==NULL)
		{
		  Head=D;
		}
		else
		{
		 struct Products *Temp;
		 Temp = Head;
		  while(Temp->Next!=NULL)
		  {
		  Temp=Temp->Next;
		  }
		  Temp->Next=D;
		}	
	ShowProducts();
}

//Update Product
void UpdateProduct()
{
	int ID, Quantity,Update=0;
	printf("\n Enter the ID of product you want to update: 101(let)");
	scanf("%d", &ID);
	printf("\n Enter Quantity:");
	scanf("%d", &Quantity);
	struct Products *Temp;
		Temp = Head;
		  while(Temp!= NULL)
		 {
		 		if(Temp->ID==ID)
		 		{
		 			if(Quantity!=0)
		 			{
		 			Temp->Quantity = Quantity;
		 			Update=1;
		 			}
		 			
		 		}
		    Temp=Temp->Next;
		 }
		 if(Update==1)
		 {
		 printf("\n Successfully Updated...");
		 }
		 else
		 {
		 printf("\n Failed to Updated...");
		 }

	return;
}

//Show Product
void ShowProducts()
{
	if(Head==NULL)
	 {
	 printf("\n Empty");
	 }
	 else
	 {
	  struct Products *Temp;
	  Temp = Head;
	   while(Temp!=NULL)
	   {
	   printf("\n \t%d ",Temp->ID);
	   printf("%s \t",Temp->Name);
	   printf("%s \t",Temp->Description);
	   printf("\t %d",Temp->Quantity);
	   Temp=Temp->Next;
	   }
	 }
	
}

//Delete Product
void DeleteProduct()
{
	int ID;
	printf("\n ############DELETE PRODUCT##############");
	printf("\n Enter the ID of product you want to delete:");
	scanf("\n%d",&ID);
	if(Head==NULL)
	{
		  printf("\nEmpty..");
	}
	else
	{
		int firstNode = 0; 
		struct Products *Temp, *Current;
		Temp = Head;
		  while((Temp->Next != NULL) && (Temp->ID != ID))
		 {
		 		firstNode++;
		 		Current = Temp;
		    Temp=Temp->Next;
		 }
		 if(firstNode==0)
		 {
		 		Temp = Head;
		 		Head = Head->Next;
		 		free(Temp);
		 		printf("\n Deleted Successfully"); 
		 }
		 else
		 {
		 	if(Temp->ID == ID)  
      {  
            Current->Next = Temp->Next;  
            free(Temp);  
            printf("\n Deleted Successfully");  
      }
      else
      {
      	printf("\n Not Found");
      }
		 }
		 
		 
	}	
	
}

/* #########SALES SECTION############ */

//Sales
void Sale()
{
	int Option = SaleOptions();
	switch(Option)
	{
		case 1: MakeSale();
		break;
		case 2: SaleDisplay();
		break;
	}
	
}

int SaleOptions()
{
	int Options;
	printf("\n 1. Make sale");
	printf("\n 2. Display");
	scanf("%d", &Options);
	return Options;
}

//MakeSale
void MakeSale()
{
 	int ID, Quantity;
 	int Exit=0;
 	char Cart[10][20];
 	int count = 0;
 	int NoSales=0;
 	do
 	{
	printf("\n Enter Product ID:");
        scanf("%d",&ID);
        printf("\n Enter Quantity:");
	scanf("%d",&Quantity);
	EffectProducts(ID,Quantity);
	NoSales++;
	char StrQuant[10];
	char StrID[10];
	sprintf(StrID, "%d", ID);//Converts int to String
	sprintf(StrQuant, "%d", Quantity);//Converts int to String
	char *NewString;
	NewString = JoinStrings(StrID,StrQuant);//Joing Strings with < , >
	char String[50];
	strcpy(String, NewString); //Copies pointer value to string
	printf("%s",String);
	int i=0;
	while(String[i]!='\0')
	{
	 Cart[count][i]=String[i];
	 i++;
	}
	Cart[count][i]='\0'; // '\0' Denotes ending of individual String
	count++; 
	printf("\n Enter 1 to c \n");
	scanf("%d",&Exit);
	}while(Exit!=0);
	
	
	//printing Cart Data
	int j=0;
	while(j<count)
	{
	  printf("%s",Cart[j]);
	  j++;
	}
	
	
	//Save to Sales Linked List
	int i=0;
	char *DT = GetTime();
	char DATETIME[25];
	strcpy(DATETIME,DT);
	
	struct Sales *SalesNode = (struct Sales*)malloc(sizeof(struct Sales));
	
	SalesNode->SaleID = ID *10;
	SalesNode->NoItems = NoSales;
	//strcpy(SalesNode->DateTime,DATETIME);
	

	while(i<count)
	{
	  strcpy(SalesNode->Cart[i],Cart[i]);
	  i++;
	}
	
	if(SalesHead==NULL)
	{
         SalesHead=SalesNode;
	}
	else
	{
	 struct Sales *SalesTemp;
	 SalesTemp = SalesHead;
	 while(SalesTemp->Next!=NULL)
         {
          SalesTemp=SalesTemp->Next;
         }
	  SalesTemp->Next=SalesNode;
	}
	
	return;
}

void EffectProducts(int ID, int Quantity)
{
   struct Products *Temp;
		Temp = Head;
		  while(Temp!= NULL)
		 {
		 		if(Temp->ID==ID)
		 		{
		 			if(Quantity!=0)
		 			{
		 			Temp->Quantity = Temp->Quantity - Quantity;
		 			}
		 			
		 		}
		    Temp=Temp->Next;
		 }
		 return;
}







//Display
void SaleDisplay()
{
	
	if(SalesHead==NULL)
	 {
	 printf("\n Empty");
	 }
	 else
	 {
	  struct Sales *SalesTemp;
	  SalesTemp = SalesHead;
	   while(SalesTemp!=NULL)
	   {
	   printf("%d\n %s",SalesTemp->SaleID, SalesTemp->DateTime);

	   int i=0;
	   while(i<SalesTemp->NoItems)
	   {
	   printf("\n %s", SalesTemp->Cart[i]);
	   i++;
	   }
	   
	   SalesTemp=SalesTemp->Next;
	   }
	 }
	 
  return;
}

void ProductReport()
{
	printf("\n #########Product Report#############\n");
	ShowProducts();
}

void SalesReport()
{
	printf("\n ############Sales Report#############");
	SaleDisplay();
	
}



//FILES
void UpdateProductFile()
{

	FILE *W = fopen("Products.txt","w");
	if(Head==NULL)
	 {
	 printf("\n Empty");
	 }
	 else
	 {
	  struct Products *Temp;
	  Temp = Head;
	   while(Temp!=NULL)
	   {
		 fprintf(W,"%d %s %s %d\n",Temp->ID, Temp->Name, Temp->Description, Temp->Quantity); 
	   Temp=Temp->Next;
	   }
	 }
	fclose(W);
}


//Loads Products File
void LoadProductFile()
{
	int ID, Quantity;
	char Name[50], Description[50];
	FILE *R = fopen("Products.txt","r");
	while(fscanf(R,"%d %s %s %d",&ID,Name,Description,&Quantity)!=EOF)
	{
		//printf("\n %d %s %s %d",ID,Name,Description,Quantity);
		//char NM[50] = Name;
		//printf("\n NAME: %s",NM);
		
		struct Products *D = (struct Products*)malloc(sizeof(struct Products));
 		D->ID= ID;
 		strcpy(D->Name, Name);
 		strcpy(D->Description,Description);
 		D->Quantity= Quantity;
 		D->Next=NULL;
 		if(Head==NULL)
		{
		  Head=D;
		}
		else
		{
		 struct Products *Temp;
		 Temp = Head;
		  while(Temp->Next!=NULL)
		  {
		  Temp=Temp->Next;
		  }
		  Temp->Next=D;
		}	
	}
	
	fclose(R);
}

//Update Sales File
void UpdateSalesFile()
{
	FILE *A = fopen("Sales.txt","a");
	if(SalesHead==NULL)
	 {
	 printf("\n Empty");
	 }
	 else
	 {
	  struct Sales *SalesTemp;
	  SalesTemp = SalesHead;
	   while(SalesTemp!=NULL)
	   {
	   fprintf(A,"%d ",SalesTemp->SaleID);
	   int i=0;
	   	while(i<SalesTemp->NoItems)
	   	{
	   	fprintf(A,"%s  ",SalesTemp->Cart[i]);
	   	i++;
	   	}
	   	fprintf(A,"\n");
	         SalesTemp=SalesTemp->Next;
	   }
	 }
	fclose(A);
}


//Join Strings like <ID, Quantity>
char *JoinStrings(char String1[15],char String2[15])
{
	int i=0,j=1;
	char *STR =  (char *)malloc(sizeof(30));
	STR[0] = '<';
	
	while (String1[i] != '\0')// Insert First String
	{
        STR[j] = String1[i];
        i++;
        j++;
    	}
    
    i = 0;
    STR[j]=',';
    j++;
    while (String2[i] != '\0') {
        STR[j] = String2[i];
        i++;
        j++;
    }
    	STR[j] = '>';
    	j++;
	STR[j] = '\0';
	return STR;
}

char* GetTime()
{
	int point=0,count=0;
	time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  char *DateTime =  (char *)malloc(sizeof(25));
  char Day[3];
  char Month[3];
  char Year[5];
  char Hour[3];
  char Minute[3];
  char Seconds[3];
  char Date[15]; //Date like 22-11-2022
  char Time[15]; //Time like 15:20:60
  sprintf(Day, "%d", tm.tm_mday);
  sprintf(Month, "%02d",tm.tm_mon + 1);
  sprintf(Year, "%02d",tm.tm_year + 1900);
  sprintf(Hour, "%02d",tm.tm_hour);
  sprintf(Minute, "%02d",tm.tm_min);
  sprintf(Seconds, "%02d",tm.tm_sec);
  
  //Join Date with '-'
  while(Day[count]!='\0')
  {
  Date[point]= Day[count];
  point++;
  count++;
  }
  Date[point]='-';
  point++;
  count=0;
  while(Month[count]!='\0')
  {
  Date[point]= Month[count];
  point++;
  count++;
  }
  Date[point]='-';
  point++;
  count=0;
  while(Year[count]!='\0')
  {
  Date[point]= Year[count];
  point++;
  count++;
  }
  Date[point]='\0';
 
  
  //Joins Time with ':'
  point=0;
  count=0;
  while(Hour[count]!='\0')
  {
  Time[point] = Hour[count];
  point++;
  count++;
  }
  Time[point]=':';
  point++;
  count=0;
  while(Minute[count]!='\0')
  {
  Time[point]=Minute[count];
  point++;
  count++;
  }
  count=0;
  Time[point]=':';
  point++;
  while(Seconds[count]!='\0')
  {
  Time[point]=Seconds[count];
  point++;
  count++;
  }
  Time[point]='\0';
  
  point=0;
  count=0;
  while(Date[count]!='\0')
  {
  DateTime[point]=Date[count];
  point++;
  count++;
  }
  DateTime[point]=' ';
  point++;
  
  count=0;
  while(Time[count]!='\0')
  {
  DateTime[point]=Time[count];
  point++;
  count++;
  }
  DateTime[point]='\0';
  
  return DateTime;
}





