class Territory{
    private:
        int numOfArmies;
        //Player player;
        //Continent  continent;
    
    public:
        Territory();
        Territory(int numOfArmies);
       inline int getArmies(){
           return numOfArmies;
       }
       inline void setArmies(int numOfArmies){
        this->numOfArmies = numOfArmies;
       }


};