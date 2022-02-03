
using namespace std;
#include <iostream>


class Territory{
    private:
        int numOfArmies;
        //Player player;
        //Continent  continent;
    
    public:
        Territory(){

        }
        Territory(int numOfArmies);
       inline int getArmies(){
           return numOfArmies;
       }
       inline void setArmies(int numOfArmies){
        this->numOfArmies = numOfArmies;
       }



};
class Node 
{
    Territory* data;
    Node* next;
};
Territory::Territory(int num){
    this->numOfArmies = num;
}
int main(){

    Territory *t1 = new Territory(10);
    Node* n1;

    n1->data = *t1;
    
    int num = n1->data.getArmies();
        
   // cout << t1->getArmies() <<endl;
    cout << "The armies: " << num <<endl;
        
}