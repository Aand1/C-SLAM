/*
 * c_fuzzy,
 *
 *
 * Copyright (C) 2014 Davide Tateo
 * Versione 1.0
 *
 * This file is part of c_fuzzy.
 *
 * c_fuzzy is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * c_fuzzy is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with c_fuzzy.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CLASSIFIERREASONER_H_
#define CLASSIFIERREASONER_H_

#include <map>
#include <vector>
#include <string>

#include "FuzzyReasoner.h"

typedef std::map<std::string, int> ObjectProperties;
typedef std::map<std::string, double> ClassificationMap;
typedef std::vector<ClassificationMap> InstanceClassification;

struct ObjectInstance
{
	size_t id;
	ObjectProperties properties;
};

class ClassifierReasoner
{
private:
	typedef std::map<std::string, int> ClassificationTable;
public:
	ClassifierReasoner(FuzzyClassifier& classifier,
			FuzzyKnowledgeBase& knowledgeBase);

	void addInstance(ObjectInstance& instance);
	InstanceClassification runClassification();
private:
	FuzzyClassifier& classifier;
	FuzzyReasoner& reasoner;
	std::vector<ObjectInstance&> inputs;

	ClassificationTable table;
};

#endif /* CLASSIFIERREASONER_H_ */