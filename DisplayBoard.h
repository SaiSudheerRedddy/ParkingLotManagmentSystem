#include<iostream>
using namespace std;
class displayBoard : public parkingLot
{
    public:
        bool getStatus(parkingLot P1){
            if(P1.AvailableLot > 0){
                return true;
            }else{
                return false;
            }
        }
};