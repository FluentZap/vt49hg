#ifndef VTMAP_H
#define VTMAP_H
#include <map>

using namespace std;

class StarMapData_Type
	{	
	public:
		const char* Sector;
		int uid;
		const char* Link;
		const char* Grid;
		float x;
		float y;
		const char* Region;
		bool Canon;
		const char* RightRot;
		const char* Name;
		double latitude;
		double longitude;		
	};	
	

class VTMap
{
public:
	VTMap();
	~VTMap();


	struct odd
	{	
		int vv;
	};	
	map<int, StarMapData_Type*> StarMap;
	
	void LoadMapFile(const char*);
	
	
};

#endif // VTMAP_H
