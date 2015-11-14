#include "vars.h"
#include "conf.h"
#include "text.h"
#include "player.h"
#include "textures.h"
#include "keyboard.h"
#include "mouse.h"
#include "shoot.h"
#include "scene.h"
#include "loading.h"
#include "items.h"
#include "quests.h"

GLvoid InitGL(GLsizei Width, GLsizei Height)	// We call this right after our OpenGL window is created.
{
	

	LoadIntefaceTex();
	glEnable(GL_TEXTURE_2D);                    // Enable texture mapping.

	glBlendFunc(GL_DST_COLOR, GL_ZERO);          // Set the blending function for translucency (note off at init time)
	glClearColor(0.3f, 0.3f, 0.4f, 0.0f);	// This Will Clear The Background Color To sky blue
	glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LEQUAL);                       // type of depth test to do.
	glEnable(GL_DEPTH_TEST);                    // enables depth testing.
	glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();				// Reset The Projection Matrix
	
	gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window
	
	glMatrixMode(GL_MODELVIEW);

	BuildFont();
}

GLvoid ReSizeGLScene(GLsizei Width, GLsizei Height)
{
    if (Height==0)				// Prevent A Divide By Zero If The Window Is Too Small
	Height=1;

    glViewport(0, 0, Width, Height);		// Reset The Current Viewport And Perspective Transformation

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,10000.0f);
    glMatrixMode(GL_MODELVIEW);
	printf("Resized to : %d x %d\n",Width,Height);
	resX = Width; resY =Height;
}

int main (int argc, char *argv[])
{

	getConf();

	
	/* Initialize GLUT state - glut will take any command line arguments that pertain to it or 
	X Windows - look at its documentation at http://reality.sgi.com/mjk/spec3/spec3.html */  
	glutInit(&argc, argv);  
	
	/* Select type of Display mode:   
	Double buffer 
	RGBA color
	Depth buffer 
	Alpha blending */  
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_ALPHA);
	
	/* get a 640 x 480 window */
	glutInitWindowSize(resX, resY);  
	
	/* the window starts at the upper left corner of the screen */
	glutInitWindowPosition(0, 0);  
	
	/* Open a window */  
	window = glutCreateWindow("Gedas' Quest");  
	
	/* Register the function to do all our OpenGL drawing. */
	glutDisplayFunc(&Draw);  
	
	/* Go fullscreen.  This is as soon as possible. */
	if(fs)glutFullScreen();
	
	/* Even if there are no events, redraw our gl scene. */
	glutIdleFunc(&Idle); 
	
	/* Register the function called when our window is resized. */
	glutReshapeFunc(&ReSizeGLScene);
	
	/* Register the function called when the keyboard is pressed. */
	glutKeyboardFunc(&keyPressed);
	
	/* Register the function called when special keys (arrows, page down, etc) are pressed. */
	glutSpecialFunc(&specialKeyPressed);
	//adding here the mouse processing callbacks
	glutMouseFunc(processMouse);
	glutMotionFunc(processMouseActiveMotion);
	glutPassiveMotionFunc(processMousePassiveMotion);
	glutEntryFunc(processMouseEntry);
	
	/* Initialize our window. */
	InitGL(resX, resY);
	
	/* Start Event Processing Engine */  
	glutMainLoop();  
	
	return 1;
} 
