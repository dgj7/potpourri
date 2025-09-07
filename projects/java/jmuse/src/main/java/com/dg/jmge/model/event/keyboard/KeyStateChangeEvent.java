package com.dg.jmge.model.event.keyboard;

import com.dg.jmge.model.event.AbstractUserInputEvent;
import com.dg.jmge.model.event.EventSource;
import com.dg.jmge.model.state.ButtonState;

public class KeyStateChangeEvent extends AbstractUserInputEvent {
    public KeyStateChangeEvent(ButtonState buttonStateInput) {
        super(EventSource.Keyboard, buttonStateInput);
    }
}