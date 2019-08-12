/* collada_core.cpp */

#include "collada_core.h"
#include "editor/import/editor_import_collada.h"
#include "scene/resources/material.h"
#include "scene/resources/surface_tool.h"
#include "core/map.h"

ColladaCore::ColladaCore() {
}

ColladaCore::~ColladaCore() {
}

Node* ColladaCore::parse(String file_path) {
    // Collada *col_body = memnew(Collada);
    EditorSceneImporterCollada *col_body = memnew(EditorSceneImporterCollada);
    Node *test = col_body->import_scene(file_path, NULL, NULL, NULL, NULL);

    String names = "";
    for(int i = 0; i < test->get_child_count(); ++i)
    {
        if(test->get_child(i)->get_class() == "MeshInstance")
        {
            return test->get_child(i);
        }
    }
    return NULL;
}
