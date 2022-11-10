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

	//window
	neu::g_renderer.CreateWindow("Neumont", 800, 600);
	LOG("Window Initialize...");
	neu::g_gui.Initialize(neu::g_renderer);

	// load scene 
	auto scene = neu::g_resources.Get<neu::Scene>("scenes/test.scn");

	glm::vec3 pos{ 0, 0, 0 };
	bool quit = false;
	while (!quit)
	{
		neu::Engine::Instance().Update();
		neu::g_gui.BeginFrame(neu::g_renderer);

		if (neu::g_inputSystem.GetKeyState(neu::key_escape) == neu::InputSystem::KeyState::Pressed) quit = true;


		auto actor = scene->GetActorFromName("Ogre");

		//if (actor)
		//{
		//	actor->m_transform.rotation.y += neu::g_time.deltaTime * 45.0f;
		//}

		auto actor1 = scene->GetActorFromName("Light");
		if (actor1)
		{
			// move light using sin wave
			actor1->m_transform.position = pos;
		}

		ImGui::Begin("Hello");
		ImGui::Button("Press Me!");
		ImGui::SliderFloat3("Position", &pos[0], -50, 50);
		ImGui::End();

		scene->Update();
		
		neu::g_renderer.BeginFrame();

		scene->Draw(neu::g_renderer);

		neu::g_gui.Draw();

		neu::g_renderer.EndFrame();
		neu::g_gui.EndFrame();
	}

	scene->RemoveAll();
	neu::Engine::Instance().Shutdown();

	return 0;
}

	//static glm::vec3 defaultPosition = glm::vec3{ 0, 2, 2 };