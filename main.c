#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct Products
{
	int ID;
	char Name[50];
	char Description[50];
	int Quantity;
	struct Products *Next;
};
struct Products *Head;
void Options();
void Register();
int Login();
void Menu();
int MenuOptions();
void Product();
int ProductOptions();
void AddProduct();
void UpdateProduct();
void ShowProducts();
void DeleteProduct();
void Sale();
void MakeSale();
void SaleDisplay();
void ProductReport();
void SalesReport();
void UpdateProductFile();
void LoadProductFile();

void main()
{
	
	LoadProductFile();
	Options();
	UpdateProductFile();
	return;
}

void Options()
{
	int Option=1;
	int Log=0;
	while(Option!=0)
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
	}
	
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
	int Option = 1;
	while(Option!=0)
	{
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
		}
	}
	
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
	//int Option = SaleOptions();
	switch(1)
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
	printf("\n Enter Product ID:");
	printf("\n Enter Quantity:");
}

//Display
void SaleDisplay()
{
	printf("\n Disply Sales");
}

void ProductReport()
{
	printf("\n Product Report");
}

void SalesReport()
{
	printf("\n Sales Report");
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
