#include "VTMap.h"
#include <tinyxml2.h>

using namespace std;
using namespace tinyxml2;

XMLDocument* planetMap;

VTMap::VTMap()
{
}

VTMap::~VTMap()
{
}

void VTMap::LoadMapFile(const char * fileName)
{
	
	planetMap = new XMLDocument();
	
	//Load Map Files	
	planetMap->LoadFile(fileName);
	
	//XMLHandle * pRoot 
	//XMLNode * pRoot = planetMap.FirstChild();
	//if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;
	
	//XMLElement * pElement = pRoot.FirstChildElement("planets");
	//const char* pName = planetMap.FirstChildElement( "Folder" )->FirstChildElement( "name" )->GetText();
	
	
	//XMLElement * pElement = planetMap.FirstChildElement( "kml" )->FirstChildElement( "Document" )->FirstChildElement( "Folder" )->FirstChildElement( "Placemark" )->FirstChildElement( "name" )->GetText();
	//const char * name = planetMap.FirstChildElement( "kml" )->FirstChildElement( "Document" )->FirstChildElement( "Folder" )->FirstChildElement( "name" )->GetText();
	
	//XMLText* textNode = planetMap->FirstChildElement( "kml" )->FirstChildElement( "Document" )->FirstChildElement( "Folder" )->FirstChildElement( "name" )->FirstChild()->ToText();	
	//pName = textNode->Value();
	
	XMLNode * mFolderNode = planetMap->FirstChildElement( "kml" )->FirstChildElement( "Document" )->FirstChildElement( "Folder" );
	//XMLVisitor mPlanets;
	//mPlanetNode->Accept(mPlanets);
	//mPlanets->
	for (const XMLNode* mPlanet = mFolderNode->FirstChildElement( "Placemark" ); mPlanet != nullptr; mPlanet=mPlanet->NextSibling() )
	{
		StarMapData_Type* planetDataStructure = new StarMapData_Type();
		
		const XMLNode * mPlanetDataNode = mPlanet->FirstChildElement( "ExtendedData" )->FirstChildElement( "SchemaData" );				
		const XMLNode* mPlanetData = mPlanetDataNode->FirstChildElement( "SimpleData" );
		
		
		if (mPlanetData->FirstChild() != nullptr) planetDataStructure->Sector = mPlanetData->FirstChild()->Value();		
		mPlanetData = mPlanetData->NextSibling();
		mPlanetData = mPlanetData->NextSibling();
		if (mPlanetData->FirstChild() != nullptr) planetDataStructure->uid = atoi(mPlanetData->FirstChild()->Value());
		mPlanetData = mPlanetData->NextSibling();
		if (mPlanetData->FirstChild() != nullptr) planetDataStructure->Link = mPlanetData->FirstChild()->Value();
		mPlanetData = mPlanetData->NextSibling();
		if (mPlanetData->FirstChild() != nullptr) planetDataStructure->Grid = mPlanetData->FirstChild()->Value();
		mPlanetData = mPlanetData->NextSibling();
		if (mPlanetData->FirstChild() != nullptr) planetDataStructure->x = atoi(mPlanetData->FirstChild()->Value());
		mPlanetData = mPlanetData->NextSibling();
		if (mPlanetData->FirstChild() != nullptr) planetDataStructure->y = atoi(mPlanetData->FirstChild()->Value());
		mPlanetData = mPlanetData->NextSibling();
		mPlanetData = mPlanetData->NextSibling();
		if (mPlanetData->FirstChild() != nullptr) planetDataStructure->Region = mPlanetData->FirstChild()->Value();
		mPlanetData = mPlanetData->NextSibling();
		if (mPlanetData->FirstChild() != nullptr) planetDataStructure->Canon = mPlanetData->FirstChild()->Value();
		mPlanetData = mPlanetData->NextSibling();
		mPlanetData = mPlanetData->NextSibling();
		if (mPlanetData->FirstChild() != nullptr) planetDataStructure->Name = mPlanetData->FirstChild()->Value();
		mPlanetData = mPlanetData->NextSibling();
		mPlanetData = mPlanetData->NextSibling();
		mPlanetData = mPlanetData->NextSibling();
		if (mPlanetData->FirstChild() != nullptr) planetDataStructure->latitude = atof(mPlanetData->FirstChild()->Value());
		mPlanetData = mPlanetData->NextSibling();
		if (mPlanetData->FirstChild() != nullptr) planetDataStructure->longitude = atof(mPlanetData->FirstChild()->Value());
		/*
		planetDataStructure.Link =  mPlanetData->NextSibling->Value();
		planetDataStructure.Grid =  mPlanetData->NextSibling->Value();
		planetDataStructure.x =  mPlanetData->NextSibling->Value();
		planetDataStructure.y =  mPlanetData->NextSibling->Value();
		mPlanetData = mPlanetData->NextSibling();		//skipp
		planetDataStructure.Region =  mPlanetData->NextSibling->Value();
		planetDataStructure.Canon =  mPlanetData->NextSibling->Value();
		mPlanetData = mPlanetData->NextSibling();		//skipp
		planetDataStructure.Name =  mPlanetData->NextSibling->Value();
		mPlanetData = mPlanetData->NextSibling();		//skipp
		mPlanetData = mPlanetData->NextSibling();		//skipp
		//planetDataStructure.latitude =  mPlanetData->NextSibling;
		*/
		StarMap.insert(make_pair(planetDataStructure->uid, planetDataStructure));
	}
	
	
	//->FirstChildElement( "Placemark" )->FirstChildElement( "ExtendedData" )->FirstChildElement( "SchemaData" )->FirstChildElement( "SchemaData" );
	
	//mPlanet
	//StarMap.StarMap.insert()
	
	
	
	
}


