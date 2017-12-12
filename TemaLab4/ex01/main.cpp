#include <iostream>
#include <unistd.h>
#include <string.h>
using namespace std;

class Product
{
	string product_type;
	string product_name;
	float price;
	string barcode;
	public:

		void setProductType(string type);
		void setProductName(string name);
		void setPrice(float p);
		void setBarcode(string barcode);

		string getProductType();
		string getProductName();
		float getPrice();
		string getBarcode();

		Product();
		Product(string t, string n);
		Product(string t, string n, float p);
		Product(string t, string n, float p, string b);
	friend bool ComparePrices(Product p1, Product p2);
};
//constructors
Product::Product()
{
	product_type = "Universal";
	product_name = "Anything";
	price = 0;
	barcode = "0000";
}

Product::Product(string t, string n)
{
	product_type = t;
	product_name = n;
	price = 0;
}

Product::Product(string t, string n, float p)
{
	product_type = t;
	product_name = n;
	price = p;
}

Product::Product(string t, string n, float p, string b)
{
	product_type = t;
	product_name = n;
	price = p;
	barcode = b;
}
//setters
void Product::setProductType(string type)
{ 
	product_type = type;
}

void Product::setProductName(string name)
{
	product_name = name;
}

void Product::setPrice(float p)
{
	price = p;
}

void Product::setBarcode(string b)
{
	barcode = b;
}
//getters
string Product::getProductType()
{
	return product_type;
}

string Product::getProductName()
{
	return product_name;
}

float Product::getPrice()
{
	return price;
}

string Product::getBarcode()
{
	return barcode;
}
//friend function that compares prices
bool ComparePrices(Product  ps1,Product ps2)
{
	return ((  ps1.getPrice()> ps2.getPrice()) ? 1 : 0) ;
}

int	main()
{
	Product p1("refreshment","Cola", 17.99);
	Product p2("alcohol", "Beer",5.99);
	if(ComparePrices(p1,p2))
	{
	cout<<p1.getProductName()<<" is more expensive than "<<p2.getProductName()<<endl;
	}	
	else
	{
	cout<<p2.getProductName()<<" is more expensive than "<<p1.getProductName()<<endl;
	}
	return  (0);
}
