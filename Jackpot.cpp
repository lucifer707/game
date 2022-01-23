#include <iostream>
#include<fstream>//use to read and write file
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>//Needed to use the time function -it return the number of second allapsed since jan1971
using namespace std;

int Guess;
int Total;

// Question Class
class Question {
private:
	string Question_Text;
	string Answer_1;
	string Answer_2;
	string Answer_3;
	string Answer_4;
	int Correct_Answer;
	int Question_Score;

public:
	// Setter Function
	void setValues(string, string,
				string, string,
				string, int, int);

	// Function to ask questions
	void askQuestion();
};
void rules();
int main()
{
    string playerName;
    int age;
    int g;
    int chance; // stores player's balance
    int bettingAmount;
    int guess;
    int dice; // stores the random number
    char choice;
    srand(time(0)); // "Seed" the random generator
    cout << "\n\t\t========WELCOME TO JACKPOT WORLD=======\n\n";
    cout << "\n\nWhat's your Name : ";
    getline(cin, playerName);
    cout<< "\n\nHow old are you : ";
    cin>>age;
    ofstream out("data.txt");
    out<<"player Name : "<<playerName<<endl;
    out<<"player Age : "<<age<<endl;
    cout << "\n\nYou have Three chance\n";
    chance=3;
    do
    {
        system("cls");
        rules();
        cout << "\n\nYou have " << chance << " chance"<<"\n";
// Get player's betting balance
        do
        {
            cout << "Hey, " << playerName<<"\n";
            bettingAmount=1;
            
        }while(bettingAmount > chance);
// Get player's numbers
        do
        {
            cout << "Guess any betting number between 1 & 10 :";
            cin >> guess;
            g=guess;
            out<<"Number guess : "<<g<<endl;
            if(guess <= 0 || guess > 10)
                cout << "\nNumber should be between 1 to 10\n"
                    <<"Re-enter number:\n ";
        }while(guess <= 0 || guess > 10);
        dice = rand()%10 + 1;
        if(dice == guess)
        {
        	 system("cls");
            cout << "\n\nYou are in luck!! You have won first round"<<endl;//here we have to create the function for next round
            cout << "WELCOME TO QUIZ ROUND"
		<< endl;
	cout << "\nPress Enter to start "
		<< "the quiz... " << endl;

	// Input
	cin.get();
	string Respond;
	cout << "Are you ready to take"
		<< " the quiz " 
		<< "? y/n" << endl;
	cin >> Respond;

	if (Respond == "y") {
		cout << endl;
		cout << "Good Luck!" << endl;
	}
	else {
		cout << "Okay Good Bye!" << endl;
		return 0;
	}

	// Objects of Question Class
	Question q1;
	Question q2;
	Question q3;
	Question q4;
	Question q5;


	// 3 is the position of
	// correct answer
	q1.setValues("Question : How many players are there in one Baseball team", "five",
				"Six", "Eight",
				"Nine", 4, 10);
	q2.setValues("Question : Where is Salim Ali National Park located", "Bihar",
				"Answer punjab", "Jammu and Kashmir",
				"Delhi", 3, 10);
	q3.setValues("Question : Name any other search engine besides google", "Yahoo",
				"Microsoft", "Dolphin",
				"firefox", 1, 10);
	q4.setValues("Question : What is the currency of Japan", "Dollor",
				"taka", "Yen",
				"rupee", 3, 10);
	q5.setValues("Question : what is the full form of ISRO", "Indian science and research organization",
				"Indian space and research organisation", "Indian science instritute",
				"Indian research institute", 2, 10);

	q1.askQuestion();
	q2.askQuestion();
	q3.askQuestion();
	q4.askQuestion();
	q5.askQuestion();

	// Display the total score
	cout << "Total Score = " << Total
		<< "out of 50" << endl;

	// Display the results

	// If the player pass the quiz
	if (Total >= 30) {
		cout << "Congrats you passed the"
			<< " quiz!" << endl;
		cout <<"You won 5k"<<endl;
		return 0;
	}

	// Otherwise
	else {
		cout << "Alas! You failed the quiz."
			<< endl;
		cout << "Better luck next time."
			<< endl;
	}
		}
        else
        {
            cout << "Oops, better luck next time !! You lost  "<< bettingAmount <<"chance"<<"\n";
            chance = chance - bettingAmount;
            cout << "\n"<<playerName<<", You have " << chance <<" chance left"<<"\n";
            cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
        }
        cout << "\nThe winning number was : " << dice <<"\n";
        if(chance == 0)
        {
            cout << "You have no chance left ";
            break;
        }
        
    }while(choice =='Y'|| choice=='y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game.  ";
    return 0;
}

// Function to set the values of
// the questions
void Question::setValues(
	string q, string a1,
	string a2, string a3,
	string a4, int ca, int pa)
{
	Question_Text = q;
	Answer_1 = a1;
	Answer_2 = a2;
	Answer_3 = a3;
	Answer_4 = a4;
	Correct_Answer = ca;
	Question_Score = pa;
}

// Function to ask questions
void Question::askQuestion()
{
	cout << endl;

	// Print the questions
	cout << Question_Text << endl;
	cout << "1. " << Answer_1 << endl;
	cout << "2. " << Answer_2 << endl;
	cout << "3. " << Answer_3 << endl;
	cout << "4. " << Answer_4 << endl;
	cout << endl;

	// Display the answer
	cout << "What is your answer?(in number)"
		<< endl;
	cin >> Guess;

	// If the answer is correct
	if (Guess == Correct_Answer) {
		cout << endl;
		cout << "Correct !" << endl;

		// Update the correct score
		Total = Total + Question_Score;
		cout << "Score = " << Question_Score
			<< " out of "
			<< Question_Score
			<< "!" << endl;
		cout << endl;
	}

	// Otherwise
	else {
		cout << endl;
		cout << "Wrong !" << endl;
		cout << "Score = 0"
			<< " out of "
			<< Question_Score
			<< "!" << endl;
		cout << "Correct answer = "
			<< Correct_Answer
			<< "." << endl;
		cout << endl;
	}
}
void rules()
{
    system("cls");
    cout << "\t\t======JACKPOT NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets chance to play next round\n";
    cout << "\t3. Wrong choice, and you lose the chance\n\n";
}
