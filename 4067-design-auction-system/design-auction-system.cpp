class AuctionSystem {
public:
    map<vector<int>, int> m1; // {userId, itemId} -> bidAmt;
    map<int, set<vector<int>>> m2; // itemId -> {{-bidAmt, -userId}}
    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        if(m1.find({userId, itemId}) != m1.end()){
            removeBid(userId, itemId);
        }
        m1[{userId, itemId}] = bidAmount;
        m2[itemId].insert({-1*bidAmount, -1*userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        int currentBid = m1[{userId, itemId}];
        m2[itemId].erase({-1*currentBid, -1*userId});
        m2[itemId].insert({-1*newAmount, -1*userId});
        m1[{userId, itemId}] = newAmount;
    }
    
    void removeBid(int userId, int itemId) {
        int currentBid = m1[{userId, itemId}];
        m2[itemId].erase({-1*currentBid, -1*userId});
        if(m2[itemId].size()==0){
            m2.erase(itemId);
        }
        m1.erase({userId, itemId});
    }
    
    int getHighestBidder(int itemId) {
        if(m2.find(itemId) == m2.end() ){
            return -1;
        }
        vector<int> tmp = *(m2[itemId].begin());
        return -1*tmp[1];
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */