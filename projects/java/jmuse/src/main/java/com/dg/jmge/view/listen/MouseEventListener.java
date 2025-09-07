package com.dg.jmge.view.listen;

import com.dg.jmge.model.event.AbstractEvent;
import com.dg.jmge.model.event.EventFactory;
import com.dg.jmge.model.state.ButtonState;
import com.dg.jmge.model.state.MousePresenceState;
import com.dg.jmge.system.SystemRegistry;
import com.dg.jmge.system.event.EventSystem;
import com.jogamp.newt.event.MouseEvent;
import com.jogamp.newt.event.MouseListener;

public class MouseEventListener implements MouseListener {
    private EventSystem eventSystemReference = (EventSystem) SystemRegistry.getInstance().findSystem(EventSystem.class);

    @Override
    public void mousePressed(MouseEvent e) {
        AbstractEvent event = EventFactory.getInstance().createMouseButtonStateChangeEvent(e, ButtonState.Pressed);
        eventSystemReference.addEvent(event);
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        AbstractEvent event = EventFactory.getInstance().createMouseButtonStateChangeEvent(e, ButtonState.Released);
        eventSystemReference.addEvent(event);
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        AbstractEvent event = EventFactory.getInstance().createMousePresenceStateChangeEvent(MousePresenceState.OnScreen);
        eventSystemReference.addEvent(event);
    }

    @Override
    public void mouseExited(MouseEvent e) {
        AbstractEvent event = EventFactory.getInstance().createMousePresenceStateChangeEvent(MousePresenceState.OffScreen);
        eventSystemReference.addEvent(event);
    }

    @Override
    public void mouseMoved(MouseEvent e) {
        AbstractEvent event = EventFactory.getInstance().createMousePositionChangeEvent(e);
        eventSystemReference.addMouseMovementEvent(event);
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        AbstractEvent event = EventFactory.getInstance().createMousePositionChangeEvent(e);
        eventSystemReference.addMouseMovementEvent(event);
    }

    @Override
    public void mouseClicked(MouseEvent e) {
    }

    @Override
    public void mouseWheelMoved(MouseEvent e) {
    }
}