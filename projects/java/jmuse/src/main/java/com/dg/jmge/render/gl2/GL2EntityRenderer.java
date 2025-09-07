package com.dg.jmge.render.gl2;

import com.dg.jmge.model.entity.AbstractEntity;
import com.dg.jmge.render.AbstractEntityRenderer;
import com.dg.jmge.render.gl2.entity.AbstractGL2EntityRenderer;
import com.dg.jmge.render.gl2.entity.GL2EntityRendererFactory;
import com.jogamp.opengl.GL2;
import com.jogamp.opengl.GLAutoDrawable;

public class GL2EntityRenderer extends AbstractEntityRenderer<GL2> {
    public GL2EntityRenderer(GL2 inputRenderer) {
        super(inputRenderer);
    }

    public void renderEntity(AbstractEntity entity, GLAutoDrawable drawable) throws Exception {
        if (entity.isVisible()) {
            @SuppressWarnings("unchecked") AbstractGL2EntityRenderer<AbstractEntity> entityRenderer = (AbstractGL2EntityRenderer<AbstractEntity>) GL2EntityRendererFactory.getInstance(renderer).create(entity);
            entityRenderer.render(entity, drawable);
        }
    }
}