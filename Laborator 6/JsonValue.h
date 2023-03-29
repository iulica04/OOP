#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
//#include<sstream>

class JsonValue {

public:

	virtual ~JsonValue() = 0;
	virtual void print(std::ostream& out) const = 0;
};

class NullValue : public JsonValue {
public:
	NullValue() {};
	void print(std::ostream& out) const override;
};

class NumberValue : public JsonValue
{
	double number;
public:
	NumberValue(double value) : number(value) {}
	void print(std::ostream& out) const override;
};

class BoolValue : public JsonValue
{
	bool var;
public:
	BoolValue(bool value) : var(value) {}
	void print(std::ostream& out) const override;
};

class StringValue : public JsonValue
{
	std::string sir;
public:
	StringValue(const std::string& value) : sir(value) {}
	void print(std::ostream& out) const override;
};

class ArrayValue : public JsonValue
{
	std::vector<JsonValue*> value;
public:  
	ArrayValue() : value() {}
	void add(JsonValue* val);
	void print(std::ostream& out) const override;

};

class ObjectValue : public JsonValue
{
	std::vector<std::pair<std::string, JsonValue*>> value;
public:
	ObjectValue(): value() {}
	void add(const std::string& name, JsonValue* val);
	void print(std::ostream& out) const override;
	operator unsigned() const;
};

