---------------------------------------------------------------------------------------------------------------------------------------------
For basic homework points:

1. All elements, including ships, packs, bombers, and player islands, are in the project.
2. All events, including keyboard-input events and element collision events, are handled properly.

-----------------------------------------------------------------------------------------------------------------------------------------------
For additional homework points:

1. I have added color to ships. The player's ship is green, and other objects are red.
2. There are two modes to initialize the map. One is to randomly add obstacles, and the other is to import from a map file.
   Please note that both the map file and the source file that can generate the map file are in the /map directory.
   The function for randomly adding obstacles is disabled. The default mode is importing the map from an external file.
3. The player can level up when coins reach 1000. When the player advances to the next level, the probability of enemy ship appearance will increase.

------------------------------------------------------------------------------------------------------------------------------------------------
For the user:

1. Initially, there is only the player's ship on the map, and islands are pre-initialized in the map file.
2. The user can use keyboard input events to control the player's ship.
    Press 'A' to shoot a bullet to the left.
    Press 'D' to shoot a bullet to the right.
    Press 'Spacebar' to shoot a bullet in the direction the player's ship is facing.
    Press 'T' to launch a torpedo.
    Press 'M' to launch a missile.
    Use the 'arrow' keys to move the ship.
    If the player is ship is hit, its health will decrease.
    The player ship can pick up weapon packs or medical packs if they are nearby.
    Each time an enemy ship is destroyed, the player's coins will increase.
