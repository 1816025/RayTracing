#pragma once
#include "Color.h"

enum class Pattern {
	none,//�͗l�Ȃ� 
	hstripe,//�Ȗ͗l(��) 
	vstripe,//�Ȗ͗l(�c) 
	checkered,//�s���͗l(�`�F�b�J�[�t���b�O) 
	textured//�e�N�X�`���}�b�s���O 
};

class Material
{
public:
	Material();
	Material(const Color& diff, const Color& spec, const Color& amb, float inSpecularity, float inReflectance, Pattern pp = Pattern::none);
	~Material();

	Color diffuse;		//�g�U���ː���(cos�ŕ\��������Ԃ��F)
	Color specular;		//���ʔ��ː���(�X�y�L�����Ō��肳���\�ʍގ����Ԃ��F)
	Color ambient;		//����(�Q�^)
	float specularity;	//�X�y�L�����̋���(�搔)
	float reflectance;	//���˗�
	Pattern pattern;//�͗l��� 
};

