#include <cmath>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void transf()
{
	    cout<<"�������ַ���"<<endl;
		char a;
	    cin>>a;
	    int b10;
	    b10=int(a);
	    cout<<a<<"��ASCLL��ֵΪ"<<b10<<endl;
	int sz[8];
	int i,j;
	 j=b10;
	for (int m = 0; m <= 7; m++)                    
    {
        i = j % 2;                             
        j = j / 2;                                                               
        sz[7-m]=i;                               
    }
    cout<<"ת��Ϊ������Ϊ";
    for (int m = 0; m <= 7; m++)
    {
        cout<<sz[m];
	}
	cout<<endl;
	char hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	j = b10;
	i = j % 16;                             
    j = j / 16; 
	cout<<"ת��Ϊʮ������Ϊ"<<j<<hex[i]<<endl;
	
}
void Ten()
{
	    cout<<"��������λʮ����ASCLL��ֵ��"<<endl;
		int a;
	    cin>>a;
	    char t;
	    t=char(a);
	    cout<<a<<"��ʮ������Ϊ"<<t<<endl;
}
void Two()
{
	//����������ת��Ϊʮ���ƣ���ת��Ϊascll��
	    cout<<"�������λ������ASCLL��ֵ��"<<endl;
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
		cout<<"ת��Ϊ�ַ�����"<<char(sum)<<"��"<<endl;			    
}
void Six()
{
	    cout<<"��������λʮ������ASCLL��ֵ��"<<endl;
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
				//cout<<"��ʱsi="<<s[i]<<endl;
				sum1=sum1+s[i]+10-'0';
				//cout<<"��ʱsum1="<<sum1<<endl;
			}
			else
			{
				sum2=sum2+int(s[i])-'0';
				//cout<<"������sum="<<sum2<<endl;
				//mult=mult*16;
			}
        }
		sum=sum2*16+sum1;
		//cout<<"ת��Ϊʮ����Ϊ����"<<sum<<"��"<<endl;
		cout<<"ת��Ϊ�ַ�Ϊ����"<<char(sum)<<"��"<<endl;
}
int main()
{
	cout<<"��ѡ����Ҫ���еĳ����ţ�"<<endl;
	cout<<"1�����ַ�ת��ΪASCLL��"<<endl;
	cout<<"2����ASCLL��ת��Ϊ����"<<endl;
	cout<<"3�����ļ�����"<<endl;
	int choice;
	cin>>choice;
	if(choice==1)
	{		
	    transf();
	}
	else if(choice==2)
	{
		cout<<"��ѡ����Ҫ�����ASCLL�������"<<endl;
		cout<<"1��ʮ����"<<endl;
		cout<<"2��������"<<endl;
		cout<<"3��ʮ������"<<endl;
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
			cout<<"��������"<<endl;
		}
	}
	else if(choice==3)
	{
		ofstream outfile;//�洢���ļ�
           
	  FILE *fp;
	 // FILE *fp1;
	  if(NULL ==(fp = fopen("E:\\test.txt","r")))
	  {
		  cout<<"error"<<endl;
		  exit(1);
	  }
	  //fp1=fopen("E:\\out.txt","a+");//�½��ļ�����
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
