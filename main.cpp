#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <limits>
#include <fstream>

std::vector<int> genLengths(int n, int lengthsConstraint) {
    std::random_device device;
    std::mt19937 gen(device());
    std::uniform_int_distribution<> distrib(1, lengthsConstraint);
    std::vector<int> lengths;
    while (lengths.size() < n) {
        int len = distrib(gen);
        if (std::find(lengths.begin(), lengths.end(), len) == lengths.end()) {
            lengths.push_back(len);
        }
    }
    return lengths;
}

void fillArrayByRandomNumbers(std::vector<int> &vec) {
    std::random_device device;
    std::mt19937 gen(device());
    for (auto &el : vec)
        el = gen();
}

std::vector<std::vector<int>> initMatrix(int n, int lengthsConstraint) {
    std::vector<int> lengths = genLengths(n, lengthsConstraint);
    std::vector<std::vector<int>> matr(n);
    for (int i = 0; i < lengths.size(); ++i) {
        matr[i].resize(lengths[i]);
        fillArrayByRandomNumbers(matr[i]);
        if (i % 2 == 0)
            std::sort(matr[i].begin(), matr[i].end());
        else
            std::sort(matr[i].begin(), matr[i].end(), std::greater<int> ());
    }
    return matr;
}

void writeOutput(std::vector<std::vector<int>> matr) {
		std::ofstream out;
		out.open("output.txt");
		for (auto &vec : matr) {
        for (auto &el : vec)
            out << el << " ";
        out << "\n";
		}
		out.close();
}

int main(int argc, char** argv) {
		int lengthsConstraint = 50;
		if (argc == 2) {
			if (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0) {
				std::cout << "Если вы хотите ограничить длину массива, используйте команды: \n --lengthConstraint <int> \n или  \n -lc <int>" << std::endl;
			} else {
				std::cerr << "Неверное количество аргументов" << std::endl;
			}
		}
		if (argc == 3) {
			if (strncmp(argv[1], "--lengthConstraint", 19) == 0 || strncmp(argv[1], "-lc", 4) == 0) {
					int x = atoi(argv[2]);
					if (x) {
							lengthsConstraint = x;
							std::cout << lengthsConstraint << std::endl;
					} else {
							std::cerr << "Введите число" << std::endl;
					}
			} else {
					std::cerr << "Неправильные аргументы. Если вам нужна помощь, используйте --help или -h" << std::endl;
			}
		}
    int n;
		std::cout << "Введите количество массивов: ";
    std::cin >> n;
    std::vector<std::vector<int>> matr = initMatrix(n, lengthsConstraint);
		writeOutput(matr);
    return 0;
}
