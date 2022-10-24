#include "Engine.h" 
#include <iostream> 

float vertices[] = {
	-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	 0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	 0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

	-0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	 0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	 0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	 0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	-0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	-0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

	-0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	-0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	-0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

	 0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	 0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	 0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	 0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	 0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	 0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,

	-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	 0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	 0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	 0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	-0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f
};

int main(int argc, char** argv)
{
	LOG("Application Started...");

	neu::InitializeMemory();
	neu::SetFilePath("../Assets");

	neu::Engine::Instance().Initialize();
	neu::Engine::Instance().Register();
	LOG("Engine Initialized...");

	neu::g_renderer.CreateWindow("Neumont", 800, 600);
	LOG("Window Initialize...");

	//create vertex buffer
	std::shared_ptr<neu::VertexBuffer> vb = neu::g_resources.Get<neu::VertexBuffer>("box");
	vb->CreateVertexBuffer(sizeof(vertices), 36, vertices);
	vb->SetAttribute(0, 3, 8 * sizeof(float), 0);
	vb->SetAttribute(1, 3, 8 * sizeof(float), 3 * sizeof(float));
	vb->SetAttribute(2, 2, 8 * sizeof(float), 6 * sizeof(float));


	//create material
	std::shared_ptr<neu::Material> material = neu::g_resources.Get<neu::Material>("Materials/box.mtrl");
	material->Bind();


	material->GetProgram()->SetUniform("tint", glm::vec3{ 1, 0, 0 });
	material->GetProgram()->SetUniform("scale", 1.0f);
	
	glm::mat4 model{ 1 };
	glm::mat4 projection = glm::perspective(45.0f, neu::g_renderer.GetWidth() / (float)neu::g_renderer.GetHeight(), 0.01f, 100.0f);

	glm::vec3 cameraPosition = glm::vec3{ 0, 2, 2 };
	static glm::vec3 defaultPosition = glm::vec3{ 0, 2, 2 };
	float speed = 3.0f;

	std::vector<neu::Transform> transforms;
	for (size_t i = 0; i < 200; i++)
	{
		transforms.push_back({ { neu::randomf(-10, 10), neu::randomf(-10, 10), neu::randomf(-10, 10)}, {neu::randomf(360), 90, 0} });
		
	}

	bool quit = false;
	while (!quit)
	{
		neu::Engine::Instance().Update();
		if (neu::g_inputSystem.GetKeyState(neu::key_escape) == neu::InputSystem::KeyState::Pressed) quit = true;

		//material->GetProgram()->SetUniform("scale", std::sin(neu::g_time.time * 3));
		 
		//add input to move camera
		if (neu::g_inputSystem.GetKeyState(neu::page_down) == neu::InputSystem::KeyState::Held) cameraPosition.z += speed * neu::g_time.deltaTime;
		if (neu::g_inputSystem.GetKeyState(neu::page_up) == neu::InputSystem::KeyState::Held) cameraPosition.z -= speed * neu::g_time.deltaTime;
		if (neu::g_inputSystem.GetKeyState(neu::key_up) == neu::InputSystem::KeyState::Held) cameraPosition.y += speed * neu::g_time.deltaTime;
		if (neu::g_inputSystem.GetKeyState(neu::key_down) == neu::InputSystem::KeyState::Held) cameraPosition.y -= speed * neu::g_time.deltaTime;
		if (neu::g_inputSystem.GetKeyState(neu::key_right) == neu::InputSystem::KeyState::Held) cameraPosition.x += speed * neu::g_time.deltaTime;
		if (neu::g_inputSystem.GetKeyState(neu::key_left) == neu::InputSystem::KeyState::Held) cameraPosition.x -= speed * neu::g_time.deltaTime;
		if (neu::g_inputSystem.GetKeyState(neu::key_enter) == neu::InputSystem::KeyState::Pressed) cameraPosition = defaultPosition;

		glm::mat4 view = glm::lookAt(cameraPosition, cameraPosition + glm::vec3{ 0, 0, -1 }, glm::vec3{ 0, 1, 0 });
		
		//model = glm::eulerAngleXYZ(0.0f, neu::g_time.time, 0.0f);
		
		neu::g_renderer.BeginFrame();

		for (size_t i = 0; i < transforms.size(); i++)
		{
			transforms[i].rotation += glm::vec3{ 0, 90 * neu::g_time.deltaTime, 0 };
			glm::mat4 mvp = projection * view * (glm::mat4)transforms[i];
			material->GetProgram()->SetUniform("mvp", mvp);

			vb->Draw();
		}

		neu::g_renderer.EndFrame();
	}

	neu::Engine::Instance().Shutdown();

	return 0;
}