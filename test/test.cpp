#include <gtest/gtest.h>
#include "../include/geometry.hpp"
#include <sstream>

// Тестирование функции TakeCoordinates
TEST(GeometryTest, TestTakeCoordinates) {
    // Подготовка тестовых данных
    std::vector<Point> points(4);
    int numPoints = 4;

    // Заменяем поток ввода для тестирования
    std::stringstream input_data("1 2\n3 4\n5 6\n7 8\n");
    std::streambuf* orig_cin = std::cin.rdbuf(); // Сохраняем оригинальный поток cin
    std::cin.rdbuf(input_data.rdbuf()); // Заменяем cin на наш поток

    // Вызов функции для тестирования
    TakeCoordinates(points, numPoints);

    // Проверки на основе ожидаемых результатов
    ASSERT_EQ(points.size(), 4); // Проверка размера вектора
    ASSERT_FLOAT_EQ(points[0].x, 1.0f); // Проверка координат точки A
    ASSERT_FLOAT_EQ(points[0].y, 2.0f);
    ASSERT_FLOAT_EQ(points[1].x, 3.0f); // Проверка координат точки B
    ASSERT_FLOAT_EQ(points[1].y, 4.0f);
    ASSERT_FLOAT_EQ(points[2].x, 5.0f); // Проверка координат точки C
    ASSERT_FLOAT_EQ(points[2].y, 6.0f);
    ASSERT_FLOAT_EQ(points[3].x, 7.0f); // Проверка координат точки D
    ASSERT_FLOAT_EQ(points[3].y, 8.0f);

    // Восстанавливаем оригинальный поток cin
    std::cin.rdbuf(orig_cin);
}

// Тестирование функции Calculate
TEST(GeometryTest, TestCalculate) {
    // Подготовка тестовых данных
    std::vector<Point> points(4);
    float AB, BC, CA, AD, BD, CD;

    // Заполнение точек данными для теста
    points[0].x = 0.0f;
    points[0].y = 0.0f;
    points[1].x = 1.0f;
    points[1].y = 0.0f;
    points[2].x = 0.0f;
    points[2].y = 1.0f;
    points[3].x = 1.0f;
    points[3].y = 1.0f;

    // Вызов функции для тестирования
    Calculate(points, AB, BC, CA, AD, BD, CD);

    // Проверки на основе ожидаемых результатов
    // Добавьте здесь проверки, ожидаемых результатов функции Calculate
}

