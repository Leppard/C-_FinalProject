//1252964     李贞良       search.cpp


#include "search.h"


Search::Search(void)
{
}
Search::~Search(void)
{
}


int Search::searching(Inverted_Index & Cindex)
{
	cout<<"请输入需要查找的单词："<<endl;
	string word;
	cin>>word;
	cout<<"（单词所在文件     单词位置）"<<endl;
	map<string,map<string,vector<int>>>::iterator it=Cindex.index.begin();
	//map泛型指针用于在反向索引检索该单词
	vector<int>::iterator itt;
	//vector的泛型指针用于输出单词所在文件位置
	for(;it!=Cindex.index.end();++it)
		{
			if((it->second.find(word))==(it->second.end()))
				{					
					continue;
				}
			else
				{
					itt=(it->second)[word].begin();
					cout<<it->first<<"     ";
					for(;itt!=(it->second)[word].end();++itt)
						cout<<"第"<<*itt<<" ";
				}	
			cout<<endl;
		}
return 0;
}