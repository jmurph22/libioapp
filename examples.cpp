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
#include <cstring>
#include <vector>
#include <libioapp.hpp>

int main(int argc, char* argv[])
{
	/*
	Basic example.
	Shows the ioapp function and ProcessArgs class.
	*/
	ioapp::ProcessArgs myProcessArgs(argc,argv);

	for(const auto & arg : myProcessArgs.Paths)
	{
		ioapp::ioapp(std::filesystem::path(arg), [](std::filesystem::path p) {
			std::cout << p.string() << std::endl;
		});
	}

	putchar('\n');

	/*
	Basic example but recursive.
	Second arg is recursive toggle.
	*/
	for(const auto & arg : myProcessArgs.Paths)
	{
		ioapp::ioapp(std::filesystem::path(arg), [](std::filesystem::path p) {
			std::cout << p.string() << std::endl;
		}, true);
	}

	putchar('\n');

	/*
	Basic example with debug output
	Third arg is debug print toggle.
	*/
	for(const auto & arg : myProcessArgs.Paths)
	{
		ioapp::ioapp(std::filesystem::path(arg), [](std::filesystem::path p) {
			std::cout << p.string() << std::endl;
		}, false, true);
	}

	putchar('\n');

	//Example of setting std::filesystem::directory_options for the inner library code.
	for(const auto & arg : myProcessArgs.Paths)
	{
		ioapp::ioapp(std::filesystem::path(arg), [](std::filesystem::path p) {
			std::cout << p.string() << std::endl;
		}, false, false, std::filesystem::directory_options::none);
	}

	putchar('\n');

	/*
	Example of setting the depth of a function.
	//This dictates how far down the recursion will go.
	*/
	for(const auto & arg : myProcessArgs.Paths)
	{
		ioapp::ioapp(std::filesystem::path(arg), [](std::filesystem::path p) {
			std::cout << p.string() << std::endl;
		}, true, true, std::filesystem::directory_options::none, 1);
	}

	putchar('\n');

	/*
	Example ofpPath and argument seperation.
	Try different arguments to test it out.
	*/

	printf("Paths:\n");

	for(const auto &p : myProcessArgs.Paths)
	{
		std::cout << p << std::endl;
	}

	printf("\nFlags:\n");

	for(const auto &f : myProcessArgs.Flags)
	{
		std::cout << f << std::endl;
	}

	return 0;
}