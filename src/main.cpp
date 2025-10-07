#include <SFML/Graphics.hpp>
#include <iostream>

#pragma region imgui
#include "imgui.h"
#include "imgui-SFML.h"
#include "imguiThemes.h"
#pragma endregion

#include "Game.h"

int main() {
    Game game;
    game.run();
    return 0;
}


//if you want to load OpenGL
//#include <glad/glad.h>
//#include <errorReporting.h>

//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(500, 500), "Dungeon Redemption");
//
//
//
//
//	//if you want to load OpenGL.
//	// Note: SFML also uses OpenGL so it will interfere with your code.
//	// If you want to draw both with SFML and your OpenGL code, you will have
//	// to fight with it a little.
//	// I found that calling glDisableVertexAttribArray(0); for attributes 0 - 8
//	// solved some issues sometimes
//	//  
//	//if (!gladLoadGLLoader((GLADloadproc)sf::Context::getFunction))
//	//{
//	//	std::cerr << "Failed to initialize GLAD" << std::endl;
//	//	return -1;
//	//}
//	//enableReportGlErrors();
//
//
//#pragma region imgui
//	ImGui::SFML::Init(window);
//	//you can use whatever imgui theme you like!
//	//ImGui::StyleColorsDark();				
//	//imguiThemes::yellow();
//	//imguiThemes::gray();
//	imguiThemes::green();
//	//imguiThemes::red();
//	//imguiThemes::gray();
//	//imguiThemes::embraceTheDarkness();
//
//	ImGuiIO &io = ImGui::GetIO(); (void)io;
//	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
//	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
//	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
//	io.FontGlobalScale = 2.f;
//	ImGuiStyle &style = ImGui::GetStyle();
//	style.Colors[ImGuiCol_WindowBg].w = 0.5f;
//	//style.Colors[ImGuiCol_DockingEmptyBg].w = 0.f;
//#pragma endregion
//
//
//
//	//window.setVerticalSyncEnabled(true);
//
//	// Player creation
//	sf::RectangleShape player(sf::Vector2f(20.f, 20.f));
//	player.setFillColor(sf::Color::Cyan);
//	player.setPosition(225.f, 225.f);
//
//	// View creation
//	sf::View view(sf::FloatRect(0.f, 0.f, 500.f, 500.f));
//
//	sf::Clock clock;
//
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			
//		#pragma region imgui
//			ImGui::SFML::ProcessEvent(window, event);
//		#pragma endregion
//
//
//			if (event.type == sf::Event::Closed)
//				window.close();
//			else if (event.type == sf::Event::Resized)
//			{
//				// Adjust the viewport when the window is resized
//				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
//				window.setView(sf::View(visibleArea));
//			}
//		}
//
//		//calculate the delta time
//		sf::Time deltaTime = clock.restart();
//		float deltaTimeSeconds = deltaTime.asSeconds();
//
//		//make sure delta time stays within normal bounds, like between one FPS and zero FPS
//		deltaTimeSeconds = std::min(deltaTimeSeconds, 1.f);
//		deltaTimeSeconds = std::max(deltaTimeSeconds, 0.f);
//
//	#pragma region imgui
//		ImGui::SFML::Update(window, deltaTime);
//
//		ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
//		ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
//		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
//		ImGui::PopStyleColor(2);
//	#pragma endregion
//
//
//		//ImGui::Begin("Hello, world!");
//		//ImGui::Button("Look at this pretty button!");
//		//ImGui::Text("Hello!");
//		//ImGui::Text("This is some useful text.");
//		//ImGui::End();
//
//		/* Game Code Here ***************/
//
//		// Movement logic
//		float speed = 200.f;
//		sf::Vector2f movement(0.f, 0.f);
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) movement.y -= speed * deltaTimeSeconds;
//		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movement.x -= speed * deltaTimeSeconds;
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movement.x += speed * deltaTimeSeconds;
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movement.y += speed * deltaTimeSeconds;
//		
//
//		// Camera Logic
//		view.setCenter(player.getPosition());
//		window.setView(view);
//
//		player.move(movement);
//
//		window.clear();
//
//		// Drawing tiles
//		for (int x = 0; x < 2000; x += 100)
//		{
//			for (int y = 0; y < 2000; y += 100)
//			{
//				sf::RectangleShape tile(sf::Vector2f(95.f, 95.f));
//				tile.setFillColor(sf::Color(60, 60, 60));
//				tile.setOutlineThickness(2.f);
//				tile.setOutlineColor(sf::Color(30, 30, 30));
//				tile.setPosition(x, y);
//				window.draw(tile);
//			}
//		}
//
//		window.draw(player);
//
//
//	#pragma region imgui
//		ImGui::SFML::Render(window);
//	#pragma endregion
//
//		window.display();
//	}
//
//#pragma region imgui
//	ImGui::SFML::Shutdown();
//#pragma endregion
//
//	return 0;
//}