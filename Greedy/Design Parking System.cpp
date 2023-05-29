class ParkingSystem {
private:
int carSpace[3] = {0} ;

public:
    ParkingSystem(int big, int medium, int small) 
    {
        carSpace[0] = big ; carSpace[1] = medium ; carSpace[2] = small ;    
    }
    
    bool addCar(int carType) 
    {
        int ind = carType - 1 ;

        if(carSpace[ind] > 0)
        {
            carSpace[ind]-- ;  return true ;
        }    

        else  return false ;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

// Time Complexity:  O(1)
// Space Complexity: O(1)
