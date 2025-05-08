# TimeIsMoney
* [Alpha Trailer](https://www.youtube.com/watch?v=C_mjkXX7HSU)
* [Concept Art and Alpha Screenshots](https://imgur.com/a/mBRoPgi)
* [Alpha One Sheet](https://imgur.com/a/Grtqsvg)

Time Is Money is a first-person card-playing game set in a world where everyone’s time to live is both known and used as currency. As an individual with very little time left, you seek to gain more time in a desperate bid at the casino. You’ll need to improve your strategy and your deck as you face off against tougher opponents on your way towards the top of the casino.

## Our Team
* Ronald Foster      (Engineer, Design)
* AJ Kennedy         (Design, Engineer, Artist)
* Dhillon Miclean    (Narrative, Design)
* Taibai Li          (Engineer)
* Aidan Dhawan       (Design, Engineer)
* Kobe Riddle        (Producer, Design)
* Tyler Kendall      (Engineer)
* Evan Xu            (Music, Engineer)
* Chris Ramirez      (Artist, Design)
* Brandon Ofenstein  (Music, Design)
* Xiangyi Zhao       (Artist)
* Erin Cervantes     (Artist, Narrative)

### Technical Documentation
•	CPP_Card.cpp
    o	Authored by: Ronald Foster
    o	This has logic for setting the texture and number of a Card Blueprint. It also has accessible vars for retrieving the suit and number of a card.
    
•	BP_Card
    o	Authored by: Ronald
    o	This has as static mesh with the suit and number of our cards. It has functionality for changing both the suit and number via CPP_Card method calls.
    
•	CPP_Card_Deck.cpp
    o	Authored by: Ronald Foster, Tyler Kendall, AJ Kennedy
    o	This has logic for storing the opponent and player deck. It is function for drawing cards. It has events to tell the UE5 Editor blueprints when cards were drawn. The NPC_OPP and Table_TimeIsMoney blueprints need to reference a blueprint descended from this class.
    
•	BP_Card_Deck
    o	Authored by: Ronald, Tyler
    o	This is an instantiation of CPP_Card_Deck and must be present in the scene and referenced by other actors for the game to function
    
•	CPP_NPC_Opp_TimeIsMoney.cpp
    o	Authored by: Tyler Kendall, Ronald Foster
    o	This has logic for how our opponent in the TimeIsMoney card game plays their cards. It stores their hand too.
    
•	BP_NPC_Opp_TimeIsMoney
    o	Authored by: Ronald, Tyler
    o	This is the object referenced to get what cards our opponent is playing by the BP_Table_TimeIsMoney
 
•	CPP_Table_TimeIsMoney.cpp
    o	Authored by: Ronald Foster, AJ Kennedy
    o	This has logic for our core gameloop of the card game. It keeps track of what cards were played. It has functions for determining the winner of a hand and game. It has functions for starting a new game. And it has events that tell UE5 Editor blueprints when games were started, when a         game ended, when a hand started, when player cards were played, and when opponent cards were played.
    
•	BP_Table_TimeIsMoney
    o	Authored by: Aidan, Ronald, AJ, Taibai, Chris
    o	This has logic for spawning cards, calling CPP_Table_TimeIsMoney core game-loop functions, moving cards around, deleting cards from the scene that were spawned via this BP, and it has events bound for each of the CPP_Table_TimeIsMoney events.

*All Pawns use InputActionMaps to get input from the player. Pawns are found inside /content/Blueprints/Pawns. Within /Pawns, you can find the ActionMaps and their InputActions.*

•	Pawn_TimeIsMoneyPlayer
    o	Authored by: Ronald
    o	This is the actor our player controls to play cards in the casino game
    
•	Pawn_ShopPlayer
    o	Authored by: Ronald, Aidan
    o	This is the actor our player controls to use our Shop
    
•	Pawn_firstpersonCharacter
    o	Authored by: Taibai, Ronald, AJ, Aidan
    o	This is the actor our player used to walk around the casino. It has functionality to interact with other pawns.
 
•	BP_Gamemode
    o	Authored by: Taibai, Ronald
    o	This is a mostly untouched default UE5 Gamemode blueprint we used to set our custom player controller and default pawn
    
•	BP_PlayerController
    o	Authored by: Ronald
    o	Has functions for possessing different Pawns
    
•	BP_ShopInteract
    o	Authored by: Aidan, AJ
    o	Interact interface for on-screen popup
    
•	/Content/UI/WBP_...UI.uasset
    o	Authored by: Ronald, AJ
    o	Old 2D UI we are in the middle of migrating to a 3D alternative implementation. These Widget Blueprints listen for important events from our TimeIsMoney table and card draws from our Card_Deck to update the UI. WBP_FinalUI is an important class to look at to understand how these all         work together. WBP_Card has functions for playing cards. WBP_WinResults listens to hand and game win events from TimeIsMoney table.
    
•	/Content/dialogue
    o	Authored by: Taibai
    o	Blueprints for our dialogue system.

**Essentials for the Project to Run in UE5 Editor**
* [Visual Studio Integration Tool](https://www.fab.com/listings/8a639215-7f85-4cc7-b155-fa2137326209)
* The game is made in UE5.4.4
* Visual Studio Game Development with C++
* Visual Studio 17.13.0 or later (I have 17.13.5 at time of writing)
* Git installed.

## Playtests Notes
* [Alpha Playtest](https://acrobat.adobe.com/id/urn:aaid:sc:VA6C2:de5def23-2d8c-4979-8df3-32a441e6107f)
* [Utah Games Spring 2025 Playtest](https://imgur.com/a/HurWWgQ)
