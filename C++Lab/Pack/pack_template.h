#pragma once

#pragma pack(8)

template<typename T>
class packTemplate
{
public:
	packTemplate(T _t) :t(_t) {}
	char c;
	short s;
	int i;
	T t;
};

#pragma pack()