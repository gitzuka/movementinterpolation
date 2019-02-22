 #pragma once

namespace InterpolationManager// : public QObject
{
	#include <QQuaternion>
#include <qmath.h>
	static QQuaternion slerp(QQuaternion q0, QQuaternion q1, double t)
	{
		q0.normalize();
		q1.normalize();

		float dot = QQuaternion::dotProduct(q0, q1);
		
		if (dot < 0.0f)
		{
			q1 = -q1;
			dot = -dot;
		}

		const float dotThreshold = 0.9995f;
		if (dot > dotThreshold)
		{

			QQuaternion result = (1 - t) * q0 + t * q1;
			result.normalize();
			return result;
		}

		
		double theta0 = acos(dot);        
		double theta = theta0 * t;          
		double sinTheta = sin(theta);
		double sinTheta0 = sin(theta0);

		double s0 = cos(theta) - dot * sinTheta / sinTheta0;  // == sin(theta0 - theta) / sin(theta0)
		double s1 = sinTheta / sinTheta0;

		return (s0 * q0) + (s1 * q1);
	}

	template <class T>
	static T lerp(T v0, T v1, double t)
	{
		return (1 - t) * v0 + t * v1;
	}

	static float convertToRadians(float angle)
	{
		return M_PI / 180.0f * angle;
	}

	static float convertToDegrees(float angle)
	{
		return 180.0f * angle / M_PI;
	}

	//yaw (Z), pitch (Y), roll (X)
	static QQuaternion toQuaternion(double yaw, double pitch, double roll)
	{
		yaw = convertToRadians(yaw);
		pitch = convertToRadians(pitch);
		roll = convertToRadians(roll);
		double cy = cos(yaw * 0.5);
		double sy = sin(yaw * 0.5);
		double cp = cos(pitch * 0.5);
		double sp = sin(pitch * 0.5);
		double cr = cos(roll * 0.5);
		double sr = sin(roll * 0.5);

		QQuaternion q;
		q.setScalar(cy * cp * cr + sy * sp * sr);
		q.setX(cy * cp * sr - sy * sp * cr);
		q.setY(sy * cp * sr + cy * sp * cr);
		q.setZ(sy * cp * cr - cy * sp * sr);
		return q.normalized();
	}

	//return yaw(z) pitch(y) roll(x)
	static QVector3D toEulerAngle(const QQuaternion& q)
	{
		// roll (x-axis rotation)
		double sinRcosP = +2.0 * (q.scalar() * q.x() + q.y() * q.z());
		double cosRcosP = +1.0 - 2.0 * (q.x() * q.x() + q.y() * q.y());
		double roll = atan2(sinRcosP, cosRcosP);

		// pitch (y-axis rotation)
		double sinP = +2.0 * (q.scalar() * q.y() - q.z() * q.x());
		double pitch;
		if (fabs(sinP) >= 1)
			pitch = copysign(M_PI / 2, sinP); // use 90 degrees if out of range
		else
			pitch = asin(sinP);

		// yaw (z-axis rotation)
		double sinYosP = +2.0 * (q.scalar() * q.z() + q.x() * q.y());
		double cosYosP = +1.0 - 2.0 * (q.y() * q.y() + q.z() * q.z());
		double yaw = atan2(sinYosP, cosYosP);
		return QVector3D(InterpolationManager::convertToDegrees(roll), convertToDegrees(pitch), convertToDegrees(yaw));
	}


	//private slots:
		/*void setStartPosX(double value);
		void setStartPosY(double value);
		void setStartPosZ(double value);
		void setStartEulerAngleX(double value);
		void setStartEulerAngleY(double value);
		void setStartEulerAngleZ(double value);
		void setStartQuaternionX(double value);
		void setStartQuaternionY(double value);
		void setStartQuaternionZ(double value);
		void setStartQuaternionW(double value);
		void setEndPosX(double value);
		void setEndPosY(double value);
		void setEndPosZ(double value);
		void setEndEulerAngleX(double value);
		void setEndEulerAngleY(double value);
		void setEndEulerAngleZ(double value);
		void setEndQuaternionX(double value);
		void setEndQuaternionY(double value);
		void setEndQuaternionZ(double value);
		void setEndQuaternionW(double value);*/
};
