#include "Calc.h"

inline Calc& Calc::add(int value) { m_value += value; return *this; }

inline Calc& Calc::sub(int value) { m_value -= value; return *this; }

inline Calc& Calc::mult(int value) { m_value *= value; return *this; }
