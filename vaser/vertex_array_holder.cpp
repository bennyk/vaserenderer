
#include "vertex_array_holder.h"

#include "backend.h"

namespace VASEr
{
    namespace VASErin
    {	//VASEr internal namespace


        void vertex_array_holder::draw()
        {
            backend::vah_draw(*this);
        }

    }
}