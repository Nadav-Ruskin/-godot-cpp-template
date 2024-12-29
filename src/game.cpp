#include "game.h"
#include "enumerate.h"
// #include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

std::atomic_uint32_t Food::current_id;

static std::vector<Food> foods = {
    {
        "circle",
        "res://asset/image/circle.png"
    },
    {
        "square",
        "res://asset/image/square.png"
    },
    {
        "triangle",
        "res://asset/image/triangle.png"
    },

}; 



// protected:
void Game::_bind_methods(){
        // ClassDB::bind_method(D_METHOD("add", "value"), &Game::add);
        // ClassDB::bind_method(D_METHOD("reset"), &Game::reset);
        // ClassDB::bind_method(D_METHOD("get_total"), &Game::get_total);
}

// public:

Game::Game(){
    // godot::UtilityFunctions::print("i'm being created n shit");

}


void Game::_ready(){
    // godot::UtilityFunctions::print("ello guv");
    for(std::size_t i = 0; i < foods.size(); ++i)
    {
        auto& food = foods[i];
        // foods[i].texture = ResourceLoader::get_singleton()->load(foods[i].path.c_str());
        food.texture = ResourceLoader::get_singleton()->load(foods[i].path.c_str());
        // godot::UtilityFunctions::print(foods[i].path.c_str());
        // godot::UtilityFunctions::print(foods[i].texture);


    }

	prompt = memnew(Sprite2D);
    add_child(prompt);
    prompt->set_texture(ResourceLoader::get_singleton()->load("res://asset/image/sign.png"));
    prompt->set_position(godot::Vector2(400, 100));

	card = memnew(Sprite2D);
    card->set_texture(foods[1].texture);
    prompt->add_child(card);
}

void Game::_process(double p_delta) {
    poo += p_delta;
    if (poo >= poo_target){
        poo = 0;
        set_new_target();
    }
}

void Game::set_new_target(){
    auto random_number = godot::UtilityFunctions::randi_range(0, foods.size() -1);
    // godot::UtilityFunctions::print(random_number);
    // godot::UtilityFunctions::print(foods[random_number].id);

    card->set_texture(foods[random_number].texture);
}

