#include "sdf_core.h"

SDF::SDF() {
    _models = memnew(Array);
    _worlds = memnew(Array);
    _actors = memnew(Array);
    _lights = memnew(Array);
}

SDF::~SDF() {
    memdelete(_models);
    memdelete(_worlds);
    memdelete(_actors);
    memdelete(_lights);
}

Array SDF::get_models() {
    return *this->_models;
}
Array SDF::get_worlds() {
    return *this->_worlds;
}
Array SDF::get_actors() {
    return *this->_actors;
}
Array SDF::get_lights() {
    return *this->_lights;
}

bool SDF::load(String p_file) {
    return false;
}

void SDF::_bind_methods() {
}