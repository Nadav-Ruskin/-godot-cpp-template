#pragma once
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/texture2d.hpp>

using namespace godot;

class Summator: public Object {
    GDCLASS(Summator, Object);

    int count;


    protected:
        static void _bind_methods();
    
    public:
        void add(int p_value);
        void reset();
        int get_total() const;
        Ref<Texture2D> me_texture;

        Summator();
		// void set_me_texture(const Ref<Texture2D> &p_texture);
		// Ref<Texture2D> get_me_texture() const;
};