/*config.h is generated by fltk in your system
 * this file is used with fltk 1.3 with gl enabled.
 * compile by: fltk-config --use-gl --compile test1_drag.cpp
 * or something like: g++ -lX11 -lGL 'test1_drag.cpp' -o 'test1_drag'
*/
#include <math.h>
#include <stdio.h>

#include "config.h" //config.h must always be placed before any Fl header
#include <FL/gl.h>
#include <FL/Fl_Box.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Radio_Light_Button.H>

struct Vec2 { double x,y;};
struct Color { float r,g,b,a;};
#include "../include/vase_renderer_draft1_2.cpp"

void test_draw();
#include "test1_base.cpp"

const int buf_size=20;

Vec2 AP[buf_size];
Color AC[buf_size];
int size_of_AP = 0;

Fl_Window* main_wnd;
Gl_Window* gl_wnd;
Fl_Box* text;
Fl_Button *nk1, *nk2, *nk3;

/*static void vah_dual_knife_cut( vertex_array_holder& in, vertex_array_holder& out,
		const Point& kn0, const Point& kn1, const Point& kn2)
{
	_st_knife_cut ST1, ST2a, ST2b;
	for ( int i=0; i<in.get_count(); i+=3)
	{
		//first cut
		ST1.T1[0] = in.get(i);
		ST1.T1[1] = in.get(i+1);
		ST1.T1[2] = in.get(i+2);
			ST1.C1[0] = in.get_color(i);
			ST1.C1[1] = in.get_color(i+1);
			ST1.C1[2] = in.get_color(i+2);
		
		int result1 = triangle_knife_cut( kn0,kn1,kn2,0,0, ST1);
		
		//second cut
		ST2a.T1[0] = ST1.T2[0];
		ST2a.T1[1] = ST1.T2[1];
		ST2a.T1[2] = ST1.T2[2];
			ST2a.C1[0] = ST1.C2[0];
			ST2a.C1[1] = ST1.C2[1];
			ST2a.C1[2] = ST1.C2[2];
		int result2a = triangle_knife_cut( kn2,kn1,kn0,0,0, ST2a);
		
		if ( ST1.T2c > 3)
		{
			ST2b.T1[0] = ST1.T2[1];
			ST2b.T1[1] = ST1.T2[2];
			ST2b.T1[2] = ST1.T2[3];
				ST2b.C1[0] = ST1.C2[1];
				ST2b.C1[1] = ST1.C2[2];
				ST2b.C1[2] = ST1.C2[3];
			int result2b = triangle_knife_cut( kn2,kn1,kn0,0,0, ST2b);
		}
		
		//push results
		if ( ST1.T1c > 0) {
			out.push( ST1.T1[0], ST1.C1[0]);
			out.push( ST1.T1[1], ST1.C1[1]);
			out.push( ST1.T1[2], ST1.C1[2]);
			if ( ST1.T1c > 3) {
				out.push( ST1.T1[1], ST1.C1[1]);
				out.push( ST1.T1[2], ST1.C1[2]);
				out.push( ST1.T1[3], ST1.C1[3]);
			}
		}
		
		if ( ST2a.T1c > 0) {
			out.push( ST2a.T1[0], ST2a.C1[0]);
			out.push( ST2a.T1[1], ST2a.C1[1]);
			out.push( ST2a.T1[2], ST2a.C1[2]);
			if ( ST2a.T1c > 3) {
				out.push( ST2a.T1[1], ST2a.C1[1]);
				out.push( ST2a.T1[2], ST2a.C1[2]);
				out.push( ST2a.T1[3], ST2a.C1[3]);
			}
		}
		
		if ( ST1.T2c > 3) {
			if ( ST2b.T1c > 0) {
				out.push( ST2b.T1[0], ST2b.C1[0]);
				out.push( ST2b.T1[1], ST2b.C1[1]);
				out.push( ST2b.T1[2], ST2b.C1[2]);
				if ( ST2b.T1c > 3) {
					out.push( ST2b.T1[1], ST2b.C1[1]);
					out.push( ST2b.T1[2], ST2b.C1[2]);
					out.push( ST2b.T1[3], ST2b.C1[3]);
				}
			}
		}
		
		//~ //triangle strip
		//~ for ( int j=0; j<ST2a.T1c; j++)
			//~ out.push( ST2a.T1[j], ST2a.C1[j])
	}
}*/
//
//application
void line_update()
{
	Color cc[3];
	{ Color col={1 , 0, 0, 1}; cc[0]=col;}
	{ Color col={.8,.8, 0, 1}; cc[1]=col;}
	{ Color col={ 0, 0, 1, 1}; cc[2]=col;}
	Color grey={.5,.5,.5, 1};
	
	for ( int i=0; i<size_of_AP; i++)
	{
		if ( i<3) {
			AC[i] = cc[i%3];
			AC[i].a = 0.5f;
		} else {
			AC[i] = grey;
			AC[i].a = 0.2f;
		}
	}
}
void line_init( int)
{
	AP[0].x=300; AP[0].y=30;
	AP[1].x=120; AP[1].y=250;
	AP[2].x=480; AP[2].y=250;
	
	AP[3].x=240; AP[3].y=130;
	AP[4].x=360; AP[4].y=130;
	AP[5].x=300; AP[5].y=220;
	size_of_AP = 6;
	
	line_update();
	gl_wnd->set_drag_target( AP, size_of_AP); 
}
void enable_glstates()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	
	glDisableClientState(GL_EDGE_FLAG_ARRAY);
	glDisableClientState(GL_FOG_COORD_ARRAY);
	glDisableClientState(GL_INDEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_SECONDARY_COLOR_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}
void disable_glstates()
{
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}
void drag_cb(Fl_Widget* W, void*)
{
	gl_wnd->redraw();
}
void nk_cb(Fl_Widget* W, void*)
{
	gl_wnd->redraw();
}
int N_knife()
{
	if ( nk1->value())
		return 1;
	else if ( nk2->value())
		return 2;
	else if ( nk3->value())
		return 3;
}
void make_form()
{
	text = new Fl_Box(FL_FRAME_BOX,0,300,600,80,
	"This is the test of general knife cut. "
	"The grey triangle define the knifes, which cut the colored "
	"triangle into parts. By using the 3 sides of a triangle as knives, "
	"you can obtain the result of triangle A minus triangle B. "
	"Note that the knife cut method takes care also the interpolation "
	"of colors. \n"
	"Drag the points of the triangles to play."
	);
	text->align( FL_ALIGN_TOP | FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_WRAP);
	
	{	Fl_Group* o = new Fl_Group(0,380,600,20);
		new Fl_Box(0,380,30,20,"N =");
		nk1 = new Fl_Radio_Light_Button(30,380,80,20,"1 knife");
		nk2 = new Fl_Radio_Light_Button(110,380,30,20,"2");
		nk3 = new Fl_Radio_Light_Button(140,380,30,20,"3");
		
		nk1->callback(nk_cb);
		nk2->callback(nk_cb);
		nk3->callback(nk_cb);
		
		nk1->value(1);
		o->end();
	}
}
void draw_triangles_outline( vertex_array_holder& tris)
{
	for ( int i=0, count=tris.get_count(); i<count; i++)
	{
		Point P1 = tris.get(i); i++;
		Point P2 = tris.get(i); i++;
		Point P3 = tris.get(i);
		
		glBegin(GL_LINE_STRIP);
			glColor3f(1,0,0);
			glVertex2f( P1.x,P1.y);
			glVertex2f( P2.x,P2.y);
			glVertex2f( P3.x,P3.y);
			glVertex2f( P1.x,P1.y);
		glEnd();
	}
}
void test_draw()
{
	enable_glstates();
	
	{	vertex_array_holder tri_in,tri_out;
		tri_in .set_gl_draw_mode(GL_TRIANGLES);
		tri_out.set_gl_draw_mode(GL_TRIANGLES);
		
		for ( int i=0; i<3; i++)
		{
			tri_in.push( AP[i], AC[i]);
		}
		
		Point kn0[3]={AP[3],AP[4],AP[5]};
		Point kn1[3]={AP[4],AP[5],AP[3]};
		Point kn2[3]={AP[5],AP[3],AP[4]};
		
		vah_N_knife_cut( tri_in, tri_out, kn0,kn1,kn2, 0,0,N_knife());
		tri_out.draw();
		draw_triangles_outline( tri_out);
	}
	
	{	vertex_array_holder kn;
		kn.set_gl_draw_mode(GL_TRIANGLES);
		for ( int i=3; i<6; i++)
		{
			kn.push( AP[i],AC[i]);
		}
		kn.draw();
	}
	
	disable_glstates();
}

int main(int argc, char **argv)
{
	vaserend_actual_PPI = 111.94;
	//
	main_wnd = new Fl_Window( 600,400,"knife cut test (fltk-opengl)");
		make_form(); //initialize
		gl_wnd = new Gl_Window( 0,0,600,300);  gl_wnd->end(); //create gl window
		line_init(3);
	main_wnd->end();
	main_wnd->show();
	main_wnd->redraw();
	
	return Fl::run();
}