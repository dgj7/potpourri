#!lua

local lang = "C++";

solution("tools");
	configurations({"Debug","Release"});
		project("library-class-lib");
			kind("StaticLib");
			language(lang);
			files({"../src/**.hpp","../src/**.cpp"});
			targetextension(".lib");
			targetprefix("");
			targetname("libraryclass");

			configuration("Release");
			defines({"NDEBUG"});
			flags({"Optimize"});
			buildoptions({"-std=c++11"});
			targetdir("../bin/release");
			objdir("../obj/release");

			configuration("Debug");
			defines({"DEBUG"});
			flags({"Symbols"});
			buildoptions({"-std=c++11"});
			targetdir("../bin/debug");
			objdir("../obj/debug");
			