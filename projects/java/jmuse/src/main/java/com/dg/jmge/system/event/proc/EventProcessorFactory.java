package com.dg.jmge.system.event.proc;

import com.dg.jmge.model.event.AbstractEvent;
import com.dg.jmge.model.event.mouse.MousePositionChangeEvent;

import java.util.HashMap;
import java.util.Map;

public class EventProcessorFactory {
    private static volatile EventProcessorFactory instance = null;

    private volatile Map<Class<? extends AbstractEvent>, IEventProcessor> processorMap = null;

    private IEventProcessor nullEventProcessor = new NullEventProcessor();
    private IEventProcessor undefinedEventProcessor = new UndefinedEventProcessor();

    private EventProcessorFactory() {
        processorMap = new HashMap<Class<? extends AbstractEvent>, IEventProcessor>();

        processorMap.put(MousePositionChangeEvent.class, new MousePositionEventProcessor());
    }

    public static synchronized EventProcessorFactory getInstance() {
        if (instance == null)
            instance = new EventProcessorFactory();
        return instance;
    }

    public IEventProcessor createEventProcessor(AbstractEvent event) {
        if (event == null)
            return nullEventProcessor;

        IEventProcessor processor = processorMap.get(event.getClass());

        if (processor != null)
            return processor;
        return undefinedEventProcessor;
    }
}