#pragma once
#include "Math/vec3.h"
#include <vector>
#include "GamePartType.h"
#include "3D/Thumbnail.h"
namespace tzw
{
struct AttachmentInfo
{
	AttachmentInfo(vec3 p, vec3 n, vec3 u, std::string locale, float collisionBoxSize);
	vec3 pos;
	vec3 normal;
	vec3 up;
	std::string locale;
	float collisionSize;
};
struct VisualInfo
{
	enum class VisualInfoType
	{
		CubePrimitive,
		CylinderPrimitive,
		Mesh,
		RightPrismPrimitive,
	};
	VisualInfoType type;
	vec3 size;
	std::string filePath;
	std::string diffusePath;
	std::string roughnessPath;
	std::string metallicPath;
	std::string normalMapPath;
	bool isTransparent;
	bool isPreview;
	std::vector<std::string> extraFileList;
};

struct PhysicsInfo
{
	PhysicsInfo();
	enum class PhysicsInfoType
	{
		BoxShape,
		CylinderShape,
	};
	PhysicsInfoType type;
	vec3 size;
	float mass;
};

struct GameItem
{
	bool isSpecialFunctionItem();
	bool hasAttributePanel();
	GameItem();
	GameItem(const GameItem&other);
	std::string m_name;
	GamePartType m_type;
	std::string m_desc;
	std::string m_description;
	std::vector<AttachmentInfo> m_attachList;
	VisualInfo m_visualInfo;
	PhysicsInfo m_physicsInfo;
	vec3 m_tintColor;
	std::string m_surfaceName;
	int getTypeInInt();
	DeviceTexture * getThumbNailTextureId();
	ThumbNail *m_thumbNail;
	Texture * m_texture;
};
}
