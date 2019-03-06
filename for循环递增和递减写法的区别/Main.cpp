// Main.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	for (int i = 20; i > 0; i--)
	{
		int j = 0;
		j++;
	}


	for (int k = 0 ; k < 20; k++)
	{
		int M = 0;
		M++;
	}
	return 0;
}


// 汇编如下：
int _tmain(int argc, _TCHAR* argv[])
{
00AC17F0  push        ebp  
00AC17F1  mov         ebp,esp  
00AC17F3  sub         esp,0F0h  
00AC17F9  push        ebx  
00AC17FA  push        esi  
00AC17FB  push        edi  
00AC17FC  lea         edi,[ebp-0F0h]  
00AC1802  mov         ecx,3Ch  
00AC1807  mov         eax,0CCCCCCCCh  
00AC180C  rep stos    dword ptr es:[edi]  
	for (int i = 20; i > 0; i--)
00AC180E  mov         dword ptr [i],14h  
00AC1815  jmp         wmain+30h (0AC1820h)  
00AC1817  mov         eax,dword ptr [i]  
00AC181A  sub         eax,1  
00AC181D  mov         dword ptr [i],eax  
00AC1820  cmp         dword ptr [i],0  
00AC1824  jle         wmain+48h (0AC1838h)  
	{
		int j = 0;
00AC1826  mov         dword ptr [j],0  
		j++;
00AC182D  mov         eax,dword ptr [j]  
00AC1830  add         eax,1  
00AC1833  mov         dword ptr [j],eax  
	}
00AC1836  jmp         wmain+27h (0AC1817h)  


	for (int k = 0 ; k < 20; k++)
00AC1838  mov         dword ptr [k],0  
00AC183F  jmp         wmain+5Ah (0AC184Ah)  
00AC1841  mov         eax,dword ptr [k]  
00AC1844  add         eax,1  
00AC1847  mov         dword ptr [k],eax  
00AC184A  cmp         dword ptr [k],14h  
00AC184E  jge         wmain+72h (0AC1862h)  
	{
		int M = 0;
00AC1850  mov         dword ptr [M],0  
		M++;
00AC1857  mov         eax,dword ptr [M]  
00AC185A  add         eax,1  
00AC185D  mov         dword ptr [M],eax  
	}
00AC1860  jmp         wmain+51h (0AC1841h)  
	return 0;
00AC1862  xor         eax,eax  
}


网上的结论：
i--操作本身会影响CPSR(当前程序状态寄存器)，CPSR常见的标志有N(结果为负), Z(结果为0)，C（有进位），O（有溢出）。i大于0，可以直接通过Z标志判断出来。
i++操作也会影响CPSR(当前程序状态寄存器)，但只影响O（有溢出）标志，这对于i < n的判断没有任何帮助。所以还需要一条额外的比较指令，也就是说每个循环要多执行一条指令。


从自己的实践来看，至少在VS2010上，没发现效率上的区别，指令也没多也没少。

说明：14h为十六进制
dword   双字 就是四个字节
ptr     pointer缩写 即指针
[]里的数据是一个地址值，这个地址指向一个双字型数据
比如mov eax, dword ptr [12345678]  把内存地址12345678中的双字型（32位）数据赋给eax



