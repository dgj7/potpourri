package com.dg.jmge.render.gl2.entity;

import com.dg.jmge.model.entity.text.Statistics;
import com.jogamp.opengl.GL2;
import com.jogamp.opengl.GLAutoDrawable;

public class GL2StatisticsRenderer extends AbstractGL2EntityRenderer<Statistics> {
    private GL2Text2DRenderer textRenderer = null;

    public GL2StatisticsRenderer(GL2 rendererInput) {
        super(rendererInput);
        textRenderer = new GL2Text2DRenderer(rendererInput);
    }

    public void render(Statistics statisticsInput, GLAutoDrawable drawable) {
        textRenderer.render(statisticsInput.getFpsText(), drawable);
    }
}