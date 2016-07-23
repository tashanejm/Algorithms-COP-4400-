#include<vector>
using namespace std;

class graph{
public:
	//Constructors
	graph();
	graph(int n, int m);
	
	//Setters
	void setGraph(int &x, vector<vector<int> > &arry, int &y);
	void setDirection(int n, int neigh, char c);
	void setVertices(int n);
	void addNeighb(int vertex, int neigh);
	void setStatus(int n, bool stat);
	void setData(int data);
	//Getters
	bool getStatus(int n)const;
	int getData(int n, int m) const;
	int getVertices() const;
	char getDirection(int n, int m) const;
	int getNumNeighb(int n) const;
	int getNeighbors(int n, int m)const;
	int getData(int n) const;
private:
	int vertices;				//Number of vertices
	vector<bool> status;		//Status visit or not
	vector<int> numNeighbors; //Number of Edges
	vector<int> data_val;	//Data Value
	vector<vector<int> > neighbors;
	vector<vector<char> > direct; //
};