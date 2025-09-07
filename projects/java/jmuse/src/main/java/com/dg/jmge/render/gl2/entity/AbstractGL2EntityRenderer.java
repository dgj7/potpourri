package com.dg.jmge.render.gl2.entity;

import com.dg.jmge.model.Color;
import com.dg.jmge.model.entity.AbstractEntity;
import com.dg.jmge.model.math.Vector3D;
import com.jogamp.opengl.GL2;
import com.jogamp.opengl.GLAutoDrawable;

public abstract class AbstractGL2EntityRenderer<T extends AbstractEntity> {
    protected GL2 renderer = null;

    protected AbstractGL2EntityRenderer(GL2 rendererInput) {
        renderer = rendererInput;
    }

    public abstract void render(T entity, GLAutoDrawable drawable);

    protected void useColor(Color colorInput) {
        renderer.glColor3f(colorInput.getRed(), colorInput.getGreen(), colorInput.getBlue());
    }

    protected void useVector(Vector3D vectorInput) {
        renderer.glVertex3f(vectorInput.getX(), vectorInput.getY(), vectorInput.getZ());
    }
}