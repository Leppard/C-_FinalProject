//1252964     ������       Inverted_Index.cpp



#include "Inverted_Index.h"


Inverted_Index::Inverted_Index(void)
{
}
Inverted_Index::~Inverted_Index(void)
{
}

int Inverted_Index::make_index()
{	
   	//������������Ŀ¼	
	string path;
	string Dir_path;
	while(true)								//�����ļ���λ�ã�������������������
	{
	cout<<"������������ļ���λ�ã�"<<endl;
	cout<<"��ʾ������C���ļ��С�name����C��\\name\\��"<<endl;
	cin>>path;
	Dir_path=path+"*.txt";
	long handle;                          
	//���ڲ��ҵľ��  
	struct _finddata_t fileinfo;               
	//�ļ���Ϣ�Ľṹ�� 
	handle=_findfirst(Dir_path.c_str(),&fileinfo);      
	//��һ�β��� 
	if(-1==handle)
	{cout<<"�ļ���λ����������·�����ʽ�������룡"<<endl<<endl;
	continue;}
	else
		break;
	}
	long handle;                          
	//���ڲ��ҵľ��  
	struct _finddata_t fileinfo;               
	//�ļ���Ϣ�Ľṹ�� 
	handle=_findfirst(Dir_path.c_str(),&fileinfo);      
	//��һ�β��� 
	index[fileinfo.name]; 

	ifstream infile_1(path+fileinfo.name); 
	if(!infile_1)cout<<"error"<<endl;
	//�򿪴��ļ�
	string except_word;	
	cout<<"������Ҫ�ų������б���ļ�λ�ã�"<<endl;
	cout<<"(����Ҫ�ų�����ֱ�ӡ�!����س���������"<<endl;
	cin>>except_word;
	ifstream infile_2;
	infile_2.open(except_word.c_str());
	while(!infile_2)
	{
		if(except_word=="!")
			break;
		cout<<"�Ҳ����ų������б��ļ�λ�ã�������������룡"<<endl;
		cin>>except_word;
		infile_2.open(except_word.c_str());
	} 
	string str_1,str_2;
	set<string> word_except;
		{
			word_except.insert(str_2);
		//������Ҫ�ų��ĵ��ʺͱ��	
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
		//�жϵ������һλ�Ǳ��ʱ���������ַ���ȥ�����
			if(word_except.count(str_1))
				{
					count++;
					continue;
					//�����ʳ������ų������б���ʱ������ǰ���ʵ�ѭ������ʹ�øõ���
				}
			index[fileinfo.name][str_1].push_back(count);			
		count++;
		//count���ڼ��㵥���ڸ��ļ�������λ��
		}
	
	while(!_findnext(handle,&fileinfo)) 
		//ѭ�������������ϵ��ļ���ֱ���Ҳ���������Ϊֹ
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
				//�жϵ������һλ�Ǳ��ʱ���������ַ���ȥ�����
					if(word_except.count(str_1))
						{
							count++;
							continue;
							//�����ʳ������ų������б���ʱ������ǰ���ʵ�ѭ������ʹ�øõ���
						}
					index[fileinfo.name][str_1].push_back(count);						
				count++;
				}
		}  
	_findclose(handle);   
	//�رվ��     

	return 0;  
}