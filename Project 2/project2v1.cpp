#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

//int sum = 0;
//int arry[3][4] = { 0 };

//Gobal vector
vector<vector<int>> arry2;

int mem(int b, int n, int k){
	if (arry2[b].at(n) > 0)
		return arry2[b].at(n);
	if (b == 0 && n == 0)
		return 1;
	else
	{
		for (int i = 0; i <= k; i++)
		{
			if (b-i>=0 && n-1>=0)
				arry2[b].at(n) +=mem(b - i, n-1, k);
		}
	}
	return arry2[b].at(n);
}
/*int mem2(int b, int n, int k){
	
	int total = 0;
	int row = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = b; j >0; j--){
			if (arry2[i].at(j) == 0){
				arry2[b].at(n) += 1;
			}
		}
		total++;
	}
	
	return arry2[b].at(n) += 1;
}*/

//Creates 2D vector of size row = B, col = N
void vec(int b, int n){
	arry2.resize(b+1);
	for (int i = 0; i < b+1; i++)
	{
		arry2[i].resize(n+1,0);
	}
}

int main(){

	ifstream infile;
	ofstream outfile;

	infile.open("input.txt");
	outfile.open("output.txt");

	if (infile.fail() || outfile.fail())
	{
		cout << "file can not be opened" << endl;
		return -1;
	}

	int count;

	infile >> count;

	for (int i = 1; i <= count; ++i)
	{
		int b, n, k, solution;

		infile >> b;
		infile >> n;
		infile >> k;

		//if if its not +1 get access violtaion on first function call
		vec(b, n);
		solution = mem(b, n, k);
		outfile << solution << endl;
	}

	infile.close();
	outfile.close();

	return 1;

}