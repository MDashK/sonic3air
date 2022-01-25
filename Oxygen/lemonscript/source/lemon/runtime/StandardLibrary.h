/*
*	Part of the Oxygen Engine / Sonic 3 A.I.R. software distribution.
*	Copyright (C) 2017-2022 by Eukaryot
*
*	Published under the GNU GPLv3 open source software license, see license.txt
*	or https://www.gnu.org/licenses/gpl-3.0.en.html
*/

#pragma once

#include <rmxbase.h>


namespace lemon
{
	class Module;

	class API_EXPORT StandardLibrary
	{
	public:
		inline static std::string BUILTIN_NAME_STRING_OPERATOR_PLUS = "#builtin_string_operator_plus";

	public:
		static void registerBindings(Module& module);
	};
}
