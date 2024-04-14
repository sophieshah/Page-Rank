#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

class adjacencyList{
private:
    map<int,vector<int>> m;
    vector<double> RT;
    vector<string> urlList;
    vector<double> RValues;
    map<vector<int>,int> flipped;
public:
    adjacencyList();
    void pageRank(int n);
    void addToVect(string url1, string url2);
    void makeAdjList(string url1, string url2);
    void findRT();
    void firstRValues();
    void matrixMultiply();
    void printValues();
    string returnValues();
};

adjacencyList::adjacencyList() {
    //constructor
}

//calls matrix multiply p-1 times (p is # of power iterations)
void adjacencyList::pageRank(int n) {
//    findRT();
//    firstRValues();
    for(int j=0; j<n-1; j++){
        matrixMultiply();
    }
}

//checks if values to be added are new and adds them to a vector
//then calls make make adj list function
void adjacencyList::addToVect(string url1, string url2) {
    bool url1Unique = true;
    bool url2Unique = true;
    for(auto & i : urlList){
        if(url1==i){
            url1Unique = false;
        }
        else if(url2==i){
            url2Unique = false;
        }
    }
    if(url1Unique){
        urlList.push_back(url1);
    }
    if(url2Unique){
        urlList.push_back(url2);
    }

    makeAdjList(url1, url2);
}

//inserts the values into the map, with url1 being the key and url2 being added to a vector of values of the adjacent edges
void adjacencyList::makeAdjList(string url1, string url2) {
    int firstIndex;
    int secondIndex;
    for(long long unsigned int i=0; i<urlList.size(); i++){
        if(url1==urlList[i]){
            firstIndex = i;
        }
        if(url2==urlList[i]){
            secondIndex = i;
        }
    }

    m[firstIndex].push_back(secondIndex);
}

//initializes r(t) to 1/V
void adjacencyList::findRT() {
    for(long long unsigned int  j=0; j<urlList.size(); j++){
        RT.push_back(0.0);
    }
    map<int, vector<int>>::iterator it;
    for(it = m.begin(); it!=m.end(); it++){
        RT[it->first] += 1.0/it->second.size();
//            RT.push_back(1.0/it->second.size());
    }

//    cout<<"RT Values:"<<endl;
//    for(int i=0; i<RT.size(); i++){
//        cout<<RT[i]<<" ";
//    }
//    cout<<endl;
}

//initialize the matrix with 1/V
void adjacencyList::firstRValues() {
    for(long long unsigned int  i=0; i<urlList.size(); i++){
        RValues.push_back(1.0/urlList.size());
    }

//    cout<<"R Values:"<<endl;
//    for(int j=0; j<RValues.size(); j++){
//        cout<<RValues[j]<<" ";
//    }
//    cout<<endl;
}

//iterates through the map and multiplies each column of the matrix by the row in r(t)
void adjacencyList::matrixMultiply() {

//    cout<<"R Values:"<<endl;
//    for(int j=0; j<RValues.size(); j++){
//        cout<<RValues[j]<<" ";
//    }
//    cout<<endl;

//    cout<<"RT Values:"<<endl;
//    for(int i=0; i<RT.size(); i++){
//        cout<<RT[i]<<" ";
//    }
//    cout<<endl;

    //int currIndex = 0;
    vector<double> newR;
    //cout<<"initializing vect"<<endl;
    for(long long unsigned int  j=0; j<urlList.size(); j++){
        newR.push_back(0.0);
    }

    map<int, vector<int>>::iterator it;
    for(it = m.begin(); it!=m.end(); it++){
        //cout<<"iterating through map"<<endl;
        for(long long unsigned int  i=0; i<it->second.size(); i++){
            //cout<<"iterating through vector"<<endl;
            double value = RT[it->first] * RValues[it->first];
//            cout<<RT[it->first]<<" * "<< RValues[it->first]<<"     ";
            newR[it->second[i]] += value;
//            cout<<it->second[i]<<" "<<value<<endl;
        }
    }
    //cout<<endl;

    RValues = newR;
}

//creates new map with urls and page rank value then prints them in alphabetical order
void adjacencyList::printValues() {
//    map<int, vector<int>>::iterator it = m.begin();
//    for(it; it!=m.end(); it++){
//        cout<<it->first<<" ";
//        for(int i=0; i<it->second.size();i++){
//            cout<<it->second[i];
//        }
//        cout<<endl;
//    }
//
//    for(int i=0; i<5; i++){
//        cout<<RT[i]<<" ";
//    }
//    cout<<endl;
//
//    for(int j=0; j<5; j++){
//        cout<<RValues[j]<<" ";
//    }
//    cout<<endl;

    //cout<<"printing values"<<endl;
    map<string, double> printedMap;

    for(long long unsigned int  i=0; i<urlList.size();i++){
        printedMap[urlList[i]] = RValues[i];
    }

    sort(urlList.begin(),urlList.end());
    //cout<<"sorted"<<endl;

    map<string, double>::iterator it;
    int index = 0;
    for(it = printedMap.begin(); it != printedMap.end(); it++) {
        if(it->first == urlList[index]){
            cout<<it->first<<" ";
            cout << fixed << showpoint;
            cout<<std::setprecision(2)<<it->second<<endl;
        }
        index++;
    }
}

string adjacencyList::returnValues() {
    map<string, double> printedMap;
    string returned = "";

    for(long long unsigned int  i=0; i<urlList.size();i++){
        printedMap[urlList[i]] = RValues[i];
    }

    sort(urlList.begin(),urlList.end());

    map<string, double>::iterator it;
    int index = 0;
    for(it = printedMap.begin(); it != printedMap.end(); it++) {
        if(it->first == urlList[index]){
            returned += it->first + " ";
            stringstream in;
            in << fixed << setprecision(2) << it->second;
            string rankOutput = in.str();
            returned += rankOutput;
            returned += "\n";

//            cout << fixed << showpoint;
//            cout<<std::setprecision(2)<<it->second<<endl;
        }
        index++;
    }
    return returned;
}

int main() {
//    adjacencyList a;
//    a.addToVect("google.com","gmail.com");
//    a.addToVect("google.com","maps.com");
//    a.addToVect("facebook.com","ufl.edu");
//    a.addToVect("ufl.edu","google.com");
//    a.addToVect("ufl.edu","gmail.com");
//    a.addToVect("maps.com","facebook.com");
//    a.addToVect("gmail.com","maps.com");
//
//    a.pageRank(2);
//    a.printValues();



//    user input code from project 2 powerpoint

    int n;
    cin>>n;

    int p;
    cin>>p;

    adjacencyList a;
    string l;
    getline(cin,l);
    for(int i=0; i<n; i++){
        string line;
        getline(cin, line);
        istringstream in(line);

        string from;
        in>>from;
        //cout<<from;

        string to;
        in>>to;
        //cout<<to;

        a.addToVect(from, to);
        //cout<<"inserted "<<from<<" "<<to<<endl;
    }
    a.findRT();
    a.firstRValues();
    a.pageRank(p);
    a.printValues();

    return 0;
}