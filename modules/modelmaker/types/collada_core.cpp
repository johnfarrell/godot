/* collada_core.cpp */

#include "collada_core.h"
#include "editor/collada/collada.h"
#include "scene/resources/material.h"
#include "core/map.h"

ColladaCore::ColladaCore() {
}

ColladaCore::~ColladaCore() {
}

String ColladaCore::parse(String file_path) {
    Collada *col_body = memnew(Collada);
    col_body->load(file_path, Collada::ImportFlags::IMPORT_FLAG_SCENE);

    Map<String, Collada::MeshData> m_map = col_body->state.mesh_data_map;

    Map<String, Collada::MeshData>::Element *el = m_map.front();
    String names = "START\n";

    while(el != NULL)
    {
        names += el->key();
        names += el->value().name;
        names += "\n";

        el = el->next();
    }

    names += "END\n";
    return names;
}
