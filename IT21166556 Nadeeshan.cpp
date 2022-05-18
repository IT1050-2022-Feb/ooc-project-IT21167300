#include <iostream>
#include <string.h>

using namespace std;

/*----------------------------- Staff_Member class Definition---------------------*/

class Staff_Member{
	private:
		string staffID;
		string position;
	
	public:
		Staff_Member();
		Staff_Member(string ID, string posi);
		void login();
		void display();
};

/*----------------------------- Accountant class Definition---------------------*/

class Accountant{
	private:
		string accountantID;
		string firm;
	
	public:
		Accountant();
		Accountant(int Aid, string frm);
		void login();
		void display();
};

/*----------------------------- User class Definition---------------------*/

class User{
	protected:
		string name;
		char gender;
		int age;
	
	public:
		
		User(string Uname, char Ugender, int Uage);
		virtual void login() = 0;
		void display();
};


int main(){
	return 0;
}
