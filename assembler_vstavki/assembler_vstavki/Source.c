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
	printf_s("Сложение ассемблер\n");
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Subtraction_As(a, b);
	}
	printf_s("Вычитание ассемблер\n");
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Multiplication_As(a, b);
	}
	printf_s("Умножение ассемблер\n");
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Division_As(a, b);
	}
	printf_s("Дивизион ассемблер\n");
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Remains_AS(a, b);
	}
	printf_s("Остаток ассемблер\n");
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Comparison_AS(a, b);
	}
	printf_s("Сравнение ассемблер\n");
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		ComparisonsOf3Numbers_AS(a, b, c);
	}
	printf_s("Сравнение 3 чисел ассемблер\n");
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Change_As(a, b);
	}
	printf_s("Смена чисел ассемблер\n");
	printf_s("Время выполнения %d\n\n", clock());

	for (size_t i = 0; i < f; i++)
	{
		Addition(a, b);
	}
	printf_s("Сложение С\n");
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Subtraction(a, b);
	}
	printf_s("Вычитание С\n");
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Multiplication(a, b);
	}
	printf_s("Умножение С\n");
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Division(a, b);
	}
	printf_s("Деление С\n");
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Remains(a, b);
	}
	printf_s("Остатки С\n");
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		Comparison(a, b);
	}
	printf_s("Сравнение С\n");
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		ComparisonOf3Numbers(a, b, c);
	}
	printf_s("Сравнение 3 чисел С\n");
	printf_s("Время выполнения %d\n", clock());
	for (size_t i = 0; i < f; i++)
	{
		ChangingNumbers(a, b);
	}
	printf_s("Смена чисел С\n");
	printf_s("Время выполнения %d\n", clock());
	return 0;
}

//Сложение ассемблер
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

//Вычитание ассемблер
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

//Умножение ассемблер
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

//Деление ассемблер
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

//Остаток ассемблер
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

//Сравнение ассемблер
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

//Сравнение 3 чисел ассемблер
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

//Смена двух элементов ассемблер
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

//Сложение
int Addition(int a, int b)
{
	return a + b;
}

//Вычитание
int Subtraction(int a, int b)
{
	return a - b;
}

//Умножение
int Multiplication(int a, int b)
{
	return a * b;
}

//Деление
int Division(int a, int b)
{
	return a / b;
}

//Функция для нахождения остатка от деления двух целых чисел
int Remains(int a, int b)
{
	int pr = a / b;
	return a - pr * b;
}

//Функция для сравнения двух целых чисел
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

//Функция для сравнения трех целых чисел
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

//Функция, которая меняет два элемента местами
int ChangingNumbers(int a, int b)
{
	int a1 = a;
	int b1 = b;
	a = b1;
	b = a1;
	//printf_s("a = %d, b = %d\n", a, b);
}