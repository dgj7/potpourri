package com.dg.jmge.view.window;

import com.dg.jmge.model.window.WindowConfiguration;
import com.dg.jmge.render.AbstractRenderer;
import com.dg.jmge.view.camera.AbstractCamera;
import com.dg.jmge.view.camera.CameraFactory;
import com.dg.jmge.view.camera.CameraType;
import com.dg.jmge.view.listen.KeyboardEventListener;
import com.dg.jmge.view.listen.MouseEventListener;
import com.jogamp.newt.opengl.GLWindow;
import com.jogamp.opengl.GLCapabilities;
import com.jogamp.opengl.GLProfile;
import com.jogamp.opengl.util.Animator;

/**
 * Core window type for JMuse.
 */
public abstract class AbstractWindow {
    /* jogamp stuff */
    protected final GLWindow window;
    protected final Animator animator;
    protected final GLProfile profile;
    protected final GLCapabilities capabilities;

    /* implementations of jogamp interfaces */
    protected final WindowEventHandler eventHandler;

    /* jmuse stuff */
    protected final AbstractRenderer renderer;
    protected final AbstractCamera camera;

    /**
     * Create a new instance.
     */
    protected AbstractWindow(final String version, final WindowConfiguration configuration, final AbstractRenderer rendererInput, final CameraType cameraTypeInput) {
        /* initialize jogamp stuff */
        profile = GLProfile.get(version);
        capabilities = new GLCapabilities(profile);
        window = GLWindow.create(capabilities);

        /* set jmuse renderer */
        renderer = rendererInput;

        /* set up jogamp window */
        window.setTitle(configuration.getTitle());
        window.setSize(configuration.getWidth(), configuration.getHeight());
        window.setVisible(configuration.isVisible());
        window.addMouseListener(new MouseEventListener());
        window.addKeyListener(new KeyboardEventListener());
        window.addGLEventListener(renderer);

        /* initialize animator with jogamp window */
        animator = new Animator(window);

        /* configure jmuse types */
        eventHandler = new WindowEventHandler(animator, window);
        camera = CameraFactory.getInstance().createCamera(cameraTypeInput);
        window.addWindowListener(eventHandler);

        /* all done, start the animator */
        animator.start();
    }
}
