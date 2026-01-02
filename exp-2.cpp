#include<iostream>
#include<string>
#include<random>
using namespace std; 
class RockPaperScissors {
    private:
        int userscore=0; 
        int compscore=0;
        int getComputerChoice(){
            random_device rd; 
            mt19937 gen(rd());
            uniform_int_distribution<> dist(1, 3);
            return dist(gen);
        }
        string choiceToString(int choice){
            if(choice==1) return "Rock";
            else if(choice==2) return "Paper";
            else return "Scissors";
        }
        int decideWinner(int userChoice, int compChoice){
            if(userChoice==compChoice) return 0; 
            else if((userChoice==1 && compChoice==3) || 
                    (userChoice==2 && compChoice==1) || 
                    (userChoice==3 && compChoice==2)) return 1; 
            else return -1; 
        }
        public:
        void playGame(){
            int rounds; 
            cout<<"ENter number of rounds to play: ";
            cin>>rounds;
            for(int i=0;i<rounds;i++){
                cout<<"\n----Round " << i+1 << "----";
                cout<<"\nEnter your choice (1-Rock, 2-Paper, 3-Scissors): ";
                int userChoice;
                cin>>userChoice;
                int compChoice = getComputerChoice();
                cout<<"Computer chose: " << choiceToString(compChoice) << endl;
                int result = decideWinner(userChoice, compChoice);
                if(result==1){
                    cout<<"You win this round!" << endl;
                    userscore++;
                }
                else if(result==-1){
                    cout<<"Computer wins this round!" << endl;
                    compscore++;
                }
                else{
                    cout<<"This round is a tie!" << endl;
                }
                
            }
        }
};

int main() {
    RockPaperScissors game;
    game.playGame();
    return 0;
}


