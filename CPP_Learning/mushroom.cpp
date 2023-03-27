#include "mushroom.h"
mushroom::mushroom() {
	m_age =0;
	setGrowTime(4);
}
int mushroom::getAge() {
	return m_age;
}
int mushroom::getGrowTime() {
	return m_growTime;
}
