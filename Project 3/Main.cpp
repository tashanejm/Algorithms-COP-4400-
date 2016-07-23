#include<iostream>
#include "Header.h"
#include<stack>
#include<fstream>
using namespace std;

void DFS(graph &list, const int &vertices, ostream& outputfile){
	stack <int> hop;
	stack<char> directed;

	int start = 0;
	hop.push(start);
	
	while (start != vertices-1)
	{
		if (list.getNumNeighb(start) == 0)
		{
			hop.pop();
			directed.pop();
			start = hop.top();
		}
		for (int i = 0; i < list.getNumNeighb(start); i++)
		{
			if (list.getStatus(list.getNeighbors(start,i)) == true)
			{
				directed.push(list.getDirection(start, i));
				start = list.getNeighbors(start, i);
				list.setStatus(start, false);
				hop.push(start);
				break;
			}
			if (i == list.getNumNeighb(start)- 1){
				if (list.getStatus(list.getNeighbors(start, i) == true))
				{
					hop.pop();
					directed.pop();
					start = hop.top();
					break;
				}
			}
		}
	}

	stack<char> temp;
	for (int i = directed.size(); i > 0; i--){
		temp.push(directed.top());
		directed.pop();
	}
	while (!temp.empty()){
		outputfile << temp.top()<< " ";
		temp.pop();
	}

}

int main(){

	int row;
	int col;
	int num;
	vector< vector<int> > arry;
	ifstream infile;
	ofstream outfile;

	infile.open("input.txt");
	outfile.open("output.txt");

	if (infile.fail() || outfile.fail())
	{
		cout << "file can not be opened" << endl;
		return 0;
	}

	infile >> row;
	infile >> col;

	if (row == 0 && col == 0)
	{
		return 0;
	}

	arry.resize(row);
	for (int i = 0; i < row; i++)
	{
		arry.at(i).resize(col);
		for (int j = 0; j < col; j++)
		{
			infile >> num;
			arry.at(i).at(j) = num;
		} 
	}
	graph list(row, col);
	list.setGraph(row, arry, col);

	DFS(list, list.getVertices(), outfile);
	return 0;
}
