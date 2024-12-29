#pragma once
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <string>
#include <atomic> //std::atomic_uint32_t
#include <iostream> // random
#include <random> // random


using namespace godot;


struct Food{
    private:
        static std::atomic_uint32_t current_id;
    public:
        uint32_t id;
        std::string name;
        std::string path;
        Ref<Texture2D> texture = nullptr;

    Food(std::string name, std::string path){
        this->id = this->current_id++;
        this->name = name;
        this->path = path;
    };

};



// class Prompt: public Sprite2D{

class Game: public Node2D {
    GDCLASS(Game, Node2D);


    protected:
        static void _bind_methods();
    
    public:
        Game();

		virtual void _ready() override;
		virtual void _process(double p_delta) override;

		void set_new_target();

		double poo{ 0 };
		double poo_target{ 0.5 };

		Sprite2D *prompt = nullptr;
		Sprite2D *card = nullptr;
};
