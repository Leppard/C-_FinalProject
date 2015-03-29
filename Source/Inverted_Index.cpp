//1252964     李贞良       Inverted_Index.cpp



#include "Inverted_Index.h"


Inverted_Index::Inverted_Index(void)
{
}
Inverted_Index::~Inverted_Index(void)
{
}

int Inverted_Index::make_index()
{	
   	//创建反向索引目录	
	string path;
	string Dir_path;
	while(true)								//输入文件夹位置，输入有误则重新输入
	{
	cout<<"请输入需检索文件夹位置："<<endl;
	cout<<"（示例：如C盘文件夹“name”：C：\\name\\）"<<endl;
	cin>>path;
	Dir_path=path+"*.txt";
	long handle;                          
	//用于查找的句柄  
	struct _finddata_t fileinfo;               
	//文件信息的结构体 
	handle=_findfirst(Dir_path.c_str(),&fileinfo);      
	//第一次查找 
	if(-1==handle)
	{cout<<"文件夹位置有误，请检查路径或格式重新输入！"<<endl<<endl;
	continue;}
	else
		break;
	}
	long handle;                          
	//用于查找的句柄  
	struct _finddata_t fileinfo;               
	//文件信息的结构体 
	handle=_findfirst(Dir_path.c_str(),&fileinfo);      
	//第一次查找 
	index[fileinfo.name]; 

	ifstream infile_1(path+fileinfo.name); 
	if(!infile_1)cout<<"error"<<endl;
	//打开此文件
	string except_word;	
	cout<<"请输入要排除单词列表的文件位置："<<endl;
	cout<<"(不需要排除单词直接“!”后回车可跳过）"<<endl;
	cin>>except_word;
	ifstream infile_2;
	infile_2.open(except_word.c_str());
	while(!infile_2)
	{
		if(except_word=="!")
			break;
		cout<<"找不到排除单词列表文件位置！请检查后重新输入！"<<endl;
		cin>>except_word;
		infile_2.open(except_word.c_str());
	} 
	string str_1,str_2;
	set<string> word_except;
		{
			word_except.insert(str_2);
		//生成需要排除的单词和标点	
		}
	count=1;
	while(infile_1>>str_1)
		{
			int str_length=str_1.size();
			if((str_1[str_length-1]<='z'&&str_1[str_length-1]>='a')||(str_1[str_length-1]=='\''))
				{
			
				}
			else
				{
					string substring=str_1.substr(0,str_length-1);
					str_1=substring;
				}
		//判断单词最后一位是标点时，生成子字符串去掉标点
			if(word_except.count(str_1))
				{
					count++;
					continue;
					//当单词出现在排除单词列表中时跳过当前单词的循环，不使用该单词
				}
			index[fileinfo.name][str_1].push_back(count);			
		count++;
		//count用于计算单词在该文件的所在位置
		}
	
	while(!_findnext(handle,&fileinfo)) 
		//循环查找其他符合的文件，直到找不到其他的为止
		{	
			count=1;
			index[fileinfo.name];
			ifstream infile_1(path+fileinfo.name); 
			while(infile_1>>str_1)
				{
					int str_length=str_1.size();
					if((str_1[str_length-1]<='z'&&str_1[str_length-1]>='a')||(str_1[str_length-1]=='\''))
						{
			
						}
					else
						{
							string substring=str_1.substr(0,str_length-1);
							str_1=substring;
						}
				//判断单词最后一位是标点时，生成子字符串去掉标点
					if(word_except.count(str_1))
						{
							count++;
							continue;
							//当单词出现在排除单词列表中时跳过当前单词的循环，不使用该单词
						}
					index[fileinfo.name][str_1].push_back(count);						
				count++;
				}
		}  
	_findclose(handle);   
	//关闭句柄     

	return 0;  
}