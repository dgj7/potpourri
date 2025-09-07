package com.dg.jmge.render.gl2;

import com.dg.jmge.model.entity.Axes;
import com.dg.jmge.model.entity.text.Statistics;
import com.dg.jmge.model.entity.text.Text2D;
import com.dg.jmge.render.AbstractEntityRenderer;
import com.dg.jmge.render.AbstractRenderer;
import com.jogamp.opengl.GL2;
import com.jogamp.opengl.GLAutoDrawable;
import com.jogamp.opengl.glu.GLU;

/**
 * render using opengl up to 3.0.
 * <p>
 * note: this class will undergo many changes in the future. the below
 * static code will change to use scene graph - this is to test that things
 * are working correctly.
 */
public class GL2Renderer extends AbstractRenderer {
    private GLU glu = null;
    private AbstractEntityRenderer<GL2> entityRenderer = null;
    private Axes axes = new Axes(1);
    private Text2D text = new Text2D("this is an axis with the origin at (0,0,0)", 100, 325);
    private Statistics statistics = new Statistics();

    @Override
    public void display(GLAutoDrawable drawable) {
        GL2 gl = drawable.getGL().getGL2();
        gl.glClear(GL2.GL_COLOR_BUFFER_BIT | GL2.GL_DEPTH_BUFFER_BIT);
        gl.glLoadIdentity();
        gl.glTranslatef(-1.0f, -1.0f, -6.0f);


        try {
            entityRenderer.renderEntity(axes, drawable);
            entityRenderer.renderEntity(text, drawable);
            entityRenderer.renderEntity(statistics, drawable);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void dispose(GLAutoDrawable drawable) {
        //
    }

    @Override
    public void reshape(GLAutoDrawable drawable, int x, int y, int w, int h) {
        GL2 gl = drawable.getGL().getGL2();
        float aspect = (float) w / h;
        gl.glViewport(0, 0, w, h);
        gl.glMatrixMode(GL2.GL_PROJECTION);
        gl.glLoadIdentity();
        glu.gluPerspective(45.0, aspect, 0.1, 100.0);
        gl.glMatrixMode(GL2.GL_MODELVIEW);
        gl.glLoadIdentity();
    }

    @Override
    public void init(GLAutoDrawable drawable) {
        GL2 gl = drawable.getGL().getGL2();
        glu = new GLU();
        entityRenderer = new GL2EntityRenderer(gl);
        gl.glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        gl.glClearDepth(1.0f);
        gl.glEnable(GL2.GL_DEPTH_TEST);
        gl.glDepthFunc(GL2.GL_LEQUAL);
        gl.glHint(GL2.GL_PERSPECTIVE_CORRECTION_HINT, GL2.GL_NICEST);
        gl.glShadeModel(GL2.GL_SMOOTH);
    }
}