#include "MissionBuilder.h"


//////////////////////////////////////////////////////////////////////////////////////////
//*********************MISSION BUILDER**********************************************************//
//loads all of the needed stuff for missions and objectives
//This is where all the scripting for the missions and objectives goes. 

void GameMissions::loadGameMissions()
{
	loadObjectiveIcons();


	//******Mission 1 - welcome to telkram
	Mission *Mission1;
	Mission1 = new Mission(1, 0, true, "Welcome to Telkram");
	Mission1->startArea = new collisionObject(10.0f, Vec3f(389.443f, 0.0f, 436.398f), 0.0f, false);
	Mission1->dialogue = new Dialogue();
	
	///11 lines of dialogue
	sf::String m1_l1 = "Agent. Glad to see you made it.";
	sf::String m1_l2 = "Welcome to Telkram. Looks like a really nice city.";
	sf::String m1_l3 = "But, according to these reports it's far from it.";
	sf::String m1_l4 = "My name is Elara Nova, and I'll be your Handler during the operation on Telkram.";
	sf::String m1_l5 = "First, can I say that... it's an honour being assigned to you.";
	sf::String m1_l6 = "This is my first assignment on a Class 5 Op. And the things I've heard about you...";
	sf::String m1_l7 = "In any case, let's get you started.";
	sf::String m1_l8 = "Your first objective will be to talk to our Contact on the ground.";
	sf::String m1_l9 = "His name is Drava. He should be in a court just North of your Insertion point.";
	sf::String m1_l10 = "Be careful down there. The locals know an Agent just touched down on the planet.";
	sf::String m1_l11 = "Good luck, Agent. I'll be here to update you if need be. Elara out.";
	
	Mission1->dialogue->theString.push_back(m1_l1);
	Mission1->dialogue->theString.push_back(m1_l2);
	Mission1->dialogue->theString.push_back(m1_l3);
	Mission1->dialogue->theString.push_back(m1_l4);
	Mission1->dialogue->theString.push_back(m1_l5);
	Mission1->dialogue->theString.push_back(m1_l6);
	Mission1->dialogue->theString.push_back(m1_l7);
	Mission1->dialogue->theString.push_back(m1_l8);
	Mission1->dialogue->theString.push_back(m1_l9);
	Mission1->dialogue->theString.push_back(m1_l10);
	Mission1->dialogue->theString.push_back(m1_l11);
	
	float time1_l1 = 5.0f;
	float time1_l2 = 5.0f;
	float time1_l3 = 5.0f;
	float time1_l4 = 5.0f;
	float time1_l5 = 5.0f;
	float time1_l6 = 5.0f;
	float time1_l7 = 5.0f;
	float time1_l8 = 5.0f;
	float time1_l9 = 5.0f;
	float time1_l10 = 5.0f;
	float time1_l11 = 5.0f;
	
	Mission1->dialogue->timeRender.push_back(time1_l1);
	Mission1->dialogue->timeRender.push_back(time1_l2);
	Mission1->dialogue->timeRender.push_back(time1_l3);
	Mission1->dialogue->timeRender.push_back(time1_l4);
	Mission1->dialogue->timeRender.push_back(time1_l5);
	Mission1->dialogue->timeRender.push_back(time1_l6);
	Mission1->dialogue->timeRender.push_back(time1_l7);
	Mission1->dialogue->timeRender.push_back(time1_l8);
	Mission1->dialogue->timeRender.push_back(time1_l9);
	Mission1->dialogue->timeRender.push_back(time1_l10);
	Mission1->dialogue->timeRender.push_back(time1_l11);



		//********first objective
		Objective *M1_Obj1;
		sf::String string1_obj1("Talk to the Contact"); 
		M1_Obj1 = new Objective(false, 1, 0, true, string1_obj1, talkingIcon);

		M1_Obj1->goalArea = new collisionObject(5.0f, Vec3f(150.706f, 0.0f, 103.747f), 0.0f, false);
		M1_Obj1->dialogue = new Dialogue();
		
		////13 lines of dialogue
		sf::String m1_l12 = "Are... are you... the A..Ag..Agent?";
		//sf::String m1_l13 = "..........";
		sf::String m1_l14 = "The name's Drava. Not much of talker, are you?"; 
		sf::String m1_l15 = "Sorry, sorry, meant no offense, Agent.";
		//sf::String m1_l16 = "Just nervous. My family and I want to get out of this alive.";
		//sf::String m1_l17 = "We all know what happens to planets that don't join willingly.";
		//sf::String m1_l18 = "Besides, the Sovereignty's gotta be better than this, right?";
		//sf::String m1_l19 = "..........";
		sf::String m1_l20 = "Right. Okay. This District is run by the Red Dragons.";
		sf::String m1_l21 = "A gang that likes to think of themselves as 'warriors'.";
		sf::String m1_l22 = "One of their Lieutenants, is just South of here, on the other side of the district.";
		sf::String m1_l23 = "He likes to patrol one of the intersections by himself. Thinks he's tough shit.";
		
		/////change line
		/// make it catchy, corny, and funny
		sf::String m1_l24 = "You might want to go see him.";

		M1_Obj1->dialogue->theString.push_back(m1_l12);
		//M1_Obj1->dialogue->theString.push_back(m1_l13);
		M1_Obj1->dialogue->theString.push_back(m1_l14);
		M1_Obj1->dialogue->theString.push_back(m1_l15);
		//M1_Obj1->dialogue->theString.push_back(m1_l16);
		//M1_Obj1->dialogue->theString.push_back(m1_l17);
		//M1_Obj1->dialogue->theString.push_back(m1_l18);
		//M1_Obj1->dialogue->theString.push_back(m1_l19);
		M1_Obj1->dialogue->theString.push_back(m1_l20);
		M1_Obj1->dialogue->theString.push_back(m1_l21);
		M1_Obj1->dialogue->theString.push_back(m1_l22);
		M1_Obj1->dialogue->theString.push_back(m1_l23);
		M1_Obj1->dialogue->theString.push_back(m1_l24);

		float time1_l12 = 5.0f;
		//float time1_l13 = 5.0f;
		float time1_l14 = 5.0f;
		float time1_l15 = 5.0f;
		//float time1_l16 = 5.0f;
		//float time1_l17 = 5.0f;
		//float time1_l18 = 5.0f;
		float time1_l19 = 5.0f;
		float time1_l20 = 5.0f;
		float time1_l21 = 5.0f;
		float time1_l22 = 5.0f;
		float time1_l23 = 5.0f;
		float time1_l24 = 5.0f;

		M1_Obj1->dialogue->timeRender.push_back(time1_l12);
		//M1_Obj1->dialogue->timeRender.push_back(time1_l13);
		M1_Obj1->dialogue->timeRender.push_back(time1_l14);
		M1_Obj1->dialogue->timeRender.push_back(time1_l15);
		//M1_Obj1->dialogue->timeRender.push_back(time1_l16);
		//M1_Obj1->dialogue->timeRender.push_back(time1_l17);
		//M1_Obj1->dialogue->timeRender.push_back(time1_l18);
		//M1_Obj1->dialogue->timeRender.push_back(time1_l19);
		M1_Obj1->dialogue->timeRender.push_back(time1_l20);
		M1_Obj1->dialogue->timeRender.push_back(time1_l21);
		M1_Obj1->dialogue->timeRender.push_back(time1_l22);
		M1_Obj1->dialogue->timeRender.push_back(time1_l23);
		M1_Obj1->dialogue->timeRender.push_back(time1_l24);

		Mission1->firstObjective = M1_Obj1;
		Mission1->currentObjectives.push_back(M1_Obj1);

		//***********Second objective
		Objective *M1_Obj2;
		sf::String string1_obj2("Kill the Lieutenant"); 
		M1_Obj2 = new Objective(true, 1, 0, true, string1_obj2, killIcon);

		M1_Obj2->NPCToKill = NPCsToKill[0];
		M1_Obj1->attachChild(M1_Obj2);
		


		//*************third objective
		Objective *M1_Obj3;
		sf::String string1_obj3("Go Back to Drava"); 
		M1_Obj3 = new Objective(true, 1, 0, true, string1_obj3, talkingIcon);

		M1_Obj3->goalArea = new collisionObject(5.0f, Vec3f(150.706f, 0.0f, 103.747f), 0.0f, false);
		M1_Obj3->dialogue = new Dialogue();

		///9 lines of dialogue
		sf::String m1_l25 = "So, you took care of him.";
		sf::String m1_l26 = "Guess you Sovereignty Agents are tougher than you look.";
		sf::String m1_l27 = "Listen. I've already helped you.";
		sf::String m1_l28 = "Are my family and I safe from...";
		sf::String m1_l29 = "the 'Invasion'?";
		sf::String m1_l30 = "........";
		sf::String m1_l31 = "I guess we'll have to trust you.";
		sf::String m1_l32 = "You might want to go check out the Dragon Club next.";
		sf::String m1_l33 = "Someone there might know where the other Lieutenant is.";
		sf::String m1_l34 = "See you around, Agent.";

		M1_Obj3->dialogue->theString.push_back(m1_l25);
		M1_Obj3->dialogue->theString.push_back(m1_l26);
		M1_Obj3->dialogue->theString.push_back(m1_l27);
		M1_Obj3->dialogue->theString.push_back(m1_l28);
		M1_Obj3->dialogue->theString.push_back(m1_l29);
		M1_Obj3->dialogue->theString.push_back(m1_l30);
		M1_Obj3->dialogue->theString.push_back(m1_l31);
		M1_Obj3->dialogue->theString.push_back(m1_l32);
		M1_Obj3->dialogue->theString.push_back(m1_l33);
		M1_Obj3->dialogue->theString.push_back(m1_l34);

		float time1_l25 = 4.0f;
		float time1_l26 = 5.0f;
		float time1_l27 = 4.0f;
		float time1_l28 = 4.0f;
		float time1_l29 = 4.0f;
		float time1_l30 = 4.0f;
		float time1_l31 = 4.0f;
		float time1_l32 = 4.0f;
		float time1_l33 = 4.0f;
		float time1_l34 = 3.0f;

		M1_Obj3->dialogue->timeRender.push_back(time1_l25);
		M1_Obj3->dialogue->timeRender.push_back(time1_l26);
		M1_Obj3->dialogue->timeRender.push_back(time1_l27);
		M1_Obj3->dialogue->timeRender.push_back(time1_l28);
		M1_Obj3->dialogue->timeRender.push_back(time1_l29);
		M1_Obj3->dialogue->timeRender.push_back(time1_l30);
		M1_Obj3->dialogue->timeRender.push_back(time1_l31);
		M1_Obj3->dialogue->timeRender.push_back(time1_l32);
		M1_Obj3->dialogue->timeRender.push_back(time1_l33);
		M1_Obj3->dialogue->timeRender.push_back(time1_l34);

		M1_Obj2->attachChild(M1_Obj3);


		///**************fourth objective
		Objective *M1_Obj4;
		sf::String string1_obj4 ("Go to Insertion Area and Report to HQ");
		M1_Obj4 = new Objective (true, 1, 0, true, string1_obj4, talkingIcon);
		
		M1_Obj4->goalArea = new collisionObject(5.0f, Vec3f(389.443f, 0.0f, 436.398f), 0.0f, false);
		M1_Obj4->dialogue = new Dialogue();
		
		sf::String m1_l35 = "Elara here.";
		sf::String m1_l36 = "I've been keeping up on your progress.";
		sf::String m1_l37 = "Looks like you've been busy riling up the locals.";
		sf::String m1_l38 = "If they didn't know the Sovereignty were here, they do now.";
		sf::String m1_l39 = "Drava's advice seems sound. Or you could look around for information yourself.";
		sf::String m1_l40 = "The choice is yours. I'll update you as you go along. Elara out.";

		M1_Obj4->dialogue->theString.push_back(m1_l35);
		M1_Obj4->dialogue->theString.push_back(m1_l36);
		M1_Obj4->dialogue->theString.push_back(m1_l37);
		M1_Obj4->dialogue->theString.push_back(m1_l38);
		M1_Obj4->dialogue->theString.push_back(m1_l39);
		M1_Obj4->dialogue->theString.push_back(m1_l40);

		float time1_l35 = 3.0f;
		float time1_l36 = 4.0f;
		float time1_l37 = 5.0f;
		float time1_l38 = 5.0f;
		float time1_l39 = 5.0f;
		float time1_l40 = 5.0f;

		M1_Obj4->dialogue->timeRender.push_back(time1_l35);
		M1_Obj4->dialogue->timeRender.push_back(time1_l36);
		M1_Obj4->dialogue->timeRender.push_back(time1_l37);
		M1_Obj4->dialogue->timeRender.push_back(time1_l38);
		M1_Obj4->dialogue->timeRender.push_back(time1_l39);
		M1_Obj4->dialogue->timeRender.push_back(time1_l40);

		M1_Obj3->attachChild(M1_Obj4);

	active = Mission1; //set this mission to the active one
	all.push_back(Mission1); //all missions that are active or not active are put into this list so they can be drawn in the objectives menu





	//***********Mission 2 - The Dragon's Den
	Mission *Mission2;
	Mission2 = new Mission(1, 0, true, "The Dragon's Den");

	//this is the starting area of the mission (i.e. where the player first discovers this mission)
	//Mission2->startArea = new collisionObject(10.0f, Vec3f(389.443f, 0.0f, 436.398f), 0.0f, false);

	
		//**********first objective
		Objective *M2_Obj1;
		sf::String string2_obj1("Enter the Dragon Club"); 
		M2_Obj1 = new Objective(true, 1, 0, true, string2_obj1, goToIcon);

		M2_Obj1->goalArea = new collisionObject(10.0f, Vec3f(276.031f, 0.0f, 217.157f), 0.0f, false);
		
		Mission2->firstObjective = M2_Obj1; 
		Mission2->currentObjectives.push_back(M2_Obj1);
		
		//*********second objective
		Objective *M2_Obj2;
		sf::String string2_obj2("Interrogate the Owner of the Dragon Club"); 
		M2_Obj2 = new Objective(false, 1, 0, false, string2_obj2, talkingIcon);

		M2_Obj2->goalArea = new collisionObject(5.0f, Vec3f(40.4878f, 0.0f, 192.99f), 0.0f, false);
		M2_Obj2->dialogue = new Dialogue();

		///
		sf::String m2_l1 = "How ... how did you get passed the guards?!";
		sf::String m2_l2 = "You... you must be the Sovereignty Agent.";
		sf::String m2_l3 = "Are you here about the Red Dragons?";
		sf::String m2_l4 = "I heard one of their Lieutenants was killed.";
		sf::String m2_l5 = "I'm guessing that was you.";
		sf::String m2_l6 = "You must be looking for the other one, right?";
		sf::String m2_l7 = "If I tell you where he is, will you leave me alone?";
		sf::String m2_l8 = "You'll find him in an alleyway just North of here.";
		sf::String m2_l9 = "He likes to get wasted by himself.";

		M2_Obj2->dialogue->theString.push_back(m2_l1);
		M2_Obj2->dialogue->theString.push_back(m2_l2);
		M2_Obj2->dialogue->theString.push_back(m2_l3);
		M2_Obj2->dialogue->theString.push_back(m2_l4);
		M2_Obj2->dialogue->theString.push_back(m2_l5);
		M2_Obj2->dialogue->theString.push_back(m2_l6);
		M2_Obj2->dialogue->theString.push_back(m2_l7);
		M2_Obj2->dialogue->theString.push_back(m2_l8);
		M2_Obj2->dialogue->theString.push_back(m2_l9);

		float time2_l1 = 4.0f;
		float time2_l2 = 4.0f;
		float time2_l3 = 4.0f;
		float time2_l4 = 4.0f;
		float time2_l5 = 4.0f;
		float time2_l6 = 4.0f;
		float time2_l7 = 4.0f;
		float time2_l8 = 4.0f;
		float time2_l9 = 4.0f;

		M2_Obj2->dialogue->timeRender.push_back(time2_l1);
		M2_Obj2->dialogue->timeRender.push_back(time2_l2);
		M2_Obj2->dialogue->timeRender.push_back(time2_l3);
		M2_Obj2->dialogue->timeRender.push_back(time2_l4);
		M2_Obj2->dialogue->timeRender.push_back(time2_l5);
		M2_Obj2->dialogue->timeRender.push_back(time2_l6);
		M2_Obj2->dialogue->timeRender.push_back(time2_l7);
		M2_Obj2->dialogue->timeRender.push_back(time2_l8);
		M2_Obj2->dialogue->timeRender.push_back(time2_l9);

		M2_Obj1->attachChild(M2_Obj2);


		//*******third objective
		Objective *M2_Obj3;
		sf::String string2_obj3("Kill the Club Owner");
		M2_Obj3 = new Objective(true, 1, 0, false, string2_obj3, killIcon);

		M2_Obj3->NPCToKill = NPCsToKill[1];
		M2_Obj2->attachChild(M2_Obj3);


		//***********fourth objective (choice between objective 3 and 4)
		Objective *M2_Obj4;
		sf::String string2_obj4("Or Leave the Dragon Club"); 
		M2_Obj4 = new Objective(true, 1, 0, true, string2_obj4, goToIcon);

		M2_Obj4->goalArea = new collisionObject(5.0f, Vec3f(276, 0, 210), 0.0f, false);
		M2_Obj2->attachChild(M2_Obj4);
	
		//////////////////////////////////////////////
		
	Mission1->attachChild(Mission2);	
	
	cannotDo.push_back(Mission2);



	//*******Mission 4 - Killing the Second Lieutenant 
	Mission *Mission4;
	Mission4 = new Mission (1, 0, true, "One Step Closer...");

	Mission4->startArea = new collisionObject(20.0f, Vec3f(276.031f, 0.0f, 217.157f), 0.0f, false);
	Mission4->dialogue = new Dialogue();

	sf::String m4_l1 = "That was great work back there.";
	sf::String m4_l2 = "But you're transmission cut out after you talked to the Owner.";
	sf::String m4_l3 = "Did you let him live or...";
	sf::String m4_l4 = "Never mind. I'm ... I'm sure you did what you had to, Agent.";
	sf::String m4_l5 = "So, the Second Lieutenant.";
	sf::String m4_l6 = "I'll mark his location on your HUD. Elara out.";

	Mission4->dialogue->theString.push_back(m4_l1);
	Mission4->dialogue->theString.push_back(m4_l2);
	Mission4->dialogue->theString.push_back(m4_l3);
	Mission4->dialogue->theString.push_back(m4_l4);
	Mission4->dialogue->theString.push_back(m4_l5);
	Mission4->dialogue->theString.push_back(m4_l6);

	float time4_l1 = 3.0f;
	float time4_l2 = 4.0f;
	float time4_l3 = 3.0f;
	float time4_l4 = 4.0f;
	float time4_l5 = 3.0f;
	float time4_l6 = 3.0f;

	Mission4->dialogue->timeRender.push_back(time4_l1);
	Mission4->dialogue->timeRender.push_back(time4_l2);
	Mission4->dialogue->timeRender.push_back(time4_l3);
	Mission4->dialogue->timeRender.push_back(time4_l4);
	Mission4->dialogue->timeRender.push_back(time4_l5);
	Mission4->dialogue->timeRender.push_back(time4_l6);


		//*******first objective 
		Objective *M4_Obj1;
		sf::String string4_obj1("Kill the Second Lieutenant");
		M4_Obj1 = new Objective (false, 1, 0, true, string4_obj1, killIcon);

		M4_Obj1->NPCToKill = NPCsToKill[3];
		Mission4->firstObjective = M4_Obj1;
		Mission4->currentObjectives.push_back(M4_Obj1);


	Mission2->attachChild(Mission4);
	
	cannotDo.push_back(Mission4);

	
	
	
	//***********Mission 3 - The Package (can be found anytime in level, only after completing Mission 1)
	Mission *Mission3;
	Mission3 = new Mission(1, 0, true, "The Package");

	Mission3->startArea = new collisionObject(5.0f, Vec3f(626.382f, 0.0f, 377.878f), 0.0f, false);
	Mission3->dialogue = new Dialogue ();

	sf::String m3_l1 = "Hey, you must be the Sovereignty Agent. I'm Omega.";
	sf::String m3_l2 = "The whole city's been talking about you.";
	sf::String m3_l3 = "Everyone's afraid of the big, bad Agent.";
	sf::String m3_l4 = "But not me. I see this as a time for... opportunity.";
	sf::String m3_l5 = "I need you to get a package for me. It's a small metal box.";
	sf::String m3_l6 = "You do this for me, Agent, and I can help you find the Red Dragon Leader.";
	sf::String m3_l7 = "The Package is inside the Grim Bar.";
	sf::String m3_l8 = "It's in the Kitchen just behind the Bar area.";
	sf::String m3_l9 = "I need you to bring it to one of my contacts.";
	sf::String m3_l10 = "After you pick it up, I'll send you the contact's location.";

	Mission3->dialogue->theString.push_back(m3_l1);
	Mission3->dialogue->theString.push_back(m3_l2);
	Mission3->dialogue->theString.push_back(m3_l3);
	Mission3->dialogue->theString.push_back(m3_l4);
	Mission3->dialogue->theString.push_back(m3_l5);
	Mission3->dialogue->theString.push_back(m3_l6);
	Mission3->dialogue->theString.push_back(m3_l7);
	Mission3->dialogue->theString.push_back(m3_l8);
	Mission3->dialogue->theString.push_back(m3_l9);
	Mission3->dialogue->theString.push_back(m3_l10);

	float time3_l1 = 4.0f;
	float time3_l2 = 4.0f;
	float time3_l3 = 4.0f;
	float time3_l4 = 4.0f;
	float time3_l5 = 4.0f;
	float time3_l6 = 4.0f;
	float time3_l7 = 4.0f;
	float time3_l8 = 4.0f;
	float time3_l9 = 4.0f;
	float time3_l10 = 4.0f;

	Mission3->dialogue->timeRender.push_back(time3_l1);
	Mission3->dialogue->timeRender.push_back(time3_l2);
	Mission3->dialogue->timeRender.push_back(time3_l3);
	Mission3->dialogue->timeRender.push_back(time3_l4);
	Mission3->dialogue->timeRender.push_back(time3_l5);
	Mission3->dialogue->timeRender.push_back(time3_l6);
	Mission3->dialogue->timeRender.push_back(time3_l7);
	Mission3->dialogue->timeRender.push_back(time3_l8);
	Mission3->dialogue->timeRender.push_back(time3_l9);
	Mission3->dialogue->timeRender.push_back(time3_l10);

		////////////first objective
		Objective *M3_Obj1;
		sf::String string3_obj1("Enter the Grim Bar"); 
		M3_Obj1 = new Objective(true, 1, 0, true, string3_obj1, goToIcon);

		M3_Obj1->goalArea = new collisionObject(10.0f, Vec3f(269.014f, 0.0f, 435.712f), 0.0f, false);
		M3_Obj1->dialogue = new Dialogue();

		sf::String m3_l11 = "Agent, Elara here.";
		sf::String m3_l12 = "I heard your conversation.";
		sf::String m3_l13 = "Be careful of this 'Omega' character.";
		sf::String m3_l14 = "I've run his face and his alias through the Database.";
		sf::String m3_l15 = "And I still haven't found a match.";
		sf::String m3_l16 = "I know the Database isn't up-to-date, but...";
		sf::String m3_l17 = "He has no record, not even on local servers.";
		sf::String m3_l18 = "Just... be careful, Agent. Elara out.";

		M3_Obj1->dialogue->theString.push_back(m3_l11);
		M3_Obj1->dialogue->theString.push_back(m3_l12);
		M3_Obj1->dialogue->theString.push_back(m3_l13);
		M3_Obj1->dialogue->theString.push_back(m3_l14);
		M3_Obj1->dialogue->theString.push_back(m3_l15);
		M3_Obj1->dialogue->theString.push_back(m3_l16);
		M3_Obj1->dialogue->theString.push_back(m3_l17);
		M3_Obj1->dialogue->theString.push_back(m3_l18);

		float time3_l11 = 3.0f;
		float time3_l12 = 3.0f;
		float time3_l13 = 3.0f;
		float time3_l14 = 4.0f;
		float time3_l15 = 4.0f;
		float time3_l16 = 4.0f;
		float time3_l17 = 4.0f;
		float time3_l18 = 4.0f;

		M3_Obj1->dialogue->timeRender.push_back(time3_l11);
		M3_Obj1->dialogue->timeRender.push_back(time3_l12);
		M3_Obj1->dialogue->timeRender.push_back(time3_l13);
		M3_Obj1->dialogue->timeRender.push_back(time3_l14);
		M3_Obj1->dialogue->timeRender.push_back(time3_l15);
		M3_Obj1->dialogue->timeRender.push_back(time3_l16);
		M3_Obj1->dialogue->timeRender.push_back(time3_l17);
		M3_Obj1->dialogue->timeRender.push_back(time3_l18);

		Mission3->firstObjective = M3_Obj1;
		Mission3->currentObjectives.push_back(M3_Obj1);

		///////*******second objective
		Objective *M3_Obj2;
		sf::String string3_obj2("Obtain the Package");
		M3_Obj2 = new Objective(false, 1, 1, false, string3_obj2, stealIcon); 

		M3_Obj2->theObject = new Object ("Images/Items/metal_crate.jpg", "Models/Items/metal_crate.obj", 12, true, Vec3f(163, 0, 85), Vec3f(5.0f, 5.0f, 5.0f), 0.0f, 1.0f, 1.0f, false);
		M3_Obj2->theObject->collisionZone = new collisionObject(10.0f, Vec3f(163, 0, 85), 0.0f, false);
		allObjects.push_back(M3_Obj2->theObject);
		
		M3_Obj1->attachChild(M3_Obj2);


		////******** second objective A
		//Objective *M3_Obj2A;
		//sf::String string3_obj2a("Leave the Grim Bar");
		//M3_Obj2A = new Objective(false, 1, 1, false, string3_obj2a, goToIcon);

		//M3_Obj2A->goalArea = new collisionObject(10.0f, Vec3f(28.0f, 0.0f, 155.0f), 0.0f, false);
		//M3_Obj2A->attachChild(M3_Obj2);




		//***************third objective (choice between this and the next objective)
		Objective *M3_Obj3;
		sf::String string3_obj3("Leave Grim Bar and Deliver the Package");
		M3_Obj3 = new Objective (true, 1, 0, true, string3_obj3, goToIcon);

		M3_Obj3->goalArea = new collisionObject (10.0f, Vec3f(151.764f, 0.0f, 790.565f), 0.0f, false); 
		M3_Obj3->dialogue = new Dialogue();

		sf::String m3_l20 = "You got the Package, Agent?";
		sf::String m3_l22 = "Thanks. Our organization appreciates your help.";
		sf::String m3_l23 = "You should head back to Omega.";

		M3_Obj3->dialogue->theString.push_back(m3_l20);
		M3_Obj3->dialogue->theString.push_back(m3_l22);
		M3_Obj3->dialogue->theString.push_back(m3_l23);

		float time3_l20 = 3.0f;
		float time3_l22 = 4.0f;
		float time3_l23 = 3.0f;

		M3_Obj3->dialogue->timeRender.push_back(time3_l20);
		M3_Obj3->dialogue->timeRender.push_back(time3_l22);
		M3_Obj3->dialogue->timeRender.push_back(time3_l23);

		M3_Obj2->attachChild(M3_Obj3);



		//******fourth objective (linked with choice between third and fourth objective)
		Objective *M3_Obj4;
		sf::String string3_obj4("Or Go back to Insertion point and Open Package");
		M3_Obj4 = new Objective (true, 1, 0, true, string3_obj4, goToIcon);

		M3_Obj4->goalArea = new collisionObject (5.0f, Vec3f(420.882f, 0.0f, 451.961f), 0.0f, false);
		M3_Obj4->dialogue = new Dialogue();

		sf::String m3_l24 = "Agent, Elara here. Glad you decided to investigate this.";
		sf::String m3_l25 = "Let me unlock the Package.";
		sf::String m3_l26 = "Should... be... there! It's open.";
		sf::String m3_l27 = "That looks like Sovereignty tech.";
		sf::String m3_l28 = "Its a Modular Decryption Device!";
		sf::String m3_l29 = "The Weapons Research Division just finished prototyping it.";
		sf::String m3_l30 = "It's a brute-force hacking tool for frontline soldiers.";
		sf::String m3_l31 = "It only started being deployed to our troops a week ago.";
		sf::String m3_l32 = "How did they get one?! What the hell is going on?";

		M3_Obj4->dialogue->theString.push_back(m3_l24);
		M3_Obj4->dialogue->theString.push_back(m3_l25);
		M3_Obj4->dialogue->theString.push_back(m3_l26);
		M3_Obj4->dialogue->theString.push_back(m3_l27);
		M3_Obj4->dialogue->theString.push_back(m3_l28);
		M3_Obj4->dialogue->theString.push_back(m3_l29);
		M3_Obj4->dialogue->theString.push_back(m3_l30);
		M3_Obj4->dialogue->theString.push_back(m3_l31);
		M3_Obj4->dialogue->theString.push_back(m3_l32);

		float time3_l24 = 4.0f;
		float time3_l25 = 4.0f;
		float time3_l26 = 4.0f;
		float time3_l27 = 4.0f;
		float time3_l28 = 4.0f;
		float time3_l29 = 4.0f;
		float time3_l30 = 4.0f;
		float time3_l31 = 4.0f;
		float time3_l32 = 4.0f;

		M3_Obj4->dialogue->timeRender.push_back(time3_l24);
		M3_Obj4->dialogue->timeRender.push_back(time3_l25);
		M3_Obj4->dialogue->timeRender.push_back(time3_l26);
		M3_Obj4->dialogue->timeRender.push_back(time3_l27);
		M3_Obj4->dialogue->timeRender.push_back(time3_l28);
		M3_Obj4->dialogue->timeRender.push_back(time3_l29);
		M3_Obj4->dialogue->timeRender.push_back(time3_l30);
		M3_Obj4->dialogue->timeRender.push_back(time3_l31);
		M3_Obj4->dialogue->timeRender.push_back(time3_l32);

		M3_Obj2->attachChild(M3_Obj4);


		//****fifth objective (only available if player chooses obejctive 3 - give package)
		Objective *M3_Obj5;
		sf::String string3_obj5("Return to Omega");
		M3_Obj5 = new Objective(true, 1, 0, true, string3_obj5, goToIcon);

		M3_Obj5->goalArea = new collisionObject(5.0f, Vec3f(626.382f, 0.0f, 377.878f), 0.0f, false);
		M3_Obj5->dialogue = new Dialogue();
		
		sf::String m3_l33 = "Looks like you came through, Agent.";
		sf::String m3_l34 = "And, don't worry, I've held up my end, too.";
		sf::String m3_l35 = "I didn't just find a clue for you, though.";
		sf::String m3_l36 = "I've found the Red Dragon boss.";
		sf::String m3_l37 = "You can find him in the Grim Bar, just West of here.";
		sf::String m3_l38 = "He should be in the Back Office.";
		sf::String m3_l39 = "He likes to 'medicate' himself.";
		sf::String m3_l40 = "Good luck, Agent. Maybe we'll meet again.";

		M3_Obj5->dialogue->theString.push_back(m3_l33);
		M3_Obj5->dialogue->theString.push_back(m3_l34);
		M3_Obj5->dialogue->theString.push_back(m3_l35);
		M3_Obj5->dialogue->theString.push_back(m3_l36);
		M3_Obj5->dialogue->theString.push_back(m3_l37);
		M3_Obj5->dialogue->theString.push_back(m3_l38);
		M3_Obj5->dialogue->theString.push_back(m3_l39);
		M3_Obj5->dialogue->theString.push_back(m3_l40);

		float time3_l33 = 4.0f;
		float time3_l34 = 4.0f;
		float time3_l35 = 4.0f;
		float time3_l36 = 4.0f;
		float time3_l37 = 4.0f;
		float time3_l38 = 4.0f;
		float time3_l39 = 4.0f;
		float time3_l40 = 4.0f;

		M3_Obj5->dialogue->timeRender.push_back(time3_l33);
		M3_Obj5->dialogue->timeRender.push_back(time3_l34);
		M3_Obj5->dialogue->timeRender.push_back(time3_l35);
		M3_Obj5->dialogue->timeRender.push_back(time3_l36);
		M3_Obj5->dialogue->timeRender.push_back(time3_l37);
		M3_Obj5->dialogue->timeRender.push_back(time3_l38);
		M3_Obj5->dialogue->timeRender.push_back(time3_l39);
		M3_Obj5->dialogue->timeRender.push_back(time3_l40);

		M3_Obj3->attachChild(M3_Obj5);


		//**********sixth objective (ties in with objective 4 - investigate package)
		Objective *M3_Obj6;
		sf::String string3_obj6("Confront Omega");
		M3_Obj6 = new Objective(true, 1, 0, true, string3_obj6, goToIcon);

		M3_Obj6->goalArea = new collisionObject(5.0f, Vec3f(626.382f, 0.0f, 377.878f), 0.0f, false);
		M3_Obj6->dialogue = new Dialogue();

		sf::String m3_l41 = "My contact never got the Package.";
		sf::String m3_l42 = "So I guess you opened it. Damn.";
		sf::String m3_l43 = "Look, it's just business, Agent.";
		sf::String m3_l44 = "My organization wants no part in your wars.";
		sf::String m3_l45 = "Can't you just let this one slide?";
		sf::String m3_l46 = "Look, you can keep the Package. No harm done, right?";
		sf::String m3_l47 = "I'll give you the location of the Red Dragon boss.";
		sf::String m3_l48 = "He's in the Grim Bar, in the Back Office.";
		sf::String m3_l49 = "So, will you let me live?";

		M3_Obj6->dialogue->theString.push_back(m3_l41);
		M3_Obj6->dialogue->theString.push_back(m3_l42);
		M3_Obj6->dialogue->theString.push_back(m3_l43);
		M3_Obj6->dialogue->theString.push_back(m3_l44);
		M3_Obj6->dialogue->theString.push_back(m3_l45);
		M3_Obj6->dialogue->theString.push_back(m3_l46);
		M3_Obj6->dialogue->theString.push_back(m3_l47);
		M3_Obj6->dialogue->theString.push_back(m3_l48);
		M3_Obj6->dialogue->theString.push_back(m3_l49);

		float time3_l41 = 4.0f;
		float time3_l42 = 4.0f;
		float time3_l43 = 4.0f;
		float time3_l44 = 4.0f;
		float time3_l45 = 4.0f;
		float time3_l46 = 4.0f;
		float time3_l47 = 4.0f;
		float time3_l48 = 4.0f;
		float time3_l49 = 4.0f;

		M3_Obj6->dialogue->timeRender.push_back(time3_l41);
		M3_Obj6->dialogue->timeRender.push_back(time3_l42);
		M3_Obj6->dialogue->timeRender.push_back(time3_l43);
		M3_Obj6->dialogue->timeRender.push_back(time3_l44);
		M3_Obj6->dialogue->timeRender.push_back(time3_l45);
		M3_Obj6->dialogue->timeRender.push_back(time3_l46);
		M3_Obj6->dialogue->timeRender.push_back(time3_l47);
		M3_Obj6->dialogue->timeRender.push_back(time3_l48);
		M3_Obj6->dialogue->timeRender.push_back(time3_l49);

		M3_Obj4->attachChild(M3_Obj6);



		//********seventh objective (this will be a choice to either kill or let Omega live)
		Objective *M3_Obj7;
		sf::String string3_obj7("Kill Omega");
		M3_Obj7 = new Objective (true, 1, 0, true, string3_obj7, killIcon);

		M3_Obj7->NPCToKill = NPCsToKill[2];
		M3_Obj6->attachChild(M3_Obj7);


		//*******eigth objective (walk away to a certain spot to let Omega live)
		Objective *M3_Obj8;
		sf::String string3_obj8("Or Let Omega live");
		M3_Obj8 = new Objective(true, 1, 0, true, string3_obj8, goToIcon); 

		M3_Obj8->goalArea = new collisionObject (10.0f, Vec3f(542.498f, 0.0f, 325.013f), 0.0f, false);
		M3_Obj6->attachChild(M3_Obj8);



	Mission1->attachChild(Mission3);
	cannotDo.push_back(Mission3);



	//****** Mission 5 - Head of the Dragon
	Mission *Mission5;
	Mission5 = new Mission (1, 0, true, "Head of the Dragon");

	//Mission5->startArea = new collisionObject(5.0f, Vec3f(389.443f, 0.0f, 436.398f), 0.0f, false);
	Mission5->dialogue = new Dialogue();

	sf::String m5_l1 = "Agent, Elara here.";
	sf::String m5_l2 = "I've been trying to verify Omega's info.";
	sf::String m5_l3 = "Looks like he was telling the truth.";
	sf::String m5_l4 = "There's been a lot of comm traffic from the office.";
	sf::String m5_l5 = "We don't know what the Red Dragon boss looks like.";
	sf::String m5_l6 = "We only know what he sounds like from intercepted comms.";
	sf::String m5_l7 = "If he is in there, you're going to have to get him to talk.";
	sf::String m5_l8 = "Good luck, Agent. And be careful. Elara out.";

	Mission5->dialogue->theString.push_back(m5_l1);
	Mission5->dialogue->theString.push_back(m5_l2);
	Mission5->dialogue->theString.push_back(m5_l3);
	Mission5->dialogue->theString.push_back(m5_l4);
	Mission5->dialogue->theString.push_back(m5_l5);
	Mission5->dialogue->theString.push_back(m5_l6);
	Mission5->dialogue->theString.push_back(m5_l7);
	Mission5->dialogue->theString.push_back(m5_l8);

	float time5_l1 = 3.0f;
	float time5_l2 = 4.0f;
	float time5_l3 = 4.0f;
	float time5_l4 = 5.0f;
	float time5_l5 = 5.0f;
	float time5_l6 = 5.0f;
	float time5_l7 = 5.0f;
	float time5_l8 = 4.0f;

	Mission5->dialogue->timeRender.push_back(time5_l1);
	Mission5->dialogue->timeRender.push_back(time5_l2);
	Mission5->dialogue->timeRender.push_back(time5_l3);
	Mission5->dialogue->timeRender.push_back(time5_l4);
	Mission5->dialogue->timeRender.push_back(time5_l5);
	Mission5->dialogue->timeRender.push_back(time5_l6);
	Mission5->dialogue->timeRender.push_back(time5_l7);
	Mission5->dialogue->timeRender.push_back(time5_l8);



		//****** first objective
		Objective *M5_Obj1;
		sf::String string5_obj1("Go to the Grim Bar");
		M5_Obj1 = new Objective(false, 1, 0, true, string5_obj1, goToIcon);
		
		M5_Obj1->goalArea = new collisionObject(10.0f, Vec3f(269.014f, 0.0f, 435.712f), 0.0f, false);
		Mission5->firstObjective = M5_Obj1;
		Mission5->currentObjectives.push_back(M5_Obj1);


		//******Second objective
		Objective *M5_Obj2;
		sf::String string5_obj2("Verify Identity of Red Dragon Boss");
		M5_Obj2 = new Objective(false, 1, 1, false, string5_obj2, goToIcon);

		M5_Obj2->goalArea = new collisionObject(3.0f, Vec3f(144.146f, 0.0f, 31.593f), 0.0f, false);
		M5_Obj2->dialogue = new Dialogue();

		sf::String m5_l9 = "So, the Sovereignty dog has finally found me.";
		sf::String m5_l10 = "Well, it was only a matter of time.";
		sf::String m5_l11 = "But you are dead wrong if you think I'll go quietly.";
		sf::String m5_l12 = "Wait. Elara here. Something's not right.";
		sf::String m5_l13 = "The voice patterns, they're not the same.";
		sf::String m5_l14 = "This isn't the Red Dragon boss.";
		sf::String m5_l15 = "I guess your Handler has just told you who I am.";
		sf::String m5_l16 = "Or more precisely, who I'm not."; 
		sf::String m5_l17 = "He should be in another District by now. You're too late.";
		sf::String m5_l18 = "I did my job. At least my family will be safe now.";

		M5_Obj2->dialogue->theString.push_back(m5_l9);
		M5_Obj2->dialogue->theString.push_back(m5_l10);
		M5_Obj2->dialogue->theString.push_back(m5_l11);
		M5_Obj2->dialogue->theString.push_back(m5_l12);
		M5_Obj2->dialogue->theString.push_back(m5_l13);
		M5_Obj2->dialogue->theString.push_back(m5_l14);
		M5_Obj2->dialogue->theString.push_back(m5_l15);
		M5_Obj2->dialogue->theString.push_back(m5_l16);
		M5_Obj2->dialogue->theString.push_back(m5_l17);
		M5_Obj2->dialogue->theString.push_back(m5_l18);

		float time5_l9 = 4.0f;
		float time5_l10 = 4.0f;
		float time5_l11 = 4.0f;
		float time5_l12 = 4.0f;
		float time5_l13 = 4.0f;
		float time5_l14 = 4.0f;
		float time5_l15 = 4.0f;
		float time5_l16 = 4.0f;
		float time5_l17 = 4.0f;
		float time5_l18 = 4.0f;

		M5_Obj2->dialogue->timeRender.push_back(time5_l9);
		M5_Obj2->dialogue->timeRender.push_back(time5_l10);
		M5_Obj2->dialogue->timeRender.push_back(time5_l11);
		M5_Obj2->dialogue->timeRender.push_back(time5_l12);
		M5_Obj2->dialogue->timeRender.push_back(time5_l13);
		M5_Obj2->dialogue->timeRender.push_back(time5_l14);
		M5_Obj2->dialogue->timeRender.push_back(time5_l15);
		M5_Obj2->dialogue->timeRender.push_back(time5_l16);
		M5_Obj2->dialogue->timeRender.push_back(time5_l17);
		M5_Obj2->dialogue->timeRender.push_back(time5_l18);

		M5_Obj1->attachChild(M5_Obj2);


		//*************** third objective
		Objective *M5_Obj3;
		sf::String string5_obj3("Kill the Imposter");
		M5_Obj3 = new Objective (true, 1, 1, false, string5_obj3, killIcon);

		M5_Obj3->NPCToKill = NPCsToKill[4];
		M5_Obj2->attachChild(M5_Obj3);


		//*********** fourth objective - connected with third objective
		Objective *M5_Obj4;
		sf::String string5_obj4("Or let the Imposter live");
		M5_Obj4 = new Objective (true, 1, 1, false, string5_obj3, goToIcon);

		M5_Obj3->goalArea = new collisionObject (5.0f, Vec3f(101.586f, 0.0f, 33.0498f), 0.0f, false); 
		M5_Obj2->attachChild(M5_Obj4);


		//********fifth objective - this is outcome if player chooses to kill imposter
		Objective *M5_Obj5;
		sf::String string5_obj5("Leave Grim Bar and go to Insertion Point");
		M5_Obj5 = new Objective (true, 1, 0, true, string5_obj5, goToIcon);

		M5_Obj5->goalArea = new collisionObject (5.0f, Vec3f(420.882f, 0.0f, 451.961f), 0.0f, false);
		M5_Obj5->dialogue = new Dialogue();

		sf::String m5_l19 = "Agent, Elara here.";
		sf::String m5_l20 = "I saw you kill the Imposter.";
		sf::String m5_l21 = "You didn't have to, he... sorry.";
		sf::String m5_l22 = "I didn't mean to question your judgement, Agent.";
		sf::String m5_l23 = "You make the calls down there.";
		sf::String m5_l24 = "We're looking for the real Red Dragon boss, now.";
		sf::String m5_l25 = "There are four other districts in this city.";
		sf::String m5_l26 = "We'll narrow it down for you.";
		sf::String m5_l27 = "In the meantime, there might be other leads you can look into.";
		sf::String m5_l28 = "Ask and talk to the locals. They might know something.";
		sf::String m5_l29 = "I'll update you if need be, Elara out.";

		M5_Obj5->dialogue->theString.push_back(m5_l19);
		M5_Obj5->dialogue->theString.push_back(m5_l20);
		M5_Obj5->dialogue->theString.push_back(m5_l21);
		M5_Obj5->dialogue->theString.push_back(m5_l22);
		M5_Obj5->dialogue->theString.push_back(m5_l23);
		M5_Obj5->dialogue->theString.push_back(m5_l24);
		M5_Obj5->dialogue->theString.push_back(m5_l25);
		M5_Obj5->dialogue->theString.push_back(m5_l26);
		M5_Obj5->dialogue->theString.push_back(m5_l27);
		M5_Obj5->dialogue->theString.push_back(m5_l28);
		M5_Obj5->dialogue->theString.push_back(m5_l29);

		float time5_l19 = 3.0f;
		float time5_l20 = 3.0f;
		float time5_l21 = 3.0f;
		float time5_l22 = 4.0f;
		float time5_l23 = 3.0f;
		float time5_l24 = 4.0f;
		float time5_l25 = 4.0f;
		float time5_l26 = 3.0f;
		float time5_l27 = 5.0f;
		float time5_l28 = 4.0f;
		float time5_l29 = 3.0f;

		M5_Obj5->dialogue->timeRender.push_back(time5_l19);
		M5_Obj5->dialogue->timeRender.push_back(time5_l20);
		M5_Obj5->dialogue->timeRender.push_back(time5_l21);
		M5_Obj5->dialogue->timeRender.push_back(time5_l22);
		M5_Obj5->dialogue->timeRender.push_back(time5_l23);
		M5_Obj5->dialogue->timeRender.push_back(time5_l24);
		M5_Obj5->dialogue->timeRender.push_back(time5_l25);
		M5_Obj5->dialogue->timeRender.push_back(time5_l26);
		M5_Obj5->dialogue->timeRender.push_back(time5_l27);
		M5_Obj5->dialogue->timeRender.push_back(time5_l28);
		M5_Obj5->dialogue->timeRender.push_back(time5_l29);

		M5_Obj3->attachChild(M5_Obj5);



		//**********sixth objective - linked to objective four (not killing the imposter)
		Objective *M5_Obj6;
		sf::String string5_obj6("Leave Grim Bar and go to Insertion Point");
		M5_Obj6 = new Objective (true, 1, 0, true, string5_obj6, goToIcon);

		M5_Obj6->goalArea = new collisionObject (10.0f, Vec3f(420.882f, 0.0f, 451.961f), 0.0f, false);
		M5_Obj6->dialogue = new Dialogue();

		sf::String m5_l30 = "Agent, Elara here.";
		sf::String m5_l31 = "I'm glad you let the Imposter live.";
		sf::String m5_l32 = "He was just doing what he had to.";
		sf::String m5_l33 = "We're looking for the real leader now.";
		//sf::String m5_l34 = "There are four other districts in the city.";
		sf::String m5_l35 = "But, this might take some time.";
		sf::String m5_l36 = "Maybe you can find other leads in this district.";
		sf::String m5_l37 = "I'll let you know if something comes up.";
		sf::String m5_l38 = "Stay safe, Agent. Elara out.";

		M5_Obj6->dialogue->theString.push_back(m5_l30);
		M5_Obj6->dialogue->theString.push_back(m5_l31);
		M5_Obj6->dialogue->theString.push_back(m5_l32);
		M5_Obj6->dialogue->theString.push_back(m5_l33);
		//M5_Obj6->dialogue->theString.push_back(m5_l34);
		M5_Obj6->dialogue->theString.push_back(m5_l35);
		M5_Obj6->dialogue->theString.push_back(m5_l36);
		M5_Obj6->dialogue->theString.push_back(m5_l37);
		M5_Obj6->dialogue->theString.push_back(m5_l38);

		float time5_l30 = 3.0f;
		float time5_l31 = 4.0f;
		float time5_l32 = 4.0f;
		float time5_l33 = 4.0f;
		//float time5_l34 = 4.0f;
		float time5_l35 = 4.0f;
		float time5_l36 = 4.0f;
		float time5_l37 = 4.0f;
		float time5_l38 = 3.0f;

		M5_Obj6->dialogue->timeRender.push_back(time5_l30);
		M5_Obj6->dialogue->timeRender.push_back(time5_l31);
		M5_Obj6->dialogue->timeRender.push_back(time5_l32);
		M5_Obj6->dialogue->timeRender.push_back(time5_l33);
		//M5_Obj6->dialogue->timeRender.push_back(time5_l34);
		M5_Obj6->dialogue->timeRender.push_back(time5_l35);
		M5_Obj6->dialogue->timeRender.push_back(time5_l36);
		M5_Obj6->dialogue->timeRender.push_back(time5_l37);
		M5_Obj6->dialogue->timeRender.push_back(time5_l38);

		M5_Obj4->attachChild(M5_Obj6);



	Mission3->attachChild(Mission5);
	cannotDo.push_back(Mission5);

}






//****************************************************************************************************************************************************************************//
//**********************************DO NOT CHANGE/WRITE ANYTHING IN THE BELOW FUNCTIONS**************************************************************************************//
////////////if you need to add something to a partcular mission or objective, add it to the GameMissions::loadGameMissions() function//////////////////////////////////////////
//*************************************************************************************************************************************************************************//


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//OBJECTS

Object::Object()
{
	theTexture = NULL;
	theModel = NULL;
	pos = Vec3f();
	theta = 0.0f;
	collisionZone = NULL;
}

Object::Object(const std::string &textureFilename, char *modelFilename, int maxTriangles, bool draw, Vec3f position, Vec3f Scale, float angle, int level, int subLevel, bool outSide)
{
	theTexture = new tex();
	theTexture->loadTex(textureFilename);

	theModel = new objLoader();
	theModel->LoadOBJ(modelFilename, maxTriangles);

	render = draw;
	pos = position;
	theta = angle;
	scale = Scale;

	Level = level;
	SubLevel = subLevel;
	OutSide = outSide;

	collisionZone = NULL;
}

Object::~Object()
{
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Dialogue
Dialogue::Dialogue()
{
	dialogueDone = false; 
	index = 0;
	render = false;
	time = 0.0f;
	updateRes = false;

	if (!font.loadFromFile("Fonts/arial.ttf"))
	{
		// error...
		cout << "ERROR, Font could not load" << endl;
	}
	text.setFont(font);
	text.setString("...");
	text.setCharacterSize(16);
	sf::Color color(255, 255, 255, 255);
	text.setColor(color);
	text.setPosition(200.0f, 400.0f);

	prevRes = sf::Vector2f(800.0f, 600.0f);
	offsetRes = sf::Vector2f(1.0f, 1.0f);
}
Dialogue::~Dialogue()
{
}

void Dialogue::draw(sf::RenderWindow *window)
{
	/*sf::Vector2f temp((sf::Vector2f)window->getSize());
	offsetRes = sf::Vector2f(temp.x/prevRes.x, temp.y/prevRes.y); 
	prevRes = temp;*/

	if(prevRes != (sf::Vector2f)window->getSize())
	{
		sf::Vector2f temp((sf::Vector2f)window->getSize());
		offsetRes = sf::Vector2f(temp.x/800.0f, temp.y/600.0f); 
		prevRes = temp;
	}

	//update text
	//reset the position of the text upon window resize
	text.setPosition(sf::Vector2f(200.0f * offsetRes.x, 400.0f * offsetRes.y));

	window->pushGLStates();
	window->draw(text);
	window->popGLStates();
}
void Dialogue::update( float dt)
{
	////reset the position of the text upon window resize
	//if(offsetRes != sf::Vector2f(1.0f, 1.0f))
	//{
	//	sf::Vector2f temp = text.getPosition();
	//	text.setPosition(temp.x * offsetRes.x, temp.y * offsetRes.y);
	//}

	if(dt < 1.0f)
	{
		time += dt; 
		
		if(index < theString.size())
		{
			render = true;
			text.setString(theString[index]);
			if(time >= timeRender[index])
			{
				index++;
				time = 0.0f;
			}
			//this give the player the ability to skip parts of the dialogue if they wish to
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Joystick::isButtonPressed(0,0))
			{
				//make sure there is a pause between clicks
				if(time > 0.5f)
				{
					index++;
					time = 0.0f;
				}
			}
		}
		else
		{
			render = false;
			dialogueDone = true; 
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//OBJECTIVES	
Objective::Objective()
{
	goalArea = NULL;
	NPCToKill = NULL;
	theObject = NULL;
	dialogue = NULL;
	objectiveComplete = false;

	display =  true;
	renderObjective = true;
}

Objective::Objective(bool Choice, int level, int subLevel, bool outSide, sf::String popup, tex *textureForIcon)
{
	choice = Choice;
	Level = level;
	SubLevel = subLevel;
	OutSide = outSide;
	theString = popup;

	goalArea = NULL;
	NPCToKill = NULL;
	theObject = NULL;
	dialogue = NULL;
	objectiveComplete = false;
	updateRes = false;

	display =  true;	

	//font
	if (!font.loadFromFile("Fonts/arial.ttf"))
	{
		// error...
		cout << "ERROR, Font could not load" << endl;
	}
	text.setFont(font);
	text.setString(theString);
	text.setCharacterSize(16);
	sf::Color color(255, 255, 255, 0);
	text.setColor(color);
	textStartingPos = textCurrentPos = Vec3f(300.0f, 150.0f, 0.0f);
	textEndingPos = Vec3f(300.0f, 100.0f, 0.0f);
	text.setPosition(textStartingPos[0], textStartingPos[1]);

	wait = false;
	time = 0.0f;
	waitCounter = 0;

	errorCounter = 0;
	space = false;
	waitLonger = false;

	prevRes = sf::Vector2f(800.0f, 600.0f);
	offsetRes = sf::Vector2f(1.0f, 1.0f);

	iconSize = 5.0f / 2.0f;
	iconTexture = textureForIcon;

	
	renderObjective = true;
}

Objective::~Objective()
{
}

void Objective::attachChild(Objective *child)
{ 
	child->parents.push_back(this);
	children.push_back(child);
}

void Objective::updateObjective(playerStats *player, float dt)
{
	iconTheta = player->theta - 180.0f;

	////reset the position of the text upon window resize
	//if(offsetRes != sf::Vector2f(1.0f, 1.0f))
	//{
	//	sf::Vector2f temp = text.getPosition();
	//	text.setPosition(temp.x * offsetRes.x, temp.y * offsetRes.y);
	//}
	//
	////if there are more than one objectives as the current objectives
	//if(difference > 0 && !space)
	//{
	//	wait = true;
	//	space = true;
	//	waitLonger = true;
	//}

	////for errors
	//if(dt < 1.0f && textDone)
	//{
	//	time += dt;

	//	if(time > 1.0f + ((int)waitLonger * difference))
	//	{
	//		time = 0.0f;
	//		if(waitLonger)
	//		{
	//			waitLonger = false;
	//		}
	//		//makes sure that the text doesn't lerp forever
	//		if(waitCounter <= 2 + ((int)space * 1))
	//		{
	//			//if text is waiting, i.e. not moving
	//			if(wait)
	//			{
	//				if(space && waitCounter == 0)
	//				{
	//					//do nothing
	//				}
	//				else
	//				{
	//					textStartingPos = textCurrentPos;
	//				}
	//				wait = false;
	//				waitCounter++;
	//			}
	//			else
	//			{
	//				wait = true;
	//				waitCounter++;
	//			}
	//		}
	//		else
	//		{
	//			sf::Color color(255, 255, 255, 0);
	//			text.setColor(color);
	//		}
	//	}
	//	//if text is not waiting, i.e. its postion is being LERP
	//	if(!wait)
	//	{
	//		//if it is going from 0 to 1 in terms of transparency
	//		if(waitCounter == 0 + ((int)space * 1))
	//		{
	//			sf::Color color(255, 255, 255, time * 255);
	//			text.setColor(color);
	//		}
	//		//if it is going from 1 to 0 in terms of transparency
	//		else
	//		{
	//			sf::Color color(255, 255, 255, (1 - time) * 255);
	//			text.setColor(color);
	//		}
	//		//LERP the text into its proper current position
	//		textCurrentPos = LERP(textStartingPos, textEndingPos, dt);
	//		text.move(textCurrentPos[0] - textStartingPos[0], textCurrentPos[1] - textStartingPos[1]);
	//	}
	//}

	if(goalArea != NULL)
	{
		iconPos = goalArea->position + Vec3f(0.0f, 20.0f, 0.0f); 

		//if the goal area is not a static collision object
		if(goalArea->updatePos)
		{
			//goalAreas[i].updateCollisionObject(
		}

		//if the player collides the with collision object
		if(player->cObject.collisionTest(goalArea))
		{
			//if the goal area is a dialogue zone
			if(dialogue != NULL)
			{
				dialogue->update(dt);
				player->dialogue = true;
				player ->playerMove = false;

				if(dialogue->dialogueDone)
				{
					objectiveComplete = true;
					player->dialogue = false;
					player ->playerMove = true;
				}
			}
			else
			{
				objectiveComplete = true;
			}
		}
	}

	else if(NPCToKill != NULL)
	{
		iconPos = NPCToKill->position + Vec3f(0.0f, 20.0f, 0.0f); 

		if(!NPCToKill->alive)
		{
			objectiveComplete = true;
		}
	}

	else if(theObject != NULL)
	{
		iconPos = theObject->pos + Vec3f(0.0f, 20.0f, 0.0f); 

		if(player->cObject.collisionTest(theObject->collisionZone))
		{
			if(theObject->render && errorCounter < 1)
			{
				theObject->render = false;
				errorCounter++;
			}
			else if (errorCounter < 1)
			{
				theObject->render = true;
				errorCounter++;
			}

			objectiveComplete = true;
		}
	}
}

//for now display current objective to the console
void Objective::drawObjective(sf::RenderWindow *window, float dt,  bool textDone, int difference)
{
	timeDifference = dt;
	TextDone = textDone;
	Difference = difference;

	sf::Vector2f temp((sf::Vector2f)window->getSize());
	offsetRes = sf::Vector2f(temp.x/prevRes.x, temp.y/prevRes.y); 
	prevRes = temp;

	//update text
	//reset the position of the text upon window resize
	if(offsetRes != sf::Vector2f(1.0f, 1.0f))
	{
		sf::Vector2f temp = text.getPosition();
		text.setPosition(temp.x * offsetRes.x, temp.y * offsetRes.y);
	}
	
	//if there are more than one objectives as the current objectives
	if(Difference > 0 && !space)
	{
		wait = true;
		space = true;
		waitLonger = true;
	}

	//for errors
	if(timeDifference < 1.0f && TextDone)
	{
		time += timeDifference;

		if(time > 1.0f + ((int)waitLonger * Difference))
		{
			time = 0.0f;
			if(waitLonger)
			{
				waitLonger = false;
			}
			//makes sure that the text doesn't lerp forever
			if(waitCounter <= 2 + ((int)space * 1))
			{
				//if text is waiting, i.e. not moving
				if(wait)
				{
					if(space && waitCounter == 0)
					{
						//do nothing
					}
					else
					{
						textStartingPos = textCurrentPos;
					}
					wait = false;
					waitCounter++;
				}
				else
				{
					wait = true;
					waitCounter++;
				}
			}
			else
			{
				sf::Color color(255, 255, 255, 0);
				text.setColor(color);
			}
		}
		//if text is not waiting, i.e. its postion is being LERP
		if(!wait)
		{
			//if it is going from 0 to 1 in terms of transparency
			if(waitCounter == 0 + ((int)space * 1))
			{
				sf::Color color(255, 255, 255, time * 255);
				text.setColor(color);
			}
			//if it is going from 1 to 0 in terms of transparency
			else
			{
				sf::Color color(255, 255, 255, (1 - time) * 255);
				text.setColor(color);
			}
			//LERP the text into its proper current position
			textCurrentPos = LERP(textStartingPos, textEndingPos, timeDifference);
			text.move(textCurrentPos[0] - textStartingPos[0], textCurrentPos[1] - textStartingPos[1]);
		}
	}

	////draw the required text
	window->pushGLStates();
	window->draw(text);
	window->popGLStates();

	if(dialogue != NULL)
	{
		if(dialogue->render)
		{
			dialogue->draw(window);
		}
	}
}

void Objective::drawIcons(cbmini::cbfw::GLSLProgram *ShaderProgram)
{
	glUniform1f(glGetUniformLocation(ShaderProgram->GetHandle(), "size"), iconSize);
	glUniform1f(glGetUniformLocation(ShaderProgram->GetHandle(), "alpha"), 1.0f);

	//render the objective's icone
	glDisable(GL_DEPTH_TEST);
	glPushMatrix();
	iconTexture->drawTex(0);
	glBegin(GL_POINTS);
			glVertex3f(iconPos[0], iconPos[1], iconPos[2]);
	glEnd();
	glPopMatrix();
	glEnable(GL_DEPTH_TEST);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MISSIONS
Mission::Mission()
{
	startArea = NULL;
	firstObjective = NULL;
	dialogue = NULL; 
	completed = false;
}

Mission::Mission(int startLevel, int startSubLevel, bool startOutSide, sf::String missionName)
{
	Level = startLevel;
	SubLevel = startSubLevel;
	OutSide = startOutSide;
	theString = missionName; 

	startArea = NULL;
	firstObjective = NULL;
	dialogue = NULL;
	completed = false;
	updateRes = false;

	//font
	if (!font.loadFromFile("Fonts/arial.ttf"))
	{
		// error...
		cout << "ERROR, Font could not load" << endl;
	}
	text.setFont(font);
	text.setString("STARTED: " + theString);
	text.setCharacterSize(20);
	sf::Color color(255, 255, 255, 0);
	text.setColor(color);
	text.setPosition(300.0f, 100.0f);
	currentTextPos = sf::Vector2f(300.0f, 100.0f);

	wait = false;
	time = 0.0f;
	waitCounter = 0;
	textDone = false;
	updateTex = true;

	prevRes = sf::Vector2f(800.0f, 600.0f);
	offsetRes = sf::Vector2f(1.0f, 1.0f);
}

Mission::~Mission()
{
}

void Mission::attachChild(Mission *child)
{
	child->parents.push_back(this);
	children.push_back(child);
}

void Mission::updateMission(playerStats *player, int level, int subLevel, bool outside, float dt)
{
	////reset the position of the text upon window resize
	//currentTextPos = sf::Vector2f(300.0f * offsetRes.x, 100.0f * offsetRes.y);
	//text.setPosition(currentTextPos);

	//if(dt < 1.0f)
	//{
	//	time += dt;

	//	if(time > 1.0f)
	//	{
	//		time = 0.0f;
	//		//makes sure that the text doesn't lerp forever
	//		if(waitCounter <= 2)
	//		{
	//			//if text is waiting, i.e. not moving
	//			if(wait)
	//			{
	//				wait = false;
	//				waitCounter++;
	//			}
	//			else
	//			{
	//				wait = true;
	//				waitCounter++;
	//				if(waitCounter > 2)
	//				{
	//					textDone = true;
	//				}
	//			}
	//		}
	//		else
	//		{
	//			sf::Color color(255, 255, 255, 0);
	//			text.setColor(color);
	//		}
	//	}
	//	//if text is not waiting, i.e. its postion is being LERP
	//	if(!wait)
	//	{
	//		//if it is going from 0 to 1 in terms of transparency
	//		if(waitCounter == 0)
	//		{
	//			sf::Color color(255, 255, 255, time * 255);
	//			text.setColor(color);
	//		}
	//		//if it is going from 1 to 0 in terms of transparency
	//		else
	//		{
	//			sf::Color color(255, 255, 255, (1 - time) * 255);
	//			text.setColor(color);
	//		}
	//	}
	//}

	for(unsigned int i = 0; i < currentObjectives.size(); i++)
	{
		//only update the objective if the player is currently in the right part of the map
		if(currentObjectives[i]->OutSide == outside && currentObjectives[i]->Level == level && currentObjectives[i]->SubLevel == subLevel)
		{
			currentObjectives[i]->updateObjective(player, dt);	//update the objective
			currentObjectives[i]->renderObjective = true;
		}
		else
		{
			currentObjectives[i]->renderObjective = false;
		}

		if(currentObjectives[i]->objectiveComplete)	//if the objective has been completed
		{
			//so do objective A or B but not both to progress the mission state
			if(currentObjectives[i]->choice)
			{
				if(currentObjectives[i]->children.empty())
				{
					if(updateTex)
					{
						updateTex = false;
						text.setString("COMPLETED: " + theString);
						wait = false;
						time = 0.0f;
						waitCounter = 0;
						textDone = false;
					}

					if(textDone)
					{
						completed = true; 
					}
				}
				else
				{

					Objective *temp = new Objective();
					temp = currentObjectives[i];
					currentObjectives.clear();

					for(unsigned int j = 0; j < temp->children.size(); j++)	//set the objective's children as the new current objectives
					{
						currentObjectives.push_back(temp->children[j]);
					}

					delete temp;
				}
			}
			//so do both objective A and B to progress the mission state
			else
			{
				//if there are more than one objective in the list
				if(currentObjectives.size() > 1)
				{
					currentObjectives.erase(currentObjectives.begin() + i);	//erase the objective from the list
				}
				//turn is into a choice objective so it can be easily be processed by the above code
				//This can be done since there should be only one objective left in the list since the others have been deleted
				else
				{
					currentObjectives[i]->choice = true;
				}

			}
		}
	}
}
void Mission::drawMission(sf::RenderWindow *window, float dt)
{
	timeDifference = dt;

	if(prevRes != (sf::Vector2f)window->getSize())
	{
		sf::Vector2f temp((sf::Vector2f)window->getSize());
		offsetRes = sf::Vector2f(temp.x/800.0f, temp.y/600.0f); 
		prevRes = temp;
	}

	//update text
	//reset the position of the text upon window resize
	currentTextPos = sf::Vector2f(300.0f * offsetRes.x, 100.0f * offsetRes.y);
	text.setPosition(currentTextPos);

	if(timeDifference < 1.0f)
	{
		time += timeDifference;

		if(time > 1.0f)
		{
			time = 0.0f;
			//makes sure that the text doesn't lerp forever
			if(waitCounter <= 2)
			{
				//if text is waiting, i.e. not moving
				if(wait)
				{
					wait = false;
					waitCounter++;
				}
				else
				{
					wait = true;
					waitCounter++;
					if(waitCounter > 2)
					{
						textDone = true;
					}
				}
			}
			else
			{
				sf::Color color(255, 255, 255, 0);
				text.setColor(color);
			}
		}
		//if text is not waiting, i.e. its postion is being LERP
		if(!wait)
		{
			//if it is going from 0 to 1 in terms of transparency
			if(waitCounter == 0)
			{
				sf::Color color(255, 255, 255, time * 255);
				text.setColor(color);
			}
			//if it is going from 1 to 0 in terms of transparency
			else
			{
				sf::Color color(255, 255, 255, (1 - time) * 255);
				text.setColor(color);
			}
		}
	}

	////draw the required text
	if(!textDone)
	{
		window->pushGLStates();
		window->draw(text);
		window->popGLStates();
	}
	else
	{
		for(unsigned int i = 0; i < currentObjectives.size(); i++)
		{
			//if(currentObjectives[i]->renderObjective)
			//{
			currentObjectives[i]->drawObjective(window, dt, true, i);		//draws all of the current objectives to the HUD
			//}
		}
	}
}

void Mission::drawIcons(cbmini::cbfw::GLSLProgram *ShaderProgram, int level, int subLevel, bool outside)
{
	for(unsigned int i = 0; i < currentObjectives.size(); i++)
	{
		if(currentObjectives[i]->OutSide == outside && currentObjectives[i]->Level == level && currentObjectives[i]->SubLevel == subLevel)
		{
			currentObjectives[i]->drawIcons(ShaderProgram);		//draws all of the current objectives icons to the HUD
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//GAME MISSIONS

GameMissions::GameMissions()
{
	active = NULL;
}

GameMissions::~GameMissions()
{
}



void GameMissions::updateGameMissions(playerStats *player, int level, int subLevel, bool outside, float dt)
{
	
	if(active != NULL)
	{
		//if the active mission has been complete
		if(active->completed)
		{
			//puts the current mission in the complete list
			completed.push_back(active);

			//puts all of the current mission's children in the not found list 
			for(unsigned int i = 0; i < active->children.size(); i++)
			{
				if(active->children[i]->startArea == NULL)
				{
					notActive.push_back(active->children[i]);
					all.push_back(active->children[i]); 
				}
				else
				{
					notFound.push_back(active->children[i]);
				}
			}

			//take completed mission out of all
			for(vector<Mission*>::iterator i = all.begin(); i != all.end();)
			{
				if(active == (*i))
				{
					i = all.erase(i);
				}
				else
				{
					i++;
				}
			}

			//takes all of the current mission's children out of the cannotDo list
			if(!cannotDo.empty())
			{
				unsigned int k = 0; 
				for(unsigned int j = 0; j < notFound.size(), k < all.size(); j++, k++)
				{
					for(vector<Mission*>::iterator i = cannotDo.begin(); i != cannotDo.end();)
					{
						if((*i) == notFound[j] || (*i) == all[k])
						{
							i = cannotDo.erase(i);
						}
						else
						{
							i++;
						}
					}
				}
			}

			active = NULL;
		}
		else
		{
			//active->updateMission(player, level, subLevel, outside, dt);
			if(active->dialogue != NULL)
			{
				if(active->dialogue->dialogueDone)
				{
					player->dialogue = false;
					player ->playerMove = true;
					active->updateMission(player, level, subLevel, outside,  dt);
				}
				else
				{
					active->dialogue->update( dt);
					player->playerMove = false;	
					player->dialogue = true;
				}
			}
			else
			{
				active->updateMission(player, level, subLevel, outside, dt);
			}
		}
		
	}

	//checks to see if the player discovers a new mission 
	for(vector<Mission*>::iterator i = notFound.begin(); i != notFound.end();)
	{
		//only check the collision area for the starting area of the mission if the player is currently in the right part of the map
		if((*i)->OutSide == outside && (*i)->Level == level && (*i)->SubLevel == subLevel)
		{
			//if the player is within the starting area of the mission
			if(player->cObject.collisionTest((*i)->startArea))
			{
				if(active != NULL)
				{
					notActive.push_back(active);
					active = NULL;
				}
				//sets the newly discoverd mission to the player's active mission
				active = (*i);
				all.push_back((*i));
				i = notFound.erase(i);
			}
			else
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}
}

void GameMissions::drawGameMissions(sf::RenderWindow *window, float dt)
{
	//draws the active mission
	if(active != NULL)
	{
		if(active->dialogue != NULL)
		{
			if(!active->dialogue->dialogueDone)
			{
				active->dialogue->draw(window);
			}
			else
			{
				active->drawMission(window, dt);
			}
		}
		else
		{
			active->drawMission(window, dt);
		}
	}
}

void GameMissions::drawMissionObjects(int level, int subLevel, bool outside)
{
	//determines if the the current processed object should be drawn or not
	for(unsigned int i = 0; i < allObjects.size(); i++)
	{
		if(allObjects[i]->render && level == allObjects[i]->Level && subLevel == allObjects[i]->SubLevel && outside == allObjects[i]->OutSide)
		{
			glPushMatrix();
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			glTranslatef(allObjects[i]->pos[0], allObjects[i]->pos[1], allObjects[i]->pos[2]);
			glRotatef(allObjects[i]->theta, 0.0f, 1.0f, 0.0f);
			glScalef(allObjects[i]->scale[0], allObjects[i]->scale[1], allObjects[i]->scale[2]);
			allObjects[i]->theTexture->drawTex(0);
			allObjects[i]->theModel->drawModel();
			glPopMatrix();
		}
	}
}

void GameMissions::drawIcons(cbmini::cbfw::GLSLProgram *ShaderProgram, int level, int subLevel, bool outside)
{
	if(active != NULL)
	{
		active->drawIcons(ShaderProgram, level, subLevel, outside);
	}
}