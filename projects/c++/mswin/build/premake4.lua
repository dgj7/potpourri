#!lua

local lang = "C++";

solution("mswin");
	configurations({"Debug","Release"});
		project("mswin-test");
			kind("WindowedApp");
			language(lang);
			files({"../src/**.hpp","../src/**.cpp"});
		
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