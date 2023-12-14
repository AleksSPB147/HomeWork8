#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
int task1();
int task2();
int task3();
int task4();
int task5();
int task6();


int main()
{
	setlocale(LC_ALL, "RU");
	//task1();
	//task2();
	//task3();
	//task4();
	//task5();
	task6();


}

/*
1.  Откройте файл “XXXX.txt”, считайте данные из файла(целое число),
возведите считанное значение во 2 степень и выведите на экран.
*/
int task1()

{
	FILE* input = NULL;                // Создаем переменную для работы с потоком файлов
	int y;                             // Создаем переменную для записи в неё числа из файла

	input = fopen("task1.txt", "r");   // Получаем указатель на файловый поток с файлом по адресу task1.txt и индификатором доступа "r" 
	if (input == NULL)                 // Проверяем что файл открылся  и  правильно
	{
		printf("Error opening file");  // Если файл не открылся, выводим сообщение об ошибке открытия файла
		exit(0);
	}
	fscanf(input, "%d", &y);           // Считываем из файла число
	y *= y;                            // Возводим в степень
	fclose(input);                     // Закрываем файл
	printf("%d\n", y);                 // Выводим на экран
	return 0;
}





//2.  В файл записаны целые числа, по одному числу в строке.
// Считайте из файла “f1.txt” построчно все данные.Выведите на экран сумму считанных чисел.
int task2()
{
	FILE* input = NULL;
	int c, sum = 0;
	input = fopen("task2.txt", "r");
	if (input == NULL)
	{
		printf("Error opening file");
		exit(0);
	}
	while (fscanf(input, "%d", &c) == 1)
	{
		sum += c;
	}
	fclose(input);
	printf("%d", sum);
	return 0;

}
//3.  В файл записаны целые числа, по одному числу в строке.
// Считайте из файла “f1.txt” построчно все данные.
// Удвойте значение каждого считанного значения и запишите в файл “f2.txt”.

int task3()
{
	FILE* input = NULL;
	FILE* output = NULL;
	int c;
	input = fopen("task3.txt", "r");
	output = fopen("task3.1.txt", "w");
	if (input == NULL)
	{
		printf("Error opening file");
		exit(0);
	}
	while (fscanf(input, "%d", &c)==1)
	{
		c *= 2;
		fprintf(output, "%dn\n", c);
		printf("%d\n", c);
	}
	fclose(input);
	fclose(output);
	
	return 0;
}

//4.  В файле “f1.txt” записан текст.
// Считать текст, определить сколько раз в считанном тексте встречается символ “s”, вывести значение на экран.


int task4()
{
	FILE* input = NULL;
	int count = 0;
	int c;
	input = fopen("task4.txt", "r");
	if (input == NULL)
	{
		printf("Error opening file");
		exit(0);
	}
	do
	{
		c = fgetc(input);   //Функция fgets считывает символы из потока и сохраняет их в виде строки в параметр string 
		if(c == 's')        //до тех пор пока не наступит конец строки или пока не будет достигнут конец файла.
		{
			count++;
		}
	} while (c != EOF);
	fclose(input);
	printf("%d", count);
	return 0;
}


//5.  Дан файл “f.txt”.Создать два файла “f1.txt” и “f2.txt”,
// записав в первый из них все четные числа, а во второй – все нечетные(каждое число в отдельной строке).

int task5()
{
	FILE* input = NULL;
	FILE* output1 = NULL;
	FILE* output2 = NULL;
	int c;
	input = fopen("task5.txt", "r");
	output1 = fopen("task5.1.txt", "w");
	output2 = fopen("task5.2.txt", "w");
	if (input == NULL)
	{
		printf("Error opening file");
		exit(0);
	}
	while (fscanf(input, "%d", &c) == 1)
	{
		if (c % 2 == 0)
		{
			fprintf(output1, "%d\n", c);      // Записываем четные числа в файл task5.1
			//printf("Четные  %d\n", c);      // Для наглядности сразу вывести на экран
			
		}
		else
			
		{
			fprintf(output2, "%d\n", c);      // Записываем не четные числа в файл task5.1
			//printf("Не четные %d\n", c);    // Для наглядности сразу вывести на экран
		}
		
	}
	fclose(input);
	fclose(output1);
	fclose(output2); 
	
	return 0;
}



//6.  В файле “f.txt” записан текст.
// Перезаписать текст в файл “f1.txt”разделяя на строки, переходить на новую строку после каждого символа “s”.
int task6()

{
	FILE* input = NULL;
	FILE* output = NULL;
	int c;
	input = fopen("task6.txt", "r");
	output = fopen("task6.1.txt", "w");
	if (input == NULL)
	{
		printf("Error opening file");
		exit(0);
	}
	do
	{
		c = fgetc(input);
		fprintf(output, "%c", c);
		if (c == 's')
		{
			fprintf(output, "\n");
			printf("%c\n", c);
		}
	} while (c != EOF);
	fclose(input);
	fclose(output);
	return 0;
}






































//
//1.  Откройте файл “f1.txt”, считайте данные из файла(целое число), 
// возведите считанное значение во 2 степень и выведите на экран.
// 
//2.  В файл записаны целые числа, по одному числу в строке.
// Считайте из файла “f1.txt” построчно все данные.Выведите на экран сумму считанных чисел.
// 
//3.  В файл записаны целые числа, по одному числу в строке.
// Считайте из файла “f1.txt” построчно все данные.
// Удвойте значение каждого считанного значения и запишите в файл “f2.txt”.
// 
//4.  В файле “f1.txt” записан текст.
// Считать текст, определить сколько раз в считанном тексте встречается символ “s”, вывести значение на экран.
// 
//5.  Дан файл “f.txt”.Создать два файла “f1.txt” и “f2.txt”, 
// записав в первый из них все четные числа, а во второй – все нечетные(каждое число в отдельной строке).
// 
//6.  В файле “f.txt” записан текст.
// Перезаписать текст в файл “f1.txt”разделяя на строки, переходить на новую строку после каждого символа “s”.
//

//Функция fgets считывает символы из потока и сохраняет их в виде строки в параметр string до тех пор пока не наступит конец строки или пока не будет достигнут конец файла.
//
//Символ новой строки прекращает работу функции fgets, но он считается допустимым символом, и поэтому он копируется в строку string.
//
//Нулевой символ автоматически добавляется в строку str после прочитанных символов, чтобы сигнализировать о конце строки.