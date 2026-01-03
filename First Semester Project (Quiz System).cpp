#include<iostream>
#include<limits>
#include<string>
#include<conio.h>
#include<iomanip>
using namespace std;

void Quiz_Questions(int access, string Task)
{
	char input, answer;
	int input_in_int, m = 20, score = 0;
	string question, option_A, option_B, option_C, option_D, ans;
	string main_heading = "Quiz System", quiz_heading = "  Quiz   ";
	static int n_Q = 0, n_Opt = 0, Take = 0;
	static string Questions[20][6];	//	Questions[n_Q][Question, Option_A, Option_B, Option_C, Option_D, Answer];
	if(access == 1 && Task == "Create")
	{
		AskAgain1:
			cout<<"How many questions(3-20) you want to add in this Quiz?"<<endl;
			cin>>n_Q;
		AskAgain2:
			cout<<"How many options(2-4) you want for each question?"<<endl;
			cin>>n_Opt;
		
		if(n_Q < 3 || n_Q > 20)
		{
			goto AskAgain1;
		}
		if(n_Opt < 2 || n_Opt > 4)
		{
			goto AskAgain2;
		}
		
		//	Adding Questions
		cout<<"\nNote: So, Now Write Questions and Their Options and keep in mind Once you Entered Any thing then you can't change it again So be careful!"<<endl<<endl<<endl;
		for(int i = 0; i < n_Q; i++)
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			for(int j = 0; j < n_Opt + 2; j++)
			{
				if(j == 0)
				{
					cout<<"\nQ no "<<i + 1<<": ";
					getline(cin, Questions[i][j]);
				}
				if(j == 1)
				{
					cout<<"Option 1: ";
					getline(cin, Questions[i][j]);
				}
				if(j == 2)
				{
					cout<<"Option 2: ";
					getline(cin, Questions[i][j]);
				}
				
				if(n_Opt == 3)
				{
					if(j == 3)
					{
						cout<<"Option 3: ";
						getline(cin, Questions[i][j]);
					}
				}
				else if(n_Opt == 4)
				{
					if(j == 3)
					{
						cout<<"Option 3: ";
						getline(cin, Questions[i][j]);
					}
					if(j == 4)
					{
						cout<<"Option 4: ";
						getline(cin, Questions[i][j]);
					}
				}
				
				if(j == n_Opt + 1)
				{
					cout<<"Enter the correct option(Example: 1, 2): ";
					cin>>Questions[i][j];
					
					// 	Checking Whether The Correct Option Is In The Provided Options
					if(n_Opt == 4 && Questions[i][j] != "1" && Questions[i][j] != "2" && Questions[i][j] != "3" && Questions[i][j] != "4")
					{
						j--;
					}
					else if(n_Opt == 3 && Questions[i][j] != "1" && Questions[i][j] != "2" && Questions[i][j] != "3")
					{
						j--;
					}
					else if(n_Opt == 2 && Questions[i][j] != "1" && Questions[i][j] != "2")
					{
						j--;
					}
				}
				
				if(Questions[i][j] == "")
				{
					cout<<"You Entered Empty String So Enter Again"<<endl;
					j--;
				}
				if(i == n_Q - 1 && j == n_Opt + 1 && Questions[i][j] != "")
				{
					cout<<"\nYou Have Succesfully Created The Quiz"<<endl;
					Take = 1;
					access = 0;
					system("pause");
				}
			}
		}
	}
	
	if(Task == "Take" && Take == 0)
	{
		system("cls");
		for(int i = 1; i <= 32; i++)
		{
			for(int j = 1; j <= 133; j++)
			{
					// Outputting The Main Borders Of The Program
				if(i == 1 || i == 32 || j == 1 || j == 133)
				{
					cout<<"#";
				}
					// Outputting The Program Heading
				else if(i == 3 && j >= 61 && j <= 71)
				{
					cout<<main_heading[j - 61];
				}
					// Creating The Inner Box
				else if(i == 5 && j >= 46 && j <= 86 || i == 28 && j >= 46 && j <= 86 || j == 46 && i >= 5 && i <= 28 || j == 86 && i >= 5 && i <= 28)
				{
					cout<<".";
				}
					// Outputting The Quiz Heading
				else if(i == 6 && j >= 62 && j <= 70)
				{
					cout<<quiz_heading[j - 62];
				}
					// Outputting The Four Options
				else if(i == 16 && j >= 49 && j <= 83)
				{
					string str = "Sorry! There is no quiz created yet";
					cout<<str[j - 49];
				}
					// Making The Box Hollow By Giving The Spaces
				else
				{
					cout<<" ";
				}
			}
		}
		cout<<endl;
		system("pause");
	}
	
	if(Task == "Take" && Take == 1)
	{
		for(int q = 0; q <= n_Q; q++)
		{
			system("cls");
			if(q != n_Q)
			{
				question = Questions[q][0];
				option_A = Questions[q][1];
				option_B = Questions[q][2];
			
				if(n_Opt == 3)
				{
					option_C = Questions[q][3];
				}
				if(n_Opt == 4)
				{
					option_C = Questions[q][3];
					option_D = Questions[q][4];
				}
				ans = Questions[q][n_Opt + 1];
				answer = ans[0];
			}
			
			for(int i = 1; i <= 32; i++)
			{
				for(int j = 1; j <= 133; j++)
				{
						// Outputting The Main Borders Of The Program
					if(i == 1 || i == 32 || j == 1 || j == 133)
					{
						cout<<"#";
					}
						// Outputting The Program Heading
					else if(i == 3 && j >= 61 && j <= 71)
					{
						cout<<main_heading[j - 61];
					}
						// Creating The Inner Box
					else if(i == 5 && j >= 46 && j <= 86 || i == 28 && j >= 46 && j <= 86 || j == 46 && i >= 5 && i <= 28 || j == 86 && i >= 5 && i <= 28)
					{
						cout<<".";
					}
						// Outputting The Quiz Heading
					else if(i == 6 && j >= 62 && j <= 70)
					{
						cout<<quiz_heading[j - 62];
					}
						// Outputting The Main Question Part 1 (First 27 characters of Question)
					else if(i == 10 && j >= 48 && j <= 83 && q < n_Q)
					{
						string Q;
						Q = "Q no ";
						if(j >= 48 && j <= 52)
						{
							cout<<Q[j - 48];
						}
						else if(j == 53)
						{
							if(q + 1 < 10)
							{
								cout<<(q + 1);
							}
							else
							{
								cout<<(q + 1) / 10;
							}
						}
						else if(j == 54 && (q + 1) > 9)
						{
							cout<<(q + 1) % 10;
						}
						else if(j == 55)
						{
							cout<<":";
						}
						else if(j == 56)
						{
							cout<<" ";
						}
						else
						{
							if(question.length() > j - 57)
							{
								cout<<question[j - 57];
							}
							else
							{
								cout<<" ";
							}
						}
					}
						// Outputting The Main Question Second Part(Characters of Question next to first 27)
					else if(i == 11 && j >= 49 && j <= 83 && q < n_Q && question.length() > 27)
					{
						if(question.length() > j - 49 + 27)
						{
							cout<<question[j - 49 + 27];
						}
						else
						{
							cout<<" ";
						}
					}
						// Outputting The Main Question Third Part(Characters of Question next to first 62)
					else if(i == 12 && j >= 49 && j <= 83 && q < n_Q && question.length() > 62)
					{
						if(question.length() > j - 49 + 62)
						{
							cout<<question[j - 49 + 62];
						}
						else
						{
							cout<<" ";
						}
					}
						// Outputting The Main Question Fourth Part(Characters of Question next to first 97)
					else if(i == 13 && j >= 49 && j <= 83 && q < n_Q && question.length() > 97)
					{
						if(question.length() > j - 49 + 97)
						{
							cout<<question[j - 49 + 97];
						}
						else
						{
							cout<<" ";
						}
					}
						// Outputting The Main Question Fifth Part(Characters of Question next to first 132)
					else if(i == 14 && j >= 49 && j <= 83 && q < n_Q && question.length() > 132)
					{
						if(question.length() > j - 49 + 132)
						{
							cout<<question[j - 49 + 132];
						}
						else
						{
							cout<<" ";
						}
					}
						// Outputting The Four Options
					else if(i == 16 && j >= 50 && j < 82 && q < n_Q)
					{
						string str = "Which one is the correct option?";
						cout<<str[j - 50];
					}
					else if(i == 18 && j >= 54 && j <= 83 && q < n_Q)
					{
						if(j == 54)
						{
							cout<<"1";
						}
						else if(j == 55)
						{
							cout<<".";
						}
						else if(j == 56)
						{
							cout<<" ";
						}
						else
						{
							if(option_A.length() > j - 57)
							{
								cout<<option_A[j - 57];
							}
							else
							{
								cout<<" ";
							}
						}
					}
					else if(i == 19 && j >= 54 && j <= 83 && q < n_Q)
					{
						if(j == 54)
						{
							cout<<"2";
						}
						else if(j == 55)
						{
							cout<<".";
						}
						else if(j == 56)
						{
							cout<<" ";
						}
						else
						{
							if(option_B.length() > j - 57)
							{
								cout<<option_B[j - 57];
							}
							else
							{
								cout<<" ";
							}
						}
					}
					else if(i == 20 && j >= 54 && j <= 83 && n_Opt > 2 && q < n_Q)
					{
						if(j == 54)
						{
							cout<<"3";
						}
						else if(j == 55)
						{
							cout<<".";
						}
						else if(j == 56)
						{
							cout<<" ";
						}
						else
						{
							if(option_C.length() > j - 57)
							{
								cout<<option_C[j - 57];
							}
							else
							{
								cout<<" ";
							}
						}
					}
					else if(i == 21 && j >= 54 && j <= 83 && n_Opt == 4 && q < n_Q)
					{
						if(j == 54)
						{
							cout<<"4";
						}
						else if(j == 55)
						{
							cout<<".";
						}
						else if(j == 56)
						{
							cout<<" ";
						}
						else
						{
							if(option_D.length() > j - 57)
							{
								cout<<option_D[j - 57];
							}
							else
							{
								cout<<" ";
							}
						}
					}
					
						// Outputting the Scores
					else if(i == 16 && j >= 60 && j < 74 && q == n_Q)
					{
						string Out = "Scores = ";
						if(j < 69)
						{
							cout<<Out[j - 60];
						}
						else if(j == 69 && score >= 10)
						{
							cout<<score / 10;
						}
						else if(j == 70)
						{
							if(score < 10)
							{
								cout<<score;
							}
							else
							{
								cout<<score % 10;
							}
						}
						else if(j == 71)
						{
							cout<<"/";
						}
						else if(j == 72)
						{
							if(n_Q < 10)
							{
								cout<<n_Q;
							}
							else
							{
								cout<<n_Q / 10;
							}
						}
						else if(j == 73 && n_Q >= 10)
						{
							cout<<n_Q % 10;
						}
						else
						{
							cout<<" ";
						}
					}
						// Making The Box Hollow By Giving The Spaces
					else
					{
						cout<<" ";
					}
				}
				cout<<endl;
			}
			input = getch();
			if(input == answer)
			{
				score++;
			}
			if(q != n_Q)
			{
				if(n_Opt == 2)
				{
					if(input != '1' && input != '2')
					{
						q--;
					}
				}
				else if(n_Opt == 3)
				{
					if(input != '1' && input != '2' && input != '3')
					{
						q--;
					}
				}
				else if(n_Opt == 4)
				{
					if(input != '1' && input != '2' && input != '3' && input != '4')
					{
						q--;
					}
				}
			}
		}
	}
	
	if(Task == "Delete")
	{
		system("cls");
		n_Q = 0;
		n_Opt = 0;
		Take = 0;
		for(int i = 1; i <= 32; i++)
		{
			for(int j = 1; j <= 133; j++)
			{
					// Outputting The Main Borders Of The Program
				if(i == 1 || i == 32 || j == 1 || j == 133)
				{
					cout<<"#";
				}
					// Outputting The Program Heading
				else if(i == 3 && j >= 61 && j <= 71)
				{
					cout<<main_heading[j - 61];
				}
					// Creating The Inner Box
				else if(i == 5 && j >= 46 && j <= 86 || i == 28 && j >= 46 && j <= 86 || j == 46 && i >= 5 && i <= 28 || j == 86 && i >= 5 && i <= 28)
				{
					cout<<".";
				}
					// Outputting The Quiz Heading
				else if(i == 6 && j >= 62 && j <= 70)
				{
					cout<<quiz_heading[j - 62];
				}
					// Outputting The Four Options
				else if(i == 16 && j >= 49 && j <= 82)
				{
					string str = "You Deleted the Quiz Successfully!";
					cout<<str[j - 49];
				}
					// Making The Box Hollow By Giving The Spaces
				else
				{
					cout<<" ";
				}
			}
		}
		cout<<endl;
		system("pause");
	}
	
}

bool Identify()
{
	system("cls");
	char pass;
	string password;
	cout<<"Enter 8-Character Password: ";
	for(int i = 1; i <= 8; i++)
	{
		pass = getch();
		cout<<"*";
		password += pass;
	}
	if(password == "AsadAziz")
	{
		cout<<"\nAccess Granted"<<endl;
		system("pause");
		return 1;
	}
	else
	{
		cout<<"\nAccess Denied"<<endl;
		return 0;
	}
}

void box()
{
	//	Clearing The Screen
	system("cls");
	
	//	Declaring The Variables
	string main_heading = "Quiz System", menu_heading = "Main Menu";
	string main_question = "What you wanna do?";
	string main_queries[4] =     {"1.Create a Quiz",
						"2. Take a Quiz ",
						"3.Delete a Quiz",
						"4.    Exit     "};
	int m = 20;
	for(int i = 1; i <= 32; i++)
	{
		for(int j = 1; j <= 133; j++)
		{
				// Outputting The Main Borders Of The Program
			if(i == 1 || i == 32 || j == 1 || j == 133)
			{
				cout<<"#";
			}
				// Outputting The Program Heading
			else if(i == 3 && j >= 61 && j <= 71)
			{
				cout<<main_heading[j - 61];
			}
				// Creating The Menu Box
			else if(i == 5 && j >= 133/2 - m && j <= 133/2 + m || i == 28 && j >= 133/2 - m && j <= 133/2 + m || j == 133/2 - m && i >= 5 && i <= 28 || j == 133/2 + m && i >= 5 && i <= 28)
			{
				cout<<".";
			}
				// Outputting The Menu Heading
			else if(i == 6 && j >= 62 && j <= 70)
			{
				cout<<menu_heading[j - 62];
			}
				// Outputting The Main Question
			else if(i == 10 && j >= 57 && j < 75)
			{
				cout<<main_question[j - 57];
			}
				// Outputting The Four Queries
			else if(i == 12 && j >= 59 && j <= 73)
			{
				cout<<main_queries[0][j - 59];
			}
			else if(i == 13 && j >= 59 && j <= 73)
			{
				cout<<main_queries[1][j - 59];
			}
			else if(i == 14 && j >= 59 && j <= 73)
			{
				cout<<main_queries[2][j - 59];
			}
			else if(i == 15 && j >= 59 && j <= 73)
			{
				cout<<main_queries[3][j - 59];
			}
				// Making The Box Hollow By Giving The Spaces
			else
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}
}

int main()
{
	char ch;
	int choice = 0;
	string questions[100];
	while(choice != 4)
	{
		box();
	 	ch = getch();
	 	choice = ch - '0';
	 	switch(choice)
	 	{
	 		case 1:
	 		     	Quiz_Questions(Identify(), "Create");
	 		     	break;
	 		case 2:
	 			Quiz_Questions(0, "Take");
	 		     	break;
	 		case 3:
	 			Quiz_Questions(0, "Delete");
	 		     	break;
		}
	}
	return 0;	
}