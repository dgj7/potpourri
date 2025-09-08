#!lua

local lang = "C++";

solution("oglwin");
	configurations({"Debug","Release"});
		project("oglwin-test");
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