#include "Dialog.h"

const std::string Dialog::daleIntroQuestion = "Hi there, the name�s Dale, how do you like your steak?";
const std::string Dialog::daleIntroResponsesBad = "I am a vegetarian, good sir.";
const std::string Dialog::daleIntroResponsesNeutral = "Medium rare.";
const std::string Dialog::daleIntroResponsesGood = "I love my steak fresh off the carcass, when you can still smell the kill.";
const std::string Dialog::daleThisThatQuestion = "Huntin� bucks or fly fishin�?";
const std::string Dialog::daleThisThatResponsesBad = "I�m not interested in the outdoors, it�s terrifying to go outside.";
const std::string Dialog::daleThisThatResponsesNeutral = "I like hunting, but also, I like fishing.";
const std::string Dialog::daleThisThatResponsesGood = "If I could hunt bucks all year round, you bet your bottom dollar I would!";
const std::string Dialog::daleKnowBetterQuestion = "What's your ideal date?";
const std::string Dialog::daleKnowBetterResponsesBad = "I like to watch rom coms and eat popcorn, gluten free, of course.";
const std::string Dialog::daleKnowBetterResponsesNeutral = "I like the idea of doing something new and adventurous in the wild.";
const std::string Dialog::daleKnowBetterResponsesGood = "My perfect date starts with a big ol� juicy steak in the morning, go straight to hunting right after, and then, at night, research government conspiracies, don't trust the government! They be spying on you!";
const std::string Dialog::daleOverallResponsesBad = "I�m sorry, I think you are working for the government, trying to trick me into giving you all of my secrets.";
const std::string Dialog::daleOverallResponsesNeutral = "I like you, but I love huntin� more.";
const std::string Dialog::daleOverallResponsesGood = "You had me at huntin�.";

const std::string Dialog::remyIntroQuestion = "";
const std::string Dialog::remyIntroResponsesBad = "";
const std::string Dialog::remyIntroResponsesNeutral = "";
const std::string Dialog::remyIntroResponsesGood = "";
const std::string Dialog::remyThisThatQuestion = "";
const std::string Dialog::remyThisThatResponsesBad = "";
const std::string Dialog::remyThisThatResponsesNeutral = "";
const std::string Dialog::remyThisThatResponsesGood = "";
const std::string Dialog::remyKnowBetterQuestion = "";
const std::string Dialog::remyKnowBetterResponsesBad = "";
const std::string Dialog::remyKnowBetterResponsesNeutral = "";
const std::string Dialog::remyKnowBetterResponsesGood = "";
const std::string Dialog::remyOverallResponsesBad = "";
const std::string Dialog::remyOverallResponsesNeutral = "";
const std::string Dialog::remyOverallResponsesGood = "";

const std::string Dialog::toddIntroQuestion = "";
const std::string Dialog::toddIntroResponsesBad = "";
const std::string Dialog::toddIntroResponsesNeutral = "";
const std::string Dialog::toddIntroResponsesGood = "";
const std::string Dialog::toddThisThatQuestion = "";
const std::string Dialog::toddThisThatResponsesBad = "";
const std::string Dialog::toddThisThatResponsesNeutral = "";
const std::string Dialog::toddThisThatResponsesGood = "";
const std::string Dialog::toddKnowBetterQuestion = "";
const std::string Dialog::toddKnowBetterResponsesBad = "";
const std::string Dialog::toddKnowBetterResponsesNeutral = "";
const std::string Dialog::toddKnowBetterResponsesGood = "";
const std::string Dialog::toddOverallResponsesBad = "";
const std::string Dialog::toddOverallResponsesNeutral = "";
const std::string Dialog::toddOverallResponsesGood = "";

const std::string Dialog::magnumIntroQuestion = "";
const std::string Dialog::magnumIntroResponsesBad = "";
const std::string Dialog::magnumIntroResponsesNeutral = "";
const std::string Dialog::magnumIntroResponsesGood = "";
const std::string Dialog::magnumThisThatQuestion = "";
const std::string Dialog::magnumThisThatResponsesBad = "";
const std::string Dialog::magnumThisThatResponsesNeutral = "";
const std::string Dialog::magnumThisThatResponsesGood = "";
const std::string Dialog::magnumKnowBetterQuestion = "";
const std::string Dialog::magnumKnowBetterResponsesBad = "";
const std::string Dialog::magnumKnowBetterResponsesNeutral = "";
const std::string Dialog::magnumKnowBetterResponsesGood = "";
const std::string Dialog::magnumOverallResponsesBad = "";
const std::string Dialog::magnumOverallResponsesNeutral = "";
const std::string Dialog::magnumOverallResponsesGood = "";

const std::string Dialog::mabelIntroQuestion = "";
const std::string Dialog::mabelIntroResponsesBad = "";
const std::string Dialog::mabelIntroResponsesNeutral = "";
const std::string Dialog::mabelIntroResponsesGood = "";
const std::string Dialog::mabelThisThatQuestion = "";
const std::string Dialog::mabelThisThatResponsesBad = "";
const std::string Dialog::mabelThisThatResponsesNeutral = "";
const std::string Dialog::mabelThisThatResponsesGood = "";
const std::string Dialog::mabelKnowBetterQuestion = "";
const std::string Dialog::mabelKnowBetterResponsesBad = "";
const std::string Dialog::mabelKnowBetterResponsesNeutral = "";
const std::string Dialog::mabelKnowBetterResponsesGood = "";
const std::string Dialog::mabelOverallResponsesBad = "";
const std::string Dialog::mabelOverallResponsesNeutral = "";
const std::string Dialog::mabelOverallResponsesGood = "";

const std::string Dialog::banjoIntroQuestion = "";
const std::string Dialog::banjoIntroResponsesBad = "";
const std::string Dialog::banjoIntroResponsesNeutral = "";
const std::string Dialog::banjoIntroResponsesGood = "";
const std::string Dialog::banjoThisThatQuestion = "";
const std::string Dialog::banjoThisThatResponsesBad = "";
const std::string Dialog::banjoThisThatResponsesNeutral = "";
const std::string Dialog::banjoThisThatResponsesGood = "";
const std::string Dialog::banjoKnowBetterQuestion = "";
const std::string Dialog::banjoKnowBetterResponsesBad = "";
const std::string Dialog::banjoKnowBetterResponsesNeutral = "";
const std::string Dialog::banjoKnowBetterResponsesGood = "";
const std::string Dialog::banjoOverallResponsesBad = "";
const std::string Dialog::banjoOverallResponsesNeutral = "";
const std::string Dialog::banjoOverallResponsesGood = "";

const std::string Dialog::eliseIntroQuestion = "";
const std::string Dialog::eliseIntroResponsesBad = "";
const std::string Dialog::eliseIntroResponsesNeutral = "";
const std::string Dialog::eliseIntroResponsesGood = "";
const std::string Dialog::eliseThisThatQuestion = "";
const std::string Dialog::eliseThisThatResponsesBad = "";
const std::string Dialog::eliseThisThatResponsesNeutral = "";
const std::string Dialog::eliseThisThatResponsesGood = "";
const std::string Dialog::eliseKnowBetterQuestion = "";
const std::string Dialog::eliseKnowBetterResponsesBad = "";
const std::string Dialog::eliseKnowBetterResponsesNeutral = "";
const std::string Dialog::eliseKnowBetterResponsesGood = "";
const std::string Dialog::eliseOverallResponsesBad = "";
const std::string Dialog::eliseOverallResponsesNeutral = "";
const std::string Dialog::eliseOverallResponsesGood = "";

const std::string Dialog::sonnyIntroQuestion = "";
const std::string Dialog::sonnyIntroResponsesBad = "";
const std::string Dialog::sonnyIntroResponsesNeutral = "";
const std::string Dialog::sonnyIntroResponsesGood = "";
const std::string Dialog::sonnyThisThatQuestion = "";
const std::string Dialog::sonnyThisThatResponsesBad = "";
const std::string Dialog::sonnyThisThatResponsesNeutral = "";
const std::string Dialog::sonnyThisThatResponsesGood = "";
const std::string Dialog::sonnyKnowBetterQuestion = "";
const std::string Dialog::sonnyKnowBetterResponsesBad = "";
const std::string Dialog::sonnyKnowBetterResponsesNeutral = "";
const std::string Dialog::sonnyKnowBetterResponsesGood = "";
const std::string Dialog::sonnyOverallResponsesBad = "";
const std::string Dialog::sonnyOverallResponsesNeutral = "";
const std::string Dialog::sonnyOverallResponsesGood = "";

const std::string Dialog::courtneyIntroQuestion = "";
const std::string Dialog::courtneyIntroResponsesBad = "";
const std::string Dialog::courtneyIntroResponsesNeutral = "";
const std::string Dialog::courtneyIntroResponsesGood = "";
const std::string Dialog::courtneyThisThatQuestion = "";
const std::string Dialog::courtneyThisThatResponsesBad = "";
const std::string Dialog::courtneyThisThatResponsesNeutral = "";
const std::string Dialog::courtneyThisThatResponsesGood = "";
const std::string Dialog::courtneyKnowBetterQuestion = "";
const std::string Dialog::courtneyKnowBetterResponsesBad = "";
const std::string Dialog::courtneyKnowBetterResponsesNeutral = "";
const std::string Dialog::courtneyKnowBetterResponsesGood = "";
const std::string Dialog::courtneyOverallResponsesBad = "";
const std::string Dialog::courtneyOverallResponsesNeutral = "";
const std::string Dialog::courtneyOverallResponsesGood = "";