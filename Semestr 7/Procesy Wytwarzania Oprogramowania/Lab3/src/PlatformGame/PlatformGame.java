package PlatformGame;

import java.awt.*;
import java.util.ArrayList;

public class PlatformGame{
    ArrayList<Level> levels;
    Level currentLevel;
    int currentLevelIndex;
    GameMap gameMap;
    ArrayList<Platform> platforms;
    Player player;
    ArrayList<Opponent> opponents;
    ArrayList<Treasure> treasures;
    double score;
    String playerName;
    Image avatar;
    PlatformGame(String playerName, int platformsQuantity, int opponentsQuantity, int treasuresQuantity){
        levels.add(new Level("Level for beginners"));
        levels.add(new Level("Advanced level"));
        levels.add(new Level("Expert level"));
        currentLevelIndex = 0;
        currentLevel = levels.get(currentLevelIndex);
        gameMap = new EuropeMap("Green background");
        player = new Player("US Army");
        for(int i=0; i<platformsQuantity; i++){
            platforms.add(new GroundPlatform(Color.BLACK));
        }
        for(int i=0; i<opponentsQuantity; i++){
            opponents.add(new Alien("Alien"));
        }
        for(int i=0; i<treasuresQuantity; i++){
            treasures.add(new Diamond(100));
        }
        score = 0;
        this.playerName = playerName;
        avatar = new Avatar(this.playerName);
    }
    public void changeLevel(){
        currentLevelIndex += 1;
        currentLevel = levels.get(currentLevelIndex);
    }
    public void movePlayer(int direction){
        switch(direction){
            case 1:
                player.up();
                break;
            case 2:
                player.right();
                break;
            case 3:
                player.down();
                break;
            case 4:
                player.left();
                break;
            default:
                player.stop();
        }
    }
}