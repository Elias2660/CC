/*
C++ Solution


USACO 2021 February Contest, Bronze
Problem 1. Year of the Cow
Link to problem:
http://usaco.org/index.php?page=viewproblem2&cpid=1107

Recommended Compile Command: 
g++ -std=c++17 year.cpp 
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

int N, years; 
map<string, vector<string> > connections, cow_links, statements;
map<string, bool> visited;
map<string, int> zodiac;




int find_year_difference(vector<string> statement, string original_cow_zodiac) {
    int cow_num = zodiac[original_cow_zodiac], connection_num = zodiac[statement[4]];
    //if previous, remove 12; if next, add 12
    if(statement[3] == "next" && connection_num > cow_num) {
        return connection_num - cow_num;
    }
    if (statement[3] == "previous" && connection_num < cow_num) {
        return connection_num - cow_num;
    }
    int bonus = statement[3] == "next"? 12:-12;
    return connection_num + bonus - cow_num;
}


void dfs(string cow, int year, string zodiac) {
    //breath first search, look through contacts until elsie reached
    if (cow == "Elsie") {
        years = year;
        return;
    }
    for (string connection:connections[cow]) {
        //for each connection, if not visited, search and add year difference
        if (!visited[connection]) {
            visited[connection] = true;
            vector<string> statement = statements[connection];
            //find the differences in years
            int year_diff = find_year_difference(statement, zodiac);
            dfs(connection, year + year_diff, statement[4]);
    }
}}


int main() {
    //freopen("year.in", "r", stdin);
    cin >> N;
    vector<string> zodiac_list{"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse",
    "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};

    for (int i = 0; i < 12; i++) {
        zodiac[zodiac_list[i]] = i + 1;
    }
    for (int n = 0; n < N; n++) {
        vector<string> statement(8);
        for (string& word:statement) {
            cin >> word;
        }
        //if the dictionary does not exist, create it and make an instance
        if (connections.count(statement[0]) == 0) {
            vector<string> s;
            connections[statement[0]] = s;
        }
        if (connections.count(statement[7]) == 0) {
            vector<string> s;
            connections[statement[7]] = s;
        }

        visited[statement[0]] = false;
        visited[statement[7]] = false;

        statements[statement[0]] = statement;
        connections[statement[7]].push_back(statement[0]);
        connections[statement[0]].push_back(statement[7]);
    }
    years = 0;
    visited["Bessie"] = true;
    dfs("Bessie", 0, "Ox");
    cout << abs(years) << endl;
}