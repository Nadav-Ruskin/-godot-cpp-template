#include "summator.h"
#include <godot_cpp/core/class_db.hpp>


// int count;

// protected:
    void Summator::_bind_methods(){
        ClassDB::bind_method(D_METHOD("add", "value"), &Summator::add);
        ClassDB::bind_method(D_METHOD("reset"), &Summator::reset);
        ClassDB::bind_method(D_METHOD("get_total"), &Summator::get_total);
        // ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "me_texture", PROPERTY_HINT_RESOURCE_TYPE, "Texture2D"), "set_me_texture", "get_me_texture");
}

// public:
void Summator::add(int p_value){
    count += p_value;
}

void Summator::reset(){
    count = 0;
}

int Summator::get_total() const{
    return count;
}


Summator::Summator(){
    count = 0;
    me_texture = ResourceLoader::get_singleton()->load("res://asset/image/circle.png");
}

// void Summator::set_me_texture(const Ref<Texture2D> &p_texture) {
// 	me_texture = p_texture;
// }

// Ref<Texture2D> Summator::get_me_texture() const {
// 	return me_texture;
// }
