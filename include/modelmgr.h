#ifndef _MODELMGR_H__
#define _MODELMGR_H__


struct model_info
{
	unsigned int _VAO;
	unsigned int _vert_count;
};


void init_model_info(model_info *model, unsigned int VAO, unsigned int nIndices);

class Modelmgr
{

	public:
		static Modelmgr *get_instance();
		struct model_info square_mesh;
		struct model_info square2_mesh;

	private:
		Modelmgr();
		static Modelmgr *instance_;
};


unsigned int create_square_vao();
#endif
