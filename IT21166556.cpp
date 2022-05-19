/*	IT21166556
	Nadeeshan I.U.N.
	Malabe
	8.2.G1
	MLB_08.02_3
   Online Laundry Service
   
   
Collaboration with other group members' classes

Maduranga D.B.W.N (IT21170270)-->
   *Payment
   *Invoice
   *Report
   
Sumanasekara P.D.M (IT21167300) -->
   *Order
   *Cart
   *Laundary_Item
I.U.N.Nadeeshan (IT21166556) -->
   *Staff_Memeber
   *Accountant
   *User
   *Delivery_Person
M.G.T Rashmika (IT21167546) -->
   *Feedback
   *Notification
`  *Inquiry
Gamlathge G.G.A.U (IT21173868) -->
   *Package
   *Subscription
   *Customer
*/

#include <iostream>
#include <string>

using namespace std;

/* Code of Nadeeshan I.U.N. (IT21166556) STARTS HERE - User, Staff_Member, Accountant, Delivery_Person */

/*----------------------------- User class Definition---------------------*/

class User{
	protected:
		string name;
		string gender;
		int age;
	
	public:
		virtual void login() = 0;
		void display();
};

/*----------------------------- Staff_Member class Definition---------------------*/

class Staff_Member : public User{
	private:
		string staffID;
		string position;
	
	public:
		Staff_Member();
		Staff_Member(string ID, string posi, string n, string g, int a);
		void login();
		void display();
};

/*----------------------------- Accountant class Definition---------------------*/

class Accountant : public User{
	private:
		string accountantID;
		string firm;
	
	public:
		Accountant();
		Accountant(string Aid, string frm, string n, string g, int a);
		void login();
		void display();
};

/*----------------------------- Delivery_Person class Definition---------------------*/

class Delivery_Person : public User{
	private:
		string deliveryID;
		string firm;
	
	public:
		Delivery_Person();
		Delivery_Person(string Did, string frm, string n, string g, int a);
		void login();
		void display();
};

/*-----------------------------Staff_Member class Implementation-------------------------*/

		Staff_Member::Staff_Member(){
			staffID = " ";
			position = " ";
			name = " ";
			gender = " ";
			age = 0;
			
		}
		Staff_Member::Staff_Member(string ID, string posi, string n, string g, int a)
		{
			staffID = ID;
			position = posi;
			name = n;
			gender = g;
			age = a;
		}
		void Staff_Member::login(){
			
		}
		void Staff_Member::display(){
			cout<<"Staff Member details -> " << endl; 
			cout << "Staff Member Name :" << name << endl;
			cout << "Staff Member Gender :" << gender << endl;
			cout << "Staff Member Age :" << age << endl;
			cout << "Staff Member ID :" << staffID << endl;
			cout << "Staff Member Position :" << position << endl << endl;
		}
		
/*-----------------------------Accountant class Implementation-------------------------*/
	
		Accountant::Accountant(){
			accountantID = "";
			firm = ""; 
			name = "";
			gender = "";
			age = 0;
		}
		Accountant::Accountant(string Aid, string frm, string an, string ag, int aa){
			accountantID = Aid;
			firm = frm; 
			name = an;
			gender = ag;
			age = aa;
		}
		void Accountant::login(){
			
		}
		void Accountant::display(){
			cout <<"Accountant details -> " << endl;
			cout << "Accountant Name :" << name << endl;
			cout << "Accountant Gender :" << gender << endl;
			cout << "Accountant Age :" << age << endl;
			cout << "Accountant ID:" << accountantID << endl;
			cout << "Accountant Firm :" << firm << endl << endl;
		}
		
/*-----------------------------Delivery_Person class Implementation-------------------------*/

		Delivery_Person::Delivery_Person(){
			deliveryID = "";
			firm = "";
			name = "";
			gender = "";
			age = 0;
		}
		Delivery_Person::Delivery_Person(string Did, string frm, string n, string g, int a){
			deliveryID = Did;
			firm = frm;
			name = n;
			gender = g;
			age = a;
		}
		void Delivery_Person::login(){
			
		}
		void Delivery_Person::display(){
			cout <<"Delivery Person details -> " << endl;
			cout << "Delivery Person Name :" << name << endl;
			cout << "Delivery Person Gender :" << gender << endl;
			cout << "Delivery Person Age :" << age << endl;
			cout << "Delivery Person ID:" << deliveryID << endl;
			cout << "Delivery Person Firm :" << firm << endl << endl;
		}
		
/* Main STARTS HERE -----------------------------------------------------*/

int main(){
	
	Staff_Member *s;
	s = new Staff_Member("S1011", "Washer", "Saman", "Male", 28);
	s -> display();
	
	Accountant *a;
	a = new Accountant("A1234", "Finance", "Sashi", "Female", 25);
	a -> display();
	
	Delivery_Person *d;
	d = new Delivery_Person("D1234", "Rider", "Kasun", "Male", 30);
	d -> display();
	
	return 0;
}
