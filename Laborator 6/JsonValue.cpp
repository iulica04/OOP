#include "JsonValue.h"

JsonValue::~JsonValue() {}

void NullValue::print(std::ostream& out) const
{
	out << NULL;
}

void NumberValue::print(std::ostream& out) const
{
	out << number;
}

void BoolValue::print(std::ostream& out ) const
{
	if (var == 1)
		out << "true";
	else
		out << "false";
}

void StringValue::print(std::ostream& out) const 
{
	out << '"' << sir << '"';
}

void ArrayValue::add(JsonValue* val)
{
	if (value.size() < 16)
		value.push_back(val);
}

void ArrayValue::print(std::ostream& out) const
{
	out << '[';
	for (size_t i = 0; i < value.size(); i++)
	{
		if (i > 0)
			out << ", ";
		value[i]->print(out);
	}
	out << ']';
}

void ObjectValue::add(const std::string& name, JsonValue* val)
{
	value.push_back(std::make_pair(name, val));
}

void ObjectValue::print(std::ostream& out) const
{
	out << '{';
	for (size_t i = 0; i < value.size(); i++)
	{
		if (i > 0)
			out << ", ";
		out << '"' << value[i].first << '"' << ':';
		value[i].second->print(out);
	}
	out << '}';
}

ObjectValue::operator unsigned() const
{
	return value.size();
}

