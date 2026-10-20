#include <iostream>
#include <stdexcept>
#include "book.h"
#include "rarebook.h"

int main() {
    setlocale(LC_ALL, "Russian");
    try
    {
        Book book("Война и мир", "Лев Толстой", 1869, 1225);
        RareBook rare_book("Редкое издание Мастера и Маргариты", "Михаил Булгаков", 1967, 480, 15000.0);


        cout << "=== Описание обычной книги ===\n";
        cout << book.description() << '\n';

        cout << "\n=== Данные редкой книги ===\n";

        cout << "Название: " << rare_book.title() << '\n';
        cout << "Автор: " << rare_book.author() << '\n';
        cout << "Год: " << rare_book.year() << '\n';
        cout << "Количество страниц: " << rare_book.pages() << '\n';


        cout << "\n=== Доступность редкой книги ===\n";
        rare_book.checkout();
        cout << "После выдачи: " << (rare_book.isAvailable() ? "доступна" : "выдана") << '\n';

        rare_book.returnBook();
        cout << "После возврата: " << (rare_book.isAvailable() ? "доступна" : "выдана") << '\n';


        cout << "\n=== Описание редкой книги ===\n";
        cout << rare_book.description() << '\n';


        cout << "\n=== Скидка ===\n";

        cout << "Начальная стоимость: " << rare_book.estimatedValue() << " руб.\n";

        rare_book.applyDiscount(10.0);

        cout << "После скидки 10%: " << rare_book.estimatedValue() << " руб.\n";

        cout << "Обновлённое описание:\n";
        cout << rare_book.description() << '\n';


        cout << "\n=== Проверка ошибки ===\n";
        try
        {
            rare_book.applyDiscount(150.0);
        }
        catch (const invalid_argument& e)
        {
            cout << "Ошибка при применении скидки: " << e.what() << '\n';
        }
    }
    catch (const invalid_argument& e)
    {
        cout << "Ошибка создания книги: " << e.what() << '\n';
    }
    return 0;
}