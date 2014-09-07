#include "JVAreaSelector.h"

JVAreaSelector::JVAreaSelector()
{
 
    m_pDisplay = XOpenDisplay(0);
    m_pWindowRoot = &DefaultRootWindow(m_pDisplay);
    m_nScreen = DefaultScreen(m_pDisplay);
    
    XWindowAttributes attributes = {0};
    XGetWindowAttributes(m_pDisplay, *m_pWindowRoot, &attributes);

    m_rc.m_nWidth = attributes.width;
    m_rc.m_nHeight = attributes.height;
    m_rc.m_nX = 0;
    m_rc.m_nY = 0;
    
    XFlush(m_pDisplay);
    XCloseDisplay(m_pDisplay);
    
   m_bEnabled = false;
}

QRect JVAreaSelector::getSelectedArea()
{
    return QRect(m_rc.m_nX,m_rc.m_nY,m_rc.m_nWidth,m_rc.m_nHeight);
}

void JVAreaSelector::start()
{
    m_bEnabled = true;
    
    m_pDisplay = XOpenDisplay(0);
    m_pWindowRoot = &DefaultRootWindow(m_pDisplay);
    m_nScreen = DefaultScreen(m_pDisplay);
    
    
    XGrabPointer(m_pDisplay, *m_pWindowRoot,
               1,
               ButtonPressMask | ButtonReleaseMask | ButtonMotionMask,
               GrabModeAsync,
               GrabModeAsync,
               0, 0,
               CurrentTime);

   XGrabKeyboard(m_pDisplay, *m_pWindowRoot,
           1,
           GrabModeAsync,
           GrabModeAsync,
           CurrentTime);

   processEvents();
}

JVAreaSelector::~JVAreaSelector()
{
    XFlush(m_pDisplay);
    XCloseDisplay(m_pDisplay);
}

void JVAreaSelector::processEvents()
{
    qDebug() << "tick area selector";


        while(m_bEnabled == true)
        {
            XEvent  event;
            XNextEvent(m_pDisplay, &event);

            switch (event.type)
            {
              case KeyPress:
                  qDebug() << "finish";

                   XUngrabPointer( m_pDisplay, CurrentTime );
                   XFlush(m_pDisplay);
                   XCloseDisplay(m_pDisplay);
                 //     XFlush(m_pDisplay);
                  m_bEnabled = false;
                  break;

              case ButtonPress:
                  //printf("ButtonPress:  X=%d   Y=%d\n",
                  //        event.xbutton.x_root, event.xbutton.y_root);
                  drawRectangle();
                  m_rc.m_nX = m_rc.m_nY = m_rc.m_nWidth = m_rc.m_nHeight = 0;

                  // grab the currnt cursor coordinates
                  m_rc.m_nX = event.xbutton.x;
                  m_rc.m_nY = event.xbutton.y;
                  break;

              case ButtonRelease:
                  //printf("ButtonPress:  X=%d   Y=%d\n",
                  //        event.xbutton.x_root, event.xbutton.y_root);

                  break;

              case MotionNotify:
                  //printf("MotionNotify:  X=%d   Y=%d\n",
                  //        event.xbutton.x_root, event.xbutton.y_root);

                  // XOR the previously drawn line to "delete" it
                  drawRectangle();

                  // construct width/height of rectangle based of click originand where the cursor currently is
                  m_rc.m_nWidth  = abs(m_rc.m_nX - event.xbutton.x);
                  m_rc.m_nHeight = abs(m_rc.m_nY - event.xbutton.y);

                  // adjust coords to account for which way the cursor was moved in order to draw the rectangle.
                  if (m_rc.m_nX > event.xbutton.x)
                      m_rc.m_nX = event.xbutton.x;
                  if (m_rc.m_nY > event.xbutton.y)
                      m_rc.m_nY = event.xbutton.y;

                  // draw new rectangle outline
                  drawRectangle();
                  break;

              default:
                    qDebug() << "default";
                  break;
            }
        }

}

void JVAreaSelector::drawRectangle()
{
    XGCValues  gc_val;

    /* create a GC (Graphics Context) for the line  */
    gc_val.function           = GXxor;
    gc_val.plane_mask         = AllPlanes;
    gc_val.foreground         = WhitePixel(m_pDisplay, m_nScreen);
    gc_val.background         = BlackPixel(m_pDisplay, m_nScreen);
    gc_val.line_width         = 4;
    gc_val.line_style         = LineSolid;
    gc_val.cap_style          = CapButt;
    gc_val.join_style         = JoinMiter;
    gc_val.fill_style         = FillOpaqueStippled;
    gc_val.fill_rule          = WindingRule;
    gc_val.graphics_exposures = False;
    gc_val.clip_x_origin      = 0;
    gc_val.clip_y_origin      = 0;
    gc_val.clip_mask          = None;
    gc_val.subwindow_mode     = IncludeInferiors;

    m_gc = XCreateGC(m_pDisplay, *m_pWindowRoot,
            GCFunction    | GCPlaneMask   | GCForeground |
            GCBackground  | GCLineWidth   | GCLineStyle  |
            GCCapStyle    | GCJoinStyle   | GCFillStyle  |
            GCFillRule    | GCGraphicsExposures          |
            GCClipXOrigin | GCClipYOrigin |  GCClipMask  |
            GCSubwindowMode,
            &gc_val);

    XDrawRectangle(m_pDisplay, *m_pWindowRoot, m_gc,
            m_rc.m_nX, m_rc.m_nY,
            m_rc.m_nWidth, m_rc.m_nHeight);
}
