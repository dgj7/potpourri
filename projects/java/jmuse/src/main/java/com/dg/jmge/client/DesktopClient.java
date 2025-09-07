package com.dg.jmge.client;

import com.dg.jmge.render.AbstractRenderer;
import com.dg.jmge.render.gl2.GL2Renderer;
import com.dg.jmge.system.SystemRegistry;
import com.dg.jmge.view.camera.CameraType;
import com.dg.jmge.view.window.GL2Window;

import javax.swing.*;

public class DesktopClient {
    private static AbstractRenderer renderer = null;

    public static void main(String[] args) {
        SystemRegistry.getInstance().startAll();

        SwingUtilities.invokeLater(() -> {
            renderer = new GL2Renderer();
            new GL2Window("JMuse", 800, 600, renderer, CameraType.Spectator);
        });
    }
}