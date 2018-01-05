#include "Level.h"


//////////////////////////////////////////////////////////////////////////////////////////
//*********************LEVEL 1**********************************************************//
//loads all of the needed stuff for level 1
//This is where all the scripting for level 1 goes. This includes all of the  districts, and interiors for that particular level
void Level1::loadLevel(GameMissions *missions)
{

///////////////////////////////////////////////////////////////////////////
//***********FOR District ONE****************************//
	//for the level's model
	objLoader *d1_tempM[50];
	
	//Ground
	d1_tempM[0] = new objLoader();
	d1_tempM[29] = new objLoader();
	d1_tempM[30] = new objLoader();
	d1_tempM[31] = new objLoader();

	//walls
	d1_tempM[6] = new objLoader();

	//fountain base
	d1_tempM[13] = new objLoader();

	//fountain water
	d1_tempM[14] = new objLoader();

	//foot bridge
	d1_tempM[16] = new objLoader();

	//light fixtures
	d1_tempM[28] = new objLoader();


	//Mission Buildings
	//apartments model
	d1_tempM[1] = new objLoader();
	//bar model
	d1_tempM[2] = new objLoader();
	//club model
	d1_tempM[3] = new objLoader();


	//Type 1 Buildings
	d1_tempM[4] = new objLoader();
	d1_tempM[10] = new objLoader();
	d1_tempM[15] = new objLoader();
	d1_tempM[17] = new objLoader();
	d1_tempM[21] = new objLoader();
	d1_tempM[23] = new objLoader();
	d1_tempM[27] = new objLoader();

	//type 2 buildings
	d1_tempM[7] = new objLoader();
	d1_tempM[9] = new objLoader();
	d1_tempM[12] = new objLoader();
	d1_tempM[19] = new objLoader();
	d1_tempM[20] = new objLoader();
	d1_tempM[25] = new objLoader();
	d1_tempM[26] = new objLoader();

	//type 3 buildings
	d1_tempM[5] = new objLoader();
	d1_tempM[8] = new objLoader();
	d1_tempM[11] = new objLoader();
	d1_tempM[18] = new objLoader();
	d1_tempM[22] = new objLoader();
	d1_tempM[24] = new objLoader();
	
	
	///extra 
	
	//d1_tempM[29] = new objLoader();
	//d1_tempM[30] = new objLoader();
	//d1_tempM[31] = new objLoader();
	//d1_tempM[32] = new objLoader();
	//d1_tempM[33] = new objLoader();
	//d1_tempM[34] = new objLoader();
	//d1_tempM[35] = new objLoader();


	//for the level's texture
	tex *d1_tempT[50];

	//ground texture
	d1_tempT[0] = new tex();
	d1_tempT[29] = new tex();
	d1_tempT[30] = new tex();
	d1_tempT[31] = new tex();

	//walls
	d1_tempT[6] = new tex();

	//fountain base
	d1_tempT[13] = new tex();

	//fountain water
	d1_tempT[14] = new tex();

	//foot bridge
	d1_tempT[16] = new tex();

	//light fixtures
	d1_tempT[28] = new tex();

	//mission buildings textures
	//apartments texture
	d1_tempT[1] = new tex();
	//bar texture
	d1_tempT[2] = new tex();
	//club texture
	d1_tempT[3] = new tex();


	//type 1 building textures
	d1_tempT[4] = new tex();
	d1_tempT[10] = new tex();
	d1_tempT[15] = new tex();
	d1_tempT[17] = new tex();
	d1_tempT[21] = new tex();
	d1_tempT[23] = new tex();
	d1_tempT[27] = new tex();

	//type 2 buildings textures
	d1_tempT[7] = new tex();
	d1_tempT[9] = new tex();
	d1_tempT[12] = new tex();
	d1_tempT[19] = new tex();
	d1_tempT[20] = new tex();
	d1_tempT[25] = new tex();
	d1_tempT[26] = new tex();

	//type 3 buildings textures
	d1_tempT[5] = new tex();
	d1_tempT[8] = new tex();
	d1_tempT[11] = new tex();
	d1_tempT[18] = new tex();
	d1_tempT[22] = new tex();
	d1_tempT[24] = new tex();
	

	///extra
	
	
	//d1_tempT[29] = new tex();
	//d1_tempT[30] = new tex();
	//d1_tempT[31] = new tex();
	//d1_tempT[32] = new tex();
	//d1_tempT[33] = new tex();
	//d1_tempT[34] = new tex();
	//d1_tempT[35] = new tex();



	//for the level's normal map
	tex *d1_tempN[50];

		//ground texture
	d1_tempN[0] = new tex();

	//walls
	d1_tempN[6] = new tex();

	//fountain base
	d1_tempN[13] = new tex();

	//fountain water
	d1_tempN[14] = new tex();

	//foot bridge
	d1_tempN[16] = new tex();

	//light fixtures
	d1_tempN[28] = new tex();

	//mission buildings textures
	//apartments texture
	d1_tempN[1] = new tex();
	//bar texture
	d1_tempN[2] = new tex();
	//club texture
	d1_tempN[3] = new tex();


	//type 1 building textures
	d1_tempN[4] = new tex();
	d1_tempN[10] = new tex();
	d1_tempN[15] = new tex();
	d1_tempN[17] = new tex();
	d1_tempN[21] = new tex();
	d1_tempN[23] = new tex();
	d1_tempN[27] = new tex();

	//type 2 buildings textures
	d1_tempN[7] = new tex();
	d1_tempN[9] = new tex();
	d1_tempN[12] = new tex();
	d1_tempN[19] = new tex();
	d1_tempN[20] = new tex();
	d1_tempN[25] = new tex();
	d1_tempN[26] = new tex();

	//type 3 buildings textures
	d1_tempN[5] = new tex();
	d1_tempN[8] = new tex();
	d1_tempN[11] = new tex();
	d1_tempN[18] = new tex();
	d1_tempN[22] = new tex();
	d1_tempN[24] = new tex();





	//load the level's obj model and texture

	//ground
	d1_tempM[0]->LoadOBJ("Models/Levels/Level1/District1/Red_Light_Ground.obj", 8);
	d1_tempT[0]->loadTex("Images/Levels/Level1/District1/Red_Light_Ground.jpg");
	d1_tempN[0]->loadTex("Images/NormalMaps/District1/Red_Light_Ground_NormalMapV2_NRM.jpg");

	d1_tempM[29]->LoadOBJ("Models/Levels/Level1/District1/Red_Light_Ground1.obj", 8);
	d1_tempT[29]->loadTex("Images/Levels/Level1/District1/Red_Light_Ground1.jpg");
	d1_tempN[29] = d1_tempN[0];

	d1_tempM[30]->LoadOBJ("Models/Levels/Level1/District1/Red_Light_Ground2.obj", 8);
	d1_tempT[30]->loadTex("Images/Levels/Level1/District1/Red_Light_Ground2.jpg");
	d1_tempN[30] = d1_tempN[0];

	d1_tempM[31]->LoadOBJ("Models/Levels/Level1/District1/Red_Light_Ground3.obj", 8);
	d1_tempT[31]->loadTex("Images/Levels/Level1/District1/Red_Light_Ground3.jpg");
	d1_tempN[31] = d1_tempN[0];

	//walls
	d1_tempM[6]->LoadOBJ("Models/Levels/Level1/District1/Walls.obj", 24);
	d1_tempT[6]->loadTex("Images/Levels/Level1/District1/baked-Walls.jpg");
	d1_tempN[6]->loadTex("Images/NormalMaps/District1/Red_Light_Walls_NRM.jpg");

	//fountain base
	d1_tempM[13]->LoadOBJ("Models/Levels/Level1/District1/FountainBase.obj", 456);
	d1_tempT[13]->loadTex("Images/Levels/Level1/District1/baked-FountainBase.jpg");
	d1_tempN[13]->loadTex("Images/NormalMaps/District1/Fountain_Texture_NRM.jpg");

	//fountain water
	d1_tempM[14]->LoadOBJ("Models/Levels/Level1/District1/FountainWater.obj", 450);
	d1_tempT[14]->loadTex("Images/Levels/Level1/District1/baked-FountainWater.jpg");
	d1_tempN[14]->loadTex("Images/NormalMaps/District1/Fountain_Texture_NRM.jpg");

	//foot bridge
	d1_tempM[16]->LoadOBJ("Models/Levels/Level1/District1/Foot_Bridge.obj", 8);
	d1_tempT[16]->loadTex("Images/Levels/Level1/District1/baked-Foot_Bridge.jpg");
	d1_tempN[16]->loadTex("Images/NormalMaps/District1/Bridge_Texture_NRM.jpg");

	//light fixtures
	d1_tempM[28]->LoadOBJ("Models/Levels/Level1/District1/Light_Fixtures.obj", 1184);
	d1_tempT[28]->loadTex("Images/Levels/Level1/District1/baked-Light_Fixtures.jpg");
	d1_tempN[28]->loadTex("Images/NormalMaps/District1/black_metal_NRM.jpg");



	//mission buildings
	//apartments
	d1_tempM[1]->LoadOBJ("Models/Levels/Level1/District1/Apartments.obj", 155);
	d1_tempT[1]->loadTex("Images/Levels/Level1/District1/baked-Apartments.jpg");
	d1_tempN[1]->loadTex("Images/NormalMaps/District1/ApartmentExterior_NRM.jpg");

	//bar
	d1_tempM[2]->LoadOBJ("Models/Levels/Level1/District1/GrimBar.obj", 258);
	d1_tempT[2]->loadTex("Images/Levels/Level1/District1/baked-GrimBar.jpg");
	d1_tempN[2]->loadTex("Images/NormalMaps/District1/ApartmentExterior_NRM.jpg"); //*********

	//club
	d1_tempM[3]->LoadOBJ("Models/Levels/Level1/District1/DragonClub.obj", 108);
	d1_tempT[3]->loadTex("Images/Levels/Level1/District1/baked-DragonClub.jpg");
	d1_tempN[3]->loadTex("Images/NormalMaps/District1/ClubExterior_NRM.jpg"); 


	//type 1 buildings
	d1_tempM[4]->LoadOBJ("Models/Levels/Level1/District1/Building1_T1.obj", 38);
	d1_tempT[4]->loadTex("Images/Levels/Level1/District1/baked-Building1_T1.jpg");
	d1_tempN[4]->loadTex("Images/NormalMaps/District1/Building1_Type1_NRM.jpg"); 

	d1_tempM[10]->LoadOBJ("Models/Levels/Level1/District1/Building3_T1.obj", 22);
	d1_tempT[10]->loadTex("Images/Levels/Level1/District1/baked-Building3_T1.jpg");
	d1_tempN[10]->loadTex("Images/NormalMaps/District1/Building3_Type1_NRM.jpg"); 

	d1_tempM[15]->LoadOBJ("Models/Levels/Level1/District1/Building10_T1.obj", 38);
	d1_tempT[15]->loadTex("Images/Levels/Level1/District1/baked-Building10_T1.jpg");
	d1_tempN[15]->loadTex("Images/NormalMaps/District1/Building10_Type1_NRM.jpg");

	d1_tempM[17]->LoadOBJ("Models/Levels/Level1/District1/Building34_T1.obj", 44);
	d1_tempT[17]->loadTex("Images/Levels/Level1/District1/baked-Building34_T1.jpg");
	d1_tempN[17]->loadTex("Images/NormalMaps/District1/Building34_Type1_NRM.jpg");

	d1_tempM[21]->LoadOBJ("Models/Levels/Level1/District1/Building6_T1.obj", 18);
	d1_tempT[21]->loadTex("Images/Levels/Level1/District1/baked-Building6_T1.jpg");
	d1_tempN[21]->loadTex("Images/NormalMaps/District1/Building6_Type1_NRM.jpg");

	d1_tempM[23]->LoadOBJ("Models/Levels/Level1/District1/Building18_T1.obj", 34);
	d1_tempT[23]->loadTex("Images/Levels/Level1/District1/baked-Building18_T1.jpg");
	d1_tempN[23]->loadTex("Images/NormalMaps/District1/Building18_Type1_NRM.jpg");

	d1_tempM[27]->LoadOBJ("Models/Levels/Level1/District1/Building21_T1.obj", 12);
	d1_tempT[27]->loadTex("Images/Levels/Level1/District1/baked-Building21_T1.jpg");
	d1_tempN[27]->loadTex("Images/NormalMaps/District1/Building21_Type1_NRM.jpg");



	//type 2 buildings
	d1_tempM[7]->LoadOBJ("Models/Levels/Level1/District1/Building14_T2.obj", 44);
	d1_tempT[7]->loadTex("Images/Levels/Level1/District1/baked-Building14_T2.jpg");
	d1_tempN[7]->loadTex("Images/NormalMaps/District1/Building14_Type2_NRM.jpg");

	d1_tempM[9]->LoadOBJ("Models/Levels/Level1/District1/Building31_T2.obj", 54);
	d1_tempT[9]->loadTex("Images/Levels/Level1/District1/baked-Building31_T2.jpg");
	d1_tempN[9]->loadTex("Images/NormalMaps/District1/Building31_Type2_NRM.jpg");

	d1_tempM[12]->LoadOBJ("Models/Levels/Level1/District1/Building4_T2.obj", 26);
	d1_tempT[12]->loadTex("Images/Levels/Level1/District1/baked-Building4_T2.jpg");
	d1_tempN[12]->loadTex("Images/NormalMaps/District1/Building4_Type2_NRM.jpg");

	d1_tempM[19]->LoadOBJ("Models/Levels/Level1/District1/Building23_T2.obj", 14);
	d1_tempT[19]->loadTex("Images/Levels/Level1/District1/baked-Building23_T2.jpg");
	d1_tempN[19]->loadTex("Images/NormalMaps/District1/Building23_Type2_NRM.jpg");

	d1_tempM[20]->LoadOBJ("Models/Levels/Level1/District1/Building32_T2.obj", 24);
	d1_tempT[20]->loadTex("Images/Levels/Level1/District1/baked-Building32_T2.jpg");
	d1_tempN[20]->loadTex("Images/NormalMaps/District1/Building32_Type2_NRM.jpg");

	d1_tempM[25]->LoadOBJ("Models/Levels/Level1/District1/Building33_T2.obj", 30);
	d1_tempT[25]->loadTex("Images/Levels/Level1/District1/baked-Building33_T2.jpg");
	d1_tempN[25]->loadTex("Images/NormalMaps/District1/Building33_Type2_NRM.jpg");

	d1_tempM[26]->LoadOBJ("Models/Levels/Level1/District1/Building26_T2.obj", 90);
	d1_tempT[26]->loadTex("Images/Levels/Level1/District1/baked-Building26_T2.jpg");
	d1_tempN[26]->loadTex("Images/NormalMaps/District1/Building26_Type2_NRM.jpg");


	//type 3 buildings
	d1_tempM[5]->LoadOBJ("Models/Levels/Level1/District1/Building13_T3.obj", 22);
	d1_tempT[5]->loadTex("Images/Levels/Level1/District1/baked-Building13_T3.jpg");
	d1_tempN[5]->loadTex("Images/NormalMaps/District1/Building13_Type3_NRM.jpg");

	d1_tempM[8]->LoadOBJ("Models/Levels/Level1/District1/Building30_T3.obj", 36);
	d1_tempT[8]->loadTex("Images/Levels/Level1/District1/baked-Building30_T3.jpg");
	d1_tempN[8]->loadTex("Images/NormalMaps/District1/Building30_Type3_NRM.jpg");

	d1_tempM[11]->LoadOBJ("Models/Levels/Level1/District1/Building12_T3.obj", 34);
	d1_tempT[11]->loadTex("Images/Levels/Level1/District1/baked-Building12_T3.jpg");
	d1_tempN[11]->loadTex("Images/NormalMaps/District1/Building12_Type3_NRM.jpg");

	d1_tempM[18]->LoadOBJ("Models/Levels/Level1/District1/Building27_T3.obj", 556);
	d1_tempT[18]->loadTex("Images/Levels/Level1/District1/baked-Building27_T3.jpg");
	d1_tempN[18]->loadTex("Images/NormalMaps/District1/ApartmentExterior_NRM.jpg");

	d1_tempM[22]->LoadOBJ("Models/Levels/Level1/District1/Building22_T3.obj", 18);
	d1_tempT[22]->loadTex("Images/Levels/Level1/District1/baked-Building22_T3.jpg");
	d1_tempN[22]->loadTex("Images/NormalMaps/District1/Building22_Type3_NRM.jpg");

	d1_tempM[24]->LoadOBJ("Models/Levels/Level1/District1/Building29_T3.obj", 30);
	d1_tempT[24]->loadTex("Images/Levels/Level1/District1/baked-Building29_T3.jpg");
	d1_tempN[24]->loadTex("Images/NormalMaps/District1/Building29_Type3_NRM.jpg");
	

	
	///extra
	//
	//d1_tempM[29]->LoadOBJ("Models/Levels/Level1/Building13_T3.obj", 22);
	//d1_tempT[29]->loadTex("Images/Levels/Level1/baked-Building13_T3.jpg");
	//
	//d1_tempM[30]->LoadOBJ("Models/Levels/Level1/Building13_T3.obj", 22);
	//d1_tempT[30]->loadTex("Images/Levels/Level1/baked-Building13_T3.jpg");
	//
	//d1_tempM[31]->LoadOBJ("Models/Levels/Level1/Building13_T3.obj", 22);
	//d1_tempT[31]->loadTex("Images/Levels/Level1/baked-Building13_T3.jpg");
	//
	//d1_tempM[32]->LoadOBJ("Models/Levels/Level1/Building13_T3.obj", 22);
	//d1_tempT[32]->loadTex("Images/Levels/Level1/baked-Building13_T3.jpg");
	//
	//d1_tempM[33]->LoadOBJ("Models/Levels/Level1/Building13_T3.obj", 22);
	//d1_tempT[33]->loadTex("Images/Levels/Level1/baked-Building13_T3.jpg");
	//
	//d1_tempM[34]->LoadOBJ("Models/Levels/Level1/Building13_T3.obj", 22);
	//d1_tempT[34]->loadTex("Images/Levels/Level1/baked-Building13_T3.jpg");
	//
	//d1_tempM[35]->LoadOBJ("Models/Levels/Level1/Building13_T3.obj", 22);
	//d1_tempT[35]->loadTex("Images/Levels/Level1/baked-Building13_T3.jpg");



	//Change the current players position to the start of the level
	//player->position =  player->startingPosition = Vec3f(520.f * 0.6  * 3.0, 0.0, 290.f * 0.6 * 3.0);
	
	
	gameLevel.district[0].sectionModels.push_back(d1_tempM[0]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[0]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[0]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[1]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[1]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[1]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[2]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[2]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[2]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[3]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[3]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[3]);
	
	gameLevel.district[0].sectionModels.push_back(d1_tempM[4]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[4]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[4]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[5]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[5]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[5]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[6]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[6]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[6]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[7]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[7]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[7]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[8]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[8]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[8]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[9]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[9]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[9]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[10]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[10]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[10]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[11]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[11]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[11]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[12]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[12]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[12]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[13]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[13]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[13]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[14]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[14]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[14]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[15]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[15]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[15]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[16]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[16]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[16]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[17]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[17]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[17]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[18]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[18]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[18]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[19]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[19]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[19]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[20]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[20]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[20]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[21]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[21]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[21]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[22]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[22]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[22]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[23]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[23]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[23]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[24]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[24]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[24]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[25]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[25]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[25]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[26]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[26]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[26]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[27]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[27]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[27]);
	
	gameLevel.district[0].sectionModels.push_back(d1_tempM[28]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[28]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[28]);

	gameLevel.district[0].sectionModels.push_back(d1_tempM[29]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[29]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[29]);
 
	gameLevel.district[0].sectionModels.push_back(d1_tempM[30]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[30]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[30]);
 
	gameLevel.district[0].sectionModels.push_back(d1_tempM[31]);
	gameLevel.district[0].sectionTexs.push_back(d1_tempT[31]);
	gameLevel.district[0].sectionNormalMaps.push_back(d1_tempN[31]);

	//
	//gameLevel.district[0].sectionModels.push_back(d1_tempM[29]);
	//gameLevel.district[0].sectionTexs.push_back(d1_tempT[29]);
	//
	//gameLevel.district[0].sectionModels.push_back(d1_tempM[30]);
	//gameLevel.district[0].sectionTexs.push_back(d1_tempT[30]);
	//
	//gameLevel.district[0].sectionModels.push_back(d1_tempM[31]);
	//gameLevel.district[0].sectionTexs.push_back(d1_tempT[31]);
	//
	//gameLevel.district[0].sectionModels.push_back(d1_tempM[32]);
	//gameLevel.district[0].sectionTexs.push_back(d1_tempT[32]);
	//
	//gameLevel.district[0].sectionModels.push_back(d1_tempM[33]);
	//gameLevel.district[0].sectionTexs.push_back(d1_tempT[33]);
	//
	//gameLevel.district[0].sectionModels.push_back(d1_tempM[34]);
	//gameLevel.district[0].sectionTexs.push_back(d1_tempT[34]);
	//
	//gameLevel.district[0].sectionModels.push_back(d1_tempM[35]);
	//gameLevel.district[0].sectionTexs.push_back(d1_tempT[35]);

//**************Other areas********************//
	toNextArea *d1_areas[10];
	collisionObject *d1_collisionZones[10];

	d1_collisionZones[0] = new collisionObject(10.0f, Vec3f(276.0f, 0.0f, 210.0f), 0.0f, false);
	d1_areas[0] = new toNextArea(d1_collisionZones[0], Vec3f(206, 0, 115),false, 0);
	gameLevel.district[0].Areas.push_back(d1_areas[0]);

	//for going to the bar
	d1_collisionZones[1] = new collisionObject(10.0f, Vec3f(272.0f, 0.0f, 436.0f), 0.0f, false);
	d1_areas[1] = new toNextArea(d1_collisionZones[1], Vec3f(28.0f, 0.0f, 155.0f),false, 1);
	gameLevel.district[0].Areas.push_back(d1_areas[1]);




////**********DISTRICT pathfinding**********************////
	//must generate the squares/nodes that the graph will use (the graph itself)
	//gameLevel.district[0].AIPath.gameLevel->generateGraph(Vec3f(0,-8,0), Vec3f(2,-8 ,0), Vec3f(2 ,-8  ,2 ), Vec3f(0 ,-8, 2), 237, 82);
	gameLevel.district[0].levelCollisionMap = new levelGraph();
	gameLevel.district[0].levelCollisionMap->generateGraph(Vec3f(0,0,0), Vec3f(2,0 ,0), Vec3f(2, 0  ,2 ), Vec3f(0 ,0, 2), 408, 304);

	//load the collision map to fill in the infomation of the graph
	//gameLevel.district[0].collisionMask = collisionObject("Images/Levels/Level1/Section1_V5_CollisionMap.jpg", Vec3f(0.f,0.f,0.f),0.f, 3.0f, 3.0f);
	gameLevel.district[0].collisionMask = collisionObject("Images/Levels/Level1/District1/RedLight_CollisionMapV3.jpg", Vec3f(0.f,0.f,0.f),0.f, 3.0f, 3.0f, Vec3f(0.725f, 0.0, 0.725f));
	gameLevel.district[0].collisionList.push_back(&gameLevel.district[0].collisionMask);
	
	
	gameLevel.district[0].levelCollisionMap->loadLevelGraph(&gameLevel.district[0].collisionMask);

	//**********CLUB pathfinding**********************////
	//must generate the squares/nodes that the graph will use (the graph itself)
	//gameLevel.interior[0].AIPath.gameLevel->generateGraph(Vec3f(0,-8,0), Vec3f(2,-8 ,0), Vec3f(2 ,-8  ,2 ), Vec3f(0 ,-8, 2), 237, 82);
	gameLevel.interior[0].levelCollisionMap = new levelGraph();
	gameLevel.interior[0].levelCollisionMap->generateGraph(Vec3f(0,0,0), Vec3f(2,0 ,0), Vec3f(2 ,0  ,2 ), Vec3f(0 ,0, 2), 356, 356); //179, 174

	//load the collision map to fill in the infomation of the graph
	//gameLevel.district[0].collisionMask = collisionObject("Images/Levels/Level1/Section1_V5_CollisionMap.jpg", Vec3f(0.f,0.f,0.f),0.f, 3.0f, 3.0f);
	//gameLevel.interior[0].collisionMask = collisionObject("Images/Levels/Level1/Interior1/Dragon_Club_CollisionMaskv1.jpg", Vec3f(0.f,0.f,0.f),0.f, 1.0f, 1.0f, Vec3f(0.645f, 0.0, 0.645f));
	gameLevel.interior[0].collisionMask = collisionObject("Images/Levels/Level1/Interior1/Dragon_Club_CollisionMaskv1.jpg", Vec3f(0.f,0.f,0.f),0.f, 3.0f, 3.0f, Vec3f(0.217f, 0.0, 0.217f)); //0.215 // 0.217
	gameLevel.interior[0].collisionList.push_back(&gameLevel.interior[0].collisionMask);
	
	
	gameLevel.interior[0].levelCollisionMap->loadLevelGraph(&gameLevel.interior[0].collisionMask);

	////**********BAR pathfinding**********************////
	//must generate the squares/nodes that the graph will use (the graph itself)
	gameLevel.interior[1].levelCollisionMap = new levelGraph();
	//gameLevel.interior[1].levelCollisionMap->generateGraph(Vec3f(0,0,0), Vec3f(2,0 ,0), Vec3f(2, 0  ,2 ), Vec3f(0 ,0, 2), 432, 269);
	gameLevel.interior[1].levelCollisionMap->generateGraph(Vec3f(0,0,0), Vec3f(2,0 ,0), Vec3f(2, 0  ,2 ), Vec3f(0 ,0, 2), 432, 269); //427 264

	//load the collision map to fill in the infomation of the graph
	gameLevel.interior[1].collisionMask = collisionObject("Images/Levels/Level1/Interior2/Grim_Bar_CollisionMaskV1.jpg", Vec3f(0.f,0.f,0.f),0.f, 3.0f, 3.0f, Vec3f(0.233f, 0.0, 0.233f));
	gameLevel.interior[1].collisionList.push_back(&gameLevel.interior[1].collisionMask);
	
	
	gameLevel.interior[1].levelCollisionMap->loadLevelGraph(&gameLevel.interior[1].collisionMask);



//******************NPC**********************************//
//	////////////////////NPC//////////////////////////////
//	//Set up the NPC's
//	//const static int npcAmount = 20;
	regularNPC* NPC;
	tex *gang1Texture;
	objLoader NPCModel;
	tex *civilianTexture[3];
	char* gang1Model1;

	gang1Texture = new tex();
	civilianTexture[0] = new tex();
	civilianTexture[1] = new tex();
	civilianTexture[2] = new tex();
	gang1Texture->loadTex("Images/Characters/gang1Boundv2.jpg");
	civilianTexture[0]->loadTex("Images/Characters/civilian1Texture.jpg");
	civilianTexture[1]->loadTex("Images/Characters/civilian2Texture.jpg");
	civilianTexture[2]->loadTex("Images/Characters/civilian3Texture.jpg");
	gang1Model1 = "Models/Characters/NPCs/gang1.obj";
	int polyCountGang1 = 3858;

	//npc animations
	morph NPCIdle;
	morph NPCWalking;
	morph NPCDying;
	morph NPCShooting;
	morph NPCScared;

	//idle
	NPCIdle.addKeyFrame("Animations/NPC/Idle/idle1.obj", polyCountGang1);
	NPCIdle.addKeyFrame("Animations/NPC/Idle/idle2.obj", polyCountGang1);
	NPCIdle.addKeyFrame("Animations/NPC/Idle/idle3.obj", polyCountGang1);
	NPCIdle.addKeyFrame("Animations/NPC/Idle/idle4.obj", polyCountGang1);
	NPCIdle.addKeyFrame("Animations/NPC/Idle/idle5.obj", polyCountGang1);
	NPCIdle.addKeyFrame("Animations/NPC/Idle/idle6.obj", polyCountGang1);
	NPCIdle.addKeyFrame("Animations/NPC/Idle/idle7.obj", polyCountGang1);

	//walking
	NPCWalking.addKeyFrame("Animations/NPC/Walking/walk.obj", polyCountGang1);
	NPCWalking.addKeyFrame("Animations/NPC/Walking/walk2.obj", polyCountGang1);
	NPCWalking.addKeyFrame("Animations/NPC/Walking/walk3.obj", polyCountGang1);
	NPCWalking.addKeyFrame("Animations/NPC/Walking/walk4.obj", polyCountGang1);
	NPCWalking.addKeyFrame("Animations/NPC/Walking/walk5.obj", polyCountGang1);

	//Dying
	NPCDying.addKeyFrame("Animations/NPC/Dying/dying1.obj", polyCountGang1);
	NPCDying.addKeyFrame("Animations/NPC/Dying/dying2.obj", polyCountGang1);
	NPCDying.addKeyFrame("Animations/NPC/Dying/dying3.obj", polyCountGang1);
	NPCDying.addKeyFrame("Animations/NPC/Dying/dying4.obj", polyCountGang1);
	NPCDying.addKeyFrame("Animations/NPC/Dying/dying5.obj", polyCountGang1);
	NPCDying.addKeyFrame("Animations/NPC/Dying/dying6.obj", polyCountGang1);
	NPCDying.loop = false;

	//shooting
	NPCShooting.addKeyFrame("Animations/NPC/Shooting/shoot1.obj", polyCountGang1);
	NPCShooting.addKeyFrame("Animations/NPC/Shooting/shoot2.obj", polyCountGang1);
	NPCShooting.addKeyFrame("Animations/NPC/Shooting/shoot3.obj", polyCountGang1);
	NPCShooting.addKeyFrame("Animations/NPC/Shooting/shoot4.obj", polyCountGang1);

	//scared
	NPCScared.addKeyFrame("Animations/NPC/Scared/scared1.obj", polyCountGang1);
	NPCScared.addKeyFrame("Animations/NPC/Scared/scared2.obj", polyCountGang1);
	NPCScared.addKeyFrame("Animations/NPC/Scared/scared3.obj", polyCountGang1);
	NPCScared.addKeyFrame("Animations/NPC/Scared/scared4.obj", polyCountGang1);
	NPCScared.addKeyFrame("Animations/NPC/Scared/scared5.obj", polyCountGang1);


//

/////////District Civilians
//civ 1     the wanderer
NPC =  new regularNPC(true, 100,0,6,false,Vec3f(240,0,335),false,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(240,0,335), 1, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(240,0,390), 1, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(100,0,390), 1, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(100,0,245), 1, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(64,0,245), 1, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(62,0,158), 1, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(244,0,158), 1, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(244,0,252), 1, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(222,0,252), 1, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(222,0,335), 1, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(240,0,335), 1, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking; 
NPC->animations.Death = NPCDying;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Scared = NPCScared; 
gameLevel.district[0].NPCList.push_back(NPC);

//civ 2     middle crowd - white clothed
NPC =  new regularNPC(true, 100,0,6,false,Vec3f(166,0,164),false,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(166,0,164), 3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

//civ 3     middle crowd - purple clothed
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(159,0,172),false,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(159,0,172), 3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

//civ 4     middle crowd - red clothed
NPC =  new regularNPC(true, 100,-100,6,false,Vec3f(170,0,175),false,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(170,0,175), 3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

//civ 5     top left civilian - Drava
NPC =  new regularNPC(true, 100,0,6,false,Vec3f(70,0,43),false,false,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(70,0,43), 3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

//civ 6     top left civilians 
NPC =  new regularNPC(true, 100,-135,6,false,Vec3f(76,0,74),false,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(78,0,70), 3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

/// top left civilian
NPC =  new regularNPC(true, 100,-45,6,false,Vec3f(78,0,67),false,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(78,0,67), 3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

//civ 7     top left crowd 
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(73,0,67),false,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(73,0,67), 3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

//civ 8     southwest (bottom left) crowd (red outfit)
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(66,0,370),false,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(66,0,370), 3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

//civ 9     soutwest (bottom left) crowd (white outfit)
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(75,0,370),false,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(75,0,370), 3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

//civ 10     pair of civs south of Apartments (purple outfit)
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(232,0,315),false,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(232,0,315), 3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

//civ 11     pair of civs south of Apartments (white outfit)
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(242,0,315),false,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(242,0,7315), 3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

//civ 12     just outside of Grim Bar (red outfit)
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(130,0,225),false,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(civilianTexture[0],gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(136,0,225), 3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

//civ 13     just outside of Grim Bar (white outfit)
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(125,0,225),false,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(civilianTexture[1],gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(125,0,225), 3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

//civ 14     just outside of Apartments (purple outfit)
NPC =  new regularNPC(true, 100,45,6,false,Vec3f(200,0,235),false,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(200,0,235), 3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Death = NPCDying;
NPC->animations.Walking = NPCWalking;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

//civ 15     just outside of Apartments (red outfit)
NPC =  new regularNPC(true, 100,-135,6,false,Vec3f(204,0,238),false,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(234,0,238), 3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);



///////****Civilians in Dragon Club
/////Bartender (can attack player)
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(114,0,188),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(114,0,188), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

////DJ
NPC =  new regularNPC(true, 100,0,6,false,Vec3f(210,10,30),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(210,0,30), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

////Bartender 2
NPC =  new regularNPC(true, 100,100,6,false,Vec3f(107,0,138),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(107,0,138), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPC 1 in men's room
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(25,0,77),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(25,0,77), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPC 2 in men's room
NPC =  new regularNPC(true, 100,0,6,false,Vec3f(21,0,115),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(21,0,115), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

//NPCs near Stand Tables
///NPC 1 - Top left stand tables
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(169,0,28),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(169,0,28), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPC 2 
NPC =  new regularNPC(true, 100,180,6,false,Vec3f(153,0,40),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(153,0,40), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPC 3 
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(135,0,29),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(135,0,29), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPC 4
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(104,0,29),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(104,0,29), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPCs near top right stand tables
///NPC 1
NPC =  new regularNPC(true, 100,-10,6,false,Vec3f(322,0,34),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(322,0,34), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPC 2
NPC =  new regularNPC(true, 100,100,6,false,Vec3f(309,0,47),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(309,0,47), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPC 3
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(315,0,85),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(315,0,85), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPC 4
NPC =  new regularNPC(true, 100,180,6,false,Vec3f(301,0,99),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(301,0,99), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///Dance floor crowds
//Top left of dance floor
///NPC 1
NPC =  new regularNPC(true, 100,180,6,false,Vec3f(177,0,105),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(177,0,105), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPC 2
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(190,0,115),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(190,0,115), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPC 3
NPC =  new regularNPC(true, 100,135,6,false,Vec3f(171,0,123),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(171,0,123), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPC 4
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(161,0,113),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(161,0,113), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);


//middle right of dance floor (near main door)
///NPC 1
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(260,0,173),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(260,0,173), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPC 2
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(242,0,175),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(242,0,175), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPC 3
NPC =  new regularNPC(true, 100,180,6,false,Vec3f(252,0,193),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(252,0,193), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);


///bottom middle crowd
///NPC 1
NPC =  new regularNPC(true, 100,0,6,false,Vec3f(212,0,215),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(212,0,215), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPC 2
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(229,0,220),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(229,0,220), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPC 3
NPC =  new regularNPC(true, 100,180,6,false,Vec3f(216,0,230),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(216,0,230), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);


///near bottom tables
//left bottom table
///NPC 1
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(103,0,299),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(103,0,299), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPC 2
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(117,0,300),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(117,0,300), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPC 3
NPC =  new regularNPC(true, 100,-45,6,false,Vec3f(142,0,307),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(142,0,307), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPC 3
NPC =  new regularNPC(true, 100,0,6,false,Vec3f(125,0,307),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(125,0,307), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

//middle left table
///NPC 1
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(174,0,307),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(174,0,307), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPC 2
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(187,0,306),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(187,0,306), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///bottom right table
///NPC 1
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(336,0,303),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(336,0,303), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPC 2
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(325,0,303),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(325,0,303), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

////middle right table
///NPC 1
NPC =  new regularNPC(true, 100,45,6,false,Vec3f(231,0,297),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(231,0,297), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///NPC 2
NPC =  new regularNPC(true, 100,-135,6,false,Vec3f(242,0,307),false,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(242,0,307), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);




//////////****Civilians in Grim Bar

//*//bartender 1
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(247,0,255),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(247,0,255), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///bartender 2
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(244,0,323),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(244,0,323), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///bartender 3
NPC =  new regularNPC(true, 100,0,6,false,Vec3f(190,0,210),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(190,0,210), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///bartender 4
NPC =  new regularNPC(true, 100,0,6,false,Vec3f(131,0,210),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(131,0,210), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///bartender 5
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(243,0,280),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(243,0,280), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);


///civies around bar area
///civ 1
NPC =  new regularNPC(true, 100,45,6,false,Vec3f(226,0,363),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(226,0,263), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 2
NPC =  new regularNPC(true, 100,-135,6,false,Vec3f(236,0,379),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(236,0,279), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 3
NPC =  new regularNPC(true, 100,180,6,false,Vec3f(256,0,379),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(256,0,379), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 4
NPC =  new regularNPC(true, 100,180,6,false,Vec3f(256,0,379),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(256,0,379), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 5
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(219,0,330),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(219,0,330), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 6
NPC =  new regularNPC(true, 100,180,6,false,Vec3f(218,0,299),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(218,0,299), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 7
NPC =  new regularNPC(true, 100,0,6,false,Vec3f(218,0,288),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(218,0,288), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 8
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(224,0,252),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(224,0,252), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 9
NPC =  new regularNPC(true, 100,45,6,false,Vec3f(216,0,245),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(216,0,245), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 10
NPC =  new regularNPC(true, 100,180,6,false,Vec3f(222,0,228),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(222,0,228), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 11
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(207,0,292),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(207,0,292), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 12
NPC =  new regularNPC(true, 100,45,6,false,Vec3f(144,0,236),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(144,0,236), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 13
NPC =  new regularNPC(true, 100,-135,6,false,Vec3f(155,0,243),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(155,0,243), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 14
NPC =  new regularNPC(true, 100,180,6,false,Vec3f(122,0,236),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(122,0,236), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);


//middle/dining area civies

//crowd near doors
///civ 1
NPC =  new regularNPC(true, 100,0,6,false,Vec3f(80,0,275),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(80,0,275), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 2
NPC =  new regularNPC(true, 100,180,6,false,Vec3f(85,0,287),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(85,0,287), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 3
NPC =  new regularNPC(true, 100,-45,6,false,Vec3f(93,0,276),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(93,0,276), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);


///crowd in middle of dining area
///civ 1
NPC =  new regularNPC(true, 100,45,6,false,Vec3f(120,0,339),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(120,0,339), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 2
NPC =  new regularNPC(true, 100,-135,6,false,Vec3f(126,0,347),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(126,0,347), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 3
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(130,0,359),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(130,0,359), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 4
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(144,0,360),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(144,0,360), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);


//crowd near bottom
///civ 1
NPC =  new regularNPC(true, 100,0,6,false,Vec3f(175,0,402),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(175,0,402), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 2
NPC =  new regularNPC(true, 100,-135,6,false,Vec3f(183,0,414),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(183,0,414), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 3
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(165,0,413),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(165,0,413), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);



///crowd near bottom window
///civ 1
NPC =  new regularNPC(true, 100,180,6,false,Vec3f(21,0,362),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(21,0,362), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 2
NPC =  new regularNPC(true, 100,0,6,false,Vec3f(22,0,350),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(22,0,350), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 3
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(20,0,315),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(20,0,315), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);



////crowd in lounge area
///civ 1
NPC =  new regularNPC(true, 100,180,6,false,Vec3f(37,0,67),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(37,0,67), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 2
NPC =  new regularNPC(true, 100,180,6,false,Vec3f(45,0,75),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(45,0,75), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 3
NPC =  new regularNPC(true, 100,135,6,false,Vec3f(31,0,75),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(31,0,75), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 4
NPC =  new regularNPC(true, 100,180,6,false,Vec3f(52,0,153),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[2], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(52,0,153), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 5
NPC =  new regularNPC(true, 100,0,6,false,Vec3f(20,0,92),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(20,0,92), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 6
NPC =  new regularNPC(true, 100,180,6,false,Vec3f(20,0,105),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(20,0,105), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);


///kitchen staff
///civ 1
NPC =  new regularNPC(true, 100,0,6,false,Vec3f(170,0,155),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(170,0,155), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 2
NPC =  new regularNPC(true, 100,0,6,false,Vec3f(220,0,153),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(220,0,153), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

///civ 3
NPC =  new regularNPC(true, 100,180,6,false,Vec3f(208,0,110),false,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(208,0,110), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);




//////----------------Enemies-----------------------//

//NPC 2     line left
NPC =  new regularNPC(true, 100,0,6,true,Vec3f(27,0,104),true,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(27,0,104), 3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(27,0,152), 3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

//NPC 3     northern box walk
NPC =  new regularNPC(true, 100,0,6,true,Vec3f(160,0,105),true,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(gang1Texture,gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(160,0,105),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(92,0,105),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(92,0,45),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(160,0,45),  3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

//NPC 4     stationary north 1 - outside Dragon Club
NPC =  new regularNPC(true, 100,0,6,false,Vec3f(115,0,100),true,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(115,0,95),  3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

//NPC 5     stationary north 2 - outside Dragon Club
NPC =  new regularNPC(true, 100,0,6,false,Vec3f(135,0,100),true,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(135,0,95), 3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

//NPC 6   north L-path  
NPC =  new regularNPC(true, 100,0,6,true,Vec3f(96,0,156),true,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(96,0,156),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(148,0,156), 3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(148,0,120), 3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(148,0,156), 3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(96,0,156), 3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

//NPC 7   east weird path  
NPC =  new regularNPC(true, 100,0,6,true,Vec3f(250,0,40),true,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(250,0,40),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(240,0,68),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(240,0,108),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(265,0,140),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(240,0,108),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(240,0,68),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(250,0,40),  3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

//NPC 8   north L-path   1
NPC =  new regularNPC(true, 100,0,6,true,Vec3f(55,0,166),true,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(55,0,166),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(55,0,238),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(22,0,238),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(55,0,238),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(55,0,166),  3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

//NPC 9   north L-path     2
NPC =  new regularNPC(true, 100,0,6,true,Vec3f(70,0,166),true,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(70,0,166),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(70,0,238),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(105,0,238),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(70,0,238),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(70,0,166),  3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);


//NPC 10   east l path     
NPC =  new regularNPC(true, 100,0,6,true,Vec3f(252,0,245),true,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(252,0,245),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(280,0,245),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(280,0,294),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(280,0,245),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(252,0,245),  3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

////Dragon Club Bouncers (will not attack unless provoked)
//Bouncer 1 -  near main doors
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(335,0,152),true,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(335,0,152), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

//Bouncer 2 -  near main doors
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(335,0,205),true,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(335,0,205), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

////Bouncer 3 -  near office (guarding club owner)
NPC =  new regularNPC(true, 100,180,6,false,Vec3f(67,0,255),true,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(67,0,255), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

////Bouncer 4 -  near entrance leading to back rooms
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(103,0,53),true,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(103,0,53), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

////Bouncer 5 -  near entry to behind bar
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(107,0,275),true,true,0.7, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(107,0,275), 3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

///****Grim bar bouncers
//bouncer 1 - near main doors
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(19,0,202),true,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(19,0,202), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

//bouncer 2 - near main doors
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(19,0,246),true,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(19,0,246), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

//bouncer 3 - just passed lounge area
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(90,0,85),true,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(90,0,85), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

//bouncer 4 - just passed lounge area
NPC =  new regularNPC(true, 100,90,6,false,Vec3f(90,0,114),true,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(90,0,114), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

//bouncer 5 - patrolling inner area
NPC =  new regularNPC(true, 100,180,6,false,Vec3f(114,0,160),true,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(114,0,160), 3, &gameLevel.interior[1].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(114,0,120), 3, &gameLevel.interior[1].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(114,0,80), 3, &gameLevel.interior[1].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(114,0,40), 3, &gameLevel.interior[1].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(114,0,80), 3, &gameLevel.interior[1].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(114,0,120), 3, &gameLevel.interior[1].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(114,0,160), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

//bouncer 6 - guarding office
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(177,0,37),true,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(177,0,37), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

//bouncer 7 - guarding office
NPC =  new regularNPC(true, 100,-90,6,false,Vec3f(177,0,65),true,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1 , polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(177,0,65), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Shooting = NPCShooting;
NPC->animations.Walking = NPCWalking;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);



////////////////////////////////////
////mission NPCs
//NPC 11   Cross     
NPC =  new regularNPC(true, 100,0,6,true,Vec3f(163,0,338),true,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(163,0,338),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(222,0,338),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(108,0,338),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(163,0,338),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(163,0,290),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(163,0,380),  3, &gameLevel.district[0].collisionMask);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(163,0,338),  3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Scared = NPCScared;
NPC->animations.Death = NPCDying;
gameLevel.district[0].NPCList.push_back(NPC);

missions->NPCsToKill.push_back(NPC); //ID 0


////Club owner NPC 
NPC =  new regularNPC(true, 100,0,6,false,Vec3f(40, 0.0f, 327),true,true,0.0, 75.0f, &gameLevel.interior[0].collisionMask);
NPC->loadCharacter(civilianTexture[0], gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(40, 0.0f, 327),  3, &gameLevel.interior[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[0].NPCList.push_back(NPC);

missions->NPCsToKill.push_back(NPC); //ID 1


//civ 16     lone civ east of Apartments (white outfit)
NPC =  new regularNPC(true, 100,-135,6,false,Vec3f(290,0,175),false,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(civilianTexture[1], gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(290,0,175), 3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

missions->NPCsToKill.push_back(NPC); //ID 2

//NPC 1     staying in spot. top left
NPC =  new regularNPC(true, 100,0,6,true,Vec3f(18,0,18),true,true,0.7, 75.0f, &gameLevel.district[0].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(18,0,18), 3, &gameLevel.district[0].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.district[0].NPCList.push_back(NPC);

missions->NPCsToKill.push_back(NPC); ///ID 3


//NPC    Grim Bar, Red Dragon Boss Imposter
NPC =  new regularNPC(true, 100,0,6,false,Vec3f(242,0,33),true,true,0.7, 75.0f, &gameLevel.interior[1].collisionMask);
NPC->loadCharacter(gang1Texture, gang1Model1, polyCountGang1);
NPC->cObject = collisionObject(5,NPC->position, NPC->speed, true);
NPC->aiPath.AddWaypointToEnd(sf::Vector3f(242,0,33), 3, &gameLevel.interior[1].collisionMask);
NPC->animations.Idle = NPCIdle; 
NPC->animations.Walking = NPCWalking;
NPC->animations.Shooting = NPCShooting;
NPC->animations.Death = NPCDying;
NPC->animations.Scared = NPCScared;
gameLevel.interior[1].NPCList.push_back(NPC);

missions->NPCsToKill.push_back(NPC); ///ID 4


//*************FOG************
	gameLevel.district[0].fogColor[0] = 0.0f;
	gameLevel.district[0].fogColor[1] = 0.1f;
	gameLevel.district[0].fogColor[2] = 0.2f;
	gameLevel.district[0].fogColor[3] = 1;

	gameLevel.district[0].fogStart = 0.0f;
	gameLevel.district[0].fogEnd = 1000.0f;

//***********LIGHTS*********************
	//ambient light
	//color {0.25, 0.25, 0.25}, also is the intensity of the light, fourth parameter is always one
	gameLevel.district[0].ambientLightColor[0] = 0.1f;
	gameLevel.district[0].ambientLightColor[1] = 0.1f;
	gameLevel.district[0].ambientLightColor[2] = 0.1f;
	gameLevel.district[0].ambientLightColor[3] = 1.0f;

	////directed light
	////color RGBA
	//gameLevel.district[0].directedLightColor[0] = 0.1f;
	//gameLevel.district[0].directedLightColor[1] = 0.1f;
	//gameLevel.district[0].directedLightColor[2] = 0.1f;
	//gameLevel.district[0].directedLightColor[3] = 1.0f;

	////Position first 3 variables are XYZ coordinates, the last variable is if it is a directed light (0) or positioned light (1)
	//gameLevel.district[0].directedLightPosition[0] = 4.0f;
	//gameLevel.district[0].directedLightPosition[1] = 1.0f;
	//gameLevel.district[0].directedLightPosition[2] = 8.0f;
	//gameLevel.district[0].directedLightPosition[3] = 0.0f;

//******Stores all of the districts point lights***///
	Light districtLights[50];

	//Light1
	//color: RGBA
	//Position: first 3 variables are XYZ coordinates, the last variable is if it is a directed light (0) or positioned light (1)
	//drawPoint: if we should render a point where the light it, so we can better visulize its position

	//orange spot lights in dark area
	districtLights[0] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(132.495f, 23.373f, 744.237f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[0]);

	districtLights[1] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(212.376f, 23.373f, 739.896f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[1]);

	districtLights[2] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(207.435f, 23.373f, 654.018f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[2]);

	districtLights[3] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(132.51f, 24.93f, 658.533f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[3]);

	districtLights[4] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(51.792f, 23.373f, 652.647f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[4]);

	districtLights[5] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(45.39f, 23.373f, 738.393f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[5]);

	districtLights[6] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(94.998, 23.373f, 587.319f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[6]);

	districtLights[7] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(101.541f, 23.373f, 500.517f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[7]);

	districtLights[8] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(101.214f, 23.373f, 433.815f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[8]);

	districtLights[9] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(101.067, 23.373f, 357.591f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[9]);

	//districtLights[10] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(180.459, 68.694f, 427.83f, 1.0f), true, false, 30.256f, 0.00095f, 0.0015f);
	//gameLevel.district[0].lights.push_back(districtLights[10]);

	//districtLights[11] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(221.229, 79.284f, 514.68f, 1.0f), true, false, 30.256f, 0.00095f, 0.0015f);
	//gameLevel.district[0].lights.push_back(districtLights[11]);

	districtLights[12] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(219.351f, 23.373f, 569.046f, 1.0f), true, false, 42.356f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[12]);

	/*districtLights[13] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(236.217f, 23.373f, 704.646f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[13]);*/

	//districtLights[14] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(231.939f, 23.373f, 772.218f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	//gameLevel.district[0].lights.push_back(districtLights[14]);

	//white light in center square
	districtLights[14] = Light(Vec4f(1.0f, 1.0f, 1.0f, 1.0f), Vec4f(257.61f, 33.435f, 405.603f, 1.0f), true, false, 49.919f, 0.0001f, 0.0002f);
	gameLevel.district[0].lights.push_back(districtLights[14]);

	//purple light in club door
	districtLights[15] = Light(Vec4f(0.918f, 0.270f, 1.0f, 1.0f), Vec4f(275.994f, 8.844f, 205.842f, 1.0f), true, false, 49.919f, 0.0001f, 0.0002f);
	gameLevel.district[0].lights.push_back(districtLights[15]);

	//dark corner beside club
	districtLights[16] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(499.056f, 23.373f, 69.906f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[16]);

	districtLights[17] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(601.608f, 23.373f, 125.07f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[17]);

	districtLights[18] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(491.139f, 23.373f, 145.95f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[18]);

	districtLights[19] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(518.418f, 23.373f, 290.622f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[19]);

	/*districtLights[20] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(516.654f, 23.373f, 240.777f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[20]);*/

	//districtLights[21] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(516.627f, 23.373f, 339.48f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	//gameLevel.district[0].lights.push_back(districtLights[21]);

	districtLights[22] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(576.804f, 23.373f, 419.037f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[22]);

	districtLights[23] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(576.555f, 23.373f, 507.234f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[23]);

	/*districtLights[24] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(512.907f, 23.373f, 571.98f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[24]);*/

	/*districtLights[25] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(476.145f, 23.373f, 622.107f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[25]);*/

	districtLights[26] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(401.187f, 23.373f, 622.371f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[26]);

	/*districtLights[27] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(571.455f, 23.373f, 677.166f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[27]);*/

	/*districtLights[28] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(594.981f, 23.373f, 618.375f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[28]);*/

	districtLights[29] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(612.228f, 23.373f, 676.779f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[29]);

	/*districtLights[30] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(481.755f, 23.373f, 711.375f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[30]);*/

	/*districtLights[31] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(404.814f, 23.373f, 712.189f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[31]);*/

	districtLights[32] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(485.301f, 23.373f, 831.837f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[32]);

	//court beside club (near drava)
	districtLights[33] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(103.041f, 23.373f, 157.728f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[33]);

	districtLights[34] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(205.983f, 23.373f, 92.151f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[34]);

	districtLights[35] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(132.774f, 23.373f, 91.239f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[35]);

	districtLights[36] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(187.044f, 23.373f, 227.937f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[36]);

	//middle street
	districtLights[37] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(405.93f, 23.373f, 69.408f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[37]);

	districtLights[38] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(378.333f, 23.373f, 197.589f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[38]);

	districtLights[39] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(395.157f, 23.373f, 239.58f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[39]);

	districtLights[40] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(388.995f, 23.373f, 288.633f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[40]);

	districtLights[41] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(438.699f, 23.373f, 508.593f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[41]);

	districtLights[42] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(408.201f, 23.373f, 771.738f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[42]);

	districtLights[43] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(308.208f, 23.373f, 767.145f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[43]);

	districtLights[44] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(314.184f, 23.373f, 705.069f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[44]);

	districtLights[45] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(314.394f, 23.373f, 638.019f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[45]);

	districtLights[46] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(315.948f, 23.373f, 552.798f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[46]);

	districtLights[47] = Light(Vec4f(1.0f, 0.332f, 0.163f, 1.0f), Vec4f(272.691f, 23.373f, 614.508f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.district[0].lights.push_back(districtLights[47]);


//************Store all the white lights to bring out normal map details***//////////////////
	Light normalLights[10]; 

	//normalLights[0] = Light(Vec4f(1.0f, 1.0f, 1.0f, 1.0f), Vec4f(148.0f, 20.0f, 416.0f, 1.0f), true, false);
	//gameLevel.district[0].normalLights.push_back(normalLights[0]);

	normalLights[0] = Light(Vec4f(1.0f, 1.0f, 1.0f, 1.0f), Vec4f(190.0f, 20.0f, 797.0f, 1.0f), true, false);
	gameLevel.district[0].normalLights.push_back(normalLights[0]); 

	normalLights[1] = Light(Vec4f(1.0f, 1.0f, 1.0f, 1.0f), Vec4f(341.0f, 20.0f, 422.0f, 1.0f), true, false);
	gameLevel.district[0].normalLights.push_back(normalLights[1]);

	normalLights[2] = Light(Vec4f(1.0f, 1.0f, 1.0f, 1.0f), Vec4f(358.0f, 20.0f, 224.0f, 1.0f), true, false);
	gameLevel.district[0].normalLights.push_back(normalLights[2]); 

	normalLights[3] = Light(Vec4f(1.0f, 1.0f, 1.0f, 1.0f), Vec4f(413.0f, 20.0f, 578.0f, 1.0f), true, false);
	gameLevel.district[0].normalLights.push_back(normalLights[3]); 

	normalLights[4] = Light(Vec4f(1.0f, 1.0f, 1.0f, 1.0f), Vec4f(358.0f, 20.0f, 743.0f, 1.0f), true, false);
	gameLevel.district[0].normalLights.push_back(normalLights[4]); 

	normalLights[5] = Light(Vec4f(1.0f, 1.0f, 1.0f, 1.0f), Vec4f(527.0f, 20.0f, 731.0f, 1.0f), true, false);
	gameLevel.district[0].normalLights.push_back(normalLights[5]); 

	normalLights[6] = Light(Vec4f(1.0f, 1.0f, 1.0f, 1.0f), Vec4f(583.0f, 20.0f, 304.0f, 1.0f), true, false);
	gameLevel.district[0].normalLights.push_back(normalLights[6]); 

	normalLights[7] = Light(Vec4f(1.0f, 1.0f, 1.0f, 1.0f), Vec4f(146.0f, 20.0f, 154.0f, 1.0f), true, false);
	gameLevel.district[0].normalLights.push_back(normalLights[7]); 


///////////////////////////////////////////////////////////////////////////
//***********FOR INTEROR ONE (DRAGON CLUB)****************************//

	//for the models of the Dragon Club Interior
	objLoader *i1_tempM[50];
	
	//Bar
	i1_tempM[0] = new objLoader();

	//beer glass
	i1_tempM[1] = new objLoader();

	//beer tap
	i1_tempM[2] = new objLoader();

	//Ceilings
	i1_tempM[3] = new objLoader();

	//Chairs
	i1_tempM[4] = new objLoader();

	//crate 1
	i1_tempM[5] = new objLoader();

	//dance floor
	i1_tempM[6] = new objLoader();

	//desk
	i1_tempM[7] = new objLoader();

	//disco sphere
	i1_tempM[8] = new objLoader();

	//dj board
	i1_tempM[9] = new objLoader();

	//dj booth
	i1_tempM[10] = new objLoader();

	//exterior walls
	i1_tempM[11] = new objLoader();

	//inner doors
	i1_tempM[12] = new objLoader();

	//interior walls
	i1_tempM[13] = new objLoader();

	//lights fixtures
	i1_tempM[14] = new objLoader();

	//main door
	i1_tempM[15] = new objLoader();

	//main floor
	i1_tempM[16] = new objLoader();

	//mirror
	i1_tempM[17] = new objLoader();

	//office chair
	i1_tempM[18] = new objLoader();

	//platform
	i1_tempM[19] = new objLoader();

	//poles
	i1_tempM[20] = new objLoader();

	//shelves
	i1_tempM[21] = new objLoader();

	//side table
	i1_tempM[22] = new objLoader();

	//sinks
	i1_tempM[23] = new objLoader();

	//small walls
	i1_tempM[24] = new objLoader();

	//stand tables
	i1_tempM[25] = new objLoader();

	//tables
	i1_tempM[26] = new objLoader();

	//toilet
	i1_tempM[27] = new objLoader();

	//urinal
	i1_tempM[28] = new objLoader();
	
	//vodka
	i1_tempM[29] = new objLoader();

	//whiskey
	i1_tempM[30] = new objLoader();

	//whiskey glass
	i1_tempM[31] = new objLoader();

	//wine
	i1_tempM[32] = new objLoader();
	
	
	///extra 
	//d1_tempM[33] = new objLoader();
	//d1_tempM[34] = new objLoader();
	//d1_tempM[35] = new objLoader();





	//for the Dragon's Club textures
	tex *i1_tempT[50];

		//Bar
	i1_tempT[0] = new tex();

	//beer glass
	i1_tempT[1] = new tex();

	//beer tap
	i1_tempT[2] = new tex();

	//Ceilings
	i1_tempT[3] = new tex();

	//Chairs
	i1_tempT[4] = new tex();

	//crate 1
	i1_tempT[5] = new tex();

	//dance floor
	i1_tempT[6] = new tex();

	//desk
	i1_tempT[7] = new tex();

	//disco sphere
	i1_tempT[8] = new tex();

	//dj board
	i1_tempT[9] = new tex();

	//dj booth
	i1_tempT[10] = new tex();

	//exterior walls
	i1_tempT[11] = new tex();

	//inner doors
	i1_tempT[12] = new tex();

	//interior walls
	i1_tempT[13] = new tex();

	//lights fixtures
	i1_tempT[14] = new tex();

	//main door
	i1_tempT[15] = new tex();

	//main floor
	i1_tempT[16] = new tex();

	//mirror
	i1_tempT[17] = new tex();

	//office chair
	i1_tempT[18] = new tex();

	//platform
	i1_tempT[19] = new tex();

	//poles
	i1_tempT[20] = new tex();

	//shelves
	i1_tempT[21] = new tex();

	//side table
	i1_tempT[22] = new tex();

	//sinks
	i1_tempT[23] = new tex();

	//small walls
	i1_tempT[24] = new tex();

	//stand tables
	i1_tempT[25] = new tex();

	//tables
	i1_tempT[26] = new tex();

	//toilet
	i1_tempT[27] = new tex();

	//urinal
	i1_tempT[28] = new tex();
	
	//vodka
	i1_tempT[29] = new tex();

	//whiskey
	i1_tempT[30] = new tex();

	//whiskey glass
	i1_tempT[31] = new tex();

	//wine
	i1_tempT[32] = new tex();
	
	

	///extra
	
	
	//d1_tempT[29] = new tex();
	//d1_tempT[30] = new tex();
	//d1_tempT[31] = new tex();
	//d1_tempT[32] = new tex();
	//d1_tempT[33] = new tex();
	//d1_tempT[34] = new tex();
	//d1_tempT[35] = new tex();



	//for the Dragon's club normal map
	tex *i1_tempN[50];


	///load the Dragon's CLub obj's and textures

	//bar
	i1_tempM[0]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_Bar.obj", 429);
	i1_tempT[0]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_Bar.jpg");
	////i1_tempN[0]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//beer glass
	i1_tempM[1]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_BeerGlass.obj", 288);
	i1_tempT[1]->loadTex("Images/Levels/Level1/Interior1/clear_glass.jpg");
	//i1_tempN[1]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//beer tap
	i1_tempM[2]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_BeerTap.obj", 1396);
	i1_tempT[2]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_BeerTap.jpg");
	//i1_tempN[2]->loadTex("Images/NormalMaps/Interior1/  .jpg");
	
	//ceilings
	i1_tempM[3]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_Ceilings.obj", 4);
	i1_tempT[3]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_Ceilings.jpg");
	//i1_tempN[3]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//chairs
	i1_tempM[4]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_Chairs.obj", 972);
	i1_tempT[4]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_Chairs.jpg");
	//i1_tempN[4]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//crate
	i1_tempM[5]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_Crate1.obj", 10);
	i1_tempT[5]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_Crate1.jpg");
	//i1_tempN[5]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//dance floor
	i1_tempM[6]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_DanceFloor.obj", 10);
	i1_tempT[6]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_DanceFloor.jpg");
	//i1_tempN[6]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//desk
	i1_tempM[7]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_Desk.obj", 128);
	i1_tempT[7]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_Desk.jpg");
	//i1_tempN[7]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//disco sphere
	i1_tempM[8]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_DiscoSphere.obj", 180);
	i1_tempT[8]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_DiscoSphere.jpg");
	//i1_tempN[8]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//dj board
	i1_tempM[9]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_DJBoard.obj", 2);
	i1_tempT[9]->loadTex("Images/Levels/Level1/Interior1/Mixing_Table.jpg");
	//i1_tempN[9]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//dj booth
	i1_tempM[10]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_DJBooth.obj", 30);
	i1_tempT[10]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_DJBooth.jpg");
	//i1_tempN[10]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//Exterior walls
	i1_tempM[11]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_Ext_Walls.obj", 12);
	i1_tempT[11]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_Ext_Walls.jpg");
	//i1_tempN[11]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//inner doors
	i1_tempM[12]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_InnerDoors.obj", 258);
	i1_tempT[12]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_InnerDoors.jpg");
	//i1_tempN[12]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//interior walls
	i1_tempM[13]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_Int_Walls.obj", 84);
	i1_tempT[13]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_Int_Walls.jpg");
	//i1_tempN[13]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//Light fixtures
	i1_tempM[14]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_Lights.obj", 384);
	i1_tempT[14]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_Lights.jpg");
	//i1_tempN[14]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//main door
	i1_tempM[15]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_MainDoor.obj", 8);
	i1_tempT[15]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_MainDoor.jpg");
	//i1_tempN[15]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//Main floor
	i1_tempM[16]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_MainFloor.obj", 2);
	i1_tempT[16]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_MainFloor.jpg");
	//i1_tempN[16]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//mirror
	i1_tempM[17]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_Mirror.obj", 2);
	i1_tempT[17]->loadTex("Images/Levels/Level1/Interior1/clear_glass.jpg");
	//i1_tempN[17]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//office chair
	i1_tempM[18]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_OfficeChair.obj", 100);
	i1_tempT[18]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_OfficeChair.jpg");
	//i1_tempN[18]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//platform
	i1_tempM[19]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_Platform.obj", 10);
	i1_tempT[19]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_Platform.jpg");
	//i1_tempN[19]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//poles
	i1_tempM[20]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_Poles.obj", 32);
	i1_tempT[20]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_Poles.jpg");
	//i1_tempN[20]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//shelves
	i1_tempM[21]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_Shelves.obj", 412);
	i1_tempT[21]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_Shelves.jpg");
	//i1_tempN[21]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//side table
	i1_tempM[22]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_SideTable.obj", 128);
	i1_tempT[22]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_SideTable.jpg");
	//i1_tempN[22]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//sinks
	i1_tempM[23]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_Sinks.obj", 204);
	i1_tempT[23]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_Sinks.jpg");
	//i1_tempN[23]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//small walls
	i1_tempM[24]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_SmallWalls.obj", 56);
	i1_tempT[24]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_SmallWalls.jpg");
	//i1_tempN[24]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//stand tables
	i1_tempM[25]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_StandTables.obj", 84);
	i1_tempT[25]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_StandTables.jpg");
	//i1_tempN[25]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//tables
	i1_tempM[26]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_Tables.obj", 240);
	i1_tempT[26]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_Tables.jpg");
	//i1_tempN[26]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//toilet
	i1_tempM[27]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_Toilet.obj", 148);
	i1_tempT[27]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_Toilet.jpg");
	//i1_tempN[27]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//urinal
	i1_tempM[28]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_Urinal.obj", 66);
	i1_tempT[28]->loadTex("Images/Levels/Level1/Interior1/Dragon_Club_Urinal.jpg");
	//i1_tempN[28]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//vodka bottles
	i1_tempM[29]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_Vodka.obj", 1820);
	i1_tempT[29]->loadTex("Images/Levels/Level1/Interior1/blue_vodka.jpg");
	//i1_tempN[29]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//whiskey bottles
	i1_tempM[30]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_Whiskey.obj", 1190);
	i1_tempT[30]->loadTex("Images/Levels/Level1/Interior1/whiskey_glass.jpg");
	//i1_tempN[30]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//whiskey glasses
	i1_tempM[31]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_WhiskeyGlass.obj", 470);
	i1_tempT[31]->loadTex("Images/Levels/Level1/Interior1/clear_glass.jpg");
	//i1_tempN[31]->loadTex("Images/NormalMaps/Interior1/  .jpg");

	//wine bottles
	i1_tempM[32]->LoadOBJ("Models/Levels/Level1/Interior1/Dragon_Club_Wine.obj", 1120);
	i1_tempT[32]->loadTex("Images/Levels/Level1/Interior1/red_wine.jpg");
	//i1_tempN[32]->loadTex("Images/NormalMaps/Interior1/  .jpg");



	///push.back all objects

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[0]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[0]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[0]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[1]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[1]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[1]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[2]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[2]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[2]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[3]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[3]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[3]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[4]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[4]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[4]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[5]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[5]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[5]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[6]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[6]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[6]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[7]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[7]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[7]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[8]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[8]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[8]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[9]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[9]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[9]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[10]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[10]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[10]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[11]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[11]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[11]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[12]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[12]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[12]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[13]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[13]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[13]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[14]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[14]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[14]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[15]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[15]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[15]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[16]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[16]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[16]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[17]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[17]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[17]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[18]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[18]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[18]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[19]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[19]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[19]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[20]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[20]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[20]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[21]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[21]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[21]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[22]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[22]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[22]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[23]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[23]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[23]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[24]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[24]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[24]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[25]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[25]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[25]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[26]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[26]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[26]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[27]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[27]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[27]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[28]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[28]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[28]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[29]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[29]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[29]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[30]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[30]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[30]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[31]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[31]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[31]);

	gameLevel.interior[0].sectionModels.push_back(i1_tempM[32]);
	gameLevel.interior[0].sectionTexs.push_back(i1_tempT[32]);
	//gameLevel.interior[0].sectionNormalMaps.push_back(i1_tempN[32]);


//**************Other areas********************//
	toNextArea *i1_areas[10];
	collisionObject *i1_collisionZones[10];

	i1_collisionZones[0] = new collisionObject(10.0f, Vec3f(206, 0.0f, 115), 0.0f, false);
	i1_areas[0] = new toNextArea(i1_collisionZones[0], Vec3f(276, 0, 210),true, 0);
	gameLevel.interior[0].Areas.push_back(i1_areas[0]);



//***********LIGHTS*********************
	//ambient light
	//color {0.25, 0.25, 0.25}, also is the intensity of the light, fourth parameter is always one
	gameLevel.interior[0].ambientLightColor[0] = 0.1f;
	gameLevel.interior[0].ambientLightColor[1] = 0.1f;
	gameLevel.interior[0].ambientLightColor[2] = 0.1f;
	gameLevel.interior[0].ambientLightColor[3] = 1.0f;

	Light clubLights[15];

	//Light1
	//color: RGBA
	//Position: first 3 variables are XYZ coordinates, the last variable is if it is a directed light (0) or positioned light (1)
	//drawPoint: if we should render a point where the light it, so we can better visulize its position

	//purple disco light
	clubLights[0] = Light(Vec4f(0.965f, 0.213f, 1.0f, 1.0f), Vec4f(143.229f, 42.144f, 115.68, 1.0f), true, false, 49.919f, 0.0001f, 0.0002f);
	gameLevel.interior[0].lights.push_back(clubLights[0]);

	//spot lights
	//red
	clubLights[1] = Light(Vec4f(1.0f, 0.112f, 0.112f, 1.0f), Vec4f(43.668, 31.887, 46.845, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[0].lights.push_back(clubLights[1]);

	clubLights[2] = Light(Vec4f(1.0f, 0.112f, 0.112f, 1.0f), Vec4f(43.668, 31.887, 70.845, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[0].lights.push_back(clubLights[2]);

	clubLights[3] = Light(Vec4f(1.0f, 0.112f, 0.112f, 1.0f), Vec4f(43.668, 31.887, 94.845, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[0].lights.push_back(clubLights[3]);

	clubLights[4] = Light(Vec4f(1.0f, 0.112f, 0.112f, 1.0f), Vec4f(43.668, 31.887, 115.845, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[0].lights.push_back(clubLights[4]);

	//white
	clubLights[5] = Light(Vec4f(1.0f, 0.955f, 0.955f, 1.0f), Vec4f(43.668, 31.887, 163.845, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[0].lights.push_back(clubLights[5]);

	clubLights[6] = Light(Vec4f(1.0f, 0.955f, 0.955f, 1.0f), Vec4f(19.668, 31.887, 163.845, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[0].lights.push_back(clubLights[6]);

	clubLights[7] = Light(Vec4f(1.0f, 0.955f, 0.955f, 1.0f), Vec4f(19.668, 31.887, 130.845, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[0].lights.push_back(clubLights[7]);

	clubLights[8] = Light(Vec4f(1.0f, 0.955f, 0.955f, 1.0f), Vec4f(19.668, 31.887, 106.845, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[0].lights.push_back(clubLights[8]);

	clubLights[9] = Light(Vec4f(1.0f, 0.955f, 0.955f, 1.0f), Vec4f(19.668, 31.887, 67.845, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[0].lights.push_back(clubLights[9]);

	clubLights[10] = Light(Vec4f(1.0f, 0.955f, 0.955f, 1.0f), Vec4f(19.668, 31.887, 49.845, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[0].lights.push_back(clubLights[10]);

	//yellow light in office
	clubLights[11] = Light(Vec4f(1.0f, 0.609f, 0.084f, 1.0f), Vec4f(37.668, 26.229, 204.36, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[0].lights.push_back(clubLights[11]);


///////////////////////////////////////////////////////////////////////////
//***********FOR INTEROR TWO (GRIM Bar)****************************//

	//for the models of the Grim Bar Interior
	objLoader *i2_tempM[50];

	i2_tempM[0] = new objLoader();
	i2_tempM[1] = new objLoader();
	i2_tempM[2] = new objLoader();
	i2_tempM[3] = new objLoader();
	i2_tempM[4] = new objLoader();
	i2_tempM[5] = new objLoader();
	i2_tempM[6] = new objLoader();
	i2_tempM[7] = new objLoader();
	i2_tempM[8] = new objLoader();
	i2_tempM[9] = new objLoader();
	i2_tempM[10] = new objLoader();
	i2_tempM[11] = new objLoader();
	i2_tempM[12] = new objLoader();
	i2_tempM[13] = new objLoader();
	i2_tempM[14] = new objLoader();
	i2_tempM[15] = new objLoader();
	i2_tempM[16] = new objLoader();
	i2_tempM[17] = new objLoader();
	i2_tempM[18] = new objLoader();
	i2_tempM[19] = new objLoader();
	i2_tempM[20] = new objLoader();
	i2_tempM[21] = new objLoader();
	i2_tempM[22] = new objLoader();
	i2_tempM[23] = new objLoader();
	i2_tempM[24] = new objLoader();
	i2_tempM[25] = new objLoader();
	i2_tempM[26] = new objLoader();
	i2_tempM[27] = new objLoader();
	i2_tempM[28] = new objLoader();
	i2_tempM[29] = new objLoader();
	i2_tempM[30] = new objLoader();
	i2_tempM[31] = new objLoader();
	i2_tempM[32] = new objLoader();
	i2_tempM[33] = new objLoader();
	i2_tempM[34] = new objLoader();
	i2_tempM[35] = new objLoader();
	i2_tempM[36] = new objLoader();
	i2_tempM[37] = new objLoader();
	i2_tempM[38] = new objLoader();
	i2_tempM[39] = new objLoader();
	i2_tempM[40] = new objLoader();
	i2_tempM[41] = new objLoader();
	i2_tempM[42] = new objLoader();
	i2_tempM[43] = new objLoader();
	i2_tempM[44] = new objLoader();
	i2_tempM[45] = new objLoader();

	//for the Grim Bar's textures
	tex *i2_tempT[50];

	i2_tempT[0] = new tex();
	i2_tempT[1] = new tex();
	i2_tempT[2] = new tex();
	i2_tempT[3] = new tex();
	i2_tempT[4] = new tex();
	i2_tempT[5] = new tex();
	i2_tempT[6] = new tex();
	i2_tempT[7] = new tex();
	i2_tempT[8] = new tex();
	i2_tempT[9] = new tex();
	i2_tempT[10] = new tex();
	i2_tempT[11] = new tex();
	i2_tempT[12] = new tex();
	i2_tempT[13] = new tex();
	i2_tempT[14] = new tex();
	i2_tempT[15] = new tex();
	i2_tempT[16] = new tex();
	i2_tempT[17] = new tex();
	i2_tempT[18] = new tex();
	i2_tempT[19] = new tex();
	i2_tempT[20] = new tex();
	i2_tempT[21] = new tex();
	i2_tempT[22] = new tex();
	i2_tempT[23] = new tex();
	i2_tempT[24] = new tex();
	i2_tempT[25] = new tex();
	i2_tempT[26] = new tex();
	i2_tempT[27] = new tex();
	i2_tempT[28] = new tex();
	i2_tempT[29] = new tex();
	i2_tempT[30] = new tex();
	i2_tempT[31] = new tex();
	i2_tempT[32] = new tex();
	i2_tempT[33] = new tex();
	i2_tempT[34] = new tex();
	i2_tempT[35] = new tex();
	i2_tempT[36] = new tex();
	i2_tempT[37] = new tex();
	i2_tempT[38] = new tex();
	i2_tempT[39] = new tex();
	i2_tempT[40] = new tex();
	i2_tempT[41] = new tex();
	i2_tempT[42] = new tex();
	i2_tempT[43] = new tex();
	i2_tempT[44] = new tex();
	i2_tempT[45] = new tex();


	//for the Grim Bar's normal maps
	tex *i2_tempN[50];
	//i2_tempN[0] = new tex();


	///load the Grim Bar's obj's and textures

	//bar 1
	i2_tempM[0]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Bar1.obj", 429);
	i2_tempT[0]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Bar1.jpg");
	//i2_tempN[0]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//bar 2
	i2_tempM[1]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Bar2.obj", 429);
	i2_tempT[1]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Bar2.jpg");
	//i2_tempN[1]->loadTex("Images/NormalMaps/Interior2/  .jpg");
	
	//bar shelves
	i2_tempM[2]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_BarShelves.obj", 56);
	i2_tempT[2]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_BarShelves.jpg");
	//i2_tempN[2]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//beer glass
	i2_tempM[3]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_BeerGlass.obj", 864);
	i2_tempT[3]->loadTex("Images/Levels/Level1/Interior2/clear_glass.jpg");
	//i2_tempN[3]->loadTex("Images/NormalMaps/Interior2/  .jpg");
	
	//bar taps
	i2_tempM[4]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_BeerTaps.obj", 5584);
	i2_tempT[4]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_BeerTaps.jpg");
	//i2_tempN[4]->loadTex("Images/NormalMaps/Interior2/  .jpg");
	
	//ceiling
	i2_tempM[5]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Ceiling.obj", 2);
	i2_tempT[5]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Ceiling.jpg");
	//i2_tempN[5]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	///chairs
	i2_tempM[6]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Chairs.obj", 864);
	i2_tempT[6]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Chairs.jpg");
	//i2_tempN[6]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	////couch 1
	i2_tempM[7]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Couch1.obj", 388);
	i2_tempT[7]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Couch1.jpg");
	//i2_tempN[7]->loadTex("Images/NormalMaps/Interior2/  .jpg");
	
	//couch 2
	i2_tempM[8]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Couch2.obj", 388);
	i2_tempT[8]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Couch2.jpg");
	//i2_tempN[8]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//couch 3
	i2_tempM[9]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Couch3.obj", 388);
	i2_tempT[9]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Couch3.jpg");
	//i2_tempN[9]->loadTex("Images/NormalMaps/Interior2/  .jpg");
	
	//counters
	i2_tempM[10]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Counters.obj", 24);
	i2_tempT[10]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Counters.jpg");
	//i2_tempN[10]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//desk
	i2_tempM[11]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Desk.obj", 128);
	i2_tempT[11]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Desk.jpg");
	//i2_tempN[11]->loadTex("Images/NormalMaps/Interior2/  .jpg");
	
	//exterior walls
	i2_tempM[12]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Ext_Walls.obj", 40);
	i2_tempT[12]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Ext_Walls.jpg");
	//i2_tempN[12]->loadTex("Images/NormalMaps/Interior2/  .jpg");
	
	//freezer
	i2_tempM[13]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Freezer.obj", 12);
	i2_tempT[13]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Freezer.jpg");
	//i2_tempN[13]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//freezer door
	i2_tempM[14]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_FreezerDoor.obj", 8);
	i2_tempT[14]->loadTex("Images/Levels/Level1/Interior2/freezer_door.jpg");
	//i2_tempN[14]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//inner doors
	i2_tempM[15]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_InnerDoors.obj", 48);
	i2_tempT[15]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_InnerDoors.jpg");
	//i2_tempN[15]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//interior walls
	i2_tempM[16]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Int_Walls.obj", 156);
	i2_tempT[16]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Int_Walls.jpg");
	//i2_tempN[16]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//kitchen 1
	i2_tempM[17]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Kitchen1.obj", 429);
	i2_tempT[17]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Kitchen1.jpg");
	//i2_tempN[17]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//kitchen 2
	i2_tempM[18]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Kitchen2.obj", 429);
	i2_tempT[18]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Kitchen2.jpg");
	//i2_tempN[18]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//kitchen 3
	i2_tempM[19]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Kitchen3.obj", 429);
	i2_tempT[19]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Kitchen3.jpg");
	//i2_tempN[19]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//kitchen shelves 1
	i2_tempM[20]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_KitchenShelves1.obj", 168);
	i2_tempT[20]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_KitchenShelves1.jpg");
	//i2_tempN[20]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//kitchen shelves 2
	i2_tempM[21]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_KitchenShelves2.obj", 168);
	i2_tempT[21]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_KitchenShelves2.jpg");
	//i2_tempN[21]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//kitchen taps
	i2_tempM[22]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_KitchenTaps.obj", 20);
	i2_tempT[22]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_KitchenTaps.jpg");
	//i2_tempN[22]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//lights
	i2_tempM[23]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Lights.obj", 512);
	i2_tempT[23]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Lights.jpg");
	//i2_tempN[23]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//lounge tv
	i2_tempM[24]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_LoungeTV.obj", 24);
	i2_tempT[24]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_LoungeTV.jpg");
	//i2_tempN[24]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//main door
	i2_tempM[25]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_MainDoor.obj", 22);
	i2_tempT[25]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_MainDoor.jpg");
	//i2_tempN[25]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//main floor
	i2_tempM[26]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_MainFloor.obj", 2);
	i2_tempT[26]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_MainFloor.jpg");
	//i2_tempN[26]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//main tv
	i2_tempM[27]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_MainTV.obj", 24);
	i2_tempT[27]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_MainTV.jpg");
	//i2_tempN[27]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//office chair
	i2_tempM[28]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_OfficeChair.obj", 100);
	i2_tempT[28]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_OfficeChair.jpg");
	//i2_tempN[28]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//sink 1
	i2_tempM[29]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Sink1.obj", 18);
	i2_tempT[29]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Sink1.jpg");
	//i2_tempN[29]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//sink 2
	i2_tempM[30]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Sink2.obj", 18);
	i2_tempT[30]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Sink2.jpg");
	//i2_tempN[30]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//stools
	i2_tempM[31]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Stools.obj", 576);
	i2_tempT[31]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Stools.jpg");
	//i2_tempN[31]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//stove
	i2_tempM[32]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Stove.obj", 2);
	i2_tempT[32]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Stove.jpg");
	//i2_tempN[32]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//tables
	i2_tempM[33]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Tables.obj", 550);
	i2_tempT[33]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Tables.jpg");
	//i2_tempN[33]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//tv 1
	i2_tempM[34]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_TV1.obj", 24);
	i2_tempT[34]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_TV1.jpg");
	//i2_tempN[34]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//tv 3
	i2_tempM[35]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_TV3.obj", 24);
	i2_tempT[35]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_TV3.jpg");
	//i2_tempN[35]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//tv 4
	i2_tempM[36]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_TV4.obj", 24);
	i2_tempT[36]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_TV4.jpg");
	//i2_tempN[36]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//tv 7
	i2_tempM[37]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_TV7.obj", 24);
	i2_tempT[37]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_TV7.jpg");
	//i2_tempN[37]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//tv 8
	i2_tempM[38]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_TV8.obj", 24);
	i2_tempT[38]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_TV8.jpg");
	//i2_tempN[38]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//tv 9
	i2_tempM[39]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_TV9.obj", 24);
	i2_tempT[39]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_TV9.jpg");
	//i2_tempN[39]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//vodka
	i2_tempM[40]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Vodka.obj", 1680);
	i2_tempT[40]->loadTex("Images/Levels/Level1/Interior2/blue_vodka.jpg");
	//i2_tempN[40]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//water
	i2_tempM[41]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Water.obj", 24);
	i2_tempT[41]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Water.jpg");
	//i2_tempN[41]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//whiskey
	i2_tempM[42]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Whiskey.obj", 1540);
	i2_tempT[42]->loadTex("Images/Levels/Level1/Interior2/whiskey_glass.jpg");
	//i2_tempN[42]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//whiskey glass
	i2_tempM[43]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_WhiskeyGlass.obj", 1280);
	i2_tempT[43]->loadTex("Images/Levels/Level1/Interior2/clear_glass.jpg");
	//i2_tempN[43]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//window 1
	i2_tempM[44]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Window1.obj", 18);
	i2_tempT[44]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Window1.jpg");
	//i2_tempN[44]->loadTex("Images/NormalMaps/Interior2/  .jpg");

	//window 2
	i2_tempM[45]->LoadOBJ("Models/Levels/Level1/Interior2/Grim_Bar_Window2.obj", 18);
	i2_tempT[45]->loadTex("Images/Levels/Level1/Interior2/Grim_Bar_Window2.jpg");
	//i2_tempN[45]->loadTex("Images/NormalMaps/Interior2/  .jpg");




	//////////////////////////////////////////
	///push.back all objects

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[0]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[0]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[0]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[1]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[1]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[1]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[2]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[2]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[2]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[3]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[3]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[3]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[4]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[4]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[4]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[5]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[5]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[5]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[6]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[6]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[6]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[7]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[7]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[7]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[8]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[8]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[8]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[9]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[9]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[9]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[10]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[10]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[10]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[11]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[11]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[11]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[12]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[12]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[12]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[13]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[13]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[13]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[14]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[14]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[14]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[15]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[15]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[15]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[16]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[16]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[16]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[17]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[17]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[17]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[18]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[18]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[18]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[19]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[19]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[19]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[20]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[20]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[20]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[21]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[21]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[21]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[22]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[22]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[22]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[23]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[23]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[23]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[24]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[24]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[24]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[25]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[25]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[25]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[26]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[26]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[26]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[27]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[27]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[27]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[28]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[28]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[28]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[29]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[29]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[29]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[30]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[30]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[30]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[31]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[31]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[31]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[32]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[32]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[32]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[33]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[33]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[33]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[34]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[34]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[34]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[35]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[35]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[35]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[36]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[36]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[36]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[37]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[37]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[37]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[38]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[38]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[38]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[39]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[39]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[39]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[40]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[40]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[40]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[41]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[41]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[41]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[42]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[42]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[42]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[43]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[43]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[43]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[44]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[44]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[44]);

	gameLevel.interior[1].sectionModels.push_back(i2_tempM[45]);
	gameLevel.interior[1].sectionTexs.push_back(i2_tempT[45]);
	//gameLevel.interior[1].sectionNormalMaps.push_back(i2_tempN[45]);

	////////////////////////////////////
	////////to other areas/////////////
	toNextArea *i2_areas[10];
	collisionObject *i2_collisionZones[10];

	//in bar
	i2_collisionZones[0] = new collisionObject(10.0f, Vec3f(28.0f, 0.0f, 155.0f), 0.0f, false);
	//outside
	i2_areas[0] = new toNextArea(i2_collisionZones[0], Vec3f(272.0f, 0.0f, 436.0f),true, 0);
	gameLevel.interior[1].Areas.push_back(i2_areas[0]);

//***********LIGHTS*********************
	//ambient light
	//color {0.25, 0.25, 0.25}, also is the intensity of the light, fourth parameter is always one
	gameLevel.interior[1].ambientLightColor[0] = 0.1f;
	gameLevel.interior[1].ambientLightColor[1] = 0.1f;
	gameLevel.interior[1].ambientLightColor[2] = 0.1f;
	gameLevel.interior[1].ambientLightColor[3] = 1.0f;

	Light barLights[15];

	//Light1
	//color: RGBA
	//Position: first 3 variables are XYZ coordinates, the last variable is if it is a directed light (0) or positioned light (1)
	//drawPoint: if we should render a point where the light it, so we can better visulize its position

	//orange spot lights
	barLights[0] = Light(Vec4f(1.0f, 0.539f, 0.0f, 1.0f), Vec4f(13.608f, 26.379f, 156.15f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[1].lights.push_back(barLights[0]);

	barLights[1] = Light(Vec4f(1.0f, 0.539f, 0.0f, 1.0f), Vec4f(38.808f, 26.379f, 189.78f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[1].lights.push_back(barLights[1]);

	barLights[2] = Light(Vec4f(1.0f, 0.539f, 0.0f, 1.0f), Vec4f(58.884f, 26.379f, 135.249f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[1].lights.push_back(barLights[2]);

	barLights[3] = Light(Vec4f(1.0f, 0.539f, 0.0f, 1.0f), Vec4f(74.559f, 26.379f, 104.01f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[1].lights.push_back(barLights[3]);

	barLights[4] = Light(Vec4f(1.0f, 0.539f, 0.0f, 1.0f), Vec4f(74.559f, 26.379f, 68.781f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[1].lights.push_back(barLights[4]);

	barLights[5] = Light(Vec4f(1.0f, 0.539f, 0.0f, 1.0f), Vec4f(87.87f, 26.379f, 44.46f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[1].lights.push_back(barLights[5]);

	barLights[6] = Light(Vec4f(1.0f, 0.539f, 0.0f, 1.0f), Vec4f(134.487f, 26.379f, 29.613f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[1].lights.push_back(barLights[6]);

	barLights[7] = Light(Vec4f(1.0f, 0.539f, 0.0f, 1.0f), Vec4f(105.588f, 26.379f, 90.06f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[1].lights.push_back(barLights[7]);

	barLights[8] = Light(Vec4f(1.0f, 0.539f, 0.0f, 1.0f), Vec4f(156.774f, 26.379f, 79.209f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[1].lights.push_back(barLights[8]);

	//blue
	barLights[9] = Light(Vec4f(0.0f, 0.360f, 1.0f, 1.0f), Vec4f(36.006f, 26.379f, 93.069f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[1].lights.push_back(barLights[9]);

	barLights[10] = Light(Vec4f(0.0f, 0.360f, 1.0f, 1.0f), Vec4f(39.348f, 26.379f, 48.39f, 1.0f), true, false, 49.919f, 0.00095f, 0.0015f);
	gameLevel.interior[1].lights.push_back(barLights[10]);

	//tv light
	barLights[11] = Light(Vec4f(0.404f, 0.779f, 1.0f, 1.0f), Vec4f(169.983f, 29.343f, 196.011f, 1.0f), true, false, 49.919f, 0.0001f, 0.0002f);
	gameLevel.interior[1].lights.push_back(barLights[11]);



//**************************************************************************************//
//**************************************************************************************//
//************************MUST ALWAYS BE UPDATED****************************************//
	//load missions for entire game
	//can be placed somewhere else later
	//missions.loadGameMissions();

//the total number of districts and interiors for the level****
	numDistricts = 1;
	numInteriors = 2;
	
}







//***********************************************************************************************************************************************************//
//**********************************DO NOT CHANGE/WRITE ANYTHING IN FUNCTIONS FROM BASE CLASS LEVEL**********************************************************//
///////////////////////if you need to add something to a particular level, add it to the particular level's functions//////////////////////////////////////////
//***********************************************************************************************************************************************************//

//*****This works only if there are the same number of models and textures*****
void Level::drawDistrict(int n, Shader *shader)
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);

	//draws all of the models in the district
	for(int i = 0; i < numDistricts; i++)
	{
		//we have found the right district to render
		if(i == n)
		{	
			/*FOG*/
			//glFogfv (GL_FOG_COLOR, gameLevel.district[i].fogColor);
			//glFogi(GL_FOG_MODE, GL_LINEAR);   //assigns the weighting of the gray color to a linear function // Fog Mode GL_EXP, GL_EXP2, GL_LINEAR
			//glFogf(GL_FOG_START, gameLevel.district[i].fogStart);
			//glFogf(GL_FOG_END, gameLevel.district[i].fogEnd);

			/*LIGHTS*/
			glUniform1i(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "numLights"), gameLevel.district[i].lights.size());


			//add ambient light (shines everwhere in our sceen by the same amount, so every face get lit by the same amount)
			//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, gameLevel.district[i].ambientLightColor);
			glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "globalAmbient"), 1, gameLevel.district[i].ambientLightColor);

			//////add directed light and sets it to light0
			//glLightfv(GL_LIGHT0, GL_DIFFUSE, gameLevel.district[i].directedLightColor);				//sets light intensity
			//glLightfv(GL_LIGHT0, GL_POSITION, gameLevel.district[i].directedLightPosition);			//sets postion of light
			int numLights = gameLevel.district[i].lights.size();

			if(numLights < 8)
			{
				// do nothing
			}
			else
			{
				numLights = 8; //max lights
			}

			//render dynamic lights
			for(int k = 0; k < numLights; k++)
			{
				//glLightfv(GL_LIGHT0 + k, GL_DIFFUSE, gameLevel.district[i].lights[k].LightColor);				//sets light intensity
				//glLightfv(GL_LIGHT0 + k, GL_POSITION, gameLevel.district[i].lights[0].LightPosition);			//sets postion of light

				GLfloat modelView[16];
				glGetFloatv(GL_MODELVIEW_MATRIX, modelView);

				Mat4f glModelView = Mat4f(modelView);

				//glModelView = Mat4f(glModelView.row1, glModelView.row2, glModelView.row3, Vec4f(0,0,0,1));

				Vec4f lightPos = Vec4f(gameLevel.district[i].lights[k].LightPosition[0], gameLevel.district[i].lights[k].LightPosition[1], gameLevel.district[i].lights[k].LightPosition[2], 1.0f);
				lightPos = glModelView.transpose() * lightPos; 
				lightPos[3] = gameLevel.district[i].lights[k].LightPosition[3];


				if(k == 0)
				{
					//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[k].LightPosition);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, lightPos.v);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].color"), 1, gameLevel.district[i].lights[k].LightColor);

					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].linearConstant"),  gameLevel.district[i].lights[k].linearConstant);
					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].quadraticConstant"),  gameLevel.district[i].lights[k].quadraticConstant);
					
					if(gameLevel.district[i].lights[k].spotLight)
					{
						//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
						GLfloat spot_direction[] = {0.0, -1.0, 0.0};
						//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
						//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].spotCutoff"),  gameLevel.district[i].lights[k].spotCutoff);
						glUniform3fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].spotDirection"), 1, spot_direction);
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].spotExponent"), 2.0);
					}
					else
					{
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].spotCutoff"), 180.0);
					}
				}
				else if(k == 1)
				{
					//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[1].position"), 1, gameLevel.district[i].lights[k].LightPosition);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[1].position"), 1, lightPos.v);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[1].color"), 1, gameLevel.district[i].lights[k].LightColor);

					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[1].linearConstant"),  gameLevel.district[i].lights[k].linearConstant);
					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[1].quadraticConstant"),  gameLevel.district[i].lights[k].quadraticConstant);
					
					if(gameLevel.district[i].lights[k].spotLight)
					{
						//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
						GLfloat spot_direction[] = {0.0, -1.0, 0.0};
						//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
						//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[1].spotCutoff"), 45.0);
						glUniform3fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[1].spotDirection"), 1, spot_direction);
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[1].spotExponent"), 2.0);
					}
					else
					{
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[1].spotCutoff"), 180.0);
					}
				}
				else if(k == 2)
				{
					//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[2].position"), 1, gameLevel.district[i].lights[k].LightPosition);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[2].position"), 1, lightPos.v);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[2].color"), 1, gameLevel.district[i].lights[k].LightColor);

					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[2].linearConstant"),  gameLevel.district[i].lights[k].linearConstant);
					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[2].quadraticConstant"),  gameLevel.district[i].lights[k].quadraticConstant);
					
					if(gameLevel.district[i].lights[k].spotLight)
					{
						//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
						GLfloat spot_direction[] = {0.0, -1.0, 0.0};
						//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
						//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[2].spotCutoff"), 45.0);
						glUniform3fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[2].spotDirection"), 1, spot_direction);
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[2].spotExponent"), 2.0);
					}
					else
					{
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[2].spotCutoff"), 180.0);
					}
				}
				else if(k == 3)
				{
					//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[3].position"), 1, gameLevel.district[i].lights[k].LightPosition);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[3].position"), 1, lightPos.v);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[3].color"), 1, gameLevel.district[i].lights[k].LightColor);

					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[3].linearConstant"),  gameLevel.district[i].lights[k].linearConstant);
					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[3].quadraticConstant"),  gameLevel.district[i].lights[k].quadraticConstant);
					
					if(gameLevel.district[i].lights[k].spotLight)
					{
						//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
						GLfloat spot_direction[] = {0.0, -1.0, 0.0};
						//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
						//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[3].spotCutoff"), 45.0);
						glUniform3fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[3].spotDirection"), 1, spot_direction);
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[3].spotExponent"), 2.0);
					}
					else
					{
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[3].spotCutoff"), 180.0);
					}

				}
				else if(k == 4)
				{
					//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[4].position"), 1, lightPos.v);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[4].color"), 1, gameLevel.district[i].lights[k].LightColor);

					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[4].linearConstant"),  gameLevel.district[i].lights[k].linearConstant);
					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[4].quadraticConstant"),  gameLevel.district[i].lights[k].quadraticConstant);
					
					if(gameLevel.district[i].lights[k].spotLight)
					{
						//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
						GLfloat spot_direction[] = {0.0, -1.0, 0.0};
						//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
						//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[4].spotCutoff"), 45.0);
						glUniform3fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[4].spotDirection"), 1, spot_direction);
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[4].spotExponent"), 2.0);
					}
					else
					{
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[4].spotCutoff"), 180.0);
					}
				}
				else if(k == 5)
				{
					//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[5].position"), 1, lightPos.v);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[5].color"), 1, gameLevel.district[i].lights[k].LightColor);

					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[5].linearConstant"),  gameLevel.district[i].lights[k].linearConstant);
					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[5].quadraticConstant"),  gameLevel.district[i].lights[k].quadraticConstant);
					
					if(gameLevel.district[i].lights[k].spotLight)
					{
						//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
						GLfloat spot_direction[] = {0.0, -1.0, 0.0};
						//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
						//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[5].spotCutoff"), 45.0);
						glUniform3fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[5].spotDirection"), 1, spot_direction);
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[5].spotExponent"), 2.0);
					}
					else
					{
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[5].spotCutoff"), 180.0);
					}
				}
				else if(k == 6)
				{
					//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[6].position"), 1, lightPos.v);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[6].color"), 1, gameLevel.district[i].lights[k].LightColor);

					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[6].linearConstant"),  gameLevel.district[i].lights[k].linearConstant);
					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[6].quadraticConstant"),  gameLevel.district[i].lights[k].quadraticConstant);
					
					if(gameLevel.district[i].lights[k].spotLight)
					{
						//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
						GLfloat spot_direction[] = {0.0, -1.0, 0.0};
						//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
						//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[6].spotCutoff"), 45.0);
						glUniform3fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[6].spotDirection"), 1, spot_direction);
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[6].spotExponent"), 2.0);
					}
					else
					{
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[6].spotCutoff"), 180.0);
					}
				}
				else if(k == 7)
				{
					//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[7].position"), 1, lightPos.v);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[7].color"), 1, gameLevel.district[i].lights[k].LightColor);

					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[7].linearConstant"),  gameLevel.district[i].lights[k].linearConstant);
					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[7].quadraticConstant"),  gameLevel.district[i].lights[k].quadraticConstant);
					
					if(gameLevel.district[i].lights[k].spotLight)
					{
						//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
						GLfloat spot_direction[] = {0.0, -1.0, 0.0};
						//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
						//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[7].spotCutoff"), 45.0);
						glUniform3fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[7].spotDirection"), 1, spot_direction);
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[7].spotExponent"), 2.0);
					}
					else
					{
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[7].spotCutoff"), 180.0);
					}
				}
				//else if(k == 8)
				//{
				//	//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[8].position"), 1, lightPos.v);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[8].color"), 1, gameLevel.district[i].lights[k].LightColor);

				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[8].linearConstant"),  gameLevel.district[i].lights[k].linearConstant);
				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[8].quadraticConstant"),  gameLevel.district[i].lights[k].quadraticConstant);
				//	
				//	if(gameLevel.district[i].lights[k].spotLight)
				//	{
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
				//		GLfloat spot_direction[] = {0.0, -1.0, 0.0};
				//		//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[8].spotCutoff"), 45.0);
				//		glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[8].spotDirection"), 1, spot_direction);
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[8].spotExponent"), 2.0);
				//	}
				//	else
				//	{
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[8].spotCutoff"), 180.0);
				//	}
				//}
				//else if(k == 9)
				//{
				//	//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[9].position"), 1, lightPos.v);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[9].color"), 1, gameLevel.district[i].lights[k].LightColor);

				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[9].linearConstant"),  gameLevel.district[i].lights[k].linearConstant);
				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[9].quadraticConstant"),  gameLevel.district[i].lights[k].quadraticConstant);
				//	
				//	if(gameLevel.district[i].lights[k].spotLight)
				//	{
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
				//		GLfloat spot_direction[] = {0.0, -1.0, 0.0};
				//		//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[9].spotCutoff"), 45.0);
				//		glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[9].spotDirection"), 1, spot_direction);
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[9].spotExponent"), 2.0);
				//	}
				//	else
				//	{
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[9].spotCutoff"), 180.0);
				//	}
				//}
				//else if(k == 10)
				//{
				//	//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[10].position"), 1, lightPos.v);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[10].color"), 1, gameLevel.district[i].lights[k].LightColor);

				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[10].linearConstant"),  gameLevel.district[i].lights[k].linearConstant);
				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[10].quadraticConstant"),  gameLevel.district[i].lights[k].quadraticConstant);
				//	
				//	if(gameLevel.district[i].lights[k].spotLight)
				//	{
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
				//		GLfloat spot_direction[] = {0.0, -1.0, 0.0};
				//		//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[10].spotCutoff"), 45.0);
				//		glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[10].spotDirection"), 1, spot_direction);
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[10].spotExponent"), 2.0);
				//	}
				//	else
				//	{
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[10].spotCutoff"), 180.0);
				//	}
				//}
				//else if(k == 11)
				//{
				//	//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[11].position"), 1, lightPos.v);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[11].color"), 1, gameLevel.district[i].lights[k].LightColor);

				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[11].linearConstant"),  gameLevel.district[i].lights[k].linearConstant);
				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[11].quadraticConstant"),  gameLevel.district[i].lights[k].quadraticConstant);
				//	
				//	if(gameLevel.district[i].lights[k].spotLight)
				//	{
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
				//		GLfloat spot_direction[] = {0.0, -1.0, 0.0};
				//		//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[11].spotCutoff"), 45.0);
				//		glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[11].spotDirection"), 1, spot_direction);
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[11].spotExponent"), 2.0);
				//	}
				//	else
				//	{
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[11].spotCutoff"), 180.0);
				//	}
				//}
				//else if(k == 12)
				//{
				//	//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[12].position"), 1, lightPos.v);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[12].color"), 1, gameLevel.district[i].lights[k].LightColor);

				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[12].linearConstant"),  gameLevel.district[i].lights[k].linearConstant);
				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[12].quadraticConstant"),  gameLevel.district[i].lights[k].quadraticConstant);
				//	
				//	if(gameLevel.district[i].lights[k].spotLight)
				//	{
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
				//		GLfloat spot_direction[] = {0.0, -1.0, 0.0};
				//		//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[12].spotCutoff"), 45.0);
				//		glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[12].spotDirection"), 1, spot_direction);
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[12].spotExponent"), 2.0);
				//	}
				//	else
				//	{
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[12].spotCutoff"), 180.0);
				//	}
				//}
				//else if(k == 13)
				//{
				//	//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[13].position"), 1, lightPos.v);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[13].color"), 1, gameLevel.district[i].lights[k].LightColor);

				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[13].linearConstant"),  gameLevel.district[i].lights[k].linearConstant);
				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[13].quadraticConstant"),  gameLevel.district[i].lights[k].quadraticConstant);
				//	
				//	if(gameLevel.district[i].lights[k].spotLight)
				//	{
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
				//		GLfloat spot_direction[] = {0.0, -1.0, 0.0};
				//		//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[13].spotCutoff"), 45.0);
				//		glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[13].spotDirection"), 1, spot_direction);
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[13].spotExponent"), 2.0);
				//	}
				//	else
				//	{
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[13].spotCutoff"), 180.0);
				//	}
				//}
				//else if(k == 14)
				//{
				//	//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[14].position"), 1, lightPos.v);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[14].color"), 1, gameLevel.district[i].lights[k].LightColor);

				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[14].linearConstant"),  gameLevel.district[i].lights[k].linearConstant);
				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[14].quadraticConstant"),  gameLevel.district[i].lights[k].quadraticConstant);
				//	
				//	if(gameLevel.district[i].lights[k].spotLight)
				//	{
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
				//		GLfloat spot_direction[] = {0.0, -1.0, 0.0};
				//		//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[14].spotCutoff"), 45.0);
				//		glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[14].spotDirection"), 1, spot_direction);
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[14].spotExponent"), 2.0);
				//	}
				//	else
				//	{
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[14].spotCutoff"), 180.0);
				//	}
				//}

				////draw a cube to symbolize where the light source is
				//if(gameLevel.district[i].lights[k].drawPoint)
				//{
				//	glDisable(GL_LIGHTING);
				//	glPushMatrix();
				//	glTranslatef(gameLevel.district[i].lights[k].LightPosition[0], gameLevel.district[i].lights[k].LightPosition[1], gameLevel.district[i].lights[k].LightPosition[2]);
				//	drawBox(2.0f , 2.0f, 2.0f);
				//	glPopMatrix();
				//	glEnable(GL_LIGHTING);	
				//}
			}

			//draws all of the npcs for the particular district
			for(std::list<regularNPC*>::iterator npc = gameLevel.district[i].NPCList.begin(); npc != gameLevel.district[i].NPCList.end();)
			{
				//if ((*npc)->alive)
				//{
					(*npc)->drawCharacter();
				//}

				*npc++;
			}

			//draws the models and tectures for the particular district
			shader->ShaderProgram->Deactivate();
			shader->NormalMap_Shader->Activate();
			glUniform1i(glGetUniformLocation(shader->NormalMap_Shader->GetHandle(), "numLights"), gameLevel.district[i].normalLights.size());

			for(unsigned int k = 0; k < gameLevel.district[i].normalLights.size(); k++)
			{
				glLightfv(GL_LIGHT0 + k, GL_DIFFUSE, gameLevel.district[i].normalLights[k].LightColor);				//sets light intensity
				glLightfv(GL_LIGHT0 + k, GL_POSITION, gameLevel.district[i].normalLights[k].LightPosition);			//sets postion of light
					
				if(gameLevel.district[i].normalLights[k].spotLight)
				{
					glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
					GLfloat spot_direction[] = {0.0, -1.0, 0.0};
					glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
					glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);
				}

				/*if(gameLevel.district[i].normalLights[k].drawPoint)
				{
					glDisable(GL_LIGHTING);
					glPushMatrix();
					glTranslatef(gameLevel.district[i].normalLights[k].LightPosition[0], gameLevel.district[i].normalLights[k].LightPosition[1], gameLevel.district[i].normalLights[k].LightPosition[2]);
					drawBox(2.0f , 2.0f, 2.0f);
					glPopMatrix();
					glEnable(GL_LIGHTING);	
				}*/
			}

			glPushMatrix();
			glTranslatef(gameLevel.district[i].collisionMask.theMask.startingOffset[0] * gameLevel.district[i].collisionMask.theMask.scaleX, -8.0f, gameLevel.district[i].collisionMask.theMask.startingOffset[2] * gameLevel.district[i].collisionMask.theMask.scaleZ);
			glScalef(3.0f, 3.0f, 3.0f);
			std::list<objLoader*>::iterator k = gameLevel.district[i].sectionModels.begin();
			std::list<tex*>::iterator j = gameLevel.district[i].sectionTexs.begin();
			std::list<tex*>::iterator l = gameLevel.district[i].sectionNormalMaps.begin();
			for(; k != gameLevel.district[i].sectionModels.end();)
			{
				glUniform1i(glGetUniformLocation(shader->NormalMap_Shader->GetHandle(), "myTextureSampler0"), 0);

				glUniform1i(glGetUniformLocation(shader->NormalMap_Shader->GetHandle(), "myTextureSampler1"), 1);

				(*j)->drawTex(0);

				(*l)->drawTex(1);
				
				(*k)->drawModel();

				j++;
				l++;
				k++;
			}
			glPopMatrix();
			shader->NormalMap_Shader->Deactivate();
			
			//draws the player's bullets
			//shader->Bullets_Shader->Activate();
			drawProjectile(gameLevel.district->Bullets, shader);
			//shader->Bullets_Shader->Deactivate();
			
			shader->ShaderProgram->Activate();
		}
	}

	glPopMatrix();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

void Level::drawInterior(int n, Shader *shader)
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);

	//glDisable(GL_FOG);

	//draws all of the models in the interior
	for(int i = 0; i < numInteriors; i++)
	{
		//we have found the right interior to render
		if(i == n)
		{	
			/*LIGHTS*/
			glUniform1i(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "numLights"), gameLevel.interior[i].lights.size());


			//add ambient light (shines everwhere in our sceen by the same amount, so every face get lit by the same amount)
			//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, gameLevel.district[i].ambientLightColor);
			glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "globalAmbient"), 1, gameLevel.interior[i].ambientLightColor);

			//////add directed light and sets it to light0
			//glLightfv(GL_LIGHT0, GL_DIFFUSE, gameLevel.district[i].directedLightColor);				//sets light intensity
			//glLightfv(GL_LIGHT0, GL_POSITION, gameLevel.district[i].directedLightPosition);			//sets postion of light
			int numLights = gameLevel.interior[i].lights.size();

			if(numLights < 8)
			{
				// do nothing
			}
			else
			{
				numLights = 8; //max lights
			}

			//render dynamic lights
			for(int k = 0; k < numLights; k++)
			{
				//glLightfv(GL_LIGHT0 + k, GL_DIFFUSE, gameLevel.district[i].lights[k].LightColor);				//sets light intensity
				//glLightfv(GL_LIGHT0 + k, GL_POSITION, gameLevel.district[i].lights[0].LightPosition);			//sets postion of light

				GLfloat modelView[16];
				glGetFloatv(GL_MODELVIEW_MATRIX, modelView);

				Mat4f glModelView = Mat4f(modelView);

				Vec4f lightPos = Vec4f(gameLevel.interior[i].lights[k].LightPosition[0], gameLevel.interior[i].lights[k].LightPosition[1], gameLevel.interior[i].lights[k].LightPosition[2], 1.0f);
				lightPos = glModelView.transpose() * lightPos; 
				lightPos[3] = gameLevel.interior[i].lights[k].LightPosition[3];


				if(k == 0)
				{
					//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, lightPos.v);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].color"), 1, gameLevel.interior[i].lights[k].LightColor);

					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].linearConstant"),  gameLevel.interior[i].lights[k].linearConstant);
					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].quadraticConstant"),  gameLevel.interior[i].lights[k].quadraticConstant);
					
					if(gameLevel.interior[i].lights[k].spotLight)
					{
						//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
						GLfloat spot_direction[] = {0.0, -1.0, 0.0};
						//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
						//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].spotCutoff"), 45.0);
						glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].spotDirection"), 1, spot_direction);
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].spotExponent"), 2.0);
					}
					else
					{
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].spotCutoff"), 180.0);
					}
				}
				else if(k == 1)
				{
					//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[1].position"), 1, lightPos.v);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[1].color"), 1, gameLevel.interior[i].lights[k].LightColor);

					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[1].linearConstant"),  gameLevel.interior[i].lights[k].linearConstant);
					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[1].quadraticConstant"),  gameLevel.interior[i].lights[k].quadraticConstant);
					
					if(gameLevel.interior[i].lights[k].spotLight)
					{
						//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
						GLfloat spot_direction[] = {0.0, -1.0, 0.0};
						//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
						//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[1].spotCutoff"), 45.0);
						glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[1].spotDirection"), 1, spot_direction);
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[1].spotExponent"), 2.0);
					}
					else
					{
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[1].spotCutoff"), 180.0);
					}
				}
				else if(k == 2)
				{
					//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[2].position"), 1, lightPos.v);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[2].color"), 1, gameLevel.interior[i].lights[k].LightColor);

					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[2].linearConstant"),  gameLevel.interior[i].lights[k].linearConstant);
					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[2].quadraticConstant"),  gameLevel.interior[i].lights[k].quadraticConstant);
					
					if(gameLevel.interior[i].lights[k].spotLight)
					{
						//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
						GLfloat spot_direction[] = {0.0, -1.0, 0.0};
						//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
						//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[2].spotCutoff"), 45.0);
						glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[2].spotDirection"), 1, spot_direction);
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[2].spotExponent"), 2.0);
					}
					else
					{
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[2].spotCutoff"), 180.0);
					}
				}
				else if(k == 3)
				{
					//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[3].position"), 1, lightPos.v);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[3].color"), 1, gameLevel.interior[i].lights[k].LightColor);

					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[3].linearConstant"),  gameLevel.interior[i].lights[k].linearConstant);
					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[3].quadraticConstant"),  gameLevel.interior[i].lights[k].quadraticConstant);
					
					if(gameLevel.interior[i].lights[k].spotLight)
					{
						//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
						GLfloat spot_direction[] = {0.0, -1.0, 0.0};
						//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
						//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[3].spotCutoff"), 45.0);
						glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[3].spotDirection"), 1, spot_direction);
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[3].spotExponent"), 2.0);
					}
					else
					{
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[3].spotCutoff"), 180.0);
					}

				}
				else if(k == 4)
				{
					//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[4].position"), 1, lightPos.v);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[4].color"), 1, gameLevel.interior[i].lights[k].LightColor);

					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[4].linearConstant"),  gameLevel.interior[i].lights[k].linearConstant);
					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[4].quadraticConstant"),  gameLevel.interior[i].lights[k].quadraticConstant);
					
					if(gameLevel.interior[i].lights[k].spotLight)
					{
						//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
						GLfloat spot_direction[] = {0.0, -1.0, 0.0};
						//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
						//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[4].spotCutoff"), 45.0);
						glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[4].spotDirection"), 1, spot_direction);
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[4].spotExponent"), 2.0);
					}
					else
					{
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[4].spotCutoff"), 180.0);
					}
				}
				else if(k == 5)
				{
					//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[5].position"), 1, lightPos.v);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[5].color"), 1, gameLevel.interior[i].lights[k].LightColor);

					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[5].linearConstant"),  gameLevel.interior[i].lights[k].linearConstant);
					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[5].quadraticConstant"),  gameLevel.interior[i].lights[k].quadraticConstant);
					
					if(gameLevel.interior[i].lights[k].spotLight)
					{
						//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
						GLfloat spot_direction[] = {0.0, -1.0, 0.0};
						//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
						//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[5].spotCutoff"), 45.0);
						glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[5].spotDirection"), 1, spot_direction);
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[5].spotExponent"), 2.0);
					}
					else
					{
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[5].spotCutoff"), 180.0);
					}
				}
				else if(k == 6)
				{
					//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[6].position"), 1, lightPos.v);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[6].color"), 1, gameLevel.interior[i].lights[k].LightColor);

					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[6].linearConstant"),  gameLevel.interior[i].lights[k].linearConstant);
					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[6].quadraticConstant"),  gameLevel.interior[i].lights[k].quadraticConstant);
					
					if(gameLevel.interior[i].lights[k].spotLight)
					{
						//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
						GLfloat spot_direction[] = {0.0, -1.0, 0.0};
						//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
						//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[6].spotCutoff"), 45.0);
						glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[6].spotDirection"), 1, spot_direction);
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[6].spotExponent"), 2.0);
					}
					else
					{
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[6].spotCutoff"), 180.0);
					}
				}
				else if(k == 7)
				{
					//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[7].position"), 1, lightPos.v);
					glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[7].color"), 1, gameLevel.interior[i].lights[k].LightColor);

					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[7].linearConstant"),  gameLevel.interior[i].lights[k].linearConstant);
					glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[7].quadraticConstant"),  gameLevel.interior[i].lights[k].quadraticConstant);
					
					if(gameLevel.interior[i].lights[k].spotLight)
					{
						//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
						GLfloat spot_direction[] = {0.0, -1.0, 0.0};
						//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
						//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[7].spotCutoff"), 45.0);
						glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[7].spotDirection"), 1, spot_direction);
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[7].spotExponent"), 2.0);
					}
					else
					{
						glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[7].spotCutoff"), 180.0);
					}
				}
				//else if(k == 8)
				//{
				//	//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[8].position"), 1, lightPos.v);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[8].color"), 1, gameLevel.interior[i].lights[k].LightColor);

				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[8].linearConstant"),  gameLevel.interior[i].lights[k].linearConstant);
				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[8].quadraticConstant"),  gameLevel.interior[i].lights[k].quadraticConstant);
				//	
				//	if(gameLevel.interior[i].lights[k].spotLight)
				//	{
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
				//		GLfloat spot_direction[] = {0.0, -1.0, 0.0};
				//		//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[8].spotCutoff"), 45.0);
				//		glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[8].spotDirection"), 1, spot_direction);
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[8].spotExponent"), 2.0);
				//	}
				//	else
				//	{
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[8].spotCutoff"), 180.0);
				//	}
				//}
				//else if(k == 9)
				//{
				//	//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[9].position"), 1, lightPos.v);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[9].color"), 1, gameLevel.interior[i].lights[k].LightColor);

				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[9].linearConstant"),  gameLevel.interior[i].lights[k].linearConstant);
				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[9].quadraticConstant"),  gameLevel.interior[i].lights[k].quadraticConstant);
				//	
				//	if(gameLevel.interior[i].lights[k].spotLight)
				//	{
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
				//		GLfloat spot_direction[] = {0.0, -1.0, 0.0};
				//		//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[9].spotCutoff"), 45.0);
				//		glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[9].spotDirection"), 1, spot_direction);
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[9].spotExponent"), 2.0);
				//	}
				//	else
				//	{
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[9].spotCutoff"), 180.0);
				//	}
				//}
				//else if(k == 10)
				//{
				//	//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[10].position"), 1, lightPos.v);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[10].color"), 1, gameLevel.interior[i].lights[k].LightColor);

				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[10].linearConstant"),  gameLevel.interior[i].lights[k].linearConstant);
				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[10].quadraticConstant"),  gameLevel.interior[i].lights[k].quadraticConstant);
				//	
				//	if(gameLevel.interior[i].lights[k].spotLight)
				//	{
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
				//		GLfloat spot_direction[] = {0.0, -1.0, 0.0};
				//		//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[10].spotCutoff"), 45.0);
				//		glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[10].spotDirection"), 1, spot_direction);
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[10].spotExponent"), 2.0);
				//	}
				//	else
				//	{
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[10].spotCutoff"), 180.0);
				//	}
				//}
				//else if(k == 11)
				//{
				//	//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[11].position"), 1, lightPos.v);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[11].color"), 1, gameLevel.interior[i].lights[k].LightColor);

				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[11].linearConstant"),  gameLevel.interior[i].lights[k].linearConstant);
				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[11].quadraticConstant"),  gameLevel.interior[i].lights[k].quadraticConstant);
				//	
				//	if(gameLevel.interior[i].lights[k].spotLight)
				//	{
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
				//		GLfloat spot_direction[] = {0.0, -1.0, 0.0};
				//		//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[11].spotCutoff"), 45.0);
				//		glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[11].spotDirection"), 1, spot_direction);
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[11].spotExponent"), 2.0);
				//	}
				//	else
				//	{
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[11].spotCutoff"), 180.0);
				//	}
				//}
				//else if(k == 12)
				//{
				//	//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[12].position"), 1, lightPos.v);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[12].color"), 1, gameLevel.interior[i].lights[k].LightColor);

				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[12].linearConstant"),  gameLevel.interior[i].lights[k].linearConstant);
				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[12].quadraticConstant"),  gameLevel.interior[i].lights[k].quadraticConstant);
				//	
				//	if(gameLevel.interior[i].lights[k].spotLight)
				//	{
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
				//		GLfloat spot_direction[] = {0.0, -1.0, 0.0};
				//		//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[12].spotCutoff"), 45.0);
				//		glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[12].spotDirection"), 1, spot_direction);
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[12].spotExponent"), 2.0);
				//	}
				//	else
				//	{
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[12].spotCutoff"), 180.0);
				//	}
				//}
				//else if(k == 13)
				//{
				//	//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[13].position"), 1, lightPos.v);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[13].color"), 1, gameLevel.interior[i].lights[k].LightColor);

				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[13].linearConstant"),  gameLevel.interior[i].lights[k].linearConstant);
				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[13].quadraticConstant"),  gameLevel.interior[i].lights[k].quadraticConstant);
				//	
				//	if(gameLevel.interior[i].lights[k].spotLight)
				//	{
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
				//		GLfloat spot_direction[] = {0.0, -1.0, 0.0};
				//		//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[13].spotCutoff"), 45.0);
				//		glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[13].spotDirection"), 1, spot_direction);
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[13].spotExponent"), 2.0);
				//	}
				//	else
				//	{
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[13].spotCutoff"), 180.0);
				//	}
				//}
				//else if(k == 14)
				//{
				//	//glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[0].position"), 1, gameLevel.district[i].lights[0].LightPosition);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[14].position"), 1, lightPos.v);
				//	glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[14].color"), 1, gameLevel.interior[i].lights[k].LightColor);

				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[14].linearConstant"),  gameLevel.interior[i].lights[k].linearConstant);
				//	glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[14].quadraticConstant"),  gameLevel.interior[i].lights[k].quadraticConstant);
				//	
				//	if(gameLevel.interior[i].lights[k].spotLight)
				//	{
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_CUTOFF, 45.0);
				//		GLfloat spot_direction[] = {0.0, -1.0, 0.0};
				//		//glLightfv(GL_LIGHT0 + k, GL_SPOT_DIRECTION, spot_direction);
				//		//glLightf(GL_LIGHT0 + k, GL_SPOT_EXPONENT, 2.0);*/
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[14].spotCutoff"), 45.0);
				//		glUniform4fv(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[14].spotDirection"), 1, spot_direction);
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[14].spotExponent"), 2.0);
				//	}
				//	else
				//	{
				//		glUniform1f(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "gameLights[14].spotCutoff"), 180.0);
				//	}
				//}

				////draw a cube to symbolize where the light source is
				//if(gameLevel.interior[i].lights[k].drawPoint)
				//{
				//	glDisable(GL_LIGHTING);
				//	glPushMatrix();
				//	glTranslatef(gameLevel.interior[i].lights[k].LightPosition[0], gameLevel.interior[i].lights[k].LightPosition[1], gameLevel.interior[i].lights[k].LightPosition[2]);
				//	drawBox(2.0f , 2.0f, 2.0f);
				//	glPopMatrix();
				//	glEnable(GL_LIGHTING);	
				//}
			}

			//draws all of the npcs for the particular interior
			for(std::list<regularNPC*>::iterator npc = gameLevel.interior[i].NPCList.begin(); npc != gameLevel.interior[i].NPCList.end();)
			{
				//if ((*npc)->alive)
				//{
					(*npc)->drawCharacter();
				//}

				*npc++;
			}

			//draws the models and tectures for the particular interior
			//glDisable(GL_LIGHTING);
			shader->ShaderProgram->Deactivate();
			//shader->NormalMap_Shader->Activate();
			shader->interiorShader->Activate();
			glPushMatrix();
			glTranslatef(gameLevel.interior[i].collisionMask.theMask.startingOffset[0] * gameLevel.interior[i].collisionMask.theMask.scaleX, -8.0f, gameLevel.interior[i].collisionMask.theMask.startingOffset[2] * gameLevel.interior[i].collisionMask.theMask.scaleZ);
			/*glPushMatrix();
			glTranslatef(0.0f, 10.0f, 0.0f);
			gameLevel.interior[0].collisionMask.theMask.draw();
			glPopMatrix();*/
			glScalef(3.0f, 3.0f, 3.0f);
			std::list<objLoader*>::iterator k = gameLevel.interior[i].sectionModels.begin();
			std::list<tex*>::iterator j = gameLevel.interior[i].sectionTexs.begin();
			for(; k != gameLevel.interior[i].sectionModels.end();)
			{
				(*j)->drawTex(0);
				(*k)->drawModel();
				j++;
				k++;
			}
			glPopMatrix();
			//glEnable(GL_LIGHTING);
			//shader->NormalMap_Shader->Deactivate();
			shader->interiorShader->Deactivate();

			//draws the player's bullets
			drawProjectile(gameLevel.interior[i].Bullets, shader);

			shader->ShaderProgram->Activate();
		}
	}

	//glEnable(GL_FOG);
	glPopMatrix();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

//Just in case we need to update something over time
//NPCS WILL BE UPDATED HERE
void Level::updateDistrict(playerStats *thePlayer, camera1 *theCamera, bool &interor, bool &district, int &districtID, int &interiorID, bool &drawE, float dt, sound::GameSound *AISounds[])
{
	int n = districtID; 

	//cycles through all the districts and finds which one to currently update
	for(int i = 0; i < numDistricts; i++)
	{
		//we have found the right district to update
		if(i == n)
		{	
			//if there are more than 7 lights in the district
			if(gameLevel.district[i].lights.size() > 7)
			{
				//find the distance each light is away from the player
				for(unsigned int k = 0; k < gameLevel.district[i].lights.size(); k++)
				{
					gameLevel.district[i].lights[k].rank = (Vec3f(gameLevel.district[i].lights[k].LightPosition[0], gameLevel.district[i].lights[k].LightPosition[1], gameLevel.district[i].lights[k].LightPosition[2]) - thePlayer->position).magnitude();
				}

				//sort the list from the smalles rank to the largest (bubblesort)
				//*******************SORT*********************************************//
				//bubble sort
				for(unsigned int counter = 0; counter < gameLevel.district[i].lights.size(); counter++)
				{
					unsigned int countEnd = gameLevel.district[i].lights.size() - 1;

					while(countEnd > counter)
					{
						if(gameLevel.district[i].lights[countEnd].rank < gameLevel.district[i].lights[countEnd - 1].rank)
						{
							Light temp;

							temp = gameLevel.district[i].lights[countEnd];

							gameLevel.district[i].lights[countEnd] = gameLevel.district[i].lights[countEnd - 1];
							gameLevel.district[i].lights[countEnd - 1] = temp;

						}
						countEnd--;
					}

				}
			}

			//if there are more than 7 normal light in the district
			if(gameLevel.district[i].normalLights.size() > 7)
			{
				//find the distance each light is away from the player
				for(unsigned int k = 0; k < gameLevel.district[i].normalLights.size(); k++)
				{
					gameLevel.district[i].normalLights[k].rank = (Vec3f(gameLevel.district[i].normalLights[k].LightPosition[0], gameLevel.district[i].normalLights[k].LightPosition[1], gameLevel.district[i].normalLights[k].LightPosition[2]) - thePlayer->position).magnitude();
				}

				//sort the list from the smalles rank to the largest (bubblesort)
				//*******************SORT*********************************************//
				//bubble sort
				for(unsigned int counter = 0; counter < gameLevel.district[i].normalLights.size(); counter++)
				{
					unsigned int countEnd = gameLevel.district[i].normalLights.size() - 1;

					while(countEnd > counter)
					{
						if(gameLevel.district[i].normalLights[countEnd].rank < gameLevel.district[i].normalLights[countEnd - 1].rank)
						{
							Light temp;

							temp = gameLevel.district[i].normalLights[countEnd];

							gameLevel.district[i].normalLights[countEnd] = gameLevel.district[i].normalLights[countEnd - 1];
							gameLevel.district[i].normalLights[countEnd - 1] = temp;

						}
						countEnd--;
					}

				}
			}


			//****Run NPC functions********
			for(std::list<regularNPC*>::iterator npc = gameLevel.district[i].NPCList.begin(); npc != gameLevel.district[i].NPCList.end();)
			 {
				  //if npc is alive
				  if ((*npc)->alive)
				  {
				   //reset hostile variable, to check if anything is hostile with its updated position.
					   (*npc)->isHostile = false;

					   //loop through available npcs
					   for(std::list<regularNPC*>::iterator npc2 = gameLevel.district[i].NPCList.begin(); npc2 != gameLevel.district[i].NPCList.end();)
					   {
							//if other npc is alive and it isnt the same npc
							if (((*npc2) != (*npc)) && (*npc2)->alive && (*npc2)->isHostile == true)
							{
								(*npc)->checkForHostiles((*npc2)); 
							}

							*npc2++;
					   }

					   //check character hostility for each NPC, then update their AI
					   if((*npc)->checkForHostiles(thePlayer, &gameLevel.district->collisionMask, AISounds) && (*npc)->autoAttack)
					   {
						   timeSinceDiscovered.restart();
					   }
					   (*npc)->updateCharacter(dt, gameLevel.district[i].levelCollisionMap, gameLevel.district->Bullets, &gameLevel.district->collisionMask, thePlayer->position, AISounds);
					}

				*npc++;
			 }
			//********************

			//damage to player
			thePlayer->checkForDamages(gameLevel.district[i].Bullets, dt);

			//updates the level's bullets
			updateProjectile(gameLevel.district[i].Bullets, &gameLevel.district[i].collisionMask, thePlayer->theta, dt, thePlayer->position);

			//find if the player is able to go to a new area
			for(unsigned int a = 0; a < gameLevel.district[i].Areas.size(); a++)
			{
				//if player is in collision zone display "Press E to enter" texture
				if(thePlayer->cObject.collisionTest( gameLevel.district[i].Areas[a]->collisionZone))
				{
					drawE = true;
					//if the player presses E go to new area
					if(thePlayer->input.E)
					{
						//play door sound
						AISounds[13]->updateSound(gameLevel.district[i].Areas[a]->playerPos);
						AISounds[13]->playSound();
						AISounds[13]->isPlaying = false;

						thePlayer->recentlyAttacked = thePlayer->relaxingPeriod + 1; 
						thePlayer->isHostile = false;

						for(std::list<regularNPC*>::iterator npc = gameLevel.district[i].NPCList.begin(); npc != gameLevel.district[i].NPCList.end();)
						{
							if(!(*npc)->alive)
							{
								(*npc)->health = 100;
								(*npc)->alive = true;
								(*npc)->prevAIState = 6;
								(*npc)->currentAIState = 4;

								(*npc)->aiPath.Reset();
								(*npc)->aiPath.Start();

								(*npc)->position = (*npc)->startingPosition; 

								//so the npc orientates themselves properly
								(*npc)->firstRun = true;

								//so their death animations can replay
								(*npc)->animations.Death.doneAnimation = false;
								(*npc)->animations.Death.reset();

							}
							*npc++;
						}

						//if next area is district
						if(gameLevel.district[i].Areas[a]->district)
						{
							district = true;
							interor = false;
							districtID = gameLevel.district[i].Areas[a]->ID;

							//update player's new position
							thePlayer->position = gameLevel.district[i].Areas[a]->playerPos;
							theCamera->playerPoint = gameLevel.district[i].Areas[a]->playerPos;
							theCamera->playerPointReserved = gameLevel.district[i].Areas[a]->playerPos; 
							theCamera->updateCamera(*thePlayer);
							//updateCamera();
						}
						else
						{
							interor = true;
							district = false;
							interiorID = gameLevel.district[i].Areas[a]->ID;
							
							//update player's new position
							thePlayer->position = gameLevel.district[i].Areas[a]->playerPos;
							theCamera->playerPoint = gameLevel.district[i].Areas[a]->playerPos;
							theCamera->playerPointReserved = gameLevel.district[i].Areas[a]->playerPos; 
							theCamera->updateCamera(*thePlayer);
							//updateCamera();
						}
					}
				}
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//NPCS WILL BE UPDATED HERE
void Level::updateInterior(playerStats *thePlayer, camera1 *theCamera, bool &interor, bool &district, int &districtID, int &interiorID, bool &drawE, float dt, sound::GameSound *AISounds[])
{
	int n = interiorID; 
	//cycles through all the districts and finds which one to currently update
	for(int i = 0; i < numInteriors; i++)
	{
		//we have found the right district to update
		if(i == n)
		{	
			//if there are more than 7 lights in the interior
			if(gameLevel.interior[i].lights.size() > 7)
			{
				//find the distance each light is away from the player
				for(unsigned int k = 0; k < gameLevel.interior[i].lights.size(); k++)
				{
					gameLevel.interior[i].lights[k].rank = (Vec3f(gameLevel.interior[i].lights[k].LightPosition[0], gameLevel.interior[i].lights[k].LightPosition[1], gameLevel.interior[i].lights[k].LightPosition[2]) - thePlayer->position).magnitude();
				}

				//sort the list from the smalles rank to the largest (bubblesort)
				//*******************SORT*********************************************//
				//bubble sort
				for(unsigned int counter = 0; counter < gameLevel.interior[i].lights.size(); counter++)
				{
					unsigned int countEnd = gameLevel.interior[i].lights.size() - 1;

					while(countEnd > counter)
					{
						if(gameLevel.interior[i].lights[countEnd].rank < gameLevel.interior[i].lights[countEnd - 1].rank)
						{
							Light temp;

							temp = gameLevel.interior[i].lights[countEnd];

							gameLevel.interior[i].lights[countEnd] = gameLevel.interior[i].lights[countEnd - 1];
							gameLevel.interior[i].lights[countEnd - 1] = temp;

						}
						countEnd--;
					}

				}
			}

			//Run NPC functions
			for(std::list<regularNPC*>::iterator npc = gameLevel.interior[i].NPCList.begin(); npc != gameLevel.interior[i].NPCList.end();)
			 {
				  //if npc is alive
				  if ((*npc)->alive)
				  {
				   //reset hostile variable, to check if anything is hostile with its updated position.
					   (*npc)->isHostile = false;

					   //loop through available npcs
					   for(std::list<regularNPC*>::iterator npc2 = gameLevel.interior[i].NPCList.begin(); npc2 != gameLevel.interior[i].NPCList.end();)
					   {
							//if other npc is alive and it isnt the same npc
							if (((*npc2) != (*npc)) && (*npc2)->alive && (*npc2)->isHostile == true)
							{
								(*npc)->checkForHostiles((*npc2)); 
							}

							*npc2++;
					   }

					   //check character hostility for each NPC, then update their AI
					   //(*npc)->checkForHostiles(thePlayer, &gameLevel.interior->collisionMask);
					   if((*npc)->checkForHostiles(thePlayer, &gameLevel.interior[i].collisionMask, AISounds) && (*npc)->autoAttack)
					   {
						   timeSinceDiscovered.restart();
					   }
					   (*npc)->updateCharacter(dt, gameLevel.interior[i].levelCollisionMap, gameLevel.interior[i].Bullets, &gameLevel.interior[i].collisionMask, thePlayer->position, AISounds);
					}

				*npc++;
			 }

			//damage to player
			thePlayer->checkForDamages(gameLevel.interior[i].Bullets, dt);

			//updates the level's bullets
			updateProjectile(gameLevel.interior[i].Bullets, &gameLevel.interior[i].collisionMask, thePlayer->theta, dt, thePlayer->position);

			//find if the player is able to go to a new area
			for(unsigned int a = 0; a < gameLevel.interior[i].Areas.size(); a++)
			{
				//if player is in collision zone display "Press E to enter" texture
				if(thePlayer->cObject.collisionTest( gameLevel.interior[i].Areas[a]->collisionZone))
				{
					drawE = true;

					//if the player presses E go to new area
					if(thePlayer->input.E)
					{
						//play door sound
						AISounds[13]->updateSound(gameLevel.interior[i].Areas[a]->playerPos);
						AISounds[13]->playSound();
						AISounds[13]->isPlaying = false;

						thePlayer->recentlyAttacked = thePlayer->relaxingPeriod + 1; 
						thePlayer->isHostile = false;

						for(std::list<regularNPC*>::iterator npc = gameLevel.interior[i].NPCList.begin(); npc != gameLevel.interior[i].NPCList.end();)
						{
							if(!(*npc)->alive)
							{
								(*npc)->health = 100;
								(*npc)->alive = true;
								(*npc)->prevAIState = 6;
								(*npc)->currentAIState = 4;

								(*npc)->aiPath.Reset();
								(*npc)->aiPath.Start();

								(*npc)->position = (*npc)->startingPosition; 

								//so the npc orientates themselves properly
								(*npc)->firstRun = true;

								//so their death animations can replay
								(*npc)->animations.Death.doneAnimation = false;
								(*npc)->animations.Death.reset();
							}
							*npc++;
						}

						//if next area is district
						if(gameLevel.interior[i].Areas[a]->district)
						{
							district = true;
							interor = false;
							districtID = gameLevel.interior[i].Areas[a]->ID;

							//update player's new position
							thePlayer->position = gameLevel.interior[i].Areas[a]->playerPos;
							theCamera->playerPoint = gameLevel.interior[i].Areas[a]->playerPos;
							theCamera->playerPointReserved = gameLevel.interior[i].Areas[a]->playerPos; 
							theCamera->updateCamera(*thePlayer);
							//updateCamera();
						}
						else
						{
							interor = true;
							district = false;
							interiorID = gameLevel.interior[i].Areas[a]->ID;
							
							//update player's new position
							thePlayer->position = gameLevel.interior[i].Areas[a]->playerPos;
							theCamera->playerPoint = gameLevel.interior[i].Areas[a]->playerPos;
							theCamera->playerPointReserved = gameLevel.interior[i].Areas[a]->playerPos; 
							theCamera->updateCamera(*thePlayer);
							//updateCamera();
						}
					}
				}
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//void Level::loadMissions()
//{
//	missions.loadGameMissions();
//}
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//void Level::updateMissions(playerStats player, float dt)
//{
//	missions.updateGameMissions(player, dt);
//}
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//void Level::drawMissions()
//{
//	missions.drawGameMissions();
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////

//clears the memeory
void Level::deleteLevel()
{
	//deletes all of the models in the district
	for(int i = 0; i < numDistricts; i++)
	{
		//deletes the models and tectures for the particular district
		std::list<objLoader*>::iterator k = gameLevel.district[i].sectionModels.begin();
		std::list<tex*>::iterator j = gameLevel.district[i].sectionTexs.begin();
		for(; k != gameLevel.district[i].sectionModels.end();)
		{
			k = gameLevel.district[i].sectionModels.erase(k);
			j = gameLevel.district[i].sectionTexs.erase(j);
		}
		
	}

	//deletes all of the models in the district
	for(int i = 0; i < numInteriors; i++)
	{
		//deletes the models and tectures for the particular district
		std::list<objLoader*>::iterator k = gameLevel.interior[i].sectionModels.begin();
		std::list<tex*>::iterator j = gameLevel.interior[i].sectionTexs.begin();
		for(; k != gameLevel.interior[i].sectionModels.end();)
		{
			k = gameLevel.interior[i].sectionModels.erase(k);
			j = gameLevel.interior[i].sectionTexs.erase(j);
		}
		
	}
}