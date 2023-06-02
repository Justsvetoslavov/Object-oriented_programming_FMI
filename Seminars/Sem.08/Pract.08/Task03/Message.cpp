#include "Message.h"
#include <sstream>

Message::Message(const char* sentFrom, const char* text){
	if (sentFrom == nullptr || text == nullptr)
		throw std::invalid_argument("The text doesn't exist");

	this->sentFrom = sentFrom;
	this->text = text;
}

void Message::Print() const{
	std::cout << "From: " << sentFrom.c_str() << std::endl;
	std::cout << "Message: " << text.c_str() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Message& message){
	os << message.sentFrom.c_str() << std::endl;
	os << message.text.c_str();
	return os;
}

std::istream& operator>>(std::istream& is, Message& message){
	is >> message.text;
	is >> message.sentFrom;
	return is;
}
