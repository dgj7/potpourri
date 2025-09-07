package com.dg.jmge.model.transform;

import com.dg.jmge.model.math.Vector3D;

public class EulerAngle {
    private Vector3D roll = null;        // rotation about x
    private Vector3D pitch = null;        // rotation about y (horizontal)
    private Vector3D yaw = null;        // rotation about z (vertical)

    public EulerAngle(Vector3D rollInput, Vector3D pitchInput, Vector3D yawInput) {
        roll = rollInput;
        pitch = pitchInput;
        yaw = yawInput;
    }

    public Vector3D getRoll() {
        return roll;
    }

    public Vector3D getPitch() {
        return pitch;
    }

    public Vector3D getYaw() {
        return yaw;
    }
}