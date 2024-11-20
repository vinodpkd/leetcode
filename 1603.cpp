//1603. Design Parking System
/*
Design a parking system for a parking lot. The parking lot has three kinds of parking spaces: big, medium, and small, with a fixed number of slots for each size.
Implement the ParkingSystem class:
    ParkingSystem(int big, int medium, int small) Initializes object of the ParkingSystem class. The number of slots for each parking space are given as part of the constructor.
    bool addCar(int carType) Checks whether there is a parking space of carType for the car that wants to get into the parking lot. carType can be of three kinds: big, medium, or small, which are represented by 1, 2, and 3 respectively. A car can only park in a parking space of its carType. If there is no space available, return false, else park the car in that size space and return true.
*/
class ParkingSystem {
    int big_slots{},medium_slots{},small_slots{};
public:
    ParkingSystem(int big, int medium, int small) {
        big_slots = big;
        medium_slots = medium;
        small_slots = small;
    }
    
    bool addCar(int carType) {

        if(1 == carType)
        {
            
            if(1 <= big_slots)
            {
                big_slots--;
                return true;
            }
            else
            {
                return false;
            }
                
            
        }


        if(2 == carType)
        {
            
            if(1 <= medium_slots)
            {
                medium_slots--;
                return true;
            }
            else
            {
                return false;
            }
                
            
        }

        if(3 == carType)
        {
            
            if(1 <= small_slots)
            {
                small_slots--;
                return true;
            }
            else
            {
                return false;
            }
                
            
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
