///Square Dynasty (Conclusion Sample Game Code)
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

    string board[36] = {};

    
    int storage[36];
    int miniCount = 0;
    bool valid = false;
    int preve0 = 30;
    int preve1 = 5;
    int press;
    int tele;

    ///for the characters
    string tempo;
    //int inipos1 = 30;
    //int inipos2 = 5;
    string initial1 = board[30];
    string initial2 = board[5];
    int les = 1;

    ///for  the current inယdex
    int turn = 2,j = 0;
    int c = 0;
    int control = 0;
    int signal = 0,timing = 100;
    string lastMove;
    string in;
    string name;



///Here is teleport function;

int teleport(int initipos,int preve,string c){
    int potal_1;       ///potal is a term for teleport.
    int potal_2;
    cout<<"The initial position is "<<initipos<<endl;   ///To know if it works or not can be detected.
    if(initipos==7)
    {
        potal_1=7;
        potal_2=27;
    }
    else
    {
        potal_1=27;
        potal_2=7;

    }
      board[preve]=c;
    /*if(c%2==0){
         board[potal_1]="X";
         board[potal_2]="A";

    }
    else
    {
        board[potal_1]="O";
        board[potal_2]="B";
    }*/
    return potal_2;
}





///Board Design
void draw()
{
    system("cls");
    cout<<"Player 1) A\n";
    cout<<"Player 2) B\n";


    cout<<endl<<endl;

    cout << " ______ ______ ______ ______ ______ ______ \n";
    cout << "|      |      |      |      |      |      |\n";
    cout << "|   " << board[0] << "  |   " << board[1] << "  |   " << board[2] << "  |   " <<board[3] <<"  |   " <<board[4]<<"  |   "<<board[5]<<"  |   "<< "\n";
    cout << "|______|______|______|______|______|______| \n";
    cout << "|      |      |      |      |      |      |\n";
    cout << "|   " << board[6] << "  |   " << board[7] << "  |   " << board[8] << "  |   " <<board[9] <<"  |   "<<board[10]<<"  |   "<<board[11]<<"  |   "<< "\n";
    cout << "|______|______|______|______|______|______| \n";
    cout << "|      |      |      |      |      |      |\n";
    cout << "|   " << board[12] << "  |   " << board[13] << "  |   " << board[14] << "  |   " <<board[15] <<"  |   "<<board[16]<<"  |   "<<board[17]<<"  |   "<< "\n";
    cout << "|______|______|______|______|______|______| \n";
    cout << "|      |      |      |      |      |      |\n";
    cout << "|   " << board[18] << "  |   " << board[19] << "  |   " << board[20] << "  |   " <<board[21] <<"  |   "<<board[22]<<"  |   "<<board[23]<<"  |   "<< "\n";
    cout << "|______|______|______|______|______|______| \n";
    cout << "|      |      |      |      |      |      |\n";
    cout << "|   " << board[24] << "  |   " << board[25] << "  |   " << board[26] << "  |   " <<board[27] <<"  |   "<<board[28]<<"  |   "<<board[29]<<"  |   "<< "\n";
    cout << "|______|______|______|______|______|______| \n";
    cout << "|      |      |      |      |      |      |\n";
    cout << "|   " << board[30] << "  |   " << board[31] << "  |   " << board[32] << "  |   " <<board[33] <<"  |   "<<board[34]<<"  |   "<<board[35]<<"  |   "<< "\n";
    cout << "|______|______|______|______|______|______| \n";
}


///move function for "a"

class Player {
        public:
            string ascii;
            string name;
            string owned;
            int position;
            Player() {
                ascii = "";
                name = "";
                owned = "";
                position = 0;

            }
            Player(string ascii,string name,string owned,int position) {
                this->ascii = ascii;
                this->name = name;
                this->owned = owned;
                this->position = position;

        }
    };

    int movee(string dir,Player currentPlayer,int &preve,int c) {
        string cool = (c % 2 == 0) ? "B" : "A";

        if(dir == "d") {
            if(currentPlayer.position != 35 && currentPlayer.position != 29 && currentPlayer.position != 23 && currentPlayer.position != 17 && currentPlayer.position != 11 && currentPlayer.position != 5)
                    {
                        
                            if(board[currentPlayer.position+1] != "A" && board[currentPlayer.position+1] != "B")
                        {
                            currentPlayer.position = currentPlayer.position + 1;
                            preve = currentPlayer.position - 1;
                            

                            return currentPlayer.position;
                                                       
                    } 
                    else {
                            return currentPlayer.position;
                        }  
                        }else {
                        return currentPlayer.position;
                    } 
        }
        else if(dir == "s") {

            if(currentPlayer.position != 30 && currentPlayer.position != 31 && currentPlayer.position != 32 && currentPlayer.position != 33 && currentPlayer.position != 34 && currentPlayer.position != 35)
                    {
                        if(board[currentPlayer.position + 6] != "A" && board[currentPlayer.position + 6] != "B")
                        {
                            currentPlayer.position = currentPlayer.position + 6;
                            preve = currentPlayer.position - 6;

                            return currentPlayer.position;
                            
                        }else {
                        return currentPlayer.position;

                    }
                    }else {
                            return currentPlayer.position;
                        }  
        } 
        else if(dir == "w") {
            if(currentPlayer.position != 0 && currentPlayer.position != 1 && currentPlayer.position != 2 && currentPlayer.position != 3 && currentPlayer.position != 4 && currentPlayer.position != 5)
                    {
                        if(board[currentPlayer.position - 6] != "A" && board[currentPlayer.position - 6] != "B")
                        {
                            currentPlayer.position = currentPlayer.position - 6;
                            preve = currentPlayer.position + 6;

                            return currentPlayer.position;
                            
                        }
                        else {
                           
                            return currentPlayer.position;
                        } 
                    }else {
                        
                        return currentPlayer.position;
                    } 
        } 
        else if(dir == "a") {
            if(currentPlayer.position != 30 && currentPlayer.position != 24 && currentPlayer.position != 18 && currentPlayer.position != 12 && currentPlayer.position != 6 && currentPlayer.position != 0)
                    {
                        if(board[currentPlayer.position - 1] != "A" && board[currentPlayer.position - 1] != "B")
                        {
                            currentPlayer.position = currentPlayer.position - 1;
                            preve = currentPlayer.position + 1;

                            return currentPlayer.position;
                            
                        }
                        else {
                          
                            return currentPlayer.position;
                        }  
                    } else {
                        
                        return currentPlayer.position;
                    }
                    
        } 
    }



int main(void)
{
    ///for random functions
    srand(time(0));
    for( int i = 0; i< 36; i++){ 
        board[i] = " ";
        storage[i] = 99;};
    Player player[] = { Player("A","player 1","X",30), Player("B","player 2","O",5) };
    Player currentPlayer = player[0];
    
    board[30] = "A";
    board[5] = "B";
    board[7]="T";
    board[27]="T";
    board[15]="M";
    board[28] = "P";
    draw();






//Check whether the input is 5 or 10
    
     do
    {
        cout<<"\nHow many turns do you wanna play: (5 or 10): ";
        cin>>turn;
        if (turn!=5 && turn!=10)
        {
           cout << "\nInput wrong!!";
        }
    }while(turn!=5 && turn!=10);

    //first while loop for turn
    cout<<endl<<"Remained turn = "<<(turn + 1) - les<<endl;

    do
    {

        int ran = (rand() % (6 - 1 + 1)) + 1;
        cout<<endl;
        cout<<currentPlayer.position;



        name = c % 2 == 0 ? player[0].name : player[1].name;
        currentPlayer = c % 2 == 0 ? player[0] : player[1];
        cout<<"Start "<<name;
        cout<<endl;
        cout<<name<<"'s available move according to rolling dice = "<<ran<<endl<<endl;
        j = 0;

        if(c == 0) 
            cin.ignore();

        cout<<endl<<"Conquer(by using aswd): ";
                getline(cin,in);

        ///while loop for the randomized dice number
        while(j < ran)
        {
            ///To determine whether player 1's turn or player 2's
            int newb = (currentPlayer.name == "player 1") ? 0 : 1;
            int preve = (currentPlayer.name == "player 1") ? preve0 : preve1;

                
                    press = movee(in,player[newb],preve,c);

                    if(board[press] == "T")
                            {
                                //make the initialpos  a little early for teleport function..]
                                tele = press;
                                board[press] = player[newb].owned;
                                cout<<"Teleport activated"<<endl<<endl;
                                press=teleport(tele,preve,player[newb].owned);
                                cout<<press;
                            } else if(board[press]=="M"){
                                board[8]=player[newb].owned;
                                board[9]=player[newb].owned;
                                board[10]=player[newb].owned;
                                board[14]=player[newb].owned;
                                board[16]=player[newb].owned;
                                board[20]=player[newb].owned;
                                board[21]=player[newb].owned;
                                board[22]=player[newb].owned;
                            } else if(board[press] == "P") {
                                   //send signal to activate protection
                                   signal = 1;
                            }

                    
                    player[newb].position = press;
                    board[preve] = player[newb].owned;
                    board[press] = player[newb].ascii;
                    
                
                 /*if(board[player[newb].position] == "P") {
                                    //send signal to activate protection
                                    signal = 1;
                            
                }*/

                            
                    
                    j++;
        };

            
    


            

 ///Changing normal squares to the protected squares once they have signal
            if(signal) {
                for(int i = 0; i < 36; i++) {
                    if(name == "player 1") {
                            if(board[i] == player[0].owned) {
                               board[i] = "C";
                            }

                } else if(name == "player 2") {
                    if(board[i] == player[1].owned)
                       board[i] = "C";
                }
            }

            timing = c;
        }

 ///when they get signal, they start storing the protected squares
            if(signal) {
                for(int i = 0; i < 36; i++) {
                    if(board[i] == "C") {
                        storage[miniCount] = i;
                                miniCount++;
                    }
                }

            }

 ///return protected squares in every turn until they are deactivated
            if(!valid) {
                    for(int i = 0; i < 36; i++) {
                 {
                    if(storage[i] != 99 && board[storage[i]] != "A" && board[storage[i]] != "B") 
                     board[storage[i]] = "C";
                 }
               }
            }
            signal = 0;

///determine for stopping protection function
           if(timing + 2 == c) {
               for(int i = 0; i < 36; i++) {
                    if(name == "player 1") {
                             if(board[i] == "C") {
                                board[i] = "X";
                            }
                } else if(name == "player 2") {
                    if(board[i] == "C")
                        board[i] = "O";
                }
            }
            valid = true;
            board[player[0].position] = "A";
            board[player[1].position] = "B";}
        draw();

        c++;

                control++;
        if(control == 2) {

            control = 0;
            les++;
        }
        cout<<endl<<"Remained turn = "<<(turn + 1) - les;
    }while(c != turn * 2);
    for(int i = 0; i < 36; i++) {
                    if(name == "player 1") {
                            if(board[i] == "C") {
                                board[i] = "X";
                            }
                } else if(name == "player 2") {
                    if(board[i] == "C")
                        board[i] = "O";
                }
            }
    int o = 0,x = 0;
    for(int d = 0; d < 36; d++)
    {
        if(board[d] == "O")
        {
            o++;
        }
        else if(board[d] == "X")
        {
            x++;
        }
    }
    cout<<endl<<endl;
    cout<<"Player 1 = "<< x<<endl;
    cout<<"Player 2 = "<< o<<endl;



    if(o > x)
    { 
        cout<<"player 2 = winner";
    }
    else if(o == x)
    {
        cout<<"a tie";
    }
    else
    {
        cout<<"player 1 = winner";

    }
    system("pause");
    return 0;
}

    