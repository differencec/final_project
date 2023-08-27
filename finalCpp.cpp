////Square Dynasty (Conclusion Sample Game Code)
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;



    const int Max=36;
    int storage[Max];
    int miniCount = 0;
    bool valid = false;
    int preve0 = 30;
    int preve1 = 5;
    int next_move;
    int assisCount = 1;
    int change = 0;
    char yeah = '?';
    int counter2 = 0;



   string board[Max] = {};

    ///for the characters
    string tempo;

    string initial1 = board[30];
    string initial2 = board[5];
    int les = 1;

    ///for  the current inedex
    int turn = 2,j = 0;
    int c = 0;
    int control = 0;
    int signal = 0,timing = 100;
    string lastMove;
    string in;
    string name;
    char activate;

class Player {

    private:string power;
        public:
            int MM=0;
            int ass_mark;
            int power_countdown=0;
            int dice;
            string ascii;
            string name;
            string owned;
            int position;
            string powerName;
            int counter = 0;
            int assisCount = 1;
            int startMarking = 0;
            int counter2 = 0;
            Player() {
                ascii = "";
                name = "";
                owned = "";
                position = 0;
                powerName = "";

            }
            Player(string ascii,string name,string owned,int position) {
                this->ascii = ascii;
                this->name = name;
                this->owned = owned;
                this->position = position;

            }
            void indiPower() {
                cout<<"Well I don't have";

            }
            void getpower(){
                do{
                    cout<<"Choose your character(type \"I\" for Increase Move and Mark and \"M\" Move and \"F\" for feeeze for now):";
                    getline(cin,power);
                    if(power!="I" && power!="M" && power != "F"){
                        cout<<endl<<"Wrong input";
                    }
                }while(power!="I" && power!="M" && power != "F");

            }
            string checkpower(){
                return power;
            }
            void rng(){
                dice = rand()%6+1;
            }
    };

    void draw(Player p1,Player p2)
{
    //system("cls");
    cout<<"Player "<<p1.checkpower()<<") A\n";
    cout<<"Player "<<p2.checkpower()<<") B\n";


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


int teleport(Player p,int trace1,int trace2){
    int potal_1;       ///potal is a term for teleport.
    int potal_2;
    board[trace1]=p.owned;
    board[trace2]=p.owned;

    if(trace1==7)
    {
        potal_1=7;
        potal_2=27;
    }
    else
    {
        potal_1=27;
        potal_2=7;

    }

    return potal_2;
}



    int movee(string dir,Player currentPlayer,int &preve,int c) {
        string cool = (c % 2 == 0) ? "B" : "A";

        if(dir == "d")
            {
            if(currentPlayer.position != 35 && currentPlayer.position != 29 && currentPlayer.position != 23 && currentPlayer.position != 17 && currentPlayer.position != 11 && currentPlayer.position != 5 )
                    {

                            if(board[currentPlayer.position+1] != "A" && board[currentPlayer.position+1] != "B" && board[currentPlayer.position + 1] != currentPlayer.powerName)/////"A" "B" ko opponent ascii;
                            {
                            currentPlayer.position = currentPlayer.position + 1;
                            preve = currentPlayer.position - 1;
                            }
                    }
                        return currentPlayer.position;
            }

        else if(dir == "s")
            {

            if(currentPlayer.position != 30 && currentPlayer.position != 31 && currentPlayer.position != 32 && currentPlayer.position != 33 && currentPlayer.position != 34 && currentPlayer.position != 35)
                    {
                        if(board[currentPlayer.position + 6] != "A" && board[currentPlayer.position + 6] != "B" && board[currentPlayer.position + 6] != currentPlayer.powerName)
                        {
                            currentPlayer.position = currentPlayer.position + 6;
                            preve = currentPlayer.position - 6;
                        }
                    }
                            return currentPlayer.position;

            }
        else if(dir == "w")
            {
            if(currentPlayer.position != 0 && currentPlayer.position != 1 && currentPlayer.position != 2 && currentPlayer.position != 3 && currentPlayer.position != 4 && currentPlayer.position != 5)
                    {
                        if(board[currentPlayer.position - 6] != "A" && board[currentPlayer.position - 6] != "B" && board[currentPlayer.position - 6] != currentPlayer.powerName)
                        {
                            currentPlayer.position = currentPlayer.position - 6;
                            preve = currentPlayer.position + 6;
                        }
                    }
                            return currentPlayer.position;

            }
        else if(dir == "a")
            {
            if(currentPlayer.position != 30 && currentPlayer.position != 24 && currentPlayer.position != 18 && currentPlayer.position != 12 && currentPlayer.position != 6 && currentPlayer.position != 0)
                    {
                        if(board[currentPlayer.position - 1] != "A" && board[currentPlayer.position - 1] != "B" && board[currentPlayer.position - 1] != currentPlayer.powerName)
                        {
                            currentPlayer.position = currentPlayer.position - 1;
                            preve = currentPlayer.position + 1;
                        }
                    }
                        return currentPlayer.position;

            }
    }



int power_Pos(){
    return rand()%Max+1;
}
int rngpower(){
    return rand();
}
int increase_move(int original_move,string& dir){

    int add_move;
    cout<<"\n!!Your Increase Movement Power activited!!\n";
    do
    {

        cout<<"Power Phrase"<<endl;

        cout<<"Enter the number of move you want to extent:(ranging : 1 to 3 )";
        cin>>add_move;


        cout<<"You entered:"<<add_move<<endl;
    }while(add_move<1 || add_move>3);
    cout<<"Your dice count become "<< original_move+add_move<<endl;
    cin.ignore();

    return original_move+add_move;

}
void marge(Player p1,Player p2,int center){

   // for(int i=7;i<5;i==){
            //int row=6;
            //int col=6;
            if(center-7 != p2.position && center > 6 && center-7 !=  12 && center-7 !=  18 && center-7 !=  24 && center-7 !=  30){
                board[center-7]=p1.owned;
            }
            if(center>5){
                board[center-6]=p1.owned;
            }
            if(center-5 != p2.position && center > 5 && center-5 != 11 && center-5 != 17 && center-5 != 23 && center-5 != 29 && center-5 != 35){
                board[center-5]=p1.owned;
            }
            if(center-1 != p2.position && center-1 !=  0 && center-1 !=  6 && center-1 !=  12 && center-1 !=  18 && center-1 !=  24 && center-1 !=  30){
                board[center-1]=p1.owned;
            }
            if(center+1 != p2.position && center+1 !=5 && center+1 != 11 && center+1 != 17 && center+1 != 23 && center+1 != 29 && center+1 != 35){
                board[center+1]=p1.owned;
            }
            if(center+5 != p2.position &center < 30 && center+5 != 6 && center+5 != 12 && center+5 != 18 && center+5 != 24 && center+5 != 30){
                board[center+5]=p1.owned;
            }
            if(center+6 != p2.position && center < 30){
                board[center+6]=p1.owned;
            }
            if(center+7 !=p2.position &&center <30 && center+7 !=5 && center+7 != 11 && center+7 != 17 && center+7 != 23 && center+7 != 29 && center+7 != 35){
                board[center+7]=p1.owned;
            }

}
void Ass(Player& p1){//MM is 1 mark  and 2 move
    if(p1.MM==1){

        board[p1.position]=="L";
        p1.ass_mark=p1.position;
    }
    else if(p1.MM==2){
        board[p1.position]=p1.owned;
        p1.position=p1.ass_mark;
    }

}
int main(void)
{

    srand(time(NULL));
    ///for random functions
    int powerspwan_t=0;
    int power_count=0;
    for( int i = 0; i< Max; i++){
        board[i] = " ";
        storage[i] = 99;};
    Player player[] = { Player("A","player 1","X",30), Player("B","player 2","O",5) };//add by coa power assi
    cout<<"Power \"I\" will let you increase you dice move by (1 to 3) as you wish,(this power can be use one time per 3 turn)"<<endl<<endl;
    cout<<"Power\"F\" will make to skip another player turn (this skill can use one time per 10 turn)"<<endl<<endl;
    cout<<"Power \"M\'s\" first active time will mark your current place and second time active will move to the marked placed(this power can be use one time per 2 turn)"<<endl<<endl;
    cout<<"below here is character section first time is player 1 and second time is player 2 "<<endl<<endl;

    for(int i=0;i<2;i++){

        player[i].getpower();

    }


    Player currentPlayer;
    Player nextPlayer;

    board[30] = "A";
    board[5] = "B";
    board[7]="T";
    board[27]="T";
    int inner = 0;
    int startMarking = 0;
    int freeze=0;
    draw(player[0],player[1]);




//Check whether the input is 5 or 10

     do//turn5and 10 loop
    {
        cout<<"Better to test about not int"<<endl;
        cout<<"\nHow many turns do you wanna play: (suggesst : 5 - 15 ): ";
        cin>>turn;
        cin.ignore();

    }while(turn < 0 );
    system("cls");
    draw(player[0],player[1]);
    //first while loop for turn
    cout<<endl<<"Remained turn = "<<(turn + 1) - les<<endl;
    player[0].rng();
    do
    {
        if(powerspwan_t==3 && power_count<4){
            powerspwan_t=0;
            int temppos;
               //char powertype= rngpower() % 2 == 0 ? 'M' : 'P';
            do{
                temppos= power_Pos();
                cout<<endl<<endl<<"Power appear at board "<<temppos<<endl<<endl;
            }while( board[temppos]=="A"|| board[temppos]=="B" || board[temppos]=="M" || board[temppos]=="P" || board[temppos]=="T" || board[temppos]=="C");
            board[temppos]= (rngpower() % 2) == 0 ? "M" : "P";


        }



        if(c % 2 == 0 ){
            currentPlayer=player[0];
            nextPlayer=player[1];



        }
        else{
            currentPlayer=player[1];
            nextPlayer=player[0];
        }
        nextPlayer.rng();

        cout<<endl;
        if(c == turn*2-1){
            cout<<endl<<currentPlayer.name<<"\'s dice "<<currentPlayer.dice<<"*******Turn End*******"<<endl;
        }
        else{
            cout<<currentPlayer.name<<"\'s dice "<<currentPlayer.dice<<" | and | "<<nextPlayer.name<<"\'s dice is "<<nextPlayer.dice<<endl;
        }

        //cout<<currentPlayer.name<<"'s available move according to rolling dice = "<<ran<<endl<<endl;
        j = 0;
        if(freeze==0)
            {
        cout<<endl<<"Start "<<currentPlayer.name<<endl;

    bool pna=0;       //Power Not Aviable
    do{

        if(currentPlayer.power_countdown==0){
            if(currentPlayer.checkpower()=="M" && currentPlayer.MM==1){
                cout<<endl<<endl<<"You marked at "<< currentPlayer.ass_mark <<endl<<endl;
            }

            else{
                cout<<endl<<endl<<"Your Power is ready"<<endl<<endl;
            }
        }
        else{
             cout<<endl<<endl<<"Power cooldown : "<<currentPlayer.power_countdown<<endl<<endl;
        }

        cout<<endl<<"Conquer(by using aswd and x to active ability) :";
        getline(cin,in);
        if (in != "a" && in != "s" && in != "w" && in != "d" && in != "x")
        {
           cout << "\nInput wrong!!"<<endl;
        }


    if(in=="x")
    {

        if(pna==0)
        {
            pna=1;           //power not avialable
            if(currentPlayer.power_countdown>0){
                cout<<endl<<"Your power in cooldown";
            }
            else
            {
                if(currentPlayer.checkpower()=="I"){
                    currentPlayer.power_countdown=6;
                    currentPlayer.dice=increase_move(currentPlayer.dice,in);

                }
                else if(currentPlayer.checkpower()=="M"){

                    currentPlayer.MM++;
                    Ass(currentPlayer);
                    if(currentPlayer.MM==2){
                        currentPlayer.power_countdown=4;
                        currentPlayer.MM==0;
                    }
                }
                else if(currentPlayer.checkpower()=="F"){
                    freeze=1;
                    currentPlayer.power_countdown=20;
                    cout<<endl<<endl<<"Player "<<nextPlayer.name<<" turn will be skip";
                }
            }
        }
        else if(pna==1){
            cout<<endl<<endl<<"You already active power"<<endl<<endl;
        }




    }
    }while(in != "a" && in != "s" && in != "w" && in != "d");
/*
    };

*/
        pna=0;
        ///while loop for the randomized dice number
        while(j < currentPlayer.dice && yeah != 'j')
        {

            ///To determine whether player 1's turn or player 2's
            int newb = (currentPlayer.name == "player 1") ? 0 : 1;
            int preve = (currentPlayer.name == "player 1") ? preve0 : preve1;




                    next_move = movee(in,currentPlayer,preve,c);

                    if(board[next_move] == "T")
                            {
                                //make the initialpos  a little early for teleport function..]
                                next_move=teleport(currentPlayer,next_move,preve);

                            } else if(board[next_move]=="M"){
                                    marge(currentPlayer,nextPlayer,next_move);
                            }

                            else if(board[next_move] == "P") {
                                   //send signal to activate protection
                                   signal = 1;
                            }


                    currentPlayer.position = next_move;
                    //cout<<endl<<"My position is now:"<<currentPlayer.position;
                    board[preve] = currentPlayer.owned;
                    board[next_move] = currentPlayer.ascii;

                    if(currentPlayer.startMarking != 0) {
            board[currentPlayer.startMarking] = "L";
        };





                    j++;



        }

            }
            else if (freeze==1){
                freeze=0;
            }


            if(currentPlayer.power_countdown>0){
                currentPlayer.power_countdown--;
            }
            if(nextPlayer.power_countdown>0){
                nextPlayer.power_countdown--;
            }

 ///Changing normal squares to the protected squares once they have signal
            if(signal) {
                timing = c;
                for(int i = 0; i < Max; i++) {
                        if(board[i] == currentPlayer.owned){
                            board[i]="C";
                            storage[miniCount] = i;
                            miniCount++;

                        }
                     /*
                    if(currentPlayer.name == "player 1") {
                            if(board[i] == player[0].owned) {
                               board[i] = "C";
                            }

                } else if(currentPlayer.name == "player 2") {
                    if(board[i] == player[1].owned)
                       board[i] = "C";
                }
                */
            }
        }

 ///when they get signal, they start storing the protected squares
 /*
            if(signal) {
                for(int i = 0; i < Max; i++) {
                    if(board[i] == "C") {
                        storage[miniCount] = i;
                                miniCount++;
                    }
                }

            }*/
 ///return protected squares in every turn until they are deactivated
            if(!valid) {
                    for(int i = 0; i < Max; i++) {
                 {
                    if(storage[i] != 99 && board[storage[i]] != "A" && board[storage[i]] != "B")
                     board[storage[i]] = "C";
                 }
               }
            }
            signal = 0;

///determine for stopping protection function
           if(timing + 2 == c) {
               for(int i = 0; i < Max; i++) {
                    if(currentPlayer.name == "player 1")
                    {
                             if(board[i] == "C") {
                                board[i] = "X";
                            }
                    }
                    else if(currentPlayer.name == "player 2")
                    {
                    if(board[i] == "C")
                        board[i] = "O";
                    }
            }
            valid = true;
            //board[player[0].position] = "A";
            //board[player[1].position] = "B";
            }

        draw(player[0],player[1]);

        if(c % 2 == 0 ){
            player[0]=currentPlayer;
            player[1]=nextPlayer;
        }

        else{
            player[1]=currentPlayer;
            player[0]=nextPlayer;
        }

        c++;

        control++;
        if(control == 2) {

            control = 0;
            les++;
        }
        if(currentPlayer.power_countdown>0){
            currentPlayer.power_countdown--;
        }
        powerspwan_t++;
        cout<<endl<<"Remained turn = "<<(turn + 1) - les;
    }while(c != turn * 2);
    for(int i = 0; i < Max; i++) {//loop for scorcing
                    if(currentPlayer.name == "player 1") {
                            if(board[i] == "C") {
                                board[i] = "X";
                            }
                } else if(name == "player 2") {
                    if(board[i] == "C")
                        board[i] = "O";
                }
            }
    int o = 0,x = 0;
    for(int d = 0; d < Max; d++)
    {//more scorcing
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
    cout<<"Player "<<player[0].name<<" =  "<<x<<endl;
    cout<<"Player "<<player[1].name<<" = "<< o<<endl;



    if(o > x)
    {//condition for winner sentence
        cout<<"player "<<player[1].name<<"= winner"<<endl;
    }
    else if(o == x)
    {
        cout<<"a tie"<<endl;
    }
    else
    {
        cout<<"player  "<<player[0].name<<"= winner"<<endl;

    }
    system("pause");
    return 0;
}

    
