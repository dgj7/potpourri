package com.dg.sample;

import com.dg.sample.dep.MessageRepository;

public abstract class Main {
    public static void main(final String[] args) {
        final String message = MessageRepository.retrieveMessage();
        System.out.println(message);
    }
}
