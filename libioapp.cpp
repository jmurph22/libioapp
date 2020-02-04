/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <filesystem>
#include <functional>
#include "libioapp.hpp"

unsigned SeperatedIncrement(unsigned u)
{
	u++;
	return u;
}

namespace ioapp {
	void ioapp (
		const std::filesystem::path p,
		std::function<void(std::filesystem::path)> f,
		bool recursive,
		bool debug,
		std::filesystem::directory_options declared_options,
		unsigned depth,
		unsigned NextDepth //This argument is only ever used internally.
	) {
		if(std::filesystem::is_regular_file(p))
		{
			f(p);
		}

		else if(std::filesystem::is_directory(p))
		{
			/*
			If NextDepth is zero
			(NextDepth is always starts as zero.)
			
			OR
			
			depth is zero
			AND
			Recursive is true
			
			OR

			Recursive is true
			AND
			NextDepth is less than or equal to depth
			*/
			if(NextDepth == 0 || (depth == 0 && recursive) || (recursive && (NextDepth <= depth)))
			{
				for(const auto &e : std::filesystem::directory_iterator(p, declared_options))
				{
					ioapp(e.path(),f,recursive,debug,declared_options,depth,SeperatedIncrement(NextDepth));
				}
			}
		}

		else
		{
			if(debug)
			{
				std::cerr << p.string() << "is not a file or directory.\n";
			}
		}
	}

	ProcessArgs::ProcessArgs(const int &argc, char* argv[], bool unique)
	{
		for(int arg_counter = 0; arg_counter < argc; arg_counter++)
		{
			if(std::filesystem::exists(argv[arg_counter]))
			{
				this->Paths.push_back(argv[arg_counter]);
			}

			else
			{
				this->Flags.push_back(argv[arg_counter]);
			}
		}
	}
}
