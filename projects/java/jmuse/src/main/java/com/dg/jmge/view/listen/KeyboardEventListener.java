package com.dg.jmge.view.listen;

//import org.apache.log4j.Logger;

import com.dg.jmge.model.event.AbstractEvent;
import com.dg.jmge.model.event.EventFactory;
import com.dg.jmge.model.state.ButtonState;
import com.dg.jmge.system.SystemRegistry;
import com.dg.jmge.system.event.EventSystem;
import com.jogamp.newt.event.InputEvent;
import com.jogamp.newt.event.KeyEvent;
import com.jogamp.newt.event.KeyListener;

public class KeyboardEventListener implements KeyListener {
    //private static final Logger logger = Logger.getLogger(KeyboardEventListener.class);
    private EventSystem eventSystemReference = (EventSystem) SystemRegistry.getInstance().findSystem(EventSystem.class);

    @Override
    public void keyPressed(KeyEvent e) {
        if (0 == (InputEvent.AUTOREPEAT_MASK & e.getModifiers())) {
            //logger.trace("key pressed: " + e.getKeyChar() + "/" + e.getKeyCode());
            AbstractEvent event = EventFactory.getInstance().createKeyboardStateChangeEvent(e, ButtonState.Pressed);
            eventSystemReference.addEvent(event);
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {
        if (0 == (InputEvent.AUTOREPEAT_MASK & e.getModifiers())) {
            //logger.trace("key released: " + e.getKeyChar() + "/" + e.getKeyCode());
            AbstractEvent event = EventFactory.getInstance().createKeyboardStateChangeEvent(e, ButtonState.Released);
            eventSystemReference.addEvent(event);
        }
    }
}