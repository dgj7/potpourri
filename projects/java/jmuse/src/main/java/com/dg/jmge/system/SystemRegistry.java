package com.dg.jmge.system;

import com.dg.jmge.system.event.EventSystem;
import com.dg.jmge.system.state.StateSystem;
import org.apache.log4j.Logger;

import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentMap;

/**
 * A registry for {@link AbstractSystem}s; largely these are event
 * management systems.
 */
public class SystemRegistry {
    private static volatile SystemRegistry instance = null;
    private static volatile Logger logger = Logger.getLogger(SystemRegistry.class);
    private volatile ConcurrentMap<Class<?>, AbstractSystem> registry = null;

    /**
     * Create a new instance.  This is disallowed except via getInstance().
     */
    private SystemRegistry() {
        registry = new ConcurrentHashMap<Class<?>, AbstractSystem>();

        registry.put(EventSystem.class, new EventSystem());
        registry.put(StateSystem.class, new StateSystem());
    }

    /**
     * Get the singleton {@link SystemRegistry} instance.
     *
     * @return the singleton {@link SystemRegistry} instance.
     */
    public static synchronized SystemRegistry getInstance() {
        if (instance == null)
            instance = new SystemRegistry();
        return instance;
    }

    /**
     * Start all registered {@link AbstractSystem}s.
     */
    public synchronized void startAll() {
        registry.keySet().forEach(clazz -> start(registry.get(clazz)));
    }

    /**
     * Start an {@link AbstractSystem}.
     *
     * @param system an {@link AbstractSystem}.
     */
    private synchronized void start(final AbstractSystem system) {
        try {
            system.start();
            logger.debug(safelyFindSystemName(system) + " started successfully.");
        } catch (final Exception ex) {
            logger.error("there was an error starting " + safelyFindSystemName(system) + ".");
            throw ex;
        }
    }

    /**
     * Shutdown all registered {@link AbstractSystem}s.
     */
    public synchronized void shutdownAll() {
        registry.keySet().forEach(clazz -> shutdown(registry.get(clazz)));
    }

    /**
     * Shutdown an {@link AbstractSystem}.'
     *
     * @param system an {@link AbstractSystem}.
     */
    private synchronized void shutdown(final AbstractSystem system) {
        try {
            system.shutdown();
            logger.debug(safelyFindSystemName(system) + " shut down successfully.");
        } catch (final Exception ex) {
            logger.error("there was an error shutting down " + safelyFindSystemName(system) + ".");
        }
    }

    /**
     * Find a previously registered {@link AbstractSystem}.
     *
     * @param clazz the class name of a previously registered {@link AbstractSystem}.
     * @return an {@link AbstractSystem} associated with the given {@link Class}, or null if
     * one was not previously registered for this {@link Class}.
     */
    public synchronized AbstractSystem findSystem(Class<?> clazz) {
        return registry.get(clazz);
    }

    /**
     * Safely find the name of the given {@link AbstractSystem}.
     *
     * @param system the {@link AbstractSystem} for which a name is desired.
     * @return the name of the given {@link AbstractSystem}, or UNKNOWN.
     */
    private synchronized String safelyFindSystemName(AbstractSystem system) {
        try {
            return system.getClass().getSimpleName();
        } catch (Exception ex) {
            return "UNKNOWN";
        }
    }
}