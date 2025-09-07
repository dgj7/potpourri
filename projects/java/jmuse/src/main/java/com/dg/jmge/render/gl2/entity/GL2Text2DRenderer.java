package com.dg.jmge.render.gl2.entity;

import com.dg.jmge.model.entity.text.Text2D;
import com.jogamp.opengl.GL;
import com.jogamp.opengl.GL2;
import com.jogamp.opengl.GLAutoDrawable;
import com.jogamp.opengl.util.awt.TextRenderer;
import org.apache.log4j.Logger;

import java.awt.*;
import java.util.HashMap;
import java.util.Map;

public class GL2Text2DRenderer extends AbstractGL2EntityRenderer<Text2D> {
    private static final Logger logger = Logger.getLogger(GL2Text2DRenderer.class);
    private Map<Font, TextRenderer> map = new HashMap<Font, TextRenderer>();

    public GL2Text2DRenderer(GL2 rendererInput) {
        super(rendererInput);
    }

    public void render(Text2D text, GLAutoDrawable drawable) {
        renderer.getGL().glBindBuffer(GL.GL_ARRAY_BUFFER, 0);

        try {
            TextRenderer renderer = map.get(text.getFont());
            if (renderer == null) {
                logger.debug("creating new text renderer for [" + text.getFont().getName() + "]...");
                renderer = new TextRenderer(text.getFont());
                map.put(text.getFont(), renderer);
            }

            renderer.beginRendering(drawable.getSurfaceWidth(), drawable.getSurfaceHeight());
            renderer.setColor(text.getColor().getRed(), text.getColor().getGreen(), text.getColor().getBlue(), text.getColor().getAlpha());
            renderer.draw(text.getString(), text.getX(), text.getY());
            renderer.endRendering();
        } catch (Exception ex) {
            logger.error("renderer failure - " + ex.getClass().getSimpleName() + ": " + ex.getMessage());
            map.remove(text.getFont());
            throw ex;
        }
    }
}