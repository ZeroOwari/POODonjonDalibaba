classDiagram
    
    class Salles{
    - int longueur
    -int largeur
    + salles()
    +void set_longueur()
    +void set_largeur()
    +int get_longueur()
    +int get_largeur()
    +void afficherSalle()
    }

  class Player{
    +enum Dir
    +bool heroIdle
    + Player()
    +void initAnimation()
    +void setDirection
    +int getDirection()
  }

  class MonstresGraphique{
    +Monstres()
    +void initAnimation()
  }

  class Map{
    -sf::VertexArray m_vertices
    -sf::Texture m_tileset
    -virtual void draw
    +const int COL_COUNT
    +const int ROW_COUNT
    +bool load()
    +bool loadFromFile()
    +std::vector<std::string> explode()
  }

  class Game{
    -bool inventtaireOuvert
    -bool PrintInventaire
    #RenderWindow* window
    #VideoMode videoMode
    #Player* player
    #Monstres* slime
    #Map map
    #View view
    #const int WIN_WIDTH
    #const int WIN_HEIGHT
    #int levelLoaded
    #int levelColision
    #sf::RectangleShape rects[]
    #bool canShowCollisionDebug
    +Game()
    +initWindow()
    +initPlayer()
    +initSlime()
    +initMap()
    +initMapColision()
    +view.setSize()
    +~Game()
    +void run()
    +void initMap()
    +void initMapColision()
    +void initWindow()
    +void initPlayer()
    +void initSlime()
    +void updateInput()
    +void update()
    +void rendrColisison()
    +void checkCollision()
    +sf::Vector2f playerPos = player->getPosition()
    +void render()
  }

  class Entity{
     #sf::Texture texture;
 #sf::Sprite sprite;
 #sf::Clock animClock;
 #const int SPRITE_SIZE ;
 #float walkSpeed;

 #sf::Vector2i anim = sf::Vector2i();
    +virtual void initTexture()
    +virtual void initSprite()
    +virtual void initAnimation()
    +   sf::Sprite& getShape()
    +int getSpriteSize()
    +void move()
    +void render()
    +sf::Vector2f getPosition()
    +void setPosition()

  }

  class Combat{
    -Heros& heros
    -Monstre& monstre
    -bool determinerInitiative()
    -bool attaque()
    -bool parade()
    -int calculerDegats()
    +Combat()
    +void demarrerCombat()
    +void Combat::demarrerCombat()
    +bool Combat::determinerInitiative()
    +bool Combat::attaque()
    +bool Combat::parade()
    +bool Combat::calculerDegats()
  }

  class Asset{
    +void Inventaire()
    +const float inventoryWidth
    +const float inventoryHeight
    +sf::Vector2f inventoryPosition()
    +sf::Font Police
    +sf::Sprite sprite_casque
    +sprite_casque.setTexture()
  }

  class calcul_new_poids{
    +void origine()
    +void newPoids()
  }

  class item{
    -int poids
    +item()
    +static int calculer_poids_total()

  }

  class Consommable{
    +Consommable():item()
  }

  class Equipement{
    +Equipement(): item()
  }

  class Armement{
    +Armement() :item()
  }

  class Personnages{
    #int pv
    #int niveau
    #std::unordered_map<std::string, int> competences
    + Personnage()
    +virtual void set_pv()
    +virtual void set_force()
    +virtual void set_intelligence()
    +virtual void set_adresse()
    +virtual void set_charisme()
    +virtual void set_courage()
    +virtual void set_niveau()
    +virtual int get_pv()
    +virtual std::string get_origine()
    +virtual int get_force()
    +virtual int get_intelligence()
    +virtual int get_adresse()
    +virtual int get_charisme()
    +virtual get_courage()
    +virtual get_niveau()
  }

  class CanardExplosif{
    +CanardExplosif()
    +string get_origine()
    +void afficher()
  }
    class GobelinSarcastique{
    +GobelinSarcastique()
    +string get_origine()
    +void afficher()
  }
    class Monstre{
    +CanardExplosif()
    +void subitDegats()
    +bool estVivant()
  }
    class TrollRhetoricien{
    +TrollRhetoricien()
    +string get_origine()
    +void afficher()
  }

  class Heros{
    # double poidsmax
    #double poidsactuel
    #int points
    #std::vector<std::string> inventaire
	#std::vector<std::string> spells
    +Heros()
    +virtual void set_poidsmax()
    +virtual void set_poidsactuel()
    +virtual voidd set_niveau()
    virtual void set_points()
    +virtual double get_poidsmax()
    +virtual double get_poidsactuel()
    +virtual int get_points()
    virtual void UpNiveau()
    virtual void ajoutPoint()
    virtual void AddSpells()
    virtual void afficherInventaire()
    virtual void afficherSpells()
    virtual std::strinf get_origine()
    virtual int JetCOU()
    virtual int JetINT()
    virtual int JetCHA()
    virtual int JetFO()
    virtual void TestdeJet()
    virtual void afficher()

  }

  class Humain{
    +Humain()
    +std::string get_origine()

  }

    class Elfe{
    +Elfe()
    +std::string get_origine()
    
  }

    class Barbare{
    +Barbare()
    +std::string get_origine()
    
  }

    class Nain{
    +Nain()
    +std::string get_origine()
    
  }

    class Metier

Player <|--Entity
Monstres <|--Entity
Consommable<|--item
Equipement<|--item
Armement<|--item
CanardExplosif<|--Monstre
TrollRhetoricien<|--Monstre
GobelinSarcastique<|--Monstre
Monstre<|--Personnages
Nain<|--Heros
Elfe<|--Heros
Barbare<|--Heros
Humain<|--Heros
Heros <|-- Personnages
Metier<|--Heros
