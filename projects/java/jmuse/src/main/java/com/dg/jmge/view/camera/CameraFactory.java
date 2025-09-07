package com.dg.jmge.view.camera;

public class CameraFactory {
    private static volatile CameraFactory instance = null;
    private static SpectatorCamera spectator = null;

    private CameraFactory() {
        spectator = new SpectatorCamera();
    }

    public static synchronized CameraFactory getInstance() {
        if (instance == null)
            instance = new CameraFactory();
        return instance;
    }

    public AbstractCamera createCamera(CameraType type) {
        switch (type) {
            case Spectator:
                return spectator;
            case FirstPerson:
            case ThirdPerson:
            case Isometric:
        }
        throw new UnsupportedOperationException();
    }
}