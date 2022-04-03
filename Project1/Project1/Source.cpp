#include <iostream>
#include <fstream>
#include <string>

bool IsCorrect()
{
	std::string username, password, un, ps;
	std::cout << "Enter Username: ";
	std::cin >> username;
	std::cout << "Enter password: ";
	std::cin >> password;

	std::ifstream read("D:\Visual studio projects\Project1\\ " + username + ".txt");
	std::getline(read, un);
	getline(read, ps);

	if (un == username && ps == password)
		return true;
	else
		return false;
}

int main()
{
	int choice;
	std::cout << "1 Register\n2 Login\nchoice ";
	std::cin >> choice;
	if (choice == 1)
	{
		std::string username, password;
		std::cout << "select a username: ";
		std::cin >> username;
		std::cout << "select a password: ";
		std::cin >> password;
		
		
		std::ofstream file;
		file.open("D:\Visual studio projects\Project1\\" + username + ".txt");
		file << username <<std:: endl << password;
		file.close();
		main();
	}
	else if(choice==2)

	{
		bool success = IsCorrect();
		if (!success)
		{
			std::cout << "False login\n";
			system("PAUSE");
			return 0;
		}
		else
		{
			std::cout << "Login Successful!" << std::endl;
			system("PAUSE");
			return 1;
		}
	}

}