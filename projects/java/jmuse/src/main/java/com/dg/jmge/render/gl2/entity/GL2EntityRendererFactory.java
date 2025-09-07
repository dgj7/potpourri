package com.dg.jmge.render.gl2.entity;

import com.dg.jmge.model.entity.AbstractEntity;
import com.dg.jmge.model.entity.Axes;
import com.dg.jmge.model.entity.Line;
import com.dg.jmge.model.entity.text.Statistics;
import com.dg.jmge.model.entity.text.Text2D;
import com.jogamp.opengl.GL2;

public class GL2EntityRendererFactory {
    private static volatile GL2EntityRendererFactory instance = null;

    private GL2 renderer = null;

    private GL2LineRenderer lineRenderer = null;
    private GL2AxesRenderer axesRenderer = null;
    private GL2Text2DRenderer textRenderer = null;
    private GL2StatisticsRenderer statisticsRenderer = null;

    private GL2EntityRendererFactory(GL2 rendererInput) {
        renderer = rendererInput;
        lineRenderer = new GL2LineRenderer(renderer);
        axesRenderer = new GL2AxesRenderer(renderer);
        textRenderer = new GL2Text2DRenderer(renderer);
        statisticsRenderer = new GL2StatisticsRenderer(renderer);
    }

    public static synchronized GL2EntityRendererFactory getInstance(GL2 rendererInput) {
        if (instance == null)
            instance = new GL2EntityRendererFactory(rendererInput);
        return instance;
    }

    public AbstractGL2EntityRenderer<?> create(AbstractEntity entityInput) throws Exception {
        if (entityInput instanceof Line) {
            return lineRenderer;
        } else if (entityInput instanceof Axes) {
            return axesRenderer;
        } else if (entityInput instanceof Text2D) {
            return textRenderer;
        } else if (entityInput instanceof Statistics) {
            return statisticsRenderer;
        } else {
            throw new Exception("INVALID ENTITY TYPE");
        }
    }
}