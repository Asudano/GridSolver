// Created by Andrew Sudano 6/25/15

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <exception>

using namespace std;
void solvep1(vector< vector< char> > grid, vector<string> &path, int x, int y, unsigned int am, int g1, int g2);

int StringToNumber(const string &Text)//This allows for the program to convers a string to a number
{                               
	stringstream ss(Text);
	int result;
	return ss >> result ? result : 0;
}

string chartostring(const char& ch)// this allows for the program to conver a char to a string
{
	stringstream ss;
	string news;
	ss << ch;
	ss >> news;
	return news;
}

void up(vector< vector< char> > grid, vector<string> path, int x, int y, unsigned int am,  int g1, int g2){
	if (path.size() >= am){// if you have already gone over the path length it will exit
		return;
	}
	int np = am - path.size();
	int x1 = abs(g1 - x);
	int y1 = abs(g2 - y);
	if ((x1 + y1) > np){// this is some speed checking. Here it checks to see if the current path could lead to a successful ending if not it will exit out
		return;
	}
	if (path.size() == 0 || path[path.size() - 1] != "down"){// this checks to see if you can move in the desired direction
		if (y != 0){
			if (grid[x][y - 1] == 'x'){// this will check if the desired direction will lead the final step
				for (unsigned int k = 0; k < path.size(); k++){// if it does it will loop through printing the path that led there
					cout << path[k] << " ";
				}
				cout << "up" << endl;// it will not add the final step to the path so that it can return and find other potnetial solutions to the anwer than 
				//moving in this direction
				return;
			}
			else{
				path.push_back("up");
				y--;
				solvep1(grid, path, x, y, am,g1, g2);
			}
		}
		else{
			return;
		}
	}
	else{// if you cant move in the desired direction it will exit
		return;
	}
}
void right(vector< vector< char> > grid, vector<string> path, int x, int y, unsigned int am,  int g1, int g2){
	if (path.size() >= am){// if you have already gone over the path length it will exit
		return;
	}
	int np = am - path.size();
	int x1 = abs(g1 - x);
	int y1 = abs(g2 - y);
	if ((x1 + y1) > np){// this is some speed checking. Here it checks to see if the current path could lead to a successful ending if not it will exit out
		return;
	}
	if (path.size() == 0 || path[path.size() - 1] != "left"){// this checks to see if you can move in the desired direction
		if (x != (grid.size()-1)){
			if (grid[x + 1][y] == 'x'){// this will check if the desired direction will lead the final step
				for (unsigned int k = 0; k < path.size(); k++){// if it does it will loop through printing the path that led there
					cout << path[k] << " ";
				}
				cout << "right" << endl;// it will not add the final step to the path so that it can return and find other potnetial solutions to the anwer than 
				//moving in this direction
				return;
			}
			else{
				path.push_back("right");
				x++;
				solvep1(grid, path, x, y, am, g1, g2);
			}
		}
		else{
			return;
		}
	}
	else{// if you cant move in the desired direction it will exit
		return;
	}
}
void down(vector< vector< char> > grid, vector<string> path, int x, int y, unsigned int am,  int g1, int g2){
	if (path.size() >= am){// if you have already gone over the path length it will exit
		return;
	}
	int np = am - path.size();
	int x1 = abs(g1 - x);
	int y1 = abs(g2 - y);
	if ((x1 + y1) > np){// this is some speed checking. Here it checks to see if the current path could lead to a successful ending if not it will exit out
		return;
	}
	if (path.size() == 0 || path[path.size() - 1] != "up"){// this checks to see if you can move in the desired direction
		if (y != (grid.size() -1)){
			if (grid[x][y + 1] == 'x'){// this will check if the desired direction will lead the final step
				for (unsigned int k = 0; k < path.size(); k++){// if it does it will loop through printing the path that led there
					cout << path[k] << " ";
				}
				cout << "down" << endl;// it will not add the final step to the path so that it can return and find other potnetial solutions to the anwer than 
				//moving in this direction
				return;
			}
			else{
				path.push_back("down");
				y++;
				solvep1(grid, path, x, y, am, g1, g2);
			}
		}
		else{
			return;
		}
	}
	else{// if you cant move in the desired direction it will exit
		return;
	}
}
void left(vector< vector< char> > grid, vector<string> path, int x, int y, unsigned int am,  int g1, int g2){
	if (path.size() >= am){// if you have already gone over the path length it will exit
		return;
	}
	int np = am - path.size();
	int x1 = abs(g1 - x);
	int y1 = abs(g2 - y);
	if ((x1 + y1) > np){// this is some speed checking. Here it checks to see if the current path could lead to a successful ending if not it will exit out
		return;
	}
	if (path.size() == 0 || path[path.size() - 1] != "right"){// this checks to see if you can move in the desired direction
		if (x != 0){
			if (grid[x - 1][y] == 'x'){// this will check if the desired direction will lead the final step
				for (unsigned int k = 0; k < path.size(); k++){// if it does it will loop through printing the path that led there
					cout << path[k] << " ";
				}
				cout << "left" << endl;// it will not add the final step to the path so that it can return and find other potnetial solutions to the anwer than 
				//moving in this direction
				return;
			}
			else{
				path.push_back("left");
				x--;
				solvep1(grid, path, x, y, am,  g1, g2);
			}
		}
		else{
			return;
		}
	}
	else{// if you cant move in the desired direction it will exit
		return;
	}
}


void solvep1(vector< vector< char> > grid, vector<string> &path, int x, int y, unsigned int am, int g1, int g2){
	//this is the recursive function that loops through the below possibilities 
	up(grid, path, x, y, am,  g1, g2);
	right(grid, path, x, y, am,  g1, g2);
	down(grid, path, x, y, am,  g1, g2);
	left(grid, path, x, y, am,  g1, g2);
}



int main()
{
	cout << "Program is starting....." << endl;// friendly message telling the user the program is starting 
	unsigned long i = 0;
	unsigned long k = 100000000;
	while (i < k){// This manualy creates a slight pause by looping up to 100000000
		i++;
	}
	while (true){
		//its important to note that all of the char to number comparison are the number equivlent of the char that can can be found on an ascii table 
		// also can be found with the following link http://www.asciitable.com/
		vector<string> path;// a vector called path is created to keep track of the moves that have occured
		vector< vector< char> > grid;
		// x o - - - - 
		vector<char> f1;// this is the vector that is used to input into the larger vector of vectors called grid
		string inputsize;
		string yourl;
		string wherg;
		int k, u1 = 0, u2 = 0, g1 = 0, g2 = 0; // intilizes some of the variables that are used
		// below is checking for the iputs to go into the program it also does alot of error checking to nake sure the user entered in a correct input
		cout << "How big is the grid" << endl;
		getline(cin, inputsize);// The computer is asking the user for a size to the grid
		int u = 0;
		if (inputsize[0] == 48 && (inputsize[1] > 57 || inputsize[1] <= 48)){
			cout << "I am sorry the grid cant be of size zero" << endl; // if the user enters a value of zero the program will fail
			return 1;
		}
		while (inputsize[u] != 0){
			if (inputsize[u] > 57 || inputsize[u] < 48){
				cout << "You did not enter a proper number" << endl;// the value that the user entered is checked to make sure that it is a number and not another charachter
				cin.get();
				return 1;
			}
			u++;
		}
		k = StringToNumber(inputsize);
		cout << "Where are you on the split grid cordinates by spaces" << endl; // here asks the user to input where they are starting 
		getline(cin, yourl);
		unsigned int m = 0;
		while (yourl[m] != 32){
				u1 += StringToNumber(chartostring(yourl[m]));
				m++;
				if (m >= yourl.size()){
					cout << "I am sorry you didn't enter number seperated by spaces" << endl;
					cin.get();
					return 1;
				}

		}

		if (u1 >= k){
			cout << "There is an error, you starting someplace off the grid" << endl;
			cin.get();
			return 1;
		}
		m++;
		while (yourl[m] != 0){
			u2 += StringToNumber(chartostring(yourl[m]));
			m++;
		}

		if (u2 >= k){
			cout << "There is an error, you starting someplace off the grid" << endl;
			cin.get();
			return 1;
		}
		cout << "where are you trying to get" << endl;
		getline(cin, wherg);
		unsigned int q = 0;
		while (wherg[q] != 32){
			g1 += StringToNumber(chartostring(wherg[q]));
			q++;
			if (q >= wherg.size()){
				cout << "I am sorry you didn't enter number seperated by spaces" << endl;
				cin.get();
				return 1;
			}
		}
		if (g1 >= k){
			cout << "There is an error, you are trying to get someplace off the grid" << endl;
			cin.get();
			return 1;
		}
		q++;
		while (wherg[q] != 0){
			g2 = StringToNumber(chartostring(wherg[q]));
			q++;
		}
		if (g2 >= k){
			cout << "There is an error, you are trying to get someplace off the grid" << endl;
			cin.get();
			return 1;
		}
		for (int i = 0; i < k; i++){
			f1.clear();
			for (int l = 0; l < k; l++)
				f1.push_back('-');
			grid.push_back(f1);
		}
		cout << "how many moves will you allow" << endl;
		string amm;
		getline(cin, amm);
		unsigned int l = StringToNumber(amm);
		grid[u1][u2] = 'o';
		grid[g1][g2] = 'x';
		while (true){
			if (u1 == g1 && u2 == g2){
				cout << "You have selected the same beggining and ending location" << endl; // If the user entered the same starting and ending point then 
				break;
			}
			if (abs(g1 - u1) + abs(g2 - u2) >= l) {
				cout << " It is not possible with those specifications" << endl;// If the user entered in impossible parameters the computer will say so here
				break;
			}
			solvep1(grid, path, u1, u2, l, g1, g2);
			break;
		}
		cout << "Program finsihed running press enter to continue" << endl;
		cin.get();// this allows for the program to way for the user to input a enter
		cout << "If you would like to try again enter in 1 then press enter. If not just press enter" << endl;
		string stayornot;
		getline(cin, stayornot);
		if (stayornot[0] != 49){// this checks to see if the user would like for the program to run again
			cout << "Exiting Program .... " << endl;
			unsigned long i = 0;
			unsigned long k = 100000000;
			while (i < k){ // This manualy creates a slight pause by looping up to 100000000
				i++;
			}
			return 0;
		}
	}
	return 0;
}
