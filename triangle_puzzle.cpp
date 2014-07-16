//
//  triangle_puzzle.cpp
//  
//
//  Created by yaakov silberstein on 12/6/13.
//
//

#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int find_max(vector<vector<int> > t,int total=0,int row=0,int col=0);
int main(){
    vector<vector<int> > triangle;
    vector<int> temp;
    ifstream infile ("triangle.txt");
    for(int i =0;infile;i++){
        for(int j=0;j<=i;j++){
            temp.push_back(0);
            infile>>temp[j];
        }
        if(infile)
            triangle.push_back(temp);
        temp.clear();
    }
    cout << find_max(triangle) << endl;
    return 0;

}
int find_max(vector<vector<int> > t,int total,int row,int col){
    total+=t[row].at(col);
    cout <<"..."<<endl;
    if(row==t.size()-1)
        return total;
    return find_max(t,total,row+1,col)>find_max(t,total,row+1,col+1) ? find_max(t,total,row+1,col):find_max(t,total,row+1,col+1);
}