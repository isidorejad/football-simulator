#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#define MAX_LINES 40

using namespace std;

    string border(40,'*');
    string border2(40,'=');
    string border3(40,'-');
    string border4(40, '_');

//Struct created to store the various elements of each team
struct team {
  string name;
  int points;
  int goals;
  int penaltyWins;
};

//These arrays are to store the teams that qualify to the other rounds
team allTeams[16] = {};
team quarterFinals[8] = {};
team semiFinals[4] = {};
team finals[2] = {};
team winner[1] = {};

//Function created to welcome the user to the applicaation
void welcomeMessage(){
    cout <<"=================================================\n";
    cout <<"== Welcome to our 2022 World Cup Competition!! ==\n";
    cout <<"====== We are so glad to have you join us ======="<<endl;
}

//This function reads the data from the file and stores it into an array for all the teams/countries participating in the tournament.
void DataIn(struct team allTeams[16]){
    ifstream file; //
    int x = 0;
    file.open("tournament.txt");//Opens the text file

    if (!file) {
        cout << ".................File failed to open!!!"<<endl;
        exit(2);
    }
    else
    {

        for (x=0; x<16; x++){
            getline(file, allTeams[x].name);
        }

    }

    file.close();

}

//This function displays the information stored in the text file
void DisplayOut (struct team allTeams[16]){
        int count = 1;
cout<<"World Cup Participants:  "<<endl;

        for(int j=0; j < 16; j++) {
            cout<<border4<<endl;
            cout<<count++<<"."<<allTeams[j].name<<endl;
}
cout<<endl;
}

void populateTeams() {
    string names[16] = {"Mexico","Italy","France","Germany","Argentina","Morocco","Sweden","Uraguay","England","Japan","Peru","Colombia","Spain","Canada","Greece","Brazil"};

 for(int x=0; x < 16; x++){
    team newTeams;

    newTeams.name = names[x];
    newTeams.points = 0;
    newTeams.goals = 0;
    newTeams.penaltyWins = 0;
    allTeams[x] = newTeams;
 }
}

//This function's sole responsibility is to simulate the round of 16
void tournament() {
string nextgame = "y";

cout<<"\n"<<border<<"\nRound 1:"<<endl;
cout<<border<<endl;
   int slot = 0;

   //This for loop will deal with two teams at a times
   //Team one will be represented by X (allTeams[x])
   //Team two will be represented by X + 1 (allTeams[x+1])
   //Team two is represented by X + 1 because it is the next team in the Array so when at index 0 Team B will be  0 + 1 which will be index 1; the next team in the array

   for(int x=0; x <= 14; x = x+2){ //Because we are already dealing with teams X and X + 1, there for the next team would be x + 2 therefore instead of adding 1 by doing x++ we add 2 to skip over to the next pair of teams


   //we randomize the goals scored and add them to the team's goal tally every round
     int team_one_score = rand() % 10;
     allTeams[x].goals += team_one_score;

     int team_two_score = rand() % 10;
     allTeams[x + 1].goals += team_two_score;

        cout<<"Teams: "<<allTeams[x].name<<" vs "<<allTeams[x+1].name<<endl;
        cout<<"Goals:   "<<team_one_score<<"         "<<team_two_score<<endl;


     if(team_one_score == team_two_score) { //this if statement deals with a drawn game

          //this is the preliminary round of penalties
          int team1penalty = 1 + rand() % 5;
          int team2penalty = 1 +rand() % 7;

          allTeams[x].penaltyWins += team1penalty;
          allTeams[x + 1].penaltyWins += team2penalty;

          while(team1penalty== team2penalty){ //If after the preliminary round of penalties are played there is still a tie, this while loop will run until there isn't a tie
              team1penalty = rand() % 5;
              team2penalty = rand() % 5;

              //we are still adding these rounds of penalties to the penalty tally
              allTeams[x].penaltyWins += team1penalty;
              allTeams[x + 1].penaltyWins += team2penalty;
          }

          if(team1penalty > team2penalty) { // If after the preliminary round the penalties are different, if team A scores more it goes to the next round
             quarterFinals[slot] = allTeams[x];
          } else { // if team B scores more then it goes to the next round
             quarterFinals[slot] = allTeams[x+1];
          }


     } else { // This else statement deals with games that are not tied
          if(team_one_score > team_two_score){ //if team A scores more goals it goes on to the next round
            quarterFinals[slot] = allTeams[x];
          } else { //if Team B scores more goals it goes on to the next round
            quarterFinals[slot] = allTeams[x+1];
          }
          }

     slot++; // Now that we have a slot filled, we need to increment the slot counter so the next team can go into the next slot
    }
   //this is just to display which teams made it to the next round
        cout<<border<<endl;
        cout<<"Quarter Finalist: \n";
        cout<<border<<endl;
   for(int x = 0; x < 8; x++){
    cout<<quarterFinals[x].name<<endl;
    cout<<"------------------------------"<<endl;
    }

cout<<"\nPlease press 'Y' to move onto the next round: "<<endl;
cin>>nextgame;
    slot = 0;

   //This for loop will deal with two teams at a times
   //Team A will be represented by X (quarterFinals[x])
   //Team B will be represented by X + 1 (quarterFinals[x+1])
   //Team B is represented by X + 1 because it is the next team in the Array so when at index 0 Team B will be  0 + 1 which will be index 1; the next team in the array
cout<<"\n"<<border<<"\nRound 2:"<<endl;
cout<<border<<endl;
   for(int x=0; x <= 6; x = x+2){ //Because we are already dealing with teams X and X + 1, there for the next team would be x + 2 therefore instead of adding 1 by doing x++ we add 2 to skip over to the next pair of teams


   //we randomize the goals scored and add them to the team's goal tally every round
     int team_one_score = rand() % 7;
     quarterFinals[x].goals += team_one_score;

     int team_two_score = rand() % 7;
     quarterFinals[x + 1].goals += team_two_score;

        cout<<"Teams: "<<quarterFinals[x].name<<" vs "<<quarterFinals[x+1].name<<endl;
        cout<<"Goals:   "<<team_one_score<<"         "<<team_two_score<<endl;

     if(team_one_score == team_two_score) { //this if statement deals with a drawn game

          //this is the preliminary round of penalties
          int team1penatly = rand() % 5;
          int team2penatly = rand() % 5;

          quarterFinals[x].penaltyWins += team1penatly;
          quarterFinals[x + 1].penaltyWins += team2penatly;

          while(team1penatly == team2penatly){ //If after the preliminary round of penalties are played there is still a tie, this while loop will run until there isn't a tie
              team1penatly = rand() % 5;
              team2penatly = rand() % 5;

              //we are still adding these rounds of penalties to the penalty tally
              quarterFinals[x].penaltyWins += team1penatly;
              quarterFinals[x + 1].penaltyWins += team2penatly;
          }

          if(team1penatly > team2penatly) { // If after the preliminary round the penalties are different, if team A scores more it goes to the next round
             semiFinals[slot] = quarterFinals[x];
          } else { // if team B scores more then it goes to the next round
             semiFinals[slot] = quarterFinals[x+1];
          }


     } else { // This else statement deals with games that are not tied
          if(team_one_score > team_two_score){ //if team A scores more goals it goes on to the next round
            semiFinals[slot] = quarterFinals[x];
          } else { //if Team B scores more goals it goes on to the next round
            semiFinals[slot] = quarterFinals[x+1];
          }
     }
     slot++; // Now that we have a slot filled, we need to increment the slot counter so the next team can go into the next slot
   }
        cout<<border<<endl;
        cout<<"Semi-Finalist: \n";
        cout<<border<<endl;
   for(int x = 0; x < 4; x++){
        cout<<semiFinals[x].name<<"\n";
        cout<<"------------------------------"<<endl;
   }
cout<<"\nPlease press 'Y' to move onto the next round: "<<endl;
cin>>nextgame;

   slot = 0;

   //This for loop will deal with two teams at a times
   //Team A will be represented by X (semiFinals[x])
   //Team B will be represented by X + 1 (semiFinals[x+1])
   //Team B is represented by X + 1 because it is the next team in the Array so when at index 0 Team B will be  0 + 1 which will be index 1; the next team in the array
cout<<"\n"<<border<<"\nRound 3:"<<endl;
cout<<border<<endl;
   for(int x=0; x <= 2; x = x+2){ //Because we are already dealing with teams X and X + 1, there for the next team would be x + 2 therefore instead of adding 1 by doing x++ we add 2 to skip over to the next pair of teams


   //we randomize the goals scored and add them to the team's goal tally every round
     int team_one_score = rand() % 6;
     semiFinals[x].goals += team_one_score;

     int team_two_score = rand() % 6;
     semiFinals[x + 1].goals += team_two_score;

        cout<<"Teams: "<<semiFinals[x].name<<" vs "<<semiFinals[x+1].name<<endl;
        cout<<"Goals:   "<<team_one_score<<"         "<<team_two_score<<endl;


     if(team_one_score == team_two_score) { //this if statement deals with a drawn game

          //this is the preliminary round of penalties
          int team1penalty = rand() % 5;
          int team2penalty = rand() % 5;

          semiFinals[x].penaltyWins += team1penalty;
          semiFinals[x + 1].penaltyWins += team2penalty;

          while(team1penalty == team2penalty){ //If after the preliminary round of penalties are played there is still a tie, this while loop will run until there isn't a tie
              team1penalty = rand() % 5;
              team2penalty = rand() % 5;

              //we are still adding these rounds of penalties to the penalty tally
              semiFinals[x].penaltyWins += team1penalty;
              semiFinals[x + 1].penaltyWins += team2penalty;
          }

          if(team1penalty > team2penalty) { // If after the preliminary round the penalties are different, if team A scores more it goes to the next round
             finals[slot] = semiFinals[x];
          } else { // if team B scores more then it goes to the next round
             finals[slot] = semiFinals[x+1];
          }


     } else { // This else statement deals with games that are not tied
          if(team_one_score > team_two_score){ //if team A scores more goals it goes on to the next round
            finals[slot] = semiFinals[x];
          } else { //if Team B scores more goals it goes on to the next round
            finals[slot] = semiFinals[x+1];
          }
     }
     slot++; // Now that we have a slot filled, we need to increment the slot counter so the next team can go into the next slot
   }
        cout<<border3<<endl;
        cout<<"Finalist: \n";
        cout<<border3<<endl;
   for( int x = 0; x < 2; x++){
    cout<<finals[x].name<<"\n";
    cout<<"------------------------------"<<endl;
}
cout<<"\nPlease press 'Y' to move onto the next round: \n"<<endl;
cin>>nextgame;
    slot = 0;
cout<<"\n"<<border<<"\nRound 4:"<<endl;
cout<<border<<endl;
   for(int x=0; x <= 0; x = x+2){ //Because we are already dealing with teams X and X + 1, there for the next team would be x + 2 therefore instead of adding 1 by doing x++ we add 2 to skip over to the next pair of teams


   //we randomize the goals scored and add them to the team's goal tally every round
     int team_one_score = rand() % 6;
     finals[x].goals += team_one_score;

     int team_two_score = rand() % 6;
     finals[x + 1].goals += team_two_score;

        cout<<"Teams: "<<finals[x].name<<" vs "<<finals[x+1].name<<endl;
        cout<<"Goals:   "<<team_one_score<<"         "<<team_two_score<<endl;


     if(team_one_score == team_two_score) { //this if statement deals with a drawn game

          //this is the preliminary round of penalties
          int team1penalty = rand() % 5;
          int team2penalty = rand() % 5;

          finals[x].penaltyWins += team1penalty;
          finals[x + 1].penaltyWins += team2penalty;

          while(team1penalty == team2penalty){ //If after the preliminary round of penalties are played there is still a tie, this while loop will run until there isn't a tie
              team1penalty = rand() % 5;
              team2penalty = rand() % 5;

              //we are still adding these rounds of penalties to the penalty tally
              finals[x].penaltyWins += team1penalty;
              finals[x + 1].penaltyWins += team2penalty;
          }

          if(team1penalty > team2penalty) { // If after the preliminary round the penalties are different, if team A scores more it goes to the next round
             winner[slot] = finals[x];
          } else { // if team B scores more then it goes to the next round
             winner[slot] = finals[x+1];
          }


     } else { // This else statement deals with games that are not tied
          if(team_one_score > team_two_score){ //if team A scores more goals it goes on to the next round
            winner[slot] = finals[x];
          } else { //if Team B scores more goals it goes on to the next round
            winner[slot] = finals[x+1];
          }
     }
     slot++; // Now that we have a slot filled, we need to increment the slot counter so the next team can go into the next slot
   }
        cout<<border3<<endl;
        cout<<"WINNER: \n";
        cout<<border3<<endl;
  for( int x = 0; x < 1; x++){
    cout<<winner[x].name<<"\n";
    cout<<"------------------------------"<<endl;
cout<<"\nPlease press 'Y' to move onto the next round: \n"<<endl;
cin>>nextgame;
}}
//This function stores the statistics of each game to display at the ending of the tournament
void statistics(){
        int showStats;
     do{
        cout<<"========================="<<endl;
        cout << "STATISTICS" << endl;
        cout<<"========================="<<endl;
        cout << "|1| GAME 1" << endl;
        cout << "|2|   GAME 2" << endl;
        cout << "|3|     GAME 3" << endl;
        cout << "|4|       GAME 4" << endl;
        cout << "|5|          GAME 5" << endl;
        cout << "|6|            GAME 6" << endl;
        cout << "|7|               MENU" << endl;
        cout<<"_________________________"<<endl;
        cin >> showStats;
        enum user_Options{game1 = 1,game2,game3, game4,game5, game6, menu};
        cout<<endl;

        switch(showStats){
        case 1:
            cout<<"\n\n\n"<<endl;
            cout<<"Round 1 Statistics: "<<endl;
            cout<<"\n";
            for(int x = 0; x < 16; x ++){
                cout<<allTeams[x].name << " Goals: " << allTeams[x].goals << " Penalties: " << allTeams[x].penaltyWins <<endl;
            }
            break;

        case 2:
            cout<<"\n\n\n"<<endl;
            cout<<"Round 2 Statistics: "<<endl;
            cout<<"\n";
            for(int x = 0; x < 8; x ++){
                cout<<"\n";
                cout<<quarterFinals[x].name << " Goals: " << quarterFinals[x].goals << " Penalties: " << quarterFinals[x].penaltyWins <<endl;
            }
            break;

        case 3:

            cout<<"\n\n\n"<<endl;
            cout<<"Round 3 Statistics: "<<endl;
            cout<<"\n";
                for(int x = 0; x < 4; x ++){
                    cout<<"\n";
                    cout<<semiFinals[x].name << " Goals: " << semiFinals[x].goals << " Penalties: " << semiFinals[x].penaltyWins <<endl;
            }
            break;

        case 4:
            cout<<"\n\n\n"<<endl;
            cout<<"Round 4 Statistics: "<<endl;
            cout<<"\n";
                for(int x = 0; x < 2; x ++){
                    cout<<"\n";
                    cout<<finals[x].name << " Goals: " << finals[x].goals << " Penalties: " << finals[x+1].penaltyWins <<endl;
                }
                break;
        case 5:
            cout<<"\n\n\n"<<endl;
            cout<<"Round 5 Statistics: "<<endl;
            cout<<"\n";
            cout<<"\n";
            cout<<winner[0].name << " Goals: " << winner[0].goals << " Penalties: " << winner[0].penaltyWins <<endl;
            cout<<winner[1].name << " Goals: " << winner[1].goals << " Penalties: " << winner[1].penaltyWins <<endl;

        case 6:
            exit;
            break;


        default:
            cout<<"INCORRECT input.........please choose one of the following numbers\nbetween 1-6!!!";
            break;
            }

    }
    while(showStats !=6);
}

//This is main functions which calls out the other functions with a menu to prompt input from the user
int main(){
    welcomeMessage();
    populateTeams();
    //Takes user input from list of choices
int user_in;
    do{
        cout<<"========================="<<endl;
        cout << "2022 World Cup Finale" << endl;
        cout<<"========================="<<endl;
        cout << "|1|  Manage" << endl;
        cout << "|2|        About" << endl;
        cout << "|3|             Exit" << endl;
        cout<<"_________________________"<<endl;
        cin >> user_in;
        enum user_Options{ manage = 1,manual,abort };
        cout<<endl;

        string playGame;
        switch(user_in){
            case 1:
                cout<<"-------------------------------------------------\n";
                cout<<"Thank you for being a manager for our tournament\n";
                cout<<"this year.You will find a list of all our compet-"<<endl;
                cout<<"itors below.\n";
                cout<<"*************************************************\n"<<endl;
                DataIn(allTeams);
                DisplayOut(allTeams);
                cout<<"Press p to start the matches--->";
                cin>>playGame;
                tournament();
                statistics();
                break;

            case 2:
                cout<<" =================================================================\n";
                cout<<"| This program manages an international football tournament for   |\n";
                cout<<"| sixteen (16) teams. This competition has 4 Rounds, 16 countries |\n";
                cout<<"| participating in this FIFA World Cup. Only 2 teams will make it |\n";
                cout<<"| to the finals.Each game must have a winner, thus each team can  |\n";
                cout<<"| either win or lose, via direct win or loss or penalty.The best 8|\n";
                cout<<"| teams go on to the 2nd round and the best 4 to the semi-finals  |\n";
                cout<<"| and the best two to the finals.                                 |"<<endl;
                cout<<"|_________________________________________________________________|"<<endl;
                break;

            case 3:
                exit(2);
                break;
            default:
                cout<<"INCORRECT input.........please choose one of the following numbers\nbetween 1-3!!!";
                break;
                }
    }
    while(user_in !=3);
    statistics();
    return 2;
}//Ends main function
