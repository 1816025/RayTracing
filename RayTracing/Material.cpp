#include "Material.h"



Material::Material() : diffuse(1, 1, 1), specular(0, 0, 0), ambient(0, 0, 0), specularity(0), reflectance(0)
{
}

Material::Material(const Color & diff, const Color & spec, const Color & amb, float inSpecularity, float inReflectance, Pattern p) :
	diffuse(diff), specular(spec), ambient(amb), specularity(inSpecularity), reflectance(inReflectance), pattern(p)
{
}

Material::~Material()
{
}
