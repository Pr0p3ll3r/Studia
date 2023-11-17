package org.example.calculations;

import static org.junit.Assert.fail;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.RepeatedTest;
import org.junit.jupiter.api.Test;

class CalculatorTest {
    Calculator calculator;
    @BeforeEach
    void init() {
        calculator = new Calculator();
    }
    @Test
    @DisplayName("Multiplication of calculator")
    void testMultiply() {
        assertEquals(10, calculator.multiply(2, 5),
                "Multiplication should work");
    }
    @RepeatedTest(10)
    @DisplayName("Ensure correct multiplication by zero")
    void testMultiplicationByZero() {
        assertEquals(0, calculator.multiply(0, 10),
                "Multiplication by zero should be zero");
        assertEquals(0, calculator.multiply(1, 0),
                "Multiplication by zero should be zero");
    }
    @RepeatedTest(10)
    @DisplayName("Ensure correct multiplication by one")
    void testMultiplicationByOne() {
        assertEquals(10, calculator.multiply(1, 10),
                "Multiplication ten by one should be ten");
        assertEquals(5, calculator.multiply(1, 5),
                "Multiplication five by one should be five");
    }

    @Test
    @DisplayName("Adding of calculator")
    void testAdd() {
        assertEquals(7, calculator.add(2, 5),
                "Adding should work");
    }
    @Test
    @DisplayName("Subtraction of calculator")
    void testSubtract() {
        assertEquals(-3, calculator.subtract(2, 5),
                "Subtraction should work");
    }
    @Test
    @DisplayName("Dividing of calculator")
    void testDivide() {
        assertEquals(2, calculator.divide(10, 5),
                "Dividing should work");
    }
    @RepeatedTest(10)
    @DisplayName("Ensure correct dividing by zero")
    void testDivideByZero() {
        assertThrows(IllegalArgumentException.class, () -> calculator.divide(10, 0),
                "Dividing by zero should throw IllegalArgumentException");
    }
}