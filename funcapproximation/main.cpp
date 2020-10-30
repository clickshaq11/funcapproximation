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

void approximate(double accuracy, int numberMax, double x1, double x2, double interval) { // �������� ������� ���������� 
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
			message = "�������� ����� �� ������� �������";
			std::cout << x << "\t" << std::setw(10) << y << "\t" << i << "\t" << message << "\t \n";
			break;
		}
		while (absValue(nextValue) > absValue(accuracy)) {
			i++;
			if (i > numberMax) {
				message = "��������� ����� ��������� N";
				i = numberMax;
				break;
			}
			y += nextValue;
			b += 2;
			a *= xSquared;
			nextValue = a / b;
		}
		if (absValue(nextValue) < absValue(accuracy)) {
			message = "��������� ������ ��������";
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
		std::cout << "������� ����� \n";
	}
	return r;
}

int validate(int) {
	int l;
	while (!(std::cin >> l)) {
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "������� ����� \n";
	}
	return l;
}

int main() {
	setlocale(LC_ALL, "rus");
	int ii = 0;
	double dd = 0.0;
	//
	double x1;
	std::cout << "������� ��������� �������� x1 \n"; //���� ���������� �������� 
	x1 = validate(dd);
	while ((x1 <= -1) || (x1 >= 1)) {
		std::cout << "��������� �������� �����������. ������� ����� �� ��������� (-1 ; 1) ";
		x1 = validate(dd);
	}
	//
	double x2;
	std::cout << "������� �������� �������� x2 \n"; //���� ��������� �������� 
	x2 = validate(dd);
	while ((x2 <= -1) || (x2 >= 1)) {
		std::cout << "�������� �������� �����������. ������� ����� �� ��������� (-1 ; 1) ";
		x2 = validate(dd);
	}
	//
	while (x1 >= x2) {
		std::cout << "��������� �������� �� ����� ���� ������ ��� ����� ���������. \n";
		std::cout << "������� ��������� �������� x1 \n"; //���� ���������� �������� 
		x1 = validate(dd);
		while ((x1 <= -1) || (x1 >= 1)) {
			std::cout << "��������� �������� �����������. ������� ����� �� ��������� (-1 ; 1) ";
			x1 = validate(dd);
		}
		std::cout << "������� �������� �������� x2 \n"; //���� ���������� �������� 
		x2 = validate(dd);
		while ((x2 <= -1) || (x2 >= 1)) {
			std::cout << "�������� �������� �����������. ������� ����� �� ��������� (-1 ; 1) ";
			x2 = validate(dd);
		}
	}
	//
	double absError = 0.0; // ������������� ����������� 
	//
	int numberMax;
	std::cout << "������� ���������� ��������� \n"; //���� ���������� ���������
	numberMax = validate(ii);
	while (numberMax <= 0) {
		std::cout << "����� N ������ ���� ������������� \n";
		numberMax = validate(ii);
	}
	//
	double interval;
	std::cout << "������� �������� \n"; //���� ���������
	interval = validate(dd);
	while (interval <= 0) {
		std::cout << "�������� �� ����� ���� ������ ����. \n";
		interval = validate(dd);
	}
	//
	double accuracy;
	std::cout << "������� �������� \n"; //���� ��������
	accuracy = validate(dd);
	while (accuracy <= 0) {
		std::cout << "�������� �� ����� ���� ������ ����. \n";
		accuracy = validate(dd);
	}
	//
	std::cout << "x:\t f(x):\t \t N:\t ����� ��:\t " << std::endl;
	//
	approximate(accuracy, numberMax, x1, x2, interval);
	return 0;
}
// �����������, �������� ����� + ���������� �������