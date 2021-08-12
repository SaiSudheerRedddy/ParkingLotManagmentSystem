#include<iostream>
using namespace std;
class parkingLot
{
    public:
        int nParkingSpots = 10;
        int parkingCharge = 10;
        int AvailableLot = nParkingSpots;

        int getParkingCharge(){
            return parkingCharge;
        }
        
        int getParkingLot(){
            return nParkingSpots;
        }

        bool getAvailability()
        {
            if(AvailableLot>0){
                return true;
            }else{
                return false;
            }
        }

        void updateParkingCharges(int newCharge)
        {
            parkingCharge = newCharge;
        }

        bool add_remove(int slots,bool update)
        {
            if(update == 1){
                nParkingSpots += slots;
            }
            else if(update == 0){
                nParkingSpots -= slots;
                if(nParkingSpots <0){
                    nParkingSpots += slots;
                    return false;
                }
            }
            AvailableLot = nParkingSpots;
            return true;
        }
        void Entry()
        {
            AvailableLot -= 1;
            cout<<AvailableLot<<endl;
        }

        void Exit()
        {
            AvailableLot += 1;
        }

        
};