#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/XKBlib.h>
#include <X11/keysym.h>

//Namespace
using namespace std;

//Global Variable Declarations
bool bFullscreen = false;
Display *gpDisplay = NULL;
XVisualInfo *gpXVisualInfo=NULL;
Colormap gColormap;
Window gWindow;
int giWindowWidth=800;
int giWindowHeight=600;



//Entry-Point Functions
int main(void)
{
    //Funcitons Declarations
    void CreateWindow(void);
    void ToggleFullscreen(void);
    void uninitialize();

    //Variable Declarations
    int winWidth=giWindowWidth;
    int winHeight=giWindowHeight;

    static XFontStruct *pXFontStruct = NULL;
    static GC gc; //Graphics Context
    static XGCValues gcValues;
    static XColor GreenColour;
    static char str[] = "Hellow World : Nandlal Lambole";

    int StringLenght;
    int StringWidth;
    int FontHeight;

    //code
    CreateWindow();

    //Message Loop
    XEvent event;
    KeySym keysym;

    while(1)
    {
        XNextEvent(gpDisplay, &event);
        switch(event.type)
        {
            case MapNotify:
            pXFontStruct = XLoadQueryFont(gpDisplay, "fixed");
              break;
            case KeyPress:
              keysym=XkbKeycodeToKeysym(gpDisplay, event.xkey.keycode, 0, 0);
            switch(keysym)
            {
                case XK_Escape:
                XUnloadFont(gpDisplay, pXFontStruct->fid);
                XFreeGC(gpDisplay, gc);
                      uninitialize();
                      exit(0);
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
              break;

            case Expose:
              gc =  XCreateGC(gpDisplay, gWindow, 0, &gcValues);
              XSetFont(gpDisplay, gc, pXFontStruct->fid);
              XAllocNamedColor(gpDisplay, gColormap, "green", &GreenColour, &GreenColour);
              XSetForeground(gpDisplay, gc ,GreenColour.pixel);

              StringLenght = strlen(str);
              StringWidth = XTextWidth(pXFontStruct, str, StringLenght);
              FontHeight = pXFontStruct->ascent + pXFontStruct->descent;
              XDrawString(gpDisplay, gWindow, gc, (winWidth/2 - StringWidth/2), (winHeight/2-FontHeight/2), str, StringLenght);
              break;

            case DestroyNotify:
              break;

            case 33:
            XUnloadFont(gpDisplay, pXFontStruct->fid);
            XFreeGC(gpDisplay, gc);
              uninitialize();
              exit(0);

            default:
            break;

        }
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

    //Code
    gpDisplay=XOpenDisplay(NULL);

    if (gpDisplay==NULL)
    {
        printf("ERROR :  Unable To Open X Display.\nExitting Now...\n");
        uninitialize();
        exit(1);
    }

    defaultScreen=XDefaultScreen(gpDisplay);

    defaultDepth=DefaultDepth(gpDisplay, defaultScreen);

    gpXVisualInfo=(XVisualInfo *)malloc(sizeof(XVisualInfo));
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

void uninitialize(void)
{
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
