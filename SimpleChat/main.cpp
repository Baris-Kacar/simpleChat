#include <iostream>
#include "Chat.h"
#include "Time.h"
using namespace std;
/**
	Simple description:
	The goal of this project was to programm a very simple chat. The chat was programmed with the doubly linked list datastructure.
*/
/**
	outputMenu() - just printing menu options
*/
void outputMenu() {
	cout << ".............................MENU..............................." << endl;
	cout << "1. To change user please type '!change'. " << endl;
	cout << "2. To search for a content in the chat please type '!search'." << endl;
	cout << "3. To delete messages please type '!delete'." << endl;
	cout << "4. To clear chat history please type '!clear'." << endl;
	cout << "................................................................" << endl << endl;
}

int main() {
	Chat* chat = new Chat();
	Time* time = new Time();

	string username = "", date = "", message = "", searchText = "", deleteMessage = "";
	while (true)
	{
		system("CLS");
		outputMenu();

		if (username == "" || message == "!change") {
			cout << ".............................LOGIN............................." << endl << endl;
			cout << "Your Username: ";
			getline(std::cin, username);
			system("CLS");
			outputMenu();
		}
		else if (message == "!search") {
			cout << "What do you want to search ? : ";
			getline(std::cin, searchText);
			system("CLS");
			outputMenu();
			cout << "............................REPORT.............................." << endl << endl;
			if (chat->searchMessageText(searchText)) cout << "Report: Your search was successful." << endl << endl;
			else cout << "Your search wasn't successul" << endl << endl;
			cout << "................................................................" << endl << endl;
		}
		else if (message == "!delete") {
			cout << "Which message do you want to delete ? :";
			getline(std::cin, deleteMessage);
			system("CLS");
			outputMenu();
			if (chat->deleteNode(deleteMessage)) cout << "Report: your message has been deleted." << endl << endl;
			else cout << "Report: message doesn't exist!" << endl << endl;
		}
		else if (message == "!clear") {
			chat->~Chat();
		}
		cout << ".............................CHAT..............................." << endl;
		chat->printChat();
		cout << "Message from (" << username << ") : ";
		getline(std::cin, message);
		chat->insert(username, time->getTime(), message);
	}

}
