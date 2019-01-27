#ifndef _VALUECOMPONENT_H_
#define _VALUECOMPONENT_H_

#include "Component.h"

class ValueComponent : public Component
{
private:
	enum Value
	{
		BUBBLY,
		CLASSY,
		WESTERN,
		FAMILY_ORIENTATED,
		SOPHISTICATED,
		CHRISTIAN,
		FLIRTY,
		QUIET,
		CREATIVE,
		AGGRESSIVE,
		SPORTY,
		SASSY,
		FUNNY,
		NIGHT_OWL,
		MORNING_PERSON,
		PATRIOTIC,
		OPTIMISTIC,
		CARING,
		ADVENTURES,
		RESPECTFUL,
		CHEERFUL,
		LAID_BACK,
		FIT_FREAK,
		JOYFUL,
		COMMITTED,
		MUSICAL,
		INDEPENDENT
	};
	Value m_values;

public:
	////////////////////////////////////////////////////////////
	/// Overloaded constructor
	////////////////////////////////////////////////////////////
	ValueComponent() : Component("Value Component") {}

	void setValue(Value values) {
		m_values = values;
	}

	std::string getValue() {
		switch (m_values) {
		case 0:
			if (Value::BUBBLY) {
				return "BUBBLY";
				break;
			}
		case 1:
			if (Value::CLASSY) {
				return "CLASSY";
				break;
			}
		case 2:
			if (Value::FAMILY_ORIENTATED) {
				return "FAMILY_ORIENTATED";
				break;
			}
		case 3:
			if (Value::SOPHISTICATED) {
				return "SOPHISTICATED";
				break;
			}
		case 4:
			if (Value::FLIRTY) {
				return "FLIRTY";
				break;
			}
		case 5:
			if (Value::QUIET) {
				return "QUIET";
				break;
			}
		case 6:
			if (Value::CREATIVE) {
				return "CREATIVE";
				break;
			}
		case 7:
			if (Value::AGGRESSIVE) {
				return "AGGRESSIVE";
				break;
			}
		case 8:
			if (Value::SPORTY) {
				return "SPORTY";
				break;
			}
		case 9:
			if (Value::SASSY) {
				return "SASSY";
				break;
			}
		case 10:
			if (Value::FUNNY) {
				return "FUNNY";
				break;
			}
		case 11:
			if (Value::NIGHT_OWL) {
				return "NIGHT_OWL";
				break;
			}
		case 12:
			if (Value::MORNING_PERSON) {
				return "MORNING_PERSON";
				break;
			}
		case 13:
			if (Value::PATRIOTIC) {
				return "PATRIOTIC";
				break;
			}
		case 14:
			if (Value::OPTIMISTIC) {
				return "OPTIMISTIC";
				break;

			}
		case 15:
			if (Value::CARING) {
				return "CARING";
				break;

			}
		case 16:
			if (Value::ADVENTURES) {
				return "ADVENTURES";
				break;

			}
		case 17:
			if (Value::RESPECTFUL) {
				return "RESPECTFUL";
				break;

			}
		case 18:
			if (Value::CHEERFUL) {
				return "CHEERFUL";
				break;

			}
		case 19:
			if (Value::LAID_BACK) {
				return "LAID_BACK";
				break;

			}
		case 20:
			if (Value::JOYFUL) {
				return "JOYFUL";
				break;

			}
		case 21:
			if (Value::COMMITTED) {
				return "COMMITTED";
				break;

			}
		case 22:
			if (Value::MUSICAL) {
				return "MUSICAL";
				break;

			}
		case 23:
			if (Value::INDEPENDENT) {
				return "INDEPENDENT";
				break;

			}
		case 24:
			if (Value::LAID_BACK) {
				return "LAID_BACK";
				break;
			}
		case 25:
			if (Value::WESTERN) {
				return "WESTERN";
				break;
			}
		case 26:
			if (Value::CHRISTIAN) {
				return "CHRISTIAN";
				break;
			}
		}
	}
};
#endif
