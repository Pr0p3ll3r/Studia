package org.example.calculations;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.Assert.*;
import static org.junit.jupiter.api.Assertions.assertThrows;
public class ThermometerTest {
    Thermometer thermometer;
    @BeforeEach
    void init() {
        thermometer = new Thermometer();
    }
    @Test
    void exceptionTesting() {
        Throwable exception = assertThrows(IllegalArgumentException.class, () -> thermometer.setCurrentTemp("0"));
        assertEquals("CurrentTemp must be an Integer.", exception.getMessage());
    }
    @Test
    void testAddDegreesThrowsException() {
        Throwable exception = assertThrows(IllegalArgumentException.class, () -> thermometer.addDegrees("-30"));
        assertEquals("Degrees to add must be an Integer.", exception.getMessage());
    }
    @Test
    void testSubtractDegreesThrowsException() {
        Throwable exception = assertThrows(IllegalArgumentException.class, () -> thermometer.subtractDegrees("30"));
        assertEquals("Degrees to subtract must be an Integer.", exception.getMessage());
    }
    @Test
    void testIsBelowZero() {
        thermometer.setCurrentTemp(10);
        assertFalse(thermometer.isBelowZero());

        thermometer.setCurrentTemp(-5);
        assertTrue(thermometer.isBelowZero());
    }
}