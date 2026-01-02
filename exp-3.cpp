#include<iostream>
#include<random>
using namespace std; 
class DiceRollingSimulator{
    private:
        int getRandomNumber(){
            random_device rd; 
            mt19937 gen(rd());
            uniform_int_distribution<> dist(1, 6);
            return dist(gen); 
        }
    public:
        void rollDice(){
            cout<<"Rolling the dice..." << endl;
            int number = getRandomNumber();
            cout<<"You rolled a " << number << "!" << endl;
        }
};
int main() {
    DiceRollingSimulator simulator;
    simulator.rollDice();
    return 0;
}