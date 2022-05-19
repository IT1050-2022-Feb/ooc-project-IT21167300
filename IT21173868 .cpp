/* 	IT21173868
	Gamlathge G.G.A.U
	Malabe
	8.2.g1
  MLB_08.02_3
  Online Laundry Service

I have programmed the classes "Payment", "Invoice", "Report" , "Inquiry" and their relationships.
"Payment" Class has whole part relationship(composition) with "Invoice" Class.
"Invoice" Class has a Association relationship(Uni-Directional) with "Report" Class.
"Inquiry" Class has a Dependency relationship with "Customer" Class.

I will comment some code because of that other class aren't implementd inside the my part and otherwise i give some error

Collaboration with other group members' classes

Maduranga D.B.W.N (IT21170270)-->
   *Payment
   *Invoice
   *Report
   *Inquiry

Sumanasekara P.D.M (IT21167300) -->
   *Order
   *Cart
   *Laundary_Item

I.U.N.Nadeeshan (IT21166556) -->
   *Staff_Memeber
   *Accountant
   *User

M.G.T Rashmika (IT21167546) -->
   *Delivery_Person
   *Feedback
   *Notification
   
Gamlathge G.G.A.U (IT21173868) -->
   *Package
   *Subscription
   *Customer
               
*/

#include <iostream>
#include <cstring>
using namespace std;

/*-----------------------------Package class Definition---------------------*/

class Package {

private:
		string packageID;
		string pName;
		

public:
		Package();
		Package(string pID, string name);
		void addpackage();
		void editPackage();
		void display();

};

/*-----------------------------Customer class Definition---------------------*/

class Customer {

private:
		string customerID;
		int contactNo;
		string email;
		string address;
		//User*user;
	
public:
		Customer();
		Customer(string CID,int CNO,string mail,string Caddress);
		void regiterUser();
		void login();
		void editUser();
		void display();

};
/*-----------------------------Subscription class Definition---------------------*/

class Subscription {

private:
		string subscriberID;
		string sPacakge;
		string duraiton;
		Customer *customer;
		Package *package;
		

public:
		Subscription();
		Subscription(string subID, string pkg,string dura);
		void displaySubscription();
		void display(Customer*customer,Package*package);
};

/*-----------------------------Package class implementation---------------------*/

	Package :: Package (){
		
		packageID = "";
		pName = "";
	}
		
	Package :: Package(string pID, string name){
		
			packageID = pID ;
			pName = name ;
	}
	void Package ::addpackage(){
		
	}
	void Package ::editPackage(){
		
	}
	void Package ::display(){
		
		cout << endl << "Package Info " << endl ;
		cout << "Package ID : " << packageID << endl ;	
		cout << "Package Name : " << pName << endl << endl ;	
	}


/*-----------------------------Customer class implementation---------------------*/

	Customer :: Customer(){
	
		customerID = "";
	    contactNo = 0;
		email = "";
		address = "";
	
	
	}		
	Customer :: Customer(string CID,int CNO,string mail,string Caddress){
		
		customerID = CID;
		contactNo = CNO;
		email	= mail;
		address = Caddress;
	}
	void Customer ::regiterUser(){
			
	}
	void Customer ::login(){
		
	}
	void Customer ::editUser(){
		
	}
	void Customer ::display(){
		
		cout << endl << "customer Info" << endl ;
		cout << "customerID : " << customerID << endl ;	
		cout << "Contact NO : " << contactNo << endl  ;
		cout << "email : " << email << endl ;
		cout << "Address : " << address << endl << endl  ;
	}

/*-----------------------------Subscription class implementation---------------------*/
	Subscription :: Subscription(){
		subscriberID = "";
		sPacakge = "";
		duraiton = "";
		
	}
	Subscription ::	Subscription(string subID, string pkg,string dura){
		
		subscriberID = subID;
		sPacakge = pkg;
		duraiton = dura;
		
	}
	void Subscription ::displaySubscription(){
		
	}
	void Subscription ::display(Customer*customer,Package*package){
		cout << endl << "Subscriber Info" << endl ;
		cout << "subscriberID : " << subscriberID << endl ;	
		cout << "Subscriber Pacakge  : " << sPacakge << endl  ;
		cout << "Duration : " << duraiton << endl << endl;
		
		customer->display();
		package->display();
		
	}



int main(){
	
	Package *pkg ;
	pkg = new Package("P1000", "Silver");
	pkg -> display();
	
	Customer *cus ;
	cus = new Customer("C1000", 76785643,"nima@gmail.com","NO 123 KAndy");
	cus -> display();
	
	Subscription *sub ;
	sub = new Subscription("S1000", "Silver","2 year");
	sub -> display(cus,pkg);
	
	delete pkg;
	delete cus;
	delete sub;
	
	return 0;
}







