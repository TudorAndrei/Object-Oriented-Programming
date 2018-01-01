#include <iostream>
#include <unistd.h>
#include <string.h>
using namespace std;

class Product
{
	protected:
		string product_type;
		string product_name;
		float price;
		string barcode;

	public:

		void setProductType(string type);
		void setProductName(string name);
		void setPrice(float p);
		void setBarcode(string b);

		string getProductType();
		string getProductName();
		float getPrice();
		string getBarcode();
		
		Product()
        {	product_type = "Universal";
	product_name = "Anything";
	price = 0;	
        }
		Product(string t, string n)
{
	product_type = t;
	product_name = n;
	price = 0;
}

		Product(string t,string n,float p)
{
	product_type = t;
	product_name = n;
	price = p;
}

		Product(string t, string n, string b,float p)
{
	product_type = t;
	product_name = n;
	price = p;
	barcode = b;
}



	friend bool ComparePrices(Product p1, Product p2);
};
class DiscountedProduct:public Product
{
	float discount;

	public:
		DiscountedProduct(string t, string n, string b, float p,float d):
		Product( t, n,b, p){
            discount = d;
        }
};
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
//friend function
bool ComparePrices(Product  ps1,Product ps2)
{
	return ((  ps1.getPrice()> ps2.getPrice()) ? 1 : 0) ;
}
//main
int	main()
{
	
	DiscountedProduct p1("soft_drink","Cola","1",3.99,1);
	DiscountedProduct p2("food","Chips","2",2.99,1);
	DiscountedProduct p3("discount","Cola","",0,0.25);	
	return  (0);
}
