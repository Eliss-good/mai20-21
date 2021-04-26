#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

struct spisok_struct* glav_p;

struct spisok_struct {
    std::string NAME = " ";
	std::string Second_Name = " ";

	struct spisok_struct* next = NULL;
};

int perevod(std::string& chislo) {
	
	int desit = 0;
	for (int k = 0; k < chislo.size(); ++k) {
		desit = desit * 10 + (static_cast<int>(chislo[k]) - '0');
	}

	return desit;
	
}

void log(std::string& new_command) {
	std::ofstream zapis("data.txt", std::ios::app);

	if (zapis.is_open()) {
		zapis << new_command <<'\n';
	}
	zapis.close();

}

void history_f() {
	std::ifstream input("data.txt");
	if (input.is_open()) {
		std::string second;

		while (getline(input, second)) {
			std::cout << second << '\n';
		}
	}
	input.close();
}

void add_f(std::string& add_name, std::string& add_secndN) {
 
	spisok_struct *new_person_card;
	new_person_card = new spisok_struct;
    new_person_card -> NAME = add_name;
	new_person_card -> Second_Name = add_secndN;
	
	if (glav_p == NULL) glav_p = new_person_card;

	else {
		spisok_struct* cur = glav_p;
		while (cur->next != NULL) {
			cur = cur->next;
		}

		cur->next = new_person_card;
	}
	
}

void see_f() {

	spisok_struct* cur = glav_p;
	while (cur != NULL) {
		std::cout << '\t' <<cur -> NAME << " " <<cur -> Second_Name << '\n';
		cur = cur->next;	
	}

	Sleep(5000);
}

void del_f(int n) {

	spisok_struct* cur = glav_p;

	for (int i = 0; i < n; ++i) {
		
		if (cur != NULL) cur = cur ->next;
	}


	if (cur != NULL && n > 0) {
		spisok_struct* buf = cur -> next;
		cur->next = buf -> next;

		delete  buf;
	}
	else if (n == 0) {
		spisok_struct* buf = glav_p;
		glav_p = cur->next;

		delete buf;
	}

}


void change(std::string& vibor) {
	spisok_struct* cur = glav_p;

	std::string poisk_new;
	if (vibor == "SURNAME") {
		std::cin >> poisk_new;
		
		while (cur != NULL) {
			
			if (cur -> Second_Name == poisk_new) {
				std::cin >> poisk_new;
				cur -> Second_Name = poisk_new;

				return;
			}
			cur = cur->next;
		}
	} else if (vibor == "NAME") {
		std::cin >> poisk_new;
		while (cur != NULL) {

			if (cur -> NAME == poisk_new) {
				std::cin >> poisk_new;
				cur -> NAME = poisk_new;

				return;
			}
			cur = cur->next;
		}
	}
	
	log(poisk_new);

	std::cout << '\t' <<"No have this " << vibor << '\n';
}
void rand_f() {
	std::string kolvo;
    std::cout << '\t' << "Please enter the line size ";
	std::cin >> kolvo;
	log(kolvo);

	int n = perevod(kolvo);

	std::string add_name , add_secndN ;

	for (int i = 0; i < n ; ++i) {
		add_name.push_back(rand() % 26 + 97);
		add_secndN.push_back(rand() % 26 + 97);
		}

	std::cout << '\n' << '\t' << add_name << " " << add_secndN;
	//Sleep(1500);
	add_f(add_name, add_secndN);
}

void command_f(std::string command) {
	if (command == "ADD") {
		std::string add_name, add_secndN;
		std::cin >> add_name >> add_secndN;
		log(add_name);
		log(add_secndN);
		add_f(add_name, add_secndN);

	} else if (command == "SEE") {
		see_f();
	} else if (command == "DEL") {
		int n;
		std::cin >> n;
		del_f(n-1);
    } else if (command == "RAND") {
		rand_f();
	} else if (command == "STOP") {
		exit(0);
	} else if (command == "HELP") {
		std::cout << " " << std::endl;

		Sleep(7000);
	} else if (command == "CHANGE") {
		std::cout << '\t' << "NAME or SURNAME?" << '\n';
		
		std::string vibor;
		std::cin >> vibor;
		log(vibor);

		change(vibor);
	} else if (command == "history") {
		history_f();
	}
} 


int main() {

	std::string command;
	while (true) {
		std::cout << "E/G" << "   ADD | CHANGE | SEE | DEL | RAND | HELP | STOP " << std::endl;

		std::cin >> command;
		log(command);
        command_f(command);
		std::cout << std::endl;
		//system("cls");
	}

	return 0;
}
