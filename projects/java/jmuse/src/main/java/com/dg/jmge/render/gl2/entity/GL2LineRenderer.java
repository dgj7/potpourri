package com.dg.jmge.render.gl2.entity;

import com.dg.jmge.model.entity.Line;
import com.jogamp.opengl.GL2;
import com.jogamp.opengl.GLAutoDrawable;

public class GL2LineRenderer extends AbstractGL2EntityRenderer<Line> {
    public GL2LineRenderer(GL2 rendererInput) {
        super(rendererInput);
    }

    public void render(Line line, GLAutoDrawable drawable) {
        renderer.glBegin(GL2.GL_LINES);
        useColor(line.getColor());
        useVector(line.getBegin());
        useVector(line.getEnd());
        renderer.glEnd();
    }
}