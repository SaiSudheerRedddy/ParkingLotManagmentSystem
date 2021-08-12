#include<iostream>
#include<string>
#include<vector>
#include "ParkingLot.h"
#include "ParkingTicket.h"
#include "Customer.h"
#include "DisplayBoard.h"
using namespace std;

class parkingTicket : public customer, public parkingLot
{
    public:

        void printTicket(int ID, int departure,vector<customer> C, parkingLot P){
            int amount  = (departure - C[ID].arrivalTime) * P.parkingCharge;
            cout<<"Customer ID = "<<ID<<endl;
            cout<<"Customer Name = "<<C[ID].customerName<<endl;
            cout<<"Vehicle No. = "<<C[ID].vehicleNo<<endl;
            cout<<"Arrival Time = "<<C[ID].arrivalTime<<endl;
            cout<<"Departure Time = "<<departure<<endl;
            cout<<"Cost of parking = "<<amount<<endl;
        }
};


int main(){
    parkingLot P;
    displayBoard D;
    parkingTicket T;
    vector<customer> C;
    int ID,Number,arrivalTime,departureTime,ticketNumber;
    string name;
    while(1){
        cout<<"Choose Below Operations: "<<endl;
        cout<<"1. Get the Parking Lot Status"<<endl;
        cout<<"2. Enter Customer"<<endl;
        cout<<"3. Print Customer Details"<<endl;
        cout<<"4. Exit Customer"<<endl;
        cout<<"5. Update number of slots"<<endl;
        cout<<"6. Update ticker price"<<endl;
        cout<<"7. Turn Off the System"<<endl;


        int key ;
        cin>>key;
        switch(key){
            case 1: 
                    if(D.getStatus(P) == true){
                        cout<<P.AvailableLot<<" Parking slots are available"<<endl;
                    }else{
                        cout<<"Parking Lot is not available"<<endl;
                    }
                    cout<<endl;
                    break;
            case 2: 
                    if(D.getStatus(P) == true){
                        customer temp;
                        cout<<"Enter Vehicle Number and arrival time"<<endl;
                        cin>>Number>>arrivalTime;
                        cout<<"Enter Name"<<endl;
                        cin>>name;
                        temp.addCustomer(C.size(),Number,name,arrivalTime,C.size());
                        temp.getProfile();
                        C.push_back(temp);
                        P.Entry();
                        
                    }else{
                        cout<<"Parking Lot is full"<<endl;
                    }
                    cout<<endl;
                    break;
            case 3:
                    for(int i=0;i<C.size();i++){
                        cout<<i<<" "<<C[i].customerName<<" "<<C[i].vehicleNo<<endl;
                    }
                    cout<<endl;
                    break;
            case 4:
                    cout<<"Enter the customer ID and departure time to exit"<<endl;
                    cin>>ID>>departureTime;
                    T.printTicket(ID,departureTime,C,P);
                    P.Exit();
                    cout<<endl;
                    break;
            case 5:
                    bool b;
                    int new_slot;
                    cout<<"Enter"<<endl;
                    cout<<"1. Add slots"<<endl;
                    cout<<"2. Remove slots"<<endl;
                    cin>>b;
                    cout<<endl<<"Enter number of new slots"<<endl;
                    cin>>new_slot;
                    if(b == true){
                        P.add_remove(new_slot,true);
                    }else{
                        P.add_remove(new_slot,false);
                    }
                    cout<<endl;
                    break;
            case 6:
                    int new_price;
                    cout<<"Enter the new price"<<endl;
                    P.updateParkingCharges(new_price);
                    break;
            case 7: 
                    return 0;       
        }   
    }
}