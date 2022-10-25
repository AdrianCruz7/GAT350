#include "CameraController.h" 
#include "Engine.h" 

namespace neu
{
	void CameraController::Update()
	{
		// update transform 

		if (g_inputSystem.GetKeyState(key_left) == InputSystem::KeyState::Held)
		{
			m_owner->m_transform.position.x -= speed * g_time.deltaTime;
			std::cout << "test" << std::endl;
		}

		if (g_inputSystem.GetKeyState(key_right) == InputSystem::KeyState::Held)
		{
			m_owner->m_transform.position.x += speed * g_time.deltaTime;
			std::cout << "test" << std::endl;
		}

		if (g_inputSystem.GetKeyState(key_up) == InputSystem::KeyState::Held)
		{
			m_owner->m_transform.position.y += speed * g_time.deltaTime;
			std::cout << "test" << std::endl;
		}

		if (g_inputSystem.GetKeyState(key_down) == InputSystem::KeyState::Held)
		{
			m_owner->m_transform.position.y -= speed * g_time.deltaTime;
			std::cout << "test" << std::endl;
		}

		if (g_inputSystem.GetKeyState(neu::page_down) == InputSystem::KeyState::Held)
		{
			m_owner->m_transform.position.z += speed * neu::g_time.deltaTime;
			std::cout << "test" << std::endl;
		}

		if (g_inputSystem.GetKeyState(neu::page_up) == InputSystem::KeyState::Held)
		{
			m_owner->m_transform.position.z -= speed * neu::g_time.deltaTime;
			std::cout << "test" << std::endl;
		}
	}

	bool CameraController::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool CameraController::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, speed);

		return true;
	}

}