#include "CameraController.h" 
#include "Engine.h" 

namespace neu
{
	void CameraController::Update()
	{
		//camera position
		if (g_inputSystem.GetKeyState(key_left) == InputSystem::KeyState::Held)
		{
			m_owner->m_transform.position.x -= speed * g_time.deltaTime;
			//std::cout << "test" << std::endl;
		}

		if (g_inputSystem.GetKeyState(key_right) == InputSystem::KeyState::Held)
		{
			m_owner->m_transform.position.x += speed * g_time.deltaTime;
			//std::cout << "test" << std::endl;
		}

		if (g_inputSystem.GetKeyState(key_up) == InputSystem::KeyState::Held)
		{
			m_owner->m_transform.position.y += speed * g_time.deltaTime;
			//std::cout << "test" << std::endl;
		}

		if (g_inputSystem.GetKeyState(key_down) == InputSystem::KeyState::Held)
		{
			m_owner->m_transform.position.y -= speed * g_time.deltaTime;
			//std::cout << "test" << std::endl;
		}

		if (g_inputSystem.GetKeyState(neu::page_down) == InputSystem::KeyState::Held)
		{
			m_owner->m_transform.position.z += speed * neu::g_time.deltaTime;
			//std::cout << "test" << std::endl;
		}

		if (g_inputSystem.GetKeyState(neu::page_up) == InputSystem::KeyState::Held)
		{
			m_owner->m_transform.position.z -= speed * neu::g_time.deltaTime;
			//std::cout << "test" << std::endl;
		}
		
		
		//camera rotation
		if (g_inputSystem.GetKeyState(neu::key_d) == InputSystem::KeyState::Held)
		{
			m_owner->m_transform.rotation.y -= cameraSpeed * neu::g_time.deltaTime;
			//std::cout << "test" << std::endl;
		}
		
		if (g_inputSystem.GetKeyState(neu::key_a) == InputSystem::KeyState::Held)
		{
			m_owner->m_transform.rotation.y += cameraSpeed * neu::g_time.deltaTime;
			//std::cout << "test" << std::endl;
		}
		
		if (g_inputSystem.GetKeyState(neu::key_w) == InputSystem::KeyState::Held)
		{
			m_owner->m_transform.rotation.x += cameraSpeed * neu::g_time.deltaTime;
			//std::cout << "test" << std::endl;
		}
		
		if (g_inputSystem.GetKeyState(neu::key_s) == InputSystem::KeyState::Held)
		{
			m_owner->m_transform.rotation.x -= cameraSpeed * neu::g_time.deltaTime;
			//std::cout << "test" << std::endl;
		}


	}

	bool CameraController::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool CameraController::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, speed);
		READ_DATA(value, cameraSpeed);

		return true;
	}

}