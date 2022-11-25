#include "Chat.h"
#include <iostream>
/**
	default constructor - initialize the object attribute
*/
Chat::Chat() {
	this->head = nullptr;
}
/**
	destrcutor - deletes chat history and releasing the pointer on the heap
*/
Chat::~Chat() {
	ChatNode* del = new ChatNode();
	del = head;
	head = nullptr;
	delete del;
}

/**
	insert() - inserts user information
			username - username for the user who wants to send a message
			date	 - current system time
			message  - contains text written by the user
*/
void Chat::insert(std::string username, std::string date, std::string message)
{
	ChatNode* node = new ChatNode(username, date, message);
	numberOfMessages++;
	if (message == "!change" || message == "!search" || message == "!delete" || message == "!clear")return;
	if (this->head == nullptr) head = node;
	else {
		ChatNode* tmp = new ChatNode();
		ChatNode* prev = new ChatNode();
		tmp = head;
		while (tmp->next != nullptr)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (tmp != node) {
			tmp->next = node;
			node->prev = tmp;
		}
	}
}
/**
	compareText() - compares two strings
			message - contains text written by the user
			searchText - contains the text that is beeing searched for
*/
bool compareText(std::string message, std::string searchText) {
	std::string lower_message = "";
	for (unsigned int i = 0; i <= message.size() - 1; i++) {
		if (message.at(i) >= 'A' && message.at(i) <= 'Z') lower_message.push_back(message.at(i) + 32);
		else lower_message.push_back(message.at(i));
	}
	if (lower_message.find(searchText) != std::string::npos) return true;
	return false;
}
/**
	searchMessageText() - searches for the text contained in the chat history
			searchText - contains the text that is beeing searched for
*/
bool Chat::searchMessageText(std::string searchText)
{
	if (head == nullptr) return false;
	else {
		ChatNode* tmp = new ChatNode();
		tmp = head;
		while (tmp != nullptr)
		{
			if (compareText(tmp->message, searchText)) return true;
			tmp = tmp->next;
		}
	}
	return false;
}
/**
	deleteNode() - deletes the oldest message with the respective text
			deleteText - contains the text to be deleted from the chat
*/
bool Chat::deleteNode(std::string deleteText)
{
	if (head == nullptr) return false;
	else {
		if (head->message == deleteText && head->next == nullptr) {
			head = nullptr;
			numberOfMessages--;
			return true;
		}
		ChatNode* tmp = new ChatNode();
		tmp = head;
		while (tmp->next != nullptr) {
			if ((compareText(tmp->message, deleteText)))break;
			tmp = tmp->next;
		}
		if (compareText(tmp->message, deleteText)) {
			if (tmp->next == nullptr) {
				tmp->prev->next = nullptr;
				tmp->prev = nullptr;
				delete tmp;
				numberOfMessages--;
				return true;
			}
			if (tmp->prev == nullptr && tmp->next != nullptr) {
				head = head->next;
				head->prev = nullptr;
				delete tmp;
				numberOfMessages--;
				return true;
			}
			else {
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				delete tmp;
				numberOfMessages--;
				return true;
			}
		}
		return false;
	}
	return false;
}
/**
	printChat() - Method to print chat history
*/
void Chat::printChat()
{
	ChatNode* tmp = new ChatNode();
	tmp = head;
	if (tmp == nullptr) return;
	int i = 0;
	while (tmp != nullptr) {
		std::cout << "Message (" << tmp->username << "):" << tmp->message << " (" << tmp->date << ")" << std::endl;
		tmp = tmp->next;
	}
}