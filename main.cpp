#include<bits/stdc++.h>
using namespace std;

/*
 * 
 */
int dimension = 5;
map<string, pair<int, int> > moves;
map<string, pair<string, string> > directions;
void initData() {
     moves["NORTH"] = make_pair(0,1);
    moves["SOUTH"] = make_pair(0,-1);
    moves["EAST"] = make_pair(1,0);
    moves["WEST"] =make_pair(-1,0);
    
    directions["NORTH"] = make_pair("WEST","EAST");
    directions["WEST"] = make_pair("SOUTH","NORTH");
    directions["SOUTH"] = make_pair("EAST","WEST");
    directions["EAST"] = make_pair("NORTH","SOUTH");
}
bool vaildPosition(int x, int y) {
        return x >= 0 && x < dimension && y >= 0 && y < dimension;
}
int main() {
         freopen("in.txt", "r", stdin);
         freopen("out.txt", "w", stdout);
         initData();
         bool isVaildPosition = false;
         string command, currentFace, newFace;
         int currentXPosition, currentYPosition, newXPosition, newYPosition;
         while(cin >> command) {
             if (command == "PLACE") {
                 cin >> newXPosition >> newYPosition >> newFace;
                 isVaildPosition = vaildPosition(newXPosition, newYPosition);
                 if (isVaildPosition) {
                     isVaildPosition = true;
                     currentXPosition = newXPosition;
                     currentYPosition = newYPosition;
                     currentFace = newFace;
                 }
             } else {
                 if(!isVaildPosition) {
                     continue;
                 }
                 if(command == "MOVE") {
                     if(vaildPosition(currentXPosition + moves[currentFace].first, currentYPosition + moves[currentFace].second)) {
                         currentXPosition += moves[currentFace].first;
                         currentYPosition += moves[currentFace].second;
                     }
                 }
                 else if (command == "LEFT") {
                     currentFace = directions[currentFace].first;
                 }
                 else if (command == "RIGHT") {
                     currentFace = directions[currentFace].second;
                 }
                 else if(command == "REPORT") {
                     cout << currentXPosition << "," << currentYPosition << "," << currentFace << endl;
                 };
             }
         }
    return 0;
}