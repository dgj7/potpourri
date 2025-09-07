package com.dg.jmge.model.event;

import com.dg.jmge.model.event.keyboard.KeyStateChangeEvent;
import com.dg.jmge.model.event.mouse.MouseButtonStateChangeEvent;
import com.dg.jmge.model.event.mouse.MousePositionChangeEvent;
import com.dg.jmge.model.event.mouse.MousePresenceStateChangeEvent;
import com.dg.jmge.model.state.ButtonState;
import com.dg.jmge.model.state.MousePresenceState;
import com.jogamp.newt.event.KeyEvent;
import com.jogamp.newt.event.MouseEvent;

public class EventFactory {
    private static volatile EventFactory instance = null;

    private EventFactory() {
        //
    }

    public static synchronized EventFactory getInstance() {
        if (instance == null)
            instance = new EventFactory();
        return instance;
    }

    public KeyStateChangeEvent createKeyboardStateChangeEvent(KeyEvent ke, ButtonState buttonStateInput) {
        KeyStateChangeEvent ksce = new KeyStateChangeEvent(buttonStateInput);

        //

        return ksce;
    }

    public MouseButtonStateChangeEvent createMouseButtonStateChangeEvent(MouseEvent me, ButtonState buttonStateInput) {
        MouseButtonStateChangeEvent mbsce = new MouseButtonStateChangeEvent(buttonStateInput);

        //

        return mbsce;
    }

    public MousePresenceStateChangeEvent createMousePresenceStateChangeEvent(MousePresenceState mousePresenceStateInput) {
        MousePresenceStateChangeEvent mpsce = new MousePresenceStateChangeEvent(mousePresenceStateInput);

        //

        return mpsce;
    }

    public MousePositionChangeEvent createMousePositionChangeEvent(MouseEvent me) {
        MousePositionChangeEvent mpce = new MousePositionChangeEvent(me.getX(), me.getY());

        //

        return mpce;
    }
}