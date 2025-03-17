#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <chrono>
#include <map>
#include <queue>
#pragma once


using namespace std;

class IdGenerator{
    static map<string, int> nr;
public:
    static string puneNr(int );
    static string genereaza(string );
};

