#include "game.h"

//-----------------------------------------------------------------------------

game::game()
{	
	player = playerStats();

	//used to help call the nessary functions to move the camera
	prevX = Vec3f(0.0f, 0.0f, 0.0f);
	prevY = Vec3f(0.0f, 0.0f, 0.0f);
	drawShapes = new drawPrimitives();

//**********LEVELS********************//
	//level 1 (redlight district)
	levels[0] = new Level1();
//***********************************//
	//PARTICLES//
	rain = new ParticleManager();
	splash = new ParticleManager();
//************************************//

	Vec3f l1CameraVector(0.0f, 10.f, -40.f);
	theCamera.setStartingVector(l1CameraVector);	
	theCamera.setSavedOffset(l1CameraVector);
	theCamera.setCurrentVector(theCamera.getStartingVector());
	
	theCamera.playerPoint = player.position;
	theCamera.playerPointReserved = player.position;
	
	theCamera.setPosition(/*player.position*/);

	player.state.fp = false;
	player.state.aiming = false;

	gameState.windowWidth = 800;
	gameState.windowHeight = 600;
	gameState.district = true;
	gameState.interior = false;

	gameState.districtID = 0;
	gameState.interiorID = 0;
	gameState.levelID = 0;

//*****COLLISIONS FOR PLAYER AND LEVEL*******//
	player.collisionSet(10.f);
	levels[0]->gameLevel.district[0].collisionList.push_back(&player.cObject);

	deathBool = true;

	numIterations = 0;
	frameRate = 0;
	deltaTime = 0.0f;

	FBO = new cbmini::cbfw::FrameBuffer;
	FBO_BP = new cbmini::cbfw::FrameBuffer;
	FBO_BOX_BLUR = new cbmini::cbfw::FrameBuffer;
	FBO_G_BLUR_X = new cbmini::cbfw::FrameBuffer;
	FBO_G_BLUR_Y = new cbmini::cbfw::FrameBuffer;
	FBO_FINAL = new cbmini::cbfw::FrameBuffer;
	HUD = new cbmini::cbfw::FrameBuffer;

	skyBox = new SkyBox(player.position);

	playMainMenuMusic = true;

	inGameMenu = gameMenu(&runningState, &menuClock);

	shrinkFactor = 8; 
	rippleTime =0;
	player.state.tp = true;

	bulletTex = new tex();

	displayCursor = true;

	ETimer = 0.0f;
	drawE = false;

	firstPersonTimer = 0.0f;
	vibrationTimer = 10.0f;

	gameState.currentTime = 0.0f;

	player.input.Lmouse = false;
	player.input.Lt = 0.0f; 
	player.input.Rt = 0.0f;
}

game::~game()
{
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
void game::runGame()
{
	//for creating the main window
	sf::ContextSettings contextSettings;
	
	// Request a 32-bits depth buffer when creating the window
    contextSettings.depthBits = 32;

	//renders smooth edges
	contextSettings.antialiasingLevel = 4; 

	//sf::Window
	sf::RenderWindow window(sf::VideoMode(gameState.windowWidth, gameState.windowHeight), "Telkram", sf::Style::Default, contextSettings);
	this->window = &window; 
	window.setMouseCursorVisible(false); // hide cursor

	//load curser and use it to create sprite
	sf::Texture texture;
	texture.loadFromFile("Images/Cursor/cursor2.png");
	sf::Sprite cursorSprite(texture);

	//load window icon
	tex *windowIcon;
	windowIcon = new tex();
	windowIcon->loadTex("Images/ObjectiveIcon/hand.png");
	window.setIcon(windowIcon->texMap.getSize().x, windowIcon->texMap.getSize().y, windowIcon->texMap.getPixelsPtr());

    // Create the main window
    window.setVerticalSyncEnabled(true);

    // Make it the active window for OpenGL calls
    window.setActive();
	
	//load and render loading screen
	UI loading = UI("Images/Misc/loadingscreen.png");
	//enable openGL functionality
	initRenderFunc();
	GLfloat ratio = (float)gameState.windowWidth/(float)gameState.windowHeight;
	initWindowFunc(ratio);

	glEnable(GL_BLEND);	//particles must have the background as transparent and must be in png format
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	//first parameter is the pixel you are currently drawing and second parameter is the old pixel
	shader->inGameMenuShader->Activate();
	
	loading.draw(Vec3f(0,0,0), Vec3f(0,0,-1), gameState.windowWidth, gameState.windowHeight);

	shader->inGameMenuShader->Deactivate();	
	glDisable(GL_BLEND);

	window.display();

	//Initialize the text for the GUI
	myGUIView = sf::View(window.getDefaultView());

	lerpTime = 0.8f;

	//loading the model and texture for the player
	//player.loadCharacter("Images/Characters/MainCharacterTextureV3.png","Models/Characters/Player/newPlayerModel.obj", 12000);

	//for the player's animation
	player.loadAnimations();
	
	////level must come before loading the missions
	levels[0]->loadLevel(&missions); 

	//load missions for entire game
	//can be placed somewhere else later
	missions.loadGameMissions();

//******************PARTICLES*****************************************//
	//500
	//rain
	//rain->setPositionRand(Vec3f(-350.0f,1.0f,-350.0f), Vec3f(600.0f,10.0f,600.0f));
	rain->setPositionRand(Vec3f(-80.0f,1.0f,-80.0f), Vec3f(150.0f,10.0f,150.0f));
	rain->setVerlocityRand(Vec3f(1, -10, 1), Vec3f(1, -20, 1));
	rain->setLifeTrans(false);
	rain->setCollisionPos(Vec3f(player.position[0],player.position[1] - 8.5f,player.position[2])); 
	rain->setAtrributes(Vec3f(0.0f, -60.0f, 0.0f), Vec3f(1.0f, 1.0f, 1.0f), Vec3f(player.position[0], 20, player.position[2]), Vec3f(0.0f, G, 0.0f), 1, 1, 1.00f, -1, 200, false); 
	rain->loadTex("Images/Particles/rainParticle1.png");

	particleSystems.push_back(rain);

	//rain splash
	splash->setPositionRand(Vec3f(-350.0f,1.0f,-350.0f), Vec3f(700.0f,1.0f,700.0f));
	splash->setLifeTrans(false);
	splash->setAtrributes(Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.8f, 0.8f, 0.8f), Vec3f(player.position[0], 0.0, player.position[2]), Vec3f(0.0f, 0.0f, 0.0f), 1, 1, 0.15f, -1, 300, false);  
	splash->loadTex("Images/Particles/splashParticle.png");

	//load bullet texture
	loadBulletTex();

///////////////////////////////////////////////////////////
	menuCube = new objLoader();
	menuCube->LoadOBJ("Models/Props/menuCube.obj", 20);
	menuCubeTexture = new tex();
	menuCubeTexture->loadTex("Models/Props/menuCubeGood.png");
	menuMask = Mask("Models/Props/mainMenuMask.png");
	menuMask1[mainMenu].loadFromFile("Models/Props/MenuMask.png");
	menuMask1[credits].loadFromFile("Models/Props/CreditsMask.png");
	menuMask1[options].loadFromFile("Models/Props/ControlsMask.png");
	menuState = mainMenu;
	runningState = menu;
	firstPress = false;
	transitionTime = 1.0f;
	lerpTime = 0.5f;
	theCamera.setLastState(theCamera.savedOffset);

	//set up that UI
	pressEToEnter = UI("Images/Misc/EtoEnter.png");
	pressAToEnter = UI("Images/Misc/AtoEnter.png");
	ui = UI("Models/Props/FogOfWar.png");
	deathUI = UI("Images/Misc/you_are_dead.png");
	cursor = UI("Models/Props/reticule3.png");
	inGameMenu.addUI("Images/InGameMenu/menu.png", "Images/InGameMenu/menuMask.png", inGameMenu.pause, sf::Vector3f(0, 0, 101));
	inGameMenu.addUI("Images/InGameMenu/missions.png", "Images/InGameMenu/missionsMask.png", inGameMenu.missions, sf::Vector3f(0, 101, 0));
	inGameMenu.addUI("Images/InGameMenu/options.png", "Images/InGameMenu/optionsMask.png", inGameMenu.options, sf::Vector3f(101, 0, 0));

	skyBox->initSkyBox();

	//player sounds
	rainSound = new sound::GameSound(sound::soundManager);
	rainSound->load3DSound("Sounds/Misc/rain1.mp3", player.position + (player.ZaxisPos * Vec3f(10, 0, 10)), Vec3f(0.0f, 0.0f, 0.0f), 0.5f, 5000.0f, true);
	rainSound->changeRollOff(true);
	
	test2Dsound = new sound::GameSound(sound::soundManager);
	test2Dsound->load2DSound("Sounds/Music/GameMusic.mp3", true);

	atmospheric = new sound::GameSound(sound::soundManager);
	atmospheric->load2DSound("Sounds/Music/atmospheric.mp3", true);
	
	clubMusic = new sound::GameSound(sound::soundManager);
	clubMusic->load3DSound("Sounds/Music/ClubMusic.mp3", Vec3f(143.229f, 42.144f, 115.68), Vec3f(0.0f, 0.0f, 0.0f), 0.5f, 500.0f, true);

	/*barMusic = new sound::GameSound(sound::soundManager);
	barMusic->load3DSound("Sounds/Music/ClubMusic.mp3", Vec3f(104.261f, 42.144f, 217.433), Vec3f(0.0f, 0.0f, 0.0f), 0.5f, 500.0f, true);*/

	lowBass = new sound::GameSound(sound::soundManager);
	lowBass->load3DSound("Sounds/Music/ClubMusicBass.mp3", Vec3f(277, 0, 146), Vec3f(0.0f, 0.0f, 0.0f), 0.5f, 5.0f, true);
	lowBass->changeRollOff(true);

	laserBlast = new sound::GameSound(sound::soundManager);
	laserBlast->load3DSound("Sounds/Shooting/laser_player.mp3", player.position, Vec3f(0.0f, 0.0f, 0.0f), 0.5f, 5000.0f, false);
	laserBlast->changeRollOff(true);

	//enterStealth
	stealth[0]= new sound::GameSound(sound::soundManager);
	stealth[0]->load2DSound("Sounds/Stealth/enterStealth.mp3", false);

	//instealth
	stealth[1]= new sound::GameSound(sound::soundManager);
	stealth[1]->load2DSound("Sounds/Stealth/inStealth.mp3", true);

	//discovered
	stealth[2]= new sound::GameSound(sound::soundManager);
	stealth[2]->load2DSound("Sounds/Stealth/discovered.mp3", false);
	
	death = new sound::GameSound(sound::soundManager);
	death->load3DSound("Sounds/Death/Pain.mp3", player.position, Vec3f(0.0f, 0.0f, 0.0f), 0.5f, 5000.0f, false);
	death->changeRollOff(true);
	
	//npc sounds
	//shooting
	AISounds[0] = new sound::GameSound(sound::soundManager);
	AISounds[0]->load3DSound("Sounds/Shooting/laser1.mp3", Vec3f(277, 0, 146), Vec3f(0.0f, 0.0f, 0.0f), 0.5f, 500.0f, false);
	AISounds[0]->changeRollOff(true);

	//death
	AISounds[1] = new sound::GameSound(sound::soundManager);
	AISounds[1]->load3DSound("Sounds/Death/dyingSound1.mp3", player.position, Vec3f(0.0f, 0.0f, 0.0f), 0.5f, 500.0f, false);
	AISounds[1]->changeRollOff(true);

	//attack 
	AISounds[2] = new sound::GameSound(sound::soundManager);
	AISounds[2]->load3DSound("Sounds/Dialogue/TheresTheAgent.mp3", player.position, Vec3f(0.0f, 0.0f, 0.0f), 0.5f, 500.0f, false);
	AISounds[2]->changeRollOff(true);

	//attack 2
	AISounds[3] = new sound::GameSound(sound::soundManager);
	AISounds[3]->load3DSound("Sounds/Dialogue/ThereHeIs.mp3", player.position, Vec3f(0.0f, 0.0f, 0.0f), 0.5f, 500.0f, false);
	AISounds[3]->changeRollOff(true);

	//attack 3
	AISounds[4] = new sound::GameSound(sound::soundManager);
	AISounds[4]->load3DSound("Sounds/Dialogue/ComeHereYou.mp3", player.position, Vec3f(0.0f, 0.0f, 0.0f), 0.5f, 500.0f, false);
	AISounds[4]->changeRollOff(true);

	//flee 
	AISounds[5] = new sound::GameSound(sound::soundManager);
	AISounds[5]->load3DSound("Sounds/Dialogue/YouDontHaveTheBalls.mp3", player.position, Vec3f(0.0f, 0.0f, 0.0f), 0.5f, 500.0f, false);
	AISounds[5]->changeRollOff(true);

	//ambient dialogue 1
	AISounds[6] = new sound::GameSound(sound::soundManager);
	AISounds[6]->load3DSound("Sounds/Dialogue/IUsedToBeAnAgent.mp3", player.position, Vec3f(0.0f, 0.0f, 0.0f), 0.5f, 500.0f, false);
	AISounds[6]->changeRollOff(true);

	//ambient dialogue 2
	AISounds[7] = new sound::GameSound(sound::soundManager);
	AISounds[7]->load3DSound("Sounds/Dialogue/didYouHearAboutThe.mp3", player.position, Vec3f(0.0f, 0.0f, 0.0f), 0.5f, 500.0f, false);
	AISounds[7]->changeRollOff(true);

	//flee 2
	AISounds[8] = new sound::GameSound(sound::soundManager);
	AISounds[8]->load3DSound("Sounds/Dialogue/scared1.mp3", player.position, Vec3f(0.0f, 0.0f, 0.0f), 0.5f, 500.0f, false);
	AISounds[8]->changeRollOff(true);

	//flee 3
	AISounds[9] = new sound::GameSound(sound::soundManager);
	AISounds[9]->load3DSound("Sounds/Dialogue/scared2.mp3", player.position, Vec3f(0.0f, 0.0f, 0.0f), 0.5f, 500.0f, false);
	AISounds[9]->changeRollOff(true);

	//death 2
	AISounds[10] = new sound::GameSound(sound::soundManager);
	AISounds[10]->load3DSound("Sounds/Death/dyingSound2.mp3", player.position, Vec3f(0.0f, 0.0f, 0.0f), 0.5f, 500.0f, false);
	AISounds[10]->changeRollOff(true);

	//death 3
	AISounds[11] = new sound::GameSound(sound::soundManager);
	AISounds[11]->load3DSound("Sounds/Death/dyingSound3.mp3", player.position, Vec3f(0.0f, 0.0f, 0.0f), 0.5f, 500.0f, false);
	AISounds[11]->changeRollOff(true);

	//death 4
	AISounds[12] = new sound::GameSound(sound::soundManager);
	AISounds[12]->load3DSound("Sounds/Death/dyingSound4.mp3", player.position, Vec3f(0.0f, 0.0f, 0.0f), 0.5f, 500.0f, false);
	AISounds[12]->changeRollOff(true);

	//door
	AISounds[13] = new sound::GameSound(sound::soundManager);
	AISounds[13]->load3DSound("Sounds/Misc/Futuristic_door.mp3", player.position, Vec3f(0.0f, 0.0f, 0.0f), 0.5f, 500.0f, false);
	AISounds[13]->changeRollOff(true);


	//initialize FBO
	FBO->Initialize(gameState.windowWidth,gameState.windowHeight, 1);
	FBO_BP->Initialize(gameState.windowWidth/shrinkFactor,gameState.windowHeight/shrinkFactor, 1, 0);
	FBO_G_BLUR_X->Initialize(gameState.windowWidth/shrinkFactor,gameState.windowHeight/shrinkFactor, 1, 0);
	FBO_G_BLUR_Y->Initialize(gameState.windowWidth/shrinkFactor,gameState.windowHeight/shrinkFactor, 1, 0);
	FBO_BOX_BLUR->Initialize(gameState.windowWidth/shrinkFactor,gameState.windowHeight/shrinkFactor, 1, 0);
	FBO_FINAL->Initialize(gameState.windowWidth, gameState.windowHeight, 1, 0);
	HUD->Initialize(gameState.windowWidth, gameState.windowHeight, 1);

//////////////////////////////////////////////////////////
	while(window.isOpen())
	{
		//handles user input whether it be by keyboard or joystick/controller
		handleInput();

		//process events

		//Mouse input
		sf::Vector2i TLocalPosition = sf::Mouse::getPosition(window);
		mouse.current = TLocalPosition;
		mouseMotion(mouse.current, &window);

		///////
		if(end == true)
		{
			cleanUp();
			window.close();
		}
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			//close window (exit button)
			if(Event.type == sf::Event::Closed)
			{
				cleanUp();
				window.close();
			}
			//escape key (exit game)
			if((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
			{
				//runningState = mainMenu;
			}

			if((Event.type == sf::Event::MouseButtonPressed) && (Event.key.code == sf::Mouse::Right) && (player.alive))
			{
				player.state.aiming = true;
				player.input.Rmouse = true;
				theCamera.setLastState(theCamera.getCurrentVector());
				cameraClock.restart();
			}
			
			if((Event.type == sf::Event::MouseButtonReleased) && (Event.key.code == sf::Mouse::Right) && (player.alive))
			{
				player.state.aiming = false;
				player.input.Rmouse = false;
				theCamera.setLastState(theCamera.getCurrentVector());
				cameraClock.restart();
			}

			//change perspective
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::P))
			{
				if(player.state.fp == false)
				{
					player.state.fp = true;
					player.state.tp = false;
				}
				else if(player.state.fp == true)
				{
					player.state.fp = false;
					player.state.tp = true;
				}
				theCamera.setLastState(theCamera.getCurrentVector());
				cameraClock.restart();
			}

			if((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::LControl))
			{
				//Ctrl button
				if(!player.state.sneaking)
				{
					stealth[0]->playSound();
					stealth[0]->isPlaying = false;

					player.input.LCtrl = true;
					player.state.sneaking = true;
					player.state.walking = false;
				}
				else if(player.state.sneaking)
				{
					player.input.LCtrl = false;
					player.state.sneaking = false;
					player.state.walking = true;
				}
			}

			if((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Space) && (player.alive) && player.playerMove)
			{
				if(player.position[1] <= player.landHeight)
				{
					player.state.jumping = true;
				}
				player.input.space = true;
			}
			/*if((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::H))
			{
				player.health-= 10;
			}*/
			/*if((Event.type == sf::Event::KeyReleased) && (Event.key.code == sf::Keyboard::F))
			{
				cout << "The current FrameRate is: " << frameRate << endl;
			}*/

			//adjust the viewport when the window is resized

			if(Event.type == sf::Event::Resized)
			{
				//tell openGL how to convert from coordinates to pixel values
				glViewport(0, 0, Event.size.width, Event.size.height);
				gameState.windowWidth = Event.size.width;
				gameState.windowHeight = Event.size.height;

				//resize the FBO resolution so it matches the window's
				FBO->Release();
				FBO->Initialize(gameState.windowWidth,gameState.windowHeight, 1);

				FBO_BP->Release();
				FBO_BP->Initialize(gameState.windowWidth/shrinkFactor,gameState.windowHeight/shrinkFactor, 1, 0);

				FBO_G_BLUR_X->Release();
				FBO_G_BLUR_X->Initialize(gameState.windowWidth/shrinkFactor,gameState.windowHeight/shrinkFactor, 1, 0);

				FBO_G_BLUR_Y->Release();
				FBO_G_BLUR_Y->Initialize(gameState.windowWidth/shrinkFactor,gameState.windowHeight/shrinkFactor, 1, 0);

				FBO_BOX_BLUR->Release();
				FBO_BOX_BLUR->Initialize(gameState.windowWidth/shrinkFactor,gameState.windowHeight/shrinkFactor, 1, 0);

				FBO_FINAL->Release();
				FBO_FINAL->Initialize(gameState.windowWidth, gameState.windowHeight, 1, 0);

				HUD->Release();
				HUD->Initialize(gameState.windowWidth, gameState.windowHeight, 1);
			}
		}

		//GLfloat ratio = static_cast<float>(window.getSize().x) / window.getSize().y;
		GLfloat ratio = (float)gameState.windowWidth/(float)gameState.windowHeight;
		initWindowFunc(ratio);

		//resize the text upon window resize
		myGUIView = sf::View(sf::FloatRect(0.0f, 0.0f, gameState.windowWidth, gameState.windowHeight));
		window.setView(myGUIView);
		
		if(runningState == states::running)
		{
			if(!playMainMenuMusic)
			{
				atmospheric->playSound();
				test2Dsound->stopSound();
				playMainMenuMusic = true;
			}
			updateFunc();
			drawFunc(&window);
		}
		//drawFunc();
		if(runningState == states::menu)
		{
			if(playMainMenuMusic)
			{
				atmospheric->stopSound();
				rainSound->stopSound();
				test2Dsound->playSound();
				playMainMenuMusic = false;
			}
			updateMenu();
			drawMenu();
		}
		else if(runningState == states::paused)
		{
			drawFunc(&window);
		}

		//draw mouse cursor
		if(displayCursor)
		{
			//update mouse cursor's position
			cursorSprite.setPosition(static_cast<sf::Vector2f>(TLocalPosition));

			//draw mouse cursor
			window.pushGLStates();
			window.draw(cursorSprite);
			window.popGLStates();
		}

		// Finally, display the rendered frame on screen
        window.display();
	}

}
////////////////////////////////////////////////////////////////////////////////////////////////
void game::handleInput()
{
	
	//if a controller is connected
	
	{
		//if the player wants to go to the in game menu
		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)||sf::Joystick::isButtonPressed(0,7)) && menuClock.getElapsedTime().asSeconds() > 0.5f)
		{
			if(runningState == running)
			{
				runningState = paused;
				menuClock.restart();
			}
			else if(runningState == paused)
			{
				runningState = running;
				menuClock.restart();
			}
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
		{
			if(runningState == running)
			{
				runningState = mainMenu;
			}
		}
		//handles player in game input
		if(runningState == running /*&& player.playerMove*/ && player.alive != false)
		{
			handleJoyStickFunc();

			if(player.playerMove)
			{
				handleKeyFunc();
			}
		}
		if(runningState == menu || runningState == paused)
		{
			ZeroMemory( &vibration, sizeof(XINPUT_VIBRATION) ); // 1500
			vibration.wLeftMotorSpeed = 0; // use any value between 0-65535 here
			vibration.wRightMotorSpeed = 0; // use any value between 0-65535 here
			XInputSetState( 0, &vibration );
			joyStickMoveMouse();
		}
		//handles player in menu input
		if(runningState == menu)
		{
			menuKeyFunc();
		}
		if(runningState == paused)
		{
			pausedKeyFunc();
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void game::pausedKeyFunc()
{
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left) || joyStick.isButtonPressed(0,0))
	{
		player.input.Lmouse = true;
	}
	else
	{
		player.input.Lmouse = false;
	}
	if(player.input.Lmouse)
	{
		float difference = 800.0f / gameState.windowWidth;
		float difference2 = 600.0f / gameState.windowHeight; 
		int x = mouse.current.x * difference;
		int y = mouse.current.y * difference2;

		inGameMenu.changePage(x,y);
	}
}
void game::menuKeyFunc()
{
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left) || joyStick.isButtonPressed(0,0))
	{
		player.input.Lmouse = true;
	}
	else
	{
		player.input.Lmouse = false;
	}

	if(menuClock.getElapsedTime().asSeconds() >= transitionTime)
	{
		if(player.input.Lmouse)
		{
			float difference = 800.0f / gameState.windowWidth;
			float difference2 = 600.0f / gameState.windowHeight; 

			//Vec3f rgb = Vec3f(mouse.current.x, mouse.current.y ,0.0f);
			//rgb = menuMask.menuCollisionCheck(rgb);
			if(mouse.current.x * difference < (int)menuMask1[menuState].getSize().x && 
				mouse.current.x * difference> 0 &&
				mouse.current.y * difference2 < (int)menuMask1[menuState].getSize().y &&
				mouse.current.y * difference2 > 0)
			{

				Vec3f rgb = Vec3f(float(menuMask1[menuState].getPixel(mouse.current.x * difference, mouse.current.y * difference2).r),
					float(menuMask1[menuState].getPixel(mouse.current.x * difference, mouse.current.y * difference2).g),
					float(menuMask1[menuState].getPixel(mouse.current.x * difference, mouse.current.y * difference2).b));


				if(rgb[0] >= 250 && rgb[1] >= 250 && rgb[2] >= 250)
				{
					runningState = running;
				}
				else if(rgb[0] >= 30 && rgb[1] >= 30 && rgb[2] >= 30)
				{
					end = true;
				}
				else if(rgb[1] >= 253 )
				{
					menuState = menuToOptions;
				}
				else if(rgb[1] >= 120 )
				{
					menuState = optionsToMenu;
				}
				else if(rgb[2] >= 253)
				{
					menuState = menuToCredits;
				}
				else if(rgb[2] >= 120)
				{
					menuState = creditsToMenu;
				}
				firstPress = true;
				player.input.Lmouse = false;
			}
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
//***********************TO DO: ADD JOYSTICK/CONTROLLER INPUT HANDLING ****************************************
//handles joystick/contoller input
void game::handleJoyStickFunc()
{
	
	DWORD dwResult;    
	ZeroMemory( &controllerState, sizeof(XINPUT_STATE) );

	// Simply get the state of the controller from XInput.
	dwResult = XInputGetState( 0, &controllerState );
	if( dwResult == ERROR_SUCCESS )
	{
		// Controller is connected 
		XINPUT_STATE state = controllerState;
		player.input.Lt = state.Gamepad.bLeftTrigger;
		player.input.Rt = state.Gamepad.bRightTrigger;
	}
	
	firstPersonTimer += frameTime.asSeconds();
	
	if(player.playerMove)	
	{

		 if(vibrationTimer > 1.0f)
		 {
		  ZeroMemory( &vibration, sizeof(XINPUT_VIBRATION) ); // 1500
		  vibration.wLeftMotorSpeed = 0; // use any value between 0-65535 here
		  vibration.wRightMotorSpeed = 0; // use any value between 0-65535 here
		  XInputSetState( 0, &vibration );
		 }

		testTimer += frameTime.asSeconds();
		/*firstPersonTimer += frameTime.asSeconds();*/

		XInputSetState( 0, &vibration );
		vibrationTimer += frameTime.asSeconds();

		//std::cout << joyStick.getButtonCount(0) << std::endl;
		if(testTimer > 3)
		{
			//std::cout << joyStick.getAxisPosition(0, sf::Joystick::Axis::Z) << std::endl;
			for(int i =0; i<12; i++)
			{
				if(joyStick.isButtonPressed(0,i))
				{
					//std::cout << i << " is pressed "<< std::endl;
				}
			}
			testTimer = 0;
		}
		//B button
		if(joyStick.isButtonPressed(0,1) && testTimer > 0.5)
		{
			//Ctrl button
			if(!player.state.sneaking)
			{
				stealth[0]->playSound();
				stealth[0]->isPlaying = false;

				player.runSpeed = 0.5f;
				player.input.LCtrl = true;
				player.state.sneaking = true;
				player.state.walking = false;
			}
			else if(player.state.sneaking)
			{
				player.runSpeed = 1.0f;
				player.input.LCtrl = false;
				player.state.sneaking = false;
				player.state.walking = true;
			}
			testTimer=0;
		}
		if(joyStick.isButtonPressed(0,3) && player.alive)
		{
			if(player.position[1] <= player.landHeight)
			{
				player.state.jumping = true;
			}
			player.input.space = true;
		}
		if(player.input.Rt > 100)
		 {
			player.input.Lmouse = true;
		 }
		 if(player.input.Lt > 100 && player.state.aiming != true)
		 {
			player.input.Rmouse = true;
			player.state.aiming = true;
			theCamera.setLastState(theCamera.getCurrentVector());
			cameraClock.restart();
		 }
		 else if(!(player.input.Lt > 100) && player.state.aiming == true && joyStick.isConnected(0))
		 {
			player.input.Rmouse = false;
			player.state.aiming = false;
			theCamera.setLastState(theCamera.getCurrentVector());
			cameraClock.restart();
		 }
		if(joyStick.isButtonPressed(0,4))
		{
			player.input.Lshift = true;
		}
		if(joyStick.isButtonPressed(0,7))
		{
		}
		/*if(joyStick.isButtonPressed(0,5) && firstPersonTimer > 1.0f)
		{
				if(player.state.fp == false)
				{
					player.state.fp = true;
					player.state.tp = false;
				}
				else if(player.state.fp == true)
				{
					player.state.fp = false;
					player.state.tp = true;
				}
				theCamera.setLastState(theCamera.getCurrentVector());
				cameraClock.restart();
				firstPersonTimer = 0.0f;
		}*/
		if(joyStick.isButtonPressed(0, 0))
		{
			if(ETimer > 1.0f)
			{
				player.input.E = true;
				ETimer = 0.0f;
			}
			else
			{
				player.input.E = false;
			}
		}
		////rotate camera
		//float thetaRotationSpeed =  joyStick.getAxisPosition(0,sf::Joystick::Axis::U) * frameTime.asSeconds() * 1.5f;
		//if(joyStick.getAxisPosition(0,sf::Joystick::Axis::U) > 50)
		//{
		//	player.theta -= thetaRotationSpeed;
		//	thetaRotationSpeed = thetaRotationSpeed * -1.0f;
		//	theCamera.setCurrentVector(theCamera.currentVector.applyYRotation(thetaRotationSpeed));
		//	theCamera.setSavedOffset(theCamera.savedOffset.applyYRotation(thetaRotationSpeed));
		//	updateCamera();
		//}
		//if(joyStick.getAxisPosition(0,sf::Joystick::Axis::U) < -50)
		//{
		//	player.theta -= thetaRotationSpeed;
		//	thetaRotationSpeed = thetaRotationSpeed * -1.0f;
		//	theCamera.setCurrentVector(theCamera.currentVector.applyYRotation(thetaRotationSpeed));
		//	theCamera.setSavedOffset(theCamera.savedOffset.applyYRotation(thetaRotationSpeed));
		//	updateCamera();
		//}
		if(joyStick.getAxisPosition(0,sf::Joystick::Axis::X) > 50)
		{
			player.input.d = true;
		}
		if(joyStick.getAxisPosition(0,sf::Joystick::Axis::X) < -50)
		{
			player.input.a = true;
		}
		if(joyStick.getAxisPosition(0,sf::Joystick::Axis::Y) > 50)
		{
			player.input.s = true;
		}
		if(joyStick.getAxisPosition(0,sf::Joystick::Axis::Y) < -50)
		{
			player.input.w = true;
		}
		//std::cout << joyStick.getButtonCount(0) << std::endl;
	}

	//rotate camera
	float thetaRotationSpeed =  joyStick.getAxisPosition(0,sf::Joystick::Axis::U) * frameTime.asSeconds() * 1.5f;
	if(joyStick.getAxisPosition(0,sf::Joystick::Axis::U) > 50)
	{
		player.theta -= thetaRotationSpeed;
		thetaRotationSpeed = thetaRotationSpeed * -1.0f;
		theCamera.setCurrentVector(theCamera.currentVector.applyYRotation(thetaRotationSpeed));
		theCamera.setSavedOffset(theCamera.savedOffset.applyYRotation(thetaRotationSpeed));
		updateCamera();
	}
	if(joyStick.getAxisPosition(0,sf::Joystick::Axis::U) < -50)
	{
		player.theta -= thetaRotationSpeed;
		thetaRotationSpeed = thetaRotationSpeed * -1.0f;
		theCamera.setCurrentVector(theCamera.currentVector.applyYRotation(thetaRotationSpeed));
		theCamera.setSavedOffset(theCamera.savedOffset.applyYRotation(thetaRotationSpeed));
		updateCamera();
	}

	//switch between first person and third person
	if(joyStick.isButtonPressed(0,5) && firstPersonTimer > 1.0f)
	{
		if(player.state.fp == false)
		{
			player.state.fp = true;
			player.state.tp = false;
		}
		else if(player.state.fp == true)
		{
			player.state.fp = false;
			player.state.tp = true;
		}
		theCamera.setLastState(theCamera.getCurrentVector());
		cameraClock.restart();
		firstPersonTimer = 0.0f;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

//key is the buttton that the user presses on the keyboard
//x and y are the mouse's position on the screen
void game::handleKeyFunc()
{
//*********IF PLAYER IS IN A DISTRICT (OUTSIDE)******************//
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player.input.a = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player.input.w = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		player.input.s = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player.input.d = true;
	}
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		player.input.Lmouse = true;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		player.input.Lshift = true;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		if(ETimer > 1.0f)
		{
			player.input.E = true;
			ETimer = 0.0f;
		}
		else
		{
			player.input.E = false;
		}
	}
	if(gameState.district)
	{
		player.movementVec = Vec3f(0.f, 0.f, 0.f);
		//A button
		if (player.input.a == true)
		{
			//Collision
			player.movementVec += player.XaxisPos;

			//update the player's collision box with the new vector. 
			player.cObject.updateCollisionObject(player.movementVec,player.runSpeed,player.position);

			if(!player.cObject.collisionTest(levels[gameState.levelID]->gameLevel.district[gameState.districtID].collisionList)) //collisionList
			{
				//update player position
				player.position += player.XaxisPos * player.runSpeed;
				//Camera update for running, jumping, and first person
				theCamera.playerPoint += player.XaxisPos * player.runSpeed;
				theCamera.playerPointReserved += player.XaxisPos * player.runSpeed; 
			}

			updateCamera();
		}

		//D button
		if (player.input.d == true)
		{
			player.movementVec += player.XaxisNeg;

			//update the player's collision box. 
			player.cObject.updateCollisionObject(player.movementVec,player.runSpeed,player.position);

			if (!player.cObject.collisionTest(levels[gameState.levelID]->gameLevel.district[gameState.districtID].collisionList))
			{
				player.position += player.XaxisNeg * player.runSpeed;
			
				//Camera update for running, jumping, and first person
				theCamera.playerPoint += player.XaxisNeg * player.runSpeed;
				theCamera.playerPointReserved += player.XaxisNeg * player.runSpeed; 
			}
		
			updateCamera();
		}

		//W button
		if (player.input.w == true)
		{
			player.movementVec += player.ZaxisPos;

			//update the player's collision box. 
			player.cObject.updateCollisionObject(player.movementVec,player.runSpeed,player.position);

			if (!player.cObject.collisionTest(levels[gameState.levelID]->gameLevel.district[gameState.districtID].collisionList))
			{
				player.position += player.ZaxisPos * player.runSpeed;
				//Camera update for running, jumping, and first person
				theCamera.playerPoint += player.ZaxisPos * player.runSpeed;
				theCamera.playerPointReserved += player.ZaxisPos * player.runSpeed; 
			}

			updateCamera();
		}

		//S button
		if (player.input.s == true)
		{
			player.movementVec += player.ZaxisNeg;

			//update the player's collision box. 
			player.cObject.updateCollisionObject(player.movementVec,player.runSpeed,player.position);

			if (!player.cObject.collisionTest(levels[gameState.levelID]->gameLevel.district[gameState.districtID].collisionList))
			{
				player.position += player.ZaxisNeg * player.runSpeed;
				//Camera update for running, jumping, and first person
				theCamera.playerPoint += player.ZaxisNeg * player.runSpeed;
				theCamera.playerPointReserved += player.ZaxisNeg * player.runSpeed; 
			}

			updateCamera();
		}

		//left mouse button
		if(player.input.Lmouse == true)
		{
			if(bulletClock.getElapsedTime().asSeconds() > 0.5)
			{
				
				laserBlast->updateSound(player.position);
				laserBlast->playSound();
				laserBlast->isPlaying = false;
				
				levels[gameState.levelID]->gameLevel.district->Bullet.setProjectile(player.ZaxisPos,player.position,5.0,3.0,5.0, &player.node, bulletTex);
			
				levels[gameState.levelID]->gameLevel.district->Bullets.push_back(levels[gameState.levelID]->gameLevel.district->Bullet);

				ZeroMemory( &vibration, sizeof(XINPUT_VIBRATION) ); // 1500
				vibration.wLeftMotorSpeed = 8000;
				vibration.wRightMotorSpeed = 8000;
				XInputSetState( 0, &vibration );
				vibrationTimer = 0.75;

				bulletClock.restart();

				player.recentlyAttacked = 0;
			}
			
		}
	}

//****************IF PLAYER IS IN A INTERIOR (INSIDE)********************//
	else if(gameState.interior)
	{
		player.movementVec = Vec3f(0.f, 0.f, 0.f);
		//A button
		if (player.input.a == true)
		{
			//Collision
			player.movementVec += player.XaxisPos;

			//update the player's collision box with the new vector. 
			player.cObject.updateCollisionObject(player.movementVec,player.runSpeed,player.position);

			if (!player.cObject.collisionTest(levels[gameState.levelID]->gameLevel.interior[gameState.interiorID].collisionList)) //collisionList
			{
				//update player position
				player.position += player.XaxisPos * player.runSpeed;
				//Camera update for running, jumping, and first person
				theCamera.playerPoint += player.XaxisPos * player.runSpeed;
				theCamera.playerPointReserved += player.XaxisPos * player.runSpeed; 
			}

			updateCamera();
		}

		//D button
		if (player.input.d == true)
		{
			player.movementVec += player.XaxisNeg;

			//update the player's collision box. 
			player.cObject.updateCollisionObject(player.movementVec,player.runSpeed,player.position);

			if (!player.cObject.collisionTest(levels[gameState.levelID]->gameLevel.interior[gameState.interiorID].collisionList))
			{
				player.position += player.XaxisNeg * player.runSpeed;
			
				//Camera update for running, jumping, and first person
				theCamera.playerPoint += player.XaxisNeg * player.runSpeed;
				theCamera.playerPointReserved += player.XaxisNeg * player.runSpeed; 
			}
		
			updateCamera();
		}

		//W button
		if (player.input.w == true)
		{
			player.movementVec += player.ZaxisPos;

			//update the player's collision box. 
			player.cObject.updateCollisionObject(player.movementVec,player.runSpeed,player.position);

			if (!player.cObject.collisionTest(levels[gameState.levelID]->gameLevel.interior[gameState.interiorID].collisionList))
			{
				player.position += player.ZaxisPos * player.runSpeed;
				//Camera update for running, jumping, and first person
				theCamera.playerPoint += player.ZaxisPos * player.runSpeed;
				theCamera.playerPointReserved += player.ZaxisPos * player.runSpeed; 
			}

		
			updateCamera();
		}

		//S button
		if (player.input.s == true)
		{
			player.movementVec += player.ZaxisNeg;

			//update the player's collision box. 
			player.cObject.updateCollisionObject(player.movementVec,player.runSpeed,player.position);

			if (!player.cObject.collisionTest(levels[gameState.levelID]->gameLevel.interior[gameState.interiorID].collisionList))
			{
				player.position += player.ZaxisNeg * player.runSpeed;
				//Camera update for running, jumping, and first person
				theCamera.playerPoint += player.ZaxisNeg * player.runSpeed;
				theCamera.playerPointReserved += player.ZaxisNeg * player.runSpeed; 
			}

			updateCamera();
		}

		//left mouse button
		if(player.input.Lmouse == true)
		{
			if(bulletClock.getElapsedTime().asSeconds() > 0.5)
			{
				
				laserBlast->updateSound(player.position);
				laserBlast->playSound();
				laserBlast->isPlaying = false;
				
				gameState.currentInterior->Bullet.setProjectile(player.ZaxisPos,player.position,5.0,3.0,5.0, &player.node, bulletTex);
			
				gameState.currentInterior->Bullets.push_back(gameState.currentInterior->Bullet);

				ZeroMemory( &vibration, sizeof(XINPUT_VIBRATION) ); // 1500
				vibration.wLeftMotorSpeed = 8000;
				vibration.wRightMotorSpeed = 8000;
				XInputSetState( 0, &vibration );
				vibrationTimer = 0.5;

				bulletClock.restart();

				player.recentlyAttacked = 0;
			}
		}
	}
	////////////////////////////////////////////////////////////////
//***************can be used in both the a district and interior***************************************************************8

	//Left shift
	if(player.input.Lshift == true)
	{
		player.runSpeed = 2.0f;
		player.state.running = true;
		player.state.walking = false;
	}
	else
	{
		player.runSpeed = 1.0f;
		player.state.running = false;
		player.state.walking = true;
	}

	////Ctrl button
	if(player.state.sneaking)
	{
		player.runSpeed = 0.5f;
	}

	////checks player's state
	if(player.input.w || player.input.a || player.input.s || player.input.d || player.input.Lmouse || player.input.Lshift || player.input.space)
	{
		player.state.idle = false;
		player.updatePlayerStateTheta = true;
	}
	else
	{
		player.state.idle = true;
		if(player.updatePlayerStateTheta)
		{
			player.state.theta = player.theta;
			player.updatePlayerStateTheta = false;
		}
	}


	//update the player's collision box. 
	player.cObject.updateCollisionObject(player.movementVec,player.runSpeed,player.position);

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && joyStick.getAxisPosition(0, joyStick.X) > -50.0f)
	{
		player.input.a = false;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && joyStick.getAxisPosition(0, joyStick.Y) > -50.0f)
	{
		player.input.w = false;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::S)&& joyStick.getAxisPosition(0, joyStick.Y) < 50.0f)
	{
		player.input.s = false;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D) && joyStick.getAxisPosition(0, joyStick.X) < 50.0f)
	{
		player.input.d = false;
	}
	if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && player.input.Rt < 100)
	{
		player.input.Lmouse = false;
	}
	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		player.input.Lshift = false;
	}
	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !joyStick.isButtonPressed(0,0))
	{
		player.input.E = false;
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//initializer
void game::initRenderFunc()
{
	glClearDepth(1.f);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	glEnable(GL_COLOR_MATERIAL);		//enables color									 
	glEnable(GL_DEPTH_TEST);		//essantial for 3D
	glEnable(GL_LIGHTING);		//enables light
	glEnable(GL_LIGHT0);		//enables light 0
	glEnable(GL_LIGHT1);		//enables light 1
	glEnable(GL_LIGHT2);		//enables light 2
	glEnable(GL_LIGHT3);		//enables light 3
	glEnable(GL_LIGHT4);		//enables light 4
	glEnable(GL_LIGHT5);		//enables light 5
	glEnable(GL_LIGHT6);		//enables light 6
	glEnable(GL_LIGHT7);		//enables light 7

	//rendering is faster
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glEnable(GL_NORMALIZE);		//automatically normlize normals
	glEnable(GL_TEXTURE_2D);	//enables 2D textures
	//glEnable(GL_BLEND);
	//glEnable(GL_POLYGON_SMOOTH);
	//glEnable(GL_FOG);		//enables fog

	//intialize Sound
	sound::initSound();
	
	//find frent frame of camera
	theCamera.updateCamera(player);

	sound::soundManager->set3DListener(player.position, Vec3f(0.0f, 0.0f, 0.0f), player.ZaxisPos, Vec3f(0.0f, 1.0f, 0.0f));

	//intialize GLEW
	GLenum err = glewInit();

	shader = new Shader();
	shader->LoadShaders(err);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//intializes window and projection/prespective
void game::initWindowFunc(GLfloat ratio)
{
	glMatrixMode(GL_PROJECTION);	//switch to setting the camera perspective
	//set the camera perspective
	glLoadIdentity();	//reset the camera
	
	gluPerspective(45.0f,						//the camera angle
					ratio,		//the width to height ratio (aspect ratio)
					1.0f,							//the near z clipping coordinate (if there is something that is closer than one unit to the eye, then openGL will not draw it, do not want object taking up full screen)
					5000.0f);						//the far z clipping coordinate (if there is something that is far than 200 units to the eye, then openGL will not draw it, there is no point in drawing something that you cannot see)

		
	// Clear color and depth buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void game::drawMenu()
{
	shader->mainMenuShader->Activate();
	//glDisable(GL_FOG);
	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0f, 1.0f, 0.0f); 
	float dt = menuClock.getElapsedTime().asSeconds();
	if(dt > transitionTime)
	{
		dt = transitionTime;
	}
	
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);	//particles must have the background as transparent and must be in png format
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	//first parameter is the pixel you are currently drawing and second parameter is the old pixel
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, -7.0f);
		glScalef(1.0f, 1.1f, 1.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		if(menuState == menuToOptions)
		{
			float angleOptions = (float)LERP(0,-90,dt/transitionTime);
			glRotatef(angleOptions, 0.0f, 1.0f, 0.0f);
			if(dt == transitionTime)
			{
				menuState = options;
			}
		}
		else if(menuState == optionsToMenu)
		{
			float angleOptions = (float)LERP(-90,0,dt/transitionTime);
			glRotatef(angleOptions, 0.0f, 1.0f, 0.0f);
			if(dt == transitionTime)
			{
				menuState = mainMenu;
			}
		}
		else if(menuState == menuToControls)
		{
			float angleControls = (float)LERP(0,90,dt/transitionTime);
			glRotatef(angleControls, 0.0f, 1.0f, 0.0f);
			if(dt == transitionTime)
			{
				menuState = mainMenu;
			}
		}
		else if(menuState == controlToMenu)
		{
			float angleControls = (float)LERP(90,0,dt/transitionTime);
			glRotatef(angleControls, 0.0f, 1.0f, 0.0f);
			if(dt == transitionTime)
			{
				menuState = mainMenu;
			}
		}
		else if(menuState == menuToCredits)
		{
			float angleCredits = (float)LERP(0,-90,dt/transitionTime);
			glRotatef(angleCredits, 1.0f, 0.0f, 0.0f);
			if(dt == transitionTime)
			{
				menuState = credits;
			}
		}
		else if(menuState == creditsToMenu)
		{
			float angleCredits = (float)LERP(-90,0,dt/transitionTime);
			glRotatef(angleCredits, 1.0f, 0.0f, 0.0f);
			if(dt == transitionTime)
			{
				menuState = mainMenu;
			}
		}
		else if(menuState == controls)
		{
			glRotatef(90, 0.0f, 1.0f, 0.0f);
		}
		else if(menuState == options)
		{
			glRotatef(-90, 0.0f, 1.0f, 0.0f);
		}
		else if(menuState == credits)
		{
			glRotatef(-90, 1.0f, 0.0f, 0.0f);
		}
		menuCubeTexture->drawTex(0);
		menuCube->drawModel();
		//glColor3f(1.0f, 1.0f, 1.0f);
	glPopMatrix();
	glDisable(GL_BLEND);

	glEnable(GL_LIGHTING);
	shader->mainMenuShader->Deactivate();
	//glEnable(GL_FOG);

}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//draws the game
void game::drawFunc(sf::RenderWindow *window)
{
	//cout << player.position << endl;

	float dt = frameTime.asSeconds();

	//***Render the Game**
	RenderHDRScene(window);

	//bind fbo to primitive to render it to screen
	glActiveTexture(GL_TEXTURE0);
	//FBO_BLUR->BindColour(0);
	//FBO->BindColour(0);

	//player gets discovered while sneaking
	if(levels[gameState.levelID]->timeSinceDiscovered.getElapsedTime().asSeconds() < 0.25f && player.state.sneaking)
	{
		stealth[1]->stopSound();

		stealth[2]->playSound();
		stealth[2]->isPlaying = false;

		ZeroMemory( &vibration, sizeof(XINPUT_VIBRATION) ); 
		vibration.wLeftMotorSpeed = 10000;
		vibration.wRightMotorSpeed = 10000;
		XInputSetState( 0, &vibration );
		vibrationTimer = 0;

		shader->rippleShader->Activate();
		glUniform1f(glGetUniformLocation(shader->rippleShader->GetHandle(), "time"), rippleTime);
		glUniform1f(glGetUniformLocation(shader->rippleShader->GetHandle(), "offsetRipple"), rippleTime);
	}
	else if(player.state.sneaking)
	{
		stealth[1]->playSound();
	}
	else
	{
		stealth[1]->stopSound();
	}

	FBO_FINAL->BindColour(0);
	gameScreen.drawScreen(Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f,0.0f, -1.0f), gameState.windowWidth, gameState.windowHeight);	
	shader->rippleShader->Deactivate();

	glEnable(GL_BLEND);	//particles must have the background as transparent and must be in png format
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	//first parameter is the pixel you are currently drawing and second parameter is the old pixel

	if((player.state.aiming || !player.state.tp) && !player.dialogue)
	{
		cursor.draw(Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f,0.0f, -1.0f), gameState.windowWidth, gameState.windowHeight);
	}

	if(drawE)
	{
		if(joyStick.isConnected(0))
		{
			pressAToEnter.draw(Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f,0.0f, -1.0f), gameState.windowWidth, gameState.windowHeight);
		}
		else
		{
			pressEToEnter.draw(Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f,0.0f, -1.0f), gameState.windowWidth, gameState.windowHeight);
		}
		drawE = false;
	}

	//***Render the HUD***
	HUD->Activate();	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	if(runningState == paused)
	{
		if(rainSound->isPlaying)
		{
			rainSound->stopSound();
		}

		if(lowBass->isPlaying)
		{
			lowBass->stopSound();
		}

		shader->inGameMenuShader->Activate();
		inGameMenu.draw(gameState.windowWidth, gameState.windowHeight, &missions, window);
		shader->inGameMenuShader->Deactivate();
	}
	//only play rain sound if we are outside
	else if (gameState.district)
	{
		if(!rainSound->isPlaying)
		{
			rainSound->playSound();
		}
	}
	else
	{
		if(rainSound->isPlaying)
		{
			rainSound->stopSound();
		}
	}
	
	shader->HealthShader->Activate();
	if(player.health < 0)
	{
		player.health = 0;
	}
	glUniform1i(glGetUniformLocation(shader->HealthShader->GetHandle(), "health"), player.health);

	ui.draw(Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f,0.0f, -1.0f), gameState.windowWidth, gameState.windowHeight);
	
	if(!player.alive)
	{
		glUniform1i(glGetUniformLocation(shader->HealthShader->GetHandle(), "health"), 0.0f);
		deathUI.draw(Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f,0.0f, -1.0f), gameState.windowWidth, gameState.windowHeight);
	}

	glDisable(GL_BLEND);
	shader->HealthShader->Deactivate();
	HUD->Deactivate();

	//bind fbo to screen to render it
	glEnable(GL_BLEND);	//particles must have the background as transparent and must be in png format
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	//first parameter is the pixel you are currently drawing and second parameter is the old pixel
	glDisable(GL_DEPTH_TEST);
	HUD->BindColour(0);
	gameScreen.drawScreen(Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f,0.0f, -1.0f), gameState.windowWidth, gameState.windowHeight);	
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);

	//draw missions (text) to screen
	missions.drawGameMissions(window, dt);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//Everything that renders the 3D scene with HDR
void game::RenderHDRScene(sf::RenderWindow *window)
{
	//Render 3D scene to offscreen Framebuffer
	{
		FBO->Activate();
		//glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		/*Camera*/ //for FBO
		//first 3 variables are the positon of the camera
		//second three variables are the postion that the camera is looking at
		//last theree variables is where up is. 
		glPushMatrix();
		gluLookAt(theCamera.position[0],theCamera.position[1], theCamera.position[2], theCamera.playerPoint[0], theCamera.playerPoint[1], theCamera.playerPoint[2], 0.0f, 1.0f, 0.0f); 

		if(gameState.district)
		{
			skyBox->drawSkyBox();
		}

		
		shader->ShaderProgram->Activate();

		//textures
		glUniform1i(glGetUniformLocation(shader->ShaderProgram->GetHandle(), "my_color_texture"), 0);
		
		///*Player*/
		//shader->meshSkinningShader->Activate();
		player.drawCharacter(/*shader->meshSkinningShader*/ shader);
		//shader->meshSkinningShader->Deactivate();
		
		//shader->ShaderProgram->Activate();

		//draw mission objects
		if(gameState.district)
		{
			missions.drawMissionObjects(1, gameState.districtID, true);
		}
		else
		{
			missions.drawMissionObjects(1, gameState.interiorID, false);
		}
	
		//the level
		if(gameState.district)
		{
			levels[gameState.levelID]->drawDistrict(gameState.districtID, shader);
		}
		else if(gameState.interior)
		{
			levels[gameState.levelID]->drawInterior(gameState.interiorID, shader);
			//levels[0]->drawInterior(0, shader);
		}

		shader->ShaderProgram->Deactivate();


		shader->Particle_Shader->Activate();
		//*******PARTICLES************)
	
		glEnable(GL_BLEND);	//particles must have the background as transparent and must be in png format
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	//first parameter is the pixel you are currently drawing and second parameter is the old pixel

			
		//only draw rain particles if the player is outside
		if(gameState.district)
		{
			rain->drawParticles(shader->Particle_Shader);
			splash->drawParticles(shader->Particle_Shader);
		}

		//DRAW THE PARTICLES
		//particleSystems;
		/*for(std::list<ParticleManager*>::iterator i = particleSystems.begin(); i != particleSystems.end();)
		{
			(*i)->drawParticles();
			i++;
		}*/

		if(gameState.district)
		{
			missions.drawIcons(shader->Particle_Shader, 1, gameState.districtID, true);
		}
		else
		{
			missions.drawIcons(shader->Particle_Shader, 1, gameState.interiorID, false);
		}

		glDisable(GL_BLEND);
		glPopMatrix();
		shader->Particle_Shader->Deactivate();
		FBO->Deactivate();
	}

	
	glDisable(GL_DEPTH_TEST);

	//Hightlight Bright areas (tone-mapping)
	{
		FBO_BP->Activate();
		glViewport(0, 0, (gameState.windowWidth/shrinkFactor), (gameState.windowHeight/shrinkFactor)); 
			
		shader->HDR_BP_Shader->Activate();

		////bind fbo to primitive to see what is going on 
		glActiveTexture(GL_TEXTURE0);
		FBO->BindColour(0);
		gameScreen.drawScreen(Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f,0.0f, -1.0f), gameState.windowWidth, gameState.windowHeight);
			
		shader->HDR_BP_Shader->Deactivate();
		FBO_BP->Deactivate();
	}

	//Apply a Box Blur 
	{
		FBO_BOX_BLUR->Activate();

		shader->HDR_Box_Blur_Shader->Activate();

		//send pixel size to shader
		glUniform2f(glGetUniformLocation(shader->HDR_Box_Blur_Shader->GetHandle(), "pixelSize"), 1.0f/(float)(gameState.windowWidth/shrinkFactor), 1.0f/(float)(gameState.windowHeight/shrinkFactor));

		////bind fbo to primitive to see what is going on 
		glActiveTexture(GL_TEXTURE0);
		//FBO_BP->BindColour(0);
		FBO_BP->BindColour(0);
		gameScreen.drawScreen(Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f,0.0f, -1.0f), gameState.windowWidth, gameState.windowHeight);

		shader->HDR_Box_Blur_Shader->Deactivate();
		FBO_BOX_BLUR->Deactivate();
	}

	//Apply a 1D Gaussian blur horzontally (x-axis)
	{
		FBO_G_BLUR_X->Activate();

		shader->HDR_G_Blur_X_Shader->Activate();

		//send pixel size to shader
		glUniform2f(glGetUniformLocation(shader->HDR_G_Blur_X_Shader->GetHandle(), "pixelSize"), 1.0f/(float)(gameState.windowWidth/shrinkFactor), 1.0f/(float)(gameState.windowHeight/shrinkFactor));

		////bind fbo to primitive to see what is going on 
		glActiveTexture(GL_TEXTURE0);
		FBO_BOX_BLUR->BindColour(0);
		gameScreen.drawScreen(Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f,0.0f, -1.0f), gameState.windowWidth, gameState.windowHeight);

		shader->HDR_G_Blur_X_Shader->Deactivate();
		FBO_G_BLUR_X->Deactivate();
	}

	//Apply a 1D Gaussian blur vertically (y-axis)
	{
		FBO_G_BLUR_Y->Activate();

		shader->HDR_G_Blur_Y_Shader->Activate();

		//send pixel size to shader
		glUniform2f(glGetUniformLocation(shader->HDR_Box_Blur_Shader->GetHandle(), "pixelSize"), 1.0f/(float)(gameState.windowWidth/shrinkFactor), 1.0f/(float)(gameState.windowHeight/shrinkFactor));

		////bind fbo to primitive to see what is going on 
		glActiveTexture(GL_TEXTURE0);
		FBO_G_BLUR_X->BindColour(0);
		gameScreen.drawScreen(Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f,0.0f, -1.0f), gameState.windowWidth, gameState.windowHeight);

		shader->HDR_G_Blur_Y_Shader->Deactivate();
		FBO_G_BLUR_Y->Deactivate();
	}

	
	//Final Image = FBO_BOX_BLUR + FBO
	{
		FBO_FINAL->Activate();
		glViewport(0, 0, (gameState.windowWidth), (gameState.windowHeight)); 
		//glClearColor(0.0f, 1.0f, 1.0f, 0.0f);
		//glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		shader->HDR_Final_Shader->Activate();

		glUniform1i(glGetUniformLocation(shader->HDR_Final_Shader->GetHandle(), "myTextureSampler0"), 0);

		glUniform1i(glGetUniformLocation(shader->HDR_Final_Shader->GetHandle(), "myTextureSampler1"), 1);

		glActiveTexture(GL_TEXTURE0);
		FBO->BindColour();
			
		glActiveTexture(GL_TEXTURE1);
		FBO_G_BLUR_Y->BindColour();
			
		gameScreen.drawScreen(Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f,0.0f, -1.0f), gameState.windowWidth, gameState.windowHeight);

		shader->HDR_Final_Shader->Deactivate();
		FBO_FINAL->Deactivate();
	}

	glEnable(GL_DEPTH_TEST);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//Delete stuff here
void game::cleanUp()
{ 
	//delete groundTex;
	delete drawShapes;
	//delete[] testParticle;

	levels[0]->deleteLevel();

	rainSound->cleanUp();
	sound::soundManager->cleanUp();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void game::updateMenu()
{
	if(firstPress == true && (menuState != credits && menuState != mainMenu && menuState != options && menuState != controls ))
	{
		menuClock.restart();
		firstPress = false;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
// update anything that needs to be updated and/or moved
void game::updateFunc()
{
	gameState.currentInterior = &levels[gameState.levelID]->gameLevel.interior[gameState.interiorID]; 

	if(player.alive == false && deathBool == true)
	{
		death->playSound();
		death->updateSound(player.position);
		death->isPlaying = false;

		deathClock.restart();
		deathBool = false;

		//move the camera back to third person, if in first person or aiming, so player can see death animation
		if(player.state.fp || player.state.aiming)
		{
			player.state.tp = true;
			player.state.fp = false;
			player.state.aiming = false;
			cameraClock.restart();
		}
	}

	//////change the perspective of the player when they enter a dialogue scene
	//if(player.dialogue)
	//{
	//	if(!player.state.prevfp)
	//	{
	//		player.state.prevfp = player.state.fp;
	//	}
	//	
	//	//if not in first person change to first person
	//	if(!player.state.prevfp)
	//	{
	//		//change perspectives
	//		player.state.fp = true;
	//		player.state.tp = false;
	//		player.state.aiming = false;

	//		//so we do not reset the camera clock again
	//		player.state.prevfp = true;

	//		//so we can go to the perspective the player was in when they entered in the dialogue scene
	//		player.updateDialoguePerspective = true;
	//		
	//		//restart camera timer so we can lerp to perspectives
	//		cameraClock.restart();
	//	}
	//}
	//else
	//{
	//	//if prev not in first person change back to third person
	//	if(player.state.prevfp && player.updateDialoguePerspective)
	//	{
	//		//change perspectives
	//		player.state.fp = false;
	//		player.state.tp = true;
	//		player.state.aiming = false;

	//		//so we do not reset the camera clock again
	//		player.state.prevfp = false;	//make sure we do not call this again until we enter another dialogue section
	//		
	//		//so we can go to the perspective the player was in when they entered in the dialogue scene
	//		player.updateDialoguePerspective = false;

	//		//restart camera timer so we can lerp to perspectives
	//		cameraClock.restart();
	//	}
	//}

	//respawn the player
	if(deathClock.getElapsedTime().asSeconds() > 5.0 && player.alive == false)
	{
		player.alive = true;
		player.health = 100;
		deathBool = true;

		//so death animations can replay
		player.animations.Death.reset();
		player.animations.Death.doneAnimation = false;

		player.recentlyAttacked = player.relaxingPeriod + 1; 
		player.isHostile = false;

		gameState.district = true;
		gameState.interior = false;
		gameState.districtID = 0;
		
		player.position = player.startingPosition;
		theCamera.playerPoint = player.startingPosition;
		theCamera.playerPointReserved = player.startingPosition; 
		theCamera.updateCamera(player);
		updateCamera();
	}

	if(gameState.district && gameState.districtID == 0)
	{
		if(!lowBass->isPlaying)
		{
			lowBass->playSound();
		}
	}
	else
	{
		if(lowBass->isPlaying)
		{
			lowBass->stopSound();
		}
	}

	//play the music inside of the club
	if(gameState.interior && gameState.interiorID == 0)
	{
		atmospheric->stopSound();
		clubMusic->playSound();
	}
	else
	{
		atmospheric->playSound();
		clubMusic->stopSound();
	}

	//if(gameState.interior && gameState.interiorID == 1)
	//{
	//	atmospheric->stopSound();
	//	//barMusic->playSound();
	//}
	//else
	//{
	//	atmospheric->playSound();
	//	//barMusic->stopSound();
	//}

	//update time every frame
	frameTime = theClock.getElapsedTime();
	theClock.restart();
	float dt = frameTime.asSeconds();
	rippleTime += dt;
	ETimer += dt;
	gameState.currentTime += dt;
	//For when the player jumps
	playerJumping();
	
	//calcualte the TLocal axis of which the player will move on depending on the orientation of the camera
	player.calcAxis();

	//game.cpp update function under player.jumping
	PlayercheckHostile((levels[gameState.levelID]->gameLevel.district->NPCList), dt);

	//update missions based on the player's state
	if(gameState.district)
	{
		missions.updateGameMissions(&player, 1, gameState.districtID, true, dt);

		//update the rain particles
		//only update them if player is outside
		rain->setCollisionPos(Vec3f(player.position[0],-8.5f,player.position[2])); 
		rain->updateIntialPos(Vec3f(player.position[0], player.position[1] + 20, player.position[2]));
		rain->updateParticles(dt, player.theta, theCamera.position);

		splash->updateIntialPos(Vec3f(player.position[0], -8.0f, player.position[2]));
		splash->updateParticles(dt, player.theta, theCamera.position);

		float health = player.health; 

		//update the level
		//NPCs are updated in this function
		levels[gameState.levelID]->updateDistrict(&player, &theCamera, gameState.interior, gameState.district, gameState.districtID, gameState.interiorID, drawE, dt, AISounds);
		
		if(health > player.health)
		{
			ZeroMemory( &vibration, sizeof(XINPUT_VIBRATION) ); // 1500
			vibration.wLeftMotorSpeed = 10000;
			vibration.wRightMotorSpeed = 10000;
			XInputSetState( 0, &vibration );
			vibrationTimer = 0;
		}

		//update the skybox based on the player's position
		skyBox->updateSkyBox(player.position);
	}
	else if(gameState.interior)
	{
		missions.updateGameMissions(&player, 1, gameState.interiorID, false, dt);

		float health = player.health; 

		//update the level
		//NPCs are updated in this function
		levels[gameState.levelID]->updateInterior(&player, &theCamera, gameState.interior, gameState.district, gameState.districtID, gameState.interiorID, drawE, dt, AISounds);
	
		if(health > player.health)
		{
			ZeroMemory( &vibration, sizeof(XINPUT_VIBRATION) ); // 1500
			vibration.wLeftMotorSpeed = 10000;
			vibration.wRightMotorSpeed = 10000;
			XInputSetState( 0, &vibration );
			vibrationTimer = 0;
		}
	}

	//update camera
	theCamera.updateCamera(player);

	sound::soundManager->set3DListener(player.position, Vec3f(0.0f, 0.0f, 0.0f), player.ZaxisPos, Vec3f(0.0f, 1.0f, 0.0f));

	rainSound->updateSound(player.position + (player.ZaxisPos * Vec3f(10, 0, 10)));

	laserBlast->updateSound(player.position + (player.ZaxisPos * Vec3f(5, 0, 5)));

	//update camera for first person view
	 float tempTime = cameraClock.getElapsedTime().asSeconds();
	 if(tempTime > lerpTime)
	 {
		tempTime = lerpTime;
	 }
	 //for first person perspective
	 Vec3f bob = player.position + (player.ZaxisPos*50.0f) ;
	 if(player.state.fp && theCamera.lastState == player.XaxisPos*-2.5f + player.ZaxisNeg*8.5f + Vec3f(0.0f, player.position[1] + 8.0f, 0.0f))
	 {
		  theCamera.setCurrentVector(LERP(theCamera.lastState, Vec3f(0.0f, 6.1f + player.position[1] - player.landHeight , 0.0f) , tempTime/lerpTime));
		  theCamera.playerPoint = LERP(player.position, bob, tempTime/lerpTime);
		  updateCamera();
	 }
	 else if(player.state.fp)
	 {
		  theCamera.setCurrentVector(LERP(theCamera.lastState, Vec3f(0.0f, 6.1f + player.position[1] - player.landHeight , 0.0f) , tempTime/lerpTime));
		  theCamera.playerPoint = bob;
		  updateCamera();
	 }
	 //for aiming
	 else if(player.state.aiming)
	 {
		 theCamera.setCurrentVector(LERP(theCamera.lastState, player.XaxisPos*-2.5f + player.ZaxisNeg*8.5f + Vec3f(0.0f, player.position[1] + 8.0f, 0.0f), tempTime/lerpTime));
		 theCamera.playerPoint = LERP(player.position, bob, tempTime/lerpTime);
		 updateCamera();
	 }
	 //back to third person
	 else
	 {
		  theCamera.setCurrentVector(LERP(theCamera.lastState,theCamera.savedOffset , tempTime/lerpTime)); 
		  theCamera.playerPoint = LERP(bob , player.position, tempTime/lerpTime);
		  updateCamera();
	 }
	  if(tempTime == lerpTime)
	 {
		 theCamera.setLastState(theCamera.getCurrentVector());
		 if(theCamera.lastState != theCamera.getCurrentVector())
		 {
			 cameraClock.restart();
		 }
	 }

////************player animation*******************//
	  player.updateAnimations(dt);


//************************************************//
	 //used for framerate
	 if(deltaTime < 1.0f)
	 {
		deltaTime += frameTime.asSeconds();
		numIterations += 1;
	 }
	 else
	 {
		deltaTime = 0.0f;
		frameRate = numIterations;
		numIterations = 0;
	 }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//handles updating mouse input, mouse direction, and camera's orientation
void game::mouseMotion(sf::Vector2i current, sf::RenderWindow *window)
{
	//cout << "( " << current.x << ", " << current.y << ")" << endl;

	//if we are in the actually game and not in the menu
	if(runningState != states::menu && runningState != states::paused)
	{
		/*float thetaRotationSpeed =  joyStick.getAxisPosition(0,sf::Joystick::Axis::U) * frameTime.asSeconds() * 1.5f;
		if(joyStick.getAxisPosition(0,sf::Joystick::Axis::U) > 50)
		{
			player.theta -= thetaRotationSpeed;
			thetaRotationSpeed = thetaRotationSpeed * -1.0f;
			theCamera.setCurrentVector(theCamera.currentVector.applyYRotation(thetaRotationSpeed));
			theCamera.setSavedOffset(theCamera.savedOffset.applyYRotation(thetaRotationSpeed));
			updateCamera();
		}
		if(joyStick.getAxisPosition(0,sf::Joystick::Axis::U) < -50)
		{
			player.theta -= thetaRotationSpeed;
			thetaRotationSpeed = thetaRotationSpeed * -1.0f;
			theCamera.setCurrentVector(theCamera.currentVector.applyYRotation(thetaRotationSpeed));
			theCamera.setSavedOffset(theCamera.savedOffset.applyYRotation(thetaRotationSpeed));
			updateCamera();
		}*/

		//make curser invisable to player
		//window->setMouseCursorVisible(false);
		displayCursor = false;

		//center of the screen
		Vec3f center = Vec3f(gameState.windowWidth/2.0f, gameState.windowHeight/2.0f, 0.0f);
		
		//calculate the differnece between the mouse and the center of the screen
		Vec3f diff; 
		//have different camera rotation speeds depending on the state of the player
		if(player.state.aiming || player.state.fp)
		{
			diff = (Vec3f(mouse.current.x,mouse.current.y, 0.0f) - center) * 0.5f;
		}
		else
		{
			diff = (Vec3f(mouse.current.x,mouse.current.y, 0.0f) - center) * 0.75f;
		}

		//calculate how fast the rotation speed should be
		float thetaRotationSpeed = diff[0] * 0.25f;

		//apply rotation fo player and camera
		player.theta -= thetaRotationSpeed;
		
		thetaRotationSpeed = thetaRotationSpeed * -1.0f;
		theCamera.setCurrentVector(theCamera.currentVector.applyYRotation(thetaRotationSpeed));
		theCamera.setSavedOffset(theCamera.savedOffset.applyYRotation(thetaRotationSpeed));
		updateCamera();

		//set the mouse back to the center of the screen
		sf::Mouse::setPosition(sf::Vector2i(gameState.windowWidth/2.0f, gameState.windowHeight/2.0f), *window);


		/*fix floating point errors*/
		if(player.theta >= 360.0f)
		{
			player.theta -= 360.0f;
		
		}
		else if(player.theta <= -360.0f)
		{
			player.theta += 360.0f;
		
		}
	}
	//if we are in a menu
	else
	{
		//make curser visable to player
		//window->setMouseCursorVisible(true);
		displayCursor = true;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void game::updateCamera()
{
	theCamera.setPosition();
}

void game::playerJumping()
{
	if(player.state.jumping == true && player.position[1] >= player.landHeight)
	{
		player.jumpForce = G;
		player.state.jumping = false;
		player.position[1] = player.landHeight;
		player.yVelocity = 6.f;
		jumpClock.restart();
	}
	else if(player.position[1] <= player.landHeight)
	{
		player.jumpForce = 0.0f;
		player.yAccel = 0.0f;
		player.yVelocity = 0.0f;
		player.position[1] = player.landHeight;
		theCamera.currentVector[1] = theCamera.savedOffset[1];
		theCamera.playerPointReserved[1] = player.landHeight;
		// player.input.space = false;
	}
	player.yAccel = player.jumpForce / player.playerMass;
	player.yVelocity += player.yAccel;
	player.position += Vec3f(0.0f, player.yVelocity*jumpClock.getElapsedTime().asSeconds(), 0.0f);
	theCamera.playerPointReserved += Vec3f(0.0f, player.yVelocity*jumpClock.getElapsedTime().asSeconds(), 0.0f);
	theCamera.currentVector += Vec3f(0.0f, player.yVelocity*jumpClock.getElapsedTime().asSeconds(), 0.0f);
	updateCamera();

	if(player.position[1] == 0.0f)
	{
		player.input.space = false;
	}
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void game::PlayercheckHostile(std::list<regularNPC*>& theNPC, float dt)
{
	//if the player has fired recently: 
	//shows how long it has been since the player last attacked. 
	//dont update if its been greater than the relaxing period.
	if (player.recentlyAttacked <= player.relaxingPeriod)
	{
		player.recentlyAttacked += dt;
		player.isHostile = true;
	}
	else
	{

		if (player.isHostile)
		{

			for (std::list<regularNPC*>::iterator i = theNPC.begin(); i != theNPC.end();i++)
			{
				//reset hostile variable
				Vec3f tempVec; //used to grab the magnitude of the two distances

				//grab the distance between the two
				tempVec = player.position.negate() + (*i)->position;

				//if they are either within the line of sight, or radius of the NPC
				if (tempVec.magnitude() <= (*i)->sightRadius)
				{
					return;
				}
			}

			//if the end of the loop is reached and no enemies are in range (hasnt had break activated)
			player.isHostile = false;
		}

		//if it hasn't attacked it becomes relaxed and no longer hostile
		player.isHostile = false;
	}	
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void game::joyStickMoveMouse()
{
	 DWORD dwResult;    
	 ZeroMemory( &controllerState, sizeof(XINPUT_STATE) );

	 // Simply get the state of the controller from XInput.
	 dwResult = XInputGetState( 0, &controllerState );
	 float Rx = 0, Ry = 0, scale; 
	 sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	 if(runningState == paused)
	 {
		scale = 15.0f;
	 }
	 if(runningState == menu)
	 {
		scale = 10.0f;
	 }
	 if( dwResult == ERROR_SUCCESS )
	 {
		  // Controller is connected 
		  XINPUT_STATE state = controllerState;
		  Rx = controllerState.Gamepad.sThumbRX;
		  Ry = controllerState.Gamepad.sThumbRY;
		  if(Rx < 7000 &&  Rx > -7000)
		  {
			  Rx = 0;
		  }
		  if(Ry < 7000 && Ry > -7000)
		  {
			  Ry = 0;
		  }
		  Rx = (Rx*scale)/22768.0f;
		  Ry = (Ry*scale)/22768.0f;
		  sf::Mouse::setPosition(mousePos + sf::Vector2i(Rx,-1*Ry), *window);
		  //mouse.current += sf::Vector2i(Rx,Ry);
	 }
}