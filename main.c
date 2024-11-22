#include <stdio.h>

enum ShapeType { TRIANGLE, RECTANGLE, CIRCLE };

struct Triangle { int base, height; };
struct Rectangle { int width, height; };
struct Circle { int radius; };

union ShapeData {
    struct Triangle triangle;
    struct Rectangle rectangle;
    struct Circle circle;
};

struct Shape {
    enum ShapeType type;
    union ShapeData data;
};

double calculate_area(struct Shape shape) {
    switch (shape.type) {
    case TRIANGLE:
        return 0.5 * shape.data.triangle.base * shape.data.triangle.height;
    case RECTANGLE:
        return shape.data.rectangle.width * shape.data.rectangle.height;
    case CIRCLE:
        return 3.14159 * shape.data.circle.radius * shape.data.circle.radius;
    default:
        return 0;
    }
}

int main() {
    struct Shape shape;

    printf("도형의 타입을 입력하시오 (0: 삼각형, 1: 사각형, 2: 원): ");
    scanf("%d", &shape.type);

    switch (shape.type) {
    case TRIANGLE:
        printf("삼각형의 밑변과 높이를 입력하시오 (예: 100,100): ");
        scanf("%d,%d", &shape.data.triangle.base, &shape.data.triangle.height);
        break;
    case RECTANGLE:
        printf("사각형의 가로 및 세로 너비를 입력하시오 (예: 100,100): ");
        scanf("%d,%d", &shape.data.rectangle.width, &shape.data.rectangle.height);
        break;
    case CIRCLE:
        printf("원의 반지름을 입력해주세요: ");
        scanf("%d", &shape.data.circle.radius);
        break;
    default:
        printf("유효하지 않은 도형 타입 입력입니다. 종료합니다.\n");
        return 1;
    }

    printf("면적은: %.2f\n", calculate_area(shape));
    return 0;
}