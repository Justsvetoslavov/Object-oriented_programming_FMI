#include "Tire.h"

bool Tire::isValidWidth(ushort width){
	return width >= MIN_WIDTH && width <= MAX_WIDTH;
}

bool Tire::isValidProfile(ushort profile){
	return profile >= MIN_PROFILE && profile <= MAX_PROFILE;
}

bool Tire::isValidDiameter(ushort diameter){
	return diameter >= MIN_RIM_SIZE && diameter <= MAX_RIM_SIZE;
}

Tire::Tire(unsigned ID, MyString manufacturer, MyString description, ushort width, ushort profile, ushort diameter) : CarPart (ID, manufacturer, description){
	setWidth(width);
	setProfile(profile);
	setRimSize(diameter);
}

ushort Tire::getWidth() const {
	return _width;
}

bool Tire::setWidth(ushort width) {
	if (!isValidWidth(width)) {
		return false;
	}

	_width = width;
	return true;
}

ushort Tire::getProfile() const {
	return _profile;
}

bool Tire::setProfile(ushort profile) {
	if (!isValidProfile(profile)) {
		return false;
	}

	_profile = profile;
	return true;
}

ushort Tire::getRimSize() const {
	return _rim;
}

bool Tire::setRimSize(ushort diameter) {
	if (!isValidDiameter(diameter)) {
		return false;
	}

	_rim = diameter;
	return true;
}

std::ostream& operator << (std::ostream& os, const Tire& t) {
	os << (CarPart)t;
	return os << " - " << t.getWidth() << " / " << t.getProfile() << "R" << t.getRimSize();
}
