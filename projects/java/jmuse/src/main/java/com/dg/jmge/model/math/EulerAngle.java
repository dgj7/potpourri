package com.dg.jmge.model.math;

public class EulerAngle {
    private float heading = 0.0f;
    private float pitch = 0.0f;
    private float bank = 0.0f;

    private EulerAngle(float headingInput, float pitchInput, float bankInput) {
        heading = headingInput;
        pitch = pitchInput;
        bank = bankInput;
    }

    public static EulerAngle createEulerAngle(float headingInput, float pitchInput, float bankInput) {
        return new EulerAngle(headingInput, pitchInput, bankInput);
    }

    public static EulerAngle createIdentityEulerAngle() {
        return createEulerAngle(0.0f, 0.0f, 0.0f);
    }

    public float getHeading() {
        return heading;
    }

    public float getPitch() {
        return pitch;
    }

    public float getBank() {
        return bank;
    }
	
	/*
	public boolean isGimbelLocked()
	{
		return (Math.abs(pitch) > (Constants.PI_OVER_TWO - Constants.GIMBEL_LOCK_TOLERANCE));
	}
	
	public void canonize()
	{
		pitch = MathUtil.wrapThetaInPi(pitch);
		if(pitch < -(Constants.PI_OVER_TWO))
		{
			pitch = (-(Constants.PI)) - pitch;
			heading += Constants.PI;
			bank += Constants.PI;
		}
		else if(pitch > Constants.PI_OVER_TWO)
		{
			pitch = Constants.PI - pitch;
			heading += Constants.PI;
			bank += Constants.PI;
		}
		
		if(isGimbelLocked())
		{
			heading += bank;
			bank = 0.0f;
		}
		else
		{
			bank = MathUtil.wrapThetaInPi(bank);
		}
		heading = MathUtil.wrapThetaInPi(heading);
	}
	
	public void fromObjectToIntertialQuaternion(Quaternion input)
	{
		float sinPitch = Constants.NEGATIVE_TWO * ((input.getY() * input.getZ())-(input.getW()*input.getX()));
		if(Math.abs(sinPitch) > 0.9999f)
		{
			pitch = Constants.PI_OVER_TWO * sinPitch;
			final float headingOrdinate = (-(input.getX()*input.getZ()))+(input.getW()*input.getY());
			final float headingAbscissa = 0.5f - input.getY()*input.getY()-input.getZ()*input.getZ();
			heading = (float) Math.atan2(headingOrdinate,headingAbscissa);
			bank = 0.0f;
		}
		else
		{
			pitch = (float) Math.asin(sinPitch);
			final float headingOrdinate = input.getX()*input.getZ() + input.getW()*input.getY();
			final float headingAbscissa = 0.5f - input.getX()*input.getX() - input.getY()*input.getY();
			heading = (float) Math.atan2(headingOrdinate,headingAbscissa);
			final float bankOrdinate = input.getX()*input.getY() + input.getW()*input.getZ();
			final float bankAbscissa = 0.5f - input.getX()*input.getX() - input.getZ()*input.getZ();
			bank = (float) Math.atan2(bankOrdinate,bankAbscissa);
		}
	}
	*/
}