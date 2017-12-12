#include <iostream>
#include <string.h>
using namespace std;

class Product
{
	string product_type;
	string product_name;
	float price;
	public:

		void setProductType(string type);
		void setPrductName(string name);
		void setPrice(float p);

		string getProductType();
		string getProductName();
		float getPrice();
		
		Product();
		Product(string t, string n);
		Product(string t,string n,float p);
	friend void CmpPrice( Product *p1, Product *p2);
}

void Product::setPrductType(string type)
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
class DiscountedPrice:public  Product
{
	float discount;
	public:
		void Discount(string s,int p);
}

void Discount::Discount(string s,int p)
{
	if(!(strcmp(s,product_name))
		{
			price -= p;
		}
	else 
		{
			cout<<"That product does not exist";
		}
}

int	main()
{
	Product p1;
	p1.Product("Cola",
	return  (0);
}
