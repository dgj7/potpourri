package com.dg.jmge.view.window;

import com.dg.jmge.model.window.WindowConfiguration;
import com.dg.jmge.render.AbstractRenderer;
import com.dg.jmge.view.camera.CameraType;
import com.jogamp.opengl.GLProfile;

public class GL2Window extends AbstractWindow {
    public GL2Window(String title, int width, int height, AbstractRenderer renderer, CameraType cameraTypeInput) {
        super(GLProfile.GL2, new WindowConfiguration(title, width, height, true), renderer, cameraTypeInput);
    }
}