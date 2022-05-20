/* 	IT21167300 
	Sumanasekara PDM
	Malabe
	MLB_08.02_3

I have programmed the classes "Order", "Cart", "Laundry_Item" and their relationships.
"Order" has whole part relationship with "Payment" and "Payment" has a whole part relationship with "Invoice".
Due to that reason I have included "Payment" and "Inoice" classes with composition here, that were written by
my fellow group memeber Maduranga DBWN (IT21170270). 

However I did not include classes that had association relationship with the classes that I wrote. Becuase of that
there are some methods and attributes that can't be used in the main program. Thus I have commented out those 
attributes and methods to make this code work. Those commented out codes are uncommonted in the "Combined Code.cpp" 

*/
  
#include <iostream>
#include <string>

#define MAX_ORDER_ITEM_SIZE 10
#define MAX_CART_ITEM_SIZE 10

using namespace std;



/* Code of Maduranga DBWN (IT21170270) STARTS HERE --------------------------------*/

/*----------------------------- Invoice Class Definition --------------------------*/

class Invoice {
	private:
		string invoiceNo;
  	public:
    	Invoice();
    	Invoice(string no);
		void display(); 
    	void getOrderDetails();
		void getCustomerDetails();
		void getPaymentDetails();
		~Invoice();		
};

/*----------------------------- Payment Class Definition --------------------------*/

class Payment
{
	private:
		Invoice *invoice;
		string paymentID;
		string paymentType;
		string PaymentDate;
		
	public:	
        Payment();
		Payment(string payID , string payType , string patDate , string No );
		void display();
		void validatePayment();
		void getOrderDetails();
		~Payment();
};

/*-----------------------------Invoice class Implementation------------------------*/

Invoice::Invoice()
{
	invoiceNo = ""; 
}

Invoice::Invoice(string No)
{
	invoiceNo = No ;
}

void Invoice::display()
{
	cout << "Invoice No   : " << invoiceNo << endl <<endl;	
}

Invoice::~Invoice()
{
	cout << "Deleted Invoice " << invoiceNo << endl ;
}

/*-----------------------------Payment class Implementation-------------------------*/

Payment::Payment()
{
	invoice = new Invoice("");
	paymentID = "" ;
	paymentType = "";
	PaymentDate = "";	
}

Payment::Payment(string payID , string payType , string payDate , string No)
{
    invoice = new Invoice(No);
    paymentID = payID ;
	paymentType = payType;
	PaymentDate = payDate;	
}

void Payment::display()
{
	cout <<"Payment Info ->"<< endl ;
	cout <<"Patment ID   : " << paymentID << endl ;
    cout <<"Payment Type : " << paymentType << endl ;
	cout <<"payment Date : " << PaymentDate << endl<<endl ;
	cout <<"Invoice Info ->" << endl;
	invoice->display();
}

Payment::~Payment()
{
	cout << "Deleted Payment " << paymentID << endl ;
	delete invoice;			
}

/* Code of Maduranga DBWN (IT21170270) ENDS HERE --------------------------------*/


/* Code of Sumanasekara PDM (IT21167300) STARTS HERE - Order, Cart, Laundry_Item  */

/*-----------------------------Laundry_Item class Definition---------------------*/

class Laundry_Item {
	
	private:
	
		string itemID;
		string itemName;
		float itemPrice;
		string itemDescription;

	public:
	
		Laundry_Item();
		Laundry_Item(string id, string name, float price, string desc);
		void display();
		void addItem();
		void editItem();			
};

/*----------------------------- Cart class Definition---------------------*/

class Cart {
	
	private:
		int itemQuantity;
		Laundry_Item * items[MAX_CART_ITEM_SIZE];		//association with Laundry_Item class
		//Customer * customer;							//association with Customer class
		
	public:
		Cart();
		Cart(int quantity);
		void addLaundryItem( Laundry_Item *item, int index); 
		//void addCustomer(Customer * cus);
		void display();
		void calculatePrice();
		void removeItem();
};

/*----------------------------- Order class Definition---------------------*/

class Order {
	
	private:
		
		string orderID;
		string oDate;
		int itemAmount; 							// Laundry_Item amount in a single order
		Payment * payment;							// Composition with payment 
		Laundry_Item * items[MAX_ORDER_ITEM_SIZE];	// Aggregation with Laundry_Items 
		Cart *cartOrder; 							// Association with cart 
		//Customer *customer;						// Association Customer
		//Delivery_Person *delivery;				// Association Delivery_Person 
		//Staff_Member *staff; 					    // Association Staff_Member 
	
	public:
		
		Order();
		Order(string oID, string oD, int amount, string payID, string payType, string payDate, string No);
		void addLaundryItem( Laundry_Item *item, int index); // Add Laundry_Items to the order
		//void addCustomer(Customer *cus);
		//void addDelivery_Person(Delivery_Person *d);
		//void addStaff_Member(Staff_Member *s);
		void display();	
		void checkAvailability();
		void placeOrder();
		void orderValidation();
		void cancelOrder();
		~Order();
};

/*-----------------------------Laundry_Item class Implementation-------------------------*/

Laundry_Item::Laundry_Item(){
	
	itemID = "";
	itemName = "";
	itemPrice = 0.0;
	itemDescription = "";	
};

Laundry_Item::Laundry_Item(string id, string name, float price, string desc){
	itemID = id;
	itemName = name;
	itemPrice = price;
	itemDescription = desc;
};

void Laundry_Item::display(){
	cout<<"Item ID : "<<itemID << endl;
	cout<<"Item Name : "<<itemName << endl;
	cout<<"Item Price : "<<itemPrice << endl;
	cout<<"Item Description : "<<itemDescription <<endl<<endl;
};

/*----------------------------- Cart class Implementation-------------------------*/

Cart::Cart(){
	itemQuantity = 0;
};

Cart::Cart(int quantity){
	itemQuantity = quantity;
};

void Cart::addLaundryItem( Laundry_Item *item, int index){
	items[index] = item;
};

//void Cart::addCustomer(Customer * cus){
//	customer = cus;	
//};

void Cart::display(){
	cout<<"Cart Details >>" << endl;
	cout<< "Cart Item Quantity : "<<itemQuantity << endl;
	for ( int i = 0; i < itemQuantity; i++){
		items[i] -> display();
	};
	cout<<endl;
}

/*----------------------------- Order class Implementation-------------------------*/

Order::Order(){
	orderID = "";
	oDate = "";
	itemAmount = 0;
	payment = new Payment();
};

Order::Order(string oID, string oD, int amount, string payID, string payType, string payDate, string No){
	orderID = oID;
	oDate = oD;
	itemAmount = amount;
	payment = new Payment(payID,payType,payDate,No);
};

void Order::addLaundryItem( Laundry_Item *item, int index){
	items[index] = item;
};

//void Order::addCustomer(Customer *cus){
//	customer = cus;
//};
		
//void Order::addDelivery_Person(Delivery_Person *d){
//	delivery = d;
//};
		
//void Order::addStaff_Member(Staff_Member *s){
//	staff = 	
//};
		
void Order::display (){
	cout<<"Order Info ->"<< endl;
	cout<<"Order ID   :"<< orderID << endl;
	cout<<"Order Date :"<< oDate << endl;
	cout<<"Order Item Amount :"<< itemAmount << endl<<endl;
	cout<<"Order Item Details >>" << endl;
	for ( int i = 0; i < itemAmount ; i++){
		items[i] -> display();
	};
	cout<<endl;
	payment -> display();
};

Order::~Order(){
	cout << "Deleted Order "<< orderID <<endl;
	delete payment;
};

/* Main STARTS HERE -----------------------------------------------------*/

int main() {
	
	Laundry_Item *l1 = new Laundry_Item("L001","Shirt",200.00,"Shirt Wash");
	Laundry_Item *l2 = new Laundry_Item("L002","Short",300.00,"Short Wash");
	
	Cart * cart = new Cart(2);
	cart -> addLaundryItem(l1,0);
	cart -> addLaundryItem(l2,1);
	cart -> display();
	
	Order * order = new Order("O1001","2021/05/16", 2, "P1001","Paypal","2021/05/16","I1001");
	order -> addLaundryItem(l1,0);
	order -> addLaundryItem(l2,1);
	order -> display();
	delete order;
	delete l1,l2;
	delete cart;
}
