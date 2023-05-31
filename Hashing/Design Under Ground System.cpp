using pp = pair<string , double> ; 
using pp2 = pair<double , int> ;

class UndergroundSystem {
private:
unordered_map<int , pp> customer ;
unordered_map<string , pp2> calcTotalTime ;

public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) 
    {
        customer[id] = {stationName , t} ; return ;
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        auto data = customer[id] ;  

        string key = data.first + "-" + stationName ;

        calcTotalTime[key].first += ( (t * 1.00) - data.second) ;
        calcTotalTime[key].second += 1 ;

        customer.erase(id) ;  return ;      
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        string key = startStation + "-" + endStation ;

        double total = calcTotalTime[key].first ;
        double cnt = calcTotalTime[key].second ;

        return (total / cnt) ;    
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

// Time Complexity:  O(N)
// Space Complexity: O(N)
