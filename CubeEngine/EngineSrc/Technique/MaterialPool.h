#ifndef TZW_MATERIALPOOL_H
#define TZW_MATERIALPOOL_H
#include "EngineSrc/Engine/EngineDef.h"
#include "Material.h"
#include <map>
#include "Mesh/Mesh.h"

namespace tzw {

class MaterialPool
{
public:
    MaterialPool();
    Material * getMaterialByName(std::string name);
    void addMaterial(std::string materialName, Material * mat);
    Mesh * getMeshByName(std::string name);
    void addMesh(std::string materialName, Mesh * mat);
    std::string getModelMangleedName(std::string modelName);
	Material * getMatFromTemplate(std::string effectName);
private:
    std::map<std::string, Material *> m_materialMap;
	std::map<std::string, Mesh *> m_modelMap;
    TZW_SINGLETON_DECL(MaterialPool);
};

} // namespace tzw

#endif // TZW_MATERIALPOOL_H
