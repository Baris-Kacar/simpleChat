#pragma once
#include <vector>
#include <string>
#include <map>
/**
	Node class -
*/

class ChatNode
{
public:
	std::string username;
	std::string date;
	std::string message;
	ChatNode* next;
	ChatNode* prev;
	ChatNode() {
		this->next = nullptr;
		this->prev = nullptr;
	}
	ChatNode(std::string benutzername, std::string date, std::string message) {
		this->next = nullptr;
		this->prev = nullptr;
		this->date = date;
		this->message = message;
		this->username = benutzername;
	}
};

/**
	DoublyLinkedList class - provides basic operations like search, insert, delete and so on...
*/
class Chat
{
public:
	Chat();
	~Chat();
	/**

	*/
	int numberOfMessages = 0;

	void insert(std::string username, std::string date, std::string message);
	bool searchMessageText(std::string searchText);
	bool deleteNode(std::string deleteText);
	void printChat();

private:
	ChatNode* head;


};