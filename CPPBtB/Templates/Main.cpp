#include <iostream>
#include "Template.h"

int main()
{
	Template<float> templateFloat;
	for (float f: {2.2f, 3.3f, 4.4f})
	{
		templateFloat.add(f);
	}
	templateFloat.put(1.1f); //puts it at the front
	templateFloat.get();	//returns the first element
	templateFloat.size();	//prints the size of the template
	templateFloat.dump();	//prints each element of the template


	Template<std::string> templateString;
	for (std::string s: {"Bobbie" ,"Kimmie" ,"Ronnie"})
	{
		templateString.add(s);
	}
	templateString.put("Connie");
	templateString.get();
	templateString.size();
	templateString.dump();

	return 0;
}