#include "node.h"


bool EmptyNode::Evaluate(const Date& date, const string& event) const {
	return true;
}


bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
	switch (comp) {
	case Comparison::Equal: {
		return date == self_date;
		break;
	}
	case Comparison::NotEqual: {
		return date != self_date;
		break;
	}
	case Comparison::Greater: {
		return date > self_date;
		break;
	}
	case Comparison::Less: {
		return date < self_date;
		break;
	}
	case Comparison::GreaterOrEqual: {
		return date >= self_date;
		break;
	}
	case Comparison::LessOrEqual: {
		return date <= self_date;
		break;
	}
	}
	return 0;
}


bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
	switch (comp) {
	case Comparison::Equal: {
		return event == value;
		break;
	}
	case Comparison::NotEqual: {
		return event != value;
		break;
	}
	case Comparison::Less: {
		return event < value;
		break;
	}
	case Comparison::Greater: {
		return event > value;
		break;
	}
	case Comparison::LessOrEqual: {
		return event <= value;
		break;
	}
	case Comparison::GreaterOrEqual: {
		return event >= value;
		break;
	}
	}
	return 0;
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
	if (operation == LogicalOperation::And) {
		return leftNode->Evaluate(date, event) && rightNode->Evaluate(date, event);
	}
	else if (operation == LogicalOperation::Or) {
		return leftNode->Evaluate(date, event) || rightNode->Evaluate(date, event);
	}
	return 0;
}