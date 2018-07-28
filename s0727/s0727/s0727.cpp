// s0727.cpp : 定义控制台应用程序的入口点。
//二叉树：已知中序和先序，求后序遍历的小程序

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdafx.h"

void root(char *mid, char *lst)
{
	char a, *p, *q;

	if (!*mid)
		return;
	p = lst + strlen(lst) - 1;
	printf("%c", *p);

	q = strchr(mid, *p);
	*p = 0x00;
	p = q - mid + lst;
	a = *p;
	*p = 0x00;
	*q = 0x00;

	root(mid, lst);
	*p = a;
	root(q + 1, p);
}


int main()
{
	char mid[] = "BADC";
	char lst[] = "BDCA";

	root(mid, lst);
	printf("\n");

	return 0;
}

