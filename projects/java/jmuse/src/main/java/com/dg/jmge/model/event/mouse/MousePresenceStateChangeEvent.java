package com.dg.jmge.model.event.mouse;

import com.dg.jmge.model.event.AbstractEvent;
import com.dg.jmge.model.event.EventSource;
import com.dg.jmge.model.state.MousePresenceState;

public class MousePresenceStateChangeEvent extends AbstractEvent {
    private MousePresenceState mousePresenceState = MousePresenceState.Undefined;

    public MousePresenceStateChangeEvent(MousePresenceState mousePresenceStateInput) {
        super(EventSource.Mouse);
        mousePresenceState = mousePresenceStateInput;
    }

    public MousePresenceState getMousePresenceState() {
        return mousePresenceState;
    }
}