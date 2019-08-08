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

String ColladaCore::parse(String file_path) {
    // Collada *col_body = memnew(Collada);
    EditorSceneImporterCollada *col_body = memnew(EditorSceneImporterCollada);
    Node *test = col_body->import_scene(file_path, NULL, NULL, NULL, NULL);

    String names = "";
    for(int i = 0; i < test->get_child_count(); ++i)
    {
        names += test->get_child(i)->get_name();
        names += test->get_child(i)->get_class();
        names += "\n\n";
    }

    // Map<String, Collada::MeshData> m_map = col_body->state.mesh_data_map;

    // Map<String, Collada::MeshData>::Element *el = m_map.front();
    // String names = "START\n";

    // SurfaceTool *tool = new SurfaceTool();
    
    // while(el != NULL)
    // {
    //     names += el->key() + " ";
    //     names += el->value().name;
    //     Vector<Collada::MeshData::Primitives> verts = el->value().primitives;
    //     // Map<String, Collada::MeshData::Primitives>::Element *vel = verts.front();
    //     names += verts.size();
    //     // while (vel != NULL)
    //     // {
    //     //     names += "\n\t" + vel->key();

    //     //     Vector<float> indices = vel->value().indices;

    //     //     names += "\n\t" + indices.size();
            

    //     //     Map<String, String>::Element *sel = vel->value().sources.front();
    //     //     while (sel != NULL)
    //     //     {
    //     //         names += "\n\t\t" + sel->key();
    //     //         names += "\n\t\t" + sel->value();

    //     //         sel = sel->next();
    //     //     }

    //     //     vel = vel->next();
    //     // }
    //     names += "\n";


    //     el = el->next();
    // }
    return names;
}
