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
void Display();
void Register();
int Login();
void Menu();
int MenuDisplay();
void Product();
int ProductDisplay();
void AddProduct();
void UpdateProduct();
void DisplayProducts();
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
  DisplayProducts();
	AddProduct();
	UpdateProductFile();
//	Display();
	return;
}

void Display()
{
	int Exit = 1;
	int Option;
	while(Exit!=0)
	{
		Exit = 0;
		int Log=0;
		printf("\n Do you want to");
		printf("\n \t 1. Register");
		printf("\n \t 2. Login");
		scanf("%d",&Option);
		Exit = Option;
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
	return 0;
}

//Menu
void Menu()
{
	int Option = 1;
	while(Option!=0)
	{
		Option = MenuDisplay();
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
int MenuDisplay()
{
	int Option;
	printf("\n 1. Add Product");
	printf("\n 2. Add Sale");
	printf("\n 3. Get the Sale Report");
	printf("\n 4. Get the Product Report");
	printf("\n 0. Exit");
	scanf("%d", &Option);
	return Option;	
}

//Product
void Product()
{
	int Option = ProductDisplay();
	switch(Option)
	{
		case 1: //AddProduct();
		break;
		case 2: UpdateProduct();
		break;
		case 3: //DisplayProducts();
		break;
		case 4: DeleteProduct();
		break;
	}
}

int ProductDisplay()
{
	int Option;
	printf("\n 1. Add a product");
	printf("\n 2. Update a product");
	printf("\n 3. Display the Product");
	printf("\n 4. Delete a product");
	scanf("%d",&Option);
}

//Add Product
void AddProduct()
{
	int ID, Quantity;
	char Name[50], Description[50];
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
	DisplayProducts();
}

//Update Product
void UpdateProduct()
{
	printf("\n Enter the ID of product you want to update: 101(let)");
	printf("\n Enter new name:");
	printf("\n Enter description:");
	printf("\n Enter Quantity:");
}

//Display Product
void DisplayProducts()
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
	printf("\n Enter the ID of product you want to delete:");
	printf("\n Product is deleted!!");
}

//Sales Part

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
		 fprintf(W,"\n%d %s %s %d",Temp->ID, Temp->Name, Temp->Description, Temp->Quantity); 
	   Temp=Temp->Next;
	   }
	 }
	fclose(W);
}

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
