package com.dg.jmge.model.event.mouse;

import com.dg.jmge.model.event.AbstractUserInputEvent;
import com.dg.jmge.model.event.EventSource;
import com.dg.jmge.model.state.ButtonState;

public class MouseButtonStateChangeEvent extends AbstractUserInputEvent {
    public MouseButtonStateChangeEvent(ButtonState buttonStateInput) {
        super(EventSource.Mouse, buttonStateInput);
    }
}