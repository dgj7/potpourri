package com.dg.jmge.model.event.mouse;

import com.dg.jmge.model.event.AbstractEvent;
import com.dg.jmge.model.event.EventSource;

public class MousePositionChangeEvent extends AbstractEvent {
    private int x = 0;
    private int y = 0;

    public MousePositionChangeEvent(int xInput, int yInput) {
        super(EventSource.Mouse);
        x = xInput;
        y = yInput;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}