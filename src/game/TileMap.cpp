#include "../../include/game/TileMap.hpp"
#include "../../include/object/ObjectManager.hpp"
neo::game::TileMap::TileMap(): neo::object::GameObject("TileMap",' ')
{
    for(int y=0; y<15; y++)
    {
        auto tileRight = std::make_shared<TileObject>(0,y);
        auto tileLeft = std::make_shared<TileObject>(40 - 1,y);
        GetObjectManager().RegisterObject(std::format("Tile_right_{}",y),tileRight);
        GetObjectManager().RegisterObject(std::format("Tile_left_{}",y),tileLeft);
    }

    for(int x=0; x<40; x++)
    {
        auto tileTop = std::make_shared<TileObject>(x,0);
        auto tileBottom = std::make_shared<TileObject>(x,15-1);
        GetObjectManager().RegisterObject(std::format("Tile_top_{}",x),tileTop);
        GetObjectManager().RegisterObject(std::format("Tile_bottom_{}",x),tileBottom);
    }
}

neo::game::TileMap::~TileMap() {

}

void neo::game::TileMap::Init() {

}

void neo::game::TileMap::Start() {

}

void neo::game::TileMap::Update() {

}

void neo::game::TileMap::LastUpdate() {

}

