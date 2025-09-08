#!lua

local lang = "C++";

solution("tools");
	configurations({"Debug","Release"});
		--[[
		project("logger");
			kind("StaticLib");
			language(lang);
			files({"../src/logger/**.hpp","../main/logger/**.cpp"});
			targetextension(".lib");
			targetprefix("");
			targetname("logger");

			configuration("Release");
			defines({"NDEBUG"});
			flags({"Optimize"});
			buildoptions({"-std=c++11"});
			targetdir("../bin/main/release");
			objdir("../obj/main/release");

			configuration("Debug");
			defines({"DEBUG"});
			flags({"Symbols"});
			buildoptions({"-std=c++11"});
			targetdir("../bin/main/debug");
			objdir("../obj/main/debug");
		--]]
		project("logger-test");
			kind("ConsoleApp");
			language(lang);
			files({"../src/**.hpp", "../src/**.cpp"});
			
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
			