#include "tomato.h"
tomato::tomato() {
	m_age = 0;
	setGrowTime(3);
}

int tomato::getAge() {
	return m_age;
}
int tomato::getGrowTime() {
	return m_growTime;
}
