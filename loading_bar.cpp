#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cmath>
#include <unistd.h>

int percentage = 0;

void show_progress_bar(int time, int end, char symbol) {
	int time_split = (time * 1000) / (end - percentage);
	std::string progress_bar;
	std::string difference_bar;
	// Construct the string
	for (percentage; percentage <= end; percentage++) {
		progress_bar = "";
		difference_bar = "";
		for (int i = 0; i < percentage; i++) {
			progress_bar += " ";
		}
		for (int i = 100; i > percentage; i--) {
			difference_bar += " ";
		}
		std::cout << "\r [" << (percentage) << '%' << "] " << "\x1B[102m" << progress_bar << "\033[40m" << difference_bar << "\033[0m" << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(time_split));
	}
}

int main() {
	show_progress_bar(20, 20, '#');
	unsigned int microsecond_sleep = 1000000;
	usleep(microsecond_sleep);
	show_progress_bar(10, 50, '#');
	std::cout << "\n\n";
}
