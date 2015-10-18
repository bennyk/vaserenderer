#include "vertex_array_holder.h"

namespace VASEr
{
    namespace VASErin
    {	//VASEr internal namespace

class backend
{
public:
	static void vah_draw(vertex_array_holder& vah);
	static void polyline( const Vec2*, Color, double W, int length, const polyline_opt*); //constant color and weight
};

    }
}