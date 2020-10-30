#include <iostream>
#include <string>
#include <iomanip>

double absValue(double m) {
	if (m > 0) {
		return m;
	}
	else {
		return -m;
	}
}

void approximate(double accuracy, int numberMax, double x1, double x2, double interval) { // основная функция вычисления 
	double absError = 0.0;
	std::string message = "";
	double x;
	int i = 0;
	int b = 1;
	double y = 0;
	x = x1;
	double a = x;
	while (x < x2) {
		double nextValue = a / b;
		double xSquared = x * x;
		if ((x <= -1) || (x >= 1)) {
			message = "аргумент вышел за пределы функции";
			std::cout << x << "\t" << std::setw(10) << y << "\t" << i << "\t" << message << "\t \n";
			break;
		}
		while (absValue(nextValue) > absValue(accuracy)) {
			i++;
			if (i > numberMax) {
				message = "Достигнут лимит слагаемых N";
				i = numberMax;
				break;
			}
			y += nextValue;
			b += 2;
			a *= xSquared;
			nextValue = a / b;
		}
		if (absValue(nextValue) < absValue(accuracy)) {
			message = "Достигнут предел точности";
		}
		std::cout << x << " \t " << std::setw(10) << y << " \t " << i << " \t " << message << "\t \n" ;
		x += interval;
		b = 1;
		a = x;
		nextValue = a / b;
		y = 0;
		i = 0;
		message = "-";
	}
}


double validate(double) {
	double r;
	while (!(std::cin >> r)) {
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Введите число \n";
	}
	return r;
}

int validate(int) {
	int l;
	while (!(std::cin >> l)) {
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Введите число \n";
	}
	return l;
}

int main() {
	setlocale(LC_ALL, "rus");
	int ii = 0;
	double dd = 0.0;
	//
	double x1;
	std::cout << "Введите начальное значение x1 \n"; //ввод начального значения 
	x1 = validate(dd);
	while ((x1 <= -1) || (x1 >= 1)) {
		std::cout << "Начальное значение некорректно. Введите число из интервала (-1 ; 1) ";
		x1 = validate(dd);
	}
	//
	double x2;
	std::cout << "Введите конечное значение x2 \n"; //ввод конечного значения 
	x2 = validate(dd);
	while ((x2 <= -1) || (x2 >= 1)) {
		std::cout << "Конечное значение некорректно. Введите число из интервала (-1 ; 1) ";
		x2 = validate(dd);
	}
	//
	while (x1 >= x2) {
		std::cout << "Начальное значение не может быть больше или равно конечному. \n";
		std::cout << "Введите начальное значение x1 \n"; //ввод начального значения 
		x1 = validate(dd);
		while ((x1 <= -1) || (x1 >= 1)) {
			std::cout << "Начальное значение некорректно. Введите число из интервала (-1 ; 1) ";
			x1 = validate(dd);
		}
		std::cout << "Введите конечное значение x2 \n"; //ввод начального значения 
		x2 = validate(dd);
		while ((x2 <= -1) || (x2 >= 1)) {
			std::cout << "Конечное значение некорректно. Введите число из интервала (-1 ; 1) ";
			x2 = validate(dd);
		}
	}
	//
	double absError = 0.0; // инициализация погрешности 
	//
	int numberMax;
	std::cout << "Введите количество слагаемых \n"; //ввод количества слагаемых
	numberMax = validate(ii);
	while (numberMax <= 0) {
		std::cout << "Число N должно быть положительным \n";
		numberMax = validate(ii);
	}
	//
	double interval;
	std::cout << "Введите интервал \n"; //ввод интервала
	interval = validate(dd);
	while (interval <= 0) {
		std::cout << "Интервал не может быть меньше нуля. \n";
		interval = validate(dd);
	}
	//
	double accuracy;
	std::cout << "Введите точность \n"; //ввод точности
	accuracy = validate(dd);
	while (accuracy <= 0) {
		std::cout << "Точность не может быть меньше нуля. \n";
		accuracy = validate(dd);
	}
	//
	std::cout << "x:\t f(x):\t \t N:\t выход по:\t " << std::endl;
	//
	approximate(accuracy, numberMax, x1, x2, interval);
	return 0;
}
// оптимизация, тестовый набор + перегрузка фукнций