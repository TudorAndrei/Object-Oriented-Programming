#include <iostream>
#include <unistd.h>
#include <string.h>
using namespace std;
//Product class
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
//Discounted Product class
class DiscountedProduct:public Product
{
	float discount;

	public:

    DiscountedProduct() : Product()
    {
     discount = 1;
    }
		DiscountedProduct(string t, string n, string b, float p,float d):
		Product( t, n,b, p){
            discount = d;
        }
    friend int  computePrice(DiscountedProduct a);
    void setDiscount(float d)
    {
        discount = d;
    }
    float getDiscount()
    {
        return (discount);
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
    DiscountedProduct  p[100];

    p[0].setProductType("soft_drink");
    p[0].setProductName("Cola");
    p[0].setBarcode("1");
    p[0].setPrice(3.99);

    p[1].setProductType("food");
    p[1].setProductName("Chips");
    p[1].setBarcode("2");
    p[1].setPrice(2.99);

    p[2].setProductType("discount");
    p[2].setProductName("Cola");
    p[2].setBarcode("");
    p[2].setPrice(0);
    p[2].setDiscount(0.25);
    int i = computePrice(p);
    cout<<i<<endl;
	return  (0);
}

int     computePrice(DiscountedProduct a[])
{
    int i;
    int j;
    int ok = 0;
    int price;
    price = 0;
    while(a[i].getProductName().compare(NULL) != 0)
    {
        if(a[i].getProductType().compare("discount") == 0)
        {
            j = 0;
            while(a[j].getProductName().compare(NULL) != 0)
            {
                if(a[j].getProductType().compare("discount") == 0 && a[i].getProductName().compare(a[j].getProductName())==0)
                    price = price + a[i].getPrice() * a[j].getDiscount();
                i++;
            }
        }
        i++;
    }

    return(price);
}
