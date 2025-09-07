package com.dg.jmge.render.gl2.entity;

import com.dg.jmge.model.entity.Axes;
import com.jogamp.opengl.GL2;
import com.jogamp.opengl.GLAutoDrawable;

public class GL2AxesRenderer extends AbstractGL2EntityRenderer<Axes> {
    private GL2LineRenderer lineRenderer = null;

    public GL2AxesRenderer(GL2 rendererInput) {
        super(rendererInput);
        lineRenderer = new GL2LineRenderer(renderer);
    }

    public void render(Axes axes, GLAutoDrawable drawable) {
        lineRenderer.render(axes.getXAxis(), drawable);
        lineRenderer.render(axes.getYAxis(), drawable);
        lineRenderer.render(axes.getZAxis(), drawable);
    }
}