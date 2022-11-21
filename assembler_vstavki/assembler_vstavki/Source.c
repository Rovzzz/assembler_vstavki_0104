#include <stdio.h>
#include <locale.h>
#include <time.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	int a = 15;
	int b = 10;
	int c = 5;
	int f = 1000000000;
	for (size_t i = 0; i < f; i++)
	{
		Addition_As(a, b);
	}
	printf_s("�������� ���������\n");
	printf_s("����� ���������� %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Subtraction_As(a, b);
	}
	printf_s("��������� ���������\n");
	printf_s("����� ���������� %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Multiplication_As(a, b);
	}
	printf_s("��������� ���������\n");
	printf_s("����� ���������� %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Division_As(a, b);
	}
	printf_s("�������� ���������\n");
	printf_s("����� ���������� %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Remains_AS(a, b);
	}
	printf_s("������� ���������\n");
	printf_s("����� ���������� %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Comparison_AS(a, b);
	}
	printf_s("��������� ���������\n");
	printf_s("����� ���������� %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		ComparisonsOf3Numbers_AS(a, b, c);
	}
	printf_s("��������� 3 ����� ���������\n");
	printf_s("����� ���������� %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Change_As(a, b);
	}
	printf_s("����� ����� ���������\n");
	printf_s("����� ���������� %d\n\n", clock());

	for (size_t i = 0; i < f; i++)
	{
		Addition(a, b);
	}
	printf_s("�������� �\n");
	printf_s("����� ���������� %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Subtraction(a, b);
	}
	printf_s("��������� �\n");
	printf_s("����� ���������� %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Multiplication(a, b);
	}
	printf_s("��������� �\n");
	printf_s("����� ���������� %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Division(a, b);
	}
	printf_s("������� �\n");
	printf_s("����� ���������� %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Remains(a, b);
	}
	printf_s("������� �\n");
	printf_s("����� ���������� %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Comparison(a, b);
	}
	printf_s("��������� �\n");
	printf_s("����� ���������� %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		ComparisonOf3Numbers(a, b, c);
	}
	printf_s("��������� 3 ����� �\n");
	printf_s("����� ���������� %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		ChangingNumbers(a, b);
	}
	printf_s("����� ����� �\n");
	printf_s("����� ���������� %d\n", clock());
	return 0;
}

//�������� ���������
int Addition_As(int a, int b)
{
	int c;
	__asm
	{
		mov eax, a
		mov ebx, b
		add eax, ebx
		mov c, eax
	}
	return c;
}

//��������� ���������
int Subtraction_As(int a, int b)
{
	int c;
	__asm
	{
		mov eax, a
		mov ebx, b
		sub eax, ebx
		mov c, eax
	}
	return c;
}

//��������� ���������
int Multiplication_As(int a, int b)
{
	int c;
	__asm
	{
		mov eax, a
		mov ebx, b
		imul eax, ebx
		mov c, eax
	}
	return c;
}

//������� ���������
int Division_As(int a, int b)
{
	int c;
	__asm
	{
		mov eax, a
		mov ebx, b
		xor edx, edx
		idiv ebx
		mov c, eax
	}
	return c;
}

//������� ���������
int Remains_AS(int a, int b)
{
	int c;
	__asm
	{
		mov eax, a
		mov ebx, b
		xor edx, edx
		idiv ebx
		mov c, eax
		imul eax, ebx
		mov ebx, a
		sub ebx, eax
		mov c, ebx
	}
	return c;
}

//��������� ���������
int Comparison_AS(int a, int b)
{
	int c;
	__asm
	{
		mov eax, a
		mov ebx, b
		cmp eax, ebx;
		je equal
			jg greater
			jmp less
			equal :
		mov c, 0
			jmp exit
			greater :
		mov c, 1
			jmp exit
			less :
		mov c, 2
			jmp exit
			exit :
	}
	return c;
}

//��������� 3 ����� ���������
int ComparisonsOf3Numbers_AS(int a, int b, int c)
{
	_asm
	{
		mov eax, a
		mov ebx, b
		mov ecx, c
		cmp eax, ebx
		je equal
		jg greater
		jmp less


		equal :
		cmp eax, ecx
			je equal2
			jg greater2
			jmp less2

			greater :
		cmp eax, ecx
			je equal2
			jg greater2
			jmp less2

			less :
		cmp ebx, ecx
			je equal2
			jg greater3
			jmp less2

			equal2 :

		mov a, 0
			jmp exit

			greater2 :
		mov a, 1
			jmp exit

			less2 :
		mov a, 3
			jmp exit

			greater3 :
		mov a, 2
			jmp exit

			exit :
	}
	return a;
}

//����� ���� ��������� ���������
int Change_As(int a, int b)
{
	int c;
	__asm
	{
		mov eax, a
		mov ebx, b

		mov ecx, eax
		mov eax, ebx
		mov ebx, ecx

		mov a, eax
		mov b, ebx

	}
	//printf_s("a = %d, b = %d\n", a, b);
}

//��������
int Addition(int a, int b)
{
	return a + b;
}

//���������
int Subtraction(int a, int b)
{
	return a - b;
}

//���������
int Multiplication(int a, int b)
{
	return a * b;
}

//�������
int Division(int a, int b)
{
	return a / b;
}

//������� ��� ���������� ������� �� ������� ���� ����� �����
int Remains(int a, int b)
{
	int pr = a / b;
	return a - pr * b;
}

//������� ��� ��������� ���� ����� �����
int Comparison(int a, int b)
{
	if (a > b)
	{
		return 1;
	}
	else if (a < b)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

//������� ��� ��������� ���� ����� �����
int ComparisonOf3Numbers(int a, int b, int c)
{
	if (a > b && a > c)
	{
		return 1;
	}
	else if (b > a && b > c)
	{
		return 2;
	}
	else if (c > a && c > b)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

//�������, ������� ������ ��� �������� �������
int ChangingNumbers(int a, int b)
{
	int a1 = a;
	int b1 = b;
	a = b1;
	b = a1;
	//printf_s("a = %d, b = %d\n", a, b);
}