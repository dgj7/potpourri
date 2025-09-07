package com.dg.jmge.system.event;

import com.dg.jmge.model.event.AbstractEvent;
import com.dg.jmge.system.AbstractSystem;
import com.dg.jmge.system.event.thread.EventRunnable;

public class EventSystem extends AbstractSystem {
    private EventRunnable mainEventRunnable = new EventRunnable();
    private EventRunnable mouseMovementEventRunnable = new EventRunnable();

    private Thread mainEventThread = new Thread(mainEventRunnable, "MuseMainEventThread");
    private Thread mouseMovementEventThread = new Thread(mouseMovementEventRunnable, "MuseMouseMovementEventThread");

    public synchronized void start() {
        mainEventThread.start();
        mouseMovementEventThread.start();
    }

    public synchronized void shutdown() {
        mainEventRunnable.shutdown();
        mouseMovementEventRunnable.shutdown();
    }

    public synchronized void addEvent(AbstractEvent event) {
        mainEventRunnable.addEvent(event);
    }

    public synchronized void addMouseMovementEvent(AbstractEvent event) {
        mouseMovementEventRunnable.addEvent(event);
    }
}