#include <cmath>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void transf()
{
	    cout<<"请输入字符："<<endl;
		char a;
	    cin>>a;
	    int b10;
	    b10=int(a);
	    cout<<a<<"的ASCLL码值为"<<b10<<endl;
	int sz[8];
	int i,j;
	 j=b10;
	for (int m = 0; m <= 7; m++)                    
    {
        i = j % 2;                             
        j = j / 2;                                                               
        sz[7-m]=i;                               
    }
    cout<<"转换为二进制为";
    for (int m = 0; m <= 7; m++)
    {
        cout<<sz[m];
	}
	cout<<endl;
	char hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	j = b10;
	i = j % 16;                             
    j = j / 16; 
	cout<<"转换为十六进制为"<<j<<hex[i]<<endl;
	
}
void Ten()
{
	    cout<<"请输入三位十进制ASCLL码值："<<endl;
		int a;
	    cin>>a;
	    char t;
	    t=char(a);
	    cout<<a<<"的十进制数为"<<t<<endl;
}
void Two()
{
	//将二进制先转换为十进制，后转换为ascll码
	    cout<<"请输入八位二进制ASCLL码值："<<endl;
		char q[8];
		int i,sum,mult;
		sum=0;
		mult=2;
		for( i=0;i<8;i++)
		{
		cin>>q[i];
		}
	    for( i=7;i>=0;i--)
		{
			//cout<<(int(q[i])-48)*mult/2<<endl;
		    sum=(int(q[i])-48)*mult/2+sum;
		    mult=mult*2;
		}
		cout<<"转变为字符：“"<<char(sum)<<"”"<<endl;			    
}
void Six()
{
	    cout<<"请输入两位十六进制ASCLL码值："<<endl;
		char s[2];
		cin>>s[0];
		cin>>s[1];
		int sum2=0;
		int sum1=0;
		int sum=0;
		//int mult=16;
		for(int i=0;i<2;i++){
			if(s[i]>='A' && s[i]<='Z')
			{
				s[i]=int(s[i]-'A'+'0');
				//cout<<"此时si="<<s[i]<<endl;
				sum1=sum1+s[i]+10-'0';
				//cout<<"此时sum1="<<sum1<<endl;
			}
			else
			{
				sum2=sum2+int(s[i])-'0';
				//cout<<"数字里sum="<<sum2<<endl;
				//mult=mult*16;
			}
        }
		sum=sum2*16+sum1;
		//cout<<"转变为十进制为：“"<<sum<<"”"<<endl;
		cout<<"转变为字符为：“"<<char(sum)<<"”"<<endl;
}
int main()
{
	cout<<"请选择所要运行的程序编号："<<endl;
	cout<<"1、将字符转换为ASCLL码"<<endl;
	cout<<"2、将ASCLL码转换为符号"<<endl;
	cout<<"3、将文件导入"<<endl;
	int choice;
	cin>>choice;
	if(choice==1)
	{		
	    transf();
	}
	else if(choice==2)
	{
		cout<<"请选择您要输入的ASCLL码进制数"<<endl;
		cout<<"1、十进制"<<endl;
		cout<<"2、二进制"<<endl;
		cout<<"3、十六进制"<<endl;
		int jin;
		cin>>jin;
		if(jin==1)
		{
		   Ten();
		}
		else if(jin==2)
		{
		   Two();
		}
	    else if(jin==3)
		{
		   Six();
		}
		else
		{
			cout<<"输入有误！"<<endl;
		}
	}
	else if(choice==3)
	{
		ofstream outfile;//存储的文件
           
	  FILE *fp;
	 // FILE *fp1;
	  if(NULL ==(fp = fopen("E:\\test.txt","r")))
	  {
		  cout<<"error"<<endl;
		  exit(1);
	  }
	  //fp1=fopen("E:\\out.txt","a+");//新建文件保存
	  outfile.open("E:\\out2.txt");
	  char ch;
	  while(EOF !=(ch=fgetc(fp)))
	  {
		  //fputc(int(ch),fp1);
		  outfile<<int(ch)<<endl;
	      //cout<<int(ch)<<endl;
	  }
	  fclose(fp);
	 // fclose(fp1);
	  outfile.close(); 
	}

	return 0;
}
