package com.dg.jmge.render;

import com.dg.jmge.model.entity.AbstractEntity;
import com.jogamp.opengl.GL;
import com.jogamp.opengl.GLAutoDrawable;

public abstract class AbstractEntityRenderer<T extends GL> {
    protected T renderer = null;

    protected AbstractEntityRenderer(T rendererInput) {
        renderer = rendererInput;
    }

    public abstract void renderEntity(AbstractEntity entity, GLAutoDrawable drawable) throws Exception;
}