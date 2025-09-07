package com.dg.jmge.model.event;

public enum EventSource {
    Undefined(-1),
    Initialization(0),
    EventSystem(1),
    Keyboard(2),
    Mouse(3),
    Network(4),
    ;

    private int id;

    EventSource(int idInput) {
        id = idInput;
    }

    public int getId() {
        return id;
    }
}