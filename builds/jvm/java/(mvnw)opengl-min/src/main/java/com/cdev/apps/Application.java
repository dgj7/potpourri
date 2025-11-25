package com.cdev.apps;

import com.jogamp.newt.event.WindowAdapter;
import com.jogamp.newt.event.WindowEvent;
import com.jogamp.newt.opengl.GLWindow;
import com.jogamp.opengl.GL2;
import com.jogamp.opengl.GLAutoDrawable;
import com.jogamp.opengl.GLCapabilities;
import com.jogamp.opengl.GLEventListener;
import com.jogamp.opengl.GLProfile;
import com.jogamp.opengl.glu.GLU;
import com.jogamp.opengl.util.Animator;

public class Application implements GLEventListener
{
	private static GLWindow window = null;
    private static Animator animator = null;
    private GLU glu = null;

    public static void main(String[] args)
    {
        new Application().setup();
    }


    private void setup()
    {

        GLProfile glProfile = GLProfile.get(GLProfile.GL2);
        GLCapabilities glCapabilities = new GLCapabilities(glProfile);

        window = GLWindow.create(glCapabilities);

        window.setTitle("Minimal Java OpenGL Setup");
        window.setSize(800, 600);

        window.addGLEventListener(this);
        window.setVisible(true);

        animator = new Animator(window);
        animator.start();

        window.addWindowListener(new WindowAdapter()
        {
            @Override
            public void windowDestroyed(WindowEvent e)
            {
                animator.stop();
                System.exit(1);
            }
        });
    }

	@Override public void display(GLAutoDrawable arg0)
	{
		GL2 gl = arg0.getGL().getGL2();
		gl.glClear(GL2.GL_COLOR_BUFFER_BIT | GL2.GL_DEPTH_BUFFER_BIT);
		gl.glLoadIdentity();
		gl.glTranslatef(0.0f, 0.0f, -6.0f);
		gl.glBegin(GL2.GL_TRIANGLES);
		gl.glVertex3f(0.0f, 1.0f, 0.0f);
		gl.glVertex3f(-1.0f, -1.0f, 0.0f);
		gl.glVertex3f(1.0f, -1.0f, 0.0f);
		gl.glEnd();
	}

	@Override public void dispose(GLAutoDrawable arg0)
	{
		// TODO Auto-generated method stub
	}

	@Override public void reshape(GLAutoDrawable arg0, int x, int y, int w, int h)
	{
		GL2 gl = arg0.getGL().getGL2();
		float aspect = (float)w / h;
		gl.glViewport(0, 0, w, h);
		gl.glMatrixMode(GL2.GL_PROJECTION);
		gl.glLoadIdentity();
		glu.gluPerspective(45.0, aspect, 0.1, 100.0);
		gl.glMatrixMode(GL2.GL_MODELVIEW);
		gl.glLoadIdentity();
	}

	@Override public void init(GLAutoDrawable arg0)
	{
		GL2 gl = arg0.getGL().getGL2();
		glu = new GLU();
		gl.glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		gl.glClearDepth(1.0f);
		gl.glEnable(GL2.GL_DEPTH_TEST);
		gl.glDepthFunc(GL2.GL_LEQUAL);
		gl.glHint(GL2.GL_PERSPECTIVE_CORRECTION_HINT, GL2.GL_NICEST);
		gl.glShadeModel(GL2.GL_SMOOTH);
	}
}