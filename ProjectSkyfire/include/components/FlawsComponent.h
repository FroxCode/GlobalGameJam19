#ifndef _FLAWCOMPONENT_H_
#define _FLAWCOMPONENT_H_

#include "Component.h"

class FlawComponent : public Component
{
private:
	enum Flaw
	{
		BAD_INSULATION,
		LEAKY_CEILING,
		SQUEAKY_STAIRS,
		GAMMY_BOILER,
		OLD_FASHIONED,
		LOUD_NEIGHBOURS,
		DIRTY_GUTTERS,
		DRAUGHTY,
		NO_HEATING,
		BURST_PIPES,
		MOULDY_DELPH,
		MILDEW_SHOWER,
		SINGLE_PANED_WINDOWS,
		MONEY_SINK,
		COLD,
		SELFISH,
		COMMITMENT_ISSUES,
		RUDE,
		DULL,
		DISLIKES_MUSIC,
		CONTROLLING,
		DERELICT,
		DUSTY,
		PUNGENT_ODOUR,
		OBSESSIVELY_PATRIOTIC,
		UNEMOTIONAL,
	};
	Flaw m_flaws;

public:
	////////////////////////////////////////////////////////////
	/// Overloaded constructor
	////////////////////////////////////////////////////////////
	FlawComponent() : Component("Flaw Component") {}

	void setFlaw(Flaw flaws) {
		m_flaws = flaws;
	}

	std::string getFlaw() {
		switch (m_flaws) {
		case 0:
			if (Flaw::BAD_INSULATION) {
				return "BAD_INSULATION";
				break;
			}
		case 1:
			if (Flaw::LEAKY_CEILING) {
				return "LEAKY_CEILING";
				break;
			}
		case 2:
			if (Flaw::SQUEAKY_STAIRS) {
				return "SQUEAKY_STAIRS";
				break;
			}
		case 3:
			if (Flaw::GAMMY_BOILER) {
				return "GAMMY_BOILER";
				break;
			}
		case 4:
			if (Flaw::OLD_FASHIONED) {
				return "OLD_FASHIONED";
				break;
			}
		case 5:
			if (Flaw::LOUD_NEIGHBOURS) {
				return "LOUD_NEIGHBOURS";
				break;
			}
		case 6:
			if (Flaw::DIRTY_GUTTERS) {
				return "DIRTY_GUTTERS";
				break;
			}
		case 7:
			if (Flaw::DRAUGHTY) {
				return "DRAUGHTY";
				break;
			}
		case 8:
			if (Flaw::NO_HEATING) {
				return "NO_HEATING";
				break;
			}
		case 9:
			if (Flaw::BURST_PIPES) {
				return "BURST_PIPES";
				break;
			}
		case 10:
			if (Flaw::MOULDY_DELPH) {
				return "MOULDY_DELPH";
				break;
			}
		case 11:
			if (Flaw::MILDEW_SHOWER) {
				return "MILDEW_SHOWER";
				break;
			}
		case 12:
			if (Flaw::SINGLE_PANED_WINDOWS) {
				return "SINGLE_PANED_WINDOWS";
				break;
			}
		case 13:
			if (Flaw::MONEY_SINK) {
				return "MONEY_SINK";
				break;
			}
		case 14:
			if (Flaw::COLD) {
				return "COLD";
				break;

			}
		case 15:
			if (Flaw::SELFISH) {
				return "SELFISH";
				break;

			}
		case 16:
			if (Flaw::COMMITMENT_ISSUES) {
				return "COMMITMENT_ISSUES";
				break;

			}
		case 17:
			if (Flaw::RUDE) {
				return "RUDE";
				break;

			}
		case 18:
			if (Flaw::DULL) {
				return "DULL";
				break;

			}
		case 19:
			if (Flaw::DISLIKES_MUSIC) {
				return "DISLIKES_MUSIC";
				break;

			}
		case 20:
			if (Flaw::CONTROLLING) {
				return "CONTROLLING";
				break;
			}
		case 21:
			if (Flaw::DERELICT) {
				return "DERELICT";
				break;
			}
		case 22:
			if (Flaw::DUSTY) {
				return "DUSTY";
				break;
			}

		case 23:
			if (Flaw::DUSTY) {
				return "DUSTY";
				break;
			}

		case 24:
			if (Flaw::PUNGENT_ODOUR) {
				return "PUNGENT_ODOUR";
				break;
			}

		case 25:
			if (Flaw::DUSTY) {
				return "DUSTY";
				break;
			}

		case 26:
			if (Flaw::DUSTY) {
				return "DUSTY";
				break;
			}
		}
	}
};
#endif

