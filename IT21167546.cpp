#include <iostream>
#include <string>


using namespace std;

/*-----------------------------Inquiry Class Header--------------------------------*/

class Inquiry
{
	private:
		int inquiryNo;
	
	public:
	    Inquiry();
		Inquiry(int no);
		display();
	    //void getCustomerDetails(Customer *customer);
		void setInquiryReply();	
};

/*-----------------------------Feedback Class Header--------------------------------*/
class feedback
{
	private:
		string feedbackNo;
		string feedbackReply;
		
	public:
		feedback();
		feedback(string fNo , string fReply);
		//void getCustomerDetails(Costomer *customer);
		void display();
		void setfeedbackReply();
	
};

/*-----------------------------Notification Class Header--------------------------------*/


class Notification
{
	private:
		string notificationNo;
		//Customer *customer	
	public:
		Notification();
		Notification(string nNo /*, Customer *nCus*/);
		void display();
		void viewDiscription();	
	
};





/*-----------------------------Inquiry class implementation--------------------------------*/

Inquiry::Inquiry()
{
	inquiryNo = 0;
	
	
}

Inquiry::Inquiry(int nNo)
{
	inquiryNo =nNo;
		
}

Inquiry::display()
{
	cout << endl << "Inquiry Information " << endl ;
	cout << "Inquiry No : " << inquiryNo << "\n" << endl ;	

}
/*
void Inquiry::getCustomerDetails(Customer *customer)
{
	customer->display();
	
}
*/
void Inquiry::setInquiryReply()
{
	
	
}


/*-----------------------------Feedback class implementation--------------------------------*/



feedback::feedback(){
	feedbackNo= "";
	feedbackReply="";
}

feedback::feedback(string fNo , string fReply){
	feedbackNo=fNo;
	feedbackReply=fReply;
	
}

/*
void feedback::getCustomerDetails(Customer *customer)
{
	customer->display();
	
}
*/

void feedback::display(){
	
	cout<<"Customer Feedback "<< endl;
	cout<<"Feedback Number :" << feedbackNo << endl;
	cout<<"Feedback : " << feedbackReply << endl;
	
	
}

void feedback::setfeedbackReply(){
	
	
}



/*-----------------------------Notification class implementation--------------------------------*/



Notification::Notification(){

	notificationNo = "";

}

Notification::Notification(string nNo /*, Customer *nCus*/){
	
	notificationNo = nNo;
	//customer = nCus;
}

void Notification::display(){
	 
	cout << "\n" ;
	cout << "Notification Number : " << notificationNo << endl ;
}

void Notification::viewDiscription(){
	
	
}




int main(void)
{	



/*-----------------------------Inquiry class--------------------------------*/


	Inquiry * inquObj;
	inquObj = new Inquiry(678);
	inquObj->display();
   
/*-----------------------------Feedback class--------------------------------*/

	feedback *feedbackobj;
	feedbackobj = new feedback("678","Service was good as well");
	feedbackobj->display();

/*-----------------------------Notification class--------------------------------*/

    Notification *notifiobj;
    notifiobj = new Notification("678");
	notifiobj->display();	
   
   
   
   delete inquObj;
   delete feedbackobj;
   delete notifiobj;

	return 0;
}

