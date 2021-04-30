#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//OpenGL for XWindows
#include<GL/glx.h> //For OpenGL APIs
#include <GL/glu.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/XKBlib.h>
#include <X11/keysym.h>

//Namespace
using namespace std;

//Global Variable Declarations
Display *gpDisplay = NULL;
XVisualInfo *gpXVisualInfo=NULL;
Colormap gColormap;
GLXContext gGLXContext;
Window gWindow;
bool bFullscreen = false;
int giWindowWidth=800;
int giWindowHeight=600;

//Entry-Point Functions
int main(void)
{
    //Function Prototypes
    void Initialize(void);
    void Resize(int, int);
    void Draw(void);
    void uninitialize(void);

    //Funcitons Declarations
    void CreateWindow(void);
    void ToggleFullscreen(void);
    void uninitialize();

    //Variable Declarations
    int winWidth=giWindowWidth;
    int winHeight=giWindowHeight;
    bool bDone = false; //For GameLoop

    //code
    CreateWindow();
    Initialize();

    //Message Loop
    XEvent event;
    KeySym keysym;

    while(bDone == false)
    {
      while(XPending(gpDisplay))
      {

        XNextEvent(gpDisplay, &event);
        switch(event.type)
        {
            case MapNotify:
              break;
            case KeyPress:
              keysym=XkbKeycodeToKeysym(gpDisplay, event.xkey.keycode, 0, 0);
            switch(keysym)
            {
                case XK_Escape:
                    bDone = true;
                case XK_F:
                case XK_f:
                    if(bFullscreen==false)
                    {
                      ToggleFullscreen();
                      bFullscreen=true;
                    }
                    else
                    {
                      ToggleFullscreen();
                      bFullscreen=false;
                    }
                    break;
                default:
                    break;
            }
            break;
            case ButtonPress:
            switch(event.xbutton.button)
            {
                case 1:
                  break;
                case 2:
                  break;
                case 3:
                  break;
                default :
                  break;
            }
            break;
            case MotionNotify:
              break;

            case ConfigureNotify:
              winWidth=event.xconfigure.width;
              winHeight=event.xconfigure.height;
              Resize(winWidth, winHeight);
              break;

            case Expose:
              break;

            case DestroyNotify:
              break;

            case 33:
              bDone=true;

            default:
            break;

        }

      }
      Draw(); //GameLoop
    }
    uninitialize();
    return(0);
}

void CreateWindow(void)
{
    //Function Prototypes
    void uninitialize(void);

    //Variable Declarations
    XSetWindowAttributes winAttribs;
    int defaultScreen;
    int defaultDepth;
    int styleMask;

    static int iFrameBufferAttributes[] = {GLX_RGBA,
                                           GLX_RED_SIZE, 1,
                                           GLX_GREEN_SIZE, 1,
                                           GLX_BLUE_SIZE, 1,
                                           GLX_ALPHA_SIZE, 1,
                                           None}; //Here we can say None as a 0;

    //Code
    gpDisplay=XOpenDisplay(NULL);

    if (gpDisplay==NULL)
    {
        printf("ERROR :  Unable To Open X Display.\nExitting Now...\n");
        uninitialize();
        exit(1);
    }

    defaultScreen=XDefaultScreen(gpDisplay);
    gpXVisualInfo=glXChooseVisual(gpDisplay, defaultScreen, iFrameBufferAttributes);

    if(gpXVisualInfo==NULL)
    {
        printf("ERROR : Unable To Allocate Memory For Visual Info. \n Exitting Now...\n");
        uninitialize();
        exit(1);
    }

    XMatchVisualInfo(gpDisplay, defaultScreen, defaultDepth, TrueColor, gpXVisualInfo);
    if(gpXVisualInfo == NULL)
    {
        printf("ERROR : Unable To Get A Visual. \nExitting Now..\n");
        uninitialize();
        exit(1);
    }

    winAttribs.border_pixel=0;
    winAttribs.background_pixmap=0;
    winAttribs.colormap=XCreateColormap(gpDisplay,
                                        RootWindow(gpDisplay,gpXVisualInfo->screen),
                                        gpXVisualInfo->visual,
                                         AllocNone);
    gColormap=winAttribs.colormap;
    winAttribs.background_pixel=BlackPixel(gpDisplay, defaultScreen);

    winAttribs.event_mask=ExposureMask | VisibilityChangeMask | ButtonPressMask | KeyPressMask | PointerMotionMask | StructureNotifyMask;

    styleMask=CWBorderPixel | CWBackPixel | CWEventMask | CWColormap;

    gWindow=XCreateWindow(gpDisplay, RootWindow(gpDisplay, gpXVisualInfo->screen),
                          0,
                          0,
                          giWindowWidth,
                          giWindowHeight,
                          0,
                          gpXVisualInfo->depth,
                          InputOutput,
                          gpXVisualInfo->visual,
                          styleMask,
                          &winAttribs);

    if(!gWindow)
    {
        printf("ERROR : Failed To Create Main Window. \n Exitting Now...\n");
        uninitialize();
        exit(1);
    }

    XStoreName(gpDisplay, gWindow, "First Window : Nandlal Lambole");

    Atom windowManagerDelete=XInternAtom(gpDisplay, "WM_DELETE_WINDOW", True);
    XSetWMProtocols(gpDisplay, gWindow, &windowManagerDelete, 1);

    XMapWindow(gpDisplay, gWindow);
}

void ToggleFullscreen(void)
{
  //Variable Declarations
  Atom wm_state;
  Atom fullscreen;
  XEvent xev = {0};

  //Code
  wm_state = XInternAtom(gpDisplay, "_NET_WM_STATE", False);
  memset(&xev, 0, sizeof(xev));

  xev.type=ClientMessage;
  xev.xclient.window = gWindow;
  xev.xclient.message_type = wm_state;
  xev.xclient.format=32;
  xev.xclient.data.l[0]=bFullscreen ? 0 : 1;

  fullscreen = XInternAtom(gpDisplay, "_NET_WM_STATE_FULLSCREEN", False);
  xev.xclient.data.l[1] = fullscreen;

  XSendEvent(gpDisplay,
  RootWindow(gpDisplay, gpXVisualInfo->screen),
              False,
              StructureNotifyMask,
              &xev);
}

void Initialize(void)
{
  //Fuction Prototypes
  void Resize(int, int);
  gGLXContext = glXCreateContext(gpDisplay, gpXVisualInfo, NULL, GL_TRUE);
  glXMakeCurrent(gpDisplay, gWindow, gGLXContext);

  //Set Colour
  glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

  //WarmUp Resize Call
  Resize(CWWidth, CWHeight);
}

void Resize(int Width, int Height)
{
  if (Height == 0)
  {
    Height = 1;
  }
  glViewport(0, 0, (GLsizei)Width, (GLsizei)Height);
  glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (Width <= Height)
	{
		glOrtho(-100.0f,
				 100.0f,
				-100.0f*((GLfloat)Height / (GLfloat)Width),
			     100.0f*((GLfloat)Height / (GLfloat)Width),
				-100.0f,
			     100.0f);
	}
	else
	{
		glOrtho(-100.0f*((GLfloat)Width / (GLfloat)Height),
			     100.0f*((GLfloat)Width / (GLfloat)Height),
				-100.0f ,
				 100.0f ,
				-100.0f,
				 100.0f);
	}
}

void Draw(void)
{
  //Code
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  	glBegin(GL_TRIANGLES);

  	glColor3f(1.0f, 0.0f, 0.0f);
  	glVertex3f(0.0f, 50.0f, 0.0f);

  	glColor3f(0.0f, 1.0f, 0.0f);
  	glVertex3f(-50.0f, -50.0f, 0.0f);

  	glColor3f(0.0f, 0.0f, 1.0f);
  	glVertex3f(50.0f, -50.0f, 0.0f);

  	glEnd();
  glFlush();
}

void uninitialize(void)
{
  //Variable Declarations
  GLXContext CurrentGLXContext;

  CurrentGLXContext = glXGetCurrentContext();

  if(CurrentGLXContext == gGLXContext)
  {
    glXMakeCurrent(gpDisplay, 0, 0);
  }

  if(gGLXContext)
  {
      glXDestroyContext(gpDisplay, gGLXContext);
  }

  if(gWindow)
  {
    XDestroyWindow(gpDisplay, gWindow);
  }

  if(gColormap)
  {
    XFreeColormap(gpDisplay,gColormap);
  }

  if(gpXVisualInfo)
  {
    free(gpXVisualInfo);
    gpXVisualInfo = NULL;
  }

  if(gpDisplay)
  {
    XCloseDisplay(gpDisplay);
    gpDisplay = NULL;
  }
}



//Commands
//nandlal-lambole@Nandlal-Lambole:~$ g++ -o 03_BlueScreen 03_BlueScreen.cpp -lX11 -lGL
//nandlal-lambole@Nandlal-Lambole:~$ ./03_BlueScreen
