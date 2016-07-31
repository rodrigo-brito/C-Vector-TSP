/**
*   TSP - Travelling salesman problem
*   Authors: Rodrigo Brito (contato@rodrigobrito.net) e Bruno Gomes (bruno.nonato@ifmg.edu.br)
*   Project URI: https://github.com/rodrigo-brito/C-Vector-TSP
*/
#include <iostream>
#include "tsp.h"

using namespace std;

int main(){
    //Pointer of distance
    vector< vector<int> > * distance = new vector< vector<int> >( 5, vector<int>(5) );

    //Dataset
	int initialize[5][5]=
    {
        {0,3,4,2,7},//A
        {3,0,4,6,3},//B
        {4,4,0,5,8},//C
        {2,6,5,0,6},//D
        {7,3,8,6,0}//E
    };

    for(int i = 0; i < distance->size(); i++){
        for(int j = 0; j < distance->size(); j++){
            distance->at(i)[j] = initialize[i][j];
        }
    }

    int values_tour[] = {0,1,3,2,4};
    std::vector<int> * tour = new vector<int>(values_tour, values_tour + sizeof(values_tour) / sizeof(int) );

    TSP * tsp = new TSP( distance );
    cout<<"C = "<<tsp->getCost(tour)<<endl;
    tsp->solve( tour );
    cout<<endl;
    cout<<"C = "<<tsp->getCost(tour)<<endl;

    for(int i = 0; i < tour->size(); i++){
        cout<<" "<<tour->at(i);
    }
    return 0;
}
