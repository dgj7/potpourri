package com.dg.jmge.system.event.thread;

import com.dg.jmge.model.event.AbstractEvent;
import com.dg.jmge.model.event.app.InitializationEvent;
import com.dg.jmge.system.SystemRunnable;
import com.dg.jmge.system.event.journal.EventJournal;
import com.dg.jmge.system.event.proc.EventProcessorFactory;
import com.dg.jmge.system.event.proc.IEventProcessor;

import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;

public class EventRunnable implements SystemRunnable {
    private volatile Queue<AbstractEvent> eventQueue = null;
    private EventJournal journal = new EventJournal();
    private boolean running = false;

    public EventRunnable() {
        eventQueue = new ConcurrentLinkedQueue<AbstractEvent>();

        eventQueue.add(new InitializationEvent());
        running = true;
    }

    @Override
    public void run() {
        AbstractEvent event = eventQueue.poll();
        while (running) {
            journal.log(event);
            IEventProcessor processor = EventProcessorFactory.getInstance().createEventProcessor(event);
            processor.process(event);
            event = eventQueue.poll();
        }
    }

    @Override
    public synchronized void shutdown() {
        running = false;
    }

    public synchronized void addEvent(AbstractEvent event) {
        eventQueue.add(event);
    }
}