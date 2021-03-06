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

#ifndef IOAPP_H
#define IOAPP_H

namespace ioapp {
	void ioapp (const std::filesystem::path p, std::function<void(std::filesystem::path)> f, bool recursive=false, bool debug=false, std::filesystem::directory_options declared_options=std::filesystem::directory_options::none, unsigned depth=0, unsigned NextDepth=0);

	class ProcessArgs {
	private:
	public:
		std::vector<std::string> Paths;
		std::vector<std::string> Flags;
		ProcessArgs(const int &argc, char* argv[], bool unique=false, int offset=0);
	};
}

#endif