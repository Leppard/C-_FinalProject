//1252964     ������       search.cpp


#include "search.h"


Search::Search(void)
{
}
Search::~Search(void)
{
}


int Search::searching(Inverted_Index & Cindex)
{
	cout<<"��������Ҫ���ҵĵ��ʣ�"<<endl;
	string word;
	cin>>word;
	cout<<"�����������ļ�     ����λ�ã�"<<endl;
	map<string,map<string,vector<int>>>::iterator it=Cindex.index.begin();
	//map����ָ�������ڷ������������õ���
	vector<int>::iterator itt;
	//vector�ķ���ָ������������������ļ�λ��
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
						cout<<"��"<<*itt<<" ";
				}	
			cout<<endl;
		}
return 0;
}