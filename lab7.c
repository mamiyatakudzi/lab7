#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

void check_character(char c);
float calculate(float x, char op, float y, int* error);
int get_zodiac(int day, int month);

int main(void)
{
    setlocale(LC_ALL, ".UTF-8");
    int choice;
    printf("Выберите задание (1, 2, 3): ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
        char symbol;
        printf("Введите символ: ");
        scanf(" %c", &symbol);

        check_character(symbol);
        break;
    }
    case 2:
    {
        float num1, num2, res;
        char op;
        int calc_error = 0;

        printf("Введите выражение: ");
        scanf("%f %c %f", &num1, &op, &num2);

        res = calculate(num1, op, num2, &calc_error);

        switch (calc_error)
        {
        case 1:
            printf("Ошибка: деление на ноль!\n");
            break;
        case 2:
            printf("Ошибка: неизвестная операция!\n");
            break;
        case 0:
            printf("=%f\n", res);
            break;
        }
        break;
    }
    case 3:
    {
        int ddmm, day, month, zodiac_code;

        printf("Введите дату в формате ddmm: ");
        scanf("%d", &ddmm);

        day = ddmm / 100;
        month = ddmm % 100;

        zodiac_code = get_zodiac(day, month);

        switch (zodiac_code)
        {
        case 1: printf("Козерог\n"); break;
        case 2: printf("Водолей\n"); break;
        case 3: printf("Рыбы\n"); break;
        case 4: printf("Овен\n"); break;
        case 5: printf("Телец\n"); break;
        case 6: printf("Близнецы\n"); break;
        case 7: printf("Рак\n"); break;
        case 8: printf("Лев\n"); break;
        case 9: printf("Дева\n"); break;
        case 10: printf("Весы\n"); break;
        case 11: printf("Скорпион\n"); break;
        case 12: printf("Стрелец\n"); break;
        default: printf("Неверно введён месяц\n"); break;
        }
        break;
    }
    default:
        printf("Неверный номер задания!\n");
        break;
    }

    return 0;
}

void check_character(char c)
{
    switch (c)
    {
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        printf("это цифра\n");
        break;
    case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g':
    case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n':
    case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u':
    case 'v': case 'w': case 'x': case 'y': case 'z':
    case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G':
    case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N':
    case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U':
    case 'V': case 'W': case 'X': case 'Y': case 'Z':
        printf("это буква\n");
        break;
    default:
        printf("это прочий символ\n");
        break;
    }
}

float calculate(float x, char op, float y, int* error)
{
    float result = 0.0f;
    int is_zero;

    switch (op)
    {
    case '+':
        result = x + y;
        break;
    case '-':
        result = x - y;
        break;
    case '*':
        result = x * y;
        break;
    case '/':
        is_zero = (y == 0.0f);
        switch (is_zero)
        {
        case 1:
            *error = 1;
            break;
        case 0:
            result = x / y;
            break;
        }
        break;
    case '^':
        result = powf(x, y);
        break;
    default:
        *error = 2;
        break;
    }

    return result;
}

int get_zodiac(int day, int month)
{
    int is_after;
    int code = 0;

    switch (month)
    {
    case 1:
        is_after = (day >= 20);
        switch (is_after) {
        case 0: code = 1; break;
        case 1: code = 2; break;
        }
        break;
    case 2:
        is_after = (day >= 19);
        switch (is_after) {
        case 0: code = 2; break;
        case 1: code = 3; break;
        }
        break;
    case 3:
        is_after = (day >= 21);
        switch (is_after) {
        case 0: code = 3; break;
        case 1: code = 4; break;
        }
        break;
    case 4:
        is_after = (day >= 20);
        switch (is_after) {
        case 0: code = 4; break;
        case 1: code = 5; break;
        }
        break;
    case 5:
        is_after = (day >= 21);
        switch (is_after) {
        case 0: code = 5; break;
        case 1: code = 6; break;
        }
        break;
    case 6:
        is_after = (day >= 21);
        switch (is_after) {
        case 0: code = 6; break;
        case 1: code = 7; break;
        }
        break;
    case 7:
        is_after = (day >= 23);
        switch (is_after) {
        case 0: code = 7; break;
        case 1: code = 8; break;
        }
        break;
    case 8:
        is_after = (day >= 23);
        switch (is_after) {
        case 0: code = 8; break;
        case 1: code = 9; break;
        }
        break;
    case 9:
        is_after = (day >= 23);
        switch (is_after) {
        case 0: code = 9; break;
        case 1: code = 10; break;
        }
        break;
    case 10:
        is_after = (day >= 23);
        switch (is_after) {
        case 0: code = 10; break;
        case 1: code = 11; break;
        }
        break;
    case 11:
        is_after = (day >= 22);
        switch (is_after) {
        case 0: code = 11; break;
        case 1: code = 12; break;
        }
        break;
    case 12:
        is_after = (day >= 22);
        switch (is_after) {
        case 0: code = 12; break;
        case 1: code = 1; break;
        }
        break;
    default:
        code = 0;
        break;
    }

    return code;
}
