#include<stdio.h>
void Display();
int Register();
int Login();
void main()
{
	Display();
	return;
}

void Display()
{
	int Exit = 1;
	int Option;
	while(Exit!=0)
	{
		Exit = 0;
		printf("\n Do you want to");
		printf("\n \t 1. Register");
		printf("\n \t 2. Login");
		switch(Option)
		{
			case 1: printf("Register");
			break;
			case 2: printf("Login");
			break;
			default: printf("Invalid");
			break;
		}
	}
	
}

//Register
int Register()
{
	printf("\n Enter Your ID:");
	printf("\n Enter Your Password");
	printf("\n Re-enter Your Password");
	return 0;
}

//Login
int Login()
{
	printf("\n Enter Your ID:");
	printf("\n Enter Your Password");
	return 0;
}

//Menu
void Menu()
{
	printf("\n 1. Add Product");
	printf("\n 2. Add Sale");
	printf("\n 3. Get the Sale Report");
	printf("\n 4. Get the Product Report");
	printf("\n 0. Exit");
}

//Product
void Product()
{
	printf("\n 1. Add a product");
	printf("\n 2. Update a product");
	printf("\n 3. Display the Product");
	printf("\n 4. Delete a product");
}

//Add Product
void AddProduct()
{
	printf("\n Enter product ID:");
	printf("\n Enter new name:");
	printf("\n Enter description:");
	printf("\n Enter Quantity:");
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
void DisplayProduct()
{
	printf("\n Display Product");
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
	printf("\n 1. Make sale");
	printf("\n 2. Display");
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
