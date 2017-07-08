#include <glm/detail/type_mat.hpp>
#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/constants.hpp>

using namespace glm;

using namespace glm;

class Camera
{
public:
	Camera(float radius, float height, float dec_fact = 0.01)
	{
		this->dec_fact = dec_fact;
		this->radius = radius;
		lat = height;
		lon = 0;
		up = glm::vec3(0.0f, 1.0f, 0.0f);
		dp = vec2(0.0f, 0.0f);
		viewedPoint = glm::vec3(0.0f, 0.0f, 0.0f);
		updateCamera();
	}

	void updateZoom(float deltaRadius) {
		radius -= deltaRadius;
		radius = glm::clamp(radius, 2.0f, 25.0f);
		updateCamera();
	}

	void updatePosition(float xpos, float ypos, bool flag)
	{
		if (!flag)
		{
			dp[0] = xpos - old_xpos;
			dp[1] = ypos - old_ypos;

			this->lat = glm::clamp((this->lat) + dp[1] * dec_fact, -(this->halfPi), this->halfPi - 0.0001f);
			this->lon += dp[0] * dec_fact;
			updateCamera();
		}
		old_xpos = xpos;
		old_ypos = ypos;
	}

	void resetCamera()
	{
		old_xpos = 0;
		old_ypos = 0;
		dp[1] = 0;
		dp[0] = 0;
	}
	glm::mat4 getRotViewMatrix()
	{
		return view;
	}

private:
	float dec_fact;
	float radius;
	float halfPi = glm::two_pi<float>()/4;
	float old_xpos;
	float old_ypos;
	vec2 dp;
	float lat;
	float lon;
	glm::vec3 up;
	glm::vec3 viewedPoint;
	glm::mat4 view;

	void updateCamera() {
		float lt = halfPi - lat;
		glm::vec3 eyePos = glm::vec3(radius * cos(lon) * sin(lt), radius * cos(lt), radius * sin(lon) * sin(lt));
		view = lookAt(eyePos, viewedPoint, up);
	}
};
