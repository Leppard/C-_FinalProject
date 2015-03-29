//1252964     ¿Ó’Í¡º       Inverted_Index.h


#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<fstream>
#include<string>
#include <algorithm>
#include<io.h>
using namespace std;



class Inverted_Index
{
public:
	Inverted_Index(void);
	~Inverted_Index(void);
	map<string,map<string,vector<int>>> index;
	int count;
	int make_index();
};

