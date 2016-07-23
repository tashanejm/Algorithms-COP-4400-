#include "Header.h"
#include<iostream>


graph::graph(){
	neighbors.resize(0);
};
graph::graph(int n, int m){
	vertices = 0;
	neighbors.resize(n*m);
	direct.resize(n*m);

}
void graph::setGraph(int &row, vector<vector<int> > &arry, int &col)
{
	int n = 0;
	int end =0;
	int amount;
	for (int i = 0; i < row; i++){
		for (int j = 0; j <col; j++){
			int data = arry.at(i).at(j);
			//No Neighbors
			if (data == 0) {
				numNeighbors.push_back(end - n);
				setData(data);
				status.push_back(true);
				n = end;
				continue;
			}
			//East
			if (j + data < col){
				amount = i*col + j + data + 1 - 1;
				addNeighb(numNeighbors.size(), amount);
				setDirection(numNeighbors.size(), amount, 'E');
				end++;
			}

			//South
			if (i + data < row){
				amount = (i + data)*row + j + 1 - 1;
				addNeighb(numNeighbors.size(), amount);
				setDirection(numNeighbors.size(), amount, 'S');
				end++;
			}
			//West
			if (j - data > -1){
				amount = i*col + j - (data - 1) - 1;
				addNeighb(numNeighbors.size(), amount);
				setDirection(numNeighbors.size(), amount, 'W');
				end++;
			}
			//North
			if (i - data > -1){
				amount = (i - data)*row + j + 1 - 1;
				addNeighb(numNeighbors.size(), amount);
				setDirection(numNeighbors.size(), amount, 'N');
				end++;
			}
			setData(data);
			numNeighbors.push_back(end - n);
			status.push_back(true);
			n = end;
		}
	}
	vertices = row*col;
}

void graph::addNeighb(int vertex, int neighb){
	neighbors.at(vertex).push_back(neighb);
}

void graph::setVertices(int n){
	vertices = n;
}
int graph::getVertices()const{
	return vertices;
}

int graph::getNumNeighb(int n)const{
	return numNeighbors.at(n);
}

bool graph::getStatus(int n) const{
	return status.at(n);
}

void graph::setStatus(int n, bool stat){
	status.at(n) = stat;
}

int graph::getNeighbors(int n, int m) const{
	return neighbors.at(n).at(m);
}

char graph::getDirection(int n, int m)const {
	return direct.at(n).at(m);
}
void graph::setDirection(int vertex, int neighb, char c){
	direct.at(vertex).push_back(c);
}
void graph::setData(int data){
	data_val.push_back(data);
}
int graph::getData(int n)const {
	return data_val.at(n);
}