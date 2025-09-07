package com.dg.jmge.view.window;

import com.dg.jmge.system.SystemRegistry;
import com.jogamp.newt.event.WindowEvent;
import com.jogamp.newt.event.WindowListener;
import com.jogamp.newt.event.WindowUpdateEvent;
import com.jogamp.newt.opengl.GLWindow;
import com.jogamp.opengl.util.Animator;

/**
 * Main handler for window events.
 */
public class WindowEventHandler implements WindowListener {
    private final Animator animator;
    private final GLWindow glWindow;

    /**
     * Create a new instance.
     */
    public WindowEventHandler(final Animator ai, final GLWindow gwi) {
        animator = ai;
        glWindow = gwi;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void windowResized(final WindowEvent e) {
        //
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void windowMoved(final WindowEvent e) {
        //
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void windowDestroyNotify(final WindowEvent e) {
        if (animator.isAnimating()) {
            animator.pause();
        }
        animator.stop();
        SystemRegistry.getInstance().shutdownAll();
        System.exit(0);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void windowDestroyed(final WindowEvent e) {
        System.exit(0);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void windowGainedFocus(final WindowEvent e) {
        //
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void windowLostFocus(final WindowEvent e) {
        //
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void windowRepaint(final WindowUpdateEvent e) {
        //
    }
}
