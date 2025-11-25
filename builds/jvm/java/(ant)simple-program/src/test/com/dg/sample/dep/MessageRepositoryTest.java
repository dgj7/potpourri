package com.dg.sample.dep;

import org.junit.Test;
import org.junit.Assert;

public class MessageRepositoryTest {
    @Test
    public final void testHappyPath() {
        Assert.assertEquals("hello, world!", MessageRepository.retrieveMessage());
    }
}
