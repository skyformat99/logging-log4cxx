/***************************************************************************
                                transformer.cpp
                             -------------------
    begin                : 2003/12/11
    copyright            : (C) 2003 by Michael CATANZARITI
    email                : mcatan@free.fr
 ***************************************************************************/
 /**************************************************************************
 * Copyright (C) The Apache Software Foundation. All rights reserved.      *
 *                                                                         *
 * This software is published under the terms of the Apache Software       *
 * License version 1.1, a copy of which has been included with this        *
 * distribution in the license.apl file.                                   *
 ***************************************************************************/

#include "transformer.h"
#include <fstream>

using namespace log4cxx;


void Transformer::transform(const String& in, const String& out,
	const std::vector<Filter *>& filters) throw(UnexpectedFormatException)
{
	String line;
	std::ifstream input(in.c_str());
	std::ofstream output(out.c_str());

	while (!std::getline(input, line).fail())
	{
		for (int i = 0; i < filters.size(); i++)
		{
			line = filters[i]->filter(line);
		}
		if (!line.empty())
		{
			output << line << std::endl;
		}
	}
}

void Transformer::transform(const String& in, const String& out,
	const Filter& filter) throw(UnexpectedFormatException)
{
	String line;
	std::ifstream input(in.c_str());
	std::ofstream output(out.c_str());

	while (!std::getline(input, line).fail())
	{
		line = filter.filter(line);
		output << line << std::endl;
	}

}
