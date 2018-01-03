#include <iostream>
#include <string.h>
#include <iomanip>
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
        //setters
		void setProductType(string type)
		{ 
        	product_type = type;
        }
        
		void setProductName(string name)
		{
        	product_name = name;
        }
        
		void setProductPrice(float p)
		{
        	price = (float)p;
        }
        
		void setProductBarcode(string b)
		{
        	barcode = b;
        }
        //getters
		string getProductType()
		{
	        return product_type;
        }
        
		string getProductName()
		{
	        return product_name;
        }
        
		float getProductPrice()
		{
	        return price;
        }
        
		string getProductBarcode()
		{
    	    return barcode;
        }
		
		Product()
        {
            product_type = "Universal";
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
    friend void  computePrice(DiscountedProduct a[]);
    
    void setDiscount(float d)
    {
        discount = d;
    }
    
    float getDiscount()
    {
        return (discount);
    }
};


//main
int	main()
{
    DiscountedProduct  p[3];

    p[0].setProductType("soft_drink");
    p[0].setProductName("Cola");
    p[0].setProductBarcode("1");
    p[0].setProductPrice(3.99);

    p[1].setProductType("food");
    p[1].setProductName("Fruit");
    p[1].setProductBarcode("2");
    p[1].setProductPrice(3.99);

    p[2].setProductType("discount");
    p[2].setProductName("Cola");
    p[2].setProductBarcode("");
    p[2].setProductPrice(0);
    p[2].setDiscount(0.25);

    computePrice(p);
	return  (0);
}

void     computePrice(DiscountedProduct a[])
{
    int i;
    int j;
    int ok = 0;
    float price;
    price = 0;
    i = 0;
    //apply discounts
    while(i < 3)
    {
        if(a[i].getProductType().compare("discount") == 0)
        {
            j = 0;
            while(j < 3)
            {
                
                if(a[j].getProductType().compare("discount") != 0 && a[i].getProductName().compare(a[j].getProductName())==0)
                  {
                    a[j].setProductPrice(a[i].getDiscount() * a[j].getProductPrice());
                  }
                j++;
            }
        }
        i++;
    }
    //compute the end price
    i = 0;
    while(i < 3)
    {
        if(a[i].getProductType().compare("discount") != 0)
        {
           price = price + a[i].getProductPrice();
            
        }
        
        i++;
    }
    //make the total sum of Prices

    cout<<std::setprecision(3)<<price<<endl;
}

//friend function
bool ComparePrices(Product  ps1,Product ps2)
{
	return ((  ps1.getProductPrice()> ps2.getProductPrice()) ? 1 : 0) ;
}
