#include<SDL/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>

//compiling flags -lGL -lGLU -lSDL
// anushka uditha

//static vars
float angle = 0.0;

//draw table
void drawTable(int size)
{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);
		//front face
		glNormal3f(0.0,0.0,1.0);//align and distent and direction normal verctor for lighit calculation
		glVertex3f(size/2,size/2,size/2);
		glVertex3f(-size/2,size/2,size/2);
		glVertex3f(-size/2,-size/2,size/2);
		glVertex3f(size/2,-size/2,size/2);

		//back face
		glNormal3f(0.0,0.0,-1.0);
		glVertex3f(size/2,size/2,-size/2);
		glVertex3f(-size/2,size/2,-size/2);
		glVertex3f(-size/2,-size/2,-size/2);
		glVertex3f(size/2,-size/2,-size/2);

		//left face
		glNormal3f(-1.0,0.0,0.0);
		glVertex3f(-size/2,size/2,-size/2);
		glVertex3f(-size/2,size/2,size/2);
		glVertex3f(-size/2,-size/2,size/2);
		glVertex3f(-size/2,-size/2,-size/2);

		//right face
		glNormal3f(1.0,0.0,0.0);
		glVertex3f(size/2,size/2,-size/2);
		glVertex3f(size/2,size/2,size/2);
		glVertex3f(size/2,-size/2,size/2);
		glVertex3f(size/2,-size/2,-size/2);

		//top face
		glNormal3f(0.0,1.0,0.0);
		glVertex3f(-size/2,size/2,-size/2);
		glVertex3f(-size/2,size/2,size/2);
		glVertex3f(size/2,size/2,size/2);
		glVertex3f(size/2,size/2,-size/2);

		//bottom face
		glNormal3f(0.0,-1.0,0.0);
		glVertex3f(-size/2,-size/2,-size/2);
		glVertex3f(-size/2,-size/2,size/2);
		glVertex3f(size/2,-size/2,size/2);
		glVertex3f(size/2,-size/2,-size/2);

	glEnd();
}

//draw cube
void drawRoom(float size)
{
	float difamb[] = {0.51,0.74,1.0,0.5};//color of the material
	glBegin(GL_QUADS);
		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,difamb);//size of premitive
		//front face
		glNormal3f(0.0,0.0,1.0);//align and distent and direction normal verctor for lighit calculation
		glVertex3f(size/2,size/2,size/2);
		glVertex3f(-size/2,size/2,size/2);
		glVertex3f(-size/2,-size/2,size/2);
		glVertex3f(size/2,-size/2,size/2);

		//back face
		glNormal3f(0.0,0.0,-1.0);
		glVertex3f(size/2,size/2,-size/2);
		glVertex3f(-size/2,size/2,-size/2);
		glVertex3f(-size/2,-size/2,-size/2);
		glVertex3f(size/2,-size/2,-size/2);

		//left face
		glNormal3f(-1.0,0.0,0.0);
		glVertex3f(-size/2,size/2,-size/2);
		glVertex3f(-size/2,size/2,size/2);
		glVertex3f(-size/2,-size/2,size/2);
		glVertex3f(-size/2,-size/2,-size/2);

		//right face
		glNormal3f(1.0,0.0,0.0);
		glVertex3f(size/2,size/2,-size/2);
		glVertex3f(size/2,size/2,size/2);
		glVertex3f(size/2,-size/2,size/2);
		glVertex3f(size/2,-size/2,-size/2);

		//top face
		glNormal3f(0.0,1.0,0.0);
		glVertex3f(-size/2,size/2,-size/2);
		glVertex3f(-size/2,size/2,size/2);
		glVertex3f(size/2,size/2,size/2);
		glVertex3f(size/2,size/2,-size/2);

		//bottom face
		glNormal3f(0.0,-1.0,0.0);
		glVertex3f(-size/2,-size/2,-size/2);
		glVertex3f(-size/2,-size/2,size/2);
		glVertex3f(size/2,-size/2,size/2);
		glVertex3f(size/2,-size/2,-size/2);

	glEnd();

}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	float pos[] = {-2.0,2.0,-3.0,1.0};//positon of the light x,y,z i don't know 1.0
	glLightfv(GL_LIGHT0,GL_POSITION,pos);//modify GL llight 0 position




	glTranslatef(0.0,0.0,-250.0);
	glEnable(GL_COLOR_MATERIAL);
	drawTable(50);
	glDisable(GL_COLOR_MATERIAL);

	//drawing the cube function with lighting effects
	//glRotatef(angle,0.0,1.0,0.0);
	//drawRoom(100);

}


//initialize the viewport of open gl
void init()
{
	glClearColor(0.55,0.55,0.55,1.0); // background color 4th alpha

	glMatrixMode(GL_PROJECTION);  //what part should be render
	glLoadIdentity(); // not transformation work properly without this line
	gluPerspective(45,640.0/480.0,1.0,500.0); //eye (angle,(width and height)ration,how far close pane,far cliper pane)

	glMatrixMode(GL_MODELVIEW); // position of object
	glShadeModel(GL_SMOOTH);// color shading mode GL_FLAT (not required defualt smooth)
	glEnable(GL_DEPTH_TEST);//every single pixel have buffer when want 3D objects

	glEnable(GL_LIGHTING);//enable lighting buffer in gl
	glEnable(GL_LIGHT0);//enable one light thats why 0 can get up to 7

	float dif[] = {1.0,1.0,1.0,1.0};//rgb and alpha refleft the light in same amount ambiant is emit every where
	glLightfv(GL_LIGHT0,GL_DIFFUSE,dif);//modify gl light change diffuse
	float amb[] = {0.2,0.2,0.2,1.0};//color that omit every where
	glLightfv(GL_LIGHT0,GL_AMBIENT,amb);//set omit color

	glEnable(GL_BLEND);//enable alpha blend in gl this will enable transparency
	//(A*S)+(B*D) this the function in below function do blending transperant
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	//glEnable(GL_COLOR_MATERIAL); //this will need if we want to color up individual colors of materials

}

//main function which initialze the view port and window
int main(int argc,char** argv){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface* screen;
	screen = SDL_SetVideoMode(640,480,32,SDL_SWSURFACE|SDL_OPENGL);
	bool running = true;
	const int FPS = 30;
	Uint32 start;
	SDL_Event event;
	init();
	while(running)
	{
		start = SDL_GetTicks();
		while(SDL_PollEvent(&event)){
			switch(event.type)
			{
				case SDL_QUIT:
					running = false;
					break;
			}
		}
		//logic & rander
		display();
		SDL_GL_SwapBuffers();
		angle += 0.25;
		if(angle > 360)
			angle -= 360;
		if(1000/FPS > SDL_GetTicks() - start)
			SDL_Delay(1000/FPS - (SDL_GetTicks()-start));

	}
	SDL_Quit();
	return 0;
}

