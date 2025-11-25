package com.dg.gosumin

uses com.dg.gosumin.Thing
uses org.junit.Assert
uses org.junit.Test

class ThingTest {
	@Test
	function executeTest() {
		var objectUnderTest = new Thing()

		Assert.assertNotNull(objectUnderTest)
		Assert.assertEquals("execute with input: 'test'", objectUnderTest.execute("test"))
		Assert.assertTrue(objectUnderTest.ThingProperty)
	}
}
