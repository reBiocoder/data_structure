// s0720.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
void  scanf_test()
{
/*对scanf函数进行讨论：
①scanf函数会读取最后的换行符，也就是说在循环时，换行符会被读取进去，可以看见，当我输入了一个数字之后
并没有输入字符，程序便会退出，原因就是这里换行符充当了字符输入，消除的方式时使用getchar（）*/	
	/*int  num;
	int  a = 0;
	char ch = ' ';
	scanf("%d",&num);
    scanf("%c",&ch);
	//getchar();
	//ch = getchar();
	printf("%c", ch);
	printf("666");*/
/*②数组名是数组首元素的地址，可以看作是一个指针，若数组名为p，则*p=p[0]; 
而&p则表示的是整个数组的地址，按照树上的话来说就是，取一个数组名
的地址所产生的是一个指向数组的指针，而不是一个指向某个指针常量值的指针
*/

}
void  fgets_test()
{
/*fgets与fputs的理解：
fgets(*str,int i,*stream)实际上就是从一个文件中读取i个字符，并将这些字符存入到数组中，
fputs(*str,FILE,*stream)表示的是将一串字符写入到某个文件中
①\0：表示字符结束符；②EOF:文件结束符，其ASCii值是-1*/					
	char a[100];
	fgets(a,100,stdin);//stdin是标准输入流，也就是说这里的文件就是从键盘上输入的字符
	a[strlen(a)-1]='\0';
	printf("%s",a);//最后输出可见，有一个换行，原因是fgets能保留换行，去掉末尾换行的方法是a[strlen(a)-1]='\0';

}
/*void  getchar_test()
{getchar函数已经很熟悉了，我们只需要注意，从键盘上输入的字符先是存储在缓存区，然后才会被变量识别
 ，注意scanf函数它是能存储换行符的，它不能存储空格或者空白格，遇到空格或者空白格它会直接理解为
 第一个变量已经结束
}*/
int main()
{
	//scanf_test();
	fgets_test();
	return  0;
	
}

