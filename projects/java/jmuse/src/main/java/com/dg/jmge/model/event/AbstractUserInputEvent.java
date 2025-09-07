package com.dg.jmge.model.event;

import com.dg.jmge.model.state.ButtonState;

public abstract class AbstractUserInputEvent extends AbstractEvent {
    protected ButtonState buttonState = ButtonState.Undefined;

    protected AbstractUserInputEvent(EventSource eventSourceInput, ButtonState buttonStateInput) {
        super(eventSourceInput);
        buttonState = buttonStateInput;
    }
}