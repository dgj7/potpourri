package com.dg.jmge.model.math;

public class Vector3D {
    private float x;
    private float y;
    private float z;

    private Vector3D(float xInput, float yInput, float zInput) {
        x = xInput;
        y = yInput;
        z = zInput;
    }

    public static Vector3D createVector(float x, float y, float z) {
        return new Vector3D(x, y, z);
    }

    public static Vector3D createOriginVector() {
        return createVector(0, 0, 0);
    }

    public float getX() {
        return x;
    }

    public float getY() {
        return y;
    }

    public float getZ() {
        return z;
    }

    public float calculateLength() {
        float xSquared = x * x;
        float ySquared = y * y;
        float zSquared = z * z;
        float sum = xSquared + ySquared + zSquared;
        float squareRoot = (float) Math.sqrt(sum);
        return squareRoot;
    }

    public void normalize(Vector3D vector) {
        float length = calculateLength();
        x = x / length;
        y = y / length;
        z = z / length;
    }

    public void subtract(Vector3D subtrahend) {
        x = x - subtrahend.getX();
        y = y - subtrahend.getY();
        z = z - subtrahend.getZ();
    }

    public void add(Vector3D right) {
        x = x + right.getX();
        y = y + right.getY();
        z = z + right.getZ();
    }

    public void multiplyByScalar(float multiplicand) {
        x = x * multiplicand;
        y = y * multiplicand;
        z = z * multiplicand;
    }

    public void negate() {
        multiplyByScalar(-1);
    }

    public void divideByScalar(float divisor) {
        x = x / divisor;
        y = y / divisor;
        z = z / divisor;
    }

    public float calculateDotProduct(Vector3D right) {
        float xProduct = x * right.getX();
        float yProduct = y * right.getY();
        float zProduct = z * right.getZ();
        float sum = xProduct + yProduct + zProduct;
        return sum;
    }
}