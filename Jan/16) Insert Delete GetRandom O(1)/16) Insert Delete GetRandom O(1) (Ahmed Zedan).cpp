// author : Ahmed Zedan

/*
    - x % y = z (z>=0 and z<=y-1 )
    - Each element must have the same probability of being returned do that by use rand() method 
    - rand() method return random integer and get (% v.size()) to get random mumber between (0 to v.size()-1)
*/

class RandomizedSet {
public:
    set<long long>st ; 
    vector<long long>v ; 
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(st.find(val)!=st.end()) return false ; 
        else {
            st.insert(val) ;
            return true ; 
        }
    }
    
    bool remove(int val) {
        if(st.find(val)!=st.end()){
            st.erase(val) ; 
            return true ; 
        }
        else {
            return false ; 
        }
    }
    
    int getRandom() {
        v = vector<long long>(st.begin() , st.end()) ; 
        return v[rand()%v.size()] ;  
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */