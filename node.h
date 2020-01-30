#pragma once
#include <iostream>
#include <memory>
#include <stack>
#include <vector>
#include <string>
#include <cstdint>

using namespace std;

#include "date.h"

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

enum class LogicalOperation {
	Or,
	And
};

class Node {
public:
	virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

class EmptyNode : public Node {
public:
	bool Evaluate(const Date& date, const string& event) const override;
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(Comparison cmp, Date date) : self_date(date), comp(cmp) {
	}
	bool Evaluate(const Date& date, const string& event) const override;
private:
	Comparison comp;
	Date self_date;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(Comparison cmp, string v) :comp(cmp), value(v){
	}
	bool Evaluate(const Date& date, const string& event)  const override;
private:
	Comparison comp;
	string value;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(LogicalOperation op, shared_ptr<Node> left, shared_ptr<Node> right)
		: operation(op), leftNode(left), rightNode(right) {}
	bool Evaluate(const Date& date, const string& event) const override;
private:
	LogicalOperation operation;
	shared_ptr<Node> leftNode, rightNode;
};