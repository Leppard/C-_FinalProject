//1252964     李贞良       main.cpp



#include "Inverted_Index.h"
#include"search.h"

void help()
{
	cout<<"帮助文档："<<endl;
	cout<<"输入“-search”进入搜索功能后，首先输入所要查找的目标文件夹路径："<<endl;
cout<<"如：     C：\\NAME\\"<<endl;
cout<<"如果需要排除单词，则输入需排除单词的文档的位置："<<endl;
cout<<"如：     C：\\NAME\\name.txt"<<endl;
cout<<"如果不需排除，则根据提示直接输入“！”回车即进入单词查询。"<<endl;
cout<<"输入所需查询单词后回车，即可得到查询结果："<<endl;
cout<<"单词所在文件名        单词在文件中的位置"<<endl;
cout<<"-help得到帮助信息，-quit退出该程序。"<<endl;
cout<<"所使用输出输入文件（需要查找文件）格式：txt"<<endl<<endl<<endl;

}


int main()
{		
		cout<<"         ***********************************************************"<<endl;
		cout<<"		   欢迎使用李贞良独家信息检索系统！"<<endl;
		cout<<"		       至尊奢华，你值得拥有"<<endl;
		cout<<"         ***********************************************************"<<endl;
	while(true)                      //指示输入不同指令，如果不在列表内则循环重新输入
	{
		cout<<"请输入指令："<<endl<<"帮助文档：-help         查找功能：-search         退出程序：-quit"<<endl;
		string type;
		cin>>type;
		if(type!="-quit"&&type!="-search"&&type!="-help")
		{
		cout<<"!!对不起,找不到该指令，请检查后输入!！"<<endl<<endl<<endl;
		continue;		
		}
	switch (type[1])
		{
		case'h':{                               //-help
			help();
			continue;
			}
		case'q':{cout<<"感谢使用！走你！"<<endl;//-quit
					return -1;}
		case's':								//-search
			{
				Inverted_Index index;			//Inverted_Index类
				index.make_index();
				Search fin;						//Search类
				fin.searching(index);				
				cout<<endl<<endl;
				continue;
			}
		}	
	}
}