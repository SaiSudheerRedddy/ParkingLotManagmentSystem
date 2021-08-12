#include<iostream>
using namespace std;
class customer
{
    public:
        int customerID,vehicleNo,arrivalTime,ticketID;
        string customerName;
    public:
        void addCustomer(int ID, int Number,string name,int arrivalTime,int ticketNumber){
            customerID = ID;
            vehicleNo = Number;
            customerName.assign(name);
            arrivalTime = arrivalTime;
            ticketID = ticketNumber;
        }

        void getProfile(){
            cout<<"Customer ID = "<<customerID<<endl;
            cout<<"Vehicle No = "<<vehicleNo<<endl;
            cout<<"Cutomer Name = "<<customerName<<endl;
            cout<<"Ticker ID = "<<ticketID<<endl;
        }
};